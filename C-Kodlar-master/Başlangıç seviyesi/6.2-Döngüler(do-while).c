#include<stdio.h>
int main(){
	int i = 1;
	
	do {
		
		printf("%d \n",i );
		i ++;
	}  while (i<=10 ) ;
	return 0 ;
}
//Normal while gibi �al���r fakat while'dan fark� �udur:
//E�er d�ng� ko�ulumuz (i<=10) sa�lamasa bile ilk de�er bast�r�cakt�r.
//��nk� do-While'da d�ng�ye girmeden �nce ��kt� al�nabilir.  
