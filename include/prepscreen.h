#pragma once

#include "prelude.h"
#include "unit.h"

enum
{
    PREPMENU_FLAG_MULTIARENA = 1 << 0,
};

enum
{
    L_PREPMENU_5 = 0x05,
    L_PREPMENU_6 = 0x06,
    L_PREPMENU_B = 0x0B,
};

enum prepscreen_text_idx {
    TEXT_PREP_PICK_LEFT_BAR = 0,
};

enum prepscreen_videoalloc {
    BGCHR_PREPMENU_230 = 0x230,
    BGCHR_PREPMENU_240 = 0x240,
    BGCHR_PREPMENU_700 = 0x700,

    OBCHR_PREPMENU_240 = 0x240,
    OBCHR_PREPMENU_380 = 0x380,
    OBCHR_PREPMENU_390 = 0x390,

    BGPAL_PREPMENU_2 = 0x02,
    BGPAL_PREPMENU_A = 0x0A,
    BGPAL_PREPMENU_E = 0x0E,
    BGPAL_PREPMENU_F = 0x0F,

    OBPAL_PREPMENU_0 = 0x00,
    OBPAL_PREPMENU_2 = 0x02,
    OBPAL_PREPMENU_4 = 0x04,
    OBPAL_PREPMENU_5 = 0x05,
    OBPAL_PREPMENU_6 = 0x06,
    OBPAL_PREPMENU_D = 0x0D,
};

struct UnkProc_08678E18;
struct PrepScreenDispProc;
struct PrepSubItemProc;

enum PREP_SUB2_ACTION_IDX {
    PREP_SUB2ACT_NONE,
    PREP_SUB2ACT_1,
    PREP_SUB2ACT_TRADE_ITEM = 2,
    PREP_SUB2ACT_CONVOY,
    PREP_SUB2ACT_DISCARD_ITEM,
    PREP_SUB2ACT_CHECK_ALL_ITEM,
    PREP_SUB2ACT_STATSCREEN,
    PREP_SUB2ACT_SAVEMENU,
    PREP_SUB2ACT_8,
    PREP_SUB2ACT_9,
    PREP_SUB2ACT_ARMORY,
};

struct PrepMenuProc
{
    /* 00 */ PROC_HEADER;
    /* 29 */ u8 unk_29;
    /* 2A */ u8 in_unit_sel_screen;
    /* 2B */ u8 unk_2B;
    /* 2C */ u8 link_arena_flag;
    /* 2D */ u8 unk_2D; // size of gPrepUnitList?
    /* 2E */ u8 max_counter;
    /* 2F */ u8 cur_counter;
    /* 30 */ u8 list_num_cur; // id within gPrepUnitList
    /* 31 */ u8 unk_31;
    /* 32 */ u8 unk_32;
    /* 33 */ u8 disp_idx[2];
    /* 35 */ u8 submenu_level;
    /* 36 */ i8 hand_y_pos;
    /* 37 */ u8 unk_37; // i8 also?
    /* 38 */ u8 unk_38;
    /* 39 */ u8 unk_39;
    /* 3A */ u8 unk_3A;
    /* 3B */ u8 sub2_action;
    /* 3C */ u8 a_button_actions; // Bit1:selection unit, Bit2:Start battle
    /* 3D */ u8 do_help;
    /* 3E */ u8 end_prep;
    /* 3F */ u8 unk_3F;
    /* 40 */ u16 unk_40;
    /* 42 */ u16 scroll_timer;
    /* 44 */ u16 yDiff_cur;
    /* 46 */ STRUCT_PAD(0x46, 0x48);
    /* 48 */ struct Unit * unit1, * unit2;
    /* 50 */ struct PrepScreenDispProc * disp_proc;
    /* 54 */ STRUCT_PAD(0x54, 0x58);
    /* 58 */ ProcPtr procbg;
    /* 5C */ struct UnkProc_08678E18 * unk_5C;
    /* 60 */ ProcPtr unk_60;
};

struct PrepSubItemfxProc {
    PROC_HEADER;

