#include "lib.hpp"


void write_alarm(int t_hr, int t_min, int t_sec)
{
  if(xSemaphoreTake(gate, 0))
  {
  // write_alarm value to the current address of the EEPROM
  EEPROM.write(addr_alarm_hr, t_hr);
  EEPROM.write(addr_alarm_min, t_min);
  EEPROM.write(addr_alarm_sec, t_sec);
  xSemaphoreGive(gate);
  }
  vTaskDelay(0);
}
