/*
 * IRRangers.h
 *
 *  Created on: Dec 12, 2009
 *      Author: asher
 */

#ifndef IRRANGERS_H_
#define IRRANGERS_H_

#include "Servo.h"
#include "Robot.h"
#define maxScans 40

 struct scanData{
	int angle;
	int leftEncoderCount;
	int rightEncocerCount;
	uint16_t irData[4];
};



class IRRangers {
public:
	IRRangers();
	~IRRangers();
		scanData data[maxScans];
		int scanIndex;
		void ContinousScan();
		void scan();
		void scan2();
		void setMaxScanAngle(int degrees);
		void setMinScanAngle(int degrees);
		void setServoAngle(int degrees);
		void setScanRate(int angleDegreesPerSecond);
	private:
		 Servo LFservo;
		 Servo RFServo;
		 Servo LBServo;
		 Servo RBServo;
		 int currentAngle;
		 int scanRateDegSec;
		 int minAngle;
		 int maxAngle;
		 int DeltaAnglePerUpdate;  //Scan angle is changed every 40 ms
};

#endif /* IRRANGERS_H_ */
