#include "lib.hpp"


void clock_menu()
{
int state=0;

//Clock_menu change
delay(300);
while ((PIND & OK))
{
  if (!(digitalRead(11)))
  {
    state +=1;
    if (state ==4)
      state =0;
  }

  if (!(digitalRead(12)))
  {
    if (state ==0)
      state =4;
    state -=1;
  }
delay(500);

  switch(state)
  {
      case 0:
        lcd.clear();
        lcd.print("Set clock");
        lcd.setCursor(0,1);
        lcd.print("press ok");
        break;
      case 1:
        lcd.clear();
        lcd.print("Sett alarm");
        lcd.setCursor(0,1);
        lcd.print("press ok");
        break;
      case 2:
        lcd.clear();
        lcd.print("Alarm on/off");
        break;
      case 3:
        lcd.clear();
        lcd.print("Exit menu");
        break;
      default:
        break;
  }

}

switch(state)
{
    case 0:
      set_time();
      break;
    case 1:
      set_alarm();
      break;
    case 2:
      alarm_on_off();
      break;
    default:
      break;
}

}


void set_time()
{
  int t_hr;
  int t_min;
  int t_sec;

  t_hr=hr;
  t_min=min;
  t_sec=sec;

delay(500);
  while (PIND &OK)
  {
    //Print on display "HR value" and update
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SET TIME:");
    lcd.setCursor(0,1);
    lcd.print("HR:");
    lcd.print(t_hr);

    if (!digitalRead(12)){
      t_hr +=1;
      if (t_hr==24)
        t_hr=0;
    }
    if (!digitalRead(11)){
      if (t_hr==0)
        t_hr=24;
      t_hr -=1;
    }
  delay(300);
  }
delay(500);
  while (PIND &OK)
  {
    //Print on display "min value" and update
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SET TIME:");
    lcd.setCursor(0,1);
    lcd.print("MIN:");
    if (t_min<10)
      lcd.print("0");
    lcd.print(t_min);
    if (!digitalRead(12)){
      t_min +=1;
      if (t_min==60)
        t_min=0;
    }
    if (!digitalRead(11)){
      if (t_min==0)
        t_min=60;
      t_min -=1;
    }
    delay(300);
  }
  delay(500);
  while (PIND &OK)
  {
    //Print on display "sec value" and update
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SET TIME:");
    lcd.setCursor(0,1);
    lcd.print("SEC:");
    if (t_sec<10)
      lcd.print("0");
    lcd.print(t_sec);
    if (!digitalRead(12)){
      t_sec +=1;
      if (t_sec==60)
        t_sec=0;
    }
    if (!digitalRead(11)){
      if (t_sec==0)
        t_sec=60;
      t_sec -=1;
    }
    delay(300);
  }
  hr=t_hr; min=t_min; sec=t_sec;
  delay(500);
}

void set_alarm()
{
  int t_hr;
  int t_min;
  int t_sec;
  //henter verdi fra eeprom
  xSemaphoreTake(gate, 0);
  t_hr = EEPROM.read(addr_alarm_hr);
  t_min = EEPROM.read(addr_alarm_min);
  t_sec = EEPROM.read(addr_alarm_sec);
  xSemaphoreGive(gate);

  delay(500);
  while (PIND &OK)
  {
    //Print on display "HR value" and update
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SET TIME:");
    lcd.setCursor(0,1);
    lcd.print("HR:");
    lcd.print(t_hr);
    if (!digitalRead(12)){
      t_hr +=1;
      if (t_hr==24)
        t_hr=0;
    }
    if (!digitalRead(11)){
      if (t_hr==0)
        t_hr=24;
      t_hr -=1;
    }
    delay(300);
  }
  delay(500);
  while (PIND &OK)
  {
    //Print on display "min value" and update
      lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SET TIME:");
    lcd.setCursor(0,1);
    lcd.print("MIN:");
    if (t_min<10)
      lcd.print("0");
    lcd.print(t_min);
    if (!digitalRead(12)){
      t_min +=1;
      if (t_min==60)
        t_min=0;
    }
    if (!digitalRead(11)){
      if (t_min==0)
        t_min=60;
      t_min -=1;
    }
    delay(300);
  }
  delay(500);
  while (PIND &OK)
  {
    //Print on display "sec value" and update
      lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("SET TIME:");
    lcd.setCursor(0,1);
    lcd.print("SEC:");
    if (t_sec<10)
      lcd.print("0");
    lcd.print(t_sec);
    if (!digitalRead(12)){
      t_sec +=1;
      if (t_sec==60)
        t_sec=0;
    }
    if (!digitalRead(11)){
      if (t_sec==0)
        t_sec=60;
      t_sec -=1;
    }
    delay(300);
  }
  write_alarm(t_hr, t_min, t_sec);
  delay(500);
}
