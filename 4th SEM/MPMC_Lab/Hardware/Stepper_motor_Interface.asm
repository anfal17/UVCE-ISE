;Design and develop an assembly program to drive a stepper motor interface and rotate
;the motor in specified direction (Clock-wise or Counter – clock wise) by N steps. Introduce
;delay between successive steps

----------Commented Code---------
.MODEL SMALL

.DATA
PA EQU 0D800H   ; Port A address
CR EQU 0D803H   ; Control Register address

.CODE
MOV AX, @DATA   ; Load the address of the data segment to AX
MOV DS, AX      ; Set the data segment register to the address in AX

MOV AL, 80H     ; Set AL to 80H
MOV DX, CR      ; Load Control Register address to DX
OUT DX, AL      ; Output AL to the Control Register

MOV CX, 10      ; Set loop count to 10
MOV DX, PA      ; Load Port A address to DX
MOV AL, 11H     ; Set AL to 11H (initial value for output)

L1: 
OUT DX, AL      ; Output AL to Port A
CALL DELAY      ; Call DELAY procedure for a delay
ROR AL, 1       ; Rotate AL right by 1 bit
LOOP L1         ; Loop until CX is zero

MOV AH, 4CH     ; DOS function to exit the program
INT 21H         ; Call DOS interrupt

DELAY PROC
    PUSH CX      ; Save CX on the stack
    PUSH DX      ; Save DX on the stack
    MOV CX, 1000H ; Set the outer loop count for delay
OUTLOOP:
    MOV DX, 1000H ; Set the inner loop count for delay
INLOOP:
    DEC DX       ; Decrement DX
    JNZ INLOOP   ; Jump if DX is not zero
    LOOP OUTLOOP ; Loop until CX is zero
    POP DX       ; Restore DX from the stack
    POP CX       ; Restore CX from the stack
    RET
DELAY ENDP

END

-----------Plain Code------------
.MODEL SMALL
.DATA
PA EQU 0D800H
CR EQU 0D803H



.CODE
MOV AX , @DATA
MOV DS, AX
MOV AL , 80H
MOV DX , CR
OUT DX , AL

MOV CX, 10
MOV DX , PA
MOV AL ,11H

L1: OUT DX , AL
CALL DELAY
ROR AL ,1
LOOP L1

MOV AH, 4CH
INT 21H

DELAY PROC
PUSH CX
PUSH DX
MOV CX, 1000H
OUTLOOP:MOV DX, 1000H
INLOOP:DEC DX
JNZ INLOOP
LOOP OUTLOOP
POP DX
POP CX
RET
DELAY ENDP
END

