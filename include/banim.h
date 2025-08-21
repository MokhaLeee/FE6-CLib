#pragma once

/**
 * messed banim related struct/data/functions
 */

#include "prelude.h"
#include "banim_sprite.h"
#include "battle.h"
#include "face.h"

#define ANIM_REF_OFFSET(off_ref_round, off_ref_pos) ((off_ref_round) * 2 + off_ref_pos)

enum EkrDistanceType_idx {
    EKR_DISTANCE_CLOSE,
    EKR_DISTANCE_FAR,
    EKR_DISTANCE_FARFAR,
    EKR_DISTANCE_MONOCOMBAT,
    EKR_DISTANCE_PROMOTION,

    EKR_DISTANCE_MAX
};

extern i16 gEkrDistanceType;

extern struct BaSprite * gAnims[4];
#define MAIN_ANIM_FRONT(pos) (gAnims[pos * 2 + 0])
#define MAIN_ANIM_BACK(pos)  (gAnims[pos * 2 + 1])

enum banim_mode_index {
    BANIM_MODE_NORMAL_ATK,
    BANIM_MODE_NORMAL_ATK_PRIORITY_L,
    BANIM_MODE_CRIT_ATK,
    BANIM_MODE_CRIT_ATK_PRIORITY_L,
    BANIM_MODE_RANGED_ATK,
    BANIM_MODE_RANGED_CRIT_ATK,
    BANIM_MODE_CLOSE_DODGE,
    BANIM_MODE_RANGED_DODGE,
    BANIM_MODE_STANDING,
    BANIM_MODE_STANDING2,
    BANIM_MODE_RANGED_STANDING,
    BANIM_MODE_MISSED_ATK,

    BANIM_MODE_INVALID = -1,
};

#define EFX_BG_WIDTH 66
#define EFX_TILEMAP_LOC(aMap, aX, aY) (aMap + (aX) + EFX_BG_WIDTH * (aY))

enum video_banim {
    BGPAL_EFX_0 = 0,
    BGPAL_EFX_SPELL_BG = 1,
    BGPAL_EFX_2 = 2,
    BGPAL_EFX_3 = 3,
    BGPAL_EFX_4 = 4,
    BGPAL_EFXDRAGON_L = 6,
    BGPAL_EFXDRAGON_R = 7,

    OBPAL_EFX_SYSTEM_OBJ = 0,
    OBPAL_EFX_SPELL_BG = 1,
    OBPAL_EFX_SPELL_OBJ = 2,
    OBPAL_EFX_FACE = 3,
    OBPAL_EFX_5 = 5,
    OBPAL_EFX_BG = 6,
    OBPAL_EFX_UNIT_L = 7,
    OBPAL_EFX_UNIT_BAK_L = 8,
    OBPAL_EFX_UNIT_R = 9,
    OBPAL_EFX_UNIT_BAK_R = 10,
    OBPAL_EFXHPBAR_L = 11,
    OBPAL_EFXHPBAR_R = 12,
    OBPAL_EFX_ITEM_L = 13,
    OBPAL_EFX_ITEM_R = 14,

    VRAMOFF_BANIM_SPELL_OBJ = 0x0800,
    VRAMOFF_BANIM_SPELL_BG  = 0x2000,
    VRAMOFF_BANIM_8000 = 0x8000,

    VRAMOFF_OBJ_EKRGAUGE_SUBFIX = 0x3800,
    VRAMOFF_OBJ_EKRGAUGE_NUM_L  = 0x3A00,
    VRAMOFF_OBJ_EKRGAUGE_ICON_L = 0x3B80,
    VRAMOFF_OBJ_EKRGAUGE_ICON_R = 0x3BC0,
    VRAMOFF_OBJ_EKRGAUGE_ARROW  = 0x3C00,
    VRAMOFF_OBJ_EKRGAUGE_NUM_R  = 0x3E00,
    VRAMOFF_OBJ_4000            = 0x4000,
    VRAMOFF_OBJ_6000            = 0x6000,

    VRAMOFF_BG_EKRLVUP_FONT = 0x2400,
};

enum ekr_hit {
    EKR_HITTED = 0,
    EKR_MISS
};

enum banim_sprites_size {
    BAS_SCR_MAX_SIZE = 0x2A00,
    BAS_OAM_MAX_SIZE = 0x5800,
    BAS_IMG_MAX_SIZE = 0x1000,

    BAS_OAM_REF_MAX_SIZE = BAS_OAM_MAX_SIZE - 0x10,
};

extern u8 gBanimScrs[2 * BAS_SCR_MAX_SIZE];
extern u8 gBanimOamBufs[2 * BAS_OAM_MAX_SIZE];
extern u8 gBanimImgSheetBufs[2 * BAS_IMG_MAX_SIZE];

struct ProcEfx {
    PROC_HEADER;

    /* 29 */ u8 hitted;
    /* 2A */ u8 type;
    /* 2B */ STRUCT_PAD(0x2B, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 step;
    /* 30 */ i16 unk30;
    /* 32 */ u16 unk32;
    /* 34 */ STRUCT_PAD(0x34, 0x44);
    /* 44 */ u32 unk44;
    /* 48 */ u32 unk48;
    /* 4C */ u32 frame;
    /* 50 */ u32 speed;
    /* 54 */ i16 * unk54;
    /* 58 */ i16 ** unk58;
    /* 5C */ struct Anim *anim;
    /* 60 */ struct Anim * sub_anim;
    ProcPtr unk_64;
};

struct ProcEfxBG {
    PROC_HEADER;

    /* 29 */ u8 unk29;
    STRUCT_PAD(0x2A, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 terminator;
    /* 30 */ i16 unk30;
    /* 32 */ i16 unk32;
    /* 34 */ i16 unk34;
    STRUCT_PAD(0x36, 0x3C);
    /* 3C */ i16 unk3C;
    STRUCT_PAD(0x3E, 0x44);
    /* 44 */ u32 frame;
    /* 48 */ const u16 * frame_config;
    /* 4C */ u16 ** tsal;
    /* 50 */ u16 ** tsar;
    /* 54 */ u16 ** img;
    /* 58 */ u16 ** pal;
    /* 5C */ struct  BaSprite *anim;
    /* 60 */ struct  BaSprite *sub_anim;
};

struct ProcEfxBGCOL {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 timer2;
    /* 30 */ i16 terminator;
    /* 32 */ i16 unk32;
    STRUCT_PAD(0x34, 0x44);
    /* 44 */ u32 frame;
    /* 48 */ const u16 * frame_config;
    /* 4C */ const u16 * pal;
    STRUCT_PAD(0x50, 0x5C);
    /* 5C */ struct  BaSprite *anim;
};

struct ProcEfxRST
{
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 unk2E;
    /* 30 */ i16 unk30;
    STRUCT_PAD(0x32, 0x5C);
    /* 5C */ struct  BaSprite *anim;
    STRUCT_PAD(0x60, 0x64);
    /* 64 */ ProcPtr unk64;
};

struct ProcEfxOBJ {
    PROC_HEADER;

    /* 29 */ u8 unk29;
    /* 2A */ u8 unk2A;
    STRUCT_PAD(0x2B, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 terminator;
    /* 30 */ u16 unk30;
    /* 32 */ u16 unk32;
    /* 34 */ u16 unk34;
    /* 36 */ u16 unk36;
    /* 38 */ u16 unk38;
    /* 3A */ u16 unk3A;
    /* 3C */ u16 unk3C;
    /* 3E */ u16 unk3E;
    /* 40 */ u16 unk40;
    /* 42 */ u16 unk42;
    /* 44 */ int unk44;
    /* 48 */ int unk48;
    /* 4C */ int unk4C;
    STRUCT_PAD(0x50, 0x5C);
    /* 5C */ struct  BaSprite *anim;
    /* 60 */ struct  BaSprite *anim2;
    /* 64 */ struct  BaSprite *anim3;
    /* 68 */ struct  BaSprite *anim4;
};

extern void *gpBanimTerrainfxBufs[2];
extern u16 *gpBanimTerrainPalBufs[2];
extern int *gpBanimModesLeft;
extern int *gpBanimModesRight;
extern int gEkrDebugTimer;
extern int gEkrDebugFlag1;
extern int gEkrDebugFlag2;
extern int gAnimC01Blocking;
extern i16 gEkrXPosReal[2];
extern i16 gEkrYPosReal[2];
extern u16 gEkrXPosBase[2];
extern u16 gEkrYPosBase[2];
extern struct Vec2i gEkrBg0QuakeVec;
extern u16 * gpEfxUnitPaletteBackup[2];
extern i16 gEkrDebugModeMaybe;
extern u16 gBanimPaletteLeft[0x50];
extern u16 gBanimPaletteRight[0x50];
extern u16 gEfxPal[0x130];
extern struct Font gBanimFont;
extern struct Text gBanimText[20];
extern u32 gEkrBattleEndFlag;
extern i8 gEfxSplitedColorBufA[2][0x30];
extern i8 gEfxSplitedColorBufB[2][0x30];
extern i16 gEfxSplitedColorBufC[2][0x30];
extern int gProcEkrBaseAppearExist;
extern u32 gUnk_Banim_0201E0F8;
extern u32 gBanimDoneFlag[2];
extern ProcPtr gpProcEfxAnimeDrv;
extern const void * gpImgSheet[2];
extern ProcPtr gpProcEkrTogiColor;
extern int gEkrBg2ScrollFlip;
extern u16 * gpBg2ScrollOffsetStart;
extern u16 * gpBg2ScrollOffset;
extern u16 gpBg2ScrollOffsetTable1[];
extern u16 gpBg2ScrollOffsetTable2[];
extern int gEkrBg1ScrollFlip;
extern u16 * gpBg1ScrollOffsetStart;
extern u16 * gpBg1ScrollOffset;
extern u16 gpBg1ScrollOffsetList1[];
extern u16 gpBg1ScrollOffsetList2[];
extern int gEfxMagicChk_N;
extern int gEfxPurgeCounter;
extern u8 gEkrPids[2];
extern struct Unit * gpEkrTriangleUnits[2];
extern const u16 * gpBanimTriAtkPalettes[2];
extern const u8 * gBanimUnitChgForceImg[2];
extern i16 gBanimBG;
extern i16 gEkrInitialHitSide;
extern i16 gEkrSnowWeather;
extern u32 gEkrInitPosReal;
extern u32 gEfxFarAttackExist;
extern u32 gEfxBgSemaphore;
extern u32 gEfxHpBarResireFlag;
extern u32 gUnk_Banim_0201774C;
extern u32 gEfxTeonoState;
extern u32 gEfxTerrainLayerLow;
extern struct Vec2i gEkrBg2QuakeVec;
extern u32 gEkrBgPosition;
extern i16 gBanimEffectiveness[2];
extern i16 gBanimUniquePaletteDisabled[2];
extern i16 gBanimValid[2];
extern i16 gBanimPosIsTarget[2];
extern i16 gBanimIdx_bak[2];
extern i16 gBanimUniquePal[2];
extern i16 gBanimFactionPal[2];
extern i16 gEkrSpellAnimIndex[2];
extern i16 gBanimFloorfx[2];
extern i16 gBanimExpGain[2];
extern i16 gBanimTerrain[2];
extern i16 gBanimCon[2];
extern i16 gBanimWtaBonus[2];
extern i16 gEkrGaugeHp[2];
extern i16 gBanimMaxHP[2];
extern i16 gEkrGaugeHpBak[2];
extern i16 gEkrGaugeHit[2];
extern i16 gEkrGaugeDmg[2];
extern i16 gEkrGaugeCrt[2];
extern i16 gEkrBmLocation[4];
extern i16 gAnimRoundData[4];
extern i16 gEfxHpLutOff[2];
extern u16 gEfxHpLut[22];
extern i16 gBanimIdx[2];
extern struct BattleUnit * gpEkrBattleUnitLeft;
extern struct BattleUnit * gpEkrBattleUnitRight;
extern u32 gEkrHpBarCount;
extern u32 gEfxSpellAnimExists;
extern u32 gUnk_Banim_02017728;
extern u32 gEkrDeadExist;
extern u32 gEkrDeadEventExist;
extern u32 gEfxQuakeExist;
extern u32 gEfxHitQuakeExist;
extern i16 gEkrHitNow[];
extern u8 gSpellAnimBgfx[];
extern u16 gEkrBarfxBuf[];
extern u16 gEkrTsaBuffer[0x1000 / 2];
extern u8 gBuf_Banim[];
extern u16 gPal_Banim[];
extern u16 gTmA_Banim[0xB58 / sizeof(u16)];
extern u16 gTmB_Banim[0xB58 / sizeof(u16)];
extern i16 gBanimExpPrevious[2];

void NewEkrLvlupFan(void);
void EkrLvupFanMain(struct ProcEfx *proc);
// func_fe6_080435EC

struct ProcEkrGauge {
    PROC_HEADER;

    /* 29 */ u8 battle_init;           /* 1 in battle-starting and 0 after battle started */
    /* 2A */ u8 valid;
    /* 2B */ u8 _pad_2B[0x32 - 0x2B];
    /* 32 */ i16 unk32;
    /* 34 */ u8 _pad_34[0x3A - 0x34];
    /* 3A */ i16 unk3A;
    /* 3C */ u8 _pad_3C[0x44 - 0x3C];
    /* 44 */ int unk44;
    /* 48 */ int unk48;
    /* 4C */ int unk4C;
    /* 50 */ int unk50;
    /* 54 */
};

extern struct ProcEkrGauge * gpProcEkrGauge;
extern EWRAM_OVERLAY(banim) u16 Buf_EkrGaugeNumImg[0x200];
extern EWRAM_OVERLAY(banim) u16 gUnk_Banim_02016DC0[];
extern EWRAM_OVERLAY(banim) u8 gUnk_Banim_02016E40[0x200];
extern EWRAM_OVERLAY(banim) u8 gUnk_Banim_02017240[0x200];
extern EWRAM_OVERLAY(banim) u16 gEkrGaugeDecoder[18];

// EkrGaugeModDec
void NewEkrGauge(void);
void EndEkrGauge(void);
void EkrGauge_Clr4C50(void);
void EkrGauge_Set4C50(void);
void EkrGauge_Set4C(void);
void EkrGauge_Set50(void);
void EkrGauge_Setup44(u16 val);
void EkrGauge_Clr323A(i16 x, i16 y);
void EkrGauge_Setxy323A(i16 x, i16 y);
void EkrGauge_SetInitFlag(void);
void EkrGauge_ClrInitFlag(void);
void EnableEkrGauge(void);
void DisableEkrGauge(void);
// func_fe6_08043980
// EkrGauge_Loop
void NewEkrDispUP(void);
void EndEkrDispUP(void);
// func_fe6_080441DC
// func_fe6_080441EC
void func_fe6_080441FC(void);
void func_fe6_0804420C(void);
// func_fe6_0804421C
void EkrDispUP_SetPositionSync(u16 x, u16 y);
void SyncEkrDispUP(void);
void UnsyncEkrDispUP(void);
void AsyncEkrDispUP(void);
void UnAsyncEkrDispUP(void);
// EkrDispUP_Loop
void EfxClearScreenFx(void);
// EkrDispUp_PutTerrainfx
void EfxPrepareScreenFx(void);
int GetBanimInitPosReal(void);
void EkrEfxStatusClear(void);

struct ProcEfxHpBar {
    PROC_HEADER;

