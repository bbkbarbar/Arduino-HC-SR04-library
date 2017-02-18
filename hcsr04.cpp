//    FILE: hcsr04.cpp

#include "hcsr04.h"

#define CM_IN_MM                     10
#define HALF_CM_IN_MM_FOR_ROUNDING    5

void HCSR04::init(unsigned char trigPin, unsigned char echoPin){
	myTrigPin = trigPin;
	myEchoPin = echoPin;

	pinMode(myTrigPin, OUTPUT);
  	pinMode(myTrigPin, INPUT);
}

long HCSR04::getDisctanceFromDurationInMm(long duration){
	long distanceInCm = (long)(((double)duration/2) / 2.91);
	return distanceInCm;
}

unsigned short HCSR04::readDisctance(){
	long duration = 0;

	digitalWrite(myTrigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(myTrigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(myTrigPin, LOW);

	duration = pulseIn(myEchoPin, HIGH);
	return (unsigned short) getDisctanceFromDurationInMm(duration);
}

unsigned short HCSR04::readDisctanceInCm(){
	return ((readDisctance()+HALF_CM_IN_MM_FOR_ROUNDING) / CM_IN_MM);
}
