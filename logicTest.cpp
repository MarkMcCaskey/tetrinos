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
  for( int i = 0; i < 4; ++i )
    {
      std::cout << i << "(" << b->coord[i].x << "," << b->coord[i].y << ")" << std::endl;
    }
  std::cout << std::endl;
}

int rotationTest( void )
{
  for( int i = 0; i < 5; ++i )
    {
      auto b1 = new block( i );
      
      std::cout << i << " {" << std::endl;

      printCoords( b1 );
      b1->rotate();
      printCoords( b1 );
      b1->rotate();
      printCoords( b1 );
      b1->rotate();
      printCoords( b1 );
      b1->rotate();
      printCoords( b1 );

      std::cout << "}" << std::endl;
      
      delete b1;
    }

  return 1;
}
