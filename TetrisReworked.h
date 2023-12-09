#include "raylib.h"
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

//System
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 700
#define TITLE "Tetris"
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int InstantiateAndRunWindow();

//----- Gameplay datas -------

#define STAGE_WIDTH 12
#define STAGE_HEIGHT 22
#define TILE_SIZE 24
#define TETROMINO_SIZE 4
#define STARTING_OFFSET_X (WINDOW_WIDTH / 2) - ((STAGE_WIDTH * TILE_SIZE) / 2)
#define STARTING_OFFSET_Y (WINDOW_HEIGHT / 2) - ((STAGE_HEIGHT * TILE_SIZE) / 2)
#define TETROMINO_START_X STAGE_WIDTH / 2
#define TETROMINO_START_Y 0

extern int stage[];


void DrawMap();

//Tetrominus

#define TETROMINO_ARRAY_SIZE 16
#define TETROMINO_ARRAY_X 7
#define TETROMINO_ARRAY_Y 4

typedef struct
{
  Color color;
  int* shape;
  int* rotation90;
  int* rotation180;
  int* rotation270;
  int* actualShape;
  int startX;
  int startY;
  int x;
  int y;
  int width;
  int height;
  int rotation;
}Tetrominus;


void DrawTetrominus(Tetrominus tetrominus);


//TetrominusColor

#define COLOR_ARRAY 5

//Tetrominus "List"

typedef enum 
{
  SHAPE_L,
  SHAPE_J,
  SHAPE_O,
  SHAPE_S,
  SHAPE_T,
  SHAPE_I,
  SHAPE_Z
}TETROMINOS_TYPE;


Tetrominus GetRandomTetromino();

//tetromino Updates

extern float timeToMoveTetrominoDown;
extern float tetrominoTimer;
extern int pressed;
void UpdateTetromino(Tetrominus* tetromino);

//--------- END GAMEPLAY DATAS -------

//----------- STAGE SYSTEM ------------- 

void ClearRow();


//collision handling

int CheckCollision(const int tetrominoStartX, const int tetrominoStartY, const int *tetromino);

//Score system

#define CLEAR_LINE_SCORE 2000
#define MOVEMENT_SCORE 500 

//declaring a "public" variable for addressing the score
extern int score;

void DrawScore();
void UpdateScore(int value);


//Sound System

void InitializeSound();
Music InstantiateBgMusic(const char* audioPath);
Sound InstantiateSFX(const char* soundPath);
Sound InstantiateSFX2(const char* soundPath);
void EmitSFX(Sound sfx);
void EmitSFX2(Sound sfx2);
void PlayBackgroundMusic(Music bgMusic);
void ClearSFXs(Music bgMusic, Sound sfx, Sound sfx2);

extern Music bgMusic;
extern Sound sfx;
extern Sound clearSFX;

//Speed behaviour


#define FIRST_SCORE_GAP 5000
#define SECOND_SCORE_GAP 100000
#define THIRD_SCORE_GAP 2000000

typedef enum {FIRST_GAP, SECOND_GAP, THIRD_GAP}SPEED_VARIATION;
void VariateSpeedFromScore(SPEED_VARIATION var);


