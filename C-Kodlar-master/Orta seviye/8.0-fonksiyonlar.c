#include<stdio.h>
#include<math.h>
	int x = 16 ;			// Global variable.Yani t�m fonksiyonlarda kullan�labilir.
int kokal(int x){			// Fonksiyonumuzun d�nd�r�ce�i de�eri ve ard�ndan ismini veriyoruz. Fonksiyon oldu�u belli olmas� i�in parantez kullan�yoruz.parantez i�ine de�i�keni t�r� ile birlikte veriyoruz.
	int kok;				//kok isminde local variablemiz.Yani sadece bu fonksiyon i�inde tan�ml�.
	kok = sqrt(x);			//sqrt() math.h k�t�phanesindeki bir matematik fonksiyonu. Detay i�in bknz Deitel C How to Program 5.3 
	printf("%d",kok);		// K�ke e�itledi�imiz de�eri bast�r�yoruz.
	
}
int main(){
	
	kokal(x);				// fonksiyonumuzu main fonksiyonu alt�ndan �a��r�yoruz.
}
// Ayn� i�lemi main i�inde printf kullanarak da yapabiliriz.
//bkz. --> 8.01 


