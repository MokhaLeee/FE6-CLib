#pragma once

#include "prelude.h"

#include "proc.h"
#include "unit.h"

enum
{
    L_PLAYERPHASE_BEGIN,
    L_PLAYERPHASE_MOVE,
    L_PLAYERPHASE_ACTION_SELECT,
    L_PLAYERPHASE_END,
    L_PLAYERPHASE_MAPFADE_MOVE,
    L_PLAYERPHASE_5,
    L_PLAYERPHASE_6,
    L_PLAYERPHASE_ACTION,
    L_PLAYERPHASE_8,
    L_PLAYERPHASE_IDLE,
    L_PLAYERPHASE_10,
    L_PLAYERPHASE_SEE_RANGE,
};

enum
{
    PLAYER_SELECT_NOUNIT,
    PLAYER_SELECT_TURNENDED,
    PLAYER_SELECT_CONTROL,
    PLAYER_SELECT_NOCONTROL,
    PLAYER_SELECT_4,
};

enum
{
    LIMITVIEW_BLUE = (1 << 0),
    LIMITVIEW_RED = (1 << 1),
    LIMITVIEW_GREEN = (1 << 2),
};

void PlayerPhase_Suspend(ProcPtr proc);
void HandlePlayerMapCursor(void);
void PlayerPhase_IdleLoop(ProcPtr proc);
void DisplayUnitActionRange(struct Unit * unit);
void PlayerPhase_BeginMoveSelect(ProcPtr proc);
void PlayerPhase_MoveSelectLoop(ProcPtr proc);
void PlayerPhase_BeginSeeActionRange(ProcPtr proc);
void PlayerPhase_ContinueAction(ProcPtr proc);
void PlayerPhase_CancelAction(ProcPtr proc);
bool PlayerPhase_BeginAction(ProcPtr proc);
bool PlayerPhase_AttemptReMove(ProcPtr proc);
bool StartAvailableMoveEvents(ProcPtr proc);
bool PlayerPhase_WatchActiveUnit(ProcPtr proc);
void PlayerPhase_FinishAction(ProcPtr proc);
void func_fe6_0801BAB4(ProcPtr proc);
void PlayerPhase_BeginActionSelect(ProcPtr proc);
int GetPlayerSelectKind(struct Unit * unit);
bool CanSelectMoveTo(int x, int y);
void PlayerPhase_BeginMove(ProcPtr proc);
void PlayerPhase_WaitForMove(ProcPtr proc);
void PlayerPhase_0801BC84(ProcPtr proc);
void PlayerPhase_0801BD08(ProcPtr proc);
void OpenLimitView_Init(struct GenericProc * proc);
void OpenLimitView_Loop(struct GenericProc * proc);
void LimitView_Init(struct GenericProc * proc);
void LimitView_Loop(struct GenericProc * proc);
void LimitView_Deinit(struct GenericProc * proc);
void StartLimitView(int flags);
void EndLimitView(void);
bool TrySetCursorOn(int uid);
void TrySwitchViewedUnit(int x, int y);
void PlayerPhase_HandleAutoEnd(ProcPtr proc);

extern struct ProcScr CONST_DATA ProcScr_PlayerPhase[];
extern u8 const * CONST_DATA gOpenLimitViewImgLut[];
extern struct ProcScr CONST_DATA ProcScr_OpenLimitView[];
extern struct ProcScr CONST_DATA ProcScr_LimitView[];
