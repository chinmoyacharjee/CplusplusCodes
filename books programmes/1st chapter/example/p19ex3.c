#include<stdio.h>
int keyboard();
int area(int x, int y);
void monitor(int x);
int main(){
    int length,width,area;
    length=keyboard();
    width=keyboard();
       
    area=area_1(length,width);
    
    monitor (area);
   
}
int keyboard(){

    int x;
    scanf("%d",&x);
    return x;




}
int area_1(int a, int b){

    int area;
    area= a*b;
    return area;


}
void monitor (int x){

    printf("%d",x);

}
