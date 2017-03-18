#include "game_2048.h"

void colo(void)
{
  init_color(COLOR_GREEN, 176 * 3, 159 * 3, 145 * 3);
  init_color(COLOR_RED, 176 * 5, 159 * 5, 145 * 5);
}
void draw_window(t_2048 *lst)
{
  int i;
  int j;
  WINDOW *win;
  start_color();
  colo();
  init_pair(1, COLOR_GREEN, COLOR_GREEN);
  init_pair(2, COLOR_RED, COLOR_RED);
  init_pair(3, COLOR_BLACK, COLOR_RED);
  i = 0;
  if (LINES < 40 || COLS < 40)
  {
    printw("Window too small, fuck you.");
    return ;
  }
  while (i < 4)
  {
    j = 0;
      while (j < 4)
      {
        win = subwin(stdscr, LINES / 4, COLS / 4, (LINES / 4 - 1) * i, (COLS / 4 - 1) * j);
        wbkgd(win, COLOR_PAIR(2));
        lst->wdow = subwin(stdscr, LINES / 4, COLS / 4, (LINES / 4 - 1) * i, (COLS / 4 - 1) * j);
        move((LINES / 4 - 1) * i + (LINES / 8), (COLS / 4 - 1) * j + (COLS / 8));
        attron(COLOR_PAIR(3));
        printw("%d", lst->map[i][j]);
        attroff(COLOR_PAIR(3));
        wattron(lst->wdow, COLOR_PAIR(1));
        wborder(lst->wdow, '|', '|', '-', '-', '+', '+', '+', '+');
        wattroff(lst->wdow, COLOR_PAIR(1));
        j++;
      }
      j = 0;
      i++;
  }
  wrefresh(lst->wdow);
}

int game_over(void)
{
  int key;
  start_color();
  keypad(stdscr, TRUE);
  set_escdelay(1);
  move(LINES * 0.46, COLS * 0.45);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  printw("GAME OVER.");
  attroff(COLOR_PAIR(1));
  move(LINES / 2, COLS / 5);
  printw("Partie terminee, appuyez sur une touche pour rejouez ou ESC pour quitter.");
  move(LINES * 0.55, COLS * 0.44);
  printw("Score : 42");
  key = getch();
  if (key == 27)
    return (0);
  else
    return (1);
}
