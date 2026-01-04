#pragma once

#include "prelude.h"
#include "proc.h"

void StartIntroMonologue(ProcPtr proc);
void Monologue_End(struct Proc * proc);
void Monologue_Init(struct Proc * proc);
void MonologueSetTm(u16 * tm, int tm_ref);
void Monologue_Loop(struct Proc * proc);
void MonologueDisp_Init(struct Proc * proc);
void MonologueDisp_Loop(struct Proc * proc);

extern CONST_DATA struct ProcScr ProcScr_Monologue[];
extern CONST_DATA struct ProcScr ProcScr_MonologueDisp[];
