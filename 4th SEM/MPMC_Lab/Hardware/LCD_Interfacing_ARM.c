#include<stdio.h>
#include<LPC214x.h>

void delay(){
    unsigned int i, j;
    for(i = 0; i < 0xFF ; i++){
        for(j = 0; j < 0xFF ; j++);
    }
}

int main(){
    unsigned int number = 0x00;
    IO0DIR = 0X0000007C;
    IO0SET = 0X0000007C;

    while(1){
        IO0CLR = 0X0000003C;
        IO0SET = IO0SET | (number << 2);
        delay();
        delay();
        while(IO0PIN & 0X000080000);
        while(!(IO0PIN & 0X000080000));
        number++;
        if(number > 9)
            number = 0x00;
    }
    return 0;
}