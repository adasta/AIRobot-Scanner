/*
 * Robot.cpp
 *
 *  Created on: Dec 12, 2009
 *      Author: asher
 */

#include "Robot.h"

Robot aiRobot;

Robot::Robot() {
	// TODO Auto-generated constructor stub

RencoderCount = 0;
LencoderCount = 0;
}

int Robot::getRightEncoderCount()
{
	return RencoderCount;
}

void Robot::setRightWheelSpeed(int CmPerSec)
{

}

int Robot::getLeftEncoderCount()
{
	return LencoderCount;
}

void Robot::setLeftWheelSpeed(int CmPerSec)
{
}

Robot::~Robot() {
	// TODO Auto-generated destructor stub
}
