#pragma once

// NOTE: this may end up getting merged with chapterevents

#include "prelude.h"

#include "proc.h"
#include "event.h"
#include "eventinfo.h"

struct TutorialEventProcA
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 unk_64;
    /* 66 */ i16 unk_66;
};

struct TutorialEventProcB
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 unk_64;
};

bool IsHard(void);
// GetHardModeBonusLevelsByPid
void ApplyAllHardModeBonusLevels(void);
bool func_fe6_0806BB34(struct EventInfo * info);
bool func_fe6_0806BB68(struct EventInfo * info);
bool func_fe6_0806BB9C(struct EventInfo * info);
bool func_fe6_0806BBD0(struct EventInfo * info);
// func_fe6_0806BBF8
bool func_fe6_0806BC20(struct EventInfo * info);
bool func_fe6_0806BC5C(struct EventInfo * info);
bool func_fe6_0806BCA4(struct EventInfo * info);
bool func_fe6_0806BCEC(struct EventInfo * info);
bool func_fe6_0806BD34(struct EventInfo * info);
bool func_fe6_0806BD7C(struct EventInfo * info);
bool func_fe6_0806BDC4(struct EventInfo * info);
bool Chapter10B_CheckTalkShannaThea(struct EventInfo * info);
bool Chapter10B_CheckTalkShannaTheaAfterKlein(struct EventInfo * info);
bool Chapter10B_CheckShannaRecruitsThea(struct EventInfo * info);
// func_fe6_0806BE90
// func_fe6_0806BEB8
bool func_fe6_0806BEEC(struct EventInfo * info);
bool func_fe6_0806BF14(struct EventInfo * info);
bool IsGuinivereAround(void);
// func_fe6_0806BF70
// func_fe6_0806BF7C
// func_fe6_0806BF98
// func_fe6_0806BFA4
void RemoveFog(void);
void AddFiveThousandGold(void);
// RemoveGold
// WeakenUnitStats
// WeakenUnitStatsByPid
// IsPidBlueDeployed
bool IsLilinaBlueDeployed(void);
bool IsMarcusBlueDeployed(void);
bool IsMerlinusBlueDeployed(void);
bool IsJunoBlueDeployed(void);
bool IsZelotBlueDeployed(void);
bool IsSinBlueDeployed(void);
bool IsDayanBlueDeployed(void);
bool IsSueBlueDeployed(void);
bool IsMeladyBlueDeployed(void);
bool IsZeissBlueDeployed(void);
bool IsPercivalBlueDeployed(void);
// IsPidBlue
bool IsBorsBlue(void);
bool IsLilinaBlue(void);
bool IsElenBlue(void);
// IsRaighBlue
bool IsSueBlue(void);
// IsCathBlue
bool IsMeladyBlue(void);
bool IsZeissBlue(void);
bool IsSophiaBlue(void);
bool IsJunoBlue(void);
bool IsZelotBlue(void);
bool IsElffinBlue(void);
// IsFaeBlue
bool IsSinBlue(void);
bool IsDayanBlue(void);
bool IsKleinBlue(void);
bool IsTheaBlue(void);
bool IsDouglasBlue(void);
// func_fe6_0806C2C4
bool func_fe6_0806C2F8(void);
bool IsPidNonBlue(fu8 pid);
// IsTheaNonBlue
bool func_fe6_0806C35C(void);
bool IsKleinNonBlue(void);
bool IsCathNonBlue(void);
bool IsHughNonBlue(void);
bool IsGalleNonBlue(void);
bool func_fe6_0806C3AC(void);
bool func_fe6_0806C3BC(void);
bool IsDouglasNonBlue(void);
bool IsPercevalNonBlue(void);
bool func_fe6_0806C3EC(void);
bool func_fe6_0806C3FC(void);
bool func_fe6_0806C40C(void);
// func_fe6_0806C41C
// func_fe6_0806C460
bool IsPastTurn20(void);
bool IsPastTurn25(void);
bool IsPastTurn30(void);
bool IsBluePhase(void);
bool IsRedPhase(void);
bool IsActiveUnitMale(void);
bool func_fe6_0806C524(void);
bool func_fe6_0806C540(void);
bool func_fe6_0806C55C(void);
bool func_fe6_0806C578(void);
bool func_fe6_0806C594(void);
bool AreWeGoingToSacae(void);
void func_fe6_0806C608(void);
bool func_fe6_0806C62C(void);
void func_fe6_0806C64C(void);
void func_fe6_0806C670(void);
bool func_fe6_0806C68C(void);
void func_fe6_0806C69C(void);
void func_fe6_0806C6B0(void);
void func_fe6_0806C718(void);
void func_fe6_0806C734(void);
void func_fe6_0806C750(void);
// func_fe6_0806C76C
void func_fe6_0806C7BC(struct TutorialEventProcA * proc);
void func_fe6_0806C7E0(struct TutorialEventProcA * proc);
void func_fe6_0806C948(struct TutorialEventProcB * proc);
void func_fe6_0806C950(struct TutorialEventProcB * proc);
// func_fe6_0806C998
bool func_fe6_0806C9F8(void);
void func_fe6_0806CA1C(void);
void func_fe6_0806CA30(void);
void func_fe6_0806CA44(void);
void func_fe6_0806CA58(void);
void func_fe6_0806CA6C(void);
void func_fe6_0806CA84(void);
void func_fe6_0806CA98(void);
void func_fe6_0806CAAC(void);
void func_fe6_0806CAC4(void);
void func_fe6_0806CAD8(void);
void func_fe6_0806CAEC(void);
void func_fe6_0806CB00(void);
void func_fe6_0806CB18(void);
// func_fe6_0806CB2C
void func_fe6_0806CB40(void);
void func_fe6_0806CB54(void);
void func_fe6_0806CB6C(void);
void func_fe6_0806CB80(void);
void func_fe6_0806CB94(void);
void func_fe6_0806CBA8(void);
void func_fe6_0806CBBC(void);
bool IsActiveUnitRoy(void);
bool IsActiveUnitWolt(void);
bool IsActiveUnitLilina(void);
// IsActiveUnitAlen
bool func_fe6_0806CC68(void);
bool IsCombatAction(void);
bool func_fe6_0806CC94(void);
// func_fe6_0806CCC0
void func_fe6_0806CCC4(void);
bool IsAnyTutorialUnitDamaged(void);
bool IsAnyTutorialUnitPastColumn16(void);
bool IsBossDefeated(void);
// IsPastTurn1
bool func_fe6_0806CDC0(void);
bool func_fe6_0806CE18(void);
bool func_fe6_0806CE34(void);
bool func_fe6_0806CE50(void);
bool func_fe6_0806CE80(void);
bool func_fe6_0806CEAC(void);
void RefreshClarine(void);
bool func_fe6_0806CEF0(void);
bool func_fe6_0806CF3C(void);
void Chapter8_WeakenNorthWestWall(void);
// func_fe6_0806CFA0
void func_fe6_0806CFB8(void);
void func_fe6_0806CFD0(void);
// func_fe6_0806CFE8
void func_fe6_0806D000(void);
void func_fe6_0806D01C(void);
bool func_fe6_0806D028(void);
void func_fe6_0806D064(void);
void func_fe6_0806D0E4(void);
// func_fe6_0806D0FC
bool func_fe6_0806D150(void);
void func_fe6_0806D17C(void);
void func_fe6_0806D194(void);
void func_fe6_0806D1AC(void);
void func_fe6_0806D1D4(void);
bool func_fe6_0806D1FC(struct EventProc * proc);
bool func_fe6_0806D35C(void);
bool func_fe6_0806D398(void);
bool func_fe6_0806D3B4(void);
void func_fe6_0806D3E0(void);
void AddChapter8xFireTraps(void);
void func_fe6_0806D55C(void);
void AddChapter12xGasTraps(void);
void AddChapter14xTimedMapChanges(void);
void AddChapter16xArrowTraps(void);
void func_fe6_0806D6B4(void);
void AddChapter21xStepTraps(void);
void func_fe6_0806D77C(void);

