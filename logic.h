#include <cstdlib>
#include <iostream>

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
private:
  int orientation;
  
block( int num );
void moveDown( void );
void moveRight( void );
void moveLeft( void );
void rotate( void ); 
  
  //add color?
};


