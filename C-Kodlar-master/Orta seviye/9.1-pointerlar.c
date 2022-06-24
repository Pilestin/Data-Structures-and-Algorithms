#include<stdio.h>
/*---------Pointerler �zet-------------
p bir pointer olsun ve a isminde bir diziyi tutsun.

alttakileri bast�r�rsak:
 p =>  a'n�n adres bilgisini verir.
 
*p =>  a'n�n de�er bilgisini verir.

&p =>  kendi adres bilgisini verir.


*/
int main(){
	int *p ;
	int i = 0;
	int dizi[10] = { 1,7,12,21,24,36,19,6};
	p = &dizi[0];							// Dizinin 0.eleman�n� tutar. �stersek farkl� bir yer de verebilirdik.
	
	
	printf("\n%d",*p);						// Dizinin 0. eleman�n�n DE�ER�N� verir. 
	printf("\n%d",p);  						// Dizinin 0. eleman�n�n ADRES�N� verir. (Yani dizinin haf�zadaki ilk yeri.)
//	printf("\n%d",&p);						// p pointer'�n�n KEND� ADRES�N� verir. Di�erlerinden farkl�d�r.�imdilik gerek yok.
	


	printf("\n%d",p+1);						// Bir sonraki eleman�n adresini verir. Haf�zada arka arkaya geldi�i g�r�lebilir.
	// Arada 4 say�l�k fark vard�r.
	// ��nk� 4 bitlik yer kapl�yor.
	printf("\n%d",p+2);						// �ki sonraki eleman�n adresini verir. Haf�zada arka arkaya geldi�i g�r�lebilir
												
	
	
	printf("\n%d",*(p + 1));				// Parantez i�ine bakarsak (p+1). eleman�n de�erini vericek.
	// p+1 adres verir ki bu da listenin 2.eleman�n�nd�r.
	// *(p+1) ise bu adresteki de�eri al�r. Yani direk listedeki 2.eleman�
	
	
	
	printf("\n%d",*p+1);					// Burada ise �stten farkl� olarak *p �nceliklidir.Yani dizinin ilk de�eri.
	// �nce dizinin ilk de�erini vericek , daha sonra bu de�ere 1 ekleyecek.
}