struct DemoMonologueMsg
{
    /* 00 */ u16 msg;
    /* 02 */ u8 y_offset;
};

extern struct DemoMonologueMsg CONST_DATA gDemoMonologueMsg[];

struct ProcDemoSceneIntro
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x4C);
    /* 4C */ i16 timer;
};

void DemoScene_StartMonologue(void);
void SetBanimConfigUniqueBG(void);
void SetBanimConfigON(void);
void CleanupDemoSceneIntro(void);
void EndDemoSceneIntro(void);
void DemoSceneIntro_Blocked(ProcPtr proc);
void DemoSceneIntro_Init(struct ProcDemoSceneIntro * proc);
void DemoSceneIntro_FadeOut(struct ProcDemoSceneIntro * proc);
void DemoSceneIntro_StartExt(void);
void PutDemoMonologueMsg(void);
void DemoScene_TmpCleanup(void);
void DemoScene_JumpToChapterDirectly(int chapter, int x, int y);
void DemoScene_JumpToCh4(void);
void DemoScene_JumpToCh1(void);
void DemoScene_JumpToCh10A(void);
void DemoScene_JumpToCh2(void);
void DemoScene_JumpToCh22(void);
void DemoScene_SetRoyHp_10(void);
EventScr const * GetDemoSceneEvent_Unused(int arg_0, int arg_1);
void StartDemoSceneEvent(int arg_0, ProcPtr proc);
void EndAllProcsMark1(void);
void TrueEnding_EarthQuake_Main(void);
void TrueEnding_EarthQuake(ProcPtr proc);
void TrueEnding_EarthQuakeEnd(void);

