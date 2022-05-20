#include "lib.hpp"

void port_map()
{
  //sett pins for sw
  //set input for switch
  DDRD &= ~OK;
  DDRB &= ~UP;
  DDRB &= ~DOWN;
  //set pullup resistor on
  PORTD |= OK;
  PORTB |= UP;
  PORTB |= DOWN;

  //sett pins for LED and PIEZO
  //sett input for leds
  DDRD |= RED;
  DDRB |= GREEN;
  //DDRB |= PIEZO;
  //sett led low at start
  PORTD &= ~RED;
  PORTB &= ~GREEN;
  //PORTB &= ~PIEZO;
}