    /* 29 */ u8 death;
    STRUCT_PAD(0x2A, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 cur;
    STRUCT_PAD(0x30, 0x48);
    /* 48 */ int diff;
    /* 4C */ int this;
    /* 50 */ int next;
    /* 54 */ u32 timer2;
    /* 58 */ int finished;
    /* 5C */ struct BaSprite *anim_main_other;
    /* 60 */ struct BaSprite *anim_main_this;
    /* 64 */ struct BaSprite *anim_this;
};

int CheckEkrHitDone(void);
i16 CheckEkrHitNow(int pos);
void NewEfxHpBar(struct BaSprite *anim);
void EfxHpBar_DeclineToDeath(struct ProcEfxHpBar *proc);
void EfxHpBar_MoveCameraOnEnd(struct ProcEfxHpBar *proc);
void EfxHpBar_WaitCameraMove(struct ProcEfxHpBar *proc);
void NewEfxHpBarResire(struct BaSprite *anim);
void EfxHpBarResire_WaitOnCurrentSide(struct ProcEfxHpBar *proc);
void EfxHpBarResire_SetAnotherSide(struct ProcEfxHpBar *proc);
void EfxHpBarResire_DeclineToDeath(struct ProcEfxHpBar *proc);
void NewEfxAvoid(struct BaSprite *anim);
void EfxAvoid_Loop(struct ProcEfxHpBar *proc);
void NewEfxHpBarLive(struct BaSprite *anim);
void EfxHpBarLive_Loop(struct ProcEfxHpBar *proc);
void NewEfxNoDamage(struct BaSprite *anim1, struct BaSprite *anim2, int death);
void EfxNoDmage_Loop(struct ProcEfxHpBar *proc);
void NewEfxNoDamageYure(struct BaSprite *anim1, struct BaSprite *anim2);
void EfxNoDamageYure_Loop(struct ProcEfxHpBar *proc);
void NewEfxStatusCHG(struct BaSprite *anim);
void EfxStatusCHG_Loop(struct ProcEfxHpBar *proc);

struct ProcEfxDead {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);
    /* 2C */ i16 timer, terminator;
    STRUCT_PAD(0x30, 0x5C);
    /* 5C */ struct BaSprite *anim1, *anim2;
    /* 64 */ ProcPtr subproc;
};

void NewEfxDeadEvent(struct BaSprite *anim1, struct BaSprite *anim2);
void EfxDeathEvent_Init(struct ProcEfxDead *proc);
void EfxDeathEvent_RemoveUI(struct ProcEfxDead *proc);
void EfxDeathEvent_CallEvent(struct ProcEfxDead *proc);
void EfxDeathEvent_WaitEvent(struct ProcEfxDead *proc);
void EfxDeathEvent_End(struct ProcEfxDead *proc);
void NewEfxDead(struct BaSprite *anim1, struct BaSprite *anim2);
void EfxDead_StartPika(struct ProcEfxDead *proc);
void EfxDead_StartAlpha(struct ProcEfxDead *proc);
void NewEfxDeadPika(struct BaSprite *anim1, struct BaSprite *anim2);
void EfxDeadPika_Loop(struct ProcEfxDead *proc);
void NewEfxDeadAlpha(struct BaSprite *anim1, struct BaSprite *anim2);
void EfxDeadAlpha_Loop(struct ProcEfxDead *proc);
void NewEfxDeadDragonAlpha(struct BaSprite *anim1, struct BaSprite *anim2);
void EfxDeadDragonAlpha_Loop(struct ProcEfxDead *proc);

struct ProcEfxFarAttack
{
    /* 00 */ PROC_HEADER;
    /* 29 */ u8 pos;
    /* 2A */ u16 unk_2a;
    /* 2C */ i16 timer;
    /* 2E */ i16 unk_2e;
    /* 30 */ i16 terminator;
    /* 32 */ i16 unk_32;
    /* 34 */ i16 unk_34;
    /* 36 */ i16 unk_36;
    /* 38 */ i16 unk_38;
};

void NewEfxFarAttackWithDistance(struct Anim *anim, i16);
void func_fe6_08045D6C(struct ProcEfxFarAttack * unused, int x);
void func_fe6_08045DA4(struct ProcEfxFarAttack *proc);
void func_fe6_08045DDC(struct ProcEfxFarAttack *proc);
void func_fe6_08045E50(struct ProcEfxFarAttack *proc);
void BanimSetBg2Position(int);

struct ProcEfxQuake {
    /* 00 */ PROC_HEADER;

    /* 29 */ u8 quake_ui;
    /* 2A */ u8 kind;
    /* 2C */ i16 timer;
    /* 30 */ int unk_30;
    /* 34 */ i16 ix;
    /* 36 */ i16 unk_36;
    /* 38 */ i16 unk_38;
    /* 3A */ i16 unk_3a;
    /* 3C */ i16 iy;
    /* 3E */ i16 unk_3e;
    /* 40 */ int unk_40;
    /* 44 */ const i16 * vec;
    /* 48 */ int unk_48;
    STRUCT_PAD(0x4C, 0x5C);
    /* 5C */ struct Anim *anim_l;
    /* 60 */ struct Anim *anim_r;
    /* 64 */ struct Anim *unk_64;
};

#define SetEkrBg2QuakeVec(_x, _y) \
    gEkrBg2QuakeVec.x = (_x);     \
    gEkrBg2QuakeVec.y = (_y);

ProcPtr NewEfxQuakePure(int type, int stopped);
void EfxQuakePure_Loop(struct ProcEfxQuake *proc);
ProcPtr NewEfxHitQuakePure(void);
void EfxHitQuakePure_Loop(struct ProcEfxQuake *proc);
ProcPtr NewEfxQuake(int type);
void EfxQuake_Loop(struct ProcEfxQuake *proc);
void NewEfxHitQuake(struct Anim *anim1, struct Anim *anim2, int kind);
void EfxHitQuake_Loop(struct ProcEfxQuake *proc);

struct ProcEfxFlashing {
    PROC_HEADER;

    /* 29 */ u8 flag;

    STRUCT_PAD(0x2A, 0x2C);

    /* 2C */ i16 timer;
    /* 2E */ i16 terminator;
    /* 30 */ i16 terminator2;

    STRUCT_PAD(0x32, 0x5C);

    /* 5C */ struct Anim *anim;
};

void NewEfxFlashBgWhite(struct Anim *anim, int duartion);
void NewEfxFlashBgRed(struct Anim *anim, int duartion);
void EfxFlashBg_Loop(struct ProcEfxFlashing *proc);
void EfxFlashRestorePalSync(struct ProcEfxFlashing *proc);
void NewEfxWhiteIN(struct Anim *anim, int duartion, int duartion2);
void EfxWhiteIn_Loop1(struct ProcEfxFlashing *proc);
void EfxWhiteIn_Loop2(struct ProcEfxFlashing *proc);
void EfxBlackInRestorePalSync(struct ProcEfxFlashing *proc);

void NewEfxFlashHpBar(struct Anim *anim, int duartion, int duartion2);
void EfxFlashHpBar_Pause(struct ProcEfxFlashing *proc);
void EfxFlashHpBar_Loop(struct ProcEfxFlashing *proc);
void EfxFlashHpBar_RestorePal(struct ProcEfxFlashing *proc);

struct ProcEfxHpBarColorChange {
    PROC_HEADER;

    STRUCT_PAD(0x2A, 0x2C);

    /* 2C */ i16 timer;

    STRUCT_PAD(0x2E, 0x44);

    /* 44 */ u32 frame;
    /* 48 */ const u16 * frame_conf;
    /* 4C */ u32 frame_state;
    /* 50 */ int disabled;

    STRUCT_PAD(0x54, 0x5C);

    /* 5C */ struct Anim *anim;
};

extern struct ProcEfxHpBarColorChange * gpProcEfxHpBarColorChange;

void NewEfxHpBarColorChange(struct Anim *anim);
void EndEfxHPBarColorChange(void);
void DisableEfxHpBarColorChange(void);
void EnableEfxHpBarColorChange(void);
void EfxHpBarColorChange_Loop(struct ProcEfxHpBarColorChange *proc);

void NewEfxFlashUnit(struct Anim *anim, u16 dura1, u16 dura2, int c);
void EfxFlashUnit_Loop(struct ProcEfxFlashing *proc);
void EfxFlashUnit_RestorePal(struct ProcEfxFlashing *proc);

struct ProcEfxStatusUnit {
    PROC_HEADER;
    /* 29 */ u8 invalid;

    STRUCT_PAD(0x2A, 0x2C);

    /* 2C */ u16 timer;

    STRUCT_PAD(0x2E, 0x32);

    /* 32 */ i16 red, green, blue;

    STRUCT_PAD(0x38, 0x44);

    /* 44 */ u32 frame;
    /* 48 */ const u16 * frame_lut;
    /* 4C */ int debuff, debuf_bak;

    STRUCT_PAD(0x54, 0x5C);

    /* 5C */ struct Anim *anim;
};

extern struct ProcEfxStatusUnit * gpProcEfxStatusUnits[2];

void NewEfxStatusUnit(struct Anim *anim);
void EndEfxStatusUnits(struct Anim *anim);
void DisableEfxStatusUnits(struct Anim *anim);
void EnableEfxStatusUnits(struct Anim *anim);
void SetUnitEfxDebuff(struct Anim *anim, int debuff);
u32 GetUnitEfxDebuff(struct Anim *anim);
void EfxStatusUnitFlashing(struct Anim *anim, int r, int g, int b);
void EfxStatusUnit_Loop(struct ProcEfxStatusUnit *proc);
void EfxStatusUnit_End(struct ProcEfxStatusUnit *proc);

struct ProcEfxWeaponIcon {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ i16 timer;

    STRUCT_PAD(0x2E, 0x44);

    /* 44 */ u32 frame;
    /* 48 */ const u16 * frame_lut;
    /* 4C */ u32 frame_state;
    /* 50 */ u32 invalid;
    /* 54 */ int eff1, eff2;
};

extern struct ProcEfxWeaponIcon * gpProcEfxWeaponIcon;

void NewEfxWeaponIcon(i16 eff1, i16 eff2);
void EndProcEfxWeaponIcon(void);
void DisableEfxWeaponIcon(void);
void EnableEfxWeaponIcon(void);
void EfxWeaponIcon_Loop(struct ProcEfxWeaponIcon *proc);
void EfxWeaponIcon_End(struct ProcEfxWeaponIcon *proc);

struct ProcEfxSpellCast {
    PROC_HEADER;

    /* 29 */ u8 done;

    STRUCT_PAD(0x2A, 0x2C);

    /* 2C */ i16 timer;
    /* 2E */ i16 terminator;
};

extern struct ProcEfxSpellCast * gpProcEfxSpellCast;

void NewEfxSpellCast(void);
void UnsyncEkrDispUP(void);
void EndEfxSpellCastAsync(void);
void EndEfxSpellCastSync(void);
void EfxSpellCast_FlashIN(struct ProcEfxSpellCast *proc);
void EfxSpellCast_Pause(struct ProcEfxSpellCast *proc);
void EfxSpellCast_FlashOUT(struct ProcEfxSpellCast *proc);

void SpellFx_Begin(void);
void SpellFx_Finish(void);
void SpellFx_ClearBG1Position(void);
void SpellFx_ClearBG1(void);
void SpellFx_SetSomeColorEffect(void);
void SpellFx_ClearColorEffects(void);
void StartBattleAnimHitEffectsDefault(struct Anim *anim, int type);
void func_fe6_08047610(struct Anim *anim, int type);
void StartBattleAnimHitEffects(struct Anim *anim, int type, int quake_normal, int quake_crit);
void StartBattleAnimResireHitEffects(struct Anim *anim, int type);
void StartBattleAnimStatusChgHitEffects(struct Anim *anim, int type);
struct Anim * EfxCreateFrontAnim(struct Anim *anim, const AnimScr * scr1, const AnimScr * scr2, const AnimScr * scr3, const AnimScr * scr4);
void SpellFx_WriteBgMapUncomp(struct Anim *anim, const u16 * src1, const u16 * src2);
void SpellFx_WriteBgMap(struct Anim *anim, const u16 * src1, const u16 * src2);
void SpellFx_WriteBgMapExt(struct Anim *anim, const u16 * src, int width, int height);
void SpellFx_RegisterObjGfx(const void * img, u32 size);
void SpellFx_RegisterObjPal(const u16 * pal, u32 size);
void SpellFx_RegisterBgGfx(const void * img, u32 size);
void SpellFx_RegisterBgPal(const u16 * pal, u32 size);
void func_fe6_08047B10(const u16 * src, u16 * dst, u32 cur, u32 len_src, u32 len_dst);
void func_fe6_08047B3C(const u16 * src, u16 * dst, u32 cur, u32 len_src, u32 len_dst);
void func_fe6_08047B6C(const u16 * src, u16 * dst, u32 a, u32 b, u32 c);
i16 EfxAdvanceFrameLut(i16 * ptime, i16 * pcount, const i16 lut[]);
void PutEfxTerrainToLowerLayer(void);
int EfxGetCamMovDuration(void);
void EfxTmFillA(u32 val);
void EfxTmFillB(u32 val);
void SetEkrFrontAnimPostion(int pos, i16 x, i16 y);
bool SetupBanim(void);
void BeginAnimsOnBattleAnimations(void);
void EkrMainEndExec(void);
void OnMainBas(void);

struct ProcEkrBattleIntro {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ i16 timer, terminator;

    STRUCT_PAD(0x30, 0x32);

    /* 32 */ i16 x1, x2;

    STRUCT_PAD(0x36, 0x3A);

    /* 3A */ i16 y1, y2;
};

#define ProcEkrBattleStarting ProcEkrBattleIntro
#define ProcEkrBattleEnding   ProcEkrBattleIntro

void NewEkrBattleStarting(void);
void EkrBaStart_InitScreen(struct ProcEkrBattleStarting *proc);
void EkrBaStart_SreenFailIn(struct ProcEkrBattleStarting *proc);
void EkrBaStart_InitBattleScreen(struct ProcEkrBattleStarting *proc);
void EkrBaStart_ExecEkrBattle(struct ProcEkrBattleStarting *proc);
void EkrBaStart_BgFadeOut(struct ProcEkrBattleStarting *proc);
void EkrBaStart_MergeBG(struct ProcEkrBattleStarting *proc);
void func_fe6_08048154(struct ProcEkrBattleStarting *proc);

void NewEkrbattleending(void);
void func_fe6_080481CC(struct ProcEkrBattleEnding *proc);
void func_fe6_08048244(struct ProcEkrBattleEnding *proc);
void func_fe6_08048298(struct ProcEkrBattleEnding *proc);
void func_fe6_080482F4(struct ProcEkrBattleEnding *proc);
void func_fe6_08048354(struct ProcEkrBattleEnding *proc);
void func_fe6_080483E0(struct ProcEkrBattleEnding *proc);
void func_fe6_08048470(struct ProcEkrBattleEnding *proc);
void func_fe6_0804855C(struct ProcEkrBattleEnding *proc);

void NewEkrBaseKaiten(int identifier);
// func_fe6_0804894C
void NewEkrUnitKakudai(int identifier);
// func_fe6_08048A64
// func_fe6_08048BF0
// func_fe6_08048D98

struct ProcEkrIntroWindow {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ i16 timer, terminator, ymax;

