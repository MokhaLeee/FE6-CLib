#pragma once

/**
 * messed banim related struct/data/functions
 */

#include "prelude.h"
#include "banim_sprite.h"
#include "battle.h"

enum EkrDistanceType_idx {
    EKR_DISTANCE_CLOSE,
    EKR_DISTANCE_FAR,
    EKR_DISTANCE_FARFAR,
    EKR_DISTANCE_MONOCOMBAT,
    EKR_DISTANCE_PROMOTION
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
    BGPAL_EFX_SPELL_BG = 1,
    BGPAL_EFXDRAGON_L = 6,
    BGPAL_EFXDRAGON_R = 7,

    OBPAL_EFX_SPELL_BG = 1,
    OBPAL_EFX_SPELL_OBJ = 2,
    OBPAL_EFX_FACE = 3,
    OBPAL_EFX_UNIT_L = 7,
    OBPAL_EFX_UNIT_R = 9,
    OBPAL_EFXHPBAR_L = 11,
    OBPAL_EFXHPBAR_R = 12,
    OBPAL_EFX_ITEM_L = 13,
    OBPAL_EFX_ITEM_R = 14,

    VRAMOFF_BANIM_SPELL_OBJ = 0x0800,
    VRAMOFF_BANIM_SPELL_BG  = 0x2000,
};

enum ekr_hit {
    EKR_HITTED = 0,
    EKR_MISS
};

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
    /* 5C */ struct Anim * anim;
    STRUCT_PAD(0x60, 0x64);
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
    /* 5C */ struct  BaSprite * anim;
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
    /* 4C */ void * pal;
    STRUCT_PAD(0x50, 0x5C);
    /* 5C */ struct  BaSprite * anim;
};

struct ProcEfxRST
{
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);
    /* 2C */ i16 timer;
    /* 2E */ i16 unk2E;
    /* 30 */ i16 unk30;
    STRUCT_PAD(0x32, 0x5C);
    /* 5C */ struct  BaSprite * anim;
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
    /* 5C */ struct  BaSprite * anim;
    /* 60 */ struct  BaSprite * anim2;
    /* 64 */ struct  BaSprite * anim3;
    /* 68 */ struct  BaSprite * anim4;
};

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
extern u16 gEfxPal[0x130];
extern u32 gEkrBattleEndFlag;
extern i8 gEfxSplitedColorBufA[2][0x30];
extern i8 gEfxSplitedColorBufB[2][0x30];
extern i16 gEfxSplitedColorBufC[2][0x30];
extern int gProcEkrBaseAppearExist;
extern u32 gUnk_Banim_0201E0F8;
extern u32 gBanimDoneFlag[2];
extern ProcPtr gpProcEfxAnimeDrv;
extern const void * gpImgSheet[2];
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
extern u8 gEkrPids[2];
extern struct Unit * gpEkrTriangleUnits[2];
extern u16 * gpBanimTriAtkPalettes[2];
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
extern struct Vec2i gEkrBg2QuakeVec;
extern u32 gUnk_Banim_02017754;
extern u32 gEkrBgPosition;
extern i16 gBanimEffectiveness[2];
extern i16 gBanimUniquePaletteDisabled[2];
extern i16 gBanimValid[2];
extern i16 gBanimPositionIsEnemy[2];
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
void EkrLvupFanMain(struct ProcEfx * proc);
// func_fe6_080435EC
// EkrGaugeModDec
void NewEkrGauge(void);
void EndEkrGauge(void);
void EkrGauge_080438C8(void);
void EkrGauge_080438D8(void);
void func_fe6_080438E8(void);
void func_fe6_080438F8(void);
void EkrGauge_08043908(u16 val);
// func_fe6_08043918
void func_fe6_0804392C(i16 x, i16 y);
// func_fe6_08043940
// func_fe6_08043950
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
void func_fe6_08044230(u16 x, u16 y);
void SyncEkrDispUP(void);
void UnsyncEkrDispUP(void);
void AsyncEkrDispUP(void);
void UnAsyncEkrDispUP(void);
// EkrDispUP_Loop
void EfxClearScreenFx(void);
// func_fe6_080444EC
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
    /* 5C */ struct BaSprite * anim_main_other;
    /* 60 */ struct BaSprite * anim_main_this;
    /* 64 */ struct BaSprite * anim_this;
};

int CheckEkrHitDone(void);
i16 CheckEkrHitNow(int pos);
void NewEfxHpBar(struct BaSprite * anim);
void EfxHpBar_DeclineToDeath(struct ProcEfxHpBar * proc);
void EfxHpBar_MoveCameraOnEnd(struct ProcEfxHpBar * proc);
void EfxHpBar_WaitCameraMove(struct ProcEfxHpBar * proc);
void NewEfxHpBarResire(struct BaSprite * anim);
void EfxHpBarResire_WaitOnCurrentSide(struct ProcEfxHpBar * proc);
void EfxHpBarResire_SetAnotherSide(struct ProcEfxHpBar * proc);
void EfxHpBarResire_DeclineToDeath(struct ProcEfxHpBar * proc);
void NewEfxAvoid(struct BaSprite * anim);
void EfxAvoid_Loop(struct ProcEfxHpBar * proc);
void NewEfxHpBarLive(struct BaSprite * anim);
void EfxHpBarLive_Loop(struct ProcEfxHpBar * proc);
void NewEfxNoDamage(struct BaSprite * anim1, struct BaSprite * anim2, int death);
void EfxNoDmage_Loop(struct ProcEfxHpBar * proc);
void NewEfxNoDamageYure(struct BaSprite * anim1, struct BaSprite * anim2);
void EfxNoDamageYure_Loop(struct ProcEfxHpBar * proc);
void NewEfxStatusCHG(struct BaSprite * anim);
void EfxStatusCHG_Loop(struct ProcEfxHpBar * proc);

struct ProcEfxDead {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);
    /* 2C */ i16 timer, terminator;
    STRUCT_PAD(0x30, 0x5C);
    /* 5C */ struct BaSprite * anim1, * anim2;
    /* 64 */ ProcPtr subproc;
};

void NewEfxDeadEvent(struct BaSprite * anim1, struct BaSprite * anim2);
void EfxDeathEvent_Init(struct ProcEfxDead * proc);
void EfxDeathEvent_RemoveUI(struct ProcEfxDead * proc);
void EfxDeathEvent_CallEvent(struct ProcEfxDead * proc);
void EfxDeathEvent_WaitEvent(struct ProcEfxDead * proc);
void EfxDeathEvent_End(struct ProcEfxDead * proc);
void NewEfxDead(struct BaSprite * anim1, struct BaSprite * anim2);
void EfxDead_StartPika(struct ProcEfxDead * proc);
void EfxDead_StartAlpha(struct ProcEfxDead * proc);
void NewEfxDeadPika(struct BaSprite * anim1, struct BaSprite * anim2);
void EfxDeadPika_Loop(struct ProcEfxDead * proc);
void NewEfxDeadAlpha(struct BaSprite * anim1, struct BaSprite * anim2);
void EfxDeadAlpha_Loop(struct ProcEfxDead * proc);
void NewEfxDeadDragonAlpha(struct BaSprite * anim1, struct BaSprite * anim2);
void EfxDeadDragonAlpha_Loop(struct ProcEfxDead * proc);

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