struct UnkProc_08676854
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 unk_64;
};

void func_fe6_0806DBA0(struct UnkProc_08676854 * proc);
void func_fe6_0806DBA8(struct UnkProc_08676854 * proc);
void func_fe6_0806DC24(ProcPtr parent);
void func_fe6_0806DC38(void);

struct ProcEpilogueCredit
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 unk_64;
};

void EpilogueCredit_Init(struct ProcEpilogueCredit * proc);
void EpilogueCredit_FadeBg(struct ProcEpilogueCredit * proc);
void Epilogue_StartCredit(ProcPtr parent);
void RemoveEndingMonologueBG(void);

void EndingTimeFlowMonologue_Init(void);
void DrawEndingTimeFlowMonologue(ProcPtr parent);
bool EndingTimeFlowMonologueExists(void);

void Epilogue_RemoveEventEngineBG(struct EventProc * proc);
void Epilogue_RemoveEventEngineNoMap(struct EventProc * proc);
void TrueEnding_SetNiceWeather(void);
void Epilogue_StartWind(void);
void func_fe6_0806DE00(void);
void TruEnding_PlaySe269(void);
void func_fe6_0806DE40(void);

struct UnkProc_086768C4
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ u16 unk_64;
};

void EndingBgmLooper_Init(struct UnkProc_086768C4 * proc);
void EndingBgmLooper_Ioop(struct UnkProc_086768C4 * proc);
void NewEndingBgmLooper(ProcPtr parent);
void EndEndingBgmLooper(void);

void RenderMapForDirectJump(void);

struct UnkProc_086768DC
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x4C);
    /* 4C */ ProcPtr unk_4C;
    /* 50 */ STRUCT_PAD(0x50, 0x64);
    /* 64 */ i16 unk_64;
};

void TrueEnding_SortAllies_Init(struct UnkProc_086768DC * proc);
void TrueEnding_SortAllies_Loop(struct UnkProc_086768DC * proc);
void TrueEnding_SortAllies(ProcPtr parent);
bool TrueEnding_SortAlliesExists(void);

struct ProcEpilogueBgmFade
{
    /* 00 */ PROC_HEADER;
    /* 29 */ STRUCT_PAD(0x29, 0x64);
    /* 64 */ i16 timer;
    /* 66 */ i16 timer2;
};


void Epilogue_BgmFadeIn_Init(struct ProcEpilogueBgmFade * proc);
void Epilogue_BgmFadeOut_Init(struct ProcEpilogueBgmFade * proc);
void Epilogue_BgmFadeIn_Loop(struct ProcEpilogueBgmFade * proc);
void Epilogue_BgmFadeOut_Loop(struct ProcEpilogueBgmFade * proc);
void EarthQuakeSoundFadeOutDefault(void);
void Epilogue_BgmFadeIn(ProcPtr parent);
void Epilogue_BgmFadeOut(ProcPtr parent);

void func_fe6_0806E074(void);

struct GameEndingPosition { u8 x, y; u16 more; };

extern struct GameEndingPosition CONST_DATA gGameEndingPosition1[];
extern struct GameEndingPosition CONST_DATA gGameEndingPosition2[];

void GameEnding_PutUnitsOnPosition1(void);
void GameEnding_PutUnitsOnPosition2(void);
void GameEnding_DeployRoy(void);
void SetFlagIfDefeatedByBindingBlade(void);

enum ending_id {
    TRUE_ENDING,
    NORMAL_ENDING,
    FALSE_ENDING,
};
extern u8 EWRAM_DATA gEndingId;

void UpdateEndingId(void);
fu8 GetEndingId(void);

extern EventScr CONST_DATA EventScr_TrueEnding_IndunnNotDie[];
extern EventScr CONST_DATA EventScr_TrueEnding_IndunnDie[];
extern EventScr const * CONST_DATA EventScrs_EndingScene[];
extern EventScr CONST_DATA EventScr_TrueEnding[];
extern EventScr CONST_DATA EventScr_FalseEnding[];
extern EventScr CONST_DATA EventScr_CharacterEnding[];

void StartGameEndingScene(ProcPtr parent);
void func_fe6_0806E32C(void);