    u8 unk_29;
    u8 unk_2A[3];
    u8 unk_2D; // pad
    u16 unk_2E;
    u16 unk_30;
    u16 unk_32;
    u8 unk_34;
    u8 unk_35; // pad

    u16 unk_36;
    u16 unk_38;
};

struct PrepSubItemProc {
    PROC_HEADER_EXT(struct PrepMenuProc);

    STRUCT_PAD(0x29, 0x2B);

    /* 2B */ u8 unk2B;
    /* 2C */ u8 unk2C, unk2D;
    /* 2E */ u8 unk2E, unk2F;
    /* 30 */ u8 unk30, unk31;

    STRUCT_PAD(0x32, 0x46);

    /* 46 */ u8 unk46;

    STRUCT_PAD(0x47, 0x50);

    /* 50 */ u16 unk50;
    /* 54 */ struct Unit * unit;

    STRUCT_PAD(0x58, 0x60);

    /* 60 */ ProcPtr unk60;
};

#define SYDIFF(proc) (*((i16 *)&(proc)->yDiff_cur))

struct UnkProc_08678DE0
{
    /* 00 */ PROC_HEADER_EXT(struct PrepMenuProc);
    /* 29 */ STRUCT_PAD(0x29, 0x30);
    /* 30 */ u16 unk_30;
};

struct UnkProc_08678E00
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x48);
    /* 48 */ struct Unit * unit;
};

struct UnkProc_08678E18
{
    /* 00 */ PROC_HEADER_EXT(struct PrepMenuProc);
    /* 29 */ STRUCT_PAD(0x29, 0x2C);
    /* 2C */ struct Unit * unit;
    /* 30 */ struct PrepMenuProc * main_proc;
    /* 34 */ u8 unk_34;
    /* 35 */ u8 unk_35;
};

struct PrepScreenDispProc
{
    /* 00 */ PROC_HEADER_EXT(struct PrepMenuProc);
    /* 29 */ u8 unk_29;
    /* 2A */ u8 unk_2A;
    /* 2B */ u8 unk_2B;
    /* 2C */ u8 unk_2C;
    /* 2D */ u8 unk_2D;
    /* 2E */ u8 unk_2E;
    /* 2F */ u8 unk_2F;
    /* 30 */ u8 unk_30;
    /* 31 */ u8 unk_31;
    /* 32 */ u8 unk_32;
    /* 33 */ u8 unk_33;
    /* 34 */ u8 cursor_x, cursor_y;
    /* 36 */ u8 unk36, chidx;
    /* 38 */ u8 disp_x, disp_y;
    /* 3A */ u16 unk_3A;
    /* 3C */ u16 unk_3C;
    /* 3E */ u16 unk_3E;
    /* 40 */ u16 unk_40;
    /* 42 */ u8 unk_42;
    /* 43 */ u8 pre;
    /* 44 */ u8 unk_44;
    /* 46 */ u16 unk_46;
    /* 48 */ u16 unk_48;
};

struct PrepMenuProcBug {
    STRUCT_PAD(0, 0x34);
    u16 _bug_34;
};

extern struct Unit * gPrepUnitList[];
#define GetUnitFromPrepList(index) (gPrepUnitList[(index)])
#define RegisterPrepUnitList(index, unit) (gPrepUnitList[(index)] = (unit))

extern u8 gPrepMenuItemCnt;

