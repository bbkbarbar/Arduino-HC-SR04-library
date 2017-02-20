# Arduino HC-SR04 library

An arduino library to handle HC-SR04 distance sensor.

[Download](https://github.com/bbkbarbar/Arduino-HC-SR04-library/archive/master.zip)  as .zip file

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

### Functions
###### Initialize
```
void init(unsigned char trigPin, unsigned char echoPin);

/*
 *  Initialite the ButtonHandler object
 *  Parameters:
 *    trigPin:       The pin of arduino what is connected to trig pin of HC-SR04 sensor
 *    echoPin:       The pin of arduino what is connected to echo pin of HC-SR04 sensor
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


### ToDo list:
- [ ] try out the example with real hardwares.
- [ ] implement "safety" functions e.g: isTooClose() and isTooFar()
