#pragma once

#include "prelude.h"
#include "menu.h"
#include "proc.h"

enum video_augury {
    BGPAL_AUGURY_4 = 4,
};

enum AUGURY_CHOICE {
	AUGURY_CHOICE_0,
	AUGURY_CHOICE_1,
	AUGURY_CHOICE_2,
};

enum AUGURY_PROC_LABLE {
	PL_AUGURY_0,
	PL_AUGURY_1,
	PL_AUGURY_2,
	PL_AUGURY_3,
	PL_AUGURY_4,
	PL_AUGURY_5,
	PL_AUGURY_6,
};

struct AuguryDispConfig {
	u8 x, y;

	u8 _pad_[2];
};

struct AuguryConfig {
	/* 00 */ u8 fid;
	/* 01 */ u8 pid;
	/* 04 */ int *msgs1;
	/* 08 */ int *msgs2;
	/* 0C */ int *msgs3;
};

struct Proc_0868AFF0_Augury {
	PROC_HEADER;

	i16 timer1;
	i16 timer2;
	int current_bgm;
};

struct ProcAugury {
	PROC_HEADER;
};

extern EWRAM_OVERLAY(0) i16 gAuguryIndex;
extern EWRAM_OVERLAY(0) u16 unk_020169CE;
extern EWRAM_OVERLAY(0) u16 unk_020169D0;
extern EWRAM_OVERLAY(0) u16 unk_020169D2;
extern EWRAM_OVERLAY(0) u8 gAuguryStatus[7];
extern EWRAM_OVERLAY(0) u8 gCurrentAuguryIndex;
extern EWRAM_OVERLAY(0) i8 gAuguryChoice;
extern EWRAM_OVERLAY(0) struct Text gAuguryTexts[7];
extern EWRAM_OVERLAY(0) i16 ProcAugury_0868AFF0_EndEnable;
extern EWRAM_OVERLAY(0) i16 unk_02016A1A;
extern EWRAM_OVERLAY(0) i16 unk_02016A1C;
extern EWRAM_OVERLAY(0) u16 unk_02016A1E;
extern EWRAM_OVERLAY(0) u16 unk_02016A20;
extern EWRAM_OVERLAY(0) u16 unk_02016A22;
extern EWRAM_OVERLAY(0) u16 unk_02016A24;
extern EWRAM_OVERLAY(0) u16 unk_02016A26;
extern EWRAM_OVERLAY(0) u16 unk_02016A28;
extern EWRAM_OVERLAY(0) u16 unk_02016A2A;
extern EWRAM_OVERLAY(0) u8 unk_02016A2C;
extern EWRAM_OVERLAY(0) u8 unk_02016A2D;
extern EWRAM_OVERLAY(0) u16 unk_02016A2E[7];
extern EWRAM_OVERLAY(0) u8 unk_02016A3C;
extern EWRAM_OVERLAY(0) u8 unk_02016A3D;
extern EWRAM_OVERLAY(0) u8 unk_02016A3E;
extern EWRAM_OVERLAY(0) u8 unk_02016A3F;
extern EWRAM_OVERLAY(0) u8 unk_02016A40;
extern EWRAM_OVERLAY(0) u8 unk_02016A41;
extern EWRAM_OVERLAY(0) u8 unk_02016A42;
extern EWRAM_OVERLAY(0) u8 unk_02016A43;
extern EWRAM_OVERLAY(0) u8 unk_02016A44[0x7F];
extern EWRAM_OVERLAY(0) u8 unk_02016AC3[0x81];
extern EWRAM_OVERLAY(0) u8 unk_02016B44;
extern EWRAM_OVERLAY(0) struct Text Texts_02016B48[6];
extern EWRAM_OVERLAY(0) struct Text Texts_02016B78[2];
extern EWRAM_OVERLAY(0) u8 unk_02016B88;
extern EWRAM_OVERLAY(0) u8 unk_02016B89;
extern EWRAM_OVERLAY(0) u8 unk_02016B8A;
extern EWRAM_OVERLAY(0) ProcPtr gpAuguryFaceProc;
extern EWRAM_OVERLAY(0) u16 unk_02016B90;
extern EWRAM_OVERLAY(0) u16 unk_02016B92;
extern EWRAM_OVERLAY(0) u8 unk_02016B94[0x100];
extern EWRAM_OVERLAY(0) u8 unk_02016C94[0x100];

