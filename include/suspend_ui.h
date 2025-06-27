#pragma once

#include "prelude.h"
#include "proc.h"
#include "event.h"

void StartSuspendEvent(void);
bool SuspendPrompt_HandleInput(ProcPtr proc);
void WriteSuspandPlaterIdle(void);
void PostGameOverHandler(ProcPtr todo_event_proc);

extern EventScr CONST_DATA EventScr_SuspendPrompt[];
