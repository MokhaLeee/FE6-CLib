#ifndef CHAPTER_H
#define CHAPTER_H

#include "prelude.h"

int GetTextPrintDelay(void);
int IsFirstPlaythrough(void);
void InitPlayConfig(int is_hard);
void ResetBmSt(void);
void StartChapter(struct Proc * parent);
void JumpToChapterDirectly(void);
void ResumeChapterFromSuspend(struct Proc * parent);
void func_fe6_08029240(void);
void func_fe6_080292B8(void);
void InitBmDisplay(void);
ProcPtr StartMapMain(struct Proc * parent);
void EndMapMain(void);
void CleanupUnitsBeforeChapter(void);
void ResumeMapMainDuringPhase(ProcPtr mapmain);
void ResumeMapMainDuringAction(ProcPtr mapmain);
void ResumeMapMainDuringBerserk(ProcPtr mapmain);
void ResumeMapMainDuringArena(ProcPtr mapmain);
void ResumeMapMainDuringPhaseChange(ProcPtr mapmain);
void func_fe6_08029654(void);

#endif // CHAPTER_H
