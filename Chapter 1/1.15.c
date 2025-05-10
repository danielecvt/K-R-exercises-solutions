#include <stdio.h>

float farheneit(int celcius);

int main(){

    #define STOP 300
    #define STEP 20

    float farh;
    int celcius = 0;

    printf ("Celcius\tFarheneit\n");
    while (celcius <= STOP){
        printf("%3d\t%6.3f\n", celcius, farheneit(celcius));
        celcius += 20;
        }
}

float farheneit(int celcius){
    return (5.0/9.0) * (celcius - 32);
}