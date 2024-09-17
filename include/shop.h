#pragma once

#include "prelude.h"
#include "proc.h"
#include "unit.h"
#include "text.h"

#define SHOP_ITEMS_MAX_AMT 20
#define SHOP_TEXT_LINES 5

enum ShopProcLabel {
    PL_SHOP_ENTRY = 0,
    PL_SHOP_BUY,
    PL_SHOP_BUY_MAIN,
    PL_SHOP_BUY_DONE,
    PL_SHOP_SELL,
    PL_SHOP_SELL_MAIN,
    PL_SHOP_6_UNUSED, // unused
    PL_SHOP_SELL_NOITEM,
    PL_SHOP_ANYTHING_ELSE,
    PL_SHOP_SENDTO_INVENTORY,
    PL_SHOP_SENDTO_INVENTORY_EXT,
    PL_SHOP_BUY_FULL_NO_INEVNTORY,
    PL_SHOP_EXIT,
};

struct ProcShop {
    /* 00 */ PROC_HEADER;

    /* 2C */ struct Unit * unit;
    /* 30 */ u16 shopItems[20];

    /* 58 */ u16 unk_58;

    /* 5A */ u8 shopItemCount;
    /* 5B */ u8 unitItemCount;
    /* 5C */ u8 head_loc;
    /* 5D */ u8 hand_loc;
    /* 5E */ u8 head_idx;
    /* 5F */ u8 hand_idx; // maybe top visible item in menu?
    /* 60 */ u8 buy_or_sel;
    /* 61 */ u8 shopType;
    /* 62 */ u8 helpTextActive;

    /* 64 */ i16 goldbox_x, goldbox_y, goldbox_oam2;
};

enum ShopType {
    /* ProcShop::shopType */
    SHOP_TYPE_ARMORY      = 0,
    SHOP_TYPE_VENDOR      = 1,
    SHOP_TYPE_SECRET_SHOP = 2,

    SHOP_TYPE_MAX
};

enum ShopStatus {
    /* ProcShop::buy_or_sel */
    SHOP_ST_BUY,
    SHOP_ST_SELL
};

struct ProcShopInit {
    /* 00 */ PROC_HEADER;

    STRUCT_PAD(0x29, 0x54);

    /* 54 */ struct ProcShop * shopproc;
};

extern struct Text gShopItemTexts[SHOP_TEXT_LINES + 1];

