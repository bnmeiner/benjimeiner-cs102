#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

#define DELAY 70000
#define G 25
#define PI 3.14159265258979

double findDistance(double x1, double y1, double x2, double y2){	
    double run = x2 - x1;
    double rise = y2 - y1;
    double distance = sqrt(pow(run,2.0) + pow(rise,2.0));
	return(distance);
}
/*
typedef struct PLANET {
	double x,y; 
	double mass;
	double xvel, yvel;
	double acc, xacc, yacc; 
	double angle;
} ; 
	*/

int main(int argc, char *argv[]) {
// sun  
	double suny = 25, sunx = 60; 
	double mass = 4;
// first planet 
	double y= 25, x = 80; 
	double yvel = 2, xvel = 0;
	double acc, xacc, yacc; 
	double angle;

		// set the screen and draw circles 
		initscr();
		noecho();
		curs_set(FALSE);
 		clear(); // Clear the screen of all previously-printed characters

			mvprintw(suny, sunx, "o"); //prints the sun in the center
			mvprintw(y, x, "o"); //prints the first plant

		refresh();
 		usleep(DELAY); // Shorter delay between movement

	while(1) {

// finds distance between planets
	double distance = findDistance(sunx, suny, x, y);	
    double run = x - sunx;
    double rise = suny - y;
// calculate acceleration, and angle, and portion of accelration in x and y direction, and then change the velocities based on those accelerations 
 	acc = G*mass/(distance*distance); //find acceleration based on Gm/r^2
	angle = atan2(rise,run) / PI; // angle in xPi radians between the planet, sun, and x axis, first number is the y direction and the second is the x direction 
	xacc = cos(PI*angle) * acc; //based on the angle just found, calculate the acceleration in the x direction 
	yacc = sin(PI*angle) * acc; //based on the angle just found, calculate the acceleration in the y direction	
	yvel = yvel + yacc; //finds how much the velocity is going to change based on the acceleration
	xvel = xvel - xacc; //finds how much the velocity is going to change based on the acceleration
	y = y +	yvel; //changes y position based on the new velocity
	x = x + xvel; //changes x position based on the new velocity
		//print new circle
 		clear(); // Clear the screen of all previously-printed characters
		mvprintw(suny, sunx, "o"); //prints the sun in the center
		mvprintw(y, x, "o"); //prints the first plan
		refresh();
 		usleep(DELAY); // Shorter delay between movement
}

 endwin();
}

