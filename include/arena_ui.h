#pragma once

#include "prelude.h"
#include "proc.h"

void StartArenaScreen(void);
void StartArenaResultsScreen(void);
void ArenaUi_Init(ProcPtr proc);
void ArenaUi_BmEnd(ProcPtr proc);
void ArenaUi_WelcomeDialogue(ProcPtr proc);
void ArenaUi_WagerGoldDialogue(ProcPtr proc);
void ArenaUi_CheckConfirmation(ProcPtr proc);
void ArenaUi_ConfirmWager(ProcPtr proc);
void ArenaUi_InstructionsDialogue(ProcPtr proc);
void ArenaUi_GoodLuckDialogue(ProcPtr proc);
void ArenaUi_FadeOutBgm(ProcPtr proc);
void ArenaUi_StartArenaBattle(ProcPtr proc);
void _StartPartialGameLock(ProcPtr proc);
void _ArenaUi_Init(ProcPtr proc);
void ArenaUi_ResultsDialogue(ProcPtr proc);
void ArenaUi_ShowGoldBoxOnVictoryOrDraw(ProcPtr proc);
void ArenaUi_OnEnd(ProcPtr proc);
void StartArenaDialogue(int msg, ProcPtr proc);
void DrawArenaOpponentDetailsText(ProcPtr proc);
void Arena_PlayResultSong(ProcPtr proc);
void Arena_PlayArenaSong(ProcPtr proc);

extern CONST_DATA struct ProcScr ProcScr_ArenaUiMain[];
extern CONST_DATA struct ProcScr ProcScr_ArenaUiResults[];
extern CONST_DATA struct ProcScr ProcScr_ArenaUiResultBgm[];
