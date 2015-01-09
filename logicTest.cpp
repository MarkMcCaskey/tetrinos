#include "logic.cpp"
#include <iostream>
#include <cstdlib>

int main( void );
void printCoords( block* b );
int rotationTest( void );

int main( void )
{
  std::cout << "Rotation Test : " << (rotationTest())? "PASSED\n" : "FAILED\n";
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

int rotationTest( void )
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
	}
      for( int j = 0; j < 4; ++j )
	{
	  success = success && b1->coord[j].x == b2->coord[j].x && b1->coord[j].y == b2->coord[j].y; 
	}
     
      std::cout << i << ": " << success << std::endl;

      delete b1;
    }

  return success;
}
