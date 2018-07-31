#include<stdio.h>
void func1();
void func2();

void main(){

    func1();

    printf("3");


}void func1(){

    printf("1 ");
    func2();

}void func2(){
    
    printf("2 ");

    return;

}
