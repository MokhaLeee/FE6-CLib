#ifndef UNKNOWN_OBJECTS_H
#define UNKNOWN_OBJECTS_H

#include "gba/gba.h"
#include "types.h"

#include "proc.h"
#include "text.h"
#include "menu.h"
#include "mapselect.h"

// some or those are not so much "unknown" as much as they just don't have a home yet

extern struct Font gFont_Unk_02002770;
extern u16 gUiTmScratchA[0x280];
extern u16 gUiTmScratchB[0x280];
extern u16 gUiTmScratchC[0x240];

extern struct Glyph const * CONST_DATA TextGlyphs_Special[];
extern struct Glyph const * CONST_DATA TextGlyphs_System[];
extern struct Glyph const * CONST_DATA TextGlyphs_Talk[];
extern u16 const Pal_Text[]; // 2 palettes (system and talk)
extern u16 const Pal_GreenTextColors[];
extern u8 const Img_FactionMiniCard[];
extern u16 const Pal_FactionMiniCard[];
extern u8 const Img_TalkBubble[];
extern u16 const Pal_TalkBubble[];
extern u8 const Img_TalkBubbleOpeningA[];
extern u8 const Img_TalkBubbleOpeningB[];
extern u8 const Img_TalkBubbleOpeningC[];
extern u8 const Img_TalkBubbleOpeningD[];
extern u8 const Img_TalkBubbleOpeningE[];
extern u8 const Tsa_Unk_08101974[];
extern u8 const Tsa_Unk_08101A2C[];
extern u8 const Img_SystemObjects[];
extern u16 const Pal_SystemObjects[];
extern u8 const Img_LimitViewSquares[];
extern u16 const Pal_LimitViewBlue[];
extern u16 const Pal_LimitViewRed[];
extern u16 const Pal_LimitViewGreen[];
extern u8 const Img_PhaseChangeSquares[];
extern u8 const Img_PhaseChangePlayer[];
extern u16 const Pal_PhaseChangePlayer[];
extern u8 const Img_PhaseChangeEnemy[];
extern u16 const Pal_PhaseChangeEnemy[];
extern u8 const Img_PhaseChangeOther[];
extern u16 const Pal_PhaseChangeOther[];
extern u16 const SpriteAnim_08102450[];
extern u16 const SpriteAnim_GasTrapVertical[];
extern u16 const SpriteAnim_GasTrapHorizontal[];
extern u8 const Img_GasTrapVertical[];
extern u8 const Img_GasTrapHorizontal[];
extern u16 const Pal_GasTrap[];
extern u8 const Img_ArrowTrap[];
extern u16 const Pal_ArrowTrap[];
extern u16 const SpriteAnim_ArrowTrap[];
extern u8 const Img_FireTrap[];
extern u16 const Pal_FireTrap[];
extern u16 const SpriteAnim_FireTrap[];
extern u8 const Img_PikeTrap[];
extern u16 const SpriteAnim_PikeTrap[];
extern u16 const Pal_PikeTrap[];
extern u8 const Img_ChapterIntroFog[];
extern u16 const Pal_ChapterIntroFog[];
extern u8 const Img_ChapterIntroMotif[];
extern u16 const Pal_ChapterIntroMotif[];
extern u8 const Tm_ChapterIntroMotif[];
extern u8 const Img_GameOverText[];
extern u16 const Pal_GameOverText[];
extern u16 const Pal_Unk_0830D95C[];
extern u8 const Tsa_Unk_0830D97C[];
extern u8 const Tsa_Unk_081022FC[];
extern u16 const Pal_UnitSprites[];
extern u16 const Pal_UnitSpritesPurple[];
extern u8 const Img_SandstormParticles[];
extern u8 const Img_SnowstormParticles[];
extern u8 const Img_FlamesParticles[];
extern u16 const Pal_FlamesParticles[];
extern u8 const Img_CloudWeather[];
extern u16 const Pal_CloudWeather[];
extern u8 const Img_MovePath[];
extern u16 const Pal_MovePath[];
extern u8 const Tsa_UnitPanelHeader[];
extern u8 const Img_StatusHealEffect[];
extern u16 const Pal_StatusHealEffect[];
extern u8 const Tsa_StatusHealEffect[];
extern u8 const Tsa_BattlePreviewFrame_Short[];
extern u8 const Tsa_BattlePreviewFrame_Long[];
extern u16 const Pal_BattlePreviewFrame_Blue[];
extern u16 const Pal_BattlePreviewFrame_Red[];
extern u16 const Pal_BattlePreviewFrame_Green[];
extern u16 const Pal_BattlePreviewFrame_Purple[];
extern u8 const Img_BattlePreviewFrame[];
extern u8 const Img_BattlePreviewMultipliers[];
extern u16 const Pal_BattlePreviewMultipliers[];
extern u8 const Img_MuFogBump[];
extern u16 const SpriteAnim_MuFogBump[];
extern u8 const Img_ManimInfoWindowDigits[];
extern u16 const Pal_ManimWindowHpBar[];
extern u8 const Img_ManimInfoFrame[];
extern u8 const Img_ManimHpBar[];
extern u16 const Pal_UiWindowFrame_ThemeBlue[];
extern u16 const Pal_UiWindowFrame_ThemeRed[];
extern u16 const Pal_UiWindowFrame_ThemeGray[];
extern u16 const Pal_UiWindowFrame_ThemeGreen[];
extern u8 const Img_UiWindowFrame_ThemeBlue[];
extern u8 const Img_UiWindowFrame_ThemeRed[];
extern u8 const Img_UiWindowFrame_ThemeGray[];
extern u8 const Img_UiWindowFrame_ThemeGreen[];
extern u16 const Pal_UiStatBar_ThemeBlue[];
extern u16 const Pal_UiStatBar_ThemeRed[];
extern u16 const Pal_UiStatBar_ThemeGray[];
extern u16 const Pal_UiStatBar_ThemeGreen[];
extern u8 const Img_UiUnitNameFrame[];
extern u16 const Pal_UiUnitNameFrame[];

