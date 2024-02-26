#2. Design and develop an assembly program to sort a given set of ‘n’ 16-bit numbers in
#ascending order. Adopt Bubble sort algorithm to sort given elements.


.MODEL SMALL       ; Set memory model to small

.DATA
ARR DW 0005H,0004H,0003H,0002H,0001H   ; Define an array with 16-bit words
LEN DB ($-ARR)/2    ; Calculate the length of the array in bytes

.CODE
MOV AX,@DATA       ; Load the address of the data segment to AX
MOV DS,AX          ; Set the data segment register to the address in AX

MOV CL,LEN         ; Load the length of the array to register CL
DEC CL             ; Decrement CL to use it as a loop counter

; Outer loop (LOOP2) to iterate through the array elements
LOOP2:
    MOV SI, OFFSET ARR ; Load the offset of the array to source index SI
    MOV BL,CL          ; Copy the loop counter to BL

    ; Inner loop (LOOP1) to compare and swap adjacent elements
    LOOP1:
        MOV AX, [SI]    ; Load the current element
        ADD SI, 2       ; Move to the next element
        CMP AX, [SI]    ; Compare with the next element
        JB NEXT         ; Jump to NEXT if AX is less than [SI]

        ; Swap the elements if necessary
        MOV DX, [SI]    ; Load the next element to DX
        MOV [SI], AX    ; Store the current element in the next position
        MOV [SI-2], DX  ; Store the next element in the current position

    NEXT:
        DEC BL          ; Decrement the inner loop counter
        JNZ LOOP1       ; Jump back to LOOP1 if BL is not zero

    DEC CL              ; Decrement the outer loop counter
    JNZ LOOP2           ; Jump back to LOOP2 if CL is not zero

INT 3               ; Trigger a breakpoint interrupt for debugging purposes

END                ; End of the program


-----Plain code----------------
.MODEL SMALL
.DATA
ARR DW 0005H,0004H,0003H,0002H,0001H
LEN DB ($-ARR)/2

.CODE
MOV AX,@DATA
MOV DS,AX
MOV CL,LEN
DEC CL
LOOP2:MOV SI, OFFSET ARR
 MOV BL,CL
LOOP1:MOV AX,[SI] 
 ADD SI,2 
 CMP AX,[SI] 
 JB NEXT 
 MOV DX,[SI] 
 MOV [SI],AX 
 MOV [SI-2],DX 
NEXT: DEC BL 
 JNZ LOOP1
DEC CL 
JNZ LOOP2
INT 3
END

----Execution Steps------
->masm file.asm;
->link file.obj;
->debug.exe file.exe
->g
->d