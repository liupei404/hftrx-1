#ifndef __ARMV7SUPPORT_H__
#define __ARMV7SUPPORT_H__

int  ArmIsMpCore();
void ArmEnableIrq();
void ArmEnableFiq();
void ArmInvalidateInstructionCache();
void ArmInvalidateDataCacheEntryByMVA();
void ArmCleanDataCacheEntryByMVA();
void ArmCleanInvalidateDataCacheEntryByMVA();
void ArmInvalidateDataCacheEntryBySetWay();
void ArmCleanDataCacheEntryBySetWay();
void ArmCleanInvalidateDataCacheEntryBySetWay();
void ArmDrainWriteBuffer();
void ArmEnableMmu();
void ArmDisableMmu();
void ArmDisableCachesAndMmu();
int  ArmMmuEnabled();
void ArmEnableDataCache();
void ArmDisableDataCache();
void ArmEnableInstructionCache();
void ArmDisableInstructionCache();
void ArmEnableSWPInstruction();
void ArmEnableBranchPrediction();
void ArmDisableBranchPrediction();
void ArmSetLowVectors();
void ArmSetHighVectors();
void ArmV7AllDataCachesOperation();
void ArmV7PerformPoUDataCacheOperation();
void ArmDataMemoryBarrier();
void ArmDataSyncronizationBarrier();
void ArmInstructionSynchronizationBarrier();
int  ArmReadVBar();
void ArmWriteVBar();
void ArmEnableVFP();
void ArmCallWFI();
void ArmReadCbar();
void ArmReadMpidr();
void ArmReadTpidrurw();
void ArmWriteTpidrurw();
int  ArmIsArchTimerImplemented();
void ArmReadIdPfr1();
void ArmSetupCache();

void ArmEnableNEON();
int  ArmGetCpuID();
int  ArmGetHCR();

void ArmSetupCacheL1Clean();
void ArmSetupCacheL1Run();
#endif