    STRUCT_PAD(0x32, 0x44);

    /* 44 */ int type;
    /* 48 */ int ymax_name;
};

void NewEkrWindowAppear(int identifier, int duration);
bool CheckEkrWindowAppearUnexist(void);
// func_fe6_08048E08
void NewEkrNamewinAppear(int identifier, int duration, int delay);
bool CheckEkrNamewinAppearUnexist(void);
// func_fe6_08048EEC
// func_fe6_08048F0C
void NewEkrBaseAppear(int identifier, int duration);
bool CheckEkrBaseAppearUnexist(void);
// EkrBaseAppear_Loop
bool _SetupBanim(void);
u16 GetBattleAnimationId(const struct BanimInfoEnt *animdef, u16 item);
int GetBanimTerrainGround(u16 terrain, u16 tileset);
int GetBanimBackgroundIndex(u16 terrain, u16 tileset);
i16 GetSpellAnimId(u16 jid, u16 weapon);
void UnsetMapStaffAnim(i16 * out, u16 pos, u16 weapon);
void ParseBattleHitToBanimCmd(void);
bool CheckBattleHasHit(void);
int GetBanimUniquePal(struct Unit * unit);
const u16 * GetBanimTriangleAttackPalette(i16 bid, u16 item);

enum banim_faction_palette_idx {
    BANIMPAL_BLUE = 0,
    BANIMPAL_RED = 1,
    BANIMPAL_GREEN = 2,
    BANIMPAL_PURPLE = 3,
};

int GetBanimFactionPalette(u32 faction);

void EkrPrepareBanimfx(struct Anim *anim, i16);

enum anim_round_type {
    ANIM_ROUND_BIT8 = 0x0100,
    ANIM_ROUND_PIERCE = 0x0200,
    ANIM_ROUND_GREAT_SHIELD = 0x0400,
    ANIM_ROUND_SURE_SHOT = 0x0800,
    ANIM_ROUND_SILENCER = 0x1000,
    ANIM_ROUND_POISON = 0x2000,
    ANIM_ROUND_BIT14 = 0x4000,
    ANIM_ROUND_DEVIL = 0x8000,
};

i16 GetBattleAnimRoundType(int index);
i16 func_fe6_0804A57C(int);

#define GetRoundFlagByAnim(aAnim) (func_fe6_0804A57C((aAnim->nextRoundId - 1) * 2 + GetAnimPosition(aAnim)))

i16 GetEfxHp(int index);
// func_fe6_0804A5C0
void BattleAIS_ExecCommands(void);
void NewEkrChienCHR(struct Anim *anim);
void EkrChienCHR_Loop(struct ProcEfx *proc);
void SyncBanimImage(struct Anim *anim);
void ApplyBanimUniquePalette(u32 *buf, int pos);
int GetBanimPalette(int banim_id, int pos);
void UpdateBanimFrame(void);
void InitMainAnims(void);
void InitBattleAnimFrame(int round_type_left, int round_type_right);
void InitLeftAnim(int round_type);
void InitRightAnim(int round_type);
void LoadAnimFrame(struct Anim *anim, int type);
int GetAnimLayer(struct Anim *anim);
int GetAnimPosition(struct Anim *anim);
int CheckRoundMiss(i16 type);
int CheckRound1(i16 type);
int CheckRound2(i16 type);
int CheckRoundCrit(struct Anim *anim);
struct Anim * GetAnimAnotherSide(struct Anim *anim);
i16 GetAnimRoundType(struct Anim *anim);
i16 GetAnimNextRoundType(struct Anim *anim);
i16 GetAnimRoundTypeAnotherSide(struct Anim *anim);
i16 GetAnimNextRoundTypeAnotherSide(struct Anim *anim);
void SetAnimStateHidden(int pos);
void SetAnimStateUnHidden(int pos);

/**
 * ekrmainmini
 */
struct EkrMainMiniBuf {
    /* 00 */ u8 valid;
    /* 01 */ u8 faction_pal;
    /* 02 */ u16 x, y;
    /* 06 */ u16 bid;

    // i16 chara_pal;

    /* 08 */ u16 round_type;
    /* 0A */ u16 pos;
    /* 0C */ u16 oam2_chr;
    /* 0E */ u16 oam2_pal;
    /* 10 */ struct Anim *anim1, *anim2;
    /* 18 */ u16 *img_buf;
    /* 1C */ u16 *pal_buf;
    /* 20 */ u16 *oam_buf;
    /* 24 */ u8  *scr_buf;
    /* 28 */ const u16 *img_sheet;
    /* 2C */ void *magicfx_buf;
    /* 30 */ ProcPtr proc;
};

void EkrMainMini_ExecCommands(struct EkrMainMiniBuf *buf, struct Anim *anim);
void EkrMainMini_C01_Blocking(struct Anim *anim);
void EkrMainMini_C0D_ExecNextRoundAfterAttack(struct Anim *anim);
void EkrMainMini_InitAnim(struct EkrMainMiniBuf *buf);
void EkrMainMini_UpdateAnim(struct EkrMainMiniBuf *buf);
void EkrMainMini_ChangeAnim(struct EkrMainMiniBuf *buf, int bid);
void EkrMainMini_SetAnimPosition(struct EkrMainMiniBuf *buf, u16 x, u16 y);
void EkrMainMini_SetAnimLayer(struct EkrMainMiniBuf *buf, u16 layer);
bool EkrMainMini_CheckBlocking(struct EkrMainMiniBuf *buf);
void EkrMainMini_EndBlock(struct EkrMainMiniBuf *buf);
bool EkrMainMini_CheckDone(struct EkrMainMiniBuf *buf);
void NewEfxAnimeDrvProc(void);
void EndEfxAnimeDrvProc(void);
void EkrAnimeDrv_Loop(void);

struct ProcEkrUnitMainMini {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x5C);

    struct EkrMainMiniBuf *buf;
};

void NewEkrUnitMainMini(struct EkrMainMiniBuf *buf);
void EndEkrMainMini(struct EkrMainMiniBuf *buf);
void EkrMainMini_Loop(struct ProcEkrUnitMainMini *proc);

/**
 * EkrTerrainfx
 */
struct EkrTerrainfxDesc {
    /* 00 */ i16 terrain_l;
    /* 02 */ i16 pal_l;
    /* 04 */ i16 chr_l;
    /* 06 */ i16 terrain_r;
    /* 0A */ i16 pal_r;
    /* 08 */ i16 chr_r;
    /* 0C */ i16 distance;
    /* 0E */ i16 bg_index;

    /* 10 */ u16 _pad_10;

    /* 14 */ struct ProcEkrSubAnimeEmulator *proc1;
    /* 18 */ struct ProcEkrSubAnimeEmulator *proc2;
    /* 1C */ int vram_offset;
    /* 20 */ u8 *img_buf;

    /* 24 */ int _pad_24;
};

extern struct EkrTerrainfxDesc gEkrTerrainfxDesc, gEkrLvupTerrainfxDesc;

void NewEkrTerrainfx(struct EkrTerrainfxDesc *desc); // FE8: sub_805AA68
void EndEkrTerrainfx(struct EkrTerrainfxDesc *desc);
void EkrTerrainfx_SetPosition(struct EkrTerrainfxDesc *desc, i16 x1, i16 y1, i16 x2, i16 y2);
void EkrTerrainfx_PutTiles(struct EkrTerrainfxDesc *desc);
void BanimCopyBgTM(i16 distance, i16 pos);

/**
 * EkrArena
 */
void SetBanimArenaFlag(int flag);
int GetBattleAnimArenaFlag(void);
void EkrArena_ChangeBg3Offset(int x);
void PlayDeathSoundForArena(void);
void StopArenaBgmWhenSpeedUp(void);
void BeginAnimsOnBattle_Arena(void);
void ExecBattleAnimArenaExit(void);
void NewEkrTogiInitPROC(void);
void EkrTogiInit_Init(struct ProcEfxBG *proc);
void EkrTogiInit_LoadGfx(struct ProcEfxBG *proc);
void EkrTogiInit_Loop(struct ProcEfxBG *proc);
void EkrTogiInit_End(struct ProcEfxBG *proc);
void NewEkrTogiEndPROC(void);
void EkrTogiEnd_Init(struct ProcEfxBG *proc);
void EkrTogiEnd_Loop(struct ProcEfxBG *proc);
void EkrTogiEnd_End(struct ProcEfxBG *proc);

struct ProcEkrTogiColor {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ s16 timer;

    STRUCT_PAD(0x2E, 0x44);

    /* 44 */ u32 frame;
    /* 48 */ const u16 * frame_config;
    /* 4C */ const u16 **pal;
};

void NewEkrTogiColor(void);
void EndEkrTogiColor(void);
void EkrTogiColor_Loop(struct ProcEkrTogiColor *proc);

/* efxmagic */
void StartSpellAnimation(struct Anim *anim);
void func_fe6_0804C8D0(void);
ProcPtr NewefxRestRST(struct Anim *anim, int unk44, int unk48, int frame, int unk50);
void EfxRestRST_End(struct ProcEfx *proc);
void EfxRestRST_Loop(struct ProcEfx *proc);
void NewDummvRST(struct Anim *anim, int unk44);
void EfxDummyRST_End(struct ProcEfx *proc);
void EfxDummyRST_Loop(struct ProcEfx *proc);
void NewEfxRestWIN(struct Anim *anim, int unk44, void * unk54, void * unk58);
void EfxRestWIN_Loop(struct ProcEfx *proc);
void NewEfxRestWINH(struct Anim *anim, int a, i16 b, void (* hblank)(void));
void NewEfxRestWINH_(struct Anim *anim, int a, void (* hblank)(void));
void EfxRestWINH_Dummy(struct ProcEfx *proc);
void EfxRestWINH_Loop(struct ProcEfx *proc);
void EfxRestWINH_DefaultHblank(void);

struct ProcEfxALPHA
{
    PROC_HEADER;

    /* 29 */ u8 unk29;

    STRUCT_PAD(0x2A, 0x2C);

    /* 2C */ i16 timer;
    /* 2E */ i16 delay;
    /* 30 */ i16 duration_total;

    STRUCT_PAD(0x32, 0x44);

    /* 44 */ int lo, hi, type;

    STRUCT_PAD(0x50, 0x5C);

    /* 5C */ struct Anim *anim;
};

void NewEfxALPHA(struct Anim *anim, int delay, int duration2, int lo, int hi, int type);
void EfxALPHA_Loop(struct ProcEfxALPHA *proc);

struct ProcEfxCircleWIN
{
    PROC_HEADER;
    STRUCT_PAD(0x29, 0x2c);

    /* 2C */ i16 timer;
    /* 2E */ i16 unk_2e;
    /* 30 */ i16 unk_30;
    /* 32 */ i16 unk_32;

    STRUCT_PAD(0x34, 0x3a);

    /* 3A */ u16 unk_3a;

    STRUCT_PAD(0x3c, 0x44);

    /* 44 */ int unk_44;

    STRUCT_PAD(0x48, 0x54);

    /* 54 */ u16 * unk_54;
    /* 58 */ int unk_58;
    /* 5C */ struct Anim *anim;
};

void NewEfxCircleWIN(struct Anim *anim, int terminator, u16 * c, u16 d, u16 e);
void EfxCircleWIN_Loop(struct ProcEfxCircleWIN *proc);

struct ProcEfxMagicQuake
{
    PROC_HEADER;
    STRUCT_PAD(0x29, 0x2c);

    /* 2C */ i16 timer, duration;

    STRUCT_PAD(0x30, 0x5c);

    /* 5C */ struct Anim *anim;
    /* 60 */ ProcPtr qproc;
};

void NewEfxMagicQUAKE(struct Anim *anim, int duration);
void EfxMagicQUAKE_Loop(struct ProcEfxMagicQuake *proc);

struct ProcEfxMagic {
    PROC_HEADER;

    /* 29 */ u8 hitted;
    /* 2A */ u8 type;
    /* 2B */ STRUCT_PAD(0x2B, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 step;
    /* 30 */ i16 unk30;
    /* 32 */ u16 unk32;
    /* 34 */ STRUCT_PAD(0x34, 0x44);
    /* 44 */ u32 unk44;
    /* 48 */ u32 unk48;
    /* 4C */ u32 frame;
    /* 50 */ u32 speed;
    /* 54 */ i16 * unk54;
    /* 58 */ i16 ** unk58;
    /* 5C */ struct Anim *anim;
    STRUCT_PAD(0x60, 0x64);
    ProcPtr unk_64;
};

struct ProcEfxMagicOBJ {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ i16 timer, terminator;

    STRUCT_PAD(0x30, 0x5C);

    /* 5C */ struct Anim *anim;
    /* 60 */ struct Anim *anim2;

    /* 64 */ ProcPtr seproc;
};

struct ProcEfxEclipseBG
{
    PROC_HEADER;

    /* 29 */ u8 unk29;

    STRUCT_PAD(0x2A, 0x2C);

    /* 2C */ i16 timer;
    /* 2E */ i16 terminator;
    /* 30 */ i16 unk30;

    STRUCT_PAD(0x32, 0x44);

