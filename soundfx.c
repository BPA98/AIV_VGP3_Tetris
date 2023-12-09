#include "TetrisReworked.h"
#include "raylib.h"

void InitializeSound()
{
  InitAudioDevice();
} 

Music InstantiateBgMusic(const char* audioPath)
{
  Music bgMusic = LoadMusicStream(audioPath);
  bgMusic.looping = 1;
  return bgMusic;
}

Sound InstantiateSFX(const char *soundPath)
{
  Sound sfx = LoadSound(soundPath);
  return sfx;
}

Sound InstantiateSFX2(const char* soundPath)
{
  Sound sfx = LoadSound(soundPath);
  return sfx;
}

void EmitSFX(Sound sfx)
{
  PlaySound(sfx);
}

void EmitSFX2(Sound sfx2)
{
  PlaySound(sfx2);
} 

void PlayBackgroundMusic(Music bgMusic)
{
  PlayMusicStream(bgMusic);
}


void ClearSFXs(Music bgMusic, Sound sfx, Sound sfx2)
{
  UnloadMusicStream(bgMusic);
  UnloadSound(sfx);
  UnloadSound(sfx2);
}
