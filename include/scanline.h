#pragma once

#include "prelude.h"
#include "hardware.h"

extern u16 EWRAM_DATA gManimScanlineBufA[DISPLAY_HEIGHT * 2];
extern u16 EWRAM_DATA gManimScanlineBufB[DISPLAY_HEIGHT * 2];
extern u16 *EWRAM_DATA gManimScanlineBufs[2];
extern u16 *EWRAM_DATA gManimActiveScanlineBuf;

void InitScanlineEffect(void);
void func_fe6_08069C74(void);
void func_fe6_08069DA4(int x, int y, int arg_08);
void func_fe6_08069DD8(void);
void OnHBlank_WinHScanlines(void);
void OnHBlank_08069E50(void);
void OnHBlank_ManimFrameGradient(void);
void OnHBlank_08069F58(void);
void OnHBlank_08069FD8(void);
void OnHBlank_0806A040(void);
void StartManimFrameGradientScanlineEffect(u16 arg_0, u16 arg_1, u16 color_2, u16 color_3);
void func_fe6_0806A218(u16 yStart, u16 yEnd, u16 arg_2, u16 arg_3);
void func_fe6_0806A270(int x, int y, int a, int b, u8 const *unk);
// PrepareSineWaveScanlineBuf
// PrepareSineWaveScanlineBufExt
void SwapScanlineBufs(void);
void InitScanlineBuf(u16 *buf);
void SetScanlineBufWinL(u16 *buf, int x, int y);
void SetScanlineBufWinR(u16 *buf, int x, int y);
void func_fe6_0806A51C(u16 *buf, int x, int y, int arg_0C);
void PrepareGradientScanlineBuf(u16 *buf, u16 arg_02, u16 arg_04, u16 arg_06, u16 arg_30);

struct ManimShiftingSineWaveScanlineBufProc {
	/* 00 */ PROC_HEADER;
	/* 29 */ STRUCT_PAD(0x29, 0x64);
	/* 64 */ i16 phase;
};

void ManimShiftingSineWaveScanlineBuf_Init(struct ManimShiftingSineWaveScanlineBufProc *proc);
void ManimShiftingSineWaveScanlineBuf_Loop(struct ManimShiftingSineWaveScanlineBufProc *proc);
void Scanline_SetupMonologue(void);
u16 *func_fe6_0806A87C(int buf_id, int scanline);