void NewEfxFarAttackWithDistance(struct Anim * anim, i16);
void func_fe6_08045D6C(struct ProcEfxFarAttack * unused, int x);
void func_fe6_08045DA4(struct ProcEfxFarAttack * proc);
void func_fe6_08045DDC(struct ProcEfxFarAttack * proc);
void func_fe6_08045E50(struct ProcEfxFarAttack * proc);
void func_fe6_08045EE8(int);

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
    /* 5C */ struct BaSprite * anim_l;
    /* 60 */ struct BaSprite * anim_r;
    /* 64 */ struct BaSprite * unk_64;
};

#define SetEkrBg2QuakeVec(_x, _y) \
    gEkrBg2QuakeVec.x = (_x);     \
    gEkrBg2QuakeVec.y = (_y);

ProcPtr NewEfxQuakePure(int type, int stopped);
void EfxQuakePure_Loop(struct ProcEfxQuake * proc);
ProcPtr NewEfxHitQuakePure(void);
void EfxHitQuakePure_Loop(struct ProcEfxQuake * proc);
ProcPtr NewEfxQuake(int type);
void EfxQuake_Loop(struct ProcEfxQuake * proc);
void NewEfxHitQuake(struct BaSprite * anim1, struct BaSprite * anim2, int kind);
void EfxHitQuake_Loop(struct ProcEfxQuake * proc);

struct ProcEfxFlashing {
    PROC_HEADER;

    /* 29 */ u8 flag;

    STRUCT_PAD(0x2A, 0x2C);

    /* 2C */ i16 timer;
    /* 2E */ i16 terminator;
    /* 30 */ i16 terminator2;

    STRUCT_PAD(0x32, 0x5C);

    /* 5C */ struct BaSprite * anim;
};

void NewEfxFlashBgWhite(struct BaSprite * anim, int duartion);
void NewEfxFlashBgRed(struct BaSprite * anim, int duartion);
void EfxFlashBg_Loop(struct ProcEfxFlashing * proc);
void EfxFlashRestorePalSync(struct ProcEfxFlashing * proc);
void NewEfxWhiteIN(struct BaSprite * anim, int duartion, int duartion2);
void EfxWhiteIn_Loop1(struct ProcEfxFlashing * proc);
void EfxWhiteIn_Loop2(struct ProcEfxFlashing * proc);
void EfxBlackInRestorePalSync(struct ProcEfxFlashing * proc);

void NewEfxFlashHpBar(struct Anim * anim, int duartion, int duartion2);
void EfxFlashHpBar_Pause(struct ProcEfxFlashing * proc);
void EfxFlashHpBar_Loop(struct ProcEfxFlashing * proc);
void EfxFlashHpBar_RestorePal(struct ProcEfxFlashing * proc);

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

    /* 5C */ struct Anim * anim;
};

extern struct ProcEfxHpBarColorChange * gpProcEfxHpBarColorChange;

void NewEfxHpBarColorChange(struct BaSprite * anim);
void EndEfxHPBarColorChange(void);
void DisableEfxHpBarColorChange(void);
void EnableEfxHpBarColorChange(void);
void EfxHpBarColorChange_Loop(struct ProcEfxHpBarColorChange * proc);

void NewEfxFlashUnit(struct BaSprite * anim, u16 dura1, u16 dura2, int c);
void EfxFlashUnit_Loop(struct ProcEfxFlashing * proc);
void EfxFlashUnit_RestorePal(struct ProcEfxFlashing * proc);

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

    /* 5C */ struct Anim * anim;
};

extern struct ProcEfxStatusUnit * gpProcEfxStatusUnits[2];

void NewEfxStatusUnit(struct BaSprite * anim);
void EndEfxStatusUnits(struct BaSprite *anim);
void DisableEfxStatusUnits(struct BaSprite * anim);
void EnableEfxStatusUnits(struct BaSprite * anim);
void SetUnitEfxDebuff(struct BaSprite * anim, int debuff);
u32 GetUnitEfxDebuff(struct BaSprite * anim);
void EfxStatusUnitFlashing(struct Anim * anim, int r, int g, int b);
void EfxStatusUnit_Loop(struct ProcEfxStatusUnit * proc);
void EfxStatusUnit_End(struct ProcEfxStatusUnit * proc);

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
void EfxWeaponIcon_Loop(struct ProcEfxWeaponIcon * proc);
void EfxWeaponIcon_End(struct ProcEfxWeaponIcon * proc);

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
void EfxSpellCast_FlashIN(struct ProcEfxSpellCast * proc);
void EfxSpellCast_Pause(struct ProcEfxSpellCast * proc);
void EfxSpellCast_FlashOUT(struct ProcEfxSpellCast * proc);

void SpellFx_Begin(void);
void SpellFx_Finish(void);
void SpellFx_SetBG1Position(void);
void SpellFx_ClearBG1(void);
void SpellFx_SetSomeColorEffect(void);
void SpellFx_ClearColorEffects(void);
void StartBattleAnimHitEffectsDefault(struct BaSprite * anim, int type);
void func_fe6_08047610(struct Anim * anim, int type);
void StartBattleAnimHitEffects(struct BaSprite * anim, int type, int quake_normal, int quake_crit);
void StartBattleAnimResireHitEffects(struct BaSprite * anim, int type);
void StartBattleAnimStatusChgHitEffects(struct BaSprite * anim, int type);
struct BaSprite * EfxCreateFrontAnim(struct BaSprite * anim, const AnimScr * scr1, const AnimScr * scr2, const AnimScr * scr3, const AnimScr * scr4);
void SpellFx_WriteBgMapUncomp(struct Anim * anim, const u16 * src1, const u16 * src2);
void SpellFx_WriteBgMap(struct BaSprite * anim, const u16 * src1, const u16 * src2);
void SpellFx_WriteBgMapExt(struct Anim * anim, const u16 * src, int width, int height);
void SpellFx_RegisterObjGfx(const void * img, u32 size);
void SpellFx_RegisterObjPal(const u16 * pal, u32 size);
void SpellFx_RegisterBgGfx(const void * img, u32 size);
void SpellFx_RegisterBgPal(const u16 * pal, u32 size);
void func_fe6_08047B10(const u16 * src, u16 * dst, u32 cur, u32 len_src, u32 len_dst);
void func_fe6_08047B3C(const u16 * src, u16 * dst, u32 cur, u32 len_src, u32 len_dst);
void func_fe6_08047B6C(const u16 * src, u16 * dst, u32 a, u32 b, u32 c);
i16 EfxAdvanceFrameLut(i16 * ptime, i16 * pcount, const i16 lut[]);
void func_fe6_08047C1C(void);
int EfxGetCamMovDuration(void);
void EfxTmFilA(u32 val);
void EfxTmFilB(u32 val);
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
void EkrBaStart_InitScreen(struct ProcEkrBattleStarting * proc);
void EkrBaStart_SreenFailIn(struct ProcEkrBattleStarting * proc);
void EkrBaStart_InitBattleScreen(struct ProcEkrBattleStarting * proc);
void EkrBaStart_ExecEkrBattle(struct ProcEkrBattleStarting * proc);
void EkrBaStart_BgFadeOut(struct ProcEkrBattleStarting * proc);
void EkrBaStart_MergeBG(struct ProcEkrBattleStarting * proc);
void func_fe6_08048154(struct ProcEkrBattleStarting * proc);

