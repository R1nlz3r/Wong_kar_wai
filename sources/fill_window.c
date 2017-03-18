#include "game_2048.h"

void draw_window(t_2048 *lst)
{
  int i;
  int j;

  i = 0;
  while (i < 4)
  {
    j = 0;
      while (j < 4)
      {
        lst->wdow = subwin(stdscr, LINES / 4, COLS / 4, (LINES / 4 - 1) * i, (COLS / 4 - 1) * j);
        move((LINES / 4) * i + (LINES / 8) - 2 , (COLS / 4) * j + (COLS / 8) - 2);
        printw("%d", lst->map[i][j]);
        wborder(lst->wdow, '|', '|', '-', '-', '+', '+', '+', '+');
        j++;
      }
      j = 0;
      i++;
  }
  wrefresh(lst->wdow);
}
