#pragma once

#include "prelude.h"

#include "event.h"

#include "constants/flags.h"

enum { EVENT_NOSCRIPT = 1 };

enum { MAX_CHAPTER_FLAGS = 32 };
enum { MAX_PERMANENT_FLAGS = 40 };

enum
{
    TILE_COMMAND_NONE,

    TILE_COMMAND_VISIT    = 0x0E,
    TILE_COMMAND_SEIZE    = 0x0F,
    TILE_COMMAND_DOOR     = 0x10,
    TILE_COMMAND_BRIDGE   = 0x11,
    TILE_COMMAND_CHEST    = 0x12,
    TILE_COMMAND_ARMORY   = 0x13,
    TILE_COMMAND_VENDOR   = 0x14,
    TILE_COMMAND_SECRET   = 0x15,
    TILE_COMMAND_SHOP_UNK = 0x16,

    TILE_COMMAND_PILLAGE  = 0x1D,
};

// NOTE: this uses the RNG that is usually used for aesthetic purposes
// this means that random events will not be the same accross suspend reloads
#define EventRandNext_N(upper_bound) (DivRem(RandNextB(), (upper_bound)))

typedef uptr EventListScr;

struct EventInfo
{
    /* 00 */ EventListScr const * list_script;
    /* 04 */ void const * script; // could be EventScr, could be item list, could be "1"...
    /* 08 */ u32 flag;
    /* 0C */ u32 tile_command;
    /* 10 */ u32 given_money;
    /* 14 */ u32 given_iid;
    /* 18 */ i8 x_location;
    /* 19 */ i8 y_location;
    /* 1A */ u8 pid_a;
    /* 1B */ u8 pid_b;
};

struct SupportTalkEnt
{
    /* +00 */ u8 pid_a, pid_b;
    /* +02 */ // pad
    /* +04 */ u32 msg_talk_c;
    /* +08 */ u32 msg_talk_b;
    /* +0C */ u32 msg_talk_a;
};

struct BattleTalkExtEnt
{
    /* 00 */ u8 pid_a;
    /* 01 */ u8 pid_b;
    /* 02 */ u8 chapter;
    /* 03 */ // pad
    /* 04 */ u32 msg;
    /* 08 */ u32 flag;
};

struct BattleTalkEnt
{
    /* 00 */ u8 pid;
    /* 01 */ u8 chapter;
    /* 02 */ // pad
    /* 04 */ u32 msg;
    /* 08 */ u32 flag;
    /* 0C */ u32 unk_0C;
};

struct Unk_0867619C
{
    /* 00 */ u16 msg;
    /* 02 */ u8 y_offset;
};

extern struct Unk_0867619C CONST_DATA gUnk_0867619C[];

struct UnkProc0806D82C
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x4C);
    /* 4C */ i16 unk_4C;
};

struct UnkProc_08676854
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 unk_64;
};

struct UnkProc_0867686C
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 unk_64;
};

struct HardModeBonusLevelsOverrideEnt
{
    /* 00 */ u8 pid;
    /* 04 */ int bonus_levels;
};

extern struct HardModeBonusLevelsOverrideEnt CONST_DATA gHardModeBonusLevelsOverrideList[];

struct UnkProc_0806DDC4
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x44);
    /* 44 */ u8 unk_44;
    /* 45 */ u8 unk_45;
};

struct UnkProc_086768C4
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ u16 unk_64;
};

extern struct ProcScr CONST_DATA ProcScr_Unk_086768C4[];

struct UnkProc_086768DC
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x4C);
    /* 4C */ ProcPtr unk_4C;
    /* 50 */ STRUCT_PAD(0x50, 0x64);
    /* 64 */ i16 unk_64;
};

struct UnkProc_086768FC
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 unk_64;
};

struct UnkProc_08676914
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 unk_64;
    /* 66 */ i16 unk_66;
};

struct Unk_0867692C { u8 x, y; u16 more; };

extern struct Unk_0867692C CONST_DATA gUnk_0867692C[];
extern struct Unk_0867692C CONST_DATA gUnk_0867695C[];

struct UnkProc_08677348
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ int unk_2C;
    /* 30 */ int unk_30;
    /* 34 */ int unk_34;
    /* 38 */ int unk_38;
    /* 3C */ i8 const * unk_3C;
    /* 40 */ int unk_40;
};