void NewEkrbattleending(void);
void func_fe6_080481CC(struct ProcEkrBattleEnding * proc);
void func_fe6_08048244(struct ProcEkrBattleEnding * proc);
void func_fe6_08048298(struct ProcEkrBattleEnding * proc);
void func_fe6_080482F4(struct ProcEkrBattleEnding * proc);
void func_fe6_08048354(struct ProcEkrBattleEnding * proc);
void func_fe6_080483E0(struct ProcEkrBattleEnding * proc);
void func_fe6_08048470(struct ProcEkrBattleEnding * proc);
void func_fe6_0804855C(struct ProcEkrBattleEnding * proc);

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
u16 GetBattleAnimationId(const struct BanimInfoEnt * animdef, u16 item);
int GetBanimTerrainGround(u16 terrain, u16 tileset);
int GetBanimBackgroundIndex(u16 terrain, u16 tileset);
i16 GetSpellAnimId(u16 jid, u16 weapon);
void UnsetMapStaffAnim(i16 * out, u16 pos, u16 weapon);
void ParseBattleHitToBanimCmd(void);
bool CheckBattleHasHit(void);
int GetBanimUniquePal(struct Unit * unit);
u16 * GetBanimTriangleAttackPalette(i16 bid, u16 item);

enum banim_faction_palette_idx {
    BANIMPAL_BLUE = 0,
    BANIMPAL_RED = 1,
    BANIMPAL_GREEN = 2,
    BANIMPAL_PURPLE = 3,
};

int GetBanimFactionPalette(u32 faction);

void EkrPrepareBanimfx(struct BaSprite * anim, i16);

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
i16 GetBattleAnimRoundTypeFlags(int);

#define GetRoundFlagByAnim(aAnim) (GetBattleAnimRoundTypeFlags((aAnim->nextRoundId - 1) * 2 + GetAnimPosition(aAnim)))

i16 GetEfxHp(int index);
// func_fe6_0804A5C0
void BattleAIS_ExecCommands(void);
// NewEkrChienCHR
// EkrChienCHRMain
// RegisterAISSheetGraphics
// func_fe6_0804AFD4
// GetBanimPalette
void UpdateBanimFrame(void);
void InitMainAnims(void);
void InitBattleAnimFrame(int round_type_left, int round_type_right);
void InitLeftAnim(int round_type);
void InitRightAnim(int round_type);
void SwitchAISFrameDataFromBARoundType(struct BaSprite * anim, int type);
int GetAnimLayer(struct BaSprite * anim);
int GetAnimPosition(struct BaSprite * anim);
int CheckRoundMiss(i16 type);
int CheckRound1(i16 type);
int CheckRound2(i16 type);
int CheckRoundCrit(struct Anim * anim);
struct BaSprite * GetAnimAnotherSide(struct BaSprite * anim);
i16 GetAnimRoundType(struct BaSprite * anim);
i16 GetAnimNextRoundType(struct BaSprite * anim);
i16 GetAnimRoundTypeAnotherSide(struct BaSprite * anim);
i16 GetAnimNextRoundTypeAnotherSide(struct BaSprite * anim);
void SetAnimStateHidden(int pos);
void SetAnimStateUnHidden(int pos);
// func_fe6_0804B930
// func_fe6_0804BACC
// func_fe6_0804BAF0
// func_fe6_0804BB54
// func_fe6_0804BCC8
// func_fe6_0804BE14
// func_fe6_0804BE20
// func_fe6_0804BE3C
// func_fe6_0804BE4C
// func_fe6_0804BE6C
// func_fe6_0804BE80
// NewEfxAnimeDrvProc
// EndEfxAnimeDrvProc
// ExecAllBas
// NewEkrUnitMainMini
// func_fe6_0804BF00
// func_fe6_0804BF24
// func_fe6_0804BF40
// func_fe6_0804C2EC
// func_fe6_0804C318
// func_fe6_0804C330
// func_fe6_0804C478
void SetBanimArenaFlag(int flag);
int GetBattleAnimArenaFlag(void);
void func_fe6_0804C50C(int x);
void PlayDeathSoundForArena(void);
void func_fe6_0804C56C(void);
void BeginAnimsOnBattle_Arena(void);
void ExecBattleAnimArenaExit(void);
void NewEkrTogiInitPROC(void);
// func_fe6_0804C5D0
// func_fe6_0804C658
// func_fe6_0804C6CC
// func_fe6_0804C730
// func_fe6_0804C744
// func_fe6_0804C75C
// func_fe6_0804C788
// func_fe6_0804C7EC
// func_fe6_0804C818
// func_fe6_0804C84C
// func_fe6_0804C860

/* efxmagic */
void StartSpellAnimation(struct Anim * anim);
void func_fe6_0804C8D0(void);
ProcPtr NewefxRestRST(struct Anim * anim, int unk44, int unk48, int frame, int unk50);
void EfxRestRST_End(struct ProcEfx * proc);
void EfxRestRST_Loop(struct ProcEfx * proc);
void NewDummvRST(struct Anim * anim, int unk44);
void EfxDummyRST_End(struct ProcEfx * proc);
void EfxDummyRST_Loop(struct ProcEfx * proc);
void NewEfxRestWIN(struct Anim * anim, int unk44, void * unk54, void * unk58);
void EfxRestWIN_Loop(struct ProcEfx * proc);
void NewEfxRestWINH(struct Anim * anim, int a, i16 b, void (* hblank)(void));
void NewEfxRestWINH_(struct Anim * anim, int a, void (* hblank)(void));
void EfxRestWINH_Dummy(struct ProcEfx * proc);
void EfxRestWINH_Loop(struct ProcEfx * proc);
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

    /* 5C */ struct Anim * anim;
};

void NewEfxALPHA(struct Anim * anim, int delay, int duration2, int lo, int hi, int type);
void EfxALPHA_Loop(struct ProcEfxALPHA * proc);

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
    /* 5C */ struct Anim * anim;
};

void NewEfxCircleWIN(struct Anim * anim, int terminator, u16 * c, u16 d, u16 e);
void EfxCircleWIN_Loop(struct ProcEfxCircleWIN * proc);

struct ProcEfxMagicQuake
{
    PROC_HEADER;
    STRUCT_PAD(0x29, 0x2c);

    /* 2C */ i16 timer, duration;

    STRUCT_PAD(0x30, 0x5c);

    /* 5C */ struct Anim * anim;
    /* 60 */ ProcPtr qproc;
};

void NewEfxMagicQUAKE(struct Anim * anim, int duration);
void EfxMagicQUAKE_Loop(struct ProcEfxMagicQuake * proc);

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
    /* 5C */ struct Anim * anim;
    STRUCT_PAD(0x60, 0x64);
    ProcPtr unk_64;
};

struct ProcEfxMagicOBJ {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x2C);

    /* 2C */ i16 timer, terminator;

    STRUCT_PAD(0x30, 0x5C);

    /* 5C */ struct Anim * anim;
    /* 60 */ struct Anim * anim2;

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
    /* 5C */ struct Anim * anim;
};

