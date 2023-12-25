GAME?=fe6
ELF := $(GAME).elf
REF := $(GAME).ref.s
SYM := $(GAME).sym

BASE_REF = base_ref.s

all: $(REF) $(SYM)

$(REF): $(ELF) $(BASE_REF)
	python3 elf2ref.py $< > $@
	cat $(BASE_REF) >> $@

$(SYM): $(ELF)
	python3 elf2sym.py $< > $@