bool func_fe6_0808D0C0(struct MenuProc *proc);
fu8 GetAuguryIndex(void);
void StartAuguryDialogue1(int msg, ProcPtr proc);
void StartAuguryDialogue2(int msg);
void Augury_InitBG(void);
void Augury_InitIO(ProcPtr proc);
void func_fe6_0808D308(void);
void func_fe6_0808D368(void);
void Augury_Init(void);
void func_fe6_0808D59C(ProcPtr proc);
void func_fe6_0808D630(ProcPtr proc);
void func_fe6_0808D6D4(u16 old, u16 new);
void func_fe6_0808D7B4(ProcPtr proc);
void func_fe6_0808D7F8(ProcPtr proc);
void func_fe6_0808D900(ProcPtr proc);
void func_fe6_0808D938(ProcPtr proc);
void func_fe6_0808D954(ProcPtr proc);
void func_fe6_0808D978(ProcPtr proc);
void func_fe6_0808D99C(ProcPtr proc);
void func_fe6_0808D9B0(ProcPtr proc);
void func_fe6_0808D9F0(ProcPtr proc);
void AuguryPaletteModify1(u16 *pal, int line, int start, int count, int val);
void AuguryPaletteModify2(u16 *pal, int line, int start, int count, int val);
void func_fe6_0808DB14(int lo0, int hi0, int lo1, int hi1, int x);
void func_fe6_0808DB90(struct Proc_0868AFF0_Augury *proc);
void func_fe6_0808DB98(struct Proc_0868AFF0_Augury *proc);
void func_fe6_0808DC30(struct Proc_0868AFF0_Augury *proc);
void func_fe6_0808DC4C(struct Proc_0868AFF0_Augury *proc);
void func_fe6_0808DD24(ProcPtr proc);
// func_fe6_0808DD40
// func_fe6_0808DD78
// func_fe6_0808DE04
// func_fe6_0808DE5C
// func_fe6_0808DE70
// func_fe6_0808DEA4
// func_fe6_0808DF3C
// func_fe6_0808DF78
// func_fe6_0808DFC4
// func_fe6_0808DFCC
// func_fe6_0808E0DC
// func_fe6_0808E1D0
// func_fe6_0808E1E4
// func_fe6_0808E264
// func_fe6_0808E284
// func_fe6_0808E2D0
// func_fe6_0808E2F0
// func_fe6_0808E2F4
// func_fe6_0808E390
// func_fe6_0808E420
// func_fe6_0808E434
// func_fe6_0808E4E8
// func_fe6_0808E5F0
// func_fe6_0808E6E0
// func_fe6_0808E6FC
// func_fe6_0808E710
// func_fe6_0808E730
// func_fe6_0808E79C
// func_fe6_0808E7CC
// func_fe6_0808E93C
// func_fe6_0808EA74
// func_fe6_0808EB94
// func_fe6_0808EC1C
// func_fe6_0808EC48
// func_fe6_0808EC78
// func_fe6_0808ECD0
// func_fe6_0808EDE0
// func_fe6_0808F060
// func_fe6_0808F098
// func_fe6_0808F22C
// func_fe6_0808F27C
// func_fe6_0808F2A4
// func_fe6_0808F2F0
// func_fe6_0808F30C
u8 func_fe6_0808F33C(void);
// func_fe6_0808F3E8
// func_fe6_0808F470
u8 func_fe6_0808F490(void);
// func_fe6_0808F4B8
// func_fe6_0808F4F0
u8 func_fe6_0808F524(void);
// func_fe6_0808F550
// func_fe6_0808F59C
u8 func_fe6_0808F5AC(void);
u8 func_fe6_0808F600(void);
// func_fe6_0808F648
u8 func_fe6_0808F68C(void);
u8 func_fe6_0808F6E0(void);
// func_fe6_0808F73C
// func_fe6_0808F780
// func_fe6_0808F790
// func_fe6_0808F7B0
// func_fe6_0808F7D0
// func_fe6_0808F838
// func_fe6_0808F844
// func_fe6_0808F8B8
// func_fe6_0808F984
// func_fe6_0808FA14
// func_fe6_0808FD14
// func_fe6_0808FD44
void func_fe6_0808FD6C(ProcPtr parent);

