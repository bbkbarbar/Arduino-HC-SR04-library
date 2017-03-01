# Arduino HC-SR04 library

An arduino library to handle HC-SR04 distance sensor.


### Basic useage
```
#include <hcsr04.h>

#define TRIG_PIN    4
#define ECHO_PIN    3

HCSR04 mySensor;
unsigned short distance;

void setup() {         

  mySensor.init(TRIG_PIN, ECHO_PIN);

}

void loop(){

  distance = mySensor.readDisctanceInMm();

  // Do something with measured distance value
}
```

### Installion

- Clone or [download as a .zip file](https://github.com/bbkbarbar/Arduino-HC-SR04-library/archive/master.zip) and unpack this repository directly into  "libraries" folder of Arduino IDE (e.g.: *c:\Program Files (x86)\Arduino\libraries\* )
- Restart Arduino IDE.
- Now you can find and use this library from *Sketch > Include library > "Arduino-HC-SR04-library"*


### Functions
###### Initialize
```
void init(unsigned char trigPin, unsigned char echoPin);

/*
 *  Initialite the ButtonHandler object
 *  Parameters:
 *      trigPin:   The pin of arduino what is connected to trig pin of HC-SR04 sensor
 *      echoPin:   The pin of arduino what is connected to echo pin of HC-SR04 sensor
 */
```

###### readDisctance
```
unsigned short readDisctance();

/*
 *  Read disctance
 *  Returns:
 *      the disctance in mm.
 */
```

###### readDisctanceInCm
```
unsigned short readDisctanceInCm();

/*
 *  Read disctance in cm
 *  Returns:
 *      the disctance in cm
 *      (rounded value from mm value
 *      with mathematically corrent rounding).
 */
```

###### readAvgDisctanceInMm
```
unsigned short readAvgDisctanceInMm(unsigned short measurementCount);

/*
 *  Read disctance in mm by multiple measurement
 *  and calculate average of results
 *  Parameter:
 *      measurementCount: The count of measurements what will be used to calculate average
 *  Returns:
 *      the average of multiple disctance measurement in mm.
 */
```

###### readAvgDisctanceInCm
```
unsigned short readAvgDisctanceInCm(unsigned short measurementCount);

/*
 *  Read disctance in cm by multiple measurement
 *  and calculate average of results
 *  Parameter:
 *      measurementCount: The count of measurements what will be used to calculate average
 *  Returns:
 *      the average of multiple disctance measurement in cm.
 *      (rounded value from mm value
 *      with mathematically corrent rounding).
 */
```

###### setCalibration
```
void setCalibration(double calibrationMultiplier);

/*
 *  Set calibration multiplier
 *  Default is 1.0
 */
```
###### getCalibration
```
double getCalibration();

/*
 *  Returns:
 *      Current calibration multiplier.
 */
```

###### setOffset
```
void setOffset(long offsetValueInMm);

/*
 *  Set offset for disctance measurement.
 *  Default is 0 mm.
 */
```
###### getOffset
```
long getOffset();

/*
 *  Returns:
 *      Current ofset offset for disctance measurement.
 */
```

###### setDelayBetweenAvgMeasurementsInMs
```
void setDelayBetweenAvgMeasurementsInMs(unsigned short delayInMs);

/*
 * Returns the average of measured disctance in cm.
 * Parameter:
 *     delayInMs:
 */
```

###### readAccurateDisctanceInMm
```
unsigned short readAccurateDisctanceInMm();
/*
 * Read distance 5 times, drop the minimum and the maximum values
 * And return the average of the middle 3 measurement result in mm.
 */
```

###### readAccurateDisctanceInCm
```
unsigned short readAccurateDisctanceInCm();
/*
 * Read distance 5 times, drop the minimum and the maximum values
 * And return the average of the middle 3 measurement result in mm.
 */
```

### ToDo list:
- [x] try out the example with real hardwares.
- [ ] implement "safety" functions e.g: isTooClose() and isTooFar()
