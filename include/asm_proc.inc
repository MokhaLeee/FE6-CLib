.equiv PROC_CMD_END, 0
.equiv PROC_CMD_NAME, 1
.equiv PROC_CMD_CALL, 2
.equiv PROC_CMD_REPEAT, 3
.equiv PROC_CMD_ONEND, 4
.equiv PROC_CMD_START_CHILD, 5
.equiv PROC_CMD_START_CHILD_BLOCKING, 6
.equiv PROC_CMD_START_BUGGED, 7
.equiv PROC_CMD_WHILE_EXISTS, 8
.equiv PROC_CMD_END_EACH, 9
.equiv PROC_CMD_BREAK_EACH, 10
.equiv PROC_CMD_LABEL, 11
.equiv PROC_CMD_GOTO, 12
.equiv PROC_CMD_GOTO_SCR, 13
.equiv PROC_CMD_SLEEP, 14
.equiv PROC_CMD_MARK, 15
.equiv PROC_CMD_BLOCK, 16
.equiv PROC_CMD_END_IF_DUP, 17
.equiv PROC_CMD_SET_FLAG2, 18
.equiv PROC_CMD_13, 19
.equiv PROC_CMD_WHILE, 20
.equiv PROC_CMD_15, 21
.equiv PROC_CMD_CALL_2, 22
.equiv PROC_CMD_END_DUPS, 23
.equiv PROC_CMD_CALL_ARG, 24
.equiv PROC_CMD_19, 25

.macro PROC_END
	.short PROC_CMD_END
	.short 0
	.4byte 0
.endm

.macro PROC_CMD_NAME name
	.short PROC_CMD_NAME
	.short 0
	.4byte \name
.endm

.macro PROC_CALL func
	.short PROC_CMD_CALL
	.short 0
	.4byte \func
.endm

.macro PROC_REPEAT func
	.short PROC_CMD_REPEAT
	.short 0
	.4byte \func
.endm

.macro PROC_ONEND func
	.short PROC_CMD_ONEND
	.short 0
	.4byte \func
.endm

.macro PROC_START_CHILD scr
	.short PROC_CMD_START_CHILD
	.short 0
	.4byte \scr
.endm

.macro PROC_START_CHILD_LOCKING scr
	.short PROC_CMD_START_CHILD_BLOCKING
	.short 0
	.4byte \scr
.endm

.macro PROC_START_BUGGED scr
	.short PROC_CMD_START_BUGGED
	.short 0
	.4byte \scr
.endm

.macro PROC_WHILE_EXISTS scr
	.short PROC_CMD_WHILE_EXISTS
	.short 0
	.4byte \scr
.endm

.macro PROC_END_EACH scr
	.short PROC_CMD_END_EACH
	.short 0
	.4byte \scr
.endm

.macro PROC_BREAK_EACH scr
	.short PROC_CMD_BREAK_EACH
	.short 0
	.4byte \scr
.endm

.macro PROC_LABEL label
	.short PROC_CMD_LABEL
	.short \label
	.4byte 0
.endm

.macro PROC_GOTO label
	.short PROC_CMD_GOTO
	.short \label
	.4byte 0
.endm

.macro PROC_GOTO_SCR scr
	.short PROC_CMD_GOTO_SCR
	.short 0
	.4byte \scr
.endm

.macro PROC_SLEEP duration
	.short PROC_CMD_SLEEP
	.short \duration
	.4byte 0
.endm

.macro PROC_MARK mark
	.short PROC_CMD_MARK
	.short \mark
	.4byte 0
.endm

.macro PROC_BLOCK
	.short PROC_CMD_BLOCK
	.short 0
	.4byte 0
.endm

.macro PROC_END_IF_DUP
	.short PROC_CMD_END_IF_DUP
	.short 0
	.4byte 0
.endm

.macro PROC_SET_FLAG2
	.short PROC_CMD_SET_FLAG2
	.short 0
	.4byte 0
.endm

.macro PROC_13
	.short PROC_CMD_13
	.short 0
	.4byte 0
.endm

.macro PROC_WHILE func
	.short PROC_CMD_WHILE
	.short 0
	.4byte \func
.endm

.macro PROC_15
	.short PROC_CMD_15
	.short 0
	.4byte 0
.endm

.macro PROC_CALL_2 func
	.short PROC_CMD_CALL_2
	.short 0
	.4byte \func
.endm

.macro PROC_END_DUPS
	.short PROC_CMD_END_DUPS
	.short 0
	.4byte 0
.endm

.macro PROC_CALL_ARG func, arg
	.short PROC_CMD_CALL_ARG
	.short \arg
	.4byte \func
.endm

.macro PROC_19
	.short PROC_CMD_19
	.short 0
	.4byte 0
.endm

.macro PROC_YIELD
	PROC_SLEEP 0
.endm

.macro PROC_NAME_DEBUG name
	PROC_19
.endm
