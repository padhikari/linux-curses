#include<stdio.h>
#include<stdlib.h>
#include<curses.h>

int main(){
	initscr();
	move(5,25);
	printw("%s", "hello World");
	refresh();
	sleep(2);
	endwin();
	exit(EXIT_SUCCESS);
}
