#include<stdio.h>
#include<stdlib.h>		// malloc kullan�rken bu k�t�phaneyi eklemek gerekebilir!!!
int main(){
	/*----------------malloc----------------
	A�a��daki gibi bir dizi tan�mlama C'de hata verir.
	��nk� de�i�ken , ad� �st�nde de�i�kendir. Daha sonradan de�eri de�i�tirilebilir.
	Bu da ramde dizi i�in belirlenen yerin de�i�tirilmesi demek olur.
	int a = 10;
	int d[a];
	
	Bunun yerine malloc kullanabiliriz.
	*/
	/*  �ki sat�rda veya tek sat�rda kullan�labilir.
		int p* ;
		p = (int *)malloc(sizeof(int) *10); */
	
	int *p = (int *)malloc(sizeof(int) *10);
	// malloc tip olarak void (yani tipsiz) d�nd�r�r. Bu y�zden int * 'a �evirdik. 
	// sizeof ise ne kadar yer ayr�laca��n� belirler."(int)*10" dedi�imiz i�in 10 integer'l�k yer ay�rd�.(�arp�)
	p[2] = 12;
	// p pointer�m�z art�k bir dizi gibi kullan�labilri.
	printf("%d",p[2]);
}
