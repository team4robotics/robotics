# Activities

## 2022-09-17 

* Started work on the F2L aspect of the code
* Inquired about 3D Printing material as well as pricing and location for pick-up
* Making CAD models with precision models for 3D printing

## 2022-09-10 

* Received materials and built Robot Framework
* Constructed 3D Model of the Robot on TinkerCAD
* Experimented with different gear ratios and decided on the one to use

## 2022-08-27

* Debugged last times code
* Solved problem of white faces on the other side
  * Figured out a way to move white face to other side
* Made first design for clasp
  * Uses a removable piece that slides along the shaft for easy removal of cube
  * Created animation and renders
* Renders
![claspV1](images/claspV1.png)
![claspV1Detail](images/claspV1Detail.png)
![claspV1Detail2](images/claspV1Detail2.png)
* Rough Animation
  ![claspV1Animation2](images/claspV1Animation2.avi)
  * Rendered and animated using Fusion 360

## 2022-08-20

* Finished white cross algorithm for one of 6 possible scenarios
  * Algorithm should be easy to duplicate for other possible scenarios
* Finalized build plans for robot
* Discussed how to transfer rotational force from motor to cube
   * Sorbothane pads currently best solution
   * Glue can also be used

## 2022-08-13

* Discussed how to "hold onto" the middle piece of a side
  * 3D printed model for connector piece (?)
  * Double-sided tape/Sorbothane for added friction
	* Stick one on 3D model, one on middle piece of a side
* Discussed how to mount the vision sensors
  * 3D printed mount for the vision sensors
* Discussed a way to code the white cross
  * Complete the white cross; disregard the side colours
  * Solve the side colours

## 2022-08-06

* Completed the Rubik's cube turn functions
* Learned a more efficient way to solve a Rubik's cube
* Designed a new model to consider the bottom motor (See image below)
![sketch.v1.0-1](images/sketch.v1.0-1.jpg)
* Finalized and ordered the Parts List

## 2022-07-16

* Discussed options to hold cube and rotate with motor.
* Discussed new model of build.
  * Size 
  * Shape
  * Motor placement
* Drew a new model
* Started to acquire parts
* Made design to hold rubix cube
* Discussed formulas to solve cube
  * Thistlethwaite's 52 move algorithm
  * CFOP method
  * https://www.youtube.com/watch?v=MS5jByTX_pk
* Started to learn CFOP 
  * Cross
  * F2L
  * OLL
  * PLL
* Started function list on Visual Studio
* Discussed more details on rubix cube code
* Started to fix old code from last week.
* Talked about new details on 3D printing software and example. 
* Reasearched 3D printing for different parts.
* Reasearched 3D printing for different parts.

## 2022-06-25

* Discussed different methods to build robot
* Everyone listed pros of their method, and were put on the spot to try and come up with solutions to the cons brought up by peers (specifics listed below)
* Eventually decided to go with the standard "6-motor" design where frame wraps around cube and individual motors control sides
 * Agreed that this would be te easiest to program, along with being fast and efficient and relatively simple mechanically without complicated gearing or heavy reliance on 3d-printed, custom parts
 * Discussed ways to assemble frame for structure
 * Discussed ways to mount Motor (c-channel, l-channel, or flat metal strip) and ways to mount Vision Sensor at optimal angle (zip ties, brackets, MPL 3D printers and TinkerCad) 
 * Discussed ways to "hold" the rubiks cube (glue, rubber, frame, or MPL 3D Printers and TinkerCad) 
 * Currently prefering l/c-channels for motor attatchment and exploring 3D printing options for the rest
