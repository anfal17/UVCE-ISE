#include<lpc214x.h>
#include<stdio.h>
#include<startup.s>

int main(){
    int a, b, c, d, e, f;
    a = 5;
    b = 3;

    c = a+b; 
    d = a-b; 
    e = a*b; 
    f = a/b;

    return 0; 
}


/*-----Execution metod------------
1. Open Keil µVision.
2. Project -> New µVision Project -> Save.
3. NXP -> LPC2148 -> OK -> Yes.
4. Right-click on "Source Group 1" -> Add New Item -> C Source File.
5. Write C code in the new file.
6. Project -> Build Target (or press F7).
7. Debug (F5) to start debugging.
8. Inspect variables in the "Watch" window.
9. Run/Stop debugging using toolbar buttons.
10. Close Keil when finished.
*/
