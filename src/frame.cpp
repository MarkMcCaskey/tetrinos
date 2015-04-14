#include "../inc/frame.h"

Frame::Frame(int x, int y, int row, int col)
{
    window = newwin(x, y, row, col);
    xy.first = x; xy.second = y;
    rc.first = row; rc.second = col;
}

Frame::~Frame()
{
    delwin(window);
}

void Frame::add(char c, int x, int y)
{
    mvaddch(window, x, y, c);   
}

void Frame::refresh()
{
  wrefresh(window);
}
