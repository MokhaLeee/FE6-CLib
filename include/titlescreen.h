#pragma once

#include "prelude.h"
#include "proc.h"

struct ProcTitle {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x64);

    /* 64 */ i16 timer;
};

struct ProcTitleDisp {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x64);

    /* 64 */ i16 timer1, timer2;
};

void Title_ReinitTimer(struct ProcTitle * proc);
void Title_Idle(struct ProcTitle * proc);
void Title_End(struct ProcTitle * proc);
void func_fe6_0809B378(ProcPtr proc);
void Title_Init(struct ProcTitle * proc);
void Title_InitDisp(struct ProcTitle * proc);
void func_fe6_0809B53C(struct ProcTitleDisp * proc);
void func_fe6_0809B54C(struct ProcTitleDisp * proc);
void func_fe6_0809B590(struct ProcTitleDisp * proc);
void func_fe6_0809B608(struct ProcTitleDisp * proc);
void func_fe6_0809B69C(struct ProcTitleDisp * proc);
void func_fe6_0809B6A4(struct ProcTitleDisp * proc);
void func_fe6_0809B6CC(struct ProcTitleDisp * proc);
void func_fe6_0809B6F4(struct ProcTitleDisp * proc);
void func_fe6_0809B75C(struct ProcTitleDisp * proc);
void func_fe6_0809B7D4(struct ProcTitleDisp * proc);
void func_fe6_0809B864(struct ProcTitleDisp * proc);
void func_fe6_0809B898(struct ProcTitleDisp * proc);
void func_fe6_0809B8FC(struct ProcTitleDisp * proc);
void func_fe6_0809B96C(struct ProcTitleDisp * proc);
void func_fe6_0809B99C(struct ProcTitleDisp * proc);
void Title_StartBgm(struct ProcTitle * proc);
void func_fe6_0809BB00(void);

extern struct ProcScr CONST_DATA ProcScr_TitleScreenFromOp[];
extern struct ProcScr CONST_DATA ProcScr_TitleScreen[];
extern struct ProcScr CONST_DATA ProcScr_Title_08692258[];
extern struct ProcScr CONST_DATA ProcScr_Title_08692268[];
extern struct ProcScr CONST_DATA ProcScr_Title_08692298[];
extern u16 CONST_DATA Sprite_086922F0[];
extern u16 CONST_DATA Sprite_086922F8[];
extern u16 CONST_DATA Sprite_08692300[];
extern struct ProcScr CONST_DATA ProcScr_TitleScreenFromOp[];
