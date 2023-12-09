#include "TetrisReworked.h"
#include "raylib.h"
#include <stdio.h>

int score = 0;

void DrawScore()
{
  Rectangle rect = {};
  rect.x = 200; rect.y = 20; rect.width = 200; rect.height = 45;
  DrawRectangleRec(rect, GRAY);

  int scoreXText = rect.x + 30;
  int scoreYText = rect.y + 10;

  DrawText("Score: ", scoreXText  , scoreYText, 20, PURPLE);

  char scoreToChar[25];
  snprintf(scoreToChar, sizeof(scoreToChar), " %d", score);

  DrawText(scoreToChar, scoreXText + 70, scoreYText, 20, PURPLE);

}

void UpdateScore(int value)
{
  score += value;
  DrawText("Score: ", 230, 30, 20, PURPLE);
  char updatedScore[25];
  snprintf(updatedScore, sizeof(updatedScore), " %d", score);
  DrawText(updatedScore, 300, 30, 20, PURPLE);
}