int GetShopFace(struct ProcShop * proc);
void StartShopDialogue(int msg, struct ProcShop * proc);
void StartDefaultArmoryScreen(struct Unit * unit, ProcPtr proc);
void StartArmoryScreenOrphaned(struct Unit * unit, u16 const * iid_list);
void StartVendorScreenOrphaned(struct Unit * unit, u16 const * iid_list);
void StartSecretShopScreenOrphaned(struct Unit * unit, u16 const * iid_list);
// StartArmoryScreen
void StartShopScreen(struct Unit * unit, const u16 * iid_list, u8 type, ProcPtr parent);
void UpdateShopItemCounts(struct ProcShop * proc);
void TalkChoice_OnBuy(void);
void TalkChoice_OnSell(void);
void Shop_EntryDialogue(struct ProcShop * proc);
void Shop_HandleEntryDialoguePrompt(struct ProcShop * proc);
void Shop_BuyDialogue(struct ProcShop * proc);
void ShopDrawBuyItemLine(struct ProcShop * proc, int list_idx);
void ShopDrawSellItemLine(struct ProcShop * proc, int list_idx);
void Shop_InitBuyState(struct ProcShop * proc);
void Shop_Loop_BuyKeyHandler(struct ProcShop * proc);
void Shop_HandleBuyConfirmPrompt(struct ProcShop * proc);
void Shop_TryAddItemToInventory(struct ProcShop * proc);
void Shop_HandleSendToConvoyPrompt(struct ProcShop * proc);
void Shop_NoSendToConvoyDialogue(struct ProcShop * proc);
void Shop_AddItemToConvoy(struct ProcShop * proc);
void Shop_SendToConvoyDialogue(struct ProcShop * proc);
void Shop_CheckIfConvoyFull(struct ProcShop * proc);
void Shop_ConvoyFullDialogue(struct ProcShop * proc);
void Shop_AnythingElseDialogue(struct ProcShop * proc);
void Shop_SellDialogue(struct ProcShop * proc);
void Shop_InitSellState(struct ProcShop * proc);
void Shop_Loop_SellKeyHandler(struct ProcShop * proc);
void Shop_HandleSellConfirmPrompt(struct ProcShop * proc);
void Shop_SellAnythingElseDialogue(struct ProcShop * proc);
void Shop_AnythingElseRestartDialogue(struct ProcShop * proc);
void Shop_AnythingElseContinueDialogue(struct ProcShop * proc);
void Shop_ExitShopDialogue(struct ProcShop * proc);
void Shop_OnExit(struct ProcShop * proc);
void StartShopFadeIn(struct ProcShop * proc);
void StartShopFadeOut(struct ProcShop * proc);
void func_fe6_08096B38(struct ProcShop * proc);
// StartUiGoldBox
// InitGoldBoxText
// ClearGoldBoxTextTm2Line
// DisplayGoldBoxText
void ShopInitTexts_OnBuy(struct ProcShop * proc);
// DrawShopSoldItems
void InitShopBuyStatus(struct ProcShopInit * proc);
void ShopInitTexts_OnSell(struct ProcShop * proc);
// func_fe6_08097354
void InitShopSellStatus(struct ProcShopInit * proc);
void DrawShopItemPriceLine(struct Text * text, int item, struct Unit * unit, u16 * tm);
void DrawShopItemLine(struct Text * text, int item, struct Unit * unit, u16 * tm);
u16 GetItemPrice(struct Unit *, int);
// func_fe6_080975A0
// func_fe6_080975C8
void GoldBox_OnLoop(struct ProcShop * proc);
void InitShopScreenConfig(void);
void _DisplayShopUiArrows(void);
void DisplayShopUiArrows(void);
void UnpackUiVArrowGfx(int, int);
void DisplayUiVArrow(int, int, u16, int);
void HandleShopBuyAction(struct ProcShop * proc);
int ShopTryMoveCursor(int pos, int pre, bool scroll);
// func_fe6_080979AC
// ShopTryScrollPage
// ShopUpdateBg2Offset
void RegisterShopState(u16, u16 item_cnt, u16 lines, u16 cur_sel, int bg_off, void (* on_draw)(struct ProcShop *, int), struct ProcShop * proc);
void Shop_TryMoveHandPage(void);
u16 ShopSt_GetHeadLoc(void);
int ShopSt_GetBg2Offset(void);
u16 ShopSt_GetHandLoc(void);
// func_fe6_08097D50
// func_fe6_08097D7C
bool IsShopPageScrolling(void);
bool ShouldDisplayUpArrow(void);
bool ShouldDisplayDownArrow(void);

// extern CONST_DATA ??? gDefaultShopItems
// extern CONST_DATA ??? gShopDislogueIdx
// extern CONST_DATA ??? gShopFaces
extern CONST_DATA struct ProcScr ProcScr_ShopFadeIn[];
extern CONST_DATA struct ProcScr ProcScr_ShopFadeOut[];
extern CONST_DATA struct ProcScr ProcScr_Shop[];
// extern CONST_DATA ??? ProcScr_ShopBuyInit
// extern CONST_DATA ??? ProcScr_ShopSellInit
// extern CONST_DATA ??? Sprite_ShopGoldBox
extern CONST_DATA struct ProcScr ProcScr_GoldBox[];
extern CONST_DATA struct ProcScr ProcScr_ShopDrawHand[];
// extern CONST_DATA ??? gpShopSt
