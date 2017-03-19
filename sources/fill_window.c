#include "game_2048.h"

void colo(void)
{
  init_color(FOND, 187 * 3, 173 * 3, 160 * 3);
  init_color(ZERO, 205 * 4, 193 * 4, 180 * 4);
  init_color(CHIFFRE, 119, 110, 101);
  init_color(DEUX, 238 * 4, 228 * 4, 218 * 4);
  init_color(QUATRE, 237 * 4, 224 * 4, 200* 4);
  init_color(HUIT, 242 * 5, 177 * 5, 121 * 5);
}
short get_color(short val)
{
	short t[10] = {0, 2, 4, 8, 16, 32, 64, 128, 256, 512};
	short i;

	i = 0;
	while (t[i] != val)
		i++;
	return (i + 11);
}
void draw_window(t_2048 *lst)
{
  int i;
  int j;
  short tmp;
  short b = 4;
  WINDOW *win;

  init_pair(1, FOND, FOND);
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
		tmp = get_color((short)lst->map[i][j]);

		init_pair(b, tmp, tmp);

		init_pair(2000, CHIFFRE, tmp);
        wbkgd(win, COLOR_PAIR((chtype)b));
		b++;
        lst->wdow = subwin(stdscr, LINES / 4, COLS / 4, (LINES / 4 - 1) * i, (COLS / 4 - 1) * j);
        move((LINES / 4 - 1) * i + (LINES / 8), (COLS / 4 - 1) * j + (COLS / 8));
        attron(COLOR_PAIR(25));
		if (lst->map[i][j] != 0)
        	printw("%d", lst->map[i][j]);
        attroff(COLOR_PAIR(25));
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

  move(LINES * 0.46, COLS * 0.44);
  init_pair(5, COLOR_RED, COLOR_BLACK);
  attron(COLOR_PAIR(5));
  printw("GAME OVER.");
  attroff(COLOR_PAIR(5));
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