void NewEfxDummyMagic(struct Anim * anim);
void EfxDummyMagic_Loop(struct ProcEfxMagic * proc);
void NewEfxTeono(struct Anim * anim);
void EfxTeono_Loop(struct ProcEfxMagic * proc);
void NewEfxTeonoOBJ(struct Anim * anim);
void EfxTeonoObj_Loop(struct ProcEfxMagicOBJ * proc);
void EfxTeonoObj_End(struct ProcEfxMagicOBJ * proc);
void NewEfxTeonoOBJ2(struct Anim * anim);
void EfxTeonoOBJ2_Loop(struct ProcEfxMagicOBJ * proc);
ProcPtr NewEfxTeonoSE(struct Anim * anim, struct Anim * anim2);
void EfxTeonoSE_End(struct ProcEfxMagicOBJ * proc);
void EfxTeonoSE_Loop(struct ProcEfxMagicOBJ * proc);
// NewEfxArrow
// EfxArrow_Loop
// func_fe6_0804D728
// func_fe6_0804D790
// func_fe6_0804D7C0
// func_fe6_0804D81C
// func_fe6_0804D878
// func_fe6_0804D8D4
// func_fe6_0804D930
// func_fe6_0804D98C
// func_fe6_0804D9E8
// func_fe6_0804DA44
// func_fe6_0804DAA0
// func_fe6_0804DAFC
// func_fe6_0804DBAC
// func_fe6_0804DC24
// func_fe6_0804DC54
// func_fe6_0804DC8C
// func_fe6_0804DD38
// func_fe6_0804DD94
// func_fe6_0804DDC8
// func_fe6_0804DE04
// func_fe6_0804DE4C
// func_fe6_0804DE84
// func_fe6_0804DF30
// func_fe6_0804DF80
// func_fe6_0804E040
// func_fe6_0804E0B8
// func_fe6_0804E0E8
// func_fe6_0804E124
// func_fe6_0804E1C0
// func_fe6_0804E280
// func_fe6_0804E2B4
// func_fe6_0804E2F8
// func_fe6_0804E3C0
// func_fe6_0804E3FC
// func_fe6_0804E448
// func_fe6_0804E484
// func_fe6_0804E540
// func_fe6_0804E5B0
// func_fe6_0804E5E4
// func_fe6_0804E61C
// func_fe6_0804E6BC
// func_fe6_0804E744
// func_fe6_0804E778
// func_fe6_0804E814
// func_fe6_0804E848
// func_fe6_0804E884
// func_fe6_0804E8CC
// func_fe6_0804E908
// func_fe6_0804E988
// func_fe6_0804E9FC
// func_fe6_0804EA14
// func_fe6_0804EA4C
// func_fe6_0804EAD4
// func_fe6_0804EB24
// func_fe6_0804EB7C
// func_fe6_0804EBB8
// func_fe6_0804EC04
// func_fe6_0804EC84
// func_fe6_0804ECB8
// func_fe6_0804ECF4
// func_fe6_0804ED94
// func_fe6_0804EE18
// func_fe6_0804EE9C
// func_fe6_0804EED8
// func_fe6_0804EF24
// func_fe6_0804EF84
// func_fe6_0804EFB4
// func_fe6_0804EFF8
// func_fe6_0804F03C
// func_fe6_0804F144
// func_fe6_0804F1A4
// func_fe6_0804F1FC
// func_fe6_0804F288
// func_fe6_0804F2D0
// func_fe6_0804F354
// func_fe6_0804F3B8
// func_fe6_0804F450
// func_fe6_0804F484
// func_fe6_0804F4C8
// func_fe6_0804F510
// func_fe6_0804F594
// func_fe6_0804F5C4
// func_fe6_0804F600
// func_fe6_0804F738
// func_fe6_0804F7BC
// func_fe6_0804F820
// func_fe6_0804F8A4
// func_fe6_0804F908
// func_fe6_0804F96C
// func_fe6_0804F99C
// func_fe6_0804F9E8
// func_fe6_0804FA14
// func_fe6_0804FB6C
// func_fe6_0804FC28
// func_fe6_0804FC64
// func_fe6_0804FD24
// func_fe6_0804FD78
// func_fe6_0804FDD4
// func_fe6_0804FDF8
// func_fe6_0804FE3C
// func_fe6_0804FE60
// func_fe6_0804FE84
// func_fe6_0804FEB8
// func_fe6_0804FF1C
// func_fe6_0804FF94
// func_fe6_0804FFD8
// func_fe6_08050038
// func_fe6_0805007C
// func_fe6_080500B8
// func_fe6_080501B8
// func_fe6_08050228
// func_fe6_0805027C
// func_fe6_080502C0
// func_fe6_08050308
// func_fe6_08050390
// func_fe6_080503BC
// func_fe6_080503F8
// func_fe6_080504F0
// func_fe6_080505A0
// func_fe6_08050650
// func_fe6_080506B4
// func_fe6_080506F8
// func_fe6_08050744
// func_fe6_0805075C
// func_fe6_08050798
// func_fe6_080507D4
// func_fe6_08050810
// func_fe6_0805083C
// func_fe6_08050860
// func_fe6_0805089C
// func_fe6_080509E4
// func_fe6_08050A70
// func_fe6_08050B10
// func_fe6_08050B94
// func_fe6_08050C30
// func_fe6_08050C9C
// func_fe6_08050D04
// func_fe6_08050D68
// func_fe6_08050D98
// func_fe6_08050DE0
// func_fe6_08050E1C
// func_fe6_08050ED4
// func_fe6_08050F54
// func_fe6_0805100C
// func_fe6_08051050
// func_fe6_0805108C
// func_fe6_080511BC
// func_fe6_0805120C
// func_fe6_08051288
// func_fe6_080512BC
// func_fe6_08051328
// func_fe6_08051394
// func_fe6_080513AC
// func_fe6_080513E8
// func_fe6_0805151C
// func_fe6_080515A0
// func_fe6_08051624
// func_fe6_0805166C
// func_fe6_080516B8
// func_fe6_080516D8
// func_fe6_080516EC
// func_fe6_08051700
// func_fe6_08051720
// func_fe6_08051770
// func_fe6_080517E4
// func_fe6_0805183C
// func_fe6_08051870
// func_fe6_08051908
// func_fe6_08051A14
// func_fe6_08051A60
// func_fe6_08051AC4
// func_fe6_08051BAC
// func_fe6_08051C00
// func_fe6_08051C30
// func_fe6_08051C5C
// func_fe6_08051CD0
// func_fe6_08051D0C
// func_fe6_08051DFC
// func_fe6_08051E80
// func_fe6_08051F04
// func_fe6_08051F88
// func_fe6_08051FEC
// func_fe6_08052060
// func_fe6_08052090
// func_fe6_080520CC
// func_fe6_08052238
// func_fe6_080522D0
// func_fe6_08052334
// func_fe6_0805238C
// func_fe6_08052460
// func_fe6_080524A8
// func_fe6_080524F4
// func_fe6_08052544
// func_fe6_08052598
// func_fe6_0805267C
// func_fe6_080526F4
// func_fe6_080527A4
// func_fe6_08052848
// func_fe6_08052878
// func_fe6_080528CC
// func_fe6_08052974
// func_fe6_080529EC
// func_fe6_08052A28
// func_fe6_08052BA8
// func_fe6_08052C34
// func_fe6_08052C68
// func_fe6_08052C9C
// func_fe6_08052D40
// func_fe6_08052D8C
// func_fe6_08052DF4
// func_fe6_08052E30
// func_fe6_08052E9C
// func_fe6_08052F28
// func_fe6_08052FB4
// func_fe6_0805304C
// func_fe6_0805308C
// func_fe6_080530E4
// func_fe6_08053114
// func_fe6_0805315C
// func_fe6_0805318C
// func_fe6_080531C4
// func_fe6_080531F4
// func_fe6_08053218
// func_fe6_0805327C
// func_fe6_08053340
// func_fe6_08053420
// func_fe6_080534BC
// func_fe6_080534FC
// func_fe6_08053530
// func_fe6_08053568
// func_fe6_080535F8
// func_fe6_080536C4
// func_fe6_08053764
// func_fe6_080537A0
// func_fe6_08053954
// func_fe6_080539C4
// func_fe6_08053A44
// func_fe6_08053A98
// func_fe6_08053AFC
// func_fe6_08053B88
// func_fe6_08053BA0
// func_fe6_08053BFC
// func_fe6_08053C58
// func_fe6_08053CB4
// func_fe6_08053CFC
// func_fe6_08053D5C
// func_fe6_08053DB0
// func_fe6_08053DC8
// func_fe6_08053E04
// func_fe6_08053FF4
// func_fe6_08054084
// func_fe6_080540A0
// func_fe6_080540D0
// func_fe6_08054118
// func_fe6_08054128
// func_fe6_08054168
// func_fe6_080541C8
// func_fe6_080541FC
// func_fe6_0805428C
// func_fe6_08054310
// func_fe6_080543C4
// func_fe6_0805440C
// func_fe6_08054458
// func_fe6_080544D8
// func_fe6_08054558
// func_fe6_08054580
// func_fe6_080546A8
// func_fe6_080546D0
// func_fe6_08054848
// func_fe6_08054870
// func_fe6_080549E8
// func_fe6_08054A10
// func_fe6_08054B98
// func_fe6_08054C54
// func_fe6_08054D08
// func_fe6_08054D78
// func_fe6_08054DE8
// func_fe6_08054E58
// func_fe6_08054EA0
// func_fe6_08054EDC
// func_fe6_08054EF8
// func_fe6_08054F8C
// func_fe6_08054FEC
// func_fe6_08055050
// func_fe6_08055084
// func_fe6_080550B8
// func_fe6_080550EC
// func_fe6_08055134
// func_fe6_08055200
// func_fe6_08055234
// func_fe6_08055264
// func_fe6_08055294
// func_fe6_08055364
// func_fe6_080553B4
// func_fe6_08055434
// func_fe6_08055480
// func_fe6_080554C8
// func_fe6_08055580
// func_fe6_08055628
// func_fe6_08055674
// func_fe6_080556BC
// func_fe6_080556F8
// func_fe6_0805581C
// func_fe6_08055870
// func_fe6_080558D4
// func_fe6_0805594C
// func_fe6_0805595C
// func_fe6_08055998
// func_fe6_08055AA0
// func_fe6_08055B2C
// func_fe6_08055B84
// func_fe6_08055BDC
// func_fe6_08055BF4
// func_fe6_08055C30
// func_fe6_08055D30
// func_fe6_08055DBC
// func_fe6_08055E14
// func_fe6_08055E6C
// func_fe6_08055EC0
// func_fe6_08055ED0
// func_fe6_08055EF4
// func_fe6_08055F14
// func_fe6_08055F24
// func_fe6_08055F60
// func_fe6_08056080
// func_fe6_080560D4
// func_fe6_08056138
// func_fe6_08056190
// func_fe6_080561A0
// func_fe6_080561DC
// func_fe6_080562C0
// func_fe6_080563E0
// func_fe6_08056444
// func_fe6_08056470
// func_fe6_080564D4
// func_fe6_080564E4
// func_fe6_0805653C
// func_fe6_08056554
// func_fe6_08056590
// func_fe6_080565CC
// func_fe6_08056608
// func_fe6_08056644
// func_fe6_08056680
// func_fe6_080566BC
// func_fe6_080566F8
// func_fe6_08056734
// func_fe6_08056770
// func_fe6_080567AC
// func_fe6_080567E8
// func_fe6_080568B4
// func_fe6_08056910
// func_fe6_08056968
// func_fe6_080569C0
// func_fe6_08056A00
void NewEfxDamageMojiEffect(struct BaSprite * anim, int hitted);
// func_fe6_08056A3C
// func_fe6_08056A68
// func_fe6_08056AD8
void NewEfxPierceCritical(struct Anim * anim);
// func_fe6_08056B28
// func_fe6_08056B58
// func_fe6_08056BA8
// func_fe6_08056BD0
// func_fe6_08056C00
void NewEfxNormalEffect(struct Anim * anim);
// func_fe6_08056C5C
// func_fe6_08056C9C
// func_fe6_08056D28
// NewEfxYushaSpinShield
// func_fe6_08056DA8
// NewEfxYushaSpinShieldOBJ
// func_fe6_08056E34
// func_fe6_08056E9C
// func_fe6_08056EC4
// func_fe6_08056F28
// NewEfxHurtmutEff00
// func_fe6_08056F94
// func_fe6_08056FA0
// func_fe6_08056FE4
// func_fe6_08057030
// func_fe6_0805707C
// func_fe6_080570A0
// func_fe6_080570E4
// func_fe6_08057130
// func_fe6_0805717C
// func_fe6_080571A0
// func_fe6_08057208
// func_fe6_08057224
// func_fe6_080572EC
// func_fe6_08057344
// func_fe6_08057374
// func_fe6_08057380
// func_fe6_0805752C
// NewEfxKingPika
// func_fe6_08057578
// NewEfxFlashFX
// func_fe6_0805765C
// NewEfxSongOBJ2
// func_fe6_08057720
// func_fe6_08057754
// func_fe6_080577A0
// func_fe6_080577F4
// func_fe6_08057860
// func_fe6_08057920
// func_fe6_0805792C
// func_fe6_0805794C
// func_fe6_080579C0
// func_fe6_08057A0C
// func_fe6_08057A34
// func_fe6_08057A5C
// func_fe6_08057A7C
// func_fe6_08057B2C
// func_fe6_08057B4C
// func_fe6_08057B90
// func_fe6_08057BB0
// func_fe6_08057BF8
// func_fe6_08057C94
// NewEfxMantBatabata
// func_fe6_08057E98
// func_fe6_08057EC4
// func_fe6_08057EF4
// func_fe6_08057F08
// func_fe6_08057F24
// func_fe6_08057F40
// func_fe6_08057F4C
// func_fe6_08057F58
// func_fe6_08057F60
// func_fe6_08057FB8
// func_fe6_08057FE8
// func_fe6_0805803C
// func_fe6_080580A8
// func_fe6_080580D8
// func_fe6_08058100
// func_fe6_08058130
// func_fe6_08058158
// func_fe6_0805817C
// func_fe6_08058180
// func_fe6_080581A0
// func_fe6_080581C0
// func_fe6_08058220
// func_fe6_0805826C
// func_fe6_080582EC
// func_fe6_08058310
// func_fe6_08058330
// func_fe6_08058358
// func_fe6_080583B4
// func_fe6_08058438
// func_fe6_0805846C
// func_fe6_080584AC
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
int func_fe6_0805B9C8(int a);

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

    /* 44 */ u32 * anim_scr;
    /* 48 */ void * sprite;
    /* 4C */ int oam2Base;
    /* 50 */ int oamBase;
};

