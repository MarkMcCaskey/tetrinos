#include <cstdlib>
#include <iostream>

#define NUM_TYPES_OF_BLOCKS 7
#define PIECES_PER_BLOCK 4
#define BOARD_HEIGHT 24
#define BOARD_WIDTH 10

enum class Block_Type : char { longB, leftL, rightL, square, leftN, pyramid, rightN };
enum class Block_Color : char { red, blue, green, white };

struct coords
{
  int x;
  int y;
};

class block
{
public:
  struct coords* coord;
  Block_Type type;
  Block_Color color;
 
  block( int );
  void moveDown( void );
  void moveRight( void );
  void moveLeft( void );
  void rotate( void ); 

 private:
  int orientation;
  
  //add color?
};


