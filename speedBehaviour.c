#include "TetrisReworked.h"

void SpeedUp(float variation)
{
  tetrominoTimer = variation;
}

SPEED_VARIATION Set(SPEED_VARIATION var)
{
  switch (var) 
  {
    case FIRST_GAP:
      SpeedUp(0.4f);
    break;
    case SECOND_GAP:
      SpeedUp(0.2f);
    break;
    case THIRD_GAP:
      SpeedUp(0.08f);
    break;
  }

  return var;
}

void VariateSpeedFromScore(SPEED_VARIATION var)
{
  if(score >= FIRST_SCORE_GAP)
  {
    Set(FIRST_GAP);
  }

  if(score >= SECOND_SCORE_GAP)
  {
    Set(SECOND_GAP);
  }

  if(score >= THIRD_SCORE_GAP)
  {
    Set(THIRD_GAP);
  }
}