extern u16 const Pal_EfxRestBG[]; // manim

extern u8 const Tsa_StatusScreen_FactionInfoFrame[]; // tsa
extern u8 const Tsa_StatusScreen_PlaytimeFrame[]; // tsa
extern u8 const gUnk_08309408[]; // compressed tsa
extern u8 const gUnk_0833C6F4[]; // tsa
extern u8 const gUnk_0833C8D8[]; // tsa

// extern ??? gUnk_083198CC
extern u16 const Pal_SpinningArrow[];
// extern ??? gUnk_08319EE8
// extern ??? gUnk_0831A088
// extern ??? gUnk_0831A248
// extern ??? gUnk_0831A268
// extern ??? Pal_Sio_0831AABC
extern u16 const Pal_0831AAFC[];
// extern ??? gUnk_0831AB1C
// extern ??? gUnk_0831B068
extern u8 const Img_MonologueBG[];
extern u8 const Tsa_MonologueBG[];
// extern ??? gUnk_08320436
extern u16 const Pal_MonologueBG[];
extern u32 const Img_SpinningArrow[];
// extern ??? gUnk_08320EEC
// extern ??? gUnk_08320FCE
// extern ??? gUnk_083210A0
// extern ??? gUnk_083215B8
// extern ??? gUnk_08321EE4
// extern ??? gUnk_08321F24
// extern ??? gUnk_08321FA4
// extern ??? gUnk_08326910
// extern ??? gUnk_08326930
// extern ??? gUnk_08326E64
// extern ??? gUnk_08326EE6
// extern ??? gUnk_08327108

extern struct ProcScr CONST_DATA ProcScr_OpAnim[];
extern struct ProcScr CONST_DATA ProcScr_WorldMapIntroEvent[];
extern struct ProcScr CONST_DATA ProcScr_Config[];
extern u16 CONST_DATA Pal_ManimFireDragonMu[];
extern u16 CONST_DATA Pal_ManimDivineDragonMu[];

