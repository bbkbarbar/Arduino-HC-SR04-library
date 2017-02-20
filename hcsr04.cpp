//    FILE: hcsr04.cpp

#include "hcsr04.h"

#define CM_IN_MM                                          10
#define HALF_CM_IN_MM_FOR_ROUNDING                         5

#define NO_CALIBRATION_NEEDED                            1.0
#define DEFAULT_CALIBRATION_MULTIPLIER NO_CALIBRATION_NEEDED
#define NO_OFFSET                                          0
#define DEFAULT_OFFSET                             NO_OFFSET

void HCSR04::init(unsigned char trigPin, unsigned char echoPin){
	myTrigPin = trigPin;
	myEchoPin = echoPin;

	pinMode(myTrigPin, OUTPUT);
  	pinMode(myTrigPin, INPUT);

  	myCalibrationMultiplier = DEFAULT_CALIBRATION_MULTIPLIER;
  	myOffsetInMm = DEFAULT_OFFSET;
}

void HCSR04::setCalibration(double calibrationMultiplier){
	myCalibrationMultiplier = calibrationMultiplier;
}

void HCSR04::setOffset(double offsetValueInMm){
	myOffsetInMm = offsetValueInMm;
}


long HCSR04::getDisctanceFromDurationInMm(long duration){
	
	long distanceInMm = (long)(((double)duration/2) / 2.91);

	if(myCalibrationMultiplier != NO_CALIBRATION_NEEDED){
		distanceInMm = (long)(((double)distanceInMm)*myCalibrationMultiplier);
	}

	if(myOffsetInMm != NO_OFFSET){
		distanceInMm += myOffsetInMm;
	}

	return distanceInMm;
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

unsigned short HCSR04::readDisctanceInMm(){
	return readDisctance();
}

unsigned short HCSR04::readDisctanceInCm(){
	return ((readDisctance()+HALF_CM_IN_MM_FOR_ROUNDING) / CM_IN_MM);
}