void ResetSioPidPool(void);
void RegisterSioPid(fu8 pid);
void RemoveSioPid(fu8 pid);
void func_fe6_0807921C(void);
void func_fe6_08079250(struct UnkProc_08678DE0 *proc);
void func_fe6_080792C8(struct UnkProc_08678DE0 *proc);
void func_fe6_08079388(struct UnkProc_08678DE0 *proc);
void func_fe6_080793F0(struct PrepMenuProc * parent);
bool IsUnitMandatoryDeploy(struct Unit * unit);
void InitPrepScreenMainMenu(struct PrepMenuProc *proc);
void PrepUnit_DrawLeftUnitInfo(struct Unit * unit, u16 * tm);
void PrepScreen_ReloadLeftUnitInfo(struct Unit * unit);
void func_fe6_0807979C(struct UnkProc_08678E00 *proc);
void func_fe6_080797DC(struct PrepMenuProc * parent);
void func_fe6_08079804(struct PrepMenuProc *proc);
void func_fe6_080798EC(struct PrepMenuProc *proc);
void func_fe6_08079928(struct PrepMenuProc *proc, int unit_id_or_pid, bool by_pid);
void ReorderPlayerUnitsBasedOnDeployment(void);
void func_fe6_08079A94(struct PrepMenuProc *proc);
void func_fe6_08079BC8(struct UnkProc_08678E18 *proc);
void func_fe6_08079C38(struct UnkProc_08678E18 *proc);
struct UnkProc_08678E18 * func_fe6_08079D70(struct PrepMenuProc * parent);
void func_fe6_08079D84(struct PrepMenuProc *proc);
void PrepUnit_DrawPickLeftBar(struct PrepMenuProc *proc);
void PrepUnit_DrawUnitListNames(struct PrepMenuProc *proc, fu8 row);
void RearrangeMandatoryDeployUnits(void);
void SioResetUnitItems(void);
void func_fe6_0807A1C8(struct PrepMenuProc *proc, bool load_sprites);
void PrepMenu_InitScreenExt(struct PrepMenuProc *proc);
void PrepMenu_InitScreen(struct PrepMenuProc *proc);
void PrepScreen_DrawScreenInfo(struct PrepMenuProc *proc);
void PrepMenu_InitExt(struct PrepMenuProc *proc);
fi8 PrepUnitSel_Loop(struct PrepMenuProc *proc);
void PrepSubMenu_FinishMoving(struct PrepMenuProc *proc);
void PrepMenu_CancelAction(struct PrepMenuProc *proc);
void func_fe6_0807ACE8(struct PrepMenuProc *proc);
void PrepMenu_EndIfNoUnit(struct PrepMenuProc *proc);
void PrepMenu_Init(struct PrepMenuProc *proc);
void PrepMenu_Loop(struct PrepMenuProc *proc);
// AtMenu_SetEndFlag
// AtMenu_ResetBmUiEffect
// PrepUnit_HandleScrollUp
// PrepUnit_HandleScrollDown
// AtMenu_StartSubmenu
// AtMenu_OnSubmenuEnd
// PrepScreen_ReloadLeftUnitInfoFromStatscreen
// func_fe6_0807B4C0
// func_fe6_0807B5A0
// func_fe6_0807B69C
void StartPrepAtMenu(void);
// StartSioPrepMenu

struct ProcPrepFade {
    PROC_HEADER;
    STRUCT_PAD(0x29, 0x42);
    u16 timer;
};

void PrepMenuFade_Init(struct ProcPrepFade *proc);
void PrepMenuFadeOut_Loop(struct ProcPrepFade *proc);
void PrepMenuFadeIn_Loop(struct ProcPrepFade *proc);
void StartPrepMenuFadeOut(ProcPtr proc);
void StartPrepMenuFadeIn(ProcPtr proc);

void func_fe6_0807B8B0(struct PrepScreenDispProc *proc, int idx);
void PrepDisp_SetWorlMapInfo(struct PrepScreenDispProc *proc, fu8 x, fu8 y, int chidx);
void PrepDisp_PutPickLeftBar(u8 a, u8 b, int c);
void PrepUnit_DrawSMSAndObjs(struct PrepScreenDispProc *proc);
void PrepMenu_DrawGmapSprites(struct PrepScreenDispProc *proc);
void PrepDisp_PutHand(struct PrepScreenDispProc *proc);
void func_fe6_0807BF70(struct PrepScreenDispProc *proc);
void PrepDisp_PutTitleSprite(struct PrepScreenDispProc *proc);
// PrepScreenDisp_Init
// PrepScreenDisp_Loop
// PrepScreenDisp_End
// PrepScreenDisp_Block
ProcPtr StartPrepScreenDisp(ProcPtr parent);

