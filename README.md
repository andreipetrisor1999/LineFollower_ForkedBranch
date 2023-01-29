# LineFollower - Lightning McQueen

### 🏁 ◼◼◼ 🏎

## About

Arduino two-person project developed during a one-day hackathon, at the Introduction to Robotics course taken in the 3rd year at the Faculty of Mathematics and Computer Science, University of Bucharest.

## Project Details 📑

**Requirements:** Program the makeshift car, so that it follows the racetrack consisting of a black line that loops, as fast and as correct (no shortcuts between parts of the track, no leaving the track, and no turning back on the track; the only allowed movement is the continuous movement along the black line) as possible. The QTR sensor should calibrate itself right before the robot starts traversing the track (meaning no manual calibration of the sensor). Using a PID controller, define the characteristics of the robot's movement.

**Functionality:** At first, while on top of the black line, the robot calibrates its sensor by repeatedly moving left and right, learning this way to recognize the black line whenever it appears in front of the sensor, and to dismiss surfaces other than the black line. After a short period of calibration, the robot will attempt to follow any black surface in front of its sensor, while attempting to calculate its speed and to determine its movement behavior through the use of a PID controller.

**The PID algorithm:** The values for the PID controller were chosen randomly at first to observe the behaviour of the robot (not counting the I variable). After many test drives, the numbers present in the code above pushed the robot close to it's full potential. In the end, all of the PID controlled values were used.

> Note: Our team's robot managed to finish the racetrack below in **15.430 seconds**!

**Components Used:**
* 1 Arduino Uno
* 1 QTR-8A reflectance sensor
* 2 DC motors
* 1 L293D motor driver
* 1 LiPo battery (power source)
* 2 wheels
* 1 ball caster
* 1 breadboard (medium; 400 pts)
* wires (per logic)

**Racetrack Picture:**

![racetrack](https://user-images.githubusercontent.com/87432371/213283226-c7c55969-2e19-4f83-b589-6c5681b6e521.jpeg)

**Robot Setup Pictures:**

![from the side](https://user-images.githubusercontent.com/87432371/213257714-dea2f7b3-b9df-413d-8651-d11315612f7a.jpeg)

![from the back](https://user-images.githubusercontent.com/87432371/213258241-515ff87a-385a-4171-9397-d99bdc7f5bd8.jpeg)

![from above](https://user-images.githubusercontent.com/87432371/213258269-01c975a0-e59b-475a-9e8f-da9e161ece65.jpeg)

![from the front](https://user-images.githubusercontent.com/87432371/213258303-9be18188-8e27-4d28-aa3b-0b191b589f92.jpeg)

**Robot Showcase 🤖:** https://www.youtube.com/watch?v=77cRA0fMZrk&ab_channel=AlexandruSasu

## Project Contributors 💻

- [https://github.com/alexsasu](https://github.com/alexsasu/LineFollower)
- [https://github.com/andreipetrisor1999](https://github.com/andreipetrisor1999/LineFollower_ForkedBranch)