    /* 44 */ u32 frame;
    /* 48 */ const u16 * frame_config;
    /* 4C */ u16 ** tsal;
    /* 50 */ u16 ** tsar;
    /* 54 */ u16 ** img;
    /* 58 */ u16 * pal;
    /* 5C */ struct Anim *anim;
};

void NewEfxDummyMagic(struct Anim *anim);
void EfxDummyMagic_Loop(struct ProcEfxMagic *proc);
void NewEfxTeono(struct Anim *anim);
void EfxTeono_Loop(struct ProcEfxMagic *proc);
void NewEfxTeonoOBJ(struct Anim *anim);
void EfxTeonoObj_Loop(struct ProcEfxMagicOBJ *proc);
void EfxTeonoObj_End(struct ProcEfxMagicOBJ *proc);
void NewEfxTeonoOBJ2(struct Anim *anim);
void EfxTeonoOBJ2_Loop(struct ProcEfxMagicOBJ *proc);
ProcPtr NewEfxTeonoSE(struct Anim *anim, struct Anim *anim2);
void EfxTeonoSE_End(struct ProcEfxMagicOBJ *proc);
void EfxTeonoSE_Loop(struct ProcEfxMagicOBJ *proc);
void NewEfxArrow(struct Anim *anim);
void EfxArrow_Loop(struct ProcEfx *proc);
void NewEfxArrowOBJ(struct Anim *anim);
void EfxArrowObj_Loop(struct ProcEfxMagicOBJ *proc);
void StartSpellAnimJavelin(struct Anim *anim);
void StartSpellAnimJavelinCavalier(struct Anim *anim);
void StartSpellAnimJavelinSoldier(struct Anim *anim);
void StartSpellAnimJavelinPaladin(struct Anim *anim);
void StartSpellAnimJavelinPrgasusKnight(struct Anim *anim);
void StartSpellAnimJavelinFalcon(struct Anim *anim);
void StartSpellAnimJavelinWyvernRider(struct Anim *anim);
void StartSpellAnimJavelinWyvernLord(struct Anim *anim);
void StartSpellAnimJavelinGenerial(struct Anim *anim);
void EfxTeyari_Loop(struct ProcEfx *proc);
void NewEfxTeyariOBJ(struct Anim *anim, int type);
void EfxTeyariObj_Loop(struct ProcEfxMagicOBJ *proc);
void StartSpellAnimSong(struct Anim *anim);
void EfxSong_Loop(struct ProcEfx *proc);
void NewEfxSongBG(struct Anim *anim);
void EfxSongBG_Loop(struct ProcEfxBG *proc);
void NewEfxSongBGCOL(struct Anim *anim);
void EfxSongBGCOL_Loop(struct ProcEfxBGCOL *proc);
void StartSpellAnimDance(struct Anim *anim);
void EfxDance_Loop(struct ProcEfx *proc);
void StartSpellAnimBallista(struct Anim *anim);
void EfxShooter_Loop(struct ProcEfx *proc);
void NewEfxShooterOBJ(struct Anim *anim);
void EfxShooterOBJ_Loop(struct ProcEfxOBJ *proc);
void StartSpellAnimEckesachs(struct Anim *anim);
void EfxEckesachs_Loop(struct ProcEfx *proc);
void NewEfxEckesachsBG(struct Anim *anim, int duration);
void EfxEckesachsBG_Loop(struct ProcEfxBG *proc);
void Pal_EfxEckesachsBGCtrl(struct Anim *anim, int duration);
void EfxEckesachsBGCtrl_Loop(struct ProcEfxBG *proc);
void NewEfxEckesachsBGCOL(struct Anim *anim);
void EfxEckesachsBGCOL_Loop(struct ProcEfxBGCOL *proc);
void StartSpellAnimBindingBlade(struct Anim *anim);
void EfxHurtmut_Loop(struct ProcEfx *proc);
void NewEfxHurtmutOBJ(struct Anim *anim);
void EfxHurtmutOBJ_Loop(struct ProcEfxOBJ *proc);
void StartSpellAnimFireBreath(struct Anim *anim);
void EfxFirebreath_Loop(struct ProcEfx *proc);
void NewEfxFirebreathOBJ(struct Anim *anim);
void EfxFirebreathOBJ_Loop(struct ProcEfxOBJ *proc);
void NewEfxFirebreathBG(struct Anim *anim);
void EfxFirebreathBG_Loop(struct ProcEfxBG *proc);
void NewEfxFirebreathBGCOL(struct Anim *anim);
void EfxFirebreathBGCOL_Loop(struct ProcEfxBGCOL *proc);
void StartSpellAnimIceBreath(struct Anim *anim);
void EfxIcebreath_Loop(struct ProcEfx *proc);
void NewEfxIcebreathOBJ(struct Anim *anim);
void EfxIcebreathOBJ_OnEnd(struct ProcEfxOBJ *proc);
void StartSpellAnimDarkBreath(struct Anim *anim);
void EfxDarkbreath_Loop(struct ProcEfx *proc);
void NewEfxDarkbreathBG(struct Anim *anim);
void EfxDarkbreathBG_Loop(struct ProcEfxBG *proc);
void NewEfxDarkbreathBGCOL(struct Anim *anim);
void EfxDarkbreathBGCOL_Loop(struct ProcEfxBGCOL *proc);
void NewEfxDarkbreathOBJ(struct Anim *anim);
void EfxDarkbreathOBJ_Loop(struct ProcEfxOBJ *proc);
void StartSpellAnimThunder(struct Anim *anim);
void EfxThunder_Loop(struct ProcEfx *proc);
void NewEfxThunderBG(struct Anim *anim);
void EfxThunderBG_Loop(struct ProcEfxBG *proc);
void NewEfxThunderBGCOL(struct Anim *anim);
void EfxThunderBGCOL_Loop(struct ProcEfxBGCOL *proc);
void NewEfxThunderOBJ(struct Anim *anim);
void EfxThunderOBJ_Loop(struct ProcEfxOBJ *proc);
void StartSpellAnimFire(struct Anim *anim);
void StartSpellAnimElfire(struct Anim *anim);
void EfxFire_Loop(struct ProcEfx *proc);
void NewEfxFireBG(struct Anim *anim);
void EfxFireBG_Loop(struct ProcEfxBG *proc);
void NewEfxFireOBJ(struct Anim *anim);
void EfxFireOBJ_Loop(struct ProcEfxOBJ *proc);
void NewEfxFireHITBG(struct Anim *anim);
void EfxFireHITBG_Loop(struct ProcEfxBG *proc);
void NewEfxElfireBG(struct Anim *anim);
void EfxElfireBG_Loop(struct ProcEfxBG *proc);
void NewEfxElfireBGCOL(struct Anim *anim);
void EfxElfireBGCOL_Loop(struct ProcEfxBGCOL *proc);
void NewEfxElfireOBJ(struct Anim *anim);
void EfxElfireOBJ_Loop(struct ProcEfxOBJ *proc);
void StartSpellAnimFimbulvetr(struct Anim *anim);
void EfxFimbulvetr_Loop(struct ProcEfx *proc);
void NewEfxFimbulvetrBGTR(struct Anim *anim);
void EfxFimbulvetrBGTR_Loop(struct ProcEfxBG *proc);
void NewEfxFimbulvetrBG(struct Anim *anim);
void EfxFimbulvetrBG_Loop(struct ProcEfxBG *proc);
void NewEfxFimbulvetrOBJ(struct Anim *anim);
void EfxFimbulvetrOBJ_Loop(struct ProcEfxOBJ *proc);
void NewEfxFimbulvetrOBJ2(struct Anim *anim);
void EfxFimbulvetrOBJ2_Loop(struct ProcEfxOBJ *proc);
void NewEfxFimbulvetrOBJ2Fall(struct Anim *anim, int kind);
void EfxFimbulvetrOBJ2Fall_Loop(struct ProcEfxOBJ *proc);
void StartSpellAnimBolting(struct Anim *anim);
void EfxThunderstorm_Loop(struct ProcEfx *proc);
void NewEfxThunderstormBG(struct Anim *anim);
void EfxThunderstormBG_Loop(struct ProcEfxBG *proc);
void NewEfxThunderstormOBJ(struct Anim *anim);
void EfxThunderstormOBJ_Loop(struct ProcEfxOBJ *proc);
void EfxThunderstormOBJ_End(struct ProcEfxOBJ *proc);
void NewEfxThunderstormCOLOR(struct Anim *anim);
void EfxThunderstormCOLOR_LoopA(struct ProcEfxBGCOL *proc);
void EfxThunderstormCOLOR_LoopB(struct ProcEfxBGCOL *proc);
void EfxThunderstormCOLOR_LoopC(struct ProcEfxBGCOL *proc);
void NewEfxThunderstormDARK(struct Anim *anim, int timer, int terminator);
void EfxThunderstormDARK_LoopA(struct ProcEfxBGCOL *proc);
void EfxThunderstormDARK_LoopB(struct ProcEfxBGCOL *proc);
void StartSpellAnimAircalibur(struct Anim *anim);
void NewEfxAlacaliburBG(struct Anim *anim);
void NewEfxAlacaliburBG(struct Anim *anim);
void EfxAlacaliburBG_Loop(struct ProcEfxBG *proc);
void NewEfxAlacaliburBGCOL(struct Anim *anim);
void EfxAlacaliburBGCOL_Loop(struct ProcEfxBGCOL *proc);
void NewEfxAlacaliburOBJ(struct Anim *anim);
void EfxAlacaliburOBJ_Loop(struct ProcEfxOBJ *proc);
void StartSpellAnimFlux(struct Anim *anim);
void EfxMistyrain_Loop(struct ProcEfx *proc);
void NewEfxMistyrainBG1(struct Anim *anim);
void NewEfxMistyrainBG2(struct Anim *anim);
void NewEfxMistyrainBG_Loop(struct ProcEfxBG *proc);
void NewEfxMistyrainOBJ(struct Anim *anim);
struct ProcEfxOBJ * NewEfxMistyrainOBJ2(struct Anim *anim);
void EfxMistyrainOBJ_OnEnd(struct ProcEfxOBJ *proc);
void EfxMistyrainOBJ1_Loop1(struct ProcEfxOBJ *proc);
void EfxMistyrainOBJ1_Loop2(struct ProcEfxOBJ *proc);
void EfxMistyrainOBJ1_Loop3(struct ProcEfxOBJ *proc);
void EfxMistyrainOBJ2_Loop1(struct ProcEfxOBJ *proc);
void EfxMistyrainOBJ2_Loop2(struct ProcEfxOBJ *proc);
void StartSpellAnimNosferatu(struct Anim *anim);
// EfxResire_Loop
void NewEfxResireBG(struct Anim *anim);
void NewEfxResireBG2(struct Anim *anim);
// EfxResireBG_Loop1
// EfxResireBG_Loop2
// EfxResireBG_Loop3
// EfxResireBG_Loop4
// EfxResireBG2_Loop
void NewEfxResireRST(struct Anim *anim);
// EfxResireRST_Loop
void StartSpellAnimLightning(struct Anim *anim);
// EfxLightning_Loop
void NewEfxLightningBG(struct Anim *anim);
// EfxLightningBG_Loop
void StartSpellAnimPurge(struct Anim *anim);
// EfxPurge_PlaySFX
// EfxPurge_Loop
void NewEfxPurgeBG(struct Anim *anim);
// EfxPurgeBG_Loop
void NewEfxPurgeOBJRND(struct Anim *anim);
// EfxPurgeOBJRND_Loop
void NewEfxPurgeOBJ(struct Anim *anim);
// EfxPurgeOBJ_OnEnd
void StartSpellAnimForblaze(struct Anim *anim);
// EfxForblaze_Loop
void NewEfxForblazeBG1(struct Anim *anim);
// EfxForblazeBG1_Loop
void NewEfxForblazeBGCOL1(struct Anim *anim);
// EfxForblazeBGCOL1_Loop
void NewEfxForblazeBGCtrl1(struct Anim *anim);
// EfxForblazeBGCtrl1_Loop1
// EfxForblazeBGCtrl1_Loop2
// EfxForblazeBGCtrl1_Loop3
void NewEfxForblazeOBJ(struct Anim *anim);
// EfxForblazeOBJ_Loop
void NewEfxForblazeOBJ2(struct Anim *anim);
// EfxForblazeOBJ2_Loop
void NewEfxForblazeBG2(struct Anim *anim);
// EfxForblazeBG2_Loop
void NewEfxForblazeOBJCtrl(struct Anim *anim);
// EfxForblazeOBJCtrl_Loop
void NewEfxForblazeOBJFall(struct Anim *anim);
// EfxForblazeOBJFall_Loop
void HBlank_EfxForblaze(void);
void NewEfxForblazeRST(struct Anim *anim);
// EfxForblazeRST_Loop
void StartSpellAnimDivine(struct Anim *anim);
// EfxDivine_Loop
void NewEfxDivineBG(struct Anim *anim);
void NewEfxDivineBG2(struct Anim *anim);
void NewEfxDivineBG3(struct Anim *anim);
// EfxDivineBG_Loop
void NewEfxDivineOBJ(struct Anim *anim);
// EfxDivineOBJ_Loop
void StartSpellAnimAureola(struct Anim *anim);
// EfxAureola_Loop
// NewEfxAureolaBG
// EfxAureolaBG_Loop
// NewEfxAureolaBG2
// EfxAureolaBG2_Loop
// NewEfxAureolaBG2COL
// EfxAureolaBG2COL_Loop
// NewEfxAureolaOBJ
// EfxAureolaOBJ_Loop
// NewEfxAureolaOBJCtrl
// EfxAureolaOBJCtrl_Loop
// NewEfxAureolaOBJ2
// EfxAureolaOBJ2_Loop
// NewEfxAureolaOBJ3
// EfxAureolaOBJ3_Loop
// NewEfxAureolaOBJ3Ctrl
// EfxAureolaOBJ3Ctrl_Loop
// StartSpellAnimApocalypse
// EfxApocalypse_Loop
// NewEfxApocalypseBG
// EfxApocalypseBG_Loop
// NewEfxApocalypseBGCtrl
// EfxApocalypseBGCtrl_Loop
// NewEfxApocalypseBGCOL
// EfxApocalypseBGCOL_Loop
// NewEfxApocalypseOBJ
// EfxApocalypseOBJ_Loop1
// EfxApocalypseOBJ_Loop2
// EfxApocalypseOBJ_Loop3
// EfxApocalypseOBJ_Loop4
// NewEfxApocalypseBGCOL2
// EfxApocalypseBGCOL2_Loop
// NewEfxApocalypseDummy
// EfxApocalypseDummy_Loop
// NewEfxApocalypseBgFlash1
// EfxApocalypseBgFlash1_Loop
// NewEfxApocalypseBgFlash2
// EfxApocalypseBgFlash2_Loop1
// EfxApocalypseBgFlash2_Loop2
// NewEfxApocalypseBG2
// EfxApocalypseBG2_Loop
// NewEfxApocalypseOBJ2
// EfxApocalypseOBJ2_Loop1
// EfxApocalypseOBJ2_Loop2
// NewEfxApocalypseOBJ3
// EfxApocalypseOBJ3_Loop
// NewEfxApocalypseOBJ3RND
// EfxApocalypseOBJ3RND_Loop
// StartSpellAnimEclipse
// EfxHazymoon_Loop
// NewEfxHazymoonBG1
// NewEfxHazymoonBG2
// NewEfxHazymoonBG3
// EfxHazymoonBG_Loop
// NewEfxHazymoonOBJ2
// EfxHazymoonOBJ2_OnEnd
// EfxHazymoonOBJ2_Loop1
// EfxHazymoonOBJ2_Loop2
// EfxHazymoonOBJ2_Loop3
// NewEfxHazymoonOBJ3
// EfxHazymoonOBJ3_Loop
// NewEfxHazymoonOBJ3RND
// EfxHazymoonOBJ3RND_Loop
// StartSpellAnimFenrir
// EfxFenrir_Loop
// NewEfxFenrirBG
// EfxFenrirBG_OnEnd
// EfxFenrirBG_Loop
// NewEfxFenrirBGCOL
// EfxFenrirBGCOL_OnEnd
// EfxFenrirBGCOL_Loop
// NewEfxFenrirOBJ
// EfxFenrirOBJ_Loop
// NewEfxFenrirBG2_A
// NewEfxFenrirBG2_B
// EfxFenrirBG2_Loop
// NewEfxFenrirOBJ2
// EfxFenrirOBJ2_Loop
// NewEfxFenrirOBJ2Chiri
// EfxFenrirOBJ2Chiri_Loop
// StartSpellAnimHeal
// EfxLive_Loop
// StartSpellAnimMend
// EfxRelive_Loop
// StartSpellAnimRecover
// EfxRecover_Loop
// StartSpellAnimPhysic
// EfxReblow_Loop
// NewEfxLiveBG_A
// NewEfxLiveBG_B
// EfxLiveBG_Loop
// NewEfxLiveBGCOL_A
// NewEfxLiveBGCOL_B
// EfxLiveBGCOL_Loop
// NewEfxLiveALPHA
// EfxLiveALPHA_Delay
// EfxLiveALPHA_Loop
// NewEfxLiveOBJ
// NewEfxReserveOBJ
// EfxLiveOBJ_Loop
// EfxReserveOBJ_Loop1
// EfxReserveOBJ_Loop2
// NewEfxReblowOBJ
// EfxReblowOBJ_Loop1
// EfxReblowOBJ_Loop2
// StartSpellAnimFortify
// StartSpellAnimLatona
// EfxReserve_Loop
// NewEfxReserveBG
// EfxReserveBG_Loop
// NewEfxReserveBGCOL
// EfxReserveBGCOL_Loop
// NewEfxReserveBG2
// EfxReserveBG2_Loop
// NewEfxReserveBGCOL2
// EfxReserveBGCOL2_Loop
// StartSpellAnimRestore
// EfxRest_Loop
// NewEfxRestBG
// EfxRestBG_Loop
// NewEfxRestOBJ
// EfxRestOBJ_Loop
// StartSpellAnimSilence
// EfxSilence_Loop
// NewEfxSilenceBG
// EfxSilenceBG_Loop
// NewEfxSilenceOBJ
// EfxSilenceOBJ_OnEnd
// StartSpellAnimSleep
// EfxSleep_Loop
// NewEfxSleepBG
// EfxSleepBG_Loop
// NewEfxSleepOBJ
// NewEfxSleepOBJ2
// EfxSleepOBJ_OnEnd
// NewEfxSleepSE
// EfxSleepSE_PlaySE
// EfxSleepSE_OnEnd
// StartSpellAnimHammerne
// EfxHammarne_Loop
// NewEfxHammarneBG
// EfxHammarneBG_Loop
// NewEfxHammarneOBJ
// EfxHammarneOBJ_OnEnd
// StartSpellAnimBerserk
// EfxBerserk_Loop
// NewEfxBerserkBG
// EfxBerserkBG_Loop
// NewEfxBerserkCLONE
// EfxBerserkCLONE_Loop
// EfxBerserkCLONE_OnEnd
// NewEfxBerserkOBJ
// EfxBerserkOBJ_OnEnd
// EfxBerserkOBJ_Loop1
// EfxBerserkOBJ_Loop3
// EfxBerserkOBJ_Loop5
// EfxBerserkOBJ_Loop7
// EfxBerserkOBJ_Loop9
// EfxBerserkOBJ_Loop2
// EfxBerserkOBJ_Loop4
// EfxBerserkOBJ_Loop6
// EfxBerserkOBJ_Loop8
// EfxBerserkOBJ_Loop10
// StartSpellAnimBarrier
// EfxMshield_Loop
// NewEfxMshieldBG
// EfxMshieldBG_Loop
// NewEfxMshieldOBJ
// NewEfxMshieldOBJ2
// EfxMshieldOBJ_OnEnd

struct ProcEfxDamageMojiEffectOBJ {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 terminator;
    STRUCT_PAD(0x30, 0x5C);
    /* 5C */ struct Anim *anim;
    /* 60 */ struct ProcEkrSubAnimeEmulator *sub_proc;
};

void NewEfxDamageMojiEffect(struct Anim *anim, int hitted);
void EfxDamageMojiEffect_Loop(struct ProcEfx *proc);
void NewEfxDamageMojiEffectOBJ(struct Anim *anim, int hitted);
void EfxDamageMojiEffectOBJ_Loop(struct ProcEfxDamageMojiEffectOBJ *proc);
void NewEfxCriricalEffect(struct Anim *anim);
void EfxCriricalEffect_Loop(struct ProcEfx *proc);
void NewEfxCriricalEffectBG(struct Anim *anim);
void EfxCriricalEffectBG_Loop(struct ProcEfxBG *proc);
void NewEfxCriricalEffectBGCOL(struct Anim *anim);
void EfxCriricalEffectBGCOL_Loop(struct ProcEfxBGCOL *proc);
void NewEfxNormalEffect(struct Anim *anim);
void EfxNormalEffect_Loop(struct ProcEfx *proc);
void NewEfxNormalEffectBG(struct Anim *anim);
void EfxNormalEffectBG_Loop(struct ProcEfxBG *proc);

/**
 * efxmisc
 */
void NewEfxYushaSpinShield(struct Anim *anim, int state);
void EfxYushaSpinShield_Null(struct ProcEfx *proc);
void NewEfxYushaSpinShieldOBJ(struct Anim *anim, int state);
void EfxYushaSpinShieldOBJ_1(struct ProcEfxOBJ *proc);
void EfxYushaSpinShieldOBJ_2(struct ProcEfxOBJ *proc);
void EfxYushaSpinShieldOBJ_3(struct ProcEfxOBJ *proc);
void EfxYushaSpinShieldOBJ_4(struct ProcEfxOBJ *proc);
void NewEfxHurtmutEff00(struct Anim *anim);
void EfxHurtmutEff00_Null(struct ProcEfx *proc);
void NewEfxHurtmutEff00OBJ(struct Anim *anim);
void EfxHurtmutEff00OBJ_1(struct ProcEfxOBJ *proc);
void EfxHurtmutEff00OBJ_2(struct ProcEfxOBJ *proc);
void EfxHurtmutEff00OBJ_3(struct ProcEfxOBJ *proc);
void NewEfxHurtmutEff01OBJ(struct Anim *anim);
void EfxHurtmutEff01OBJ_1(struct ProcEfxOBJ *proc);
void EfxHurtmutEff01OBJ_2(struct ProcEfxOBJ *proc);
void EfxHurtmutEff01OBJ_3(struct ProcEfxOBJ *proc);
void NewEfxMagfcast(struct Anim *anim, int type);
void EfxMagfcast_Loop(struct ProcEfx *proc);
void NewEfxMagfcastBG(struct Anim *anim, u32 type);
void EfxMagfcastBG_Loop(struct ProcEfxBG *proc);
void NewEfxSunakemuri(struct Anim *anim, int type);
void EfxSunakemuri_Null(struct ProcEfx *proc);
void NewEfxSunakemuriOBJ(struct Anim *anim, int type);
void EfxSunakemuriOBJ_Loop(struct ProcEfxOBJ *proc);
void NewEfxKingPika(struct Anim *anim);
void EfxKingPika_Loop(struct ProcEfx *proc);
void NewEfxSongFE6(struct Anim *anim);
void EfxSongFE6_Loop(struct ProcEfxOBJ *proc);
void NewEfxDanceOBJ(struct Anim *anim);
void EfxDanceOBJ_Loop(struct ProcEfxOBJ *proc);
void NewEfxMosaicEffect(struct Anim *anim, int duration, int hi);
void EfxMosaicEffect_1(struct ProcEfxBG *proc);
void EfxMosaicEffect_2(struct ProcEfxBG *proc);

struct ProcEfxSRankSCR2 {
    PROC_HEADER;
    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ i16 timer;
    /* 2E */ i16 terminator;

