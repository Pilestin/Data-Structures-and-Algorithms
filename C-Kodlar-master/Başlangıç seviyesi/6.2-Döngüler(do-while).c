#include<stdio.h>
int main(){
	int i = 1;
	
	do {
		
		printf("%d \n",i );
		i ++;
	}  while (i<=10 ) ;
	return 0 ;
}
//Normal while gibi çalýþýr fakat while'dan farký þudur:
//Eðer döngü koþulumuz (i<=10) saðlamasa bile ilk deðer bastýrýcaktýr.
//Çünkü do-While'da döngüye girmeden önce çýktý alýnabilir.  