extern CONST_DATA int AuguryMsgs[];
extern CONST_DATA struct AuguryDispConfig gAuguryDispConfig[];
extern CONST_DATA struct AuguryConfig gAuguryConfig[];
extern CONST_DATA u16 Obj_AuguryUI[];
extern CONST_DATA u16 BgConf_Augury[];
extern CONST_DATA struct ProcScr ProcScr_0868AFD8[];
extern CONST_DATA struct ProcScr ProcScr_0868AFF0[];
extern CONST_DATA struct ProcScr ProcScr_Augury[];
// extern CONST_DATA ??? HelpInfo_0868B1B0
// extern CONST_DATA ??? HelpInfo_0868B2C8
// extern CONST_DATA ??? HelpInfo_0868B3C4
extern CONST_DATA u16 *gpAuguryBuf[];
// extern CONST_DATA ??? gUnk_0868B410
// extern CONST_DATA ??? gUnk_0868B418
// extern CONST_DATA ??? gUnk_0868B420
// extern CONST_DATA ??? gUnk_0868B490
// extern CONST_DATA ??? gUnk_0868B4D0
// extern CONST_DATA ??? gUnk_0868B5B0
// extern CONST_DATA ??? gUnk_0868B5C8
// extern CONST_DATA ??? gUnk_0868B5E0
extern CONST_DATA struct ProcScr ProcScr_0868B5E8[];
extern CONST_DATA struct ProcScr ProcScr_0868B610[];
extern CONST_DATA struct ProcScr ProcScr_0868B648[];
extern CONST_DATA struct ProcScr ProcScr_0868B6D8[];
extern CONST_DATA struct ProcScr ProcScr_0868B700[];
// extern CONST_DATA ??? gUnk_0868B720
extern CONST_DATA struct ProcScr ProcScr_0868B730[];
extern CONST_DATA struct ProcScr ProcScr_0868B750[];
extern CONST_DATA struct ProcScr ProcScr_0868B768[];
// extern CONST_DATA ??? gUnk_0868B788
// extern CONST_DATA ??? gUnk_0868B79C
// extern CONST_DATA ??? gUnk_0868B7A0
// extern CONST_DATA ??? gUnk_0868B7A4
// extern CONST_DATA ??? gUnk_0868B7A8
// extern CONST_DATA ??? gUnk_0868B7B8
// extern CONST_DATA ??? gUnk_0868B7D6
// extern CONST_DATA ??? gUnk_0868B7E2
// extern CONST_DATA ??? gUnk_0868B7E8
// extern CONST_DATA ??? BgConfig_0868B7F4
extern CONST_DATA struct ProcScr ProcScr_0868B80C[];
extern CONST_DATA struct ProcScr ProcScr_0868B88C[];
extern CONST_DATA struct ProcScr ProcScr_0868B8AC[];
extern CONST_DATA struct ProcScr ProcScr_0868B8E4[];
extern CONST_DATA struct ProcScr ProcScr_0868B99C[];
// extern CONST_DATA ??? gUnk_0868BA24
// extern CONST_DATA ??? gUnk_0868BA3C
// extern CONST_DATA ??? gUnk_0868BB1C
extern CONST_DATA struct ProcScr ProcScr_0868BB3C[];
extern CONST_DATA struct ProcScr ProcScr_0868BB5C[];
extern CONST_DATA struct ProcScr ProcScr_0868BB7C[];
// extern CONST_DATA ??? gUnk_0868BB9C
// extern CONST_DATA ??? gUnk_0868BBEC
extern CONST_DATA struct ProcScr ProcScr_0868BC44[];
// extern CONST_DATA ??? gUnk_0868BC8C
// extern CONST_DATA ??? gUnk_0868BCE4
extern CONST_DATA struct ProcScr ProcScr_0868BDB4[];
// extern CONST_DATA ??? gUnk_0868BDF4
// extern CONST_DATA ??? gUnk_0868BE2C
// extern CONST_DATA ??? gUnk_0868BE4C
extern CONST_DATA struct ProcScr ProcScr_0868BE74[];
// extern CONST_DATA ??? gUnk_0868BEEC
// extern CONST_DATA ??? gUnk_0868BF14
extern CONST_DATA struct ProcScr ProcScr_0868BF3C[];
// extern CONST_DATA ??? gUnk_0868BFAC
// extern CONST_DATA ??? gUnk_0868BFCC