extern struct ChapterInfo CONST_DATA ChapterInfoTable[];

extern void const * CONST_DATA ChapterAssets[];

extern u16 const Pal_LinkArenaMuralBackground[];
extern u16 const Pal_Unk_083087C8[][0x20];

extern u8 const gUnk_083080D0[]; // compressed img (statscreen misc sprite sheet)
extern u8 const gUnk_08307CEC[]; // compressed tsa (statscreen main window frame)
extern u16 const gUnk_08308050[]; // pal (statscreen equip stats frame)
extern u8 const gUnk_08307ED4[]; // compressed img (statscreen equip stats frame)
extern u8 const gUnk_08308920[]; // compressed img (equipment label)

extern u8 const gUnk_08307D58[]; // tsa (compressed): statscreen page A frame
extern u8 const gUnk_08307DD4[]; // tsa (compressed): statscreen page B frame
extern u8 const gUnk_08307E50[]; // tsa (compressed): statscreen page C frame
extern u8 const gUnk_08308070[]; // tsa (compressed): statscreen page B battle stat box
extern u8 const gUnk_083080AC[]; // tsa: statscreen page B equipped weapon background

extern u8 Img_WmDialogueBox[];
extern u16 Pal_WmDialogueBox[];
extern u8 Pal_Wm_082AADA4[];
extern u8 Pal_Wm_082B2380[];
extern u8 Pal_Wm_082B9E64[];
extern u8 Pal_Wm_082C1224[];
extern u8 Pal_Wm_082C8874[];
extern u8 Pal_Wm_082D1964[];
extern u8 Pal_Wm_082D1BA0[];
extern u8 const Img_WmHighlight_Nation1[];
extern u8 const Img_WmHighlight_Nation2[];
extern u8 const Img_WmHighlight_Nation3[];
extern u8 const Img_WmHighlight_Nation4[];
extern u8 const Img_WmHighlight_Nation5[];
extern u8 const Img_WmHighlight_Nation6[];
extern u8 const Img_WmHighlight_Nation7[];
extern u16 const ApInfo_WmHighlight_Nation1[];
extern u16 const ApInfo_WmHighlight_Nation2[];
extern u16 const ApInfo_WmHighlight_Nation3[];
extern u16 const ApInfo_WmHighlight_Nation4[];
extern u16 const ApInfo_WmHighlight_Nation5[];
extern u16 const ApInfo_WmHighlight_Nation6[];
extern u16 const ApInfo_WmHighlight_Nation7[];
extern u16 const Pal_WmHightlight[];
extern u8 const Img_WorldMapStuff[];
extern u16 const ApInfo_WmDot[];
extern u16 const Pal_WorldMapStuff[];
extern u16 const Pal_WmSpriteDisp2[];
extern u16 const Pal_WmSpriteDisp1[];
extern u16 const Pal_WmMapText[];
extern u16 const ApInfo_WmMapTextDisp[];
extern u8 const Img_WmMapTextDisp_082D3904[];
extern u8 const Img_WmMapTextDisp_082D3C68[];
extern u8 const Img_WmMapTextDisp_082D3E78[];
extern u8 const Img_WmMapTextDisp_082D4120[];
extern u8 const Img_WmMapTextDisp_082D43A4[];
extern u8 const Img_WmMapTextDisp_082D45E0[];
extern u8 const Img_WmMapTextDisp_082D4838[];
extern u8 const Img_WmMapTextDisp_082D4B38[];
extern u8 const Img_WmMapTextDisp_082D4D3C[];
extern u8 const Img_WmMapTextDisp_082D4F9C[];
extern u8 const Img_WmMapTextDisp_082D5254[];
extern u8 const Img_WmMapTextDisp_082D5400[];
extern u8 const Img_WmMapTextDisp_082D55A4[];
extern u8 const Img_WmMapTextDisp_082D5778[];
extern u8 const Img_WmMapTextDisp_082D5844[];
extern u8 const Img_DefaultMapText[];
extern u8 const Img_WmMapTextDisp_082D59DC[];
extern u8 const Img_WmMapTextDisp_082D5B98[];
extern u8 const Img_WmMapTextDisp_082D5D08[];
extern u8 const Img_WmMapTextDisp_082D5EE0[];
extern u8 const Img_WmMapTextDisp_082D60F4[];
extern u8 const Img_WmMapTextDisp_082D6274[];
extern u8 const Img_WmMapTextDisp_082D6408[];
extern u8 const Img_WmMapTextDisp_082D65A8[];
extern u8 const Img_WmMapTextDisp_082D6768[];
extern u8 const Img_WmMapTextDisp_082D6930[];
extern u8 const Img_WmMapTextDisp_082D6AF4[];
extern u8 const Img_WmMapTextDisp_082D6CA8[];
extern u8 const Img_WmMapTextDisp_082D6E44[];
extern u8 const Img_WmMapTextDisp_082D7018[];
extern u8 const Img_WmMapTextDisp_082D720C[];
extern u8 const Img_WmMapTextDisp_082D73D0[];
extern u8 const Img_WmMapTextDisp_082D75D8[];
extern u8 const Img_WmMapTextDisp_082D7774[];
extern u8 const Img_WmMapTextDisp_082D7934[];
extern u8 const Img_WmMapTextDisp_082D7B20[];
extern u8 const Img_WmMapTextDisp_082D7D24[];
extern u8 const Img_WmMapTextDisp_082D7F2C[];
extern u8 const Img_Background_082D80B0[];
extern u8 const Tsa_Background_082DAC8C[];
extern u16 const Pal_Background_082DB140[];
extern u8 const Img_Background_082E28F8[];
extern u8 const Tsa_Background_082E35DC[];
extern u16 const Pal_Background_082E3A90[];
extern u8 const Img_Background_082E3B10[];
extern u8 const Tsa_Background_082E3EC0[];
extern u16 const Pal_Background_082E4374[];
extern u8 const Img_Background_082E4650[];
extern u8 const Tsa_Background_082E6EB4[];
extern u16 const Pal_Background_082E7368[];
extern u8 const Img_Background_082E73E8[];
extern u8 const Tsa_Background_082EADF0[];
extern u16 const Pal_Background_082EB2A4[];
extern u8 const Img_Background_082EB324[];
extern u8 const Tsa_Background_082EDB7C[];
extern u16 const Pal_Background_082EE030[];
extern u8 const Img_Background_082EE0B0[];
extern u8 const Tsa_Background_082EF97C[];
extern u16 const Pal_Background_082EFE30[];
extern u16 const Pal_Background_082EFEB0[];
extern u8 const Img_Background_082EFF30[];
extern u8 const Tsa_Background_082F1490[];
extern u16 const Pal_Background_082F1944[];
extern u8 const Img_Background_082F19C4[];
extern u8 const Tsa_Background_082F3494[];
extern u16 const Pal_Background_082F3948[];
extern u8 const Img_Background_082F39C8[];
extern u8 const Tsa_Background_082F62E0[];
extern u16 const Pal_Background_082F6794[];
extern u16 const Pal_Background_082F6814[];
extern u8 const Img_Background_082F6894[];
extern u8 const Tsa_Background_082F85E8[];
extern u16 const Pal_Background_082F8A9C[];
extern u8 const Img_Background_082F8B1C[];
extern u8 const Tsa_Background_082FBE6C[];
extern u16 const Pal_Background_082FC320[];
extern u8 const Img_Background_082FC3A0[];
extern u8 const Tsa_Background_082FECE0[];
extern u16 const Pal_Background_082FF194[];
extern u8 const Img_Background_082FF214[];
extern u8 const Tsa_Background_08301244[];
extern u16 const Pal_Background_083016F8[];
extern u16 const Pal_Background_08301778[];
extern u16 const Pal_Background_083017F8[];
extern u8 const Img_Background_08301878[];
extern u8 const Tsa_Background_0830491C[];
extern u16 const Pal_Background_08304DD0[];
extern u8 const Img_Background_08304E50[];
extern u8 const Tsa_Background_08306F24[];
extern u16 const Pal_Background_083073D8[];

