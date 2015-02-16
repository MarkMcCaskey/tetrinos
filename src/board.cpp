#include <logic.h>


board::board( void )
{
  //  xy = new bool[BOARD_WIDTH][BOARD_HEIGHT];
  score = 0;
}

void board::addScore( int add )
{
  score += add;
}


/*
 * Checks for full lines, clears them, add points and returns true or false
 * indicating whether or not any lines were cleared.
 *
 * Consider spliting this function into multiple more modular functions
 *
 * This function needs a lot of optimization
 */
bool board::clearLines( void )
{
  bool tracker = true;
  bool ret = false;
  for( int i = 0; i < BOARD_HEIGHT; ++i )
    {
      //short circuit if tracker becomes negative
      for( int j = 0; j < BOARD_WIDTH && tracker; ++j )
	{
	  tracker = (tracker && xy[j][i]);
	}
      if( tracker )
	{
	  ret = true;
	  moveDown( i );
	  addScore( LINE_CLEAR_REWARD );
	}
      tracker = true;
    }

  return ret;
}

/*
 * moveDown is used to shift the board down when a line is cleared.
 * This should probably only be called from clearLines()
 */
void board::moveDown( int line )
{
  assert( line < BOARD_HEIGHT );
  for( int i = line; i < BOARD_HEIGHT; ++i )
    {
      for( int j = 0; j < BOARD_WIDTH; ++j )
	{
	  xy[j][i] = xy[j][i+1];
	}
    }
}

void board::newBlock( void )
{
  block blo = new block( random() % NUM_TYPES_OF_BLOCKS );
  current_block = blo;
  block_store.insert( blo );
}

//not sure if this function is needed
void board::advanceBlock( void )
{
  active_block.moveDown();
}
