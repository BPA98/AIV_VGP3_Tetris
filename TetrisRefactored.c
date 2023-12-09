#include "TetrisReworked.h"
#include "raylib.h"
#include <stdlib.h>
#include <time.h>

float tetrominoTimer = 1.f;
float timeToMoveTetrominoDown;
int pressed;

Music bgMusic;
Sound sfx;
Sound clearSFX;
//SPEED_VARIATION speedVariation;

int InstantiateAndRunWindow()
{
  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);

  SetTargetFPS(60);

  
  Tetrominus currentTetromino = GetRandomTetromino();

  time_t unixTime;
  time(&unixTime);

  SetRandomSeed(unixTime);

  timeToMoveTetrominoDown = tetrominoTimer;
  pressed = 0;

  InitializeSound();

  bgMusic = InstantiateBgMusic("./SoundFX/bgMusic.mp3"); 
  sfx = InstantiateSFX("./SoundFX/tetris_place.wav");
  clearSFX = InstantiateSFX2("./SoundFX/clear_row_sound.wav");

  SPEED_VARIATION speedVariation;

  PlayBackgroundMusic(bgMusic);

  while(!WindowShouldClose())
  {

    //INPUT/UPDATE

    UpdateMusicStream(bgMusic);

    VariateSpeedFromScore(speedVariation);
    
    UpdateTetromino(&currentTetromino);
    

    timeToMoveTetrominoDown -= GetFrameTime();


  
    //DRAW
    
    BeginDrawing();
    ClearBackground(RED);
    DrawScore();
    DrawMap();
    DrawTetrominus(currentTetromino);
    
    EndDrawing();

  }

  ClearSFXs(bgMusic,sfx,clearSFX);
  CloseWindow();
  return EXIT_SUCCESS;
}
