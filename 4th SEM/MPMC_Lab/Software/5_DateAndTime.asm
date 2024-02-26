;Design and develop an assembly program to read the current time and date from the system
;and display it in the standard format on screen

----------Code with Comments----------
.MODEL SMALL
.DATA
MSG1 DB "TIME IS$"
MSG2 DB 10,13,"DATE IS$"

.CODE
MOV AX, @DATA     ; Load the address of the data segment to AX
MOV DS, AX        ; Set the data segment register to the address in AX

LEA DX, MSG1      ; Load the address of MSG1 to DX
MOV AH, 09H       ; DOS function to print string
INT 21H           ; Call DOS interrupt to print "TIME IS$"

MOV AH, 2CH       ; DOS function to read system time
INT 21H           ; Call DOS interrupt

MOV AL, CH        ; Move hours to AL
CALL DISPLAY      ; Call DISPLAY procedure
MOV AL, CL        ; Move minutes to AL
CALL DISPLAY      ; Call DISPLAY procedure
MOV AL, DH        ; Move seconds to AL
CALL DISPLAY      ; Call DISPLAY procedure

LEA DX, MSG2      ; Load the address of MSG2 to DX
MOV AH, 09H       ; DOS function to print string
INT 21H           ; Call DOS interrupt to print "DATE IS$"

MOV AH, 2AH       ; DOS function to read system date
INT 21H           ; Call DOS interrupt

MOV BX, DX        ; Save month and day in BX, BH = month, BL = day
CALL DISPLAY      ; Call DISPLAY procedure for month
MOV AL, BL        ; Move day from BL to AL
CALL DISPLAY      ; Call DISPLAY procedure for day
MOV AL, BH        ; Move month from BH to AL
CALL DISPLAY      ; Call DISPLAY procedure for year

MOV DL, ':'       ; Display character ':'
MOV AH, 02H       ; DOS function to display character
INT 21H           ; Call DOS interrupt

MOV AX, CX        ; Move year to AX (e.g., 2017)
MOV DX, 0         ; DX = 0
MOV BX, 10        ; BX = 10
DIV BX            ; DX:AX / BX -> 2017 / 10, AX = 201, DX = 07
MOV CL, DL        ; Move the tens place (07) to CL
MOV DX, 0         ; DX = 0
DIV BX            ; DX:AX / BX -> 201 / 10, AX = 20, DL = 01
ADD DL, 30H       ; Convert to ASCII, DL + 30H = 01 + 30H = 31H (ASCII '1')
MOV AH, 02H       ; DOS function to display character
INT 21H           ; Call DOS interrupt to display the tens place
MOV DL, CL        ; Move the ones place (07) to DL
ADD DL, 30H       ; Convert to ASCII, DL + 30H = 07 + 30H = 37H (ASCII '7')
MOV AH, 02H       ; DOS function to display character
INT 21H           ; Call DOS interrupt to display the ones place

MOV AH, 4CH       ; DOS function to exit the program
INT 21H           ; Call DOS interrupt

DISPLAY PROC
    PUSH AX        ; Save AX on the stack
    MOV DL, ':'    ; Display symbol ':'
    MOV AH, 02H    ; DOS function to display character
    INT 21H        ; Call DOS interrupt
    POP AX         ; Pop AX from the stack
    AAM            ; Convert packed BCD in AL to unpacked (e.g., 12 -> 01 02)
    MOV DX, AX     ; DX = 01 02
    ADD DX, 3030H  ; DX + 3030H = 01 02 + 30 30H = 31 32H (ASCII code of '1' and '2')
    XCHG DH, DL    ; Display character in DH
    MOV AH, 02H    ; DOS function to display character
    INT 21H        ; Call DOS interrupt
    MOV DL, DH     ; Display character in DL
    MOV AH, 02H    ; DOS function to display character
    INT 21H        ; Call DOS interrupt
    RET            ; Return from procedure
DISPLAY ENDP

END


----------Plain code-----------------------
.MODEL SMALL
.DATA
MSG1 DB "TIME IS$"
MSG2 DB 10,13,"DATE IS$"

.CODE
MOV AX, @DATA
MOV DS, AX

LEA DX, MSG1
MOV AH, 09H
INT 21H

MOV AH, 2CH
INT 21H

MOV AL, CH
CALL DISPLAY
MOV AL, CL
CALL DISPLAY
MOV AL, DH
CALL DISPLAY

LEA DX, MSG2
MOV AH, 09H
INT 21H

MOV AH, 2AH
INT 21H

MOV BX, DX
CALL DISPLAY
MOV AL, BL
CALL DISPLAY
MOV AL, BH
CALL DISPLAY

MOV DL, ':'
MOV AH, 02H
INT 21H

MOV AX, CX
MOV DX, 0
MOV BX, 10
DIV BX
MOV CL, DL
MOV DX, 0
DIV BX
ADD DL, 30H
MOV AH, 02H
INT 21H
MOV DL, CL
ADD DL, 30H
MOV AH, 02H
INT 21H

MOV AH, 4CH
INT 21H

DISPLAY PROC
    PUSH AX
    MOV DL, ':'
    MOV AH, 02H
    INT 21H
    POP AX
    AAM
    MOV DX, AX
    ADD DX, 3030H
    XCHG DH, DL
    MOV AH, 02H
    INT 21H
    MOV DL, DH
    MOV AH, 02H
    INT 21H
    RET
DISPLAY ENDP

END

----Execution Steps------
->masm file.asm;
->link file.obj;
->file.exe