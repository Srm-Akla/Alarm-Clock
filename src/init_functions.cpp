#include "lib.hpp"
void init_eeprom(){
  //writ to the eeprom at correct adress default value
  EEPROM.write(addr_alarm_hr, 06);
  EEPROM.write(addr_alarm_min, 00);
  EEPROM.write(addr_alarm_sec, 00);
  delay(1);
}

void init_interupt()
{
  // disable all interrupts while Configuration
  cli();//stop interrupts
  //set timer1 interrupt at 1Hz
    TCCR1A = 0;// set  register to 0
    TCCR1B = 0;// set reg to 0
    TCNT1  = 0;//set counter value to 0
    // set compare match register to 1hz increments
    OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536) and (>256)
    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    // Set CS10 and CS12 bits for 1024 prescaler this must be done becaus else out of range count
    TCCR1B |= (1 << CS12) | (1 << CS10);
    // enable compare interrupt
    TIMSK1 |= (1 << OCIE1A);
  sei();//allow interrupts

}

void init_task ()
  {
    //creat tasks running clock priority 1
    xTaskCreate(clock_run_task, "Normal_run", 256, NULL, 1, NULL);
  }
