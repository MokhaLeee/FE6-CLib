#pragma once

#include "prelude.h"
#include "proc.h"

struct SpellAssoc {
    /* 00 */ u16 item;
    /* 02 */ u8 count;
    /* 04 */ i16 efx;
    /* 08 */ const struct ProcScr * scr;
    /* 0C */ u8 stat;
    /* 0D */ u8 facing;
    /* 0E */ u8 flash_color;
};

extern CONST_DATA struct SpellAssoc gSpellAssoc[];

struct SpellAssoc * GetSpellAssocStructPtr(u16 item);
u8 GetSpellAssocCharCount(u16 item);
u16 GetSpellAssocEfxIndex(u16 item);
struct ProcScr const * GetSpellAssocManimSpecialScr(int item);
fu8 CheckSpellAssocCombat(u16 item);
fu8 GetSpellAssocFacing(u16 item);
fu8 GetSpellAssocFlashColor(u16 item);
