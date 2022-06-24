#include<stdio.h>
int main(){
// Girilen 5 sayýnýn ortalamasýný alan program
	int sayi1,sayi2,sayi3,sayi4,sayi5; 
	float ortalama;
	int toplam;
	printf("1.sayiyi giriniz:");
	scanf ("%d",&sayi1);
	toplam = sayi1;
		printf("\n2.sayiyi giriniz:");
		scanf ("%d",&sayi2);
		toplam = toplam + sayi2;
			printf("\n3.sayiyi giriniz:");
			scanf ("%d",&sayi3);
			toplam = toplam + sayi3;
				printf("\n4.sayiyi giriniz:");
				scanf ("%d",&sayi4);
				toplam = toplam + sayi4;
					printf("\n5.sayiyi giriniz:");
					scanf ("%d",&sayi5);
					toplam = toplam + sayi5;
	ortalama = toplam/5.0;
	
	printf("\nGirdiginiz sayilarin ortalamasi = %f",ortalama);
	
	
return 0 ;
}
