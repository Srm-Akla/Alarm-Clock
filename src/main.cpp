#include "lib.hpp"

//lcd is a variabel of type LiquidCrystal
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//gatekeeper and queue_handler
int hr =12;
int min=00;
int sec=00;

SemaphoreHandle_t gate=NULL;

void setup()
{
  // start a serialport
  Serial.begin(9600);
  // wait for serial port to connect. Needed for native USB port only
  while (!Serial)
  {}
    // setup lcd display
    lcd.begin(16,2);

    //setup eeprom memory
    init_eeprom();

    //setup tasks, que and gatekeeper
    init_task ();
    init_interupt();

  //lcd.clear();
  port_map();

  gate = xSemaphoreCreateMutex();

}

void loop()
{
  // put your main code here, to run repeatedly:
}