extern u16 const Pal_Unk_08309474[];
extern u16 const Pal_Unk_083094F4[];
extern u16 const Pal_Unk_0830D5E4[];

extern u8 const Img_ChapterTitleBG1[]; // img
extern u8 const Img_ChapterTitleBG2[]; // img
extern u8 const Tsa_ChapterTitleFxDefaultBG[]; // tsa
extern u8 const gUnk_08308A78[]; // img
extern u16 const Pal_08100A48[]; // pal

extern u16 Img_ChapterTitle_0830D9C0[];
extern u16 Img_ChapterTitle_0830DDBC[];
extern u16 Img_ChapterTitle_0830E1DC[];
extern u16 Img_ChapterTitle_0830E640[];
extern u16 Img_ChapterTitle_0830EA4C[];
extern u16 Img_ChapterTitle_0830EDC8[];
extern u16 Img_ChapterTitle_0830F250[];
extern u16 Img_ChapterTitle_0830F6C4[];
extern u16 Img_ChapterTitle_0830F9B8[];
extern u16 Img_ChapterTitle_0830FE60[];
extern u16 Img_ChapterTitle_083102CC[];
extern u16 Img_ChapterTitle_083107A8[];
extern u16 Img_ChapterTitle_08310BBC[];
extern u16 Img_ChapterTitle_08311094[];
extern u16 Img_ChapterTitle_083114AC[];
extern u16 Img_ChapterTitle_08311890[];
extern u16 Img_ChapterTitle_08311D54[];
extern u16 Img_ChapterTitle_08312158[];
extern u16 Img_ChapterTitle_083124FC[];
extern u16 Img_ChapterTitle_083129A0[];
extern u16 Img_ChapterTitle_08312D20[];
extern u16 Img_ChapterTitle_08313104[];
extern u16 Img_ChapterTitle_083135C0[];
extern u16 Img_ChapterTitle_0831394C[];
extern u16 Img_ChapterTitle_08313D38[];
extern u16 Img_ChapterTitle_083140C8[];
extern u16 Img_ChapterTitle_083144E4[];
extern u16 Img_ChapterTitle_083149C8[];
extern u16 Img_ChapterTitle_08314E14[];
extern u16 Img_ChapterTitle_083151E8[];
extern u16 Img_ChapterTitle_0831569C[];
extern u16 Img_ChapterTitle_08315AC0[];
extern u16 Img_ChapterTitle_08315F88[];
extern u16 Img_ChapterTitle_08316354[];
extern u16 Img_ChapterTitle_083167EC[];
extern u16 Img_ChapterTitle_08316C00[];
extern u16 Img_ChapterTitle_08317014[];
extern u16 Img_ChapterTitle_08317484[];
extern u16 Img_ChapterTitle_08317858[];
extern u16 Img_ChapterTitle_08317AA4[];
extern u16 Img_ChapterTitle_08317D94[];
extern u16 Img_ChapterTitle_08318040[];
extern u16 Img_ChapterTitle_0831833C[];
extern u16 Img_ChapterTitle_08318658[];

