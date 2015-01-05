#include <cstdlib>
#include <iostream>

enum class Block_Type : char { longB, leftL, rightL, square, leftN, pyramid, rightN };
enum class Block_Color : char { red, blue, green, white };

struct coords
{
  int x;
  int y;
};

//TODO: figure out classes and implement functions as methods of object as opposed to pointers

class block
{
public:
  struct coords coord[4];
  Block_Type type;
  Block_Color color;
private:
  int orientation;
  
  
  //add color?
};

block::block( int num )
{
  type = static_cast<Block_Type>( num % 7 ); //replace 7 with macro or const
  coord = new struct coords[4];
  color = static_cast<Block_Color>( num % 4 ); //replace 4 with macro or const
  orientation = 0;

  switch( type ){
  case Block_Type::longB:
    for( i : coord )
      {
	coord[i].x = (4+i);
	coord[i].y = 21; //change to macro or const for max height of place
      }
    break;
  case Block_Type::leftL:
    coord[0].x = 5;
    coord[0].y = 22;
    coord[1].x = 5;
    coord[1].y = 21;
    coord[2].x = 6;
    coord[2].y = 21;
    coord[3].x = 7;
    coord[3].y = 21;
    break;
  case Block_Type::rightL:
    coord[0].x = 5;
    coord[0].y = 21;
    coord[1].x = 6;
    coord[1].y = 21;
    coord[2].x = 7;
    coord[2].y = 21;
    coord[3].x = 7;
    coord[3].y = 22;
    break;
  case Block_Type::square:
    coord[0].x = 5;
    coord[0].y = 22;
    coord[1].x = 6;
    coord[1].y = 22;
    coord[2].x = 5;
    coord[2].y = 21;
    coord[3].x = 6;
    coord[3].y = 21;
    break;
  case Block_Type::leftN: 
    coord[0].x = 5;
    coord[0].y = 21;
    coord[1].x = 6;
    coord[1].y = 21;
    coord[2].x = 6;
    coord[2].y = 22;
    coord[3].x = 7;
    coord[3].y = 22;
    break;
  case Block_Type::pyramid:
    coord[0].x = 5;
    coord[0].y = 21;
    coord[1].x = 6;
    coord[1].y = 21;
    coord[2].x = 7;
    coord[2].y = 21;
    coord[3].x = 6;
    coord[3].y = 22;
    break;
  case Block_Type::rightN:
    coord[0].x = 5;
    coord[0].y = 22;
    coord[1].x = 6;
    coord[1].y = 22;
    coord[2].x = 6;
    coord[2].y = 21;
    coord[3].x = 7;
    coord[3].y = 21;
    break;
  }
}
  
block::moveDown( void )
{
  for( i : coord )
    {
      //Intersection check
      coord[i].y--;
    }
}

block::moveRight( void )
{  
  for( i : coord )
    {
      //Intersection check
      coord[i].x++;
    }
}

block::moveLeft( void )
{  
  for( i : coord )
    {
      //Intersection check
      coord[i].x--;
    }
}

