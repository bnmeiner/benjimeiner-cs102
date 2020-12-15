Planets.c Program:
This program computes real physics calculations to simulate planets moving around the sun

  The first part of the program includes the necessary files, ncurses (to print the planets), math.h (to use sin, cosine and power functions), and stdio.h. Next, we define the rest of the numbers needed for our program, delay, Gravitational constant (G), Pi, and then all the planets are given a number. 
   ```
  #include <ncurses.h>
  #include <unistd.h> 
  #include <stdio.h>
  #include <math.h>

  #define DELAY 70000
  #define G 25
  #define PI 3.14159265258979
  #define sun 0
  #define mercury 1
  #define venus 2
  #define earth 3
  #define mars 4
  #define jupiter 5
  #define satrun 6
  #define uranus 7
  #define neptune 8
  ```
  
  
  Then, a structure is defined with 6 variables, x and y which are going to be the position of the planet, mass, xvel and yvel which are the velocities in the x direction and velocity in the y direction, and a character which will be the symbol each planet is given. Then an array called planet[] is created of type "Planet"(which is our structure). 
  
  A couple of functions are now defined. 
      **findDistance**: computes distance between 2 planets using the distance formula.
      **findRun:** finds the distance in the x direction between 2 planets. (this will be necessary in addition to the distance)
      **findRise:** finds the distance in the y direction between 2 planets.
      **changePosition**: This function requires input of a number which represents the planet number (planetnum) and then changes the position based on the characteristics of that planet. Acceleration, x-acceleration, y-acceleration and angle variables are defined. Then the distance, run, and rise are calculated based on the previous functions. Then the acceleration is calculated based on GxM/r^2, which means gravitational constant times the mass of planet (this refers to the mass of the sun in this case) divided by the distance squared. This will get the acceleration of the planet being studied at its current position. Next, the angle that it makes with the sun is calculated with a function atan2(), which requires 2 inputs, the y distance (rise) and the x distance (run). This function is important because it will take into account whether the run or rise is negative and output the angle in the proper quadrant. Then, based on the total acceleration calculated, the xacc and yacc are calculated using sin and cosine functions of the angle multiplied by the acceleration. Now that the acceleration portions have been calculated, the velocities can now be changed. Planet[planetnum].yvel += yacc means, take the y velocity of the number planet that has been inputted and add to it the y acceleration. Then, with this new velocity, add it to the y position of that planet (same calculations for x). 
      **drawPlanets:** draws all the planets with mvprintw(y, x, char)
      
  Now for the main function. Each planet is given the characteristics from the structure (the sun does not need velocities, and the rest of the planets don't need mass because in this program they are not pulling other planets towards them, just the sun is. Only the mass of the object pulling the other one is needed for the acceleration). The ncurses screen is set and the drawPlanets function is used to draw the original positions of all the planets. Then a while loop is started, while(1), Which will just continue to loop forever. In this loop, each of the planets are inputted into the changePosition function, the screen is cleared, the planets are redrawn and then a delay between each of these calculations. 

      
