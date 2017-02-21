//    FILE: hcsr04.cpp

#include "hcsr04.h"

#define CM_IN_MM                                          10
#define HALF_CM_IN_MM_FOR_ROUNDING                         5

#define NO_CALIBRATION_NEEDED                            1.0
#define DEFAULT_CALIBRATION_MULTIPLIER NO_CALIBRATION_NEEDED
#define NO_OFFSET                                          0
#define DEFAULT_OFFSET                             NO_OFFSET
#define DELAY_BETWEEN_AVG_MEASUREMENTS_IN_MS              10


// Init

void HCSR04::init(unsigned char trigPin, unsigned char echoPin){
    myTrigPin = trigPin;
    myEchoPin = echoPin;

    pinMode(myTrigPin, OUTPUT);
    pinMode(myTrigPin, INPUT);

    myCalibrationMultiplier = DEFAULT_CALIBRATION_MULTIPLIER;
    myOffsetInMm = DEFAULT_OFFSET;
}


// Calibration

void HCSR04::setCalibration(double calibrationMultiplier){
    myCalibrationMultiplier = calibrationMultiplier;
}

double HCSR04::getCalibration(){
    return myCalibrationMultiplier;
}


// Offset

void HCSR04::setOffset(long offsetValueInMm){
    myOffsetInMm = offsetValueInMm;
}

long HCSR04::getOffset(){
    return myOffsetInMm;
}


// Calculation

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


// Main functionality - Distance measurement

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


// Main functionality - Distance measurement (avg of multiple results)

unsigned short HCSR04::readAvgDisctanceInMm(unsigned short measurementCount){
    if(measurementCount <= 1){
        // don't have to calculate average of 1 value, 
        // and we could not calculate average of 0 value
        return readDisctance();
    }

    unsigned long sum = 0;
    unsigned char i;
    for(i=0; i<measurementCount; i++){
        sum += readDisctance();
        delay(DELAY_BETWEEN_AVG_MEASUREMENTS_IN_MS);
    }
    // calculate avg value with mathematically correct rounding..
    unsigned short result = (((double)sum / measurementCount) + (double)0.5);
    return result;
}

unsigned short HCSR04::readAvgDisctanceInCm(unsigned short measurementCount){
    return ((readAvgDisctanceInMm(measurementCount)+HALF_CM_IN_MM_FOR_ROUNDING) / CM_IN_MM);
}