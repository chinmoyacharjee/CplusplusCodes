#include<stdio.h>
float convert(float dollar);
float a,pound,dollar;
int main (){
    
    scanf("%f",&dollar);
    
    pound=convert(dollar);

}float convert(float dollar){

    pound=dollar*2;
    printf("pound = %f ",pound);
    return (pound);

}
