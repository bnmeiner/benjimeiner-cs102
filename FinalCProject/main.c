#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "planets.h"


int main(int argc, char *argv[]) {
// Sun planet 
    planet[sun].x = 60;
    planet[sun].y = 37;
    planet[sun].mass=4;
    planet[sun].c = "S";
// mercury planet
    planet[1].x = 75;
    planet[1].y = 37;
    planet[1].xvel = 0;
    planet[1].yvel = 2;
    planet[1].c = "m";
// venus planet
    planet[2].x = 77;
    planet[2].y = 37;
    planet[2].xvel = 0;
    planet[2].yvel = 2;
    planet[2].c =  "v";
// earth planet
    planet[earth].x = 79;
    planet[earth].y = 37;
    planet[earth].xvel = 0;
    planet[earth].yvel = 2;
    planet[earth].c = "e";
// mars planet
    planet[mars].x = 81;
    planet[mars].y = 37;
    planet[mars].xvel = 0;
    planet[mars].yvel = 2;
    planet[mars].c = "M";
// jupiter planet
    planet[5].x = 83;
    planet[5].y = 37;
    planet[5].xvel = 0;
    planet[5].yvel = 2;
    planet[5].c = "J";
// saturn planet
    planet[6].x = 85;
    planet[6].y = 37;
    planet[6].xvel = 0;
    planet[6].yvel = 2;
    planet[6].c = "s";
// uranus planet
    planet[7].x = 87;
    planet[7].y = 37;
    planet[7].xvel = 0;
    planet[7].yvel = 2;
    planet[7].c = "U";
// Neptune planet
    planet[8].x = 89;
    planet[8].y = 37;
    planet[8].xvel = 0;
    planet[8].yvel = 2;
    planet[8].c = "N";

// set the screen and draw circles
        initscr();
        noecho();
        curs_set(FALSE);
        clear(); // Clear the screen of all previously-printed characters
        refresh();
        drawPlanets();
        usleep(DELAY); // Shorter delay between movement

        while(1) {
			for(int i=1; i<=8; i++){
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