* Created rough sketches (coming soon) of the robot
* Mapped out a parts list (below) based on design (not final yet, first draft)
* Specifics of different design's pros and cons:
  * Rubix "1.0" (https://www.youtube.com/watch?v=bGxpXlIaIaA)
    * PROS
      * Simple 
      * Less motors and sensors and parts compared to other options.
    * CONS
      * Slow
      * Harder to code
      * Possible mechanical programs
      * Accuracy 
   * "Parts List"
      * Requires 2 colour sensors
      * Requires 2 motors
      * Requires Brain
      * Requires Booster pack
* Rubix 2.0 (https://www.youtube.com/watch?v=L6gSuM-JHgo)
  * PROS
    * Relatively simple
    * Versatile
    * Faster than 1.0
  * CONS
    * Slow compared to other methods
    * Complicated programming
    * Can use function to track sides and convert conventional input into instructions for robot to make programming simpler
    * Relatively complicated mechanically, may require 3d printed parts for optimal function
    * Higher chance of failure compared to other designs
    * complicated gearing and mechanisms
  * "Parts List"
    * requires unique parts
      * large metal bracket
      * complicated structure
      * need a part to hold the rubiks cube
      * may need a weight to keep from moving
    * Approx6 assorted small metal parts for base frame
    * 10 small custommetal parts (possibly 3d printed) for rubiks holder
    * At least 3 motors
    * Mounting bracket for frame
    * Mostly small parts, but need many custom shapes 
    * Cable management may be a problem 
* Conventional "6-motor" fast-solver design
  * PROs
    * Simple idea
    * Versatile
    * Very fast
    * (debatable) Simple code
  * CONs
    * Complex design
    * Hard to hold onto the faces
  * "Parts List"
    * 6 motors
    * 6 metal beams
    * 2 vision sensors
    * ~1 Booster Pack
    * Something to hold onto the faces
* Parts List Draft
  Format: (Quantity needed)QTY (Name) (VEX Part #) FOR (purpose)
    * 14QTY 2*1*2*1*25 Aluminum C-Channel 276-2288 FOR MAIN STURCUTRE FRAME
    * 8QTY 2*2*25 Aluminum Angle 276-2304 FOR easy remove top
    * 6QTY 4” Shaft 276-3523 FOR Motor control over rubiks cube 
    * 2QTY Vision Sensor 276-4850
    * 2QTY (+4 we have) Smart Motor 276-4840
    * 6QTY Smart Motor 100RPM Cartridge 276-5840
    * Custom Parts:
      * 6QTY 3D Printed Cube Bracket
      * 2QTY 3D Printed Mounting Bracket for Vision Sensor

## 2022-06-11

* Learned Rubik's Cube Algorithms(White Cross, White Corners(ULDR), Middle Layer(ULDR), 
  Yellow Cross(ULDR), Match Edges(ULDLURR), Match Corners(URULDRD), Solve(ULDR))
* Discussed Model Options
* Created List of Required Parts
* Learned Rubik's Cube Algorithms
  * White Cross
  * White Corners(ULDR)
  * Middle Layer(ULDR)
  * Yellow Cross(ULDR)
  * Match Edges(ULDLURR)
  * Match Corners(URULDRD)
  * Solve(ULDR)
* Discussed Model Options
  * [RUBIX - VEX IQ Rubik's Cube Solver](https://www.youtube.com/watch?v=bGxpXlIaIaA)
  * [RUBIX 2.0 - VEX IQ Rubik's Cube Solver](https://www.youtube.com/watch?v=L6gSuM-JHgo)
    * Pros:
      * Requires less motor (More stable)
      * Requires fewer parts
      * Simpler (More reliable)
    * Cons:
      * Slow (more moves)
      * Logic is quite Complex(with only one rotating face, keeping track of where each face becomes difficult)
  * https://www.youtube.com/watch?v=wLzn1w8vgM4
  * https://www.youtube.com/watch?v=GJKdbGAF9H0
* Tasks:
  * Design
  * Parts
    * Vision Sensor x 1
  * Build Robot
  * Coding
    * Status Recognition
    * Solver
      * data structure
      * move functions
      * algorithm
  * Optimization

  ![20220611_001](images/20220611_001.jpg)

## 2022-05-07

* Experimented and debugged tank-drive using callback functions
* Experimented with event functions

![20220507_003](images/20220507_003.jpg)

## 2022-04-23

* Tested programs to control the drivetrain using the two bumpers
* Tested programs to control the drivetrain using the controller

![20220423_001](images/20220423_001.jpg)

## 2022-04-02

* Fixed the issue with the arm
* Ran the Clawbot using the controller without coding
* Removed arm and claw

![20220402_001](images/20220402_001.jpg)