    STRUCT_PAD(0x30, 0x44);

    /* 44 */ u32 unk44;

    STRUCT_PAD(0x48, 0x5C);

    /* 5C */ struct ProcEfx *seff_scr1;
};
extern EWRAM_OVERLAY(banim) i16 gEfxSpecalEffectExist[2];

void NewEfxSpecalEffect(struct Anim *anim);
void EfxSpecalEffect_Null(ProcPtr proc);
void NewEfxSRankWeaponEffect(struct Anim *anim);
void EfxSRankWeaponEffect_Loop(struct ProcEfx *proc);
void NewEfxSRankWeaponEffectBG(struct Anim *anim);
void EfxSRankWeaponEffectBG_Loop(struct ProcEfxBG *proc);
void HBlank_EfxSRankWeaponEffectSCR(void);
void NewEfxSRankWeaponEffectSCR(void);
 void EfxSRankWeaponEffectSCR_Loop(struct ProcEfx *proc);
void NewEfxSRankWeaponEffectSCR2(struct ProcEfx *seff_scr);
void EfxSRankWeaponEffectSCR2_Loop(struct ProcEfxSRankSCR2 *proc);
void NewEfxMagdhisEffect(struct Anim *anim);
void EfxMagdhisEffect_Loop(struct ProcEfx *proc);
void NewEfxMagdhisEffectBG(struct Anim *anim, int);
void EfxMagdhisEffectBG_Loop(struct ProcEfxBG *proc);
void NewEfxMantBatabata(struct Anim *anim);
void EfxMantBatabata_1(struct ProcEfxOBJ *proc);
void EfxMantBatabata_2(struct ProcEfxOBJ *proc);
void ResetClassReelSpell(void);
void EndActiveClassReelSpell(void);
void EndActiveClassReelBgColorProc(void);
void SetActiveClassReelSpell(ProcPtr proc);
void SetActiveCRSpellBgColorProc(ProcPtr proc);
// GetMagicEffectBufferFor
// SetCRSpellBgPosition
// ClearCRSpellBgTmBuf
// CRSpellCreateFrontAnim
// CRSpell_WriteBgMap
// CRSpell_RegisterBgGfx
// CRSpell_RegisterBgPal
// CRSpell_RegisterObjGfx
// CRSpell_RegisterObjPal
void StartClassReelSpellAnim(struct Anim *anim);
// StartClassReelSpellAnimDummy
// StartClassReelSpellAnimFire
// EfxopFire_Loop
// NewEfxopFireBG
// EfxopFireBG_Loop
// NewEfxopFireOBJ
// EfxopFireOBJ_Loop
// StartClassReelSpellAnimThunder
// EfxopThunder_Loop
// NewEfxopThunderBG
// EfxopThunderBG_Loop
// NewEfxopThunderBGCOL
// EfxopThunderBGCOL_Loop
// NewEfxopThunderOBJ
// func_fe6_08058528
// func_fe6_0805854C
// func_fe6_08058568
// func_fe6_080585DC
// func_fe6_08058630
// func_fe6_0805867C
// func_fe6_080586B0
// func_fe6_080586F0
// func_fe6_08058720
// func_fe6_0805873C
// func_fe6_080587C0
// func_fe6_08058824

/* banim_ekrdragon.h */

void func_fe6_0805B01C(u16 * tm, u16 width, u16 height, int pal, int chr);
void FillBGRect(u16 * tm, u16 width, u16 height, int pal, int chr);
void func_fe6_0805B0D4(u16 * tm, u16 width, u16 height, int pal, int chr);
void EfxTmModifyPal(u16 * tm, u16 width, u16 height);
void EfxTmCpyBG(const void * ptr1, void * ptr2, u16 width, u16 height, int pal, int chr);
void EfxTmCpyBgHFlip(const u16 * tsa, u16 * tm, u16 width, u16 height, int pal, int chr);
void EfxTmCpyExt(const u16 * src, i16 src_width, u16 * dst, i16 dst_width, u16 width, u16 hight, int pal, int chr);
void EfxTmCpyExtHFlip(const u16 * src, i16 src_width, u16 * dst, i16 dst_width, u16 width, u16 hight, int pal, int chr);
void func_fe6_0805B380(u16 * tm, int arg1, int arg2);
void EkrModifyBarfx(u16 * tm, int);
// func_fe6_0805B4D8
void EfxPalBlackInOut(u16 * pal_buf, int line, int length, int ref);
void EfxPalWhiteInOut(u16 * pal_buf, int line, int length, int ref);
void EfxPalFlashingInOut(u16 const * pal_buf, int line, int length, int r0, int g0, int b0);
void EfxPalModifyPetrifyEffect(u16 * pal_buf, int line, int length);
void EfxSplitColor(u16 * pal, u8 * dst, u32 length);
void EfxSplitColorPetrify(u16 * src, u8 * dst, u32 length);
void func_fe6_0805B88C(i8 * src1, i8 * src2, i16 * pal, u32 length, int ref);
void EfxDecodeSplitedPalette(u16 * dst, i8 * src1, i8 * src2, i16 * src3, u32 length, int ref, int unk);
void EfxChapterMapFadeOUT(int speed);
int BanimSpawnRandB(int a);

struct ProcEkrSubAnimeEmulator {
    PROC_HEADER;

    /* 29 */ u8 type;
    /* 2A */ u8 valid;
    /* 2C */ i16 timer;
    /* 2E */ i16 scr_cur;

    STRUCT_PAD(0x30, 0x32);

    /* 32 */ i16 x1;
    /* 34 */ i16 x2;

    STRUCT_PAD(0x36, 0x3A);

    /* 3A */ i16 y1;
    /* 3C */ i16 y2;

    STRUCT_PAD(0x3E, 0x44);

