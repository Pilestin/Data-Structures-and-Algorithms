#include<stdio.h>

int fibonacci(int);
int cagrilma(int);
int x;
int main(){
	int sonuc , sonuccagrilma;
	
	printf ("Fibonacci serisinin kacinci elemaninin hesaplanacagini giriniz:");
	scanf("%d",&x);

		sonuc = fibonacci(x);
		printf ("\n%d. elemanin degeri : %d", x , sonuc);
		
		sonuccagrilma = 2*cagrilma(x) - 2;
		printf("\nSerinin %d. elemanini hesaplamak icin fonksiyon cagrilma sayisi : %d ",x , sonuccagrilma);
						
}
int fibonacci(int x ){

	int a , b;
			
		if (x<=1)
			return x;
			
		else{
			a = fibonacci( (x-1) ) ;
			b = fibonacci( (x-2) ) ;
		}
	return ( a + b);
}
int cagrilma(x){
	int k , l , g;
	
	if(x<=1)
		return 1 ;
	else{
		k = cagrilma( (x-1) );
		l = cagrilma( (x-2) );
	}
		
	return (k + l );

}


