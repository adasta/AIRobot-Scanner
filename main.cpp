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

Servo LFservo;
Servo RFServo;
Servo LBServo;
Servo RBServo;

void setServoAngle(int angle)
	{
	RFServo.write(180-angle);
	LFservo.write(angle);
	LBServo.write(180-angle);
	RBServo.write(angle);

	}


int main(void)
{
	init();
	Serial.begin(115200);
	IRRangers scanner;

//scanner.ContinousScan();

	//scanner.ContinousScan();

	while(1==1){
	//	if (Serial.available()){ // get new byte, parse if neccesary

		//}
		scanner.scan2();
		_delay_ms(1);

	}

}