    /* 44 */ u32 *anim_scr;
    /* 48 */ void * sprite;
    /* 4C */ int oam2Base;
    /* 50 */ int oamBase;
};

struct ProcEkrSubAnimeEmulator * NewEkrsubAnimeEmulator(int x, int y, u32 *anim_scr, int type, int oam2Base, int oamBase, ProcPtr parent);
void EkrsubAnimeEmulator_Loop(struct ProcEkrSubAnimeEmulator *proc);
int GetAnimSpriteRotScaleX(u32 header);
int GetAnimSpriteRotScaleY(u32 header);
void BanimUpdateSpriteRotScale(void * src, struct BaSpriteData * out, i16 x, i16 y, int unused);
void EfxPlaySE(int songid, int volume);
// func_fe6_0805BD04
void DoM4aSongNumStop(int num);
// func_fe6_0805BD64
void EfxStopBGM1(void);
void UnregisterEfxSoundSeExist(void);
// func_fe6_0805BDA8
// func_fe6_0805BDB4
void M4aPlayWithPostionCtrl(int songid, int x, int flag);
void EfxPlaySEwithCmdCtrl(struct BaSprite *anim, int cmd);
// func_fe6_0805C1A0
int IsAnimSoundInPosition(struct Anim *anim);
// func_fe6_0805C2E0
enum efx_hp_change_type {
    EFX_HPT_CHANGED = 0,
    EFX_HPT_DEFEATED = 1,
    EFX_HPT_NOT_CHANGE = 2
};

i16 GetEfxHpChangeType(struct Anim *anim);
void EfxPlayHittedSFX(struct Anim *anim);
void EfxPlayCriticalHittedSFX(struct Anim *anim);
int EfxCheckRetaliation(int is_retaliation);
int EfxCheckStaffType(int weapon);
void EkrPlayMainBGM(void);
void EkrRestoreBGM(void);
int GetProperAnimSoundLocation(struct Anim *anim);
void PlaySFX(int songid, int volume, int locate, int type);
void PlaySfxAutomatically(int songid, int volume, struct Anim *anim);
bool EkrClasschgFinished(void);
void EndEkrClasschg(void);
void NewEkrClassChg(struct BaSprite *anim);
// func_fe6_0805C89C
// func_fe6_0805CB64
// func_fe6_0805CB6C
// func_fe6_0805CBB0
// func_fe6_0805CBF4
// func_fe6_0805CC64
// func_fe6_0805CC80
// func_fe6_0805CCE8
// func_fe6_0805CD04
// func_fe6_0805CD68
// func_fe6_0805CDB4
// func_fe6_0805CDCC
// func_fe6_0805CEE0
// func_fe6_0805CF38
// func_fe6_0805CF58
// func_fe6_0805CFBC
// func_fe6_0805CFC0
// func_fe6_0805CFF8
// func_fe6_0805D09C
// func_fe6_0805D0E0

enum ekr_lvup_status_index {
    EKRLVUP_STAT_HP = 0,
    EKRLVUP_STAT_POW,
    EKRLVUP_STAT_SKL,
    EKRLVUP_STAT_SPD,
    EKRLVUP_STAT_LCK,
    EKRLVUP_STAT_DEF,
    EKRLVUP_STAT_RES,
    EKRLVUP_STAT_CON,
    EKRLVUP_STAT_MAX,

    EKRLVUP_STAT_CLASS = EKRLVUP_STAT_MAX,
    EKRLVUP_STAT_LV_MSG,
    EKRLVUP_STAT_LV_VAL,

    EKRLVUP_STAT_PNAME = EKRLVUP_STAT_MAX,
    EKRLVUP_STAT_LVPRE_MSG,
    EKRLVUP_STAT_LVPRE_VAL
};

struct ProcEkrlvup {
    PROC_HEADER;

    /* 29 */ u8 finished;
    /* 2A */ u8 is_promotion;
    /* 2C */ i16 timer;
    /* 2E */ i16 index;

    STRUCT_PAD(0x30, 0x44);

    /* 44 */ int scroll_timer[4];

    STRUCT_PAD(0x54, 0x5C);

    struct Anim *anim_this, *anim_other;
};

extern struct ProcEkrlvup * gpProcEkrLevelup;
extern struct Unit * gpEkrLvupUnit;
extern struct BattleUnit * gpEkrLvupBattleUnit;
extern u16 gEkrLvupPreLevel;
extern u16 gEkrLvupPostLevel;
extern u16 gEkrLvupBaseStatus[EKRLVUP_STAT_MAX];
extern u16 gEkrLvupPostStatus[EKRLVUP_STAT_MAX];
extern u16 gEkrLvupScrollPos1;
extern u16 gEkrLvupScrollPos2;
extern int gEkrLvupApfxUnexist;

extern const u16 sEfxLvupPartsPos[];
extern CONST_DATA char EkrLvupMsgsStr[][5];
extern CONST_DATA char EkrLvupMsgsMag[][5];

bool CheckEkrLvupDone(void);
void EndEkrLevelUp(void);
// EkrLvup_InitStatusText
// func_fe6_0805D4E0
// func_fe6_0805D538
// func_fe6_0805D570
void NewEkrLevelup(struct BaSprite *anim);
void EkrLvup_Init(struct ProcEkrlvup *proc);
void EkrLvup_InitLevelUpBox(struct ProcEkrlvup *proc);
void func_fe6_0805DA08(struct ProcEkrlvup *proc);
void func_fe6_0805DA38(struct ProcEkrlvup *proc);
void func_fe6_0805DA7C(struct ProcEkrlvup *proc);
void func_fe6_0805DBA4(struct ProcEkrlvup *proc);
void func_fe6_0805DBD4(struct ProcEkrlvup *proc);
void func_fe6_0805DC2C(struct ProcEkrlvup *proc);
void func_fe6_0805DCB4(struct ProcEkrlvup *proc);
void func_fe6_0805DD08(struct ProcEkrlvup *proc);
void func_fe6_0805DD78(struct ProcEkrlvup *proc);
void func_fe6_0805DDA8(struct ProcEkrlvup *proc);
void func_fe6_0805DE8C(struct ProcEkrlvup *proc);
void func_fe6_0805DEBC(struct ProcEkrlvup *proc);
void func_fe6_0805DEC8(struct ProcEkrlvup *proc);
void func_fe6_0805DF90(struct ProcEkrlvup *proc);
void func_fe6_0805E104(struct ProcEkrlvup *proc);
// func_fe6_0805E140
// func_fe6_0805E180
// func_fe6_0805E230
// func_fe6_0805E248
// func_fe6_0805E2BC
// func_fe6_0805E2C0
// func_fe6_0805E2CC
// func_fe6_0805E2E4
// func_fe6_0805E2E8
// func_fe6_0805E370
// func_fe6_0805E43C
// func_fe6_0805E448
// func_fe6_0805E454
// func_fe6_0805E4D4
// func_fe6_0805E510
bool CheckEkrTriangleInvalid(void);
void DebugEkrTriangleMsg(void);
void NewEkrTriangle(struct BaSprite *anim);
// EkrTriangle_Loop
// NewEkrTriPegasusKnight
// EkrTriPegasusKnight_Loop
// NewEkrTriPegasusKnightBG
// EfxTriPegasusKnightBG_Loop
// NewEkrTriPegasusKnightOBJ
// EkrTriPegasusKnightOBJ_Loop
// NewEkrTriArmorKnight
// EkrTriArmorKnight_Loop
// NewEkrTriArmorKnightOBJ
// EkrTriArmorKnightOBJ_Loop
// NewEkrTriArmorKnightOBJ2
// EkrTriArmorKnightOBJ2_Loop1
// EkrTriArmorKnightOBJ2_Loop2
// NewEfxTriangleQUAKE
// EfxTriangleQUAKE_Loop

extern CONST_DATA u16 *gBattleBGDataTable[];

void PutBanimBgIMG(int index);
void PutBanimBgTSA(int index);
void PutBanimBgPAL(int);
void PutBanimBG(int);

struct ProcEkrPopup {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ i16 timer;
    /* 2E */ i16 terminator;

    STRUCT_PAD(0x30, 0x44);

    /* 44 */ int lbuff;
    /* 48 */ int ldebuf;
    /* 4C */ int rbuff;
    /* 50 */ int rdebuf;

    STRUCT_PAD(0x54, 0x60);

