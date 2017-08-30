# Watch Dog Timer
Watch dog timer is a tool which insures that the iven part of the loop **doesn't take more than a given time period** and if it does the **WDT resets the microcontroller** and the whole code starts from the beginning even the initializations.

Following order should be folowed to use WDT in atmega :-

1.**wdt_enable(time)** This function enables the WDT with a given time period.

2.**wdt_reset()** This function resets the WDT to 0.

3.**Do the thing**

4.**wdt_disable()** This function disables the WDT if the given thing gets over before the given time period.


Following is the basic implementation of WDT ( *Timer insures loop doesn't take more than two seconds.* ):-

```C
timer_reset_two_sec(); // global reset of counter to 0 always first line of the loop
/* part whose time needs to be checked 
   order should be :-
   wdt_enable(time)
   wdt_reset()
   do the thing
   wdt_disable();
*/
wdt_enable(WDTO_2S);
wdt_reset();
//do the thing

wdt_disable();
timer_wait_reset(); // waits if the time is less than 2 sec always the last line of the loop where the time has to be checked
```
