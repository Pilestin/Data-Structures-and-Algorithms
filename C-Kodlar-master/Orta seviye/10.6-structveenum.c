// Struct ve pointer struct 
#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int yas;
	char *isim;

}Insan;

int main(){
	
	Insan ali;
	
	Insan *yasin; // structlarda pointer kullanýlabilir. Ayný pointerda olduðu gibi malloc kullanýmý vardýr.
	yasin = (Insan *)malloc(sizeof(Insan) ) ; // Insan nesnesinden bir adet oluþturuldu ve yasin deðiþkenine atandý.void olarak gelecek degiskeni Insan * tipine çevirdik.
	
	ali.yas = 30;
	yasin -> yas = 20;   					 // pointer-struct da bu þekilde kullanýlýyor.
	
	printf("%d",ali.yas);
	printf("\n%d",yasin -> yas);			// pointer-struct da bu þekilde kullanýlýyor.
	
}