struct PrepMenuItem {
    /* 00 */ void (* func)(struct PrepMenuProc *proc);
    /* 04 */ int desc;
    /* 08 */ u8 color;
    /* 09 */ fu8 is_submenu;
    /* 0C */ int name;
    /* 10 */ u8 index;
    /* 14 */
};

enum PrepMenuItemIndex {
    /* PrepMenuItem::index */
    PREPMENUITEM_UNITSEL,
    PREPMENUITEM_ITEMSEL,
    PREPMENUITEM_2,
    PREPMENUITEM_SAVE,
    PREPMENUITEM_CHECKMAP,
    PREPMENUITEM_TRADE,
    PREPMENUITEM_DISCARD,
    PREPMENUITEM_CONVOY,
    PREPMENUITEM_ALLITEMS,
    PREPMENUITEM_SHOP,
    PREPMENUITEM_AUGURY,
    PREPMENUITEM_11,
    PREPMENUITEM_STARTBATTLE,

    PREPMENUITEM_INVALID = 0xFF,
};

extern struct PrepMenuItem gPrepMenuItems[0x10];

// func_fe6_0807C520
void PrepScreenMenu_OnPickUnits(struct PrepMenuProc *proc);
void PrepScreenMenu_OnItems(struct PrepMenuProc *proc);
void func_fe6_0807C840(struct PrepMenuProc *proc);
void PrepScreenSubMenu_OnTrade(struct PrepMenuProc *proc);
void PrepScreenSubMenu_OnDiscard(struct PrepMenuProc *proc);
void PrepScreenSubMenu_Convoy(struct PrepMenuProc *proc);
void PrepScreenSubMenu_AllItems(struct PrepMenuProc *proc);
void PrepScreenSubMenu_Shop(struct PrepMenuProc *proc);
// func_fe6_0807CAD4
void PrepScreenMenu_Augury(struct PrepMenuProc *proc);
// func_fe6_0807CB40
void PrepScreenMenu_OnSave(struct PrepMenuProc *proc);
void PrepScreenMenu_OnCheckMap(struct PrepMenuProc *proc);
void PrepScreenSubMenu_StartBattle(struct PrepMenuProc *proc);
void ResetPrepMenuItem(void);
void SetPrepScreenMenuItem(void(*func)(struct PrepMenuProc *proc), fu8 is_submenu, int name, fu8 color, int desc, fu8 index);
bool PrepMenuOnSelected(struct PrepMenuProc *proc);
fu8 GetPrepMenuItemAmount(fu8 arg_0);
void PutPrepScreenMenuItems(struct Text * text, fu8 arg_1, u16 * tm, fu8 arg_3);
void PrepMenuHelpbox(struct PrepMenuProc *proc);
u8 GetPrepScreenMenuCurrentItemIndex(struct PrepMenuProc *proc);
void SetPrepMenuItemUsability(u8 index, u8 color);
u8 GetPrepScreenMenuDispItemIndex(u8 disp_idx, fu8 is_submenu);

struct ProcPrepfx_08679368 {
    PROC_HEADER;

    STRUCT_PAD(0x29, 0x34);

    /* 34 */ struct Text * text1;

    STRUCT_PAD(0x38, 0x3c);

    /* 3C */ struct Text * text2;

    STRUCT_PAD(0x40, 0x44);

    /* 3C */ struct Text * text3;
};

void func_fe6_0807CF78(struct ProcPrepfx_08679368 *proc);
void func_fe6_0807CFA0(struct ProcPrepfx_08679368 *proc);
// func_fe6_0807CFA4
void dummy_0807CFB8(int a, int b, int c);

struct ProcPrepfx_086793A8 {
    PROC_HEADER_EXT(struct PrepSubItemProc);

    /* 2A */ u16 timer;
    /* 2C */ ProcPtr procfx;
    /* 30 */ int obj_offset;
};

void func_fe6_0807CFBC(struct ProcPrepfx_086793A8 *proc);
void func_fe6_0807CFDC(struct ProcPrepfx_086793A8 *proc);
ProcPtr func_fe6_0807D074(ProcPtr parent);

