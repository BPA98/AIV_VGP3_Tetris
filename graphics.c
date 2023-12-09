#include "TetrisReworked.h"
#include "raylib.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>


int stage[] = {
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

void DrawMap()
{
  for (int h = 0; h < STAGE_HEIGHT; h++) 
  {
    for(int w = 0; w < STAGE_WIDTH; w++)
    {
      const int offset = h * STAGE_WIDTH + w;

      if(stage[offset] != 0)
      {
        DrawRectangle(w * TILE_SIZE + STARTING_OFFSET_X , h * TILE_SIZE + STARTING_OFFSET_Y, TILE_SIZE, TILE_SIZE, GRAY);
      }

      DrawRectangleLines(w * TILE_SIZE + STARTING_OFFSET_X, h * TILE_SIZE + STARTING_OFFSET_Y, TILE_SIZE, TILE_SIZE, BLACK);
    }
  }
}

void DrawTetrominus(Tetrominus tetrominus)
{ 
  for(int y = 0; y < TETROMINO_SIZE; y++)
  {
    for(int x = 0; x < TETROMINO_SIZE; x++)
    {
      const int offset = y * TETROMINO_SIZE + x;
      
      if(tetrominus.shape[offset] == 1)
      {
        DrawRectangle((x + tetrominus.x) * TILE_SIZE + STARTING_OFFSET_X, (y + tetrominus.y) * TILE_SIZE + STARTING_OFFSET_Y, 
                      TILE_SIZE, TILE_SIZE, tetrominus.color);
      }
    }
  }
}


void ResetRow(int yLine)
{
  for(int y = yLine; y >= 0; y--)
  {
    for(int x = 1; x < STAGE_WIDTH - 1; x++)
    {
      const int offset = y * STAGE_WIDTH + x;
      const int offsetBelow = (y + 1) * STAGE_WIDTH + x;

      if(stage[offsetBelow] == 0 && stage[offset] > 0)
      {
        stage[offsetBelow] = stage[offset];
        stage[offset] = 0;
        UpdateScore(CLEAR_LINE_SCORE);
        EmitSFX2(clearSFX);
      }
    }
  }
}


void ClearRow()
{

  for(int y = 0; y < STAGE_HEIGHT - 1; y++)
  {
    int checkLine = 1;

    for(int x = 1; x < STAGE_WIDTH - 1; x++)
    {
      const int offset = y * STAGE_WIDTH + x;

      if(stage[offset] == 0)
      {
        checkLine = 0;
        break;
      }
    }

    if(checkLine)
    {
      const int offset = y * STAGE_WIDTH + 1;
      memset(stage + offset, 0 , (STAGE_WIDTH - 2) * sizeof(int));
      ResetRow(y);
    }
  }
}
