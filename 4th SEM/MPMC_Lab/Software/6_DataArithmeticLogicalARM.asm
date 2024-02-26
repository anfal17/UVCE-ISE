AREA PRG6,CODE,READONLY
ENTRY
LDR R0,= 5
LDR R1,= 3

ADD R2, R0 ,R1
SUB R3, R0 ,R1
MUL R4, R0 ,R1

AND R5, R0, R1
ORR R6, R0, R1
EOR R7, R0, R1

END


-----Execution-------
1. Open Keil µVision.
2. Project -> Close Project (if any).
3. Project -> New µVision Project -> Save.
4. NXP -> LPC2148 -> OK -> Yes.
5. File -> New -> Edit Program -> Save as .S.
6. Target 1 -> Source Group 1 -> Add Files (select .S file).
7. Project -> Build Target (check for 0 errors).
8. Debug (F5) to start debugging.
9. Inspect registers, memory, and debug output.