block::rotate( void )
{
  switch( type )
    {
    case Block_Type::longB:
      if( orientation = 0 )
	{
	coord[0].x = coord[2].x = coord[3].x = coord[1].x; 
	coord[0].y = coord[1].y;
	coord[1].y = coord[0].y + 1;
	coord[2].y = coord[1].y + 1;
	coord[3].y = coord[2].y + 1;
	orientation = 1;
	} else {
	coord[0].x = coord[1].x - 1;
	coord[2].x = coord[1].x + 1;
	coord[3].x = coord[2].x + 1;
	coord[0].y = coord[2].y = coord[3].y = coord[1].y;
	orientation = 0;
      }
      break;
    case Block_Type::square:
      //do nothing
      break;
    case Block_Type::leftL:
      switch( orientation )
	{
	case 0:
	  coord[1].x = coord[3].x = coord[2].x;
	  coord[1].y = coord[2].y - 1;
	  coord[2].y = coord[2].y + 1;
	  coord[0].y -= 2;
	  orientation++;
	  break;
	case 1:
	  coord[0].x +=2;
	  coord[1].y = coord[3].y = coord[2].y;
	  coord[1].x = coord[2].x + 1;
	  coord[3].x = coord[2].x - 1;
	  orientation++;
	  break;
	case 2:
	  coord[0].y += 2;
	  coord[1].x = coord[3].x = coord[2].x;
	  coord[1].y = coord[2].y + 1;
	  coord[3].y = coord[2].y - 1;
	  orientation++;
	  break;
	case 3:
	  coord[0].x -= 2;
	  coord[1].y = coord[3].y = coord[2].y;
	  coord[1].x = coord[2].x - 1;
	  coord[3].x = coord[2].x + 1;
	  orientation = 0;
	  break;
	}
      break;
    case Block_Type::rightL:
      switch( orientation )
	{
	case 0:
	  coord[3].x -= 2;
	  coord[2].x = coord[0].x = coord[1].x;
	  coord[0].y = coord[1].y - 1;
	  coord[2].y = coord[1].y + 1;
	  orientation++;
	  break;
	case 1:
	  coord[3].y -= 2;
	  coord[0].y = coord[2].y = coord[1].y; 
	  coord[0].x = coord[1].x - 1;
	  coord[2].x = coord[1].x + 1;
	  orientation++;
	  break;
	case 2:
	  coord[3].x += 2;
	  coord[0].x = coord[2].x = coord[1].x;
	  coord[0].y = coord[1].y + 1;
	  coord[2].y = coord[1].y - 1;
	  orientation++;
	  break;
	case 3:
	  coord[3].y += 2;
	  coord[0].y = coord[2].y = coord[1].y;
	  coord[0].x = coord[1].x - 1;
	  coord[2].x = coord[1].x + 1;
	  orientation = 0;
	  break;
	}
      break;
    case Block_Type::leftN:
      if( orientation == 0 )
	{
	  coord[0].x += 1;
	  coord[1].y += 1;
	  coord[2].x -= 1;
	  coord[3].x -= 2;
	  coord[3].y += 1;
	  orientation++;
	} else {
	coord[0].x -= 1;
	coord[1].y -= 1;
	coord[2].x += 1;
	coord[3].x += 2;
	coord[3].y -= 1;
	orientation = 0;
      }
      break;
    case Block_Type::pyramid:
      switch( orientation )
	{
	case 0:
	  coord[3].x--;
	  coord[3].y++;
	  coord[0].x++;
	  coord[0].y++;
	  coord[2].x--;
	  coord[2].y--;
	  orientation++;
	  break;
	case 1:
	  coord[3].x++;
	  coord[3].y++;
	  coord[0].x++;
	  coord[0].y--;
	  coord[2].y++;
	  coord[2].x--;
	  orientation++;
	  break;
	case 2:
	  coord[3].x++;
	  coord[3].y--;
	  coord[0].y--;
	  coord[0].x--;
	  coord[2].x++;
	  coord[2].y++;
	  orientation++;
	  break;
	case 3:
	  coord[3].x--;
	  coord[3].y--;
	  coord[0].y--;
	  coord[0].x--;
	  coord[2].x++;
	  coord[2].y++;
	  orientation = 0;
	  break;
	}
      break;
    case Block_Type::rightN:
      switch( orientation )
	{
	case 0:
	  orientation++;
	  break;
	case 1:
	  orientation++;
	  break;
	case 2:
	  orientation++;
	  break;
	case 3:
	  orientation = 0;
	  break;
	}
    }
}

struct block *newLongBlock( void )
{
  struct block b = new struct block();
  b.coord = new struct coords[4];
  b.type = Block_Type::longB; 

  for( int i = 0; ; ++i )
    {
      b.coord[i].x = 0;
      b.coord[i].y = 0;
    }
}

 struct block *newLeftLBlock( void )
 {
   struct block b = new struct block();
   b.coord = new struct coords[4];
   b.type = Block_Type::leftL;

   for( int i = 0; ; ++i )
     {
       b.coord[i].x = 0;
       b.coord[i].y = 0;
     }
 }

struct block rotate( struct block * b )
{
  switch( b->type )
    {
      //TODO: add rotation based on block or implement generic rotation function
    }

}