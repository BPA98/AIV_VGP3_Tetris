#include "TetrisReworked.h"
#include "raylib.h"
#include <string.h>
#include <stdlib.h>


Tetrominus CreateLTetromino();
Tetrominus CreateJTetromino();
Tetrominus CreateOTetromino();
Tetrominus CreateSTetromino();
Tetrominus CreateTTetromino();
Tetrominus CreateITetromino();
Tetrominus CreateZTetromino();
Tetrominus CreateTetromino(TETROMINOS_TYPE type);


Color TetrominoColor[COLOR_ARRAY] = 
{
  {82, 192, 209, 255},
  {55, 87, 176, 255},
  {107, 240, 103, 255},
  {240, 231, 103, 255},
  {149, 103, 240, 255}
};

int GetRandomIndex()
{
  int guess = GetRandomValue(0, COLOR_ARRAY - 1);
  TraceLog(LOG_INFO, "index color: %d", guess);
  return guess;
}

Color SetRandomColorTo(Tetrominus* tetromino) // a pointer is useful for manipulating the tetromino without instantiating another
{
  int idx = GetRandomIndex();
  tetromino->color = TetrominoColor[idx];
  TraceLog(LOG_INFO, "tetromino color: %d %d %d", tetromino->color.r, tetromino->color.g, tetromino->color.b);         
  return tetromino->color;
}

Tetrominus CreateTetromino(TETROMINOS_TYPE type)
{
  Tetrominus tetromino;

  switch (type) 
  {
    case SHAPE_L:
      tetromino = CreateLTetromino();
    break;
    case SHAPE_J:
      tetromino = CreateJTetromino();
    break;
    case SHAPE_O:
      tetromino = CreateOTetromino();
    break;
    case SHAPE_S:
      tetromino = CreateSTetromino();
    break;
    case SHAPE_T:
      tetromino = CreateTTetromino();
    break;
    case SHAPE_I:
      tetromino = CreateITetromino();
    break;
    case SHAPE_Z:
      tetromino = CreateZTetromino();
    break;
  }

  return tetromino;
}

Tetrominus GetRandomTetromino()
{
  Tetrominus t = CreateTetromino(GetRandomIndex());
  return t;
}

void RotationArray(int* original, int* rot90, int* rot180, int* rot270, int size)
{
  for(int i = 0; i < size; ++i)
  {
    int row = i / 4;
    int col = i % 4;

    rot90[col * 4 + (3 - row)] = original[i];
    rot180[(3 - row) * 4 + (3 - col)] = original[i];
    rot270[(3 - col) * 4 + row] = original[i];
  }
}

Tetrominus CreateLTetromino()
{
  size_t size = TETROMINO_ARRAY_SIZE;
  Tetrominus l = {};
  l.shape = malloc(sizeof(int) * size);
  l.rotation90 = malloc(sizeof(int) * size);
  l.rotation180 = malloc(sizeof(int) * size);
  l.rotation270 = malloc(sizeof(int) * size);

  if(l.shape != NULL && l.rotation90 != NULL && l.rotation180 != NULL && l.rotation270 != NULL)
  {
    for(size_t i = 0; i < size; i++)
    {
      int shape[TETROMINO_ARRAY_SIZE] = { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 };
      l.shape[i] = shape[i];
    }

    RotationArray(l.shape, l.rotation90, l.rotation180, l.rotation270, size);

    l.x = TETROMINO_START_X;
    l.y = TETROMINO_START_Y;
    l.startX = l.x;
    l.startY = l.y;
    l.width = TILE_SIZE;
    l.height = TILE_SIZE;
    l.rotation = 0;

    SetRandomColorTo(&l);
  }

  return l;
}

Tetrominus CreateJTetromino()
{
  size_t size = TETROMINO_ARRAY_SIZE;
  Tetrominus j = {};
  j.shape = malloc(sizeof(int) * size);
  j.rotation90 = malloc(sizeof(int) * size);
  j.rotation270 = malloc(sizeof(int) * size);
  j.rotation180 = malloc(sizeof(int) * size);

  if(j.shape != NULL && j.rotation90 != NULL && j.rotation180 != NULL && j.rotation270 != NULL)
  {
    for(size_t i = 0; i < size; i++)
    {
      int shape[TETROMINO_ARRAY_SIZE] = { 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, };
      j.shape[i] = shape[i];
    }

    RotationArray(j.shape, j.rotation90, j.rotation180, j.rotation270, size);

    j.x = TETROMINO_START_X;
    j.y = TETROMINO_START_Y;
    j.startX = j.x;
    j.startY = j.y;
    j.width = TILE_SIZE;
    j.height = TILE_SIZE;
    j.rotation = 0;

    SetRandomColorTo(&j);
  }

  return j;
}

Tetrominus CreateOTetromino()
{
  size_t size = TETROMINO_ARRAY_SIZE;
  Tetrominus o = {};
  o.shape = malloc(sizeof(int) * size);
  o.rotation90 = malloc(sizeof(int) * size);
  o.rotation180 = malloc(sizeof(int) * size);
  o.rotation270 = malloc(sizeof(int) * size);

  if(o.shape != NULL && o.rotation90 != NULL && o.rotation180 != NULL && o.rotation270 != NULL)
  {
    for(size_t i = 0; i < size; i++)
    {
      int shape[TETROMINO_ARRAY_SIZE] = { 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
      o.shape[i] = shape[i];
    }

    RotationArray(o.shape, o.rotation90, o.rotation180, o.rotation270, size);

    o.x = TETROMINO_START_X;
    o.y = TETROMINO_START_Y;
    o.startX = o.x;
    o.startY = o.y;
    o.width = TILE_SIZE;
    o.height = TILE_SIZE;
    o.rotation = 0;

    SetRandomColorTo(&o);
  }

  return o;
}


Tetrominus CreateSTetromino()
{
  size_t size = TETROMINO_ARRAY_SIZE;
  Tetrominus s = {};
  s.shape = malloc(sizeof(int) * size);
  s.rotation90 = malloc(sizeof(int) * size);
  s.rotation180 = malloc(sizeof(int) * size);
  s.rotation270 = malloc(sizeof(int) * size);

  if(s.shape != NULL && s.rotation90 != NULL && s.rotation180 != NULL && s.rotation270 != NULL)
  {
    for(size_t i = 0; i < size; i++)
    {
      int shape[TETROMINO_ARRAY_SIZE] = { 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, };
      s.shape[i] = shape[i];
    }

    RotationArray(s.shape, s.rotation90, s.rotation180, s.rotation270, size);

    s.x = TETROMINO_START_X;
    s.y = TETROMINO_START_Y;
    s.startX = s.x;
    s.startY = s.y;
    s.width = TILE_SIZE;
    s.height = TILE_SIZE;
    s.rotation = 0;

    SetRandomColorTo(&s);
  }

  return s;
}


Tetrominus CreateTTetromino()
{
  size_t size = TETROMINO_ARRAY_SIZE;
  Tetrominus t = {};
  t.shape = malloc(sizeof(int) * size);
  t.rotation90 = malloc(sizeof(int) * size);
  t.rotation180 = malloc(sizeof(int) * size);
  t.rotation270 = malloc(sizeof(int) * size);

  if(t.shape != NULL && t.rotation90 != NULL && t.rotation180 != NULL && t.rotation270 != NULL)  
  {
    for(size_t i = 0; i < size; i++)
    {
      int shape[TETROMINO_ARRAY_SIZE] = { 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, };
      t.shape[i] = shape[i];
    }

    RotationArray(t.shape, t.rotation90, t.rotation180, t.rotation270, size);

    t.x = TETROMINO_START_X;
    t.y = TETROMINO_START_Y;
    t.startX = t.x;
    t.startY = t.y;
    t.width = TILE_SIZE;
    t.height = TILE_SIZE;
    t.rotation = 0;

    SetRandomColorTo(&t);
  }

  return t;
}

Tetrominus CreateITetromino()
{
  size_t size = TETROMINO_ARRAY_SIZE;
  Tetrominus i = {};
  i.shape = malloc(sizeof(int) * size);
  i.rotation90 = malloc(sizeof(int) * size);
  i.rotation180 = malloc(sizeof(int) * size);
  i.rotation270 = malloc(sizeof(int) * size);

  if(i.shape != NULL && i.rotation90 != NULL && i.rotation180 != NULL && i.rotation270 != NULL)  
  {
    for(size_t j = 0; j < size; j++)
    {
      int shape[TETROMINO_ARRAY_SIZE] = { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, };
      i.shape[j] = shape[j];
    }

    RotationArray(i.shape, i.rotation90, i.rotation180, i.rotation270, size);

    i.x = TETROMINO_START_X;
    i.y = TETROMINO_START_Y;
    i.startX = i.x;
    i.startY = i.y;
    i.width = TILE_SIZE;
    i.height = TILE_SIZE;
    i.rotation = 0;

    SetRandomColorTo(&i);
  }

  return i;
}

Tetrominus CreateZTetromino()
{
  size_t size = TETROMINO_ARRAY_SIZE;
  Tetrominus z = {};
  z.shape = malloc(sizeof(int) * size);
  z.rotation90 = malloc(sizeof(int) * size);
  z.rotation180 = malloc(sizeof(int) * size);
  z.rotation270 = malloc(sizeof(int) * size);

  if(z.shape != NULL && z.rotation90 != NULL && z.rotation180 != NULL && z.rotation270 != NULL)   
  {
    for(size_t j = 0; j < size; j++)
    {
      int shape[TETROMINO_ARRAY_SIZE] = { 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, };
      z.shape[j] = shape[j];
    }

    RotationArray(z.shape, z.rotation90, z.rotation180, z.rotation270, size);

    z.x = TETROMINO_START_X;
    z.y = TETROMINO_START_Y;
    z.startX = z.x;
    z.startY = z.y;
    z.width = TILE_SIZE;
    z.height = TILE_SIZE;
    z.rotation = 0;

    SetRandomColorTo(&z);
  }

  return z;
}

void RotateTetrominus(Tetrominus* tetromino) //same thing goes for this function, better a pointer than another instance
{
  tetromino->rotation = (tetromino->rotation + 90) % 360;
  int* tmpShape = tetromino->shape;

  if(tetromino->rotation == 0)
  {
    tetromino->shape = tmpShape;
  }

  else if(tetromino->rotation == 90)
  {
    tetromino->shape = tetromino->rotation90;
  }

  else if(tetromino->rotation == 180)
  {
    tetromino->shape = tetromino->rotation180;
  }

  else if(tetromino->rotation == 270)
  {
    tetromino->shape = tetromino->rotation270;
  }

  while(CheckCollision(tetromino->x, tetromino->y, tetromino->shape))
  {
    if(tetromino->x > 0)
    {
      tetromino->x--;
    }
    else
    {
      tetromino->x++;
    }
  }
}


void UpdateTetromino(Tetrominus* tetromino)
{

  if(timeToMoveTetrominoDown <= 0 || IsKeyPressed(KEY_DOWN))
  { 
    if(!CheckCollision(tetromino->x, tetromino->y + 1, tetromino->shape))
      {
        tetromino->y++;
        timeToMoveTetrominoDown = tetrominoTimer;
        UpdateScore(MOVEMENT_SCORE);
      }
    else
    {
      for(int y = 0; y < TETROMINO_SIZE; y++)
      {
        for(int x = 0; x < TETROMINO_SIZE; x++)
        {
          const int offset = y * TETROMINO_SIZE + x;
          TraceLog(LOG_INFO, "offset: %d", offset);

          if(tetromino->shape[offset] == 1)
          {
            const int mapOffset = (y + tetromino->y) * STAGE_WIDTH + (x + tetromino->x); 
            stage[mapOffset] = GetRandomIndex() + 1; 
            EmitSFX(sfx);
          } 
        }

      }
      ClearRow();
      *tetromino = GetRandomTetromino();
    }
  }

  if(IsKeyPressed(KEY_LEFT))
  {
    if(!CheckCollision(tetromino->x - 1, tetromino->y, tetromino->shape))
    {
      tetromino->x--;
    }
  }

  if(IsKeyPressed(KEY_RIGHT))
  {
    if(!CheckCollision(tetromino->x + 1, tetromino->y, tetromino->shape))
    {
      tetromino->x++;
    }
  }

  if(IsKeyPressed(KEY_SPACE) && !CheckCollision(tetromino->x, tetromino->y, tetromino->shape))
  {
    if(tetromino->rotation > 270)
    {
      tetromino->rotation = 0;
    }

    RotateTetrominus(tetromino);
  }
}



