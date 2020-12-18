#ifndef PLANETS_H
#define PLANETS_H

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


typedef struct PLANETS {
    double x,y;
    double mass;
    double xvel, yvel;
	  char *c;
} Planet;


Planet planet[9];

double findDistance(Planet planet1, Planet planet2){
    double run = planet2.x - planet1.x;
    double rise = planet2.y - planet1.y;
    double distance = sqrt(pow(run,2.0) + pow(rise,2.0));
    return(distance);
}

double findRun(Planet planet1, Planet planet2){
    double run = planet2.x - planet1.x;
    return(run);
}

double findRise(Planet planet1, Planet planet2){
    double rise = planet1.y - planet2.y;
    return(rise);
}

void changePosition(int planetnum) {
        double xacc, yacc, acc, angle;
        double distance = findDistance(planet[sun], planet[planetnum]);
        double run = findRun(planet[sun], planet[planetnum]);
        double rise = findRise(planet[sun], planet[planetnum]);
		// calculate acceleration, and angle, and portion of acceleration in x and y direction, and then change the velocities based on those accelerations
        acc = G*planet[sun].mass/(distance*distance); //find acceleration based on Gm/r^2
        angle = atan2(rise,run) / PI; // angle in xPi radians between the planet, sun, and x axis, first number is the y direction and the second is the x direction
        xacc = cos(PI*angle) * acc; //based on the angle just found, calculate the acceleration in the x direction
        yacc = sin(PI*angle) * acc; //based on the angle just found, calculate the acceleration in the y direction
        planet[planetnum].yvel += yacc; //finds how much the velocity is going to change based on the acceleration
        planet[planetnum].xvel -= xacc; //finds how much the velocity is going to change based on the acceleration
        planet[planetnum].y += planet[planetnum].yvel; //changes y position based on the new velocity
        planet[planetnum].x += planet[planetnum].xvel; //changes x position based on the new velocity
}


void drawPlanets() {
        for (int i=0;i<=8;i++)
        	mvprintw(planet[i].y, planet[i].x, planet[i].c); //prints the sun in the center`
}


#endif /* PLANETS_H */
