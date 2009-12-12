#include "WProgram.h"
#include <avr/interrupt.h>
extern "C"{
#include "motorcontrol.h"
#include "pwm.h"
#include <avr/io.h>
}

#include "Servo.h"
#include "IRRangers.h"

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
void scan(){
	int angle=0;
	int direction =0;
	while(1==1){
			setServoAngle(angle);
			Serial.print(angle);
			Serial.println(" ");
			delay(80);
			if (direction ==0) angle = angle +5;
			else angle = angle -5;

			if (angle >180) {
				angle = 180;
				direction =1;
			}
			if (angle < 0){
				direction =0;
				angle = 0;
			}
	}
}


int main(void)
{
	init();
	Serial.begin(9600);
	IRRangers scanner;

	scanner.scan();


	}





