#include <stdio.h>
#include<conio.h>
#include<string.h>
char charArray [] = {"A computer is a machine that can be instructed to carry out sequences of arithmetic or logical operations automatically via computer programming. Modern computers have the ability to follow generalized sets of operations, called programs. These programs enable computers to perform an extremely wide range of tasks. A complete computer including the hardware, the operating system (main software), and peripheral equipment required and used for full operation can be referred to as a computer system. This term may as well be used for a group of computers that are connected and work together, in particular a computer network or computer cluster. Computers are used as control systems for a wide variety of industrial and consumer devices. This includes simple special purpose devices like microwave ovens and remote controls, factory devices such as industrial robots and computer-aided design, and also general purpose devices like personal computers and mobile devices such as smartphones. The Internet is run on computers and it connects hundreds of millions of other computers and their users. Early computers were only conceived as calculating devices. Since ancient times, simple manual devices like the abacus aided people in doing calculations. Early in the Industrial Revolution, some mechanical devices were built to automate long tedious tasks, such as guiding patterns for looms. More sophisticated electrical machines did specialized analog calculations in the early 20th century."};	
char sesli[10] = {'A','E','I','U','O','a','e','i','o','u'} , sessiz[38] = {'B','C','D','F','G','H','J','K','L','M','N','P','R','S','T','V','Y','Z','q','x','b','c','d','f','g','h','j','k','l','m','n','p','r','s','t','v','y','z'};
char karakter , maxsesli , maxsessiz ;

int i , k , sayac=1 , max1=0 , max2=0 , kelimesayisi=1 , sayackarakter = 0 , hecesayisi = 0;
int main(){
	 
	//Kullanýcý tarafýndan girilen harfin kaç kez geçtiðini veren kodlar.
	printf("Lutfen bir harf giriniz:\n");
	scanf("%c",&karakter);
	for(i = 0 ; charArray[i] != '\0' ; i++ ){
		if(charArray[i] == karakter )
			sayackarakter++ ;
	}
	printf("Bu metinde %d adet %c var",sayackarakter,karakter);

	//toplam harf sayýsýný veren kodlar

	hecesayisi = strlen(charArray);
	printf("\nBu metinde %d adet hece vardir.",hecesayisi);
	
	//En çok geçen sesli heceyi veren kodlar
	for(i=0 ; i<10 ; i++){
		for(k=0; charArray[k] !='\0'  ; k++){
				if (sesli[i] == charArray[k]){
					sayac++;
				}
				else
					continue;
			}
		if(sayac > max1){
				max1 = sayac;
				maxsesli = sesli[i];
		}	
		sayac = 0;						
	}
	printf("\nEn cok gecen sesli harf '%c' ve %d adet gecti",maxsesli,max1)	;
	
	//En çok geçen sessiz harfi veren kodlar.
	
	for(i=0 ; i<38 ; i++){
		for(k=0; charArray[k] !='\0'  ; k++){
			if (sessiz[i] == charArray[k]){
				sayac++;
			}
			else                            
				continue;
		}
		if(sayac > max2){
			max2 = sayac;
			maxsessiz = sessiz[i];
		}	
		sayac = 0;						
	}
	printf("\nEn cok gecen sessiz harf '%c' ve %d adet gecti.",maxsessiz,max2);
}
