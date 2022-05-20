#ifndef PRE_DECLARATION_FUNCTIONS_H
#define PRE_DECLARATION_FUNCTIONS_H
//from init_functions.cpp
void init_eeprom();
void init_interupt ();
void init_task ();
//from clock_run_task.cpp
void clock_run_task ();
//from clock_functions.cpp
void clock_menu();
void set_time();
void set_alarm();
//from alarm.cpp
void alarm_on_off();
void alarm_buzz();
//from EEPROM_functions
void write_alarm(int t_hr, int t_min, int t_sec);
//portmapping clock_functions
void port_map();

extern int hr;
extern int min;
extern int sec;

extern SemaphoreHandle_t gate;
extern LiquidCrystal lcd;

#endif