extern u8 const Img_MapUiElements[];

extern u16 const Pal_UnitMapUiFrame_Blue[];
extern u16 const Pal_UnitMapUiFrame_Red[];
extern u16 const Pal_UnitMapUiFrame_Green[];

extern u8 const Tsa_UnitMapUi_Frame[];
extern u8 const Tsa_TerrainMapUi_Labels[];
extern u8 const Tsa_TerrainMapUi_BallistaLabels[];
extern u8 const Tsa_TerrainMapUi_ObstacleLabels[];
extern u8 const Tsa_TerrainMapUi_ObstacleFullHp[];
extern u8 const Tsa_TerrainMapUi_Frame[];
extern u8 const Tsa_UnitBurstMapUi_Frame0[];
extern u8 const Tsa_UnitBurstMapUi_Frame1[];
extern u8 const Tsa_UnitBurstMapUi_Frame2[];
extern u8 const Tsa_UnitBurstMapUi_Frame3[];
extern u8 const Tsa_UnitBurstMapUi_Frame4[];
extern u8 const Tsa_UnitBurstMapUi_Frame5[];

extern u8 const Img_Unk_083092CC[];

// extern const ??? gUnk_08336CD0
// extern const ??? gUnk_08336CF0
// extern const ??? gUnk_08336CF8
// extern const ??? gUnk_08336D00
// extern const ??? gUnk_08336D3C
// extern const ??? gUnk_08336D48
// extern const ??? gUnk_08336D54
extern u8 const Img_MuralBackground[];
extern u8 const Img_0833B958[];
extern u8 const Img_0833BB14[];
extern u8 const Img_0833BB28[];
extern u8 const Tsa_0833BE84[];
extern u8 const Tsa_0833BF08[];
extern u16 const Pal_MuralBackground[];
extern u16 const Pal_0833C01C[];
extern u16 const Pal_0833C03C[];
extern u8 const Img_0833C09C[];
extern u8 const Tsa_0833C1D8[];
extern u8 const Tsa_0833C234[];
extern u8 const Img_Unk_0833C378[];
// extern const ??? gUnk_0833C6F4
// extern const ??? gUnk_0833C8D8
extern u16 const Pal_Unk_0833C944[];
extern u8 const Img_WorldMap_PlayRank[];
extern u8 const Tsa_08340ED8[];
extern u16 const Pal_0834138C[];
extern u8 const Img_PlayRank_083413CC[];
extern u16 const Pal_08341DA0[];
extern u8 const Img_PlayRank[];
extern u8 const Img_PlayRankCharacters[];
extern u16 const Pal_08342A98[];
extern u16 const Pal_08342AB8[];
extern u16 const Pal_08342AD8[];
extern u8 const Tsa_08342AF8[];
// extern const ??? gUnk_08342B54
extern const u16 Pal_08343358[];
extern u8 const Img_08343398[];
extern u8 const Img_08343A80[];
extern u8 const Img_08343FAC[];
// extern const ??? gUnk_083442C4
// extern const ??? gUnk_08344304
extern u8 const Img_Fin[];
extern u16 const Pal_Fin[];
extern u8 const Img_Ending_CopyRight[];
extern u16 const Tsa_Ending_CopyRight[];
extern u16 const Pal_Ending_CopyRight[];
// extern const ??? Tsa_EndingPInfoBG
// extern const ??? gUnk_08345934
// extern const ??? gUnk_08346184
// extern const ??? gUnk_083461C4
// extern const ??? gUnk_08346330
// extern const ??? gUnk_083463B4
// extern const ??? gUnk_083463F4
// extern const ??? gUnk_08346574
extern u8 const Img_MonologueText[];
extern u16 const Pal_MonologueText[];
extern u8 const Img_EndingMonologueText3[];
extern u8 const Img_EndingMonologueText1[];
extern u8 const Img_EndingMonologueText4[];
extern u8 const Img_08352160[];
extern u16 const Pal_EndingMonologueText[];
extern const int gUnk_08353328[];
// extern const ??? gUnk_08354728
// extern const ??? gUnk_08354760
// extern const ??? gUnk_08354780
// extern const ??? gUnk_08357140
// extern const ??? gUnk_083599AC
// extern const ??? gUnk_0835A368
// extern const ??? gUnk_0835A3E8
// extern const ??? gUnk_0835A5D0
// extern const ??? gUnk_0835A5F0
// extern const ??? gUnk_0835AB08
// extern const ??? gUnk_0835AB28
// extern const ??? gUnk_0835B040
// extern const ??? gUnk_0835C034
// extern const ??? gUnk_0835C80C
// extern const ??? gUnk_0835C824
// extern const ??? gUnk_0835C829
// extern const ??? String_ShopGoldG
// extern const ??? gUnk_0835CA78
extern u16 const Pal_Title_BG[];
extern u8 const Img_Title_BG[];
extern u8 const Img_Title_Sprites[];
extern u16 const SpriteAnim_0835F2C8[];
extern u16 const Pal_Title_0835F388[];
extern u8 const Tsa_Title_BG2[];
extern u8 const Tsa_Title_BG0[];
extern u8 const Tsa_Title_BG1[];
extern u8 const Img_Title_BG3[];
extern u16 const Pal_Title_BG3[];
extern u8 const Img_Title_08364438[];
extern u16 const Pal_Title_08364A94[];
// extern const ??? gUnk_08364AB4
// extern const ??? gUnk_083674BC
// extern const ??? gUnk_08367B30
// extern const ??? gUnk_0836A094
// extern const ??? gUnk_0836A494
// extern const ??? gUnk_0836A888
// extern const ??? gUnk_0836A9AC
// extern const ??? gUnk_0836EEFC
// extern const ??? gUnk_0836F610
// extern const ??? Img_EndingMonologue
// extern const ??? Tsa_EndingMonologue
// extern const ??? Zpal_EndingMonologue
// extern const ??? gUnk_083747A4
// extern const ??? gUnk_08375888
// extern const ??? gUnk_083758A8
// extern const ??? gUnk_08375908
// extern const ??? gUnk_08375ADC
// extern const ??? gUnk_08375B64
// extern const ??? gUnk_08375B84
// extern const ??? gUnk_08376B70
// extern const ??? gUnk_08376DF4
// extern const ??? gUnk_08376FDC
// extern const ??? gUnk_08378C60
// extern const ??? gUnk_08378F54
// extern const ??? gUnk_08379D0C
// extern const ??? gUnk_08379D2C
// extern const ??? gUnk_08379DCC
// extern const ??? gUnk_08379F8C
// extern const ??? gUnk_0837AA68
// extern const ??? gUnk_0837AAC8
// extern const ??? gUnk_0837AAE8
// extern const ??? gUnk_0837AB18
// extern const ??? gUnk_0837ACB0
// extern const ??? gUnk_0837ACD0
// extern const ??? gUnk_0837C844
// extern const ??? gUnk_0837CB0C
// extern const ??? gUnk_0837CB2C
// extern const ??? gUnk_0837CB4C
// extern const ??? gUnk_0837CB6C
// extern const ??? gUnk_0837CB8C
// extern const ??? gUnk_0837EEB4
// extern const ??? gUnk_0837F418
// extern const ??? Img_OpAnimGlyphs
// extern const ??? Pal_OpAnimGlyphs
// extern const ??? gUnk_08380F4C
// extern const ??? gUnk_08380F54
// extern const ??? gUnk_08380F5A
// extern const ??? gUnk_08380F62