void func_fe6_0807D088(struct ProcPrepfx_086793A8 *proc);
void func_fe6_0807D0A8(struct ProcPrepfx_086793A8 *proc);
// func_fe6_0807D16C
void func_fe6_0807D180(struct ProcPrepfx_086793A8 *proc);
void func_fe6_0807D1AC(struct ProcPrepfx_086793A8 *proc);
// func_fe6_0807D2E0
// func_fe6_0807D2F4
// func_fe6_0807D338
// func_fe6_0807D358
// func_fe6_0807D4A8
// func_fe6_0807D6C0
// func_fe6_0807D834
// func_fe6_0807D9E4
// func_fe6_0807DB80
// func_fe6_0807DCB8
// func_fe6_0807DDC8
// func_fe6_0807DE60
// func_fe6_0807DEC8
// func_fe6_0807DF60
void func_fe6_0807DFEC(u8 a, int timer, int obj_off);
// func_fe6_0807E06C

void func_fe6_0807E0D4(struct Proc *proc);
void func_fe6_0807E41C(struct Proc *proc);
// func_fe6_0807E544
void func_fe6_0807E5A8(struct Proc *proc);
void func_fe6_0807EB70(struct Proc *proc);
void func_fe6_0807EDBC(struct Proc *proc);
// func_fe6_0807FBE8
void func_fe6_0807FCFC(struct Proc *proc);
void func_fe6_0807FF98(struct Proc *proc);
void func_fe6_08080284(struct Proc *proc);
void func_fe6_080813E8(struct Proc *proc);
void func_fe6_08081540(struct Proc *proc);

void StartPrepSubItemScreen(struct PrepMenuProc * parent, int type);
void func_fe6_080815E4(struct Unit * unit, ProcPtr parent);
void func_fe6_08081620(struct Unit * unit, ProcPtr parent);
// func_fe6_0808165C
// func_fe6_0808166C

struct ProcPrepDiscardScreen {
	PROC_HEADER;

	STRUCT_PAD(0x29, 0x2C);

	/* 2C */ u8 in_arena;
	/* 2D */ u8 unk_2D;
	/* 2E */ u8 y;
	/* 2F */ u8 unk_2F;
	/* 30 */ u8 x;
};

void PrepDiscard_Init(struct ProcPrepDiscardScreen *proc);
void PrepDiscard_Loop(struct ProcPrepDiscardScreen *proc);
void PrepDiscard_End(struct ProcPrepDiscardScreen *proc);
void StartPrepDiscardItemScreen(ProcPtr parent);

struct ProcPrepDiscardHand {
	PROC_HEADER_EXT(struct ProcPrepDiscardScreen);

	STRUCT_PAD(0x29, 0x52);

	u16 timer;
};

void PrepDiscardHand_Init(struct ProcPrepDiscardHand *proc);
void PrepDiscardHand_Loop(struct ProcPrepDiscardHand *proc);
ProcPtr NewPrepDiscardHand(ProcPtr parent);

struct MenuScrollBarProc {
    PROC_HEADER;

    /* 2A */ u16 xBase;
    /* 2C */ u8 yBase;
    /* 2D */ u8 numSegments;
    /* 2E */ u16 currentSegment;
    /* 30 */ u16 prevSegment;
    /* 32 */ u16 numTotalRows;
    /* 34 */ u8 numVisibleRows;
    /* 36 */ u16 oam2Chr;
    /* 38 */ u16 oam2Pal;
    /* 3A */ u8 topArrowFrameIdx;
    /* 3B */ u8 bottomArrowFrameIdx;
};

void MenuScroll_Init(struct MenuScrollBarProc *proc);
void MenuScroll_Loop(struct MenuScrollBarProc *proc);
ProcPtr StartMenuScrollBar(ProcPtr parent);
void func_fe6_08082320(struct PrepSubItemfxProc *proc, int a, int b, int c, int d, int e, int f);
void func_fe6_08082348(struct PrepSubItemfxProc *proc, int a, u8 b);
void func_fe6_08082360(struct Text *th, u16 *tm, int color, int x, const char *str);
void func_fe6_080823A0(u8 * a, u16 * b);

