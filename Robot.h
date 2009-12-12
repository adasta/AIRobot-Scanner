/*
 * Robot.h
 *
 *  Created on: Dec 12, 2009
 *      Author: asher
 */

#ifndef ROBOT_H_
#define ROBOT_H_

class Robot {
public:
	Robot();

	void setRightWheelSpeed(int CmPerSec);
	void setLeftWheelSpeed(int CmPerSec);

	int getLeftEncoderCount();
	int getRightEncoderCount();

	~Robot();
private:
	int LencoderCount;
	int RencoderCount;;

	int currentLSpeed;
	int currentRSpeed;
};
extern Robot aiRobot;

#endif /* ROBOT_H_ */
