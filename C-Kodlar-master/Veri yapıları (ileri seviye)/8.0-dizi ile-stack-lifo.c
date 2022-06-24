#include<stdio.h>
#include<stdlib.h>

// Stack (yýðýn) kodlamasý , diziler ile yapým.
// LIFO :(last in first out) Son giren ilk çýkar.

int *dizi;			// Normal dizilerle yapýlamayacaðý için pointer kullanmalýyýz
int boyut = 2 ; 	// Dizinin baþlangýç boyutu.
int tepe = 0 ;		
int i;

int pop(){
	if(tepe < boyut/4){
		int *dizi2 = (int *)malloc(sizeof(int)*boyut/2 ); // Dizilerde deðiþken kullanamayýz. Bu yüzden pointer kullanýcaz.
		for(i = 0 ; i<boyut ; i++)
			dizi2[i] = dizi[i];
		free(dizi);		// Eski diziyi ramden temizledik.
		dizi = dizi2;
		boyut /= 2 ;
	}
	return dizi[--tepe];	// Dizideki en üst deðeri tutan tepe artýk bir azalýyor. Böylece en üst noktada ki dizi elemanýmýz yerine bir alttaki eleman tepe tarafýndan tutuluyor.
}							// E peki bastýrýrken sorun olmuyor mu  ; olmuyor çünkü bastýrýrken tepeye kadar gittiðimiz için eski deðer puf oluyor.

void push(int a ){		// Diziye eleman ekler.
	if(tepe >= boyut){		
		int *dizi2 = (int *)malloc(sizeof(int)*boyut*2 ); // Dizilerde deðiþken kullanamayýz. Bu yüzden pointer kullanýcaz.
		for(i = 0 ; i<boyut ; i++)
			dizi2[i] = dizi[i];
		free(dizi);		// Eski diziyi ramden temizledik.
		dizi = dizi2;
		boyut *= 2 ;	
	}
	dizi[tepe++] = a;
}
void bastir(){						// Sadece dizideki elemanlarý bastýrýr.
	printf("(Boyut : %d) \n",boyut);
	for(i = 0 ; i<tepe ; i++){
		printf("%d\n",dizi[i] );
	}
}
int main(){
	dizi = (int*)malloc(sizeof(int)*2);	// 2 elemanlý bir dizi tanýmlandý
	push(10);
	bastir();
	push(20);
	bastir();
	push(30);
	bastir();
	pop();
	bastir();
	push(40);
	bastir();
	push(50);
	bastir();
	pop();
	bastir();
	
}