struct Proc_0867968C {
    PROC_HEADER;

    /* 2A */ u16 pos;
    /* 2C */ u8 timer;
};

void PrepBgScrolling_Init(struct Proc_0867968C *proc);
void PrepBgScrolling_Loop(struct Proc_0867968C *proc);
void PrepBgScrolling_End(struct Proc_0867968C *proc);
ProcPtr func_fe6_08082560(ProcPtr parent);

struct Win1H {
    /* 00 */ u8 left;
    /* 01 */ u8 right;
};

extern struct Win1H sSallyCirWinH_obj[2][160];
extern struct Win1H *sSallyCirWinH[2];

struct ProcSallyCir {
    PROC_HEADER;

    /* 29 */ u8 timer;
    /* 2A */ i8 direct;
    /* 2C */ int pos;
};

void SallyCir1_HBlank(void);
void SallyCir1_Init(struct ProcSallyCir *proc);
void SallyCir1_Loop(struct ProcSallyCir *proc);
void SallyCir1_End(struct ProcSallyCir *proc);
ProcPtr NewSallyCir1(ProcPtr parent, i8 direct);
void SallyCir2_Init(struct ProcSallyCir *proc);
void SallyCir2_Loop(struct ProcSallyCir *proc);
ProcPtr NewSallyCir2(ProcPtr parent, i8 direct);
u8 GetTotalSupplyItemCount(void);

struct ViewCounterProc {
    /* 00 */ PROC_HEADER;
    /* 2A */ u16 targetFrameCount;
    /* 2C */ u16 counter;
};

void ViewCounter_Loop(struct ViewCounterProc *proc);
void StartViewCounter(u16 frames, ProcPtr parent);
void TryLockProc(ProcPtr);
void TryUnlockProc(ProcPtr);
void PrepHbKeyListener_Loop(ProcPtr proc);
ProcPtr StartPrepErrorHelpbox(int x, int y, int msg, ProcPtr parent);
bool IsWeaponUsable(struct Unit *unit, int weapon);
int CountUnitUsableWeapons(struct Unit *unit);
bool CanUnitUseWeaponsInArena(struct Unit * unit);
// CheckValidLinkArenaItemSwap
// CheckValidLinkArenaItemSupply
// PrepCanUnitPutItemToSupply
void SetupPrepUiPalette(void);

struct Proc_Prep_08679774 {
    PROC_HEADER;

    /* 2C */ u16 *vram;
    /* 30 */ struct Font font;
    /* 48 */ struct Text text;
    /* 50 */ int oam2;
};

ProcPtr func_fe6_08082CF4(ProcPtr parent);
void func_fe6_08082D08(struct Proc_Prep_08679774 *proc, int unused_1, fu16 obpal);
void func_fe6_08082D54(struct Proc_Prep_08679774 *proc, int msg_order_idx);
void func_fe6_08082DA4(struct Proc_Prep_08679774 *proc, int x, int y, u32 scale);

extern struct Text gPrepScreenText_PickLeftBar;
extern struct Text gUnk_0200E864[];
extern struct Text gPrepScreenText_LeftPersonName;
extern u16 gUnk_0200E8A4[];
extern struct Unit gPrepUnitPool[]; // rearrange buf
extern struct Text gPrepScreenTexts_Units[];
extern u8 gUnk_0200E7D4;
extern struct Text gUnk_0200E88C[];
extern u16 gPrepFadePal[0x200];
extern u8 gUnk_020104A4[]; // img buf
extern int gPrepSubMenuIcons[];
extern u16 gUnk_0201636A;

