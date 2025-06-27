#pragma once

#include "prelude.h"
#include "proc.h"

void StartIntroMonologue(ProcPtr proc);
void Monologue_End(struct GenericProc * proc);
void Monologue_Init(struct GenericProc * proc);
void MonologueSetTm(u16 * tm, int tm_ref);
void Monologue_Loop(struct GenericProc * proc);
void MonologueDisp_Init(struct GenericProc * proc);
void MonologueDisp_Loop(struct GenericProc * proc);

extern CONST_DATA struct ProcScr ProcScr_Monologue[];
extern CONST_DATA struct ProcScr ProcScr_MonologueDisp[];
