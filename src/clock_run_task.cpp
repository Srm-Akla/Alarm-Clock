#include "lib.hpp"

void clock_run_task ()
{
    while (1)
    {
      if (xSemaphoreTake(gate,0))
      {
          // read clock value from the current address of the EEPROM
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Time is:");
          //next lin on display write time
          lcd.setCursor(0, 1);
          lcd.print(hr);
          lcd.print(":");
          if (min<10)
            lcd.print("0");
          lcd.print(min);
          lcd.print(":");
          if (sec<10)
            lcd.print("0");
          lcd.print(sec);
          //se for match of time and alarm start alarm
          if (!(PIND & OK))
            {
              vTaskDelay(10);
              clock_menu();
            }
        //sjekk alarm if alarm_on is high
        if ((hr==EEPROM.read(addr_alarm_hr))&&(min==EEPROM.read(addr_alarm_min))&&(sec==EEPROM.read(addr_alarm_sec)))
        {
          vTaskDelay(10);
          if (PIND & RED)
            alarm_buzz();
      }
        xSemaphoreGive(gate);
        vTaskDelay(10);
    }
}
}
