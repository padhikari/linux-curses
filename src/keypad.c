#include<unistd.h>
#include<stdlib.h>
#include<curses.h>

#define LOCAL_ESCAPE_KEY 27

int main(){

	int key;
	initscr();
	crmode();
	keypad(stdscr, TRUE);
	
	//turn echo off to prevent the cursor from being moved when some cursor keys are pressed
	noecho();
	//the screen is cleared and some text displayed
	clear();
	mvprintw(5,5,"Key pad demonstration. Press 'q' to quit");
	move(7,5);
	refresh();
	
	//program waits for each keystroke and unless it is Q or produces an error
	key = getch();
	while(key != ERR && key !='q'){
		move(7,5);
		clrtoeol();
		
		if((key >= 'A' && key <= 'Z') ||(key >= 'a' && key <= 'z')){
			printw("key was %c", (char)key);
		}
		else{
			switch(key) {
				case LOCAL_ESCAPE_KEY: printw("%s", "Escape key"); 					break;
				case KEY_END: printw("%s", "END key"); 
				break;
				case KEY_BEG: printw("%s", "BEGINNING key");
				break;
				case KEY_RIGHT: printw("%s", "RIGHT key"); 
				break;
				case KEY_LEFT: printw("%s", "LEFT key"); 
				break;
				case KEY_UP: printw("%s", "UP key"); 
				break;
				case KEY_DOWN: printw("%s", "DOWN key"); 
				break;
				default: printw("Unmatched - %d", key); 
				break;
			}
		}	
		refresh();
		key = getch();
	}
	endwin();
	exit(EXIT_SUCCESS);

}
