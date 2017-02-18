# Arduino HC-SR04 library

An arduino library to handle HC-SR04 distance sensor.

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

### ToDo list:
- [ ] try out the example with real hardwares.
