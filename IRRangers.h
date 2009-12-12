/*
 * IRRangers.h
 *
 *  Created on: Dec 12, 2009
 *      Author: asher
 */

#ifndef IRRANGERS_H_
#define IRRANGERS_H_

#include "Robot.h"
#include "Servo.h"

 struct scanData{
	int angle;
	int leftEncoderCount;
	int rightEncocerCount;
	int irData[4];
};


class IRRangers {
public:
	IRRangers();
	~IRRangers();
	void setScanRate(int angleDegreesPerSecond);
		scanData data[100];
		int numberOfScans;
		void scan();
		void Update();
		void setMaxScanAngle(int degrees);
		void setMinScanAngle(int degrees);
		void setServoAngle(int degrees);
	private:
		 Servo LFservo;
		 Servo RFServo;
		 Servo LBServo;
		 Servo RBServo;
		 int currentAngle;
};

#endif /* IRRANGERS_H_ */
