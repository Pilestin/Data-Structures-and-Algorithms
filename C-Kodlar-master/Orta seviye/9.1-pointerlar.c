#include<stdio.h>
/*---------Pointerler Özet-------------
p bir pointer olsun ve a isminde bir diziyi tutsun.

alttakileri bastýrýrsak:
 p =>  a'nýn adres bilgisini verir.
 
*p =>  a'nýn deðer bilgisini verir.

&p =>  kendi adres bilgisini verir.


*/
int main(){
	int *p ;
	int i = 0;
	int dizi[10] = { 1,7,12,21,24,36,19,6};
	p = &dizi[0];							// Dizinin 0.elemanýný tutar. Ýstersek farklý bir yer de verebilirdik.
	
	
	printf("\n%d",*p);						// Dizinin 0. elemanýnýn DEÐERÝNÝ verir. 
	printf("\n%d",p);  						// Dizinin 0. elemanýnýn ADRESÝNÝ verir. (Yani dizinin hafýzadaki ilk yeri.)
//	printf("\n%d",&p);						// p pointer'ýnýn KENDÝ ADRESÝNÝ verir. Diðerlerinden farklýdýr.Þimdilik gerek yok.
	


	printf("\n%d",p+1);						// Bir sonraki elemanýn adresini verir. Hafýzada arka arkaya geldiði görülebilir.
	// Arada 4 sayýlýk fark vardýr.
	// Çünkü 4 bitlik yer kaplýyor.
	printf("\n%d",p+2);						// Ýki sonraki elemanýn adresini verir. Hafýzada arka arkaya geldiði görülebilir
												
	
	
	printf("\n%d",*(p + 1));				// Parantez içine bakarsak (p+1). elemanýn deðerini vericek.
	// p+1 adres verir ki bu da listenin 2.elemanýnýndýr.
	// *(p+1) ise bu adresteki deðeri alýr. Yani direk listedeki 2.elemaný
	
	
	
	printf("\n%d",*p+1);					// Burada ise üstten farklý olarak *p önceliklidir.Yani dizinin ilk deðeri.
	// Önce dizinin ilk deðerini vericek , daha sonra bu deðere 1 ekleyecek.
}
