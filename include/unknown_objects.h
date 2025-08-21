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
// extern ??? gUnk_0831AABC
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

extern struct ProcScr CONST_DATA ProcScr_OpeningSequence[];
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

extern u8 const Img_EfxSideHitDmgCrit[];
extern u8 const Img_EfxArrowWTA[];
extern u16 Img_EkrGaugeNumber[];
extern u16 Pal_EkrGauge_081131A4[];
extern u16 Pal_08113224[];
extern u16 gPalEfxHpBarPurple[];
extern u16 gPalEfxHpBarGreen[];
extern u16 Pal_081134C4[];
extern u16 const Pal_BanimUnitFlashing[];
extern u8 const Img_EkrExpBar[];
extern u8 const Img_EkrExpBarChange[];
extern u8 const Img_BarNumfx[];
extern u8 const Tsa_EkrExpBar[];
extern u16 const Pal_EkrExpBar[];
// extern ??? gUnk_08113D70
extern u16 const Pal_08113F98[];
extern u16 const Pal_08113FB8[];
extern u16 const Pal_08113FD8[];
extern u8 const Img_BanimArcherFBallistaIntro[];
extern u8 const Img_BanimArcherMBallistaIntro[];
extern u8 const Img_BanimSnipperFBallistaIntro[];
extern u8 const Img_LevelUpFrame[]; // img (stat gains)
extern u8 const Tm_LevelUpFrame[]; // tiles (stat gains)
extern u16 const Pal_LevelUpFrame[]; // pal (stat gains)
// extern ??? gUnk_081150E8
// extern ??? gUnk_081152FC
extern u8 const Img_EkrPopup[];
extern u8 const Img_EkrUnkPopup[];
extern u16 const Pal_EkrPopup[];
extern u8 const Tsa_EkrPopup[];
extern u8 const Img_ArenaBattleBg[];
extern u8 const Tsa_ArenaBattleBg[];
extern u16 const Pal_ArenaBattleBg_A[];
extern u16 const Pal_ArenaBattleBg_B[];
extern u16 const Pal_ArenaBattleBg_C[];
// extern ??? gUnk_08119CD8
extern u16 const FrameArray_EfxSongBGCOL[];
extern u16 const FrameConf_EfxEckesachsBGCOL[];
extern u16 const gUnk_08119D78[];
extern u16 const FrameConf_EfxDarkbreathBG[];
extern u16 const FrameConf_EfxDarkbreathBGCOL[];
extern u16 const FrameConf_EfxThunderBG[];
extern u16 const FrameConf_EfxThunderBGCOL[];
extern u16 const FrameConf_EfxFireBG[];
extern u16 const FrameConf_EfxFireHITBG[];
extern u16 const FrameConf_EfxElfireBGCOL[];
// extern ??? FrameConf_EfxFimbulvetrBGTR
// extern ??? FrameConf_EfxFimbulvetrBG
// extern ??? FrameConf_EfxThunderstormBG
// extern ??? FrameConf_EfxAlacaliburBG
// extern ??? FrameConf_EfxAlacaliburBGCOL
// extern ??? FrameConf_EfxMistyrainBG1
// extern ??? FrameConf_EfxMistyrainBG2
// extern ??? FrameConf_EfxResireBG
// extern ??? FrameConf_EfxResireBG3
// extern ??? FrameConf_EfxResireBG2
// extern ??? FrameConf_EfxLightningBG
// extern ??? FrameArray_EfxPurgeBG
// extern ??? FrameConf_EfxForblazeBG1
// extern ??? FrameArray_EfxForblazeBGCOL1
// extern ??? gUnk_0811A520
// extern ??? FrameArray_EfxDivineBG
// extern ??? FrameArray_EfxDivineBG2
// extern ??? FrameArray_EfxDivineBG3
// extern ??? FrameArray_EfxAureolaBG
// extern ??? FrameArray_EfxAureolaBG2COL
// extern ??? FrameArray_EfxApocalypseBGCOL2
// extern ??? FrameArray_EfxApocalypseBG2
// extern ??? FrameArray_EfxHazymoonBG1
// extern ??? FrameArray_EfxHazymoonBG2
// extern ??? FrameArray_EfxHazymoonBG3
// extern ??? FrameArray_EfxFenrirBGCOL
// extern ??? FrameArray_EfxFenrirBG2_A
// extern ??? FrameArray1_EfxLiveBG
// extern ??? FrameArray2_EfxLiveBG
// extern ??? FrameArray3_EfxLiveBG
// extern ??? FrameArray4_EfxLiveBG
// extern ??? FrameArray1_EfxLiveBGCOL
// extern ??? FrameArray2_EfxLiveBGCOL
// extern ??? FrameArray3_EfxLiveBGCOL
// extern ??? FrameArray4_EfxLiveBGCOL
// extern ??? FrameArray_EfxReserveBG
// extern ??? EfxReserveBG_Songs
// extern ??? EfxReserveBG_SongLocs
// extern ??? FrameArray_EfxReserveBGCOL
// extern ??? FrameArray_EfxReserveBG2
// extern ??? FrameArray_EfxReserveBGCOL2
// extern ??? FrameArray_EfxRestBG
// extern ??? FrameArray_EfxSilenceBG
// extern ??? FrameArray_EfxSleepBG
// extern ??? FrameArray_EfxHammarneBG
// extern ??? FrameArray_EfxMshieldBG
extern const u16 Frames_EfxCriricalEffectBGCOL[];
extern const u16 FrameConf_EfxNormalEffectBG[];
// extern ??? FrameConfig_EfxMagFcastBg1
// extern ??? FrameConfig_EfxMagFcastBg2
// extern ??? FrameConfig_EfxMagFcastBg3
// extern ??? FrameConfig_EfxMagFcastBg4
// extern ??? FrameConf_EfxMagdhisEffectBG
// extern ??? FrameArray_EfxopFireBG
// extern ??? FrameArray_EfxopThunderBG
// extern ??? FrameArray_EfxopThunderBGCOL
// extern ??? gUnk_0811AF9E
// extern ??? gUnk_0811AFA4
extern const u8 Img_TeonoOBJ[];
extern const u16 Pal_TeonoOBJ[];
extern const u8 Img_EfxArrowOBJ[];
extern const u8 Img_SpellJavelin[];
extern const u16 Pal_SpellJavelin[];
extern const u8 Img_SpellJavelinCavalier[];
extern const u16 Pal_SpellJavelinCavalier[];
extern const u8 Img_SpellJavelinSoldier[];
extern const u16 Pal_SpellJavelinSoldier[];
extern const u8 Img_SpellJavelinPaladin[];
extern const u16 Pal_SpellJavelinPaladin[];
extern const u8 Img_SpellJavelinPrgasusKnight[];
extern const u16 Pal_SpellJavelinPrgasusKnight[];
extern const u8 Img_SpellJavelinFalcon[];
extern const u16 Pal_SpellJavelinFalcon[];
extern const u8 Img_SpellJavelinWyvernRider[];
extern const u16 Pal_SpellJavelinWyvernRider[];
extern const u8 Img_SpellJavelinWyvernLord[];
extern const u16 Pal_SpellJavelinWyvernLord[];
extern const u8 Img_SpellJavelinGenerial[];
extern const u16 Pal_SpellJavelinGenerial[];
extern const u8 Img_EfxSongFE6[];
extern const u16 Pal_EfxSongFE6[];
extern const u8 Img_EfxSongBG[];
extern const u16 Pal_EfxSongBG[];
extern const u16 Tsa_EfxSongBG[];
extern const u8 Img_EfxEckesachsBG[];
extern const u16 Pal_EfxEckesachsBG[];
extern const u16 Tsa_EfxEckesachsBG[];
extern const u8 Img_BreathSprites[];
extern u16 Pal_EfxBindingBlade[];
extern u16 Img_EfxHurtmutEff00OBJ1[];
extern u16 Img_EfxHurtmutEff00OBJ2[];
extern u16 Pal_EfxHurtmutEff00OBJ[];
extern u16 Pal_IceBreathSprites[];
extern u16 Pal_DarkBreathSprites[];
extern u16 Img_EfxDarkbreathBG[];
extern u16 Tsa_EfxDarkbreathBG1[];
extern u16 Tsa_EfxDarkbreathBG2[];
extern u16 Tsa_EfxDarkbreathBG3[];
extern u16 Tsa_EfxDarkbreathBG4[];
extern u16 Tsa_EfxDarkbreathBG5[];
extern u16 Tsa_EfxDarkbreathBG6[];
extern u16 Tsa_EfxDarkbreathBG7[];
extern u16 Tsa_EfxDarkbreathBG8[];
extern u16 Tsa_EfxDarkbreathBG9[];
extern u16 Tsa_EfxDarkbreathBG10[];
extern u16 Tsa_EfxDarkbreathBG11[];
extern u16 Tsa_EfxDarkbreathBG12[];
extern u16 Img_EfxCriricalEffectBG[];
extern u16 Pal_EfxCriricalEffectBG[];
extern u16 Tsa_EfxCriricalEffectBG_L[];
extern u16 Tsa_EfxCriricalEffectBG_R[];
extern u16 Img_EfxSRankWeaponEffectBG[];
extern u16 Pal_EfxSRankWeaponEffectBG[];
extern u16 Tsa_EfxSRankWeaponEffectBG[];
extern u16 Img_EfxNormalEffectBG[];
extern u16 Pal_EfxNormalEffectBG[];
extern u16 Tsa1_EfxNormalEffectBG[];
extern u16 Tsa2_EfxNormalEffectBG[];
extern u16 Tsa3_EfxNormalEffectBG[];
extern u16 Tsa4_EfxNormalEffectBG[];
extern u16 Tsa5_EfxNormalEffectBG[];
extern u16 Tsa6_EfxNormalEffectBG[];
extern u16 Tsa7_EfxNormalEffectBG[];
extern u16 Tsa8_EfxNormalEffectBG[];
extern u16 Tsa9_EfxNormalEffectBG[];
extern u16 TsaA_EfxNormalEffectBG[];
// extern ??? gUnk_08127778
extern u16 Img_EfxMagfcastBG[];
extern u16 Pal_EfxMagfcastBG[];
extern u16 Tsa1_EfxMagfcastBG[];
extern u16 Tsa2_EfxMagfcastBG[];
extern u16 Tsa3_EfxMagfcastBG[];
extern u16 Tsa4_EfxMagfcastBG[];
extern u16 Tsa5_EfxMagfcastBG[];
extern u16 Tsa6_EfxMagfcastBG[];
extern u16 Tsa7_EfxMagfcastBG[];
extern u16 Tsa8_EfxMagfcastBG[];
extern u16 Tsa9_EfxMagfcastBG[];
extern u16 Tsa10_EfxMagfcastBG[];
extern u16 Tsa11_EfxMagfcastBG[];
extern u16 Tsa12_EfxMagfcastBG[];
extern u16 Tsa13_EfxMagfcastBG[];
extern u16 Tsa14_EfxMagfcastBG[];
extern u16 Tsa15_EfxMagfcastBG[];
extern u16 Tsa16_EfxMagfcastBG[];
extern u16 Tsa17_EfxMagfcastBG[];
extern u16 Tsa18_EfxMagfcastBG[];
extern u16 Tsa19_EfxMagfcastBG[];
extern u16 Tsa20_EfxMagfcastBG[];
extern u16 Tsa21_EfxMagfcastBG[];
extern u16 Tsa22_EfxMagfcastBG[];
extern u16 Img_EfxMagdhisEffectBG[];
extern u16 Pal_EfxMagdhisEffectBG[];
extern u16 Tsa1_EfxMagdhisEffectBG[];
extern u16 Tsa2_EfxMagdhisEffectBG[];
extern u16 Tsa3_EfxMagdhisEffectBG[];
extern u16 Tsa4_EfxMagdhisEffectBG[];
extern u16 Img_EfxSunakemuriOBJ[];
extern u16 Pal_EfxSunakemuriOBJ1[];
extern u16 Pal_EfxSunakemuriOBJ2[];
extern u16 Pal_EfxSunakemuriOBJ3[];
extern u16 Img_EfxThunderBG[];
extern u16 Pal_EfxThunderBGCOL[];
extern u16 Tsa_EfxThuderBg1[];
extern u16 Tsa_EfxThuderBg2[];
extern u16 Img_EfxThunderOBJ[];
extern u16 Pal_EfxThunderOBJ[];
extern u16 Img_EfxFireBG[];
extern u16 Pal_EfxFireBG[];
extern u16 Tsa_EfxFireBG_0812E4C4[];
extern u16 Tsa_EfxFireBG_0812E56C[];
extern u16 Tsa_EfxFireBG_0812E614[];
extern u16 Tsa_EfxFireBG_0812E6CC[];
extern u16 Tsa_EfxFireBG_0812E794[];
extern u16 Tsa_EfxFireBG_0812E864[];
extern u16 Tsa_EfxFireBG_0812E964[];
extern u16 Tsa_EfxFireBG_0812EA6C[];
extern u16 Tsa_EfxFireBG_0812EB80[];
extern u16 Tsa_EfxFireBG_0812ECB8[];
extern u16 Tsa_EfxFireBG_0812EDBC[];
extern u16 Tsa_EfxFireBG_0812EE90[];
extern u16 Tsa_EfxFireBG_0812EF50[];
extern u16 Tsa_EfxFireBG_0812EFF8[];
extern u16 Tsa_EfxFireBG_0812F0A0[];
extern u16 Tsa_EfxFireBG_0812F158[];
extern u16 Tsa_EfxFireBG_0812F220[];
extern u16 Tsa_EfxFireBG_0812F2F0[];
extern u16 Tsa_EfxFireBG_0812F3F0[];
extern u16 Tsa_EfxFireBG_0812F4F8[];
extern u16 Tsa_EfxFireBG_0812F60C[];
extern u16 Tsa_EfxFireBG_0812F744[];
extern u16 Tsa_EfxFireBG_0812F848[];
extern u16 Tsa_EfxFireBG_0812F91C[];
extern u16 Img_EfxFireOBJ[];
extern u16 Pal_EfxFireOBJ[];
extern u16 Img_EfxFireHITBG_0812FFF8[];
extern u16 Img_EfxFireHITBG_08130D34[];
extern u16 Img_EfxFireHITBG_08131A10[];
extern u16 Img_EfxFireHITBG_08132838[];
extern u16 Img_EfxFireHITBG_0813382C[];
extern u16 Img_EfxFireHITBG_08134AC8[];
extern u16 Img_EfxFireHITBG_08135694[];
extern u16 Img_EfxFireHITBG_0813628C[];
extern u16 Img_EfxFireHITBG_08136DE4[];
extern u16 Img_EfxFireHITBG_081378E0[];
extern u16 Img_EfxFireHITBG_081382E8[];
extern u16 Tsa_EfxFireHITBG_08138C10[];
extern u16 Tsa_EfxFireHITBG_08138CBC[];
extern u16 Tsa_EfxFireHITBG_08138D74[];
extern u16 Tsa_EfxFireHITBG_08138E40[];
extern u16 Tsa_EfxFireHITBG_08138F20[];
extern u16 Tsa_EfxFireHITBG_08139014[];
extern u16 Tsa_EfxFireHITBG_0813912C[];
extern u16 Tsa_EfxFireHITBG_08139258[];
extern u16 Tsa_EfxFireHITBG_08139390[];
extern u16 Tsa_EfxFireHITBG_081394D4[];
extern u16 Tsa_EfxFireHITBG_08139628[];
extern u16 Tsa_EfxFireHITBG_08139780[];
extern u16 Tsa_EfxFireHITBG_081398E8[];
extern u16 Tsa_EfxFireHITBG_08139A54[];
extern u16 Tsa_EfxFireHITBG_08139BD0[];
extern u16 Tsa_EfxFireHITBG_08139D64[];
extern u16 Tsa_EfxFireHITBG_08139F04[];
extern u16 Tsa_EfxFireHITBG_0813A0A4[];
extern u16 Tsa_EfxFireHITBG_0813A244[];
extern u16 Tsa_EfxFireHITBG_0813A3E4[];
extern u16 Tsa_EfxFireHITBG_0813A574[];
extern u16 Pal_EfxFireHITBG[];
extern u16 Img_EfxElfireBG[];
extern u16 Pal_EfxElfireBGCOL[];
extern u16 Tsa_EfxElfireBG[];
extern u16 Tsa_FireBreathBg[];
extern u16 Img_EfxElfireOBJ[];
extern u16 Pal_EfxElfireOBJ[];
extern u16 Img_EfxThunderstormBG_0813BD94[];
extern u16 Img_EfxThunderstormBG_0813C964[];
extern u16 Img_EfxThunderstormBG_0813D9D0[];
extern u16 Pal_EfxThunderstormBG[];
extern u16 Tsa_EfxThunderstormBG_0813E7BC[];
extern u16 Tsa_EfxThunderstormBG_0813E950[];
extern u16 Tsa_EfxThunderstormBG_0813EB58[];
extern u16 Tsa_EfxThunderstormBG_0813ECBC[];
extern u16 Tsa_EfxThunderstormBG_0813ED9C[];
extern u16 Tsa_EfxThunderstormBG_0813EEB4[];
extern u16 Tsa_EfxThunderstormBG_0813F060[];
extern u16 Tsa_EfxThunderstormBG_0813F180[];
extern u16 Tsa_EfxThunderstormBG_0813F26C[];
extern u16 Tsa_EfxThunderstormBG_0813F354[];
extern u16 Tsa_EfxThunderstormBG_0813F3EC[];
extern u16 Img_EfxForblazeBG1_0813F5E0[];
extern u16 Img_EfxForblazeBG1_0813FF7C[];
extern u16 Tsa_EfxForblazeBG1_0814092C[];
extern u16 Tsa_EfxForblazeBG1_081409DC[];
extern u16 Tsa_EfxForblazeBG1_08140A98[];
extern u16 Tsa_EfxForblazeBG1_08140B60[];
extern u16 Tsa_EfxForblazeBG1_08140C30[];
extern u16 Tsa_EfxForblazeBG1_08140D00[];
extern u16 Tsa_EfxForblazeBG1_08140DCC[];
extern u16 Tsa_EfxForblazeBG1_08140E98[];
extern u16 Tsa_EfxForblazeBG1_08140F7C[];
extern u16 Tsa_EfxForblazeBG1_08141050[];
extern u16 Tsa_EfxForblazeBG1_08141114[];
extern u16 Tsa_EfxForblazeBG1_081411D4[];
extern u16 Tsa_EfxForblazeBG1_08141288[];
extern u16 Pal_EfxForblazeBG1[];
extern u16 Img1_EfxForblazeBG2[];
extern u16 Img2_EfxForblazeBG2[];
extern u16 Pal1_EfxForblazeBG2[];
extern u16 Pal2_EfxForblazeBG2[];
extern u16 Pal3_EfxForblazeBG2[];
extern u16 Pal4_EfxForblazeBG2[];
extern u16 Tsa1_EfxForblazeBG2[];
extern u16 Tsa2_EfxForblazeBG2[];
extern u16 Img_EfxForblazeOBJ[];
extern u16 Pal_EfxForblazeOBJ[];
extern u16 Img_EfxFimbulvetrBG_08144A20[];
extern u16 Img_EfxFimbulvetrBG_08145CF0[];
extern u16 Img_EfxFimbulvetrBG_081475A0[];
extern u16 Img_EfxFimbulvetrBG_081489E4[];
extern u16 Pal_EfxFimbulvetrBG[];
extern u16 Tsa_EfxFimbulvetrBG_0814A4B8[];
extern u16 Tsa_EfxFimbulvetrBG_0814A55C[];
extern u16 Tsa_EfxFimbulvetrBG_0814A604[];
extern u16 Tsa_EfxFimbulvetrBG_0814A6C0[];
extern u16 Tsa_EfxFimbulvetrBG_0814A794[];
extern u16 Tsa_EfxFimbulvetrBG_0814A890[];
extern u16 Tsa_EfxFimbulvetrBG_0814A9D0[];
extern u16 Tsa_EfxFimbulvetrBG_0814AB68[];
extern u16 Tsa_EfxFimbulvetrBG_0814AD3C[];
extern u16 Tsa_EfxFimbulvetrBG_0814AF4C[];
extern u16 Tsa_EfxFimbulvetrBG_0814B16C[];
extern u16 Img_EfxFimbulvetrBGTR_0814B39C[];
extern u16 Img_EfxFimbulvetrBGTR_0814C5A4[];
extern u16 Img_EfxFimbulvetrBGTR_0814D700[];
extern u16 Img_EfxFimbulvetrBGTR_0814E784[];
extern u16 Img_EfxFimbulvetrBGTR_0814FBC4[];
extern u16 Img_EfxFimbulvetrBGTR_08150F7C[];
extern u16 Pal_EfxFimbulvetrBGTR[];
extern u16 Tsa_EfxFimbulvetrBGTR_081521E0[];
extern u16 Tsa_EfxFimbulvetrBGTR_081523CC[];
extern u16 Tsa_EfxFimbulvetrBGTR_081525A4[];
extern u16 Tsa_EfxFimbulvetrBGTR_0815276C[];
extern u16 Tsa_EfxFimbulvetrBGTR_081529A0[];
extern u16 Tsa_EfxFimbulvetrBGTR_08152BE8[];
extern u16 Img_EfxFimbulvetrOBJ[];
extern u16 Img_EfxLightningBG_081531C8[];
extern u16 Img_EfxLightningBG_08153A90[];
extern u16 Img_EfxLightningBG_081541E0[];
extern u16 Img_EfxLightningBG_08154BA4[];
extern u16 Img_EfxLightningBG_081556F8[];
extern u16 Img_EfxLightningBG_08156200[];
extern u16 Img_EfxLightningBG_08156518[];
extern u16 Img_EfxLightningBG_081571C8[];
extern u16 Pal_EfxLightningBG_08157BE8[];
extern u16 Pal_EfxLightningBG_08157C08[];
extern u16 Tsa_EfxLightningBG_08157C28[];
extern u16 Tsa_EfxLightningBG_08157D4C[];
extern u16 Tsa_EfxLightningBG_08157E6C[];
extern u16 Tsa_EfxLightningBG_08157F78[];
extern u16 Tsa_EfxLightningBG_08158074[];
extern u16 Tsa_EfxLightningBG_0815815C[];
extern u16 Tsa_EfxLightningBG_08158244[];
extern u16 Tsa_EfxLightningBG_08158328[];
extern u16 Tsa_EfxLightningBG_08158404[];
extern u16 Tsa_EfxLightningBG_081584E4[];
extern u16 Tsa_EfxLightningBG_081585D8[];
extern u16 Tsa_EfxLightningBG_081586CC[];
extern u16 Tsa_EfxLightningBG_081587D0[];
extern u16 Tsa_EfxLightningBG_081588D8[];
extern u16 Tsa_EfxLightningBG_081589F0[];
extern u16 Tsa_EfxLightningBG_08158B14[];
extern u16 Tsa_EfxLightningBG_08158C28[];
extern u16 Tsa_EfxLightningBG_08158CD8[];
extern u16 Tsa_EfxLightningBG_08158DE0[];
extern u16 Tsa_EfxLightningBG_08158F1C[];
extern u16 Tsa_EfxLightningBG_08159090[];
extern u16 Tsa_EfxLightningBG_08159228[];
extern u16 Tsa_EfxLightningBG_0815939C[];
extern u16 Tsa_EfxLightningBG_081594A8[];
extern u16 Tsa_EfxLightningBG_0815957C[];
extern u16 Tsa_EfxLightningBG_0815961C[];
extern u16 Tsa_EfxLightningBG_0815973C[];
extern u16 Tsa_EfxLightningBG_08159858[];
extern u16 Tsa_EfxLightningBG_0815996C[];
extern u16 Tsa_EfxLightningBG_08159A64[];
extern u16 Tsa_EfxLightningBG_08159B4C[];
extern u16 Tsa_EfxLightningBG_08159C1C[];
extern u16 Tsa_EfxLightningBG_08159CE0[];
extern u16 Img_EfxAlacaliburBG[];
extern u16 Pal_EfxAlacaliburBGCOL[];
extern u16 Tsa_EfxAlacaliburBG_0815B424[];
extern u16 Tsa_EfxAlacaliburBG_0815B5AC[];
extern u16 Img_EfxAlacaliburOBJ[];
extern u16 Pal_EfxAlacaliburOBJ[];
extern u16 Img_EfxMistyrainBG_0815BEF4[];
extern u16 Img_EfxMistyrainBG_0815CAC4[];
extern u16 Img_EfxMistyrainBG_0815D7D4[];
extern u16 Img_EfxMistyrainBG_0815EA30[];
extern u16 Img_EfxMistyrainBG_0815F0B4[];
extern u16 Img_EfxMistyrainBG_0815F610[];
extern u16 Pal_EfxMistyrainBG1[];
extern u16 Tsa_EfxMistyrainBG_0815F8C0[];
extern u16 Tsa_EfxMistyrainBG_0815F9BC[];
extern u16 Tsa_EfxMistyrainBG_0815FABC[];
extern u16 Tsa_EfxMistyrainBG_0815FBC0[];
extern u16 Tsa_EfxMistyrainBG_0815FCB8[];
extern u16 Tsa_EfxMistyrainBG_0815FDC4[];
extern u16 Tsa_EfxMistyrainBG_0815FED0[];
extern u16 Tsa_EfxMistyrainBG_0815FFF0[];
extern u16 Tsa_EfxMistyrainBG_08160114[];
extern u16 Tsa_EfxMistyrainBG_081601FC[];
extern u16 Tsa_EfxMistyrainBG_081602D8[];
extern u16 Tsa_EfxMistyrainBG_08160398[];
extern u16 Tsa_EfxMistyrainBG_08160450[];
extern u16 Tsa_EfxMistyrainBG_081604F8[];
extern u16 Tsa_EfxMistyrainBG_081605B4[];
extern u16 Tsa_EfxMistyrainBG_0816068C[];
extern u16 Tsa_EfxMistyrainBG_0816076C[];
extern u16 Tsa_EfxMistyrainBG_0816085C[];
extern u16 Tsa_EfxMistyrainBG_08160958[];
extern u16 Tsa_EfxMistyrainBG_08160A4C[];
extern u16 Tsa_EfxMistyrainBG_08160B44[];
extern u16 Tsa_EfxMistyrainBG_08160C30[];
extern u16 Tsa_EfxMistyrainBG_08160D14[];
extern u16 Tsa_EfxMistyrainBG_08160DEC[];
extern u16 Tsa_EfxMistyrainBG_08160EBC[];
extern u16 Tsa_EfxMistyrainBG_08160F88[];
extern u16 Tsa_EfxMistyrainBG_08161050[];
extern u16 Tsa_EfxMistyrainBG_08161104[];
extern u16 Tsa_EfxMistyrainBG_081611B8[];
extern u16 Tsa_EfxMistyrainBG_08161258[];
extern u16 Tsa_EfxMistyrainBG_0816130C[];
extern u16 Tsa_EfxMistyrainBG_081613C8[];
extern u16 Tsa_EfxMistyrainBG_081614A4[];
extern u16 Tsa_EfxMistyrainBG_0816158C[];
extern u16 Tsa_EfxMistyrainBG_081616B0[];
extern u16 Tsa_EfxMistyrainBG_081617D0[];
extern u16 Tsa_EfxMistyrainBG_081618DC[];
extern u16 Tsa_EfxMistyrainBG_081619E8[];
extern u16 Tsa_EfxMistyrainBG_08161AE4[];
extern u16 Tsa_EfxMistyrainBG_08161BE4[];
extern u16 Tsa_EfxMistyrainBG_08161CE0[];
extern u16 Pal_EfxMistyrainBG2[];
extern u16 Img_EfxMistyrainOBJ1_1[];
extern u16 Img_EfxMistyrainOBJ1_2[];
extern u16 Img_EfxMistyrainOBJ1_3[];
extern u16 Pal_EfxMistyrainOBJ1[];
extern u16 Img_EfxResireBG_081629F4[];
extern u16 Img_EfxResireBG_081634C4[];
extern u16 Img_EfxResireBG_0816406C[];
extern u16 Img_EfxResireBG_08164BC4[];
extern u16 Img_EfxResireBG_08165678[];
extern u16 Img_EfxResireBG_08166148[];
extern u16 Img_EfxResireBG_08166E0C[];
extern u16 Img_EfxResireBG_08167710[];
extern u16 Img_EfxResireBG_08167C64[];
extern u16 Img_EfxResireBG_0816857C[];
extern u16 Img_EfxResireBG_081691B0[];
extern u16 Img_EfxResireBG_08169E54[];
extern u16 Img_EfxResireBG_0816AA48[];
extern u16 Pal_EfxResireBG[];
extern u16 Tsa_EfxResireBG_0816B348[];
extern u16 Tsa_EfxResireBG_0816B478[];
extern u16 Tsa_EfxResireBG_0816B524[];
extern u16 Tsa_EfxResireBG_0816B5D4[];
extern u16 Tsa_EfxResireBG_0816B68C[];
extern u16 Tsa_EfxResireBG_0816B74C[];
extern u16 Tsa_EfxResireBG_0816B818[];
extern u16 Tsa_EfxResireBG_0816B8F8[];
extern u16 Tsa_EfxResireBG_0816B9E0[];
extern u16 Tsa_EfxResireBG_0816BAE8[];
extern u16 Tsa_EfxResireBG_0816BC04[];
extern u16 Tsa_EfxResireBG_0816BD40[];
extern u16 Tsa_EfxResireBG_0816BE90[];
extern u16 Tsa_EfxResireBG_0816BFE8[];
extern u16 Tsa_EfxResireBG_0816C140[];
extern u16 Tsa_EfxResireBG_0816C294[];
extern u16 Tsa_EfxResireBG_0816C3E4[];
extern u16 Tsa_EfxResireBG_0816C534[];
extern u16 Tsa_EfxResireBG_0816C66C[];
extern u16 Tsa_EfxResireBG_0816C798[];
extern u16 Tsa_EfxResireBG_0816C8B4[];
extern u16 Tsa_EfxResireBG_0816C9C0[];
extern u16 Tsa_EfxResireBG_0816CAB8[];
extern u16 Tsa_EfxResireBG_0816CBA4[];
extern u16 Tsa_EfxResireBG_0816CC74[];
extern u16 Tsa_EfxResireBG_0816CD30[];
extern u16 Tsa_EfxResireBG_0816CDE4[];
extern u16 Tsa_EfxResireBG_0816CE94[];
extern u16 Tsa_EfxResireBG_0816CF40[];
extern u16 Tsa_EfxResireBG_0816CFE8[];
extern u16 Tsa_EfxResireBG_0816D09C[];
extern u16 Tsa_EfxResireBG_0816D15C[];
extern u16 Tsa_EfxResireBG_0816D228[];
extern u16 Tsa_EfxResireBG_0816D2F0[];
extern u16 Tsa_EfxResireBG_0816D3B8[];
extern u16 Tsa_EfxResireBG_0816D48C[];
extern u16 Tsa_EfxResireBG_0816D568[];
extern u16 Tsa_EfxResireBG_0816D650[];
extern u16 Tsa_EfxResireBG_0816D744[];
extern u16 Tsa_EfxResireBG_0816D84C[];
extern u16 Tsa_EfxResireBG_0816D954[];
extern u16 Tsa_EfxResireBG_0816DA78[];
extern u16 Tsa_EfxResireBG_0816DB98[];
extern u16 Tsa_EfxResireBG_0816DCB4[];
extern u16 Tsa_EfxResireBG_0816DDC4[];
extern u16 Tsa_EfxResireBG_0816DED0[];
extern u16 Tsa_EfxResireBG_0816DFD0[];
extern u16 Tsa_EfxResireBG_0816E0C0[];
extern u16 Tsa_EfxResireBG_0816E19C[];
extern u16 Tsa_EfxResireBG_0816E268[];
extern u16 Tsa_EfxResireBG_0816E320[];
extern u16 Img_EfxDivineBG1_081762DC[];
extern u16 Img_EfxDivineBG3_0816E3CC[];
extern u16 Img_EfxDivineBG3_0816E980[];
extern u16 Img_EfxDivineBG3_0816F048[];
extern u16 Img_EfxDivineBG3_0816F688[];
extern u16 Img_EfxDivineBG3_0816FC90[];
extern u16 Img_EfxDivineBG3_081702F0[];
extern u16 Img_EfxDivineBG3_08170960[];
extern u16 Img_EfxDivineBG3_08170F9C[];
extern u16 Img_EfxDivineBG3_081715E4[];
extern u16 Img_EfxDivineBG3_08171CE8[];
extern u16 Img_EfxDivineBG3_081724A0[];
extern u16 Img_EfxDivineBG3_08172C94[];
extern u16 Img_EfxDivineBG3_0817346C[];
extern u16 Img_EfxDivineBG3_08173C88[];
extern u16 Img_EfxDivineBG3_08174408[];
extern u16 Img_EfxDivineBG3_08174B9C[];
extern u16 Img_EfxDivineBG3_081752D0[];
extern u16 Img_EfxDivineBG3_08175D7C[];
extern u16 Pal_EfxDivineBG3[];
extern u16 Pal_EfxDivineBG[];
extern u16 Tsa_EfxDivineBG3_08176A8C[];
extern u16 Tsa_EfxDivineBG3_08176C20[];
extern u16 Tsa_EfxDivineBG3_08176E24[];
extern u16 Tsa_EfxDivineBG3_081770F4[];
extern u16 Tsa_EfxDivineBG3_081773C4[];
extern u16 Tsa_EfxDivineBG3_08177674[];
extern u16 Tsa_EfxDivineBG3_08177928[];
extern u16 Tsa_EfxDivineBG3_08177BB4[];
extern u16 Tsa_EfxDivineBG3_08177E38[];
extern u16 Tsa_EfxDivineBG3_081780AC[];
extern u16 Tsa_EfxDivineBG3_08178340[];
extern u16 Tsa_EfxDivineBG3_081785C8[];
extern u16 Tsa_EfxDivineBG3_08178864[];
extern u16 Tsa_EfxDivineBG3_08178AEC[];
extern u16 Tsa_EfxDivineBG3_08178D68[];
extern u16 Tsa_EfxDivineBG3_08178F98[];
extern u16 Tsa_EfxDivineBG3_081791E8[];
extern u16 Tsa_EfxDivineBG3_08179418[];
extern u16 Tsa_EfxDivineBG3_08179610[];
extern u16 Tsa_EfxDivineBG3_081797F4[];
extern u16 Tsa_EfxDivineBG3_08179990[];
extern u16 Tsa_EfxDivineBG1_08179AB8[];
extern u16 Tsa_EfxDivineBG1_08179B58[];
extern u16 Tsa_EfxDivineBG1_08179C00[];
extern u16 Tsa_EfxDivineBG1_08179CA8[];
extern u16 Tsa_EfxDivineBG1_08179D58[];
extern u16 Tsa_EfxDivineBG1_08179E10[];
extern u16 Tsa_EfxDivineBG1_08179EDC[];
extern u16 Tsa_EfxDivineBG1_08179FA8[];
extern u16 Tsa_EfxDivineBG1_0817A07C[];
extern u16 Tsa_EfxDivineBG1_0817A154[];
extern u16 Tsa_EfxDivineBG1_0817A230[];
extern u16 Tsa_EfxDivineBG1_0817A30C[];
extern u16 Tsa_EfxDivineBG1_0817A3F0[];
extern u16 Tsa_EfxDivineBG1_0817A4A4[];
extern u16 Tsa_EfxDivineBG1_0817A540[];
extern u16 Tsa_EfxDivineBG1_0817A5DC[];
extern u16 Tsa_EfxDivineBG1_0817A678[];
extern u16 Tsa_EfxDivineBG1_0817A714[];
extern u16 Tsa_EfxDivineBG1_0817A7B0[];
extern u16 Tsa_EfxDivineBG1_0817A84C[];
extern u16 Tsa_EfxDivineBG2_0817A8E8[];
extern u16 Tsa_EfxDivineBG2_0817A984[];
extern u16 Tsa_EfxDivineBG2_0817AA20[];
extern u16 Img_EfxDivineOBJ[];
extern u16 Pal_EfxDivineOBJ[];
// extern ??? gUnk_0817AC4C
extern u16  Pal_EfxApocalypse_0817B418[];
// extern ??? gUnk_0817B438
extern u16  Img_EfxApocalypseOBJ[];
extern u16  Pal_EfxApocalypseOBJ[];
// extern ??? Pals_EfxApocalypseBGCOL2
extern u16 Img_EfxApocalypseBG2_0817BBD4[];
extern u16 Img_EfxApocalypseBG2_0817D4E0[];
extern u16 Img_EfxApocalypseBG2_0817ED8C[];
extern u16 Img_EfxApocalypseBG2_081804F4[];
extern u16  Pal_EfxApocalypseBG2[];
extern u16 Tsa_EfxApocalypseBG2_08181E80[];
extern u16 Tsa_EfxApocalypseBG2_08182320[];
extern u16 Tsa_EfxApocalypseBG2_081827B0[];
extern u16 Tsa_EfxApocalypseBG2_08182C4C[];
extern u16  Img_EfxApocalypseOBJ2_1[];
extern u16  Img_EfxApocalypseOBJ2_2[];
extern u16 Img_EfxHazymoonBG_0818398C[];
extern u16 Img_EfxHazymoonBG_08183CD4[];
extern u16 Img_EfxHazymoonBG_081845A8[];
extern u16 Img_EfxHazymoonBG_081855E4[];
extern u16 Img_EfxHazymoonBG_08186250[];
extern u16 Img_EfxHazymoonBG_08186E6C[];
extern u16 Img_EfxHazymoonBG_081879C4[];
extern u16 Img_EfxHazymoonBG_08188518[];
extern u16 Img_EfxHazymoonBG_08188FC8[];
extern u16 Img_EfxHazymoonBG_081899F0[];
extern u16 Img_EfxHazymoonBG_0818A2EC[];
extern u16 Img_EfxHazymoonBG_0818ABB8[];
extern u16 Img_EfxHazymoonBG_0818B438[];
extern u16  Pal_EfxHazymoonBG2[];
extern u16  Pal_EfxHazymoonBG3[];
extern u16 Tsa_EfxHazymoonBG_0818BC0C[];
extern u16 Tsa_EfxHazymoonBG_0818BDB0[];
extern u16 Tsa_EfxHazymoonBG_0818BE50[];
extern u16 Tsa_EfxHazymoonBG_0818BEF0[];
extern u16 Tsa_EfxHazymoonBG_0818BFA4[];
extern u16 Tsa_EfxHazymoonBG_0818C058[];
extern u16 Tsa_EfxHazymoonBG_0818C10C[];
extern u16 Tsa_EfxHazymoonBG_0818C1E8[];
extern u16 Tsa_EfxHazymoonBG_0818C2C4[];
extern u16 Tsa_EfxHazymoonBG_0818C3D8[];
extern u16 Tsa_EfxHazymoonBG_0818C4EC[];
extern u16 Tsa_EfxHazymoonBG_0818C600[];
extern u16 Tsa_EfxHazymoonBG_0818C714[];
extern u16 Tsa_EfxHazymoonBG_0818C828[];
extern u16 Tsa_EfxHazymoonBG_0818C934[];
extern u16 Tsa_EfxHazymoonBG_0818CA0C[];
extern u16 Tsa_EfxHazymoonBG_0818CB1C[];
extern u16 Tsa_EfxHazymoonBG_0818CC84[];
extern u16 Tsa_EfxHazymoonBG_0818CE48[];
extern u16 Tsa_EfxHazymoonBG_0818D00C[];
extern u16 Tsa_EfxHazymoonBG_0818D1C8[];
extern u16 Tsa_EfxHazymoonBG_0818D378[];
extern u16 Tsa_EfxHazymoonBG_0818D528[];
extern u16 Tsa_EfxHazymoonBG_0818D6D8[];
extern u16 Tsa_EfxHazymoonBG_0818D87C[];
extern u16 Tsa_EfxHazymoonBG_0818DA14[];
extern u16 Tsa_EfxHazymoonBG_0818DBA4[];
extern u16  Img_EfxHazymoonOBJ2_1[];
extern u16  Img_EfxHazymoonOBJ2_2[];
extern u16  Img_EfxHazymoonOBJ2_3[];
extern u16  Pal_EfxHazymoonOBJ2[];
extern u16  Img_EfxFenrirBG[];
extern u16  Pal_EfxFenrirBGCOL[];
extern u16  Tsa_EfxFenrirBG[];
extern u16 Img_EfxFenrirBG2_A_0818F5EC[];
extern u16 Img_EfxFenrirBG2_A_08190804[];
extern u16 Img_EfxFenrirBG2_A_08191B54[];
extern u16 Img_EfxFenrirBG2_A_081929D0[];
extern u16  Pal_EfxFenrirBG2_A[];
extern u16  Pal_EfxFenrirBG2_B[];
extern u16 Tsa_EfxFenrirBG2_A_081935D8[];
extern u16 Tsa_EfxFenrirBG2_A_08193694[];
extern u16 Tsa_EfxFenrirBG2_A_08193750[];
extern u16 Tsa_EfxFenrirBG2_A_0819380C[];
extern u16 Tsa_EfxFenrirBG2_A_081938C8[];
extern u16 Tsa_EfxFenrirBG2_A_08193984[];
extern u16 Tsa_EfxFenrirBG2_A_08193A40[];
extern u16 Tsa_EfxFenrirBG2_A_08193B44[];
extern u16 Tsa_EfxFenrirBG2_A_08193C48[];
extern u16 Tsa_EfxFenrirBG2_A_08193D4C[];
extern u16 Tsa_EfxFenrirBG2_A_08193E50[];
extern u16 Tsa_EfxFenrirBG2_A_08193F54[];
extern u16 Tsa_EfxFenrirBG2_A_08194058[];
extern u16 Tsa_EfxFenrirBG2_A_08194198[];
extern u16 Tsa_EfxFenrirBG2_A_081942DC[];
extern u16 Tsa_EfxFenrirBG2_A_08194420[];
extern u16 Tsa_EfxFenrirBG2_A_08194564[];
extern u16 Tsa_EfxFenrirBG2_A_081946A8[];
extern u16 Tsa_EfxFenrirBG2_A_081947EC[];
extern u16 Tsa_EfxFenrirBG2_A_0819496C[];
extern u16 Tsa_EfxFenrirBG2_A_08194AF0[];
extern u16 Tsa_EfxFenrirBG2_A_08194C74[];
extern u16 Tsa_EfxFenrirBG2_A_08194DD4[];
extern u16 Tsa_EfxFenrirBG2_A_08194F34[];
extern u16 Tsa_EfxFenrirBG2_A_08195094[];
extern u16 Tsa_EfxFenrirBG2_A_08195238[];
extern u16 Tsa_EfxFenrirBG2_A_081953DC[];
extern u16 Tsa_EfxFenrirBG2_A_08195580[];
extern u16 Tsa_EfxFenrirBG2_A_081956F0[];
extern u16 Tsa_EfxFenrirBG2_A_08195860[];
extern u16 Tsa_EfxFenrirBG2_A_081959D0[];
extern u16 Tsa_EfxFenrirBG2_A_08195B74[];
extern u16 Tsa_EfxFenrirBG2_A_08195D18[];
extern u16 Tsa_EfxFenrirBG2_A_08195EBC[];
extern u16 Tsa_EfxFenrirBG2_A_08196030[];
extern u16 Tsa_EfxFenrirBG2_A_081961A4[];
extern u16 Tsa_EfxFenrirBG2_A_08196318[];
extern u16 Tsa_EfxFenrirBG2_A_081964C8[];
extern u16 Tsa_EfxFenrirBG2_A_08196678[];
extern u16 Tsa_EfxFenrirBG2_A_08196828[];
extern u16 Tsa_EfxFenrirBG2_A_0819699C[];
extern u16 Tsa_EfxFenrirBG2_A_08196B10[];
extern u16 Tsa_EfxFenrirBG2_A_08196C84[];
extern u16 Tsa_EfxFenrirBG2_A_08196E38[];
extern u16 Tsa_EfxFenrirBG2_A_08196FEC[];
extern u16 Tsa_EfxFenrirBG2_A_081971A0[];
extern u16 Tsa_EfxFenrirBG2_A_08197318[];
extern u16 Tsa_EfxFenrirBG2_A_08197490[];
extern u16 Tsa_EfxFenrirBG2_A_08197608[];
extern u16 Tsa_EfxFenrirBG2_A_08197860[];
extern u16 Tsa_EfxFenrirBG2_A_08197A68[];
extern u16  Img_EfxFenrirOBJ[];
extern u16  Pal_EfxFenrirOBJ[];
extern u16  Pal_EfxFenrirOBJ2[];
extern u16 Img_EfxPurgeBG_0819879C[];
extern u16 Img_EfxPurgeBG_08198CF8[];
extern u16 Img_EfxPurgeBG_08199374[];
extern u16 Img_EfxPurgeBG_081999C0[];
extern u16 Img_EfxPurgeBG_0819A174[];
extern u16 Img_EfxPurgeBG_0819A87C[];
extern u16 Img_EfxPurgeBG_0819AD98[];
extern u16 Img_EfxPurgeBG_0819B698[];
extern u16 Img_EfxPurgeBG_0819C04C[];
extern u16 Img_EfxPurgeBG_0819C9C0[];
extern u16 Img_EfxPurgeBG_0819D394[];
extern u16 Img_EfxPurgeBG_0819E398[];
extern u16 Img_EfxPurgeBG_0819F1E8[];
extern u16 Img_EfxPurgeBG_0819FCCC[];
extern u16 Img_EfxPurgeBG_081A0874[];
extern u16 Img_EfxPurgeBG_081A1410[];
extern u16 Img_EfxPurgeBG_081A1ED0[];
extern u16 Img_EfxPurgeBG_081A2948[];
extern u16 Pal_EfxPurgeBG_00000000[];
extern u16 Pal_EfxPurgeBG_081A3C4C[];
extern u16 Pal_EfxPurgeBG_081A3C6C[];
extern u16 Tsa_EfxPurgeBG_00000000[];
extern u16 Tsa_EfxPurgeBG_081A3C8C[];
extern u16 Tsa_EfxPurgeBG_081A3DB0[];
extern u16 Tsa_EfxPurgeBG_081A3ED0[];
extern u16 Tsa_EfxPurgeBG_081A3FDC[];
extern u16 Tsa_EfxPurgeBG_081A40D8[];
extern u16 Tsa_EfxPurgeBG_081A41C0[];
extern u16 Tsa_EfxPurgeBG_081A42A8[];
extern u16 Tsa_EfxPurgeBG_081A4388[];
extern u16 Tsa_EfxPurgeBG_081A4464[];
extern u16 Tsa_EfxPurgeBG_081A4544[];
extern u16 Tsa_EfxPurgeBG_081A4638[];
extern u16 Tsa_EfxPurgeBG_081A472C[];
extern u16 Tsa_EfxPurgeBG_081A4830[];
extern u16 Tsa_EfxPurgeBG_081A4938[];
extern u16 Tsa_EfxPurgeBG_081A4A50[];
extern u16 Tsa_EfxPurgeBG_081A4B74[];
extern u16 Tsa_EfxPurgeBG_081A4C88[];
extern u16 Tsa_EfxPurgeBG_081A4DAC[];
extern u16 Tsa_EfxPurgeBG_081A4ED0[];
extern u16 Tsa_EfxPurgeBG_081A4FE0[];
extern u16 Tsa_EfxPurgeBG_081A50E0[];
extern u16 Tsa_EfxPurgeBG_081A51C8[];
extern u16 Tsa_EfxPurgeBG_081A52A8[];
extern u16 Tsa_EfxPurgeBG_081A5384[];
extern u16 Tsa_EfxPurgeBG_081A5460[];
extern u16 Tsa_EfxPurgeBG_081A5544[];
extern u16 Tsa_EfxPurgeBG_081A5638[];
extern u16 Tsa_EfxPurgeBG_081A5728[];
extern u16 Tsa_EfxPurgeBG_081A582C[];
extern u16 Tsa_EfxPurgeBG_081A5934[];
extern u16 Tsa_EfxPurgeBG_081A5A48[];
extern u16 Tsa_EfxPurgeBG_081A5B6C[];
extern u16 Tsa_EfxPurgeBG_081A5C80[];
extern u16 Tsa_EfxPurgeBG_081A5DA4[];
extern u16 Tsa_EfxPurgeBG_081A5EC4[];
extern u16 Tsa_EfxPurgeBG_081A5FD0[];
extern u16 Tsa_EfxPurgeBG_081A60CC[];
extern u16 Tsa_EfxPurgeBG_081A61B4[];
extern u16 Tsa_EfxPurgeBG_081A629C[];
extern u16 Tsa_EfxPurgeBG_081A637C[];
extern u16 Tsa_EfxPurgeBG_081A6458[];
extern u16 Tsa_EfxPurgeBG_081A6538[];
extern u16 Tsa_EfxPurgeBG_081A662C[];
extern u16 Tsa_EfxPurgeBG_081A6720[];
extern u16 Tsa_EfxPurgeBG_081A6824[];
extern u16 Tsa_EfxPurgeBG_081A692C[];
extern u16 Tsa_EfxPurgeBG_081A6A44[];
extern u16 Tsa_EfxPurgeBG_081A6B68[];
extern u16 Tsa_EfxPurgeBG_081A6C78[];
extern u16 Tsa_EfxPurgeBG_081A6E8C[];
extern u16 Tsa_EfxPurgeBG_081A7048[];
extern u16 Tsa_EfxPurgeBG_081A7224[];
extern u16 Tsa_EfxPurgeBG_081A7428[];
extern u16 Tsa_EfxPurgeBG_081A7630[];
extern u16 Tsa_EfxPurgeBG_081A7844[];
extern u16 Tsa_EfxPurgeBG_081A7AA4[];
extern u16 Tsa_EfxPurgeBG_081A7CD8[];
extern u16 Tsa_EfxPurgeBG_081A7F4C[];
extern u16 Tsa_EfxPurgeBG_081A8194[];
extern u16 Tsa_EfxPurgeBG_081A84F4[];
extern u16 Tsa_EfxPurgeBG_081A8848[];
extern u16 Tsa_EfxPurgeBG_081A8B58[];
extern u16 Tsa_EfxPurgeBG_081A8E3C[];
extern u16 Tsa_EfxPurgeBG_081A910C[];
extern u16 Tsa_EfxPurgeBG_081A93A4[];
extern u16 Tsa_EfxPurgeBG_081A963C[];
extern u16 Tsa_EfxPurgeBG_081A9868[];
extern u16 Tsa_EfxPurgeBG_081A9B1C[];
extern u16 Tsa_EfxPurgeBG_081A9DDC[];
extern u16 Tsa_EfxPurgeBG_081AA10C[];
extern u16 Tsa_EfxPurgeBG_081AA45C[];
extern u16 Tsa_EfxPurgeBG_081AA7D4[];
extern u16 Tsa_EfxPurgeBG_081AAB5C[];
extern u16 Img_EfxPurgeOBJ[];
extern u16 Pal_EfxPurgeOBJ[];
extern u16  Img_EfxHealCommon[];
extern u16  Tsa_Uncomp_EfxLiveBG_BB_L[];
// extern ??? Pals1_EfxLiveBGCOL[];
extern u16  Img_EfxLiveOBJ[];
extern u16 Pal_EfxFimbulvetrOBJ[];
extern u16  Img_EfxLiveBG[];
extern u16  Tsa_Uncomp_EfxLiveBG_BA_L[];
extern u16  Tsa_Uncomp_EfxLiveBG_BA_R[];
// extern ??? Pals3_EfxLiveBGCOL[];
// extern ??? Pals2_EfxLiveBGCOL[];
extern u16 Tsa_EfxReserveBG_081ADFEC[];
extern u16 Tsa_EfxReserveBG_081AE0F8[];
extern u16 Tsa_EfxReserveBG_081AE1F8[];
extern u16 Tsa_EfxReserveBG_081AE304[];
extern u16 Tsa_EfxReserveBG2_081AE410[];
// extern ??? Pals1_EfxReserveBGCOL[];
// extern ??? Pals2_EfxReserveBGCOL[];
// extern ??? Pals2_EfxReserveBGCOL2[];
extern u16 Img_EfxRestBG_081AFC70[];
extern u16 Img_EfxRestBG_081B029C[];
extern u16 Img_EfxRestBG_081B0994[];
extern u16 Img_EfxRestBG_081B0FB4[];
extern u16 const Pal_EfxRestBG[];
extern u16 Tsa_EfxRestBG_081B1730[];
extern u16 Tsa_EfxRestBG_081B17DC[];
extern u16 Tsa_EfxRestBG_081B1890[];
extern u16 Tsa_EfxRestBG_081B1950[];
extern u16 Tsa_EfxRestBG_081B1A18[];
extern u16 Tsa_EfxRestBG_081B1AF4[];
extern u16 Tsa_EfxRestBG_081B1BD4[];
extern u16 Tsa_EfxRestBG_081B1CBC[];
extern u16 Tsa_EfxRestBG_081B1DAC[];
extern u16 Tsa_EfxRestBG_081B1EAC[];
extern u16 Tsa_EfxRestBG_081B1FB8[];
extern u16 Tsa_EfxRestBG_081B20D8[];
extern u16 Tsa_EfxRestBG_081B2208[];
extern u16  Img_EfxSilenceBG[];
extern u16 Tsa_EfxSilenceBG_081B2E10[];
extern u16 Tsa_EfxSilenceBG_081B2F0C[];
extern u16 Tsa_EfxSilenceBG_081B2FF4[];
extern u16 Tsa_EfxSilenceBG_081B30DC[];
extern u16 Tsa_EfxSilenceBG_081B31C4[];
extern u16 Tsa_EfxSilenceBG_081B32C0[];
extern u16 Tsa_EfxSilenceBG_081B33A8[];
extern u16 Tsa_EfxSilenceBG_081B3440[];
extern u16 Tsa_EfxSilenceBG_081B3528[];
extern u16 Tsa_EfxSilenceBG_081B35C0[];
extern u16 Tsa_EfxSilenceBG_081B36A8[];
extern u16 Tsa_EfxSilenceBG_081B37A4[];
extern u16 Tsa_EfxSilenceBG_081B383C[];
extern u16 Tsa_EfxSilenceBG_081B3924[];
extern u16 Tsa_EfxSilenceBG_081B39BC[];
extern u16 Tsa_EfxSilenceBG_081B3AB8[];
extern u16 Tsa_EfxSilenceBG_081B3B50[];
extern u16 Tsa_EfxSilenceBG_081B3C60[];
extern u16  Img_EfxSilenceOBJ[];
extern u16  Pal_EfxSilenceBG[];
extern u16 const Pal_EfxHammarneBG[];
extern u16 Tsa_EfxHammarneBG_081B4294[];
extern u16 Tsa_EfxHammarneBG_081B4340[];
extern u16 Tsa_EfxHammarneBG_081B43F0[];
extern u16 Tsa_EfxHammarneBG_081B44B0[];
extern u16 Tsa_EfxHammarneBG_081B4578[];
extern u16 Tsa_EfxHammarneBG_081B4650[];
extern u16 Tsa_EfxHammarneBG_081B472C[];
extern u16 Tsa_EfxHammarneBG_081B4814[];
extern u16 Tsa_EfxHammarneBG_081B4904[];
extern u16 Tsa_EfxHammarneBG_081B4A04[];
extern u16 Tsa_EfxHammarneBG_081B4B10[];
extern u16 Tsa_EfxHammarneBG_081B4C30[];
extern u16 Tsa_EfxHammarneBG_081B4D60[];
extern u16  Img_EfxBerserkBG[];
extern u16  Tsa_EfxBerserkBG[];
extern u16  Img_EfxSleepBG[];
extern u16  Pal_EfxSleepBG[];
extern u16 Tsa_EfxSleepBG_081B66A8[];
extern u16 Tsa_EfxSleepBG_081B6784[];
extern u16 Tsa_EfxSleepBG_081B6860[];
extern u16 Tsa_EfxSleepBG_081B693C[];
extern u16 Tsa_EfxSleepBG_081B6A18[];
extern u16 Tsa_EfxSleepBG_081B6AF4[];
extern u16 Tsa_EfxSleepBG_081B6BD0[];
extern u16 Tsa_EfxSleepBG_081B6CAC[];
extern u16 Tsa_EfxSleepBG_081B6D88[];
extern u16 Tsa_EfxSleepBG_081B6E64[];
extern u16 Tsa_EfxSleepBG_081B6F40[];
extern u16 Tsa_EfxSleepBG_081B701C[];
extern u16 Tsa_EfxSleepBG_081B70F8[];
extern u16 Tsa_EfxSleepBG_081B71D4[];
extern u16 Tsa_EfxSleepBG_081B72B0[];
extern u16 Tsa_EfxSleepBG_081B738C[];
extern u16 const Img_EfxHammarneOBJ[];
extern u16 const Pal_EfxRestOBJ[];
extern u16  Pal_EfxHammarneOBJ[];
extern u16  Pal_EfxBerserkBG[];
extern u16  Img_EfxBerserk1[];
extern u16  Img_EfxBerserk2[];
extern u16  Pal_EfxBerserk[];
extern u16  Img_EfxMshieldBG[];
extern u16 const Pal_EfxMshieldBG[];
extern u16 Tsa_EfxMshieldBG_081B8974[];
extern u16 Tsa_EfxMshieldBG_081B8A2C[];
extern u16 Tsa_EfxMshieldBG_081B8AF0[];
extern u16 Tsa_EfxMshieldBG_081B8BE0[];
extern u16 Tsa_EfxMshieldBG_081B8D10[];
extern u16  Pal_EfxMshieldOBJ[];
extern u16  Img_EfxAureolaBG2[];
extern u16 Img_EfxAureolaBG_081BA374[];
extern u16  Pal_EfxAureolaBG[];
extern u16  Pal_EfxAureolaBG2[];
extern u16 Tsa_EfxAureolaBG_081BB3DC[];
extern u16  Tsa_EfxAureolaBG2[];
extern u16 Tsa_EfxAureolaBG_081BB75C[];
extern u16 Tsa_EfxAureolaBG_081BB8E0[];
extern u16 Tsa_EfxAureolaBG_081BBA04[];
extern u16 Tsa_EfxAureolaBG_081BBB00[];
extern u16  Img_EfxAureolaOBJ[];
extern u16  Pal_EfxAureolaOBJ[];
extern i16 const FrameArray_EkrManaketefxNormalAttack[];
extern i16 const FrameArray_EkrManaketefxCriticalAttack[];
extern i16 const FrameArray_EkrFaefx[];
// extern ??? gUnk_081BC132
// extern ??? gUnk_081BC140
// extern ??? gUnk_081BC15E
// extern ??? gUnk_081BC17C
// extern ??? gUnk_081BC19A
extern u8 const Img_ManaketeBodyIntro2[];
extern u8 const Img_ManaketeBodyIntro1[];
extern u8 const Img_ManaketeBodyStd[];
extern u8 const Img_081BE490[];
extern const u16 Pal_EkrManaketefx[0xC0];
extern u8 const Tsa_ManaketeBodyIntro2[];
extern u8 const Tsa_ManaketeBodyIntro1[];
extern u8 const Tsa_ManaketeBodyStd[];
extern u8 const Tsa_081BFA34[];
extern u8 const Img_ManaketeObjfx1[];
extern u8 const Img_ManaketeObjfx2[];
extern u8 const Img_ManaketeObjfx3[];
extern u16 const Pal_ManaketeBodyStd[];
extern u8 const Img_EkrIdunn_081C1C94[];
extern u16 const Pal_081C4DE8[];
extern u8 const Tsa_EkrIdunn_081C4E28[];
extern u8 const Tsa_EkrIdunn_081C5264[];
extern u8 const Tsa_EkrIdunn_081C5688[];
extern u8 const Tsa_EkrIdunn_081C5AAC[];
extern u8 const Img_EkrFaefx[];
extern u16 const Pal_EkrFaefx[];
extern u16 const Tsa_EkrFaefx1[];
extern u16 const Tsa_EkrFaefx2[];
extern u16 const Tsa_EkrFaefx3[];
extern u16 const Tsa_EkrFaefx4[];
extern u16 const Tsa_EkrFaefx5[];
extern u16 const Tsa_EkrFaefx6[];
extern u16 const Tsa_EkrFaefx7[];
extern u16 const Tsa_EkrFaefx8[];
extern u16 const Tsa_EkrFaefx9[];
extern u16 const Tsa_EkrFaefx10[];
extern u16 const Tsa_EkrFaefx11[];
extern u16 const Tsa_EkrFaefx12[];
// extern ??? gUnk_081C9EF4
// extern ??? gUnk_081C9F14
// extern ??? gUnk_081C9F34
// extern ??? gUnk_081C9FA6
// extern ??? EkrLvupMsgsStr
// extern ??? EkrLvupMsgsMag
// extern ??? sEfxLvupPartsPos
extern const char gMsg_Lv[];
extern const i16 FrameArray_EkrTriPegagusBGLeft[];
extern const i16 FrameArray_EkrTriPegagusBGRight[];
extern const u16 Img_TriPegasusKnightBG[];
extern const u16 Img_TriFalconKnightLanceBG[];
extern const u16 Img_TriFalconKnightSwordBG[];
extern const u16 Img_TriPegasusKnightOBJ[];
extern const u16 Img_TriFalconKnightLanceOBJ[];
extern const u16 Img_TriFalconKnightSwordOBJ[];
extern const u16 Img_TriKnightOBJ[];
extern const u16 Img_TriGenerialLanceOBJ[];
extern const u16 Img_TriGenerialAxeOBJ[];
extern const u16 Img_TriGenerialHandAxeOBJ[];
extern const u16 Img_TriKnightAtkOBJ[];
extern const u16 Img_TriGenerialLanceAtkOBJ[];
extern const u16 Img_TriGenerialAxeAtkOBJ[];
extern const u16 Img_TriGenerialHandAxeAtkOBJ[];
extern u16 BanimBG_081D0B4C[];
extern u16 BanimBG_081D41C8[];
extern u16 BanimBG_081D8E04[];
extern u16 BanimBG_081DD1D4[];
extern u16 BanimBG_081DD2C0[];
extern u16 BanimBG_081DD3F4[];
extern u16 BanimBG_081DD4DC[];
extern u16 BanimBG_081DD5D4[];
extern u16 BanimBG_081DD6D4[];
extern u16 BanimBG_081DD7E4[];
extern u16 BanimBG_081DD890[];
extern u16 BanimBG_081DD950[];
extern u16 BanimBG_081DD9DC[];
extern u16 BanimBG_081DDA68[];
extern u16 BanimBG_081DDAD4[];
extern u16 BanimBG_081DDB8C[];
extern u16 BanimBG_081DDCBC[];
extern u16 BanimBG_081DDDAC[];
extern u16 BanimBG_081DDE3C[];
extern u16 BanimBG_081DDF24[];
extern u16 BanimBG_081DE008[];
extern u16 BanimBG_081DE120[];
extern u16 BanimBG_081DE1E8[];
extern u16 BanimBG_081DE2E4[];
extern u16 BanimBG_081DE3FC[];
extern u16 BanimBG_081DE4BC[];
extern u16 BanimBG_081DE528[];
extern u16 BanimBG_081DE680[];
extern u16 BanimBG_081DE740[];
extern u16 BanimBG_081DE830[];
extern u16 BanimBG_081DE8A0[];
extern u16 BanimBG_081DEA58[];
extern u16 BanimBG_081DED04[];
extern u16 BanimBG_081DEF48[];
extern u16 BanimBG_081DF110[];
extern u16 BanimBG_081DF3DC[];
extern u16 BanimBG_081DF650[];
extern u16 BanimBG_081DF7DC[];
extern u16 BanimBG_081DF9E0[];
extern u16 BanimBG_081DFBBC[];
extern u16 BanimBG_081DFE78[];
extern u16 BanimBG_081E0158[];
extern u16 BanimBG_081E048C[];
extern u16 BanimBG_081E0724[];
extern u16 BanimBG_081E09CC[];
extern u16 BanimBG_081E0BF4[];

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
extern u8 const Img_Credit_08344CD0[];
extern u16 const Tsa_Credit_0834523C[];
extern u16 const Pal_Credit_08345420[];
// extern const ??? gUnk_08345440
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
// extern const ??? gUnk_0837F478
// extern const ??? gUnk_08380ECC
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
extern const u8 gUnk_0832A29C[];
extern const u8 gUnk_0832B554[];
extern const u16 gUnk_0832BDE8[];
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
