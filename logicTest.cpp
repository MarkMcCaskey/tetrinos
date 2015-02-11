#include "logic.cpp"
#include <iostream>
#include <cstdlib>
#include <unistd.h>

int main( int, char** );
void printCoords( block* );
bool rotationTest( bool );
void printBlock( block* );
bool collisionTest( bool );
bool fallingTest( bool );
bool boardHandling( bool );

int main( int argc, char** argv )
{
  bool verbose = false;
  bool rton = false;
  bool cton = false;
  bool fton = false;
  int opt;

  while( (opt = getopt( argc, argv, "v") ) != -1 )
    {
      switch( opt )
	{
	case 'v':
	  verbose = true;
	  break;
	case 'r':
	  rton = true;
	  break;
	case 'c':
	  cton = true;
	  break;
	case 'f':
	  fton = true;
	  break;
	case 'a':
	  rton = true;
	  cton = true;
	  fton = true;
	  break;
	default:
	  fprintf( stderr, "Usage: %s -v", argv[0] );
	  break;
	}
    }
  
  bool rt;
  bool ct;
  bool ft;
  
  if( rton )
    {
      if( verbose )
	std::cout << "Rotation Test : ";
      rt = rotationTest( verbose );
    }
  
  if( cton )
    {
      if( verbose )
	std::cout << std::endl << "Collision Test : ";
      ct = collisionTest( verbose );
    }
  
  if( fton )
    {
      if( verbose )
	std::cout << std::endl << "Falling Test : ";
      ft = fallingTest( verbose );
    }

  if( rton )
    std::cout << "Rotation Test : " << (rt ? "PASSED" : "FAILED") << std::endl;
  if( cton )
    std::cout << "Collision Test : " << (ct ? "PASSED" : "FAILED") << std::endl; 
  if( fton )
    std::cout << "Falling Test : " << (ft ? "PASSED" : "FAILED") << std::endl;
  if( rton || cton || fton )
    std::cout << std::endl << "Overall results : " << std::endl;

  exit( EXIT_SUCCESS );
}

void printCoords( block *b )
{
  for( int i = 0; i < PIECES_PER_BLOCK; ++i )
    {
      std::cout << i << "(" << b->coord[i].x << "," << b->coord[i].y << ")" << std::endl;
    }
  std::cout << std::endl;
}

bool rotationTest( bool verbose )
{
  bool retSuccess = true;
  bool success = true;
  for( int i = 0; i < NUM_TYPES_OF_BLOCKS; ++i )
    {
      auto b1 = new block( i );
      auto b2 = new block( i );;
      success = true;

      for( int j = 0; j < 4; ++j )
	{
	  b2->rotate();
	  if( verbose )
	    printBlock( b2 );
	}
      for( int j = 0; j < 4; ++j )
	{
	  success = success && b1->coord[j].x == b2->coord[j].x && b1->coord[j].y == b2->coord[j].y; 
	  retSuccess = retSuccess && success;
	}
      if( verbose )
	std::cout << i << ": " << success << std::endl;

      delete b1;
    }

  return retSuccess;
}

void printBlock( block *b )
{
  for( int y = 20; y < 25; ++y )
    {
      for( int x = 4; x < 9; ++x )
	{
	  for( int i = 0; i < 4; ++i )
	    {
	      if( b->coord[i].x == x && b->coord[i].y == y)
		{
		  std::cout << "X";
		  break;
		} else if( i == 3 )
		{
		  std::cout << "_";
		}
	    }
	}
      std::cout << std::endl;
    }
  std::cout << std::endl;
}

bool collisionTest( bool verbose )
{
  bool ret = true;
  return false;
}

bool fallingTest( bool verbose )
{
  bool ret = true;
  for( int i = 0; i < NUM_TYPES_OF_BLOCKS; ++i )
    {
      auto b1 = new block( i );
      auto b2 = new block( i );
      ret = true;
      
      b1->moveDown();
      //create general comparison funcion
      for( int j = 0; j < PIECES_PER_BLOCK; ++j )
	{
	  ret = ret && b1->coord->x == b2->coord->x &&
	    b1->coord->y + 1 == b2->coord->y;
	  	  
	}
      if( verbose )
        {
	  std::cout << i << ": " << (ret? "TRUE":"FALSE") << std::endl;
	}

    }
  return ret;
}

bool boardHandling( bool verbose )
{
  bool ret = true;
  board bo = new board();
  
  bo.newBlock();
  for( int i = 0; i < 10; ++i )
    {
      bo.advanceBlock();
    }
  return ret;
}
