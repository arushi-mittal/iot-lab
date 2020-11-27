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
![Circuit Diagram Part a](https://github.com/arushi-mittal/iot-lab/blob/main/exp_2a.png?raw=true)
![Circuit Diagram Part b](https://github.com/arushi-mittal/iot-lab/blob/main/exp_2b.png?raw=true)

Simulation available at: https://www.tinkercad.com/things/8SX81wViSlj and https://www.tinkercad.com/things/1mHW409toxf

Experiment 3

An experiment to control a servo motor using Thingspeak.com channel data.

An account was set up on Thingspeak to create a new channel. API keys were used to enter data into the channel. 
The password and SSID were stored to start communication, and a Wi-Fi client was instantiated. 

In the loop function, we kept connected to wifi and checked status, and continued to read from private channel. 
If the status code of the information received was 200, the servo motor shaft was rotated by the value given. 

Status code was read using ThingSpeak.getLastReadStatus().