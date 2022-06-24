#include<stdio.h>
#include<stdlib.h>		// malloc kullanýrken bu kütüphaneyi eklemek gerekebilir!!!
int main(){
	/*----------------malloc----------------
	Aþaðýdaki gibi bir dizi tanýmlama C'de hata verir.
	Çünkü deðiþken , adý üstünde deðiþkendir. Daha sonradan deðeri deðiþtirilebilir.
	Bu da ramde dizi için belirlenen yerin deðiþtirilmesi demek olur.
	int a = 10;
	int d[a];
	
	Bunun yerine malloc kullanabiliriz.
	*/
	/*  Ýki satýrda veya tek satýrda kullanýlabilir.
		int p* ;
		p = (int *)malloc(sizeof(int) *10); */
	
	int *p = (int *)malloc(sizeof(int) *10);
	// malloc tip olarak void (yani tipsiz) döndürür. Bu yüzden int * 'a çevirdik. 
	// sizeof ise ne kadar yer ayrýlacaðýný belirler."(int)*10" dediðimiz için 10 integer'lýk yer ayýrdý.(Çarpý)
	p[2] = 12;
	// p pointerýmýz artýk bir dizi gibi kullanýlabilri.
	printf("%d",p[2]);
}
