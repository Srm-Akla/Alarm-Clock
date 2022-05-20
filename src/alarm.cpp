#include "lib.hpp"

void alarm_on_off()
{
  byte alarm_on = 0;
  delay(500);
  while (PIND &OK)
  {
    if (!digitalRead(12) | !digitalRead(11))
      alarm_on= ~(alarm_on);
    delay(300);
    lcd.clear();
    if (!alarm_on)
      lcd.print("Alarm OFF");
    if (alarm_on)
      lcd.print("Alarm ON");
  }
  if (!alarm_on)
    PORTD &= ~RED;//turn OFF led
  if (alarm_on)
    PORTD |= RED;//turn ON bit
  delay(500);
}


void alarm_buzz()
{
  int t_hr;
  int t_min;
  int t_sec;
  lcd.clear();
  lcd.print("Wake up!");
  PORTB &= ~GREEN;//turn OFF bit led
  delay(300);

  while (PIND &OK&&digitalRead(12)&&digitalRead(11))
  {
      tone(8,440,50);//A tone
  }
  delay(500);

  while (PIND &OK)
  {
    delay(300);
    lcd.clear();
    lcd.print("UP for snooz");
    lcd.setCursor(0, 1);
    lcd.print("OK for clock");
   if (!digitalRead(12))
      {
      PORTB |= GREEN;//turn ON bit
      //change Alarm value on EEPROM +5min
      //henter verdi fra eeprom
      xSemaphoreTake(gate, 0);
      t_hr = EEPROM.read(addr_alarm_hr);
      t_min = EEPROM.read(addr_alarm_min);
      t_sec = EEPROM.read(addr_alarm_sec);
      xSemaphoreGive(gate);
      for (int i = 0; i <= 4; i++)
        {
          t_min +=1;
          if (t_min==60)
          {
              t_min=0;
              t_hr +=1;
              if (t_hr==24)
                t_hr=0;
          }
          delay(300);
        }
        write_alarm(t_hr, t_min, t_sec);
      }}
    delay(300);
}
