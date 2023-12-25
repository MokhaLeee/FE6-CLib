#pragma once

#include "gba/gba.h"

// TODO: move elsewhere
#define CHR_SIZE 0x20
#define CHR_LINE 0x20

enum
{
    BGCHR_WINDOWFRAME = 0,

    BGCHR_MINIMAP = 0x01,

    BGCHR_TEXT_DEFAULT = 0x80,

    BGCHR_0_TEXT_POPUP = 0x100,
    BGCHR_DEBUGTEXT_DEFAULT = 0x2C0,

    BGCHR_LIMITVIEW = 0x280,

    BGCHR_ICON_BEGIN = 0x280,
    BGCHR_ICON_END   = 0x300,

    BGCHR_STATUSHEAL = 0x280,

    BGCHR_TILESET_A = 0x400,
    BGCHR_TILESET_B = 0x600,

    BGCHR_PHASE_CHANGE_SQUARES = 0x100,
    BGCHR_PHASE_CHANGE_NAME = 0x140,

    BGCHR_CHAPTERINTRO_80 = 0x80,
    BGCHR_CHAPTERINTRO_100 = 0x100,
    BGCHR_CHAPTERINTRO_MOTIF = 0x400,
    BGCHR_CHAPTERINTRO_FOG = 0x500,

    BGCHR_GAMEOVER_TEXT = 0x80,
    BGCHR_GAMEOVER_100 = 0x100,

    BGCHR_STEALSELECT_FACE = 0x200,

    BGCHR_BATTLEPREVIEW_FRAME = 0x200,

    BGCHR_MANIM_INFOFRAME = 1,
    BGCHR_MANIM_140 = 0x140,
    BGCHR_MANIM_200 = 0x200,

    BGCHR_STATSCREEN_EQUIPMENTLABEL = 0x270,

    BGCHR_STATSCREEN_EQUIPSTATFRAME = 0x60, // chr bank @ 8000
    BGCHR_STATSCREEN_FACE = 0xE0, // chr bank @ 8000
    BGCHR_STATSCREEN_BACKMURAL = 0x180, // chr bank @ 8000

    BGCHR_MAPUI_CHIBI = 0x0F0,
    BGCHR_MAPUI_100 = 0x100,
    BGCHR_MAPUI_128 = 0x128,
    BGCHR_MAPUI_140 = 0x140,

    BGCHR_STATUSSCREEN_280 = 0x280,
    BGCHR_B_STATUSSCREEN_280 = 0x280,
    BGCHR_B_STATUSSCREEN_380 = 0x380,
    BGCHR_B_STATUSSCREEN_3C0 = 0x3C0,
};

enum
{
    BGPAL_TEXT_DEFAULT    = 0,
    BGPAL_WINDOWFRAME     = 1,
    BGPAL_TALK            = 2,
    BGPAL_TALK_BUBBLE     = 3,
    BGPAL_ICONS           = 4, // .. 5
    BGPAL_TILESET         = 6, // .. 15

    BGPAL_DEBUGTEXT       = 0,

    BGPAL_EQUIP_INFO_ICON = 3,

    BGPAL_STATUSHEAL = 3,

    BGPAL_BATTLEPREVIEW_ICONALT = 3,

    BGPAL_LIMITVIEW = 4, // .. 5

    BGPAL_PHASE_CHANGE = 5,

    BGPAL_CHAPTERINTRO_0 = 0,
    BGPAL_CHAPTERINTRO_1 = 1,
    BGPAL_CHAPTERINTRO_FOG = 4,
    BGPAL_CHAPTERINTRO_MOTIF = 5,

    BGPAL_GAMEOVER_TEXT = 0,
    BGPAL_GAMEOVER_4 = 4,

    BGPAL_STEALSELECT_FACE = 5,

    BGPAL_BATTLEPREVIEW_FRAME = 1, // .. 2

    BGPAL_UI_STATBAR = 6,

    BGPAL_MANIM_INFOFRAME = 1, // .. 2
    BGPAL_MANIM_4 = 4,
    BGPAL_MANIM_INFO = 5,

    BGPAL_MURALBACKGROUND = 14, // .. 15

