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

        unsigned short delay_between_avg_measurements_in_ms;

        /*
         * Calculate the distance from duration
         */
        long getDisctanceFromDurationInMm(long duration);

    public:

        /*
         * Initialize HCSR04 instance
         * Parameter:
         *     trigPin:
         *     echoPin:
         */
        void init(unsigned char trigPin, unsigned char echoPin);

        /*
         * Initialize HCSR04 instance
         * Parameter:
         *     trigPin:
         *     echoPin:
         *     delayForAvgMeasurement:
         */
        void init(unsigned char trigPin, unsigned char echoPin, unsigned short delayForAvgMeasurement);

        
        void setCalibration(double calibrationMultiplier);

        double getCalibration();


        void setOffset(long offsetValueInMm);

        long getOffset();


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


        /*
         * Returns the average of measured disctance in mm.
         * (As mm is the default SI unit.)
         * Parameter:
         *     measurementCount: The count of measurements what will be used to calculate average
         */
        unsigned short readAvgDisctanceInMm(unsigned short measurementCount);

        /*
         * Returns the average of measured disctance in cm.
         * Parameter:
         *     measurementCount: The count of measurements what will be used to calculate average
         */
        unsigned short readAvgDisctanceInCm(unsigned short measurementCount);


        /*
         * Returns the average of measured disctance in cm.
         * Parameter:
         *     delayInMs: 
         */
        void setDelayBetweenAvgMeasurementsInMs(unsigned short delayInMs);

        /*
         * Read distance 5 times, drop the minimum and the maximum values
         * And return the average of the middle 3 measurement result in mm.
         */
        unsigned short readAccurateDisctanceInMm();

        /*
         * Read distance 5 times, drop the minimum and the maximum values
         * And return the average of the middle 3 measurement result in cm.
         */
        unsigned short readAccurateDisctanceInCm();

};

#endif
