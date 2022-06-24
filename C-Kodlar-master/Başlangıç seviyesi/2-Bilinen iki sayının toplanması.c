#include <stdio.h>
 int main (void)
 {
 int number1 = 13;			    //Bellekte sayýmýz için yer tuttuk ve deðerini belirttik. 
 int number2 = 5;			    //Bellekte sayýmýz için yer tuttuk ve deðerini belirttik.
 int toplam  = number1 + number2; //Bellekte toplama yapabilmek için yer ayarladýk.
 printf("Toplam = %d",toplam);    
 
 //%d : int. deðerler için printf'de format belirleyici.
 // Bu %d yerine gelecek deðeri de týrnak kapadýktan sonra virgül koyup deðiþkeni yazýyoruz. 
 
 return 0;
 }
