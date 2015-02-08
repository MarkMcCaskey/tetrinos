#include "graphics.h"

void setUpNcruses( void )
{
    /*
     * non-trivial sections of code here are from
     * https://solarianprogrammer.com/2012/07/12/roguelike-game-cpp-11-part-1/
     */
    initscr();
    clear();
    noecho();
    cbreak();
    keypad( stdscr, TRUE );
    curs_set( 0 );

}

void updateScreen( void )
{

    //Maybe put input logic somewhere else
    int ch;

    ch = getch();

    switch( ch )
    {
    case 'q':
    case 'Q':
	shutDownNcurses();
	break;
    default:
	break;
	
    }
    
}

void shutDownNcurses( void )
{
    endwin();
}