extern CONST_DATA struct ProcScr ProcScr_AtMenu[];
extern CONST_DATA struct ProcScr ProcScr_PrepMenuFadeOut[];
extern CONST_DATA struct ProcScr ProcScr_PrepMenuFadeIn[];
extern CONST_DATA u16 Sprite_08679048[];
extern CONST_DATA u16 Sprite_08679050[];
extern CONST_DATA u16 Sprite_0867907A[];
extern CONST_DATA u16 Sprite_08679082[];
extern CONST_DATA u16 Sprite_0867908A[];
extern CONST_DATA u16 Sprite_08679098[];
extern CONST_DATA u16 Sprite_086790A0[];
extern CONST_DATA u16 Sprite_086790BA[];
extern CONST_DATA u16 Sprite_086790DA[];
extern CONST_DATA u16 Sprite_086790E2[];
extern CONST_DATA u16 Sprite_086790EA[];
extern CONST_DATA u16 Sprite_086790F2[];
extern CONST_DATA u16 Sprite_086790FA[];
extern CONST_DATA u16 Sprite_08679102[];
extern CONST_DATA u16 Sprite_0867910A[];
extern CONST_DATA u16 Sprite_08679112[];
extern CONST_DATA u16 Sprite_0867911A[];
extern CONST_DATA u16 Sprite_08679122[];
extern CONST_DATA u16 Sprite_0867912A[];
extern CONST_DATA u16 Sprite_08679132[];
extern CONST_DATA u16 * Sprites_0867913C[12];
extern CONST_DATA u16 Sprite_0867916C[];
extern CONST_DATA u16 Sprite_0867917A[];
extern CONST_DATA u16 Sprite_08679182[];
extern CONST_DATA u16 Sprite_086791A2[];
extern CONST_DATA u16 Sprite_086791B0[];
extern CONST_DATA u16 Sprite_086791BE[];
extern struct ProcScr ProcScr_PrepScreenDisp[];
// ??? HelpboxMsg_0867929C
extern CONST_DATA u16 Sprite_086792A8[];
extern CONST_DATA u16 Sprite_086792B6[];
extern CONST_DATA u16 Sprite_086792C4[];
extern CONST_DATA u16 Sprite_08679326[];
// ??? Sprites_08679330
// ??? gUnk_08679354
extern struct ProcScr ProcScr_08679368[];
extern struct ProcScr ProcScr_08679388[];
extern struct ProcScr ProcScr_086793A8[];
extern struct ProcScr ProcScr_086793C8[];
extern struct ProcScr ProcScr_PrepSubItemScreen[];
extern struct ProcScr ProcScr_08679490[];
extern struct ProcScr ProcScr_PrepDiscardItemScreen[];
extern struct ProcScr ProcScr_PrepDiscardHand[];
extern CONST_DATA u16 Sprite_08679578[];
extern CONST_DATA u16 Sprite_08679580[];
extern CONST_DATA u16 Sprite_MenuScrollContainer[];
extern CONST_DATA u16 Sprite_08679590[];
extern CONST_DATA u16 Sprite_08679598[];
// ??? MenuScrollBarSegmentSprites
// ??? MenuScrollArrowSprites
extern struct ProcScr ProcScr_menu_scroll[];
extern struct ProcScr ProcScr_PrepBgScrolling[];
extern struct ProcScr ProcScr_SallyCir1[];
extern struct ProcScr ProcScr_SallyCir2[];
extern struct ProcScr ProcScr_ViewCounter[];
extern struct ProcScr ProcScr_PrepErrorHelpboxLister[];
extern int Msgs_08679754[];
extern CONST_DATA u16 Sprite_Prep_0867976C[];
extern struct ProcScr ProcScr_Prep_08679774[];

extern u16 const gUnk_08320FCE[]; // tiles
extern u16 const gUnk_08326EE6[]; // tiles
extern u32 const gUnk_0831A268[]; // img(lz)
extern u32 const Img_SpinningArrow[]; // img(lz)
extern u32 const gUnk_08326930[]; // img(lz)
extern u16 const Pal_SpinningArrow[]; // pal
extern u16 const Pal_Sio_0831AABC[]; // pal (x2)
extern u16 const gUnk_08326E64[]; // pal (x4)
extern u16 const gUnk_08327108[]; // pal
extern u32 const gUnk_08321FA4[]; // img(lz)
extern u16 const gUnk_08326910[]; // pal
