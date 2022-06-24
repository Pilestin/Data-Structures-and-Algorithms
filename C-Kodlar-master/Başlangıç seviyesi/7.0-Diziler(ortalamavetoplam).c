#include<stdio.h>
int main(){
	float sayilar[5];
	float toplam = 0.0;
	int i = 0 ;
	while(i<5){
	
		printf("%d. sayiyi giriniz:",(i+1));
		scanf("%f",&sayilar[i]);
		toplam += sayilar[i];
		i++;
		0
	}
	printf("Girdiginiz sayilarin aritmatik ortalamasi %.2f'dir.",toplam/5);
	printf("Girdiðiniz sayilarin toplamý %f'dir.",toplam);
}




