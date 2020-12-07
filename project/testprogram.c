#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

#define DELAY 70000
#define G 25
#define PI 3.14159265258979
#define sun 0
#define earth 1
#define mars 2
#define SUN planet[sun]
#define EARTH planet[earth]
#define MARS planet[mars]

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
        double distance = findDistance(SUN, planet[planetnum]);
        double run = findRun(SUN, planet[planetnum]);
        double rise = findRise(SUN, planet[planetnum]);

// calculate acceleration, and angle, and portion of acceleration in x and y direction, and then change the velocities based on those accelerations
        acc = G*SUN.mass/(distance*distance); //find acceleration based on Gm/r^2
        angle = atan2(rise,run) / PI; // angle in xPi radians between the planet, sun, and x axis, first number is the y direction and the second is the x direction
        xacc = cos(PI*angle) * acc; //based on the angle just found, calculate the acceleration in the x direction
        yacc = sin(PI*angle) * acc; //based on the angle just found, calculate the acceleration in the y direction

        planet[planetnum].yvel += yacc; //finds how much the velocity is going to change based on the acceleration
        planet[planetnum].xvel -= xacc; //finds how much the velocity is going to change based on the acceleration
        planet[planetnum].y += planet[planetnum].yvel; //changes y position based on the new velocity
        planet[planetnum].x += planet[planetnum].xvel; //changes x position based on the new velocity
}


void drawPlanets() {
        for (int i=0;i<=2;i++)
        	mvprintw(planet[i].y, planet[i].x, planet[i].c); //prints the sun in the center`
}


int main(int argc, char *argv[]) {
    SUN.x = 60;
    SUN.y = 25;
    SUN.mass=4;
    SUN.c = "s";

// earth planet
    EARTH.x = 80;
    EARTH.y = 25;
    EARTH.xvel = 0;
    EARTH.yvel = 2;
    EARTH.c = "e";

// mars planet
    MARS.x = 77;
    MARS.y = 25;
    MARS.xvel = 0;
    MARS.yvel = 2;
    MARS.c = "m";



// set the screen and draw circles
        initscr();
        noecho();
        curs_set(FALSE);
        clear(); // Clear the screen of all previously-printed characters
        refresh();
        drawPlanets();
        usleep(DELAY); // Shorter delay between movement

        while(1) {
			for(int i=1; i<=2; i++){
			changePosition(i);
			}
            //print new circle
            clear(); // Clear the screen of all previously-printed characters
				drawPlanets();
            refresh();
            usleep(DELAY); // Shorter delay between movement
}

 endwin();
}