void StartEventFromInfo(struct EventInfo const * info);
struct EventInfo * SearchAvailableEvent(struct EventInfo * info);
struct EventInfo * SearchNextAvailableEvent(struct EventInfo * info);
int EvtListCmd_End(struct EventInfo * info);
int EvtListCmd_Flag(struct EventInfo * info);
int EvtListCmd_Turn(struct EventInfo * info);
int EvtListCmd_TurnHard(struct EventInfo * info);
int EvtListCmd_Talk(struct EventInfo * info);
int EvtListCmd_Tile(struct EventInfo * info);
int EvtListCmd_TileWithMapChange(struct EventInfo * info);
int EvtListCmd_ItemChest(struct EventInfo * info);
int EvtListCmd_Door(struct EventInfo * info);
int EvtListCmd_Drawbridge(struct EventInfo * info);
int EvtListCmd_Shop(struct EventInfo * info);
int EvtListCmd_Area(struct EventInfo * info);
int EvtListCmd_AreaHard(struct EventInfo * info);
int EvtListCmd_Func(struct EventInfo * info);
bool EventInfoCheckTalk(struct EventInfo * info, fu8 pid_a, fu8 pid_b);
int CheckActiveUnitArea(int x1, int y1, int x2, int y2);
bool CheckAnyBlueUnitArea(int x1, int y1, int x2, int y2);
bool func_fe6_0806AD48(struct EventInfo * info);
bool func_fe6_0806AD74(struct EventInfo * info);
bool func_fe6_0806ADC4(struct EventInfo * info);
bool func_fe6_0806ADDC(struct EventInfo * info);
bool func_fe6_0806AE04(struct EventInfo * info);
bool func_fe6_0806AE2C(struct EventInfo * info);
bool func_fe6_0806AE54(struct EventInfo * info);
bool func_fe6_0806AE7C(int x1, int y1, int x2, int y2);
bool CheckAvailableTurnEvent(void);
void StartAvailableTurnEvents(void);
bool CheckAvailableTalkEvent(fu8 pid_a, fu8 pid_b);
void StartAvailableTalkEvent(fu8 pid_a, fu8 pid_b);
void StartAvailableSupportEvent(fu8 pid_a, fu8 pid_b, int support_level);
int GetAvailableTileEventCommand(fi8 x, fi8 y);
void StartAvailableTileEvent(fi8 x, fi8 y);
void StartAvailableTileEvent_Unused(fi8 x, fi8 y);
bool CheckAvailableVisitTileEvent(fi8 x, fi8 y);
void StartAvailableVisitTileEvent(fi8 x, fi8 y);
bool CheckAvailableShopTileEvent(fi8 x, fi8 y);
void StartAvailableShopTileEvent(fi8 x, fi8 y);
bool CheckAvailableChestTileEvent(fi8 x, fi8 y);
void StartAvailableChestTileEvent(fi8 x, fi8 y);
bool CheckAvailableDoorTileEvent(fi8 x, fi8 y);
void StartAvailableDoorTileEvent(fi8 x, fi8 y);
bool CheckAvailableBridgeTileEvent(fi8 x, fi8 y);
void StartAvailableBridgeTileEvent(fi8 x, fi8 y);
bool CheckAvailableVictoryEvent(void);
void StartAvailableVictoryEvent(void);
bool StartAvailableMoveSelectEvent(void);
bool CheckAvailableActionSelectEvent(void);
bool StartAvailableActionSelectEvent(void);
bool CheckAvailableMoveSelectConfirmEvent(void);
bool StartAvailableMoveSelectConfirmEvent(void);
bool StartAvailableAttackMenuEvent(void);
bool StartAvailableAttackMenuItemEvent(void);
bool StartAvailableMapMenuEvent(void);
bool CheckAvailableMoveEvent(void);
void StartAvailableMoveEvent(void);
bool CheckChapterVictory(void);
void StartChapterVictoryEvent(void);
void CreateInitialRedUnits(void);
struct UnitInfo const * GetDeployUnitInfoList(void);
struct BattleTalkEnt const * GetAvailableBattleTalkExt(fu8 pid_a, fu8 pid_b);
struct BattleTalkEnt const * GetAvailableBattleTalk(fu8 pid, struct BattleTalkEnt const * it);
bool CheckBattleTalk(fu8 pid_a, fu8 pid_b);
void StartBattleTalk(fu8 pid_a, fu8 pid_b);
bool CheckBattleDefeatTalk(fu8 pid);
void StartBattleDefeatTalk(fu8 pid);
bool func_fe6_0806B898(void);
void func_fe6_0806B89C(void);
void func_fe6_0806B8A0(void);
bool func_fe6_0806B8A4(void);
void func_fe6_0806B8A8(void);
bool func_fe6_0806B8AC(void);
bool func_fe6_0806B8B0(void);
void func_fe6_0806B8B4(void);
void func_fe6_0806B8B8(void);
void func_fe6_0806B8BC(void);
void func_fe6_0806B8C0(void);
void func_fe6_0806B8C4(void);
void SetChapterFlag(int flag);
bool CheckChapterFlag(int flag);
void ClearChapterFlag(int flag);
void ResetChapterFlags(void);
void SetPermanentFlag(int flag);
bool CheckPermanentFlag(int flag);
void ClearPermanentFlag(int flag);
void ResetPermanentFlags(void);
void SetFlag(int flag);
bool CheckFlag(int flag);
void ClearFlag(int flag);
u8 * GetPermanentFlagBits(void);
int GetPermanentFlagBitsSize(void);
u8 * GetChapterFlagBits(void);
int GetChapterFlagBitsSize(void);

