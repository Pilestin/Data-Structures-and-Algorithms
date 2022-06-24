#include<stdio.h>
#include<math.h>
float kokal();
int main(){
	int x;
	printf("Kokunu bulmak istediginiz sayiyi giriniz: ");
	scanf("%d",&x);
	printf("Girdiginiz sayinin koku = %f",kokal(x));
}
 float kokal(int x){
	float kok ;
	kok = sqrt(x);
	return kok ;
}
