//
// Created by Aman on 10.05.2023.
//

#include "audio.h"

void audio::playSoundMenu() {
    isPlaying= true;
    PlaySound(TEXT("audio/menuA.wav"), NULL, SND_ASYNC);
}
void audio::stopSound() {
    if (isPlaying){
        PlaySound(NULL,NULL,SND_ASYNC);
        isPlaying= false;
    }
}
void audio::playSoundPoint() {
    isPlaying= true;
    PlaySound(TEXT("audio/point+.wav"), NULL, SND_ASYNC);
}
void audio::SoundGameOver() {
    isPlaying= true;
    PlaySound(TEXT("audio/GameOver.wav"), NULL, SND_ASYNC);
}
void audio::SoundMove() {
    isPlaying= true;
    PlaySound(TEXT("audio/move.wav"), NULL, SND_ASYNC);
}
void audio::SoundMoveDown() {
    isPlaying= true;
    PlaySound(TEXT("audio/liongit branch.wav"), NULL, SND_ASYNC);
}
audio::audio()
{}