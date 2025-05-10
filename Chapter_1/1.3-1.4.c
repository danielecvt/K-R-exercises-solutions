#include <stdio.h>

int main(){

float start, stop, farh;
int step, celcius;

celcius = 0;
step = 20;
stop = 300;
farh = celcius;
printf ("Celcius\tFarheneit\n");
while (farh <= stop){
	farh = (5.0/9.0) * (celcius - 32);
	printf("%3d\t%6.3f\n", celcius, farh);
	celcius += 20;
	}

}
