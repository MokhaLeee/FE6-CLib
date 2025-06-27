#pragma once

#include "prelude.h"
#include "proc.h"

enum
{
    // TODO: those have different meanings depending on the state of the game controller

    GAME_ACTION_0,
    GAME_ACTION_1,
    GAME_ACTION_2,
    GAME_ACTION_3,
    GAME_ACTION_4,
    GAME_ACTION_5,
    GAME_ACTION_6,
    GAME_ACTION_7,
    GAME_ACTION_8,
};

enum
{
    L_GAMECTRL_OPENINGSEQ,
    L_GAMECTRL_CLASSDEMO,
    L_GAMECTRL_SCENEDEMO,
    L_GAMECTRL_TITLE,
    L_GAMECTRL_MAINMENU,
    L_GAMECTRL_CHAPTER,
    L_GAMECTRL_LOADSUSPEND,
    L_GAMECTRL_POSTCHAPTER,
    L_GAMECTRL_POSTTRIAL,
    L_GAMECTRL_TUTORIAL,
    L_GAMECTRL_LINK,
    L_GAMECTRL_TRIAL,
    L_GAMECTRL_PREENDING,
    L_GAMECTRL_ENDING,
    L_GAMECTRL_SRAMRESET,
};

struct GameController
{
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 next_action;
    /* 2A */ u8 next_chapter;
    /* 2B */ u8 demo_counter;
    /* 2C */ u8 previous_demo_class_set;
    /* 2E */ i16 clock;
};

int GetFurthestSaveChapter(void);
bool GC_StartClassDemo(struct GameController * proc);
void GC_CheckSramResetKeyCombo(struct GameController * proc);
void GC_InitSramResetScreen(struct GameController * proc);
void GC_InitFastStartCheck(struct GameController * proc);
void GC_FastStartCheck(struct GameController * proc);
void EndIfNotGameController(ProcPtr proc);
void CleanupGame(ProcPtr proc);
void GC_PostIntro(struct GameController * proc);
void GC_PostDemo(struct GameController * proc);
void GC_PostMainMenu(struct GameController * proc);
void GC_InitTutorial(struct GameController * proc);
void GC_InitTrialChapter(struct GameController * proc);
void GC_ClearSuspend(struct GameController * proc);
void GC_PostChapter(struct GameController * proc);
void GC_CheckForGameEnded(struct GameController * proc);
void GC_PostLoadSuspend(struct GameController * proc);
void GC_InitNextChapter(struct GameController * proc);
void GC_InitDemo(struct GameController * proc);
void GC_DarkenScreen(struct GameController * proc);
void StartGame(void);
struct GameController * GetGameController(void);
void SetNextGameAction(int action);
void SetNextChapter(int chapter);
bool HasNextChapter(void);
void RestartGameAndChapter(void);
void RestartGameAndLoadSuspend(void);
void ForceEnableSounds(void);
void func_fe6_08013A64(void);

extern struct ProcScr CONST_DATA ProcScr_Unused_GameController_085C4A1C[];
extern struct ProcScr CONST_DATA ProcScr_GameController[];
