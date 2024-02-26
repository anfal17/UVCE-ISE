; Design and develop an Assembly program to display messages “FIRE” & “HELP”
;alternately with flickering effects on a 7-segment display interface for a suitable period of
;time, ensure a flashing rate that makes it easy to read both the messages

--------Commented code-------
.MODEL SMALL

.DATA
PB EQU 0D801H   ; Port B address
PC EQU 0D802H   ; Port C address
CR EQU 0D803H   ; Control Register address
FIRE DB 86H, 88H, 0FEH, 8EH  ; Data for the FIRE pattern
HELP DB 8CH, 0C7H, 86H, 89H  ; Data for the HELP pattern

.CODE
MOV AX, @DATA
MOV DS, AX
MOV DX, CR      ; Load Control Register address to DX
MOV AL, 80H     ; Set the Control Register value to 80H
OUT DX, AL      ; Output AL to the Control Register

MOV CX, 10      ; Set loop count to 10
RPT:PUSH CX      ; Save CX on the stack
LEA SI, FIRE    ; Load address of FIRE pattern to SI
CALL DISPLAY   ; Call DISPLAY procedure to show FIRE pattern
CALL DELAY     ; Call DELAY procedure for a delay
LEA SI, HELP    ; Load address of HELP pattern to SI
CALL DISPLAY   ; Call DISPLAY procedure to show HELP pattern
CALL DELAY     ; Call DELAY procedure for a delay
POP CX          ; Restore CX from the stack
LOOP RPT        ; Loop until CX is zero

MOV AH, 4CH     ; DOS function to exit the program
INT 21H         ; Call DOS interrupt

DELAY PROC 
    PUSH CX      ; Save CX on the stack
    PUSH DX      ; Save DX on the stack
    MOV CX, 1000H ; Set the outer loop count for delay
OUTLOOP:MOV DX, 1000H ; Set the inner loop count for delay
INLOOP:DEC DX  ; Decrement DX
    JNZ INLOOP  ; Jump if DX is not zero
    LOOP OUTLOOP ; Loop until CX is zero
    POP DX       ; Restore DX from the stack
    POP CX       ; Restore CX from the stack
    RET
DELAY ENDP

DISPLAY PROC
    MOV BL, 4     ; Set the outer loop count for display
BACK2: MOV CL, 8  ; Set the inner loop count for display
    MOV AL, [SI]  ; Load data from the array pointed by SI to AL
BACK1:ROL AL, 1   ; Rotate AL left by 1 bit
    MOV DX, PB    ; Load Port B address to DX
    OUT DX, AL    ; Output AL to Port B
    PUSH AX       ; Save AX on the stack
    MOV AL, 1     ; Set AL to 1
    MOV DX, PC    ; Load Port C address to DX
    OUT DX, AL    ; Output 1 to Port C
    DEC AL        ; Decrement AL
    OUT DX, AL    ; Output AL to Port C
    POP AX        ; Restore AX from the stack
    DEC CL        ; Decrement CL
    JNZ BACK1     ; Jump if CL is not zero
    INC SI        ; Increment SI to point to the next data
    DEC BL        ; Decrement BL
    JNZ BACK2     ; Jump if BL is not zero
    RET
DISPLAY ENDP

END



---------Plain code----------------
.MODEL SMALL

.CODE
PB EQU 0D801H
PC EQU 0D802H
CR EQU 0D803H
FIRE DB 86H, 88H, 0FEH, 8EH 
HELP DB 8CH, 0C7H, 86H, 89H

.CODE
MOV AX, @DATA
MOV DS, AX
MOV DX, CR
MOV AL ,80H
OUT DX, AL

MOV CX, 10
RPT:PUSH CX
LEA SI ,FIRE
CALL DISPLAY
CALL DELAY
LEA SI , HELP
CALL DISPLAY
CALL DELAY
POP CX
LOOP RPT

MOV AH , 4CH
INT 21H

DELAY PROC 
PUSH CX
PUSH DX
MOV CX, 1000H
OUTLOOP:MOV DX , 1000H
INLOOP:DEC DX
JNZ INLOOP
LOOP OUTLOOP
POP DX
POP CX
RET
DISPLAY ENDP

DISPLAY PROC
MOV BL ,4
BACK2: MOV CL ,8
MOV AL ,[SI]
BACK1:ROL AL,1
MOV DX, PB
OUT DX, AL
PUSH AX
MOV AL ,1
MOV DX ,PC
OUT DX, AL
DEC AL
OUT DX, AL
POP AX
DEC CL
JNZ BACK1
INC SI
DEC BL
JNZ BACK2
RET
DISPLAY ENDP
END
