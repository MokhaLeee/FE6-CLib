#pragma once

#include "prelude.h"

#include "proc.h"
#include "bm.h"

#include "m4a.h"

extern struct MusicPlayer gMPlayInfo_SE1_SYS1;
extern struct MusicPlayer gMPlayInfo_SE2_SYS2;
extern struct MusicPlayer gMPlayInfo_SE3_BMP1;
extern struct MusicPlayer gMPlayInfo_SE4_BMP2;
extern struct MusicPlayer gMPlayInfo_SE5_BMP3;
extern struct MusicPlayer gMPlayInfo_SE6_BMP4;
extern struct MusicPlayer gMusicPlayer_FightBgm;
extern struct MusicPlayer gMusicPlayer_MainBgm;

int GetCurrentBgmSong(void);
bool IsBgmPlaying(void);
void func_fe6_08002F9C(int volume);
void SetBgmVolume(int volume);
void FadeBgmOut(int speed);
void EarthQuakeSoundFadeOut(int speed);
void StartBgmCore(int song, struct MusicPlayer * music_player);
void StartOrChangeBgm(int song, int speed, struct MusicPlayer * music_player);
void StartBgm(int song, struct MusicPlayer * music_player);
void StartBgmExt(int song, int speed, struct MusicPlayer * music_player);
void StartBgmFadeIn(int song, int b, struct MusicPlayer * music_player);
void OverrideBgm(int song);
void RestoreBgm(void);
void MakeBgmOverridePersist(void);
void StartBgmVolumeChange(int volume_from, int volume_to, int duration, ProcPtr parent);

#define PlaySe(id) \
    if (!gPlaySt.config_se_disable) \
        m4aSongNumStart((id))

#define PlayBgm(id) \
    if (!gPlaySt.config_bgm_disable) \
        StartBgmCore((id), NULL)

// TODO: move

extern struct Song const Song_Unk_0857A61C;
extern struct Song const Song_Unk_0857B774;
extern struct Song const Song_Unk_0857C1E4;
extern struct Song const Song_Unk_0857C95C;
