//    FILE: hcsr04.h

#ifndef hcsr04_h
#define hcsr04_h

#if defined(ARDUINO) && (ARDUINO >= 100)
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif


class HCSR04 {

	private:
		unsigned char myTrigPin;
		unsigned char myEchoPin;
		double myCalibrationMultiplier;
		short myOffsetInMm;

		long getDisctanceFromDurationInMm(long duration);

	public:

		/*
		 * 	
		 */
        void init(unsigned char trigPin, unsigned char echoPin);

        void setCalibration(double calibrationMultiplier);

        void setOffset(double offsetValueInMm);

	    /*
	     * Returns the measured disctance in mm.
	     * (As mm is the default SI unit.)
	     */
	    unsigned short readDisctance();

	    /*
	     * Returns the measured disctance in mm.
	     */
	    unsigned short readDisctanceInMm();

	    /*
	     * Returns the measured disctance in cm.
	     */
	    unsigned short readDisctanceInCm();
};

#endif