extern u8 gChapterFlagBits[(MAX_CHAPTER_FLAGS + CHAR_BIT - 1) / CHAR_BIT];
extern u8 gPermanentFlagBits[(MAX_PERMANENT_FLAGS + CHAR_BIT - 1) / CHAR_BIT];

extern u16 const gUnk_08342A98[]; // colors
extern struct ProcScr CONST_DATA ProcScr_Unk_08676220[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08676844[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08676854[];
extern struct ProcScr CONST_DATA ProcScr_Unk_0867686C[];
extern u8 gUnk_030048A8;
extern u32 EWRAM_DATA gUnk_0203D354;
extern u32 EWRAM_DATA gUnk_0203D358;
extern u8 EWRAM_DATA gUnk_0203D35C;
extern u8 EWRAM_DATA gUnk_0203D35D;
extern u8 EWRAM_DATA gUnk_0203D360;
extern u8 EWRAM_DATA gUnk_0203D361;
extern u8 EWRAM_DATA gUnk_0203D362;
extern u16 EWRAM_DATA gUnk_0203D364;
extern struct ProcScr CONST_DATA ProcScr_Unk_08677FE0[];
extern u32 EWRAM_DATA gUnk_0203D368;
extern u32 EWRAM_DATA gUnk_0203D36C;
extern struct Text EWRAM_DATA gUnkText_0203D370[];
extern struct Text EWRAM_DATA gUnkText_0203D3A0;
extern struct ProcScr CONST_DATA ProcScr_Unk_0867688C[];
extern struct ProcScr CONST_DATA ProcScr_Unk_086768DC[];
extern EventScr const * CONST_DATA gUnk_086770D4[];
extern u8 EWRAM_DATA gUnk_0203D3D8; // ending related value
extern u8 EWRAM_DATA gUnk_0203D3D9; // ending id
extern EventScr const * CONST_DATA gUnk_08676738[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08677348[];
extern struct ProcScr CONST_DATA ProcScr_Unk_086768FC[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08676914[];
extern u8 gUnk_030048A4; // COMMON
extern u8 gUnk_030048B8; // COMMON
extern u8 const gUnk_0834B69C[]; // img
extern u8 const gUnk_08349A98[]; // img
extern u8 const gUnk_0834E1D4[]; // img
extern u8 const gUnk_08352160[]; // img
extern i8 CONST_DATA gUnk_086772FC[];
extern i8 CONST_DATA gUnk_0867730C[];
extern i8 CONST_DATA gUnk_0867731C[];
extern i8 CONST_DATA gUnk_08677327[];
extern struct ProcScr CONST_DATA ProcScr_Unk_08677378[];

extern u8 const gUnk_0836F6D4[]; // img
extern u8 const gUnk_08373F80[]; // tm
extern u8 const gUnk_08374670[]; // compressed pal
extern u16 const gUnk_08353308[]; // pal
extern u16 CONST_DATA gUnk_08677360[]; // bg config
extern i8 EWRAM_DATA gUnk_0203DCA7[];
