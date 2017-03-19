#include "game_2048.h"

void start(t_2048 *wkw)
{
	keypad(stdscr, TRUE);
    set_escdelay(1);
  	wkw->wdow = subwin(stdscr, LINES, COLS, 0, 0);
  	wborder(wkw->wdow, '/','/',  '/' , '/', '/','/', '/','/');
  	move(LINES * 0.5, COLS * 0.38);
  	printw("Welcome to my 2048 ! Press key for play");
	getch();
}
