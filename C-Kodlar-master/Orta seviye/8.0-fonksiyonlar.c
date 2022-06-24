#include<stdio.h>
#include<math.h>
	int x = 16 ;			// Global variable.Yani tüm fonksiyonlarda kullanýlabilir.
int kokal(int x){			// Fonksiyonumuzun döndürüceði deðeri ve ardýndan ismini veriyoruz. Fonksiyon olduðu belli olmasý için parantez kullanýyoruz.parantez içine deðiþkeni türü ile birlikte veriyoruz.
	int kok;				//kok isminde local variablemiz.Yani sadece bu fonksiyon içinde tanýmlý.
	kok = sqrt(x);			//sqrt() math.h kütüphanesindeki bir matematik fonksiyonu. Detay için bknz Deitel C How to Program 5.3 
	printf("%d",kok);		// Köke eþitlediðimiz deðeri bastýrýyoruz.
	
}
int main(){
	
	kokal(x);				// fonksiyonumuzu main fonksiyonu altýndan çaðýrýyoruz.
}
// Ayný iþlemi main içinde printf kullanarak da yapabiliriz.
//bkz. --> 8.01 


