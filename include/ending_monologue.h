#pragma once

#include "prelude.h"
#include "proc.h"

struct ProcEndingMonologueText
{
	/* 00 */ PROC_HEADER;
	/* 29 */ STRUCT_PAD(0x29, 0x2C);
	/* 2C */ int bg_y;
	/* 30 */ int delay_timer;
	/* 34 */ int main_timer;
	/* 38 */ int bg_x;
	/* 3C */ i8 const * ctrl_y;
	/* 40 */ int paulse_timer;
};


void EndingMonologueText_Init(struct ProcEndingMonologueText *proc);
void EndingMonologueText_Loop(struct ProcEndingMonologueText *proc);
void EndingMonologue_PutText(ProcPtr parent);

void EndingMonologue_Init(void);
void EndingMonologue_MoveText(int arg_0, int arg_1);
void EndingMonologue_Loop(ProcPtr proc);
void EndingMonologue_End(void);
void func_fe6_0806E73C(void);
void StartEndingMonologue0(ProcPtr parent);
void StartEndingMonologue1(ProcPtr parent);
void StartEndingMonologue2(ProcPtr parent);
void StartEndingMonologue3(ProcPtr parent);
bool EndingMonologueExists(void);

extern u8 gEndingMonologueState;
extern u8 gEndingMonologueTextDone;
extern u8 const Img_EndingMonologueText1[]; // img
extern u8 const Img_EndingMonologueText3[]; // img
extern u8 const Img_EndingMonologueText4[]; // img
extern u8 const Img_08352160[]; // img
extern i8 CONST_DATA Ctrl_EndingMonologueText1[];
extern i8 CONST_DATA Ctrl_EndingMonologueText2[];
extern i8 CONST_DATA Ctrl_EndingMonologueText3[];
extern i8 CONST_DATA Ctrl_EndingMonologueText4[];
extern struct ProcScr CONST_DATA ProcScr_EndingMonologue[];

extern u8 const Img_EndingMonologue[]; // img
extern u8 const Tsa_EndingMonologue[]; // tm
extern u8 const Zpal_EndingMonologue[]; // compressed pal
extern u16 const Pal_EndingMonologueText[]; // pal
extern u16 CONST_DATA BgConf_EndingMonologue[]; // bg config
