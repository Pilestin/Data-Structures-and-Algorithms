#include<stdio.h>
int f(int x , int y);
int x , y , sonuc ;
int main(){
	printf("X degerini giriniz:");
	scanf("%d",&x);

	printf("\nY degerini giriniz:");
	scanf("%d",&y);

	printf("%d^%d isleminin sonucu = %d ",x , y , f( x,  y) );	
}
int f(x , y ){
	int c = 1 ;
	while(y>=1){
		
		c=x*c;
		y=y-1;
}
return c ;

}
	

