#include "logic.h"

#define ARBITRARY_SIZE 20

block* blockAlloc( void );
void blockFree( block * );

//Object pool:

static int mem_size {0};
static int mem_used {0};
static block* mem_array[BOARD_HEIGHT * BOARD_WIDTH / PIECES_PER_BLOCK];

block* blockAlloc( void )
{
  //check if enough space exists
  if( mem_used <= mem_size )
    {
      //get more space
    }
  return mem_array[ mem_used++ ];
}

void blockFree( block *b )
{
}