struct ProcEkrSubAnimeEmulator * NewEkrsubAnimeEmulator(int x, int y, u32 * anim_scr, int type, int oam2Base, int oamBase, ProcPtr parent);
void EkrsubAnimeEmulator_Loop(struct ProcEkrSubAnimeEmulator * proc);
int GetAnimSpriteRotScaleX(u32 header);
int GetAnimSpriteRotScaleY(u32 header);
void BanimUpdateSpriteRotScale(void * src, struct BaSpriteData * out, i16 x, i16 y, int unused);
void EfxPlaySE(int songid, int volume);
// func_fe6_0805BD04
void DoM4aSongNumStop(int num);
// func_fe6_0805BD64
// func_fe6_0805BD8C
void UnregisterEfxSoundSeExist(void);
// func_fe6_0805BDA8
// func_fe6_0805BDB4
void M4aPlayWithPostionCtrl(int songid, int x, int flag);
void EfxPlaySEwithCmdCtrl(struct BaSprite * anim, int cmd);
// func_fe6_0805C1A0
// func_fe6_0805C2B0
// func_fe6_0805C2E0
enum efx_hp_change_type {
    EFX_HPT_CHANGED = 0,
    EFX_HPT_DEFEATED = 1,
    EFX_HPT_NOT_CHANGE = 2
};

