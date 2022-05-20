#include "lib.hpp"

ISR(TIMER1_COMPA_vect)
{
  // Preload the timer again. so timing of the next interrupt will not be wrong.
  TCNT1 = 0;
  OCR1A = 15624;
  sec +=1;
  if (sec==60)
    {
      sec=0;
      min +=1;
      if (min==60)
      {
        min =0;
        hr +=1;
        if (hr==24)
        {
          hr=00;
        }
      }
    }
}