// extern CONST_DATA ??? gUnk_0868A4F8
// extern CONST_DATA ??? gUnk_0868A518
// extern CONST_DATA ??? gUnk_0868A550
// extern CONST_DATA ??? gUnk_0868A55C
// extern CONST_DATA ??? Sprite_0868A568
// extern CONST_DATA ??? Sprite_0868A570

extern const u16 gUnk_083278AC[];
extern const u8 gUnk_083278EC[];
extern const u16 gUnk_083280B0[];
extern const u8 gUnk_0832A130[];
extern const u8 Img_SupportMenu[];
extern const u8 gUnk_0832B554[];
extern const u16 Pal_SupportMenu[];
extern const u16 Img_XmapObj[];
extern const u16 Pal_XmapObj[];
extern const u16 gUnk_0832C35C[];
extern const u16 gUnk_0832C39C[];
extern const u16 gUnk_0832C5E8[];
extern const u16 gUnk_0832CA9C[];
extern const u16 gUnk_0832CAFC[];
extern const u16 gUnk_0832CC90[];

/* xmap.h */
/* config.h */
/* augury.h */
/* worldmap.h */
/* monologue.h */
/* shop.h */
/* arena_ui.h */
/* suspend_ui.h */
/* opanim.h */
/* titlescreen.h */

#endif // UNKNOWN_OBJECTS_H
