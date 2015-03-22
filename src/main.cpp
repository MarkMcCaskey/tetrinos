#include <cstdlib>
#include <iostream>
#include <GetOpt.h>

/*
 * Add command line arguments
 * ideas:
 * difficulty (speed), color, graphics 
 * debugging, etc.
 */


int main( int argc, char **argv )
{
  GetOpt getopt( argc, argv, "lscgd:" );
  int opt;
  int level;
  bool debug = false;
  while( ( opt = getopt() ) != EOF )
    {
      switch( opt )
	{
	case 'l':
	  level = atoi( getopt.optarg );
	  break;
	case 'd':
	  debug = true;
	  break;
	case 's':
	  break;
	case 'c':
	  break;
	case 'g':
	  break;
	default:
	  break;
	}
    }
  //load board
  //set up screen
  while( true ) //game loop
    {
      //take user input
      //action from input
      //check for collisions
      //check for lines? (maybe should go somewhere else)
      //update board
      //update screen
      if( true ) //end game conditional
	break;
    }
  exit( EXIT_SUCCESS );
}