i16 GetEfxHpChangeType(struct Anim * anim);
void EfxPlayHittedSFX(struct Anim * anim);
void EfxPlayCriticalHittedSFX(struct Anim * anim);
int EfxCheckRetaliation(int is_retaliation);
int EfxCheckStaffType(int weapon);
void EkrPlayMainBGM(void);
void EkrRestoreBGM(void);
int GetProperAnimSoundLocation(struct Anim * anim);
void PlaySFX(int songid, int volume, int locate, int type);
void PlaySfxAutomatically(int songid, int volume, struct Anim * anim);
bool EkrClasschgFinished(void);
void EndEkrClasschg(void);
void NewEkrClassChg(struct BaSprite * anim);
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
bool CheckEkrLvupDone(void);
void EndEkrLevelUp(void);
// func_fe6_0805D154
// func_fe6_0805D4E0
// func_fe6_0805D538
// func_fe6_0805D570
void NewEkrLevelup(struct BaSprite * anim);
// func_fe6_0805D604
// func_fe6_0805D8B4
// func_fe6_0805DA08
// func_fe6_0805DA38
// func_fe6_0805DA7C
// func_fe6_0805DBA4
// func_fe6_0805DBD4
// func_fe6_0805DC2C
// func_fe6_0805DCB4
// func_fe6_0805DD08
// func_fe6_0805DD78
// func_fe6_0805DDA8
// func_fe6_0805DE8C
// func_fe6_0805DEBC
// func_fe6_0805DEC8
// func_fe6_0805DF90
// func_fe6_0805E104
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
void NewEkrTriangle(struct BaSprite * anim);
// func_fe6_0805E59C
// func_fe6_0805E7A0
// func_fe6_0805E7D8
// func_fe6_0805E890
// func_fe6_0805E91C
// func_fe6_0805E964
// func_fe6_0805EA10
// func_fe6_0805EA38
// func_fe6_0805EA70
// func_fe6_0805EB40
// func_fe6_0805ECC4
// func_fe6_0805ED1C
// func_fe6_0805EE2C
// func_fe6_0805EE74
// func_fe6_0805EE9C
// func_fe6_0805EED4
// func_fe6_0805F078
// func_fe6_0805F098
void PutBanimBgPAL(int);
void PutBanimBG(int);
bool CheckEkrPopupDone(void);
void EndEkrPopup(void);
// func_fe6_0805F178
// func_fe6_0805F188
// func_fe6_0805F198
// func_fe6_0805F27C
void NewEkrPopup(void);
// func_fe6_0805F57C
// func_fe6_0805F598
// func_fe6_0805F5C0
// func_fe6_0805F5F8
// func_fe6_0805F620
// func_fe6_0805F658
// func_fe6_0805F680
// func_fe6_0805F6B8
// func_fe6_0805F6E0
// func_fe6_0805F71C
// func_fe6_0805F74C
// func_fe6_0805F750
u8 GetWeaponAnimActorCount(u16 item);
// func_fe6_0805F794
struct ProcScr const * GetWeaponAnimManimSpecialScr(int item); // fu16?
fu8 func_fe6_0805F7B4(int item); // fu16?
fu8 GetItemMaFacing(int item); // fu16?
fu8 func_fe6_0805F7D4(int item); // fu16?

extern CONST_DATA struct ProcScr ProcScr_EkrBattleDeamon[];
extern CONST_DATA struct ProcScr ProcScr_EkrBattle[];
extern CONST_DATA struct ProcScr ProcScr_EkrLvupFan[];
extern CONST_DATA struct ProcScr ProcScr_EkrGauge[];
// ??? gUnk_085CB580
// ??? gUnk_085CB5B0
// ??? gUnk_085CB5C8
// ??? gUnk_085CB5F8
// ??? gUnk_085CB634
// ??? gUnk_085CB670
// ??? gUnk_085CB688
// ??? gUnk_085CB6A0
// ??? gUnk_085CB6B8
// ??? gUnk_085CB6D0
// ??? gUnk_085CB6E8
// ??? gUnk_085CB700
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
// ??? ProcScr_EfxSpellCast
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
// ??? gUnk_085CBDB0
extern CONST_DATA struct ProcScr ProcScr_EkrChienCHR[];
extern CONST_DATA struct ProcScr ProcScr_EfxAnimeDrv[];
extern CONST_DATA struct ProcScr ProcScr_EkrUnitMainMini[];
extern CONST_DATA struct ProcScr ProcScr_EkrTogiInitPROC[];
// ??? gUnk_085CBE50
// ??? gUnk_085CBE78
// ??? Pals_ArenaBattleBg
// ??? gUnk_085CCC40
// ??? gUnk_085CCDAC
// ??? gUnk_085CCE38
// ??? gUnk_085CCEB8
// ??? gUnk_085CCF38
// ??? gUnk_085CDCA4
// ??? gUnk_085CDD18

typedef void (* SpellAnimFunc)(struct Anim * anim);
extern CONST_DATA SpellAnimFunc gEkrSpellAnimLut[];

