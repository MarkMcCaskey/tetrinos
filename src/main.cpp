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
  GetOpt getopt( argc, argv, "lcgdh:" );
  int opt;
  int level;
  bool debug = false;
  int graphic_type = 0;
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
	case 'c':
	  break;
	case 'g':
	  graphic_type = getopt.optarg;
	  break;
	case 'h': default:
	  std::cout << "Tetrinos:" << std::endl << argv[0] << " -l 1-9 set the difficulty";
	  std::cout << std::endl << "\t-d turn on debug mode" << std::endl;
	  std::cout << "\t-c set color mode" << std::endl << "-g 0-1 set graphic type";
	  std::cout << std::endl;
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
