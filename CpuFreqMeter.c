/*
htop - CpuFreqMeter.c
(C) 2018 @lex
*/

#include "CpuFreqMeter.h"
#include "Platform.h"
#include "CRT.h"


int CpuFreqMeter_attributes[] = {
   CPU_FREQ
};

static void CpuFreqMeter_setValues(Meter* this, char* buffer, int len) {
   int Freq = Platform_getCpuFreq();
   if (Freq > 1000) {
       Freq /= 1000;
   }
   snprintf(buffer, len, "%4d Mhz", Freq);
}

MeterClass CpuFreqMeter_class = {
   .super = {
      .extends = Class(Meter),
      .delete = Meter_delete
   },
   .updateValues = CpuFreqMeter_setValues, 
   .defaultMode = TEXT_METERMODE,
   .maxItems = 1,
   .total = 100.0,
   .attributes = CpuFreqMeter_attributes,
   .name = "CpuFreq",
   .uiName = "CpuFreq",
   .caption = "Cpu Freq: "
};
