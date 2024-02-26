;Develop an assembly language program to compute NCr using recursive procedure. Assume
;that ‘n’ and ‘r’ are non-negative integers.

--------code with comments---------
.MODEL SMALL
.DATA
N DW 6         ; Value of N
R DW 2         ; Value of R
NCR DW 0       ; Result variable

.CODE
MOV AX, @DATA  ; Load the address of the data segment to AX
MOV DS, AX     ; Set the data segment register to the address in AX

MOV AX, N      ; Load N to AX
MOV BX, R      ; Load R to BX
CALL NCR_PROC  ; Call the NCR_PROC procedure

MOV AH, 4CH    ; DOS function to exit the program
INT 21H        ; Call DOS interrupt

; Procedure to compute N choose R (NCr)
ncr_proc proc
    CMP AX, BX   ; Compare R and N
    JZ N1        ; If equal, add 1 to result
    CMP BX, 0    ; If not, check if R = 0
    JZ N1        ; If yes, add 1 to result
    CMP BX, 1    ; If not, check if R = 1
    JZ N2        ; If yes, add N to result

    MOV CX, AX   ; Copy N to CX
    DEC CX       ; Compute N-1
    CMP CX, BX   ; If not, check if R = N-1
    JZ N2        ; If yes, add N to result

    PUSH AX      ; Save N
    PUSH BX      ; Save R
    DEC AX       ; Compute N-1
    CALL ncr_proc ; Call ncr_proc recursively
    POP BX       ; Restore R
    POP AX       ; Restore N

    DEC AX       ; Compute N-1
    DEC BX       ; Compute R-1
    CALL ncr_proc ; Call ncr_proc recursively
    JMP LAST     ; Jump to LAST (return)

N1:
    ADD NCR, 1   ; Add 1 to the result
    RET

N2:
    ADD NCR, AX  ; Add N to the result

LAST:
    RET

ncr_proc ENDP
END

-----------------Plain Code----------
.MODEL SMALL
.DATA
N DW 6
R DW 2
NCR DW 0

.CODE
MOV AX, @DATA
MOV DS, AX
MOV AX, N
MOV BX, R
CALL NCR_PROC
MOV AH, 4CH
INT 21H

ncr_proc proc
    CMP AX, BX
    JZ N1
    CMP BX, 0
    JZ N1
    CMP BX, 1
    JZ N2
    MOV CX, AX
    DEC CX
    CMP CX, BX
    JZ N2
    PUSH AX
    PUSH BX
    DEC AX
    CALL ncr_proc
    POP BX
    POP AX
    DEC AX
    DEC BX
    CALL ncr_proc
    JMP LAST

N1:
    ADD NCR, 1
    RET

N2:
    ADD NCR, AX

LAST:
    RET
ncr_proc ENDP

END



----Execution Steps------
->masm file.asm;
->link file.obj;
->debug.exe file.exe
->g
->d

