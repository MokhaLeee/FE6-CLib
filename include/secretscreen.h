#pragma once

#include "prelude.h"
#include "proc.h"
#include "unit.h"
#include "text.h"

enum videoalloc_secret_screen {
	BGPAL_SECRETSCREEN_MURALBG = 10,
};

enum { SID_PID_POOL_SIZE = 5 };

struct ProcSecretScreen {
	PROC_HEADER;

	/* 2A */ u16 unk_2A;
	/* 2C */ u8 count;
	/* 30 */ struct Unit *units[SID_PID_POOL_SIZE];
	/* 44 */ ProcPtr subproc;
};

struct SecretScreenData {
	/* 00 */ u8 numbers[0x18];
};

extern struct SecretScreenData gSecretScreenData[];

struct UnkStruct_020169C4 {
	STRUCT_PAD(0x0, 0x6);

	u16 unk_06;
};

struct UnkStruct_SecretScreen_030048C0 {
	/* 00 */ u16 total_turn;
	/* 02 */ u16 winning_rate;
	/* 04 */ u16 dead_allies;
	/* 06 */ u16 total_level_gained;
	/* 08 */ u16 total_asset;
	/* 0A */ u16 unk_0A;
	/* 0C */ u16 total_power;
	/* 0E */ u8 hours, minutes, secounds;
	/* 11 */ u8 unk_11;
};

extern IWRAM_DATA struct UnkStruct_SecretScreen_030048C0 gSecretScreen_030048C0;


void func_fe6_08082E74(int a, int b);
// func_fe6_08082EC0
u32 GetSecretScreenRN(void);
// func_fe6_08082F18
// func_fe6_08082F54
u32 SecretRnGetter_08082FE8(int a, int b, int round);
// func_fe6_08083078
// func_fe6_080830AC
// func_fe6_08083180
void ModifyPassword(void (*func)(int a, int b));
// func_fe6_08083378
// func_fe6_0808344C
// func_fe6_0808347C
// InitPassword
// func_fe6_0808357C
// func_fe6_08083618
// PrintPassword
// func_fe6_08083750
// func_fe6_080837C8
// func_fe6_080838FC
// func_fe6_08083900
// func_fe6_08083930
void func_fe6_08083944(int a, int b);
// func_fe6_08083A68
int GetFlattenArrayOffset(int line, int col);
void func_fe6_08083BC4(struct Unit *units[], int count);
void PrintSecretScreenTexts(struct Text *text, const u8 *table);
void PutSecretScreenLineNumber(int line);
void SecretScreen_Init(struct ProcSecretScreen *proc);
void SecretScreen_Loop_Dummy(struct ProcSecretScreen *proc);
void SecretScreen_End(struct ProcSecretScreen *proc);
ProcPtr NewGeneralSecretScreen(ProcPtr parent);
ProcPtr NewUniqueSecretScreen(struct Unit *unit, ProcPtr parent);

extern EWRAM_OVERLAY(0) int Unk_020168F0;
extern EWRAM_OVERLAY(0) int Unk_020168F4;
extern EWRAM_OVERLAY(0) struct Text gSecretScreenTexts[5];
extern EWRAM_OVERLAY(0) int gSecretScreenRN;
extern EWRAM_OVERLAY(0) u8 Unk_02016924[0xA0];
extern EWRAM_OVERLAY(0) struct UnkStruct_020169C4 Unk_020169C4;

extern EWRAM_DATA u8 SioPidPool[SID_PID_POOL_SIZE];
extern EWRAM_DATA u8 Unk_0203D518[10];

extern CONST_DATA u8 gUnk_0867978C[];
extern struct ProcScr ProcScr_Prep_Password[];
extern CONST_DATA u8 gUnk_08679820[];
extern CONST_DATA struct ProcScr ProcScr_SecretScreen[];
