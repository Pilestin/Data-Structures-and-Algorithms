#include<stdio.h>
#include<stdlib.h>

// Stack (y���n) kodlamas� , diziler ile yap�m.
// LIFO :(last in first out) Son giren ilk ��kar.

int *dizi;			// Normal dizilerle yap�lamayaca�� i�in pointer kullanmal�y�z
int boyut = 2 ; 	// Dizinin ba�lang�� boyutu.
int tepe = 0 ;		
int i;

int pop(){
	if(tepe < boyut/4){
		int *dizi2 = (int *)malloc(sizeof(int)*boyut/2 ); // Dizilerde de�i�ken kullanamay�z. Bu y�zden pointer kullan�caz.
		for(i = 0 ; i<boyut ; i++)
			dizi2[i] = dizi[i];
		free(dizi);		// Eski diziyi ramden temizledik.
		dizi = dizi2;
		boyut /= 2 ;
	}
	return dizi[--tepe];	// Dizideki en �st de�eri tutan tepe art�k bir azal�yor. B�ylece en �st noktada ki dizi eleman�m�z yerine bir alttaki eleman tepe taraf�ndan tutuluyor.
}							// E peki bast�r�rken sorun olmuyor mu  ; olmuyor ��nk� bast�r�rken tepeye kadar gitti�imiz i�in eski de�er puf oluyor.

void push(int a ){		// Diziye eleman ekler.
	if(tepe >= boyut){		
		int *dizi2 = (int *)malloc(sizeof(int)*boyut*2 ); // Dizilerde de�i�ken kullanamay�z. Bu y�zden pointer kullan�caz.
		for(i = 0 ; i<boyut ; i++)
			dizi2[i] = dizi[i];
		free(dizi);		// Eski diziyi ramden temizledik.
		dizi = dizi2;
		boyut *= 2 ;	
	}
	dizi[tepe++] = a;
}
void bastir(){						// Sadece dizideki elemanlar� bast�r�r.
	printf("(Boyut : %d) \n",boyut);
	for(i = 0 ; i<tepe ; i++){
		printf("%d\n",dizi[i] );
	}
}
int main(){
	dizi = (int*)malloc(sizeof(int)*2);	// 2 elemanl� bir dizi tan�mland�
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




