#include<stdio.h>
int main(){

/// Here is the basic of 'const' keyword in c. First of all const represents constant that actually means unchangeable or immutable.
/// it is like 'final'
/// If use const char while declaration then I must need to initialize it and i cannot change it later, where i can it do without using const keyword.
    const char*  a = "abc"; /// I can change the value of a, but i cannot change the position of a as it is pointed by using const.
    const char*  b = "def"; /// I cannot change the value of b but I can change the position or location of b(&b)
    a = "abcd";
    printf("%s\n",a);
    printf("%d\n",&a);
    printf("%d\n",&b);


    return 0;
}
