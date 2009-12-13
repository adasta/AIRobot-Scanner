#include "WProgram.h"
#include <avr/interrupt.h>
extern "C"{
#include "motorcontrol.h"
#include "pwm.h"
#include <avr/io.h>
}

#include "Servo.h"
#include "IRRangers.h"
#include <avr/delay.h>

extern "C" void __cxa_pure_virtual()

{

cli();

for (;;);

}


int main(void)
{
	init();
	Serial.begin(115200);
	IRRangers scanner;

//scanner.ContinousScan();

	//scanner.ContinousScan();

	scanner.setMaxScanAngle(120);

	while(1==1){
		if (Serial.available()){ // get new byte, parse if neccesaryp
		}
			scanner.scan2();
			_delay_ms(1);


	}

}





