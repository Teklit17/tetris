//
// Created by Aman on 10.05.2023.
//


#ifndef TETRIS_SOUNDPLAYER_H
#define TETRIS_SOUNDPLAYER_H

#include <iostream>
#include <windows.h>
#include <mmsystem.h>

class audio {
private:
    bool isPlaying;
public:
    audio();
    void playSoundMenu();
    void stopSound();
    void playSoundPoint();
    void SoundGameOver();
    void SoundMove();
    void SoundMoveDown();
};

#endif //TETRIS_AUDIO_H
