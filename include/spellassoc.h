#pragma once

#include "prelude.h"
#include "proc.h"

enum efxmagic_efx {
    EFXMAGIC_DUMMY,
    EFXMAGIC_TEONO,
    EFXMAGIC_ARROW,
    EFXMAGIC_JAVELIN,
    EFXMAGIC_JAVELIN_CAVALIER,
    EFXMAGIC_JAVELIN_SOILDER,
    EFXMAGIC_JAVELIN_PALADIN,
    EFXMAGIC_JAVELIN_PEGASUSKNIGHT,
    EFXMAGIC_JAVELIN_FALCON,
    EFXMAGIC_JAVELIN_WYVERNRIDER,
    EFXMAGIC_JAVELIN_WYVERNLORD,
    EFXMAGIC_JAVELIN_GENERAL,
    EFXMAGIC_0C,
    EFXMAGIC_0D,
    EFXMAGIC_SONG,
    EFXMAGIC_DANCE,
    EFXMAGIC_BALLISTA,
    EFXMAGIC_ECEACHS,
    EFXMAGIC_BINDINGBLADE,
    EFXMAGIC_FIREBREATH,
    EFXMAGIC_DARKBREATH,
    EFXMAGIC_FIRE,
    EFXMAGIC_ELFIRE,
    EFXMAGIC_FORBLAZE,
    EFXMAGIC_THUNDER,
    EFXMAGIC_BOLTING,
    EFXMAGIC_FIMBULVETR,
    EFXMAGIC_AIRECALIBUR,
    EFXMAGIC_FLUX,
    EFXMAGIC_NOSFERATU,
    EFXMAGIC_LIGHTING,
    EFXMAGIC_PURGE,
    EFXMAGIC_AUREOLA,
    EFXMAGIC_DIVINE,
    EFXMAGIC_APOCALYPSE,
    EFXMAGIC_ECLIPSE,
    EFXMAGIC_FENRIR,
    EFXMAGIC_HEAL,
    EFXMAGIC_MEND,
    EFXMAGIC_RECOVER,
    EFXMAGIC_PHYSIC,
    EFXMAGIC_FORTIFY,
    EFXMAGIC_LATONA,
    EFXMAGIC_RESTORE,
    EFXMAGIC_SILENCE,
    EFXMAGIC_SLEEP,
    EFXMAGIC_HAMMERNE,
    EFXMAGIC_BERSERK,
    EFXMAGIC_BARRIER,
};

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

const struct SpellAssoc * GetSpellAssocStructPtr(u16 item);
u8 GetSpellAssocCharCount(u16 item);
u16 GetSpellAssocEfxIndex(u16 item);
struct ProcScr const * GetSpellAssocManimSpecialScr(int item);
fu8 CheckSpellAssocCombat(u16 item);
fu8 GetSpellAssocFacing(u16 item);
fu8 GetSpellAssocFlashColor(u16 item);
