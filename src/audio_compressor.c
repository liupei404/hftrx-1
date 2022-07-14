/* $Id$ */
//
// Проект HF Dream Receiver (КВ приёмник мечты)
// автор Гена Завидовский mgs2001@mail.ru
// UA1ARN
//

#include "hardware.h"
#include "board.h"
#include "audio_compressor.h"

enum CompStates {
	State_Idle, 
	State_Attack, 
	State_GainReduction, 
	State_Release 
};

static enum CompStates	state = State_Idle;
static unsigned			attack = 1442;			// 30ms * 48kHz
static unsigned			release = 962;			// 20ms * 48kHz
static unsigned			hold = 480;				// 10ms * 48kHz
static unsigned			time_out = 0;

static FLOAT_t			gainreduce = 0.5;		// compression ratio: 6:1 -> -6dB = 0.5
static FLOAT_t			threshold = 0.1;		// -20dB below limit

static FLOAT_t			gain_step_attack = (1.0 - 0.5) / 1442;
static FLOAT_t			gain_step_release = (1.0 - 0.5) / 962;
static FLOAT_t			gain = 1.0;

void audio_compressor_recalc() {
	gain_step_attack = (1.0 - gainreduce) / attack;
	gain_step_release = (1.0 - gainreduce) / release;
}

void audio_compressor_set_attack(unsigned samples) {
	attack = samples;
}

void audio_compressor_set_release(unsigned samples) {
	release = samples;
}

void audio_compressor_set_gainreduce(FLOAT_t ratio) {
	gainreduce = ratio;
}

void audio_compressor_set_hold(unsigned samples) {
	hold = samples;
}

void audio_compressor_set_threshold(FLOAT_t ratio) {
	threshold = ratio;
}

FLOAT_t audio_compressor_calc(FLOAT_t in) {
	if (fabs(in) > threshold) {
		if (gain >= gainreduce) {
			if (state == State_Idle || state == State_Release) {
				state = State_Attack;
				time_out = attack;
			}
		}
		
		if (state == State_GainReduction) time_out = hold;
	}

	if (fabs(in) < threshold && gain <= 1.0) {
		if (time_out == 0 && state == State_GainReduction) {
			state = State_Release;
			time_out = release;
		}
	}
	
	switch (state) {
		case State_Attack:
			if (time_out > 0 && gain > gainreduce) {
				gain -= gain_step_attack;
				time_out--;
			} else {
				state = State_GainReduction;
				time_out = hold;
			}
			break;

		case State_GainReduction:
			if (time_out > 0) {
				time_out--;
			} else {
				state = State_Release;
				time_out = release;
			}
			break;

		case State_Release:
			if (time_out > 0 && gain < 1.0) {
				time_out--;
				gain += gain_step_release;
			} else {
				state = State_Idle;
			}
			break;

		case State_Idle:
			if (gain < 1.0) gain = 1.0;
			break;

		default:
			break;
	}

	return in * gain;
}
