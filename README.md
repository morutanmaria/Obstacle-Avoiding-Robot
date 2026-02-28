Overview

This project is an autonomous robot that avoids obstacles using an ultrasonic distance sensor and reacts to ambient light levels with a light sensor. The robot is built with an Arduino, two DC motors, a servo-mounted ultrasonic sensor, and optionally an L298N motor driver.

It can:

Move forward when the path is clear

Stop in low-light conditions

Detect obstacles and decide whether to turn left or right based on available space

Problem Statement

Robots navigating an unknown environment must avoid collisions and adapt to lighting conditions. Many beginner robots simply move forward, causing them to collide with obstacles. Additionally, in low-light conditions, certain tasks may be unsafe or undesirable.

This project solves these problems by:

Automatically stopping in darkness

Detecting obstacles using a sonar sensor

Choosing the safest path using a servo to scan left and right

Hardware Components
Arduino UNO	- 1	Microcontroller
DC Motors	- 2	Left and Right wheels
L298N Motor Driver - 1	Controls motor direction and speed
HC-SR04 Ultrasonic Sensor -	1	Measures distance to obstacles
Servo Motor -	1	Rotates the ultrasonic sensor for scanning
Light Sensor (LDR) -	1	Detects ambient light levels
Jumper wires -	–	For connections
Battery pack -	1	Powers motors separately from Arduino

Hardware Schematic

<img width="1301" height="737" alt="tinkercad" src="https://github.com/user-attachments/assets/ff21eaa4-58ee-4b2c-bca0-07fa4ff57cb0" />

Code Logic

Light Sensor Priority

If ambient light is below a threshold, the robot stops immediately.

Obstacle Detection

The ultrasonic sensor measures the distance ahead.

If distance ≤ 25 cm, the robot stops, moves slightly forward, and scans left and right with the servo.

Decision Making

Compare distances left and right

Turn toward the side with more free space

Movement

Motors are controlled using PWM via the L298N

Forward, backward, turn left, turn right, and stop are implemented as functions

Servo Control

The servo rotates the ultrasonic sensor to 50° (right) and 170° (left) for scanning

Returns to 115° forward after each scan

Features

Fully autonomous movement

Obstacle detection and avoidance

Light-sensing safety stop

Servo-based scanning for better path decision

Usage

Connect all components as described in the wiring section.

Upload the Arduino code to your board.

Power the motors using a separate battery pack.

Place the robot in an environment with obstacles and light.

Observe autonomous obstacle avoidance and light-based stopping behavior.

Compatible with L298N or L293D motor drivers

Future Improvements

Add an LCD display to show sensor readings and robot status

Implement non-blocking movement using millis() instead of delay()

Integrate line-following or light-seeking behavior
![WhatsApp Image 2026-01-19 at 23 21 36](https://github.com/user-attachments/assets/8f09403a-2058-4f21-8fe0-c966bea9f8a6)
![WhatsApp Image 2026-01-19 at 23 21 31](https://github.com/user-attachments/assets/31e865f5-b02f-412c-bc11-c7021c01e468)

