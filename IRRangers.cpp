/*
 * IRRangers.cpp
 *
 *  Created on: Dec 12, 2009
 *      Author: asher
 */

#include "IRRangers.h"
#include "WProgram.h"
#include "Robot.h"
#include <avr/delay.h>


IRRangers::IRRangers() {
	// TODO Auto-generated constructor stub
	RFServo.attach(6,544, 2300);
	LFservo.attach(5);
	LBServo.attach(4, 500, 2400);//544, 2300);
	RBServo.attach(2, 544, 2300);
	setServoAngle(0);
	this->setMinScanAngle(0);
	this->setMaxScanAngle(180);
	currentAngle = minAngle;
	setScanRate(90);

	Serial.print("Scan rate : ");
	Serial.print(this->DeltaAnglePerUpdate);

}

IRRangers::~IRRangers() {
	// TODO Auto-generated destructor stub
}

void IRRangers::setScanRate(int angleDegreesPerSecond)
{
	this->scanRateDegSec = angleDegreesPerSecond;
	this->DeltaAnglePerUpdate= angleDegreesPerSecond/25;
}



void IRRangers::setMinScanAngle(int degrees)
{
	this->minAngle = degrees;
}



void IRRangers::setServoAngle(int degrees)
{

	Serial.print("Setting Angle to: ");
	Serial.println(degrees);

	RFServo.write(180-degrees);
	LFservo.write(degrees);
	LBServo.write(180-degrees);
	RBServo.write(degrees);
}



void IRRangers::setMaxScanAngle(int degrees)
{
	this->maxAngle = degrees;
}



void IRRangers::ContinousScan()
{
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
//
void IRRangers::scan2(){
		static unsigned long pTime;
		unsigned long  time = millis();

		Serial.print("Time ");
		Serial.println(time);

			if ( (time - pTime) >=40){
						currentAngle += DeltaAnglePerUpdate;
						if (currentAngle >= maxAngle) {
							currentAngle = maxAngle;
							DeltaAnglePerUpdate = DeltaAnglePerUpdate *-1;
						}
						if (currentAngle <=minAngle ){
							currentAngle = minAngle;
							DeltaAnglePerUpdate = DeltaAnglePerUpdate *-1;
						}
						Serial.println("Hi!");

						scanIndex++;

						if (scanIndex > (maxScans-1)){
							scanIndex = 0;
						}

					setServoAngle(currentAngle);
					pTime = time;

				//	this->data[scanIndex].leftEncoderCount = aiRobot.getLeftEncoderCount();
				//	this->data[scanIndex].rightEncocerCount = aiRobot.getRightEncoderCount();

			}

			for (int i=0;i<4; i++){
				this->data[scanIndex].irData[i]  = this->data[scanIndex].irData[i] *3/4 +  analogRead(i)/4;
			}


}


/*
 *Scan moves the IR Sensors back and forth at the at the rate
 */
void IRRangers::scan()
{

	 static int time ;
	 time++;

	if  ( time >= 40){  //Update Scan Angle
		currentAngle += DeltaAnglePerUpdate;
		if (currentAngle >= 180) {
			currentAngle = 180;
			DeltaAnglePerUpdate = DeltaAnglePerUpdate *-1;
		}
		if (currentAngle <=0 ){
			currentAngle = 0;
			DeltaAnglePerUpdate = DeltaAnglePerUpdate *-1;
		}


		setServoAngle(currentAngle);
		scanIndex++;

		if (scanIndex > (maxScans -1)){
			scanIndex = 0;
		}

		this->data[scanIndex].leftEncoderCount = aiRobot.getLeftEncoderCount();
		this->data[scanIndex].rightEncocerCount = aiRobot.getRightEncoderCount();
		time =0;
	}

		for (int i=0;i<4; i++){
			this->data[scanIndex].irData[i]  = this->data[scanIndex].irData[i] *3/4 +  analogRead(i)/4;
		}


}


