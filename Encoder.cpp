/*
 * Encoder.cpp
 *
 *  Created on: Dec 2, 2009
 *      Author: asher
 */

#include "Encoder.h"

Encoder::Encoder() {
	// TODO Auto-generated constructor stub
	clearCount();
}

void Encoder::clearCount(){
	encoderCount=0;
}

void Encoder::update(char channelA, char channelB){
	   if ((priorA == 0) && (channelA == 1)) {
	     if (channelB == 0) {
	       encoderCount--;
	     } else {
	       encoderCount++;
	     }
	   }
	   if ((priorA == 1) && (channelA == 0)) {
	     if (channelB == 0) {
	       encoderCount++;
	     } else {
	       encoderCount--;
	     }
	   }
	   priorA  = channelA;

	   if ((priorB == 0) && (channelB == 1)) {
	   	     if (channelA == 0) {
	   	       encoderCount++;
	   	     } else {
	   	       encoderCount--;
	   	     }
	   	   }
	   	   if ((priorB == 1) && (channelB == 0)) {
	   	     if (channelA == 0) {
	   	       encoderCount--;
	   	     } else {
	   	       encoderCount++;
	   	     }
	   	   }
	   priorB = channelB;

}

int Encoder::count(){
	return encoderCount;
}

Encoder::~Encoder() {
	// TODO Auto-generated destructor stub
}
