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
}

double findRun(Planet planet1, Planet planet2){
}

double findRise(Planet planet1, Planet planet2){
}

void changePosition(int planetnum) {
}


void drawPlanets() {
}


#endif /* PLANETS_H */
