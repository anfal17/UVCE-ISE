;Develop an assembly program to reverse a given string and verify whether it is a
;palindrome or not. Display appropriate message

.MODEL SMALL       ; Set memory model to small

.DATA
STR DB "MODEL"     ; Define a string "MODEL"
LEN EQU $-1-STR     ; Calculate the length of the string

RSTR DB 10 DUP('$') ; Define a buffer for the reversed string
MSG DB "Reverse string is:$"
MSG1 DB "String is Palindrome$"
MSG2 DB "String is Not Palindrome$"

.CODE
MOV AX,@DATA       ; Load the address of the data segment to AX
MOV DS,AX          ; Set the data segment register to the address in AX
MOV ES,AX          ; Set the extra segment register to the address in AX

LEA SI,STR         ; SI points to STR
LEA DI,RSTR        ; DI points to RSTR
ADD DI,LEN-1       ; Move DI to the end of RSTR
MOV CX,LEN         ; Load the length of the string to CX

; Reverse the string using SI and DI
RPT:
    MOV AL,[SI]    ; Move the character pointed by SI to AL
    MOV [DI],AL    ; Move AL value to the location pointed by DI
    INC SI         ; Increment SI to point to the next character
    DEC DI         ; Decrement DI to move to the next position
    LOOP RPT       ; Loop back to RPT if CX is not zero

LEA DX, STR         ; Load the address of STR to DX
MOV AH, 09H        ; DOS function to print string
INT 21H            ; Call DOS interrupt to print the string

LEA DX, MSG         ; Load the address of MSG to DX
MOV AH, 09H        ; DOS function to print string
INT 21H            ; Call DOS interrupt to print the message

LEA DX, RSTR        ; Load the address of RSTR to DX
MOV AH, 09H        ; DOS function to print string
INT 21H            ; Call DOS interrupt to print the reversed string

LEA SI, STR         ; SI points to STR
LEA DI, RSTR        ; DI points to RSTR
MOV CX, LEN         ; Load the length of the string to CX

REPE CMPSB          ; Compare [SI] and [DI] and repeat if CX is not zero and ZF is 1
JNE NOTPAL          ; Jump to NOTPAL when an unequal condition occurs

LEA DX, MSG1        ; Load the address of MSG1 to DX
MOV AH, 09H        ; DOS function to print string
INT 21H            ; Call DOS interrupt to print the message

JMP EXIT            ; Jump to EXIT

NOTPAL:
LEA DX, MSG2        ; Load the address of MSG2 to DX
MOV AH, 09H        ; DOS function to print string
INT 21H            ; Call DOS interrupt to print the message

EXIT:MOV AH,4CH
INT 21H

-------------PLAIN CODE--------------

.MODEL SMALL
.DATA
STR DB "MODEL"
LEN EQU $-1-STR
RSTR DB 10 DUP('$')
MSG DB "Reverse string is:$"
MSG1 DB "String is Palindrome$"
MSG2 DB "String is Not Palindrome$"

.CODE
MOV AX,@DATA
MOV DS,AX
MOV ES,AX

LEA SI,STR
LEA DI,RSTR
ADD DI,LEN-1
MOV CX,LEN

RPT:
    MOV AL,[SI]
    MOV [DI],AL
    INC SI
    DEC DI
    LOOP RPT

LEA DX, STR
MOV AH, 09H
INT 21H

LEA DX, MSG
MOV AH, 09H
INT 21H

LEA DX, RSTR
MOV AH, 09H
INT 21H

LEA SI, STR
LEA DI, RSTR
MOV CX, LEN

REPE CMPSB
JNE NOTPAL

LEA DX, MSG1
MOV AH, 09H
INT 21H

JMP EXIT

NOTPAL:
LEA DX, MSG2
MOV AH, 09H
INT 21H

EXIT:
MOV AH,4CH
INT 21H

----Execution Steps------
->masm file.asm;
->link file.obj;
->file.exe
->g