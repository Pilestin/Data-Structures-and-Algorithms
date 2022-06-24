#include<stdio.h>
#include<conio.h>
int main(){
	int sayi;
	int sayac=0;
	int i=1;
	printf("Bir sayi giriniz:");
	scanf("%d",&sayi);
	while (i<=sayi){
		if(sayi%i == 0){
			sayac++;
		}
		i++;
	}
	if(sayac==2){
		printf("%d asaldir.",sayi);
	}
	else {
		printf("%d asal degildir.",sayi);
	}
	

	return 0 ;
}
