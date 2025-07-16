#pragma once

#include "prelude.h"
#include "proc.h"

enum videoalloc_xmap {
    OBCHR_XMAP = 0x80,
	OBPAL_XMAP = 4,
};

enum proc_label_xmap {
	PL_XMAP_0,
	PL_XMAP_1,
	PL_XMAP_2,
	PL_XMAP_3
};

struct ProcXmap {
	PROC_HEADER;

	/* 29 */ u8 unk_29;
	/* 2A */ u8 unk_2A;
	/* 2B */ u8 unk_2B;
	/* 2C */ u8 unk_2C;
	/* 2D */ u8 unk_2D;
	/* 2E */ u8 unk_2E;

	STRUCT_PAD(0x2F, 0x38);

	i8 avaliable_trials[8];
};

extern EWRAM_DATA struct Text gXmapTexts[6];

void Xmap_Init(struct ProcXmap *proc);
// func_fe6_0808AEFC
// func_fe6_0808AF4C
void func_fe6_0808B028(struct ProcXmap *proc);
void func_fe6_0808B194(struct ProcXmap *proc);
void func_fe6_0808B2BC(struct ProcXmap *proc);
void func_fe6_0808B378(struct ProcXmap *proc);
void func_fe6_0808B3B8(struct ProcXmap *proc);
void func_fe6_0808B40C(struct ProcXmap *proc);
void func_fe6_0808B430(struct ProcXmap *proc);
void Xmap_End(struct ProcXmap *proc);
void Xmap_TextEnd(struct ProcXmap *proc);
// SaveMenu_ExecXmap
// func_fe6_0808B598
// func_fe6_0808B628
// func_fe6_0808B640
// func_fe6_0808B7A0
// func_fe6_0808B7B4
// func_fe6_0808B854
// func_fe6_0808B928
// func_fe6_0808B93C
// func_fe6_0808B9B4
// func_fe6_0808B9CC
// func_fe6_0808BBCC
// func_fe6_0808BCBC
// func_fe6_0808BCF0
// func_fe6_0808BD28
// SaveMenu_ExecSoundroom
// func_fe6_0808BD6C
// func_fe6_0808BD78
// func_fe6_0808BDF8
// NewProc_0868AA80
// func_fe6_0808BE70
// func_fe6_0808BF00
// func_fe6_0808BFF0
// func_fe6_0808C084
// func_fe6_0808C098
// NewProc_0868AAA8

extern struct ProcScr CONST_DATA ProcScr_Xmap[];
// extern CONST_DATA ??? ProcScr_0868A634
// extern CONST_DATA ??? ProcScr_0868A644
// extern CONST_DATA ??? gUnk_0868A664
// extern CONST_DATA ??? Sprite_0868A988
// extern CONST_DATA ??? Imgs_0868A998
// extern CONST_DATA ??? Sprite_0868A9E8
// extern CONST_DATA ??? Sprite_0868A9F0
// extern CONST_DATA ??? Sprite_0868A9F8
// extern CONST_DATA ??? ProcScr_SoundRoom
// extern CONST_DATA ??? ProcScr_0868AA80
// extern CONST_DATA ??? ProcScr_0868AAA8