    /* 60 */ struct Anim *anim;
};

extern struct ProcEkrPopup * gpProcEkrPopup;
extern int gEkrPopupDone;

bool CheckEkrPopupDone(void);
void EndEkrPopup(void);
// EfxPlaySound5AVol100
// EfxPlaySound5CVol100
// MakeBattlePopupTileMap
// DrawBattlePopup
void NewEkrPopup(void);
void EkrPopup_BeginningPause(struct ProcEkrPopup *proc);
void EkrPopup_DrawRankUp1(struct ProcEkrPopup *proc);
void EkrPopup_WaitRankUp1(struct ProcEkrPopup *proc);
void EkrPopup_DrawRankUp2(struct ProcEkrPopup *proc);
void EkrPopup_WaitRankUp2(struct ProcEkrPopup *proc);
void EkrPopup_DrawWeaponBroken1(struct ProcEkrPopup *proc);
void EkrPopup_WaitWeaponBroken1(struct ProcEkrPopup *proc);
void EkrPopup_DrawWeaponBroken2(struct ProcEkrPopup *proc);
void EkrPopup_WaitWeaponBroken2(struct ProcEkrPopup *proc);
void EkrPopup_EndingPause(struct ProcEkrPopup *proc);
void EkrPopup_Blocked(struct ProcEkrPopup *proc);

extern CONST_DATA struct ProcScr ProcScr_EkrBattleDeamon[];
extern CONST_DATA struct ProcScr ProcScr_EkrBattle[];
extern CONST_DATA struct ProcScr ProcScr_EkrLvupFan[];
extern CONST_DATA struct ProcScr ProcScr_EkrGauge[];
extern CONST_DATA u16 gUnk_085CB580[];
extern CONST_DATA u16 gUnk_085CB5B0[];
// ??? gUnk_085CB5C8
// ??? gUnk_085CB5F8
// ??? gUnk_085CB634
// ??? gUnk_085CB670
extern CONST_DATA u16 gUnk_085CB688[];
extern CONST_DATA u16 gUnk_085CB6A0[];
extern CONST_DATA u16 gUnk_085CB6A0[];
extern CONST_DATA u16 gUnk_085CB6B8[];
extern CONST_DATA u16 gUnk_085CB6D0[];
extern CONST_DATA u16 gUnk_085CB6E8[];
extern CONST_DATA u16 gUnk_085CB700[];
extern CONST_DATA struct ProcScr ProcScr_EkrDispUP[];
extern CONST_DATA struct ProcScr ProcScr_EfxHpBar[];
extern CONST_DATA struct ProcScr ProcScr_EfxHpBarResire[];
extern CONST_DATA struct ProcScr ProcScr_EfxAvoid[];
extern CONST_DATA struct ProcScr ProcScr_EfxNoDmage[];
extern CONST_DATA struct ProcScr ProcScr_EfxHpBarLive[];
extern CONST_DATA struct ProcScr ProcScr_EfxNoDamageYure[];
extern CONST_DATA struct ProcScr ProcScr_EfxStatusCHG[];
extern CONST_DATA struct ProcScr ProcScr_EfxDeadEvent[];
extern CONST_DATA struct ProcScr ProcScr_EfxDead[];
extern CONST_DATA struct ProcScr ProcScr_EfxDeadPika[];
extern CONST_DATA struct ProcScr ProcScr_EfxDeadAlpha[];
extern CONST_DATA struct ProcScr ProcScr_EfxDeadDragonAlpha[];
extern CONST_DATA struct ProcScr ProcScr_EfxFarAttack[];
extern CONST_DATA struct ProcScr ProcScr_EfxQuakePure[];
// ??? EfxQuakePureVecs
extern CONST_DATA struct ProcScr ProcScr_EfxHitQuakePure[];
extern CONST_DATA struct ProcScr ProcScr_EfxQuake[];
extern CONST_DATA struct ProcScr ProcScr_EfxHitQuake[];
extern CONST_DATA struct ProcScr ProcScr_EfxFlashBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxWhiteIN[];
extern CONST_DATA struct ProcScr ProcScr_EfxFlashHpBar[];
extern CONST_DATA struct ProcScr ProcScr_EfxStatusUnit[];
extern CONST_DATA struct ProcScr ProcScr_EfxWeaponIcon[];
extern CONST_DATA struct ProcScr ProcScr_EfxHpBarColorChange[];
extern CONST_DATA struct ProcScr ProcScr_EfxSpellCast[];
extern CONST_DATA struct ProcScr ProcScr_EkrBattleStarting[];
extern CONST_DATA struct ProcScr ProcScr_Ekrbattleending[];
extern CONST_DATA struct ProcScr ProcScr_EkrBaseKaiten[];
// ??? Imgs_EkrBaseKaiten1
// ??? Imgs_EkrBaseKaiten2
extern CONST_DATA AnimScr AnimScrs_EkrBaseKaiten1[];
extern CONST_DATA AnimScr AnimScrs_EkrBaseKaiten2[];
extern CONST_DATA AnimScr AnimScrs_EkrBaseKaiten3[];
extern CONST_DATA AnimScr AnimScrs_EkrBaseKaiten4[];
extern CONST_DATA AnimScr AnimScrs_EkrBaseKaiten5[];
extern CONST_DATA AnimScr AnimScrs_EkrBaseKaiten6[];
// ??? gUnk_085CBCC8
// ??? gUnk_085CBCE8
// ??? gUnk_085CBD08
extern CONST_DATA struct ProcScr ProcScr_EkrUnitKakudai[];
extern CONST_DATA struct ProcScr ProcScr_EkrWindowAppear[];
extern CONST_DATA struct ProcScr ProcScr_EkrNamewinAppear[];
extern CONST_DATA struct ProcScr ProcScr_EkrBaseAppear[];
extern CONST_DATA AnimScr AnimScr_DefaultAnim[];
extern CONST_DATA u16 *TsaConfs_BanimTmA[];
extern CONST_DATA struct ProcScr ProcScr_EkrChienCHR[];
extern CONST_DATA struct ProcScr ProcScr_EfxAnimeDrv[];
extern CONST_DATA struct ProcScr ProcScr_EkrUnitMainMini[];
extern CONST_DATA struct ProcScr ProcScr_EkrTogiInitPROC[];
extern CONST_DATA struct ProcScr ProcScr_EkrTogiEndPROC[];
extern CONST_DATA struct ProcScr ProcScr_EkrTogiColor[];
// ??? Pals_ArenaBattleBg[];
// ??? gUnk_085CCC40
extern CONST_DATA AnimScr AnimScr_EkrTerrainfx_R_Far[];
extern CONST_DATA AnimScr AnimScr_EkrTerrainfx_L_Far[];
extern CONST_DATA AnimScr AnimScr_EkrTerrainfx_R_Close[];
extern CONST_DATA AnimScr AnimScr_EkrTerrainfx_L_Close[];
extern u32 AnimScr_NoDamage[];
extern u32 AnimScr_Miss[];

typedef void (* SpellAnimFunc)(struct Anim *anim);
extern CONST_DATA SpellAnimFunc gEkrSpellAnimLut[];

extern u32 AnimScr_Common[];
extern CONST_DATA struct ProcScr ProcScr_EfxRestRST[];
extern CONST_DATA struct ProcScr ProcScr_EfxDummyRST[];
extern CONST_DATA struct ProcScr ProcScr_EfxRestWIN[];
extern CONST_DATA struct ProcScr ProcScr_EfxRestWINH[];
extern CONST_DATA struct ProcScr ProcScr_EfxALPHA[];
extern CONST_DATA struct ProcScr ProcScr_EfxCircleWIN[];
extern CONST_DATA struct ProcScr ProcScr_EfxMagicQUAKE[];
extern CONST_DATA struct ProcScr ProcScr_EfxDummyMagic[];
extern CONST_DATA struct ProcScr ProcScr_EfxTeono[];
extern CONST_DATA struct ProcScr ProcScr_EfxTeonoOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxTeonoOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxTeonoSE[];
extern CONST_DATA struct ProcScr ProcScr_EfxArrow[];
extern CONST_DATA struct ProcScr ProcScr_EfxArrowOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxTeyari[];
extern CONST_DATA struct ProcScr ProcScr_EfxTeyariOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxSong[];
extern CONST_DATA struct ProcScr ProcScr_EfxSongBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxSongBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxDance[];
extern CONST_DATA struct ProcScr ProcScr_EfxShooter[];
extern CONST_DATA struct ProcScr ProcScr_EfxShooterOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxEckesachs[];
extern CONST_DATA struct ProcScr ProcScr_EfxEckesachsBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxEckesachsBGCtrl[];
extern CONST_DATA struct ProcScr ProcScr_EfxEckesachsBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxHurtmut[];
extern CONST_DATA struct ProcScr ProcScr_EfxHurtmutOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxFirebreath[];
extern CONST_DATA struct ProcScr ProcScr_EfxFirebreathOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxFirebreathBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxFirebreathBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxIcebreath[];
extern CONST_DATA struct ProcScr ProcScr_EfxIcebreathOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxDarkbreath[];
extern CONST_DATA struct ProcScr ProcScr_EfxDarkbreathBG[];
extern CONST_DATA u16 *Tsa_EfxDarkbreathBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxDarkbreathBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxDarkbreathOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxThunder[];
extern CONST_DATA struct ProcScr ProcScr_EfxThunderBG[];
extern CONST_DATA u16 *TsaArray_EfxThunderBG_L[];
extern CONST_DATA u16 *TsaArray_EfxThunderBG_R[];
extern CONST_DATA struct ProcScr ProcScr_EfxThunderBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxThunderOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxFire[];
extern CONST_DATA struct ProcScr ProcScr_EfxFireBG[];
extern CONST_DATA u16 *TsaArray_EfxFireBG_L[];
extern CONST_DATA u16 *TsaArray_EfxFireBG_R[];
extern CONST_DATA struct ProcScr ProcScr_EfxFireOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxFireHITBG[];
extern CONST_DATA u16 *ImgArray_EfxFireHITBG[];
extern CONST_DATA u16 *TsaArray_EfxFireHITBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxElfireBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxElfireBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxElfireOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxFimbulvetr[];
extern CONST_DATA struct ProcScr ProcScr_EfxFimbulvetrBGTR[];
extern CONST_DATA u16 *TsaArray_EfxFimbulvetrBGTR[];
extern CONST_DATA u16 *ImgArray_EfxFimbulvetrBGTR[];
extern CONST_DATA struct ProcScr ProcScr_EfxFimbulvetrBG[];
extern CONST_DATA u16 *TsaArray_EfxFimbulvetrBG[];
extern CONST_DATA u16 *ImgArray_EfxFimbulvetrBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxFimbulvetrOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxFimbulvetrOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxFimbulvetrOBJ2Fall[];
extern CONST_DATA struct ProcScr ProcScr_EfxThunderstorm[];
extern CONST_DATA struct ProcScr ProcScr_EfxThunderstormBG[];
extern CONST_DATA u16 *ImgArray_EfxThunderstormBG[];
extern CONST_DATA u16 *TsaArray_EfxThunderstormBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxThunderstormOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxThunderstormCOLOR[];
extern CONST_DATA struct ProcScr ProcScr_EfxThunderstormDARK[];
extern CONST_DATA struct ProcScr ProcScr_EfxAlacalibur[];
extern CONST_DATA struct ProcScr ProcScr_EfxAlacaliburBG[];
extern CONST_DATA u16 *TsaArray_EfxAlacaliburBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxAlacaliburBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxAlacaliburOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxMistyrain[];
extern CONST_DATA struct ProcScr ProcScr_EfxMistyrainBG[];
extern CONST_DATA u16 *TsaArray_EfxMistyrainBG[];
extern CONST_DATA u16 *ImgArray_EfxMistyrainBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxMistyrainOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxMistyrainOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxResire[];
extern CONST_DATA struct ProcScr ProcScr_EfxResireBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxResireBG2[];
extern CONST_DATA u16 *ImgArray_EfxResireBG[];
extern CONST_DATA u16 *TsaArray_EfxResireBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxResireRST[];
extern CONST_DATA struct ProcScr ProcScr_EfxLightning[];
extern CONST_DATA struct ProcScr ProcScr_EfxLightningBG[];
extern CONST_DATA u16 *ImgArray_EfxLightningBG[];
extern CONST_DATA u16 *PalArray_EfxLightningBG[];
extern CONST_DATA u16 *TsaArray_EfxLightningBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxPurge[];
extern CONST_DATA struct ProcScr ProcScr_EfxPurgeBG[];
extern CONST_DATA u16 *ImgArray_EfxPurgeBG[];
extern CONST_DATA u16 *PalArray_EfxPurgeBG[];
extern CONST_DATA u16 *TsaArray_EfxPurgeBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxPurgeOBJRND[];
// ??? Vecs_EfxPurgeOBJRND
extern CONST_DATA struct ProcScr ProcScr_EfxPurgeOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxForblaze[];
extern CONST_DATA struct ProcScr ProcScr_EfxForblazeBG1[];
extern CONST_DATA u16 *TsaArray_EfxForblazeBG1[];
extern CONST_DATA u16 *ImgArray_EfxForblazeBG1[];
extern CONST_DATA struct ProcScr ProcScr_EfxForblazeBGCOL1[];
extern CONST_DATA struct ProcScr ProcScr_EfxForblazeBGCtrl1[];
extern CONST_DATA struct ProcScr ProcScr_EfxForblazeOBJ[];
// ??? gUnk_085D2288
extern CONST_DATA struct ProcScr ProcScr_EfxForblazeOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxForblazeBG2[];
extern CONST_DATA struct ProcScr ProcScr_EfxForblazeOBJCtrl[];
extern CONST_DATA struct ProcScr ProcScr_EfxForblazeOBJFall[];
extern CONST_DATA struct ProcScr ProcScr_EfxForblazeRST[];
extern CONST_DATA struct ProcScr ProcScr_EfxDivine[];
extern CONST_DATA struct ProcScr ProcScr_EfxDivineBG[];
extern CONST_DATA u16 *ImgArray_EfxDivineBG[];
extern CONST_DATA u16 *TsaArray_EfxDivineBG[];
extern CONST_DATA u16 *ImgArray_EfxDivineBG2[];
extern CONST_DATA u16 *TsaArray_EfxDivineBG2[];
extern CONST_DATA u16 *ImgArray_EfxDivineBG3[];
extern CONST_DATA u16 *TsaArray_EfxDivineBG3[];
extern CONST_DATA struct ProcScr ProcScr_EfxDivineOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxAureola[];
extern CONST_DATA struct ProcScr ProcScr_EfxAureolaBG[];
extern CONST_DATA u16 *ImgArray_EfxAureolaBG[];
extern CONST_DATA u16 *TsaArray_EfxAureolaBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxAureolaBG2[];
extern CONST_DATA struct ProcScr ProcScr_EfxAureolaBG2COL[];
extern CONST_DATA struct ProcScr ProcScr_EfxAureolaOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxAureolaOBJCtrl[];
extern CONST_DATA struct ProcScr ProcScr_EfxAureolaOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxAureolaOBJ3[];
extern CONST_DATA struct ProcScr ProcScr_EfxAureolaOBJ3Ctrl[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypse[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseBGCtrl[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseOBJ[];
// ??? AnimArray_EfxApocalypseOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseBGCOL2[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseDummy[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseBgFlash1[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseBgFlash2[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseBG2[];
extern CONST_DATA u16 *ImgArray_EfxApocalypseBG2[];
extern CONST_DATA u16 *TsaArray_EfxApocalypseBG2[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseOBJ3[];
extern int DuraArray_EfxApocalypseOBJ3RND[];
// ??? LoArray_EfxApocalypseOBJ3RND[];
// ??? StateArray_EfxApocalypseOBJ3RND[];
extern CONST_DATA struct ProcScr ProcScr_EfxApocalypseOBJ3RND[];
extern CONST_DATA struct ProcScr ProcScr_EfxHazymoon[];
extern CONST_DATA struct ProcScr ProcScr_EfxHazymoonBG[];
extern CONST_DATA u16 *TsaArray_EfxHazymoonBG[];
extern CONST_DATA u16 *ImgArray_EfxHazymoonBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxHazymoonOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxHazymoonOBJ3[];
// ??? gEclipseAnimSpriteCoordinates[];
extern CONST_DATA struct ProcScr ProcScr_EfxHazymoonOBJ3RND[];
extern CONST_DATA struct ProcScr ProcScr_EfxFenrir[];
extern CONST_DATA struct ProcScr ProcScr_EfxFenrirBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxFenrirBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxFenrirOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxFenrirBG2[];
extern CONST_DATA u16 *ImgArray_EfxFenrirBG2_A[];
extern CONST_DATA u16 *TsaArray_EfxFenrirBG2_A[];
extern CONST_DATA struct ProcScr ProcScr_EfxFenrirOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxFenrirOBJ2Chiri[];
// ??? gFenrirSpriteAngles[];
extern CONST_DATA struct ProcScr ProcScr_EfxLive[];
extern CONST_DATA struct ProcScr ProcScr_EfxRelive[];
extern CONST_DATA struct ProcScr ProcScr_EfxRecover[];
extern CONST_DATA struct ProcScr ProcScr_EfxReblow[];
extern CONST_DATA struct ProcScr ProcScr_EfxLiveBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxLiveBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxLiveALPHA[];
extern CONST_DATA struct ProcScr ProcScr_EfxLiveOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxReserveOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxReblowOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxReserve[];
extern CONST_DATA struct ProcScr ProcScr_EfxReserveBG[];
extern CONST_DATA u16 *TsaArray_EfxReserveBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxReserveBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxReserveBG2[];
extern CONST_DATA u16 *TsaArray_EfxReserveBG2[];
extern CONST_DATA struct ProcScr ProcScr_EfxReserveBGCOL2[];
extern CONST_DATA struct ProcScr ProcScr_EfxRest[];
extern CONST_DATA struct ProcScr ProcScr_EfxRestBG[];
extern CONST_DATA u16 *TsaArray_EfxRestBG[];
extern CONST_DATA u16 *ImgArray_EfxRestBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxRestOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxSilence[];
extern CONST_DATA struct ProcScr ProcScr_EfxSilenceBG[];
extern CONST_DATA u16 *TsaArray_EfxSilenceBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxSilenceOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxSleep[];
extern CONST_DATA struct ProcScr ProcScr_EfxSleepBG[];
extern CONST_DATA u16 *TsaArray_EfxSleepBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxSleepOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxSleepOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxSleepSE[];
extern CONST_DATA struct ProcScr ProcScr_EfxHammarne[];
extern CONST_DATA struct ProcScr ProcScr_EfxHammarneBG[];
extern CONST_DATA u16 *TsaArray_EfxHammarneBG[];
extern CONST_DATA u16 *ImgArray_EfxHammarneBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxHammarneOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxBerserk[];
extern CONST_DATA struct ProcScr ProcScr_EfxBerserkBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxBerserkCLONE[];
extern CONST_DATA struct ProcScr ProcScr_EfxBerserkOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxMshield[];
extern CONST_DATA struct ProcScr ProcScr_EfxMshieldBG[];
extern CONST_DATA u16 *TsaArray_EfxMshieldBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxMshieldOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxMshieldOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxDamageMojiEffect[];
extern CONST_DATA struct ProcScr ProcScr_EfxDamageMojiEffectOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxCriricalEffect[];
extern CONST_DATA struct ProcScr ProcScr_EfxCriricalEffectBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxCriricalEffectBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxNormalEffect[];
extern CONST_DATA struct ProcScr ProcScr_EfxNormalEffectBG[];
extern CONST_DATA u16 *TSAs_EfxNormalEffectBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxYushaSpinShield[];
extern CONST_DATA struct ProcScr ProcScr_EfxYushaSpinShieldOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxHurtmutEff00[];
extern CONST_DATA struct ProcScr ProcScr_EfxHurtmutEff00OBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxHurtmutEff01OBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxMagfcast[];
extern CONST_DATA struct ProcScr ProcScr_EfxMagfcastBG[];
extern CONST_DATA u16 *TsaLut1_EfxMagfcastBG[];
extern CONST_DATA u16 *TsaLut2_EfxMagfcastBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxSunakemuri[];
extern CONST_DATA struct ProcScr ProcScr_EfxSunakemuriOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxKingPika[];
extern CONST_DATA struct ProcScr ProcScr_EfxSongFE6[];
extern CONST_DATA struct ProcScr ProcScr_EfxDanceOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxMosaicEffect[];
extern CONST_DATA struct ProcScr ProcScr_EfxSpecalEffect[];
extern CONST_DATA struct ProcScr ProcScr_EfxSRankWeaponEffect[];
extern CONST_DATA struct ProcScr ProcScr_EfxSRankWeaponEffectBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxSRankWeaponEffectSCR[];
extern CONST_DATA struct ProcScr ProcScr_EfxSRankWeaponEffectSCR2[];
extern CONST_DATA i16 EfxSRankWeaponEffectSCR_Ref[];
extern CONST_DATA struct ProcScr ProcScr_EfxMagdhisEffect[];
extern CONST_DATA struct ProcScr ProcScr_EfxMagdhisEffectBG[];
extern CONST_DATA u16 *TsaArray_EfxMagdhisEffectBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxMantBatabata[];
// ??? gClassReelSpellAnimFuncLut
extern CONST_DATA struct ProcScr ProcScr_EfxopFire[];
extern CONST_DATA struct ProcScr ProcScr_EfxopFireBG[];
extern CONST_DATA u16 *TsaArray_EfxopFireBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxopFireOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EfxopThunder[];
extern CONST_DATA struct ProcScr ProcScr_EfxopThunderBG[];
extern CONST_DATA u16 *TsaArray_EfxopThunderBG[];
extern CONST_DATA struct ProcScr ProcScr_EfxopThunderBGCOL[];
extern CONST_DATA struct ProcScr ProcScr_EfxopThunderOBJ[];
// ??? gUnk_085D3A2C
// ??? gUnk_085D3A54
// ??? gUnk_085D3A6C
// ??? gUnk_085D3A70
// ??? gUnk_085D3A90
// ??? gUnk_085D3AB0
extern u32 AnimScr_TeonoObjCloseRight[];
extern u32 AnimScr_TeonoObjFarRight[];
extern u32 AnimScr_TeonoObj2Right[];
extern u32 AnimScr_TeonoObjCloseLeft[];
extern u32 AnimScr_TeonoObjFarLeft[];
extern u32 AnimScr_TeonoObj2Left[];
extern u32 AnimScr_ArrowCloseRight[];
extern u32 AnimScr_ArrowFarRight[];
extern u32 AnimScr_ArrowCloseLeft[];
extern u32 AnimScr_ArrowFarLeft[];
extern u32 AnimScr_EfxTeyariObjType0Right[];
extern u32 AnimScr_EfxTeyariObjType0Left[];
extern u32 AnimScr_EfxTeyariObjType1Right[];
extern u32 AnimScr_EfxTeyariObjType1Left[];
extern u32 AnimScr_EfxShooterOBJ_L[];
extern u32 AnimScr_EfxShooterOBJ_R[];
extern u32 AnimScr_EfxDanceObj[];
extern u32 AnimScr_EfxSongFE6[];
extern u32 AnimScr_EfxBindingBlade_L[];
extern u32 AnimScr_EfxBindingBlade_R[];
extern u32 AnimScr_HurtmutEff00OBJ1_Right[];
extern u32 AnimScr_HurtmutEff01OBJ1_Right[];
extern u32 AnimScr_HurtmutEff00OBJ1_Left[];
extern u32 AnimScr_HurtmutEff01OBJ1_Left[];
extern u32 AnimScr_HurtmutEff00OBJ2_Right[];
extern u32 AnimScr_HurtmutEff01OBJ2_Right[];
extern u32 AnimScr_HurtmutEff00OBJ2_Left[];
extern u32 AnimScr_HurtmutEff01OBJ2_Left[];
extern u32 AnimScr_FirebreathOBJ_L[];
extern u32 AnimScr_FirebreathOBJ_R[];
extern u32 AnimScr_IcebreathOBJ_R[];
extern u32 AnimScr_IcebreathOBJ_L[];
extern u32 AnimScr_DarkBreath[];
extern u32 AnimScr_YushaSpinShieldOBJ_LeftTypeA[];
extern u32 AnimScr_YushaSpinShieldOBJ2_RightTypeA[];
extern u32 AnimScr_YushaSpinShieldOBJ3_RightTypeA[];
extern u32 AnimScr_YushaSpinShieldOBJ_RightTypeA[];
extern u32 AnimScr_YushaSpinShieldOBJ2_LeftTypeA[];
extern u32 AnimScr_YushaSpinShieldOBJ3_LeftTypeA[];
extern u32 AnimScr_YushaSpinShieldOBJ_LeftTypeB[];
extern u32 AnimScr_YushaSpinShieldOBJ2_RightTypeB[];
extern u32 AnimScr_YushaSpinShieldOBJ3_RightTypeB[];
extern u32 AnimScr_YushaSpinShieldOBJ_RightTypeB[];
extern u32 AnimScr_YushaSpinShieldOBJ2_LeftTypeB[];
extern u32 AnimScr_YushaSpinShieldOBJ3_LeftTypeB[];
extern u32 AnimScr_EfxSunakemuriOBJ1_R[];
extern u32 AnimScr_EfxSunakemuriOBJ1_L[];
extern u32 AnimScr_EfxSunakemuriOBJ2_R[];
extern u32 AnimScr_EfxSunakemuriOBJ2_L[];
extern u32 AnimScr_EfxSunakemuriOBJ3_R[];
extern u32 AnimScr_EfxSunakemuriOBJ3_L[];
extern u32 AnimScr_EfxMantBatabata1_R[];
extern u32 AnimScr_EfxMantBatabata1_L[];
extern u32 AnimScr_EfxMantBatabata2_R[];
extern u32 AnimScr_EfxMantBatabata2_L[];
extern u32 AnimScr_EfxMantBatabata3_R[];
extern u32 AnimScr_EfxMantBatabata3_L[];
extern u32 AnimScr_EfxThunderOBJ_R[];
extern u32 AnimScr_EfxThunderOBJ_L[];
extern u32 AnimScr_EfxFireOBJ_L_Front[];
extern u32 AnimScr_EfxFireOBJ_L_Back[];
extern u32 AnimScr_EfxFireOBJ_R_Front[];
extern u32 AnimScr_EfxFireOBJ_R_Back[];
extern u32 AnimScr_EfxElfireOBJ_R[];
extern u32 AnimScr_EfxElfireOBJ_L[];
extern CONST_DATA AnimScr AnimScr_EfxThunderstormOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxForblazeOBJ2[];
extern CONST_DATA AnimScr AnimScr_EfxForblazeOBJ3[];
extern CONST_DATA AnimScr AnimScr_EfxForblazeOBJ4[];
extern CONST_DATA AnimScr AnimScr_EfxForblazeOBJ5[];
extern CONST_DATA AnimScr AnimScr_EfxForblazeOBJ6[];
extern CONST_DATA AnimScr AnimScr_EfxFimbulvetrOBJ1[];
extern CONST_DATA AnimScr AnimScr_EfxFimbulvetrOBJ2Fall[];
extern CONST_DATA AnimScr AnimScr_FimbulvetrOBJ2Fall_TypeA[];
extern CONST_DATA AnimScr AnimScr_FimbulvetrOBJ2Fall_TypeB[];
extern CONST_DATA AnimScr AnimScr_EfxAlacaliburOBJ_RF[];
extern CONST_DATA AnimScr AnimScr_EfxAlacaliburOBJ_RB[];
extern CONST_DATA AnimScr AnimScr_EfxAlacaliburOBJ_LF[];
extern CONST_DATA AnimScr AnimScr_EfxAlacaliburOBJ_LB[];
extern CONST_DATA AnimScr AnimScr_EfxMistyrainOBJ1_1[];
extern CONST_DATA AnimScr AnimScr_EfxHazymoonOBJ3RND[];
extern CONST_DATA AnimScr AnimScr_EfxMistyrainOBJ1_2[];
extern CONST_DATA AnimScr AnimScr_EfxMistyrainOBJ2_1[];
extern CONST_DATA AnimScr AnimScr_EfxMistyrainOBJ2_2[];
extern CONST_DATA AnimScr AnimScr_EfxMistyrainOBJ1_3[];
extern CONST_DATA AnimScr AnimScr_EfxDivineOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxApocalypseOBJ2_1[];
extern CONST_DATA AnimScr AnimScr_EfxApocalypseOBJ3RND_1[];
extern CONST_DATA AnimScr AnimScr_EfxApocalypseOBJ3RND_2[];
extern CONST_DATA AnimScr AnimScr_EfxApocalypseOBJ3RND_3[];
extern CONST_DATA AnimScr AnimScr_EfxApocalypseOBJ2_2[];
extern CONST_DATA AnimScr AnimScr_EfxHazymoonOBJ2_1[];
extern CONST_DATA AnimScr AnimScr_EfxHazymoonOBJ2_2[];
extern CONST_DATA AnimScr AnimScr_EfxHazymoonOBJ2_3[];
extern CONST_DATA AnimScr AnimScr_EfxFenrirOBJ2Chiri1[];
extern CONST_DATA AnimScr AnimScr_EfxFenrirOBJ2Chiri2[];
extern CONST_DATA AnimScr AnimScr_EfxFenrirOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxPurgeOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxLiveOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxReserveOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxReblowOBJ_L_A[];
extern CONST_DATA AnimScr AnimScr_EfxReblowOBJ_L_B[];
extern CONST_DATA AnimScr AnimScr_EfxReblowOBJ_R_A[];
extern CONST_DATA AnimScr AnimScr_EfxReblowOBJ_R_B[];
extern CONST_DATA AnimScr AnimScr_EfxRestOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxSilenceOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxHammarneOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxSleepOBJ2[];
extern CONST_DATA AnimScr AnimScr_EfxSleepOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk1[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk2[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk3[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk4[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk5[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk6[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk7[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk8[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk9[];
extern CONST_DATA AnimScr AnimScr_EfxBerserk10[];
extern CONST_DATA AnimScr AnimScr_EfxMshieldOBJ[];
extern CONST_DATA AnimScr AnimScr_EfxMshieldOBJ2[];
extern CONST_DATA AnimScr AnimScr_EfxAureolaOBJCtrl1[];
extern CONST_DATA AnimScr AnimScr_EfxAureolaOBJCtrl2[];
extern CONST_DATA AnimScr AnimScr_EfxAureolaOBJCtrl3[];
extern CONST_DATA AnimScr AnimScr_EfxAureolaOBJ2_1[];
extern CONST_DATA AnimScr AnimScr_EfxAureolaOBJ2_2[];
extern CONST_DATA AnimScr AnimScr_EfxAureolaOBJ3_1[];
extern CONST_DATA AnimScr AnimScr_EfxAureolaOBJ3_2[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonMoveBg3[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonBark[];
extern CONST_DATA struct ProcScr ProcScr_EkrManakete[];
extern CONST_DATA struct ProcScr ProcScr_EkrManaketeEnterfx[];
extern CONST_DATA struct ProcScr ProcScr_EkrManaketeExitfx[];
extern CONST_DATA struct ProcScr ProcScr_EkrManaketefx[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonFae[];
extern CONST_DATA struct ProcScr ProcScr_EkrFaefx[];
extern const u16 * CONST_DATA TsaArray_EkrFaefx[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonIdunn[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonfx_IdunnIntro[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonfx_IdunnBaseAppear[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonfx_IdunnBodyAnime[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonfx_IdunnExit2[];
extern CONST_DATA struct ProcScr ProcScr_EkrIdunnDeamon1[];
extern CONST_DATA struct ProcScr ProcScr_EkrIdunnDeamon2[];
extern CONST_DATA struct ProcScr ProcScr_EkrIdunnBodyFlashing[];
// ??? gUnk_08604A18
// ??? gUnk_08604A3C
extern CONST_DATA struct ProcScr ProcScr_EkrIdunnExitAnim1[];
// ??? gUnk_08604A9C
extern CONST_DATA struct ProcScr ProcScr_EkrDragonDeath[];
extern AnimScr AnimScr_ManaketeEnter1[];
extern AnimScr AnimScr_ManaketeExit3[];
extern AnimScr AnimScr_ManaketeEnter2[];
extern AnimScr AnimScr_ManaketeExit2[];
extern AnimScr AnimScr_ManaketeEnter3[];
extern AnimScr AnimScr_ManaketeExit1[];
extern CONST_DATA AnimScr AnimScr_EkrIdunnDeamon1[];
extern CONST_DATA AnimScr AnimScr_EkrIdunnDeamon2[];
extern i16 PosArray_EfxApocalypseBGCtrl[];
// ??? gEfxTmyPalRefs
extern CONST_DATA struct ProcScr ProcScr_EkrSubAnimeEmulator[];
extern CONST_DATA struct ProcScr ProcScr_EfxSoundSE[];
// ??? gBanimBossBGMs
// ??? gUnk_08605F34
// ??? gUnk_08605F50
// ??? gUnk_08605F6C
extern CONST_DATA struct ProcScr ProcScr_EkrClasschg[];
// ??? gUnk_08605FA8
// ??? gUnk_08605FC0
// ??? gUnk_0860601C
// ??? gUnk_08606078
// ??? gUnk_086060D4
// ??? gUnk_086060EC
// ??? gUnk_08606104
// ??? gUnk_08606124
// ??? gUnk_0860613C
// ??? gUnk_0860615C
// ??? gUnk_08606174
extern CONST_DATA struct FaceVramEnt FaceConfig_EkrLevelup[];
extern CONST_DATA struct ProcScr ProcScr_EkrLevelup[];
// ??? gUnk_08606254
// ??? gUnk_0860626C
// ??? gUnk_0860628C
// ??? gUnk_086062AC
// ??? gUnk_086062EC
extern CONST_DATA struct ProcScr ProcScr_EkrTriangle[];
extern CONST_DATA struct ProcScr ProcScr_EkrTriPegasusKnight[];
extern CONST_DATA struct ProcScr ProcScr_EkrTriPegasusKnightBG[];
extern CONST_DATA const u16 *TsaArray_EkrTriPegagusBG[];
extern CONST_DATA struct ProcScr ProcScr_EkrTriPegasusKnightOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EkrTriArmorKnight[];
extern CONST_DATA struct ProcScr ProcScr_EkrTriArmorKnightOBJ[];
extern CONST_DATA struct ProcScr ProcScr_EkrTriArmorKnightOBJ2[];
extern CONST_DATA struct ProcScr ProcScr_EfxTriangleQUAKE[];
extern CONST_DATA AnimScr AnimScr_TriAtkLeft[];
extern CONST_DATA AnimScr AnimScr_TriAtkRight[];
extern CONST_DATA AnimScr AnimScr_TriKnightOBJ[];
extern CONST_DATA AnimScr AnimScr_TriGenerialLanceOBJ[];
extern CONST_DATA AnimScr AnimScr_TriGenerialAxeOBJ[];
extern CONST_DATA AnimScr AnimScr_TriGenerialHandAxeOBJ[];
extern CONST_DATA AnimScr AnimScr_TriKnightAtkOBJ[];
extern CONST_DATA AnimScr AnimScr_TriGenerialLanceAtkOBJ[];
extern CONST_DATA AnimScr AnimScr_TriGenerialAxeAtkOBJ[];
extern CONST_DATA AnimScr AnimScr_TriGenerialHandAxeAtkOBJ[];
extern CONST_DATA AnimScr AnimScr_EkrPopup[];
extern CONST_DATA struct ProcScr ProcScr_EkrPopup[];

extern i16 const gEfxNoDmgBgShakeOff[];
extern i16 const gEfxQuakePureVec1[];
extern i16 const gEfxQuakePureVec2[];
extern i16 const gEfxQuakePureVec3[];
extern i16 const gEfxQuakePureVec4[];
extern i16 const gEfxQuakePureVec5[];
extern i16 const gEfxQuakePureVec6[];
extern i16 const gEfxQuakeVec_08111E14[];
extern i16 const gEfxQuakePureVec7[];
extern i16 const gEfxQuakePureVec8[];
extern i16 const gEfxQuakePureVec9[];
extern i16 const gEfxQuakePureVec10[];
extern i16 const gEfxQuakePureVec11[];
extern i16 const gEfxQuakeVec_08111F30[];
extern i16 const gEfxQuakeVec_08111FC6[];
// extern ??? RoundTypes_NormalPhy
// extern ??? RoundTypes_MissedPhy
// extern ??? RoundTypes_CriticalPhy
// extern ??? RoundTypes_TargetMiss
// extern ??? RoundTypes_TargetHitted
// extern ??? RoundTypes_NormalMag
// extern ??? RoundTypes_CriticalMag
// extern ??? RoundTypes_Dragon1
// extern ??? RoundTypes_Dragon2
// extern ??? RoundTypes_Dragon3
extern const u8 BanimDefaultModeConfig[ANIM_ROUND_MAX * 4];
extern const u8 BanimDefaultStandingTypes[5];
extern const u8 BanimTypesPosLeft[5];
extern const u8 BanimTypesPosRight[5];
extern const u16 BanimLeftDefaultPos[5];
extern const u16 Tsa_EkrTerrainfx_081122DA[];
// extern ??? FrameArray_EkrTogiColor
extern u16 TsaConf_BanimTmA_08112380[];
extern u16 TsaConf_BanimTmA_08112418[];
extern u16 TsaConf_BanimTmA_081124B0[];
extern u16 TsaConf_BanimTmA_08112548[];
// extern ??? gUnk_081125E0
// extern ??? gUnk_081127F0
// extern ??? gUnk_08112840
// extern ??? gUnk_081128AC
// extern ??? gUnk_081128FC
// extern ??? gUnk_08112968
// extern ??? gUnk_08112A1C
extern u8 const gUnk_08112AD0[];
extern u8 const gUnk_08112BA4[];
// extern ??? gUnk_08112C84
// extern ??? gUnk_08112CD4
