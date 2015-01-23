#include "logic.cpp"
#include <iostream>
#include <cstdlib>

int main( void );
void printCoords( block* );
bool rotationTest( bool );
void printBlock( block* );
bool collisionTest( bool );
bool fallingTest( bool );

int main( void ) //add verbosity flag
{
  bool rt;
  bool ct;
  bool ft;

  bool verbose = true;
  
  std::cout << "Rotation Test : ";
  rt = rotationTest( verbose );
  
  std::cout << std::endl << "Collision Test : ";
  ct = collisionTest( verbose );
  
  std::cout << std::endl << "Falling Test : ";
  ft = fallingTest( verbose );

  std::cout << std::endl << "Overall results : " << std::endl;
  std::cout << "Rotation Test : " << (rt ? "PASSED" : "FAILED") << std::endl;
  std::cout << "Collision Test : " << (ct ? "PASSED" : "FAILED") << std::endl; 
  std::cout << "Falling Test : " << (ft ? "PASSED" : "FAILED") << std::endl;

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
	}
      if( verbose )
	std::cout << i << ": " << success << std::endl;

      delete b1;
    }

  return success;
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
  return false;
}

bool fallingTest( bool verbose )
{
  return false;
}
