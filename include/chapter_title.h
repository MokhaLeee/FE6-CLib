#pragma once

#include "prelude.h"

struct ChapterTitleFxSt {
	u16 chr_bg;
	u16 chr_text;
};

extern struct ChapterTitleFxSt EWRAM_DATA gChapterTitleFxSt;

extern u16 const *CONST_DATA gChapterTitleData[];
