#Design and develop an assembly language program to search a key element “X” in a list of
#‘n’ 16-bit numbers. Adopt binary search algorithm in your program for searching


.MODEL SMALL      ; Set memory model to small
.STACK            ; Define a stack segment

.DATA
MSG1 DW "Key Found$"
MSG2 DW "Key Not Found$"
ARR DW 1,2,3,4,5,6,7,8   ; Define an array
LEN EQU ($-ARR)          ; Calculate the length of the array
KEY DW 8                 ; Define the key to search for

.CODE
MOV AX,@DATA       ; Load the address of the data segment to AX
MOV DS,AX          ; Set the data segment register to the address in AX

MOV SI,0           ; Initialize SI to point to the first element of the array
MOV DI,LEN         ; Initialize DI to point to the last element of the array
ADD DI,DI          ; Multiply DI by 2 to get the size of the array in bytes
SUB DI,2           ; Subtract 2 to point to the last element

; Loop for binary search
RPT:
    CMP SI, DI      ; Compare SI and DI
    JA KNF          ; Jump to KNF if SI > DI (key not found)
    MOV BX, SI      ; Copy the value of SI to BX
    ADD BX, DI      ; Add the value of DI to BX
    SHR BX, 1       ; Divide BX by 2 (calculate the middle index)

    CMP AX, ARR[BX] ; Compare the key with the middle element of the array
    JE KF           ; Jump to KF if key is found
    JB NEXT         ; Jump to NEXT if key is smaller than the middle element

    MOV SI, BX      ; Update SI to the middle index + 2
    ADD SI, 2
    JMP RPT         ; Jump back to RPT

NEXT:
    MOV DI, BX      ; Update DI to the middle index - 2
    SUB DI, 2
    JMP RPT         ; Jump back to RPT

KF:
    LEA DX, MSG1    ; Load the address of MSG1 to DX
    MOV AH, 09H     ; DOS function to print string
    INT 21H         ; Call DOS interrupt to print the message
    JMP EXIT        ; Jump to EXIT

KNF:
    LEA DX, MSG2    ; Load the address of MSG2 to DX
    MOV AH, 09H     ; DOS function to print string
    INT 21H         ; Call DOS interrupt to print the message

EXIT:
    MOV AH, 4CH     ; DOS function to exit the program
    INT 21H         ; Call DOS interrupt




--------------Plain Code--------------------------
.MODEL SMALL
.STACK

.DATA
MSG1 DW "Key Found$"
MSG2 DW "Key Not Found$"
ARR DW 1,2,3,4,5,6,7,8
LEN EQU ($-ARR) 
KEY DW 8

.CODE
MOV AX,@DATA
MOV DS,AX

MOV SI,0
MOV DI,LEN
ADD DI,DI
SUB DI,2

RPT:CMP SI,DI
JA KNF
MOV BX,SI
ADD BX,DI
SHR BX, 1

CMP AX, ARR[BX]
JE KF
JB NEXT
MOV SI,BX
ADD SI,2
JMP RPT

NEXT:MOV DI,BX
SUB DI,2
JMP RPT

KF:LEA DX,MSG1
MOV AH,09H
INT 21H
JMP EXIT

KNF:LEA DX,MSG2
MOV AH,09H
INT 21H

EXIT:MOV AH,4CH
INT 21H


----Execution Steps------
->masm file.asm;
->link file.obj;
->file.exe
->g
