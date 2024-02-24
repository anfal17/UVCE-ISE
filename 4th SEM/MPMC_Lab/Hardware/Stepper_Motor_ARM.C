#include<LPC214x.h>

unsigned int count = 0;
unsigned int j = 0;
unsigned int clock[4] = {0x00030000 , 0x00090000 , 0x000C0000 , 0x00060000};
unsigned int anti_clock[4] = {0x00060000 ,  , 0x000C0000 , 0x00030000 , 0x00090000};

void delay_1s(unsigned int n){
    unsigned int i , j;
    for(i  = 1 ;i <= n ; i++){
        for(j = 0 ; j <= 1000 ; j++);
    }
}

void clock_wise_direction(unsigned int STEP , unsigned int TIME){
    for(j = 0; j <= STEP ; j++){
        IO0PIN = clock[count];
        count++;
        delay_1s(TIME);
        if(count == 4)
            count = 0;
    }
}

void anti_clock_wise_direction(unsigned int STEP , unsigned int TIME){
    for(j = 0 ; j <= STEP ; j++){
        IO0PIN = anti_clock[count];
        count++;
        delay_1s(TIME);
        if(count == 4)
            count =0 ;
    }
}

int main(){
    IO0PIN = 0x000F0000;
    while(1){
        clock_wise_direction(10, 500);
        anti_clock_wise_direction(10, 500);
    }
    return 0;
}