    BGPAL_STATSCREEN_6 = 6,
    BGPAL_STATSCREEN_EQUIPSTATFRAME = 7,
    BGPAL_STATSCREEN_FACE = 13,

    BGPAL_MAPUI_0 = BGPAL_TEXT_DEFAULT,
    BGPAL_MAPUI_2 = 2,
    BGPAL_MAPUI_3 = 3,
    BGPAL_MAPUI_CHIBI = 4,

    BGPAL_STATUSSCREEN_TALKTEXT = 1,
    BGPAL_STATUSSCREEN_2 = 2,
    BGPAL_STATUSSCREEN_4 = 4,
    BGPAL_STATUSSCREEN_5 = 5,

    BGPAL_MINIMAP_TERRAIN = 3,
    BGPAL_MINIMAP_OBJECTS = 4,
};

enum
{
    OBCHR_SYSTEM_OBJECTS = 0x000,

    OBCHR_CLOUDS = 0x012,
    OBCHR_SNOWSTORM_PARTICLE = 0x018,
    OBCHR_SANDSTORM_PARTICLE = 0x01C,

    OBCHR_MAPSPRITES = 0x80,

    OBCHR_DEBUGTEXT_DEFAULT = 0x180,

    OBCHR_MU_180 = 0x180,

    OBCHR_MANIM_180 = 0x180,
    OBCHR_MANIM_1C0 = 0x1C0,

    OBCHR_TRAPFX = 0x240,

    OBCHR_TRADEMENU_240 = 0x240,

    OBCHR_SUBTITLEHELP_TEXT = 0x240,

    OBCHR_BATTLEPREVIEW_MULTIPLIERS = 0x2E8,

    OBCHR_MOVEPATH = 0x2F0,

    OBCHR_FACE_DEFAULT2 = 0x1E0,
    OBCHR_FACE_DEFAULT1 = 0x268,
    OBCHR_FACE_DEFAULT0 = 0x2F0,
    OBCHR_FACE_DEFAULT3 = 0x378,

    OBCHR_MU_BASE = 0x380,

    OBCHR_STATSCREEN_240 = 0x240,

    OBCHR_HELPBOX_180 = 0x180,

    OBCHR_MAPUI_NUMBERS = 0x2E0,
};

enum
{
    OBPAL_SYSTEM_OBJECTS = 0,

    OBPAL_1 = 1,

    OBPAL_TRAPFX = 2,

    OBPAL_STATUSHEAL_UNITSPRITE = 2,

    OBPAL_BATTLEPREVIEW_MULTIPLIERS = 2,

    OBPAL_MOVEPATH = 3,

    OBPAL_SUBTITLEHELP_TEXT = 4,

    OBPAL_MU_FADE = 5,

    OBPAL_FACE_DEFAULT0 = 6,
    OBPAL_FACE_DEFAULT1 = 7,
    OBPAL_FACE_DEFAULT2 = 8,
    OBPAL_FACE_DEFAULT3 = 9,

    OBPAL_TRADEMENU_8 = 8,

    OBPAL_MANIM_3 = 3,
    OBPAL_MANIM_4 = 4,
    OBPAL_MANIM_SPECIALMU = 8, // .. 9

    OBPAL_7 = 7,
    OBPAL_10 = 10,

    OBPAL_UNITSPRITE_PURPLE = 11,

    OBPAL_MAPSPRITES = 12,
    OBPAL_UNITSPRITE_BLUE = OBPAL_MAPSPRITES + 0,
    OBPAL_UNITSPRITE_RED = OBPAL_MAPSPRITES + 1,
    OBPAL_UNITSPRITE_GREEN = OBPAL_MAPSPRITES + 2,
    OBPAL_UNITSPRITE_GRAY = OBPAL_MAPSPRITES + 3,

    OBPAL_STATSCREEN_WINDOWFRAME = 2,
    OBPAL_STATSCREEN_PAGENAME = 3,
    OBPAL_STATSCREEN_SPRITES = 4,

    OBPAL_HELPBOX_5 = 5,

    OBPAL_MAPUI_8 = 8,
};
