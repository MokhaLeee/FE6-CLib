#pragma once

#include "common.h"

#include "proc.h"
#include "ai.h"

int GetUnitBattleAiScore(struct Unit * unit);
int GetUnitAiScore(struct Unit * unit);
int BuildAiUnitList(void);
void SortAiUnitList(int count);

extern struct ProcScr CONST_DATA ProcScr_AiOrder[];
extern struct ProcScr CONST_DATA ProcScr_AiOrder_Berserk[];
