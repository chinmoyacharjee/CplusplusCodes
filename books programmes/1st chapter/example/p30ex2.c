#include<stdio.h>

void func_1(void);

int main(void){

    func_1();
}void func_1(void){

    printf("this is printed");
    return;
    printf("this is never printed ");

    
}

