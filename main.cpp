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
	Serial.begin(57600);
	IRRangers scanner;
	scanner.setServoAngle(10);

//scanner.ContinousScan();

	//scanner.ContinousScan();

	scanner.setMaxScanAngle(120);

	Serial.flush();
	while(1==1){
		if (Serial.available()){ // get new byte, parse if neccesaryp
			char c = Serial.read();

			if (c ==10){
					//Printout data
				int i;\
				Serial.write(c);  //Send command back
				Serial.write(scanner.scanIndex+1);  // send scan
				for ( i=0; i<= scanner.scanIndex; i++){
				Serial.write(scanner.data[i].angle);
				Serial.writeInt(scanner.data[i].leftEncoderCount);
				Serial.writeInt(scanner.data[i].rightEncocerCount);
				Serial.write(scanner.data[i].angle);
				for (int j=0; j<4; j++){
				Serial.writeInt(scanner.data[i].irData[j]);
				}
				}
				scanner.scanIndex =0;
			}
		}
			scanner.scan2();
			_delay_ms(1);
	}

}





