Experiment 1

An IoT experiment to vary the orientation of the servo motor and blink an LED when an object is detected at less than 50 cm, using interrupts.

An interrupt is the process of forcing a microcontroller to suspend the curren job and perform a higher priority job.

This experiment requires an Arduino Uno R3, an ultrasonic distance sensor, micro servo, 220 Ohms Resistor and Red LED.

We use an interrupt service routine (ISR) to rotate the servo motor to 90 degrees. 
We attach a pin for external interrupts and an outpin to the resistor.

The loop functions reads the distance using the readUltrasonicDistance function and convert to centimetres. I
If the distance is less than 50 cm, trigger the interrupt by calling ISR.

![Circuit Diagram](https://github.com/arushi-mittal/iot-lab/blob/main/exp_1.png?raw=true)

Simulation Available at: https://www.tinkercad.com/things/8ROSjSCK7tE

Experiment 2

An IoT experiment to vary motor speed and LED intensity using PWM (pulse width modulation).

The analog input from a potentiometer is used to control the speed of the motor.

The analogread() and analogwrite() functions were used to read potentiometer signals and writing PWM signals.


The potentiometer reading is read using analogread and divided by 4 before writing to the analog pins to ensure correct range is used.

An NPN transistor is used to amplify voltage so it can be scaled for the motor from 5V to 9V.

Ouput PWM signal is given to the base of the transistor and the new output comes from the emitter, which is connected to the terminal of the motor. 

Simulation available at: https://www.tinkercad.com/things/8SX81wViSlj and https://www.tinkercad.com/things/1mHW409toxf