extern u32 AnimScr_ManaketeFlame[];
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
// ??? gUnk_085D0FF4
// ??? gUnk_085D100C
// ??? gUnk_085D1024
// ??? gUnk_085D103C
// ??? gUnk_085D1054
// ??? gUnk_085D106C
// ??? gUnk_085D108C
// ??? gUnk_085D10A4
// ??? gUnk_085D10BC
// ??? gUnk_085D10D4
// ??? gUnk_085D10EC
// ??? gUnk_085D1104
// ??? gUnk_085D111C
// ??? gUnk_085D113C
// ??? gUnk_085D1154
// ??? gUnk_085D116C
// ??? gUnk_085D1184
// ??? gUnk_085D119C
// ??? gUnk_085D11B4
// ??? gUnk_085D11D4
// ??? gUnk_085D11EC
// ??? gUnk_085D120C
// ??? gUnk_085D1224
// ??? gUnk_085D123C
// ??? gUnk_085D126C
// ??? gUnk_085D128C
// ??? gUnk_085D12A4
// ??? gUnk_085D12BC
// ??? gUnk_085D12D4
// ??? gUnk_085D12DC
// ??? gUnk_085D12E4
// ??? gUnk_085D1304
// ??? gUnk_085D131C
// ??? gUnk_085D1334
// ??? gUnk_085D134C
// ??? gUnk_085D137C
// ??? gUnk_085D13AC
// ??? gUnk_085D13C4
// ??? gUnk_085D13DC
// ??? gUnk_085D1430
// ??? gUnk_085D1484
// ??? gUnk_085D149C
// ??? gUnk_085D14BC
// ??? gUnk_085D14D4
// ??? gUnk_085D14EC
// ??? gUnk_085D1504
// ??? gUnk_085D151C
// ??? gUnk_085D1534
// ??? gUnk_085D154C
// ??? gUnk_085D1578
// ??? gUnk_085D15A4
// ??? gUnk_085D15BC
// ??? gUnk_085D15D4
// ??? gUnk_085D15EC
// ??? gUnk_085D1604
// ??? gUnk_085D161C
// ??? gUnk_085D1648
// ??? gUnk_085D1674
// ??? gUnk_085D169C
// ??? gUnk_085D16DC
// ??? gUnk_085D16FC
// ??? gUnk_085D1714
// ??? gUnk_085D172C
// ??? gUnk_085D1734
// ??? gUnk_085D1754
// ??? gUnk_085D176C
// ??? gUnk_085D1784
// ??? gUnk_085D179C
// ??? gUnk_085D1840
// ??? gUnk_085D18E4
// ??? gUnk_085D192C
// ??? gUnk_085D195C
// ??? gUnk_085D1974
// ??? gUnk_085D19A4
// ??? gUnk_085D19BC
// ??? gUnk_085D1A88
// ??? gUnk_085D1B54
// ??? gUnk_085D1B6C
// ??? gUnk_085D1B84
// ??? gUnk_085D1B9C
// ??? gUnk_085D1C20
// ??? gUnk_085D1CA4
// ??? gUnk_085D1D28
// ??? gUnk_085D1D40
// ??? gUnk_085D1D58
// ??? gUnk_085D1E90
// ??? gUnk_085D1FC8
// ??? gUnk_085D2100
// ??? gUnk_085D2120
// ??? gUnk_085D2158
// ??? gUnk_085D2178
// ??? gUnk_085D2190
// ??? gUnk_085D21A8
// ??? gUnk_085D21DC
// ??? gUnk_085D2210
// ??? gUnk_085D2230
// ??? gUnk_085D2270
// ??? gUnk_085D2288
// ??? gUnk_085D22E0
// ??? gUnk_085D22F8
// ??? gUnk_085D2310
// ??? gUnk_085D2328
// ??? gUnk_085D2340
// ??? gUnk_085D2358
// ??? gUnk_085D2370
// ??? gUnk_085D2388
// ??? gUnk_085D23D8
// ??? gUnk_085D2428
// ??? gUnk_085D2434
// ??? gUnk_085D2440
// ??? gUnk_085D2494
// ??? gUnk_085D24E8
// ??? gUnk_085D2500
// ??? gUnk_085D2518
// ??? gUnk_085D2530
// ??? gUnk_085D2544
// ??? gUnk_085D2558
// ??? gUnk_085D2570
// ??? gUnk_085D2590
// ??? gUnk_085D25A8
// ??? gUnk_085D25C0
// ??? gUnk_085D25D8
// ??? gUnk_085D25F0
// ??? gUnk_085D2608
// ??? gUnk_085D2620
// ??? gUnk_085D2638
// ??? gUnk_085D2658
// ??? gUnk_085D2678
// ??? gUnk_085D26B0
// ??? gUnk_085D26D0
// ??? gUnk_085D26F0
// ??? gUnk_085D2708
// ??? gUnk_085D2720
// ??? gUnk_085D2740
// ??? gUnk_085D2758
// ??? gUnk_085D2768
// ??? gUnk_085D2778
// ??? gUnk_085D2798
// ??? gUnk_085D27B0
// ??? gUnk_085D287C
// ??? gUnk_085D2944
// ??? gUnk_085D2A0C
// ??? gUnk_085D2A24
// ??? gUnk_085D2A3C
// ??? gUnk_085D2A54
// ??? gUnk_085D2AC0
// ??? gUnk_085D2B2C
// ??? gUnk_085D2B74
// ??? gUnk_085D2B8C
// ??? gUnk_085D2BA4
// ??? gUnk_085D2BC4
// ??? gUnk_085D2BDC
// ??? gUnk_085D2BFC
// ??? gUnk_085D2C24
// ??? gUnk_085D2C3C
// ??? gUnk_085D2C54
// ??? gUnk_085D2D20
// ??? gUnk_085D2DEC
// ??? gUnk_085D2E04
// ??? gUnk_085D2E1C
// ??? gUnk_085D2E3C
// ??? gUnk_085D2E54
// ??? gUnk_085D2E6C
// ??? gUnk_085D2E84
// ??? gUnk_085D2E9C
// ??? gUnk_085D2EB4
// ??? gUnk_085D2ED4
// ??? gUnk_085D2EF4
// ??? gUnk_085D2F0C
// ??? gUnk_085D2F2C
// ??? gUnk_085D2F4C
// ??? gUnk_085D2F64
// ??? gUnk_085D2F7C
// ??? gUnk_085D2F8C
// ??? gUnk_085D2FAC
// ??? gUnk_085D2FC4
// ??? gUnk_085D2FC8
// ??? gUnk_085D2FE8
// ??? gUnk_085D3000
// ??? gUnk_085D3018
// ??? gUnk_085D304C
// ??? gUnk_085D3080
// ??? gUnk_085D30A0
// ??? gUnk_085D30B8
// ??? gUnk_085D30D0
// ??? gUnk_085D3118
// ??? gUnk_085D3138
// ??? gUnk_085D3150
// ??? gUnk_085D3168
// ??? gUnk_085D31A8
// ??? gUnk_085D31C8
// ??? gUnk_085D31E8
// ??? gUnk_085D3230
// ??? gUnk_085D3248
// ??? gUnk_085D3260
// ??? gUnk_085D3294
// ??? gUnk_085D32C8
// ??? gUnk_085D32E8
// ??? gUnk_085D3300
// ??? gUnk_085D3318
// ??? gUnk_085D3338
// ??? gUnk_085D33F0
// ??? gUnk_085D3408
// ??? gUnk_085D3420
// ??? gUnk_085D3434
// ??? gUnk_085D3454
extern CONST_DATA struct ProcScr ProcScr_EfxDamageMojiEffect[];
// ??? gUnk_085D348C
// ??? gUnk_085D34A4
// ??? gUnk_085D34BC
// ??? gUnk_085D34D4
// ??? gUnk_085D34F4
// ??? gUnk_085D350C
// ??? gUnk_085D3524
extern CONST_DATA struct ProcScr ProcScr_EfxYushaSpinShield[];
extern CONST_DATA struct ProcScr ProcScr_EfxYushaSpinShieldOBJ[];
// ??? gUnk_085D3594
// ??? gUnk_085D35AC
// ??? gUnk_085D35E4
// ??? gUnk_085D361C
// ??? gUnk_085D3634
// ??? gUnk_085D364C
// ??? gUnk_085D3664
// ??? gUnk_085D36A4
// ??? gUnk_085D36BC
// ??? gUnk_085D36D4
// ??? gUnk_085D36EC
// ??? gUnk_085D3704
// ??? gUnk_085D371C
// ??? gUnk_085D373C
// ??? gUnk_085D3754
// ??? gUnk_085D376C
// ??? gUnk_085D3784
// ??? gUnk_085D379C
// ??? gUnk_085D37B4
// ??? gUnk_085D38A4
// ??? gUnk_085D38BC
// ??? gUnk_085D38D4
// ??? gUnk_085D38E4
// ??? gUnk_085D3904
// ??? gUnk_085D3924
// ??? gUnk_085D394C
// ??? gUnk_085D3964
// ??? gUnk_085D3994
// ??? gUnk_085D39AC
// ??? gUnk_085D39D4
// ??? gUnk_085D39EC
// ??? gUnk_085D39F4
// ??? gUnk_085D3A14
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
// ??? gUnk_085D4264
// ??? gUnk_085D4274
// ??? gUnk_085D42F0
// ??? gUnk_085D4300
// ??? gUnk_085D44E4
// ??? gUnk_085D4738
// ??? gUnk_085D4998
// ??? gUnk_085D4BF8
// ??? gUnk_085D4CFC
// ??? gUnk_085D4D98
// ??? gUnk_085D5590
// ??? gUnk_085D55C0
// ??? gUnk_085D6218
// ??? gUnk_085D6E78
// ??? gUnk_085D7190
// ??? gUnk_085D71D8
// ??? gUnk_085D74FC
// ??? gUnk_085D7544
// ??? gUnk_085D77E4
// ??? gUnk_085D77F4
// ??? gUnk_085D7A40
// ??? gUnk_085D7A50
// ??? gUnk_085D8608
// ??? gUnk_085D9208
// ??? gUnk_085D9E38
// ??? gUnk_085DAA68
// ??? gUnk_085DB6A4
// ??? gUnk_085DC850
// ??? gUnk_085DC954
// ??? gUnk_085DC97C
// ??? gUnk_085DDAF0
// ??? gUnk_085DDBF4
// ??? gUnk_085DDC1C
// ??? gUnk_085DEDC0
// ??? gUnk_085DEEC4
// ??? gUnk_085DEEEC
// ??? gUnk_085E0090
// ??? gUnk_085E0194
// ??? gUnk_085E01BC
// ??? gUnk_085E0280
// ??? gUnk_085E0324
// ??? gUnk_085E03C8
// ??? gUnk_085E046C
// ??? gUnk_085E0510
// ??? gUnk_085E05B4
// ??? gUnk_085E0748
// ??? gUnk_085E08DC
// ??? gUnk_085E0A88
// ??? gUnk_085E0C34
// ??? gUnk_085E0DE0
// ??? gUnk_085E0F88
// ??? gUnk_085E19DC
// ??? gUnk_085E2508
// ??? gUnk_085E2920
// ??? gUnk_085E294C
// ??? gUnk_085E2CA8
// ??? gUnk_085E2CD4
// ??? gUnk_085E3AA4
// ??? gUnk_085E48C4
// ??? gUnk_085E5858
// ??? gUnk_085E5C10
// ??? gUnk_085E5C2C
// ??? gUnk_085E5C34
// ??? gUnk_085E5C3C
// ??? gUnk_085E5C44
// ??? gUnk_085E79F8
// ??? gUnk_085E7A64
// ??? gUnk_085E7AC4
// ??? gUnk_085E7ACC
// ??? gUnk_085E90AC
// ??? gUnk_085E9160
// ??? gUnk_085EA7F0
// ??? gUnk_085EA8A4
// ??? gUnk_085EABC0
// ??? gUnk_085EAC34
// ??? gUnk_085EADB0
// ??? gUnk_085EB1A8
// ??? gUnk_085EB1DC
// ??? gUnk_085EB264
// ??? gUnk_085EB83C
// ??? gUnk_085EBF40
// ??? gUnk_085EBF50
// ??? gUnk_085EBF58
// ??? gUnk_085EBF60
// ??? gUnk_085EC478
// ??? gUnk_085EC630
// ??? gUnk_085EC938
// ??? gUnk_085ECC34
// ??? gUnk_085ED8CC
// ??? gUnk_085ED8F8
// ??? gUnk_085ED924
// ??? gUnk_085EDCC8
// ??? gUnk_085F0A14
// ??? gUnk_085F0AA4
// ??? gUnk_085F1FC0
// ??? gUnk_085F2034
// ??? gUnk_085F35C0
// ??? gUnk_085F3634
// ??? gUnk_085F63A8
// ??? gUnk_085F6674
// ??? gUnk_085F9358
// ??? gUnk_085FE3C4
// ??? gUnk_085FE544
// ??? gUnk_085FEAF8
// ??? gUnk_085FEB0C
// ??? gUnk_085FEB20
// ??? gUnk_085FEB34
// ??? gUnk_085FEB48
// ??? gUnk_085FEEBC
// ??? gUnk_085FEEC8
// ??? gUnk_085FEED4
// ??? gUnk_085FEEE0
// ??? gUnk_085FEEEC
// ??? gUnk_08602FAC
// ??? gUnk_086030FC
// ??? gUnk_08603B1C
// ??? gUnk_08603B24
// ??? gUnk_08603B2C
// ??? gUnk_08603B34
// ??? gUnk_08603B58
// ??? gUnk_08603BA4
// ??? gUnk_08603BC0
extern CONST_DATA struct ProcScr ProcScr_EkrDragonMoveBg3[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonBark[];
extern CONST_DATA struct ProcScr ProcScr_EkrManakete[];
extern CONST_DATA struct ProcScr ProcScr_EkrManaketeEnterfx[];
extern CONST_DATA struct ProcScr ProcScr_EkrManaketeExitfx[];
extern CONST_DATA struct ProcScr ProcScr_EkrManaketefx[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonFae[];
extern CONST_DATA struct ProcScr ProcScr_EkrFaefx[];
extern const u16 * CONST_DATA TsaLut_EkrFaefx[];
extern CONST_DATA struct ProcScr ProcScr_EkrDragonIdunn[];
// ??? gUnk_08604948
// ??? gUnk_08604968
// ??? gUnk_08604988
// ??? gUnk_086049A8
extern CONST_DATA struct ProcScr ProcScr_EkrIdunnDeamon[];
// ??? gUnk_086049E8
extern CONST_DATA struct ProcScr ProcScr_EkrIdunnBodyFlashing[];
// ??? gUnk_08604A18
// ??? gUnk_08604A3C
// ??? gUnk_08604A6C
// ??? gUnk_08604A9C
// ??? gUnk_08604ACC
extern AnimScr AnimScr_ManaketeEnter1[];
extern AnimScr AnimScr_ManaketeExit3[];
extern AnimScr AnimScr_ManaketeEnter2[];
extern AnimScr AnimScr_ManaketeExit2[];
extern AnimScr AnimScr_ManaketeEnter3[];
extern AnimScr AnimScr_ManaketeExit1[];
// ??? AnimScr_EkrIdunnDeamon
// ??? gUnk_08605A70
extern i16 gUnk_08605A94[];
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
extern CONST_DATA struct ProcScr FaceConfig_EkrLevelup[];
extern CONST_DATA struct ProcScr ProcScr_EkrLevelup[];
// ??? gUnk_08606254
// ??? gUnk_0860626C
// ??? gUnk_0860628C
// ??? gUnk_086062AC
// ??? gUnk_086062EC
extern CONST_DATA struct ProcScr ProcScr_EkrTriangle[];
// ??? gUnk_0860632C
// ??? gUnk_08606344
// ??? gUnk_0860635C
// ??? gUnk_08606374
// ??? gUnk_0860638C
// ??? gUnk_086063A4
// ??? gUnk_086063BC
// ??? gUnk_086063DC
// ??? gUnk_086068A4
// ??? gUnk_08606BD8
// ??? gUnk_08606C70
// ??? gUnk_08606D00
// ??? gUnk_08606D90
// ??? gUnk_08606E1C
// ??? gUnk_08606F0C
// ??? gUnk_08607084
// ??? gUnk_086071D8
// ??? gUnk_086074A0
// ??? gUnk_08607504
// ??? gUnk_08607660
// ??? gUnk_08607668
