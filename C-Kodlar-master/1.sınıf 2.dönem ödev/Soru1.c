#include<stdio.h>
int main(){
	int i , k ,  sayacsesli = 0 , sayacsessiz=0;
	char sesli[] = {'A','E','I','U','O','a','e','i','o','u'} , sessiz[] = {'B','C','D','F','G','H','J','K','L','M','N','P','R','S','T','V','Y','Z','q','x','w','b','c','d','f','g','h','j','k','l','m','n','p','r','s','t','v','y','z'};
	char dizi[100];
	printf("Lutfen metin giriniz.\n");
	gets(dizi);
	
	for(i=0 ; dizi[i]!='\0';i++){
	
		for(k=0 ; sesli[k]!='\0' ; k++){
			if(dizi[i]==sesli[k])
				sayacsesli++;	
		}
	}
	for(i=0 ; dizi[i]!='\0';i++){
	
		for(k=0 ; sessiz[k]!='\0' ; k++){
			if(dizi[i]==sessiz[k])
				sayacsessiz++;
		}
	}
	printf("Girdiginiz karakter dizisinde %d adet sesli harf vardir.",sayacsesli);
	printf("\nGirdiginiz karakter dizisinde %d adet sessiz harf vardir.",sayacsessiz);		
}




