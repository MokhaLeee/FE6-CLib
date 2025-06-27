#pragma once

#include "prelude.h"
#include "proc.h"

enum ClassDemoModeIndex {
    CALSS_DEMO_MODE_0,
    CALSS_DEMO_MODE_1,
    CALSS_DEMO_MODE_2,
    CALSS_DEMO_MODE_3,
};

enum ClassDemoProcLabel {
    PL_CLASS_DEMO_BRANMCH = 1,
    PL_CLASS_DEMO_IDLE = 2,
    PL_CLASS_DEMO_END_FADE = 4,
    PL_CLASS_DEMO_END_TITLE = 5,
    PL_CLASS_DEMO_END_EXT = 6,
};

struct ProcClassDemo {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2A);

    /* 2A */ u16 timer;
    /* 2C */ u8 mode;
    /* 2D */ u8 class_set;
    /* 2E */ u8 unk_2E;
    /* 2F */ u8 unk_2F;
    /* 30 */ u8 unk_30;
    /* 31 */ u8 unk_31, unk_32;

    /* 34 */ ProcPtr subproc1;
    /* 38 */ ProcPtr anim_proc;
    /* 3C */ int unk_3C;
    /* 40 */ int game_time;
};

void ClassDemo_Init(struct ProcClassDemo * proc);
void ClassDemo_Branch(struct ProcClassDemo * proc);
void ClassDemo_PostAnim(struct ProcClassDemo * proc);
void ClassDemo_Idle(struct ProcClassDemo * proc);
void ClassDemo_FadeBgmOut(struct ProcClassDemo * proc);
void ClassDemo_EndSubProcs(struct ProcClassDemo * proc);
void ClassDemo_End(struct ProcClassDemo * proc);
void StartClassDemo(u8 arg_0, ProcPtr parent);
// func_fe6_0809480C
void func_fe6_0809485C(u8 a);
// func_fe6_08094878
// func_fe6_080949B8
// func_fe6_08094B28
// func_fe6_08094B80
// func_fe6_08094BE0
// func_fe6_08094C50
ProcPtr func_fe6_08094C80(struct ProcClassDemo * proc, int a);
// func_fe6_08094CB8
// func_fe6_08094CEC
// func_fe6_08094E20
// func_fe6_08094E4C
// func_fe6_08094EE8
// func_fe6_08094F08
// func_fe6_08094F14
// func_fe6_08094F94
// func_fe6_08095034
// func_fe6_08095100
// func_fe6_08095138
// func_fe6_0809517C
// func_fe6_080951A4
// func_fe6_080951DC
// func_fe6_080951FC
// func_fe6_0809525C
// func_fe6_08095334
// func_fe6_08095850
// func_fe6_0809597C
// func_fe6_08095A70
// func_fe6_08095A74
ProcPtr StartClassAnimDisplay(struct ProcClassDemo * proc, int index);
// func_fe6_08095AE0
// func_fe6_08095BCC
// func_fe6_08095D28
// func_fe6_08095D2C
// func_fe6_08095D40
// func_fe6_08095D48
// func_fe6_08095D58

// extern CONST_DATA ??? ProcScr_ClassDemo
// extern CONST_DATA ??? ProcScr_ClassDemo_0868FEDC
// extern CONST_DATA ??? ProcScr_ClassDemo_0868FEFC
// extern CONST_DATA ??? gUnk_0868FF4C
// extern CONST_DATA ??? gUnk_0868FF84
// extern CONST_DATA ??? gUnk_0868FFCC
// extern CONST_DATA ??? gUnk_08690014
// extern CONST_DATA ??? gUnk_0869006C
// extern CONST_DATA ??? gUnk_086900BC
// extern CONST_DATA ??? gUnk_086900DC
// extern CONST_DATA ??? gUnk_086900F0
// extern CONST_DATA ??? gUnk_086900F8
// extern CONST_DATA ??? gUnk_08690100
// extern CONST_DATA ??? gUnk_08690288
extern CONST_DATA u8 gUnk_0869056C[][4];
// extern CONST_DATA ??? gUnk_0869058C
// extern CONST_DATA ??? gUnk_086905B0
// extern CONST_DATA ??? gUnk_086905F8
// extern CONST_DATA ??? gUnk_086909A4
// extern CONST_DATA ??? gUnk_08690A53
// extern CONST_DATA ??? gUnk_08690A99
// extern CONST_DATA ??? gUnk_08690C14
// extern CONST_DATA ??? gUnk_08690D44
