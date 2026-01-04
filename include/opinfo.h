#pragma once

#include "prelude.h"
#include "proc.h"

enum videoalloc_opinfo {
	OBPAL_OFINFOVIEW_LETTER_REF = 0,
	OBPAL_OFINFOVIEW_LETTER0 = 1,
	OBPAL_OFINFOICON_LINE = 14,
	OBPAL_OFINFOICON = 15,
};

enum OpInfoModeIndex {
	OPINFO_STATE_0,
	OPINFO_STATE_IDLE,
	OPINFO_STATE_2,
	OPINFO_STATE_3,
};

struct ClassDemoData {
	STRUCT_PAD(0x00, 0x2C);

	u8 jids_2C[5];
	u8 jids_31[8];
};

extern CONST_DATA struct ClassDemoData *gClassDemoData;

enum OpInfoProcLabel {
	PL_OPINFO_BRANMCH = 1,
	PL_OPINFO_IDLE = 2,
	PL_OPINFO_NAME_INTRO = 4,
	PL_OPINFO_END_TITLE = 5,
	PL_OPINFO_END_EXT = 6,
};

struct ProcOpInfo {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x2A);

	/* 2A */ u16 fade_speed;
	/* 2C */ u8 mode;
	/* 2D */ u8 class_set;
	/* 2E */ u8 unk_2E;
	/* 2F */ u8 unk_2F;
	/* 30 */ u8 unk_30;
	/* 31 */ u8 unk_31, unk_32;

	/* 34 */ ProcPtr subproc1;
	/* 38 */ ProcPtr anim_proc;
	/* 3C */ int proc_run_time;
	/* 40 */ int proc_start_time;
};

void OpInfo_Init(struct ProcOpInfo *proc);
void OpInfo_Branch(struct ProcOpInfo *proc);
void OpInfo_PostAnim(struct ProcOpInfo *proc);
void OpInfo_Idle(struct ProcOpInfo *proc);
void OpInfo_FadeBgmOut(struct ProcOpInfo *proc);
void OpInfo_EndSubProcs(struct ProcOpInfo *proc);
void OpInfo_End(struct ProcOpInfo *proc);
void StartClassDemo(u8 arg_0, ProcPtr parent);

struct ProcOpInfoFadeOut {
	PROC_HEADER;

	/* 2A */ u16 speed;
};

void OpInfoFadeOut_Sync(struct ProcOpInfoFadeOut *proc);
void OpInfo_FadeOut(u8 speed);

void PutOpInfoViewLetter(u16 char_base, u8 char_index, int x, int y, u16 x_scale, u16 y_scale, u8 pal_off);

struct ProcOpInfoEnter {
	PROC_HEADER;

	/* 2A */ u16 timer;
	/* 2C */ u16 unk_2C;
	/* 2E */ u8 unk_2E;
	/* 2F */ u8 char_count;
	/* 30 */ u8 sprit_count;
};

void OpInfoEnter_Init(struct ProcOpInfoEnter *proc);
// func_fe6_08094B28
// OpInfoEnter_Loop_In
// OpInfoEnter_Loop_Out
// OpInfoEnter_OnEnd
ProcPtr NewOpInfoEnter(struct ProcOpInfo *proc, int a);
// OpInfoView_Init
// OpInfoView_Loop_FadeIn
// OpInfoView_Loop_Display
// OpInfoView_Loop_FadeOut
// NewOpInfoView
// func_fe6_08094F08
// OpInfoIcon_Init
// func_fe6_08094F94
// func_fe6_08095034
// OpInfoIcon_Loop_FadeIn
// OpInfoIcon_LoopA
// OpInfoIcon_LoopB
// OpInfoIcon_Loop_FadeOut
// NewOpInfoIcon

struct ProcClassInfoDisp {
	PROC_HEADER;
};

void HBlank_ClassInfoDisp(void);
void OpInfo_EfxmagicMiniCallBack(void);
void ClassInfoDisp_ExecEkrMainMini(struct ProcClassInfoDisp *proc);
void ClassInfoDisp_Loop_Intro(struct ProcClassInfoDisp *proc);
void ClassInfoDisp_Loop_Main(struct ProcClassInfoDisp *proc);
void ClassInfoDisp_Block(struct ProcClassInfoDisp *proc);
void ClassInfoDisp_OnEnd(struct ProcClassInfoDisp *proc);

ProcPtr StartClassAnimDisplay(struct ProcOpInfo *proc, int index);
// func_fe6_08095AE0
// func_fe6_08095BCC
// func_fe6_08095D28
// func_fe6_08095D2C
// func_fe6_08095D40
// func_fe6_08095D48
// func_fe6_08095D58

extern CONST_DATA struct ProcScr ProcScr_OpInfo[];
extern CONST_DATA struct ProcScr ProcScr_OpInfoFadeOut[];
extern CONST_DATA struct ProcScr ProcScr_OpInfoEnter[];
extern CONST_DATA struct ProcScr ProcScr_OpInfoView[];
extern CONST_DATA struct ProcScr ProcScr_OpInfoIcon[];
extern CONST_DATA struct ProcScr ProcScr_ClassInfoDisp[];
// extern CONST_DATA ??? gUnk_08690014
extern CONST_DATA u16 *Sprites_OpInfo_0869006C[];
extern CONST_DATA u16 *Sprites_OpInfo_086900BC[];
extern CONST_DATA u16 Sprite_OpInfo_086900DC[];
extern CONST_DATA u16 Sprite_OpInfo_086900F0[];
extern CONST_DATA u16 Sprite_OpInfo_086900F8[];
extern CONST_DATA u16 Sprite_OpInfo_08690100[];
extern CONST_DATA u16 *Sprites_OpInfo_08690288[];
extern CONST_DATA u8 gUnk_0869056C[][4];
// extern CONST_DATA ??? gUnk_0869058C
// extern CONST_DATA ??? gUnk_086905B0
// extern CONST_DATA ??? gUnk_086905F8
// extern CONST_DATA ??? gUnk_086909A4
// extern CONST_DATA ??? gUnk_08690A53
// extern CONST_DATA ??? gClassDemoData
// extern CONST_DATA ??? gUnk_08690C14
// extern CONST_DATA ??? gUnk_08690D44
