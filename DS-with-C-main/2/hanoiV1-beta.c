#include<stdio.h>										
#include<stdlib.h>	
#include<locale.h>			
int adim = 0;							// Oynanan ad�m say�s�n� tutan de�i�ken (Bizim durumumuz i�in 7 ad�m var.)
struct n{
	int veri[3];						// Diskleri tutacak de�i�ken. D�SKLER BU UYGULAMA ���N 1 - 2 - 3 ALINMI�TIR.
	int sayac , tepe , hangicubuk;		// sayac : disk say�s�n� tutar  ; tepe : �ubuktaki en �st diski tutar.  ; hangicubuk : hangi cubuk oldu�u bilgisini tutar. 
}a[3];typedef struct n yigin;

int top(yigin *kimin ){												// Fonksiyona verilen �ubukta en �stteki veriyi d�nd�r�r.
	return kimin->veri[kimin->tepe];
}

int ekle(yigin *p , yigin *n){										// Disklerin ta��nabilme durumunu kontrol eden fonksiyon(kimi , nereye)
	if(n->sayac == 0 || top(p) < top(n)  ){	// ya i�eride disk olmayacak ya da i�erideki disk ekleyece�imiz diskten daha b�y�k olacak.
		return 1;
	}
	else
		printf("\n!!!!! TA�INAMAZ !!!!!\n\n");
		return 0;
}

int push(yigin *p , int sayi){										// Verilen �ubu�a , verilen say�y� (diski) ekler.
	if(p->sayac == 0){
		p->veri[p->tepe] = sayi;
		p->sayac++ ;
		printf("\n%d diskini %d. �ubu�a  ekledim  \n", sayi ,p->hangicubuk );
	}
	else if(p->sayac < 3 && p->sayac > 0){		 
		p->veri[0] = p->veri[1];							//  �ubuktaki elemanlar� bir alt k�sma ta��r.[Dizide indislerini azalt�r.] Sayi de�i�kenini en �stte olu�an bo�lu�a ekler.
		p->veri[1] = p->veri[2];
		p->veri[2] = sayi ; 
		p->sayac++;
		printf("\n%d diskini %d. �ubu�a  ekledim  \n", sayi ,p->hangicubuk );
	}
	else{
		printf("\n heeeeeeeeeeey icerisi zaten dolu\n");
		return 0;
	}	
}

int sil(yigin *p){													// Diski siler ve yerini g�nceller.
	int i , dizi [2];
	int silinen = p->veri[p->tepe];
	if ( p->sayac == 0 ){
		return 0;
	}
	
	dizi[0] = p->veri[1];
	dizi[1] = p->veri[0];	// dizi arrayi 2 elemanl� ve silinecek �ubuktaki son iki diski tutmak i�in var.
	
	p->veri[0] = 0;			// �ubuktaki en �st disk silindikten sonra di�er diskler yukar� ��kmal�. En altta kalan bo�luk ise yine 0 olacak.				
	p->veri[1] = dizi[1];	// dizideki elemanlar� tekrar �ubu�a (�ste ��kararak) ekliyoruz.
	p->veri[2] = dizi[0];				
	
	p->sayac--;				// Bir eleman silindi�i i�in sayac�m�z� azalt�yoruz.
	return silinen;			// silinen de�eri d�nd�r�yoruz ��nk� daha sonra bu i�imize yarayacak.(Oyna ve push fonksiyonunda. Push'daki int sayi de�i�keni , silinen de�i�keni olacak )
}

int oyna(yigin *kimi , yigin *nereye){								// �ubuk ve diski kontrol eden ekle fonksiyonu ve push fonksiyonunu kullanan fonksiyon. E�er disk ta��nabilir durumdaysa de�erleri push fonksiyonuna g�nderir ve ta��ma ger�ekle�ir. 
	
	int eklenirmi = ekle(kimi , nereye );	// fonksiyona gelen de�erlerin tutarl�m� oldu�unu kontrol etmek i�in ekle fonksiyonuna g�nderir.
	if(eklenirmi == 1){
		push( nereye , sil(kimi) );	// push(yigin * , int )  push fonksiyonundaki int , bizim ta��yacag�m�z cubu�un tepesindeki disk.
		return 1;
	}
	else if(kimi->tepe == 0){		// Disk i�ermeyen �ubuklar� ta��may� engellemek i�in.					
		printf("\nDiski buraya ekleyemezsin\n");
		return 0;
	}
}

void bastir(){														// Ekrana cubuklar�n durumunu basan fonksiyon
	int i , j;
	for(i=0 ; i<3 ; i++){
		printf("\n|--------%d.�ubuk--------|",i+1);
		for(j=2 ; j>=0 ; j-- ){
			printf("\n|\t    %d\t\t|",a[i].veri[j]);
		}
	}
	printf("\n|_______________________|\n\n");
}

int cubukdolumu(yigin *p ){											// �ubuk bo� ise 0 d�nd�ren fonksiyon.
	if(p->sayac == 0){
		printf("\n%d. �ubuk dolu !!!\n",p->hangicubuk);
		return 0;
	}
	else{
		return 1;
	}
}

int oyunbittimi(){													// Oyunun bitme ko�ulu olan 2. ve 3. �ubu�un dizili olma durumunu kontrol eder. 
	if(a[0].sayac == 0 && a[1].sayac == 3)
		return 1;
	if(a[0].sayac == 0 && a[2].sayac == 3)
		return 1;
	return 0;
}

int main(){
	setlocale(LC_ALL,"Turkish");
	a[0].veri[0]  	=  3		; 	a[0].veri[1] 	= 2 	; 	a[0].veri[2] 	= 1 	; 		// 1. �ubuk olu�turuldu. 
	a[0].tepe 	 	= 2 		; 	a[1].tepe 		= 2    	; 	a[2].tepe 		= 2 	;		// �ubuktaki tepeyi tutuyor.
	a[0].sayac    	= 3 		; 	a[1].sayac 		= 0    	; 	a[2].sayac 		= 0 	;		// �ubuktaki eleman say�lar�n� tutuyor.
	a[0].hangicubuk = 1 		;   a[1].hangicubuk = 2 	;   a[2].hangicubuk = 3		;		// Hangi �ubuk oldu�u bilgisini tutuyor.	
	// �lk �ubu�un de�erlerini(diskler) verdi�imiz i�in sayac� 3.												
	int i ; 
	printf("\n************************* HANO� KULELER� OYUNUNA HO� GELD�N *************************\n\n");
	printf(" Oyundaki amac�m�z diskleri (say�lar�) , ba�lang��taki �ubuk d���nda ba�ka bir �ubu�a \n 7 ad�mda s�ral� olarak dizmeye �al��makt�r.\n\n");
	printf("  KURALLAR:\n");
	printf("\n* Sadece en �stteki diski (say�y�) hareket ettirebilirsin.(�rn: Ba�lang�� i�in 1 diski) \n");
	printf("\n* Ta��mak istedi�in diski daha k���k bir disk �st�ne koyamazs�n. \n");
	printf("\n* Bo� �ubu�a herhangi bir diski koyabilirsin. \n\n\n");
	while( !oyunbittimi() ){
		int oynatCubuk = 0 , tasiCubuk = 0;	
		bastir();
		for(adim = 0 ; adim < 7 ; adim++){
			printf("\n<<<<<<<  Adim : %d  >>>>>>>\n",adim+1);
			printf("\nOynatmak istedigin disk hangi '�UBUKTA' : ");
			scanf("%d",&oynatCubuk);
			printf("\nDiski hangi �ubu�aa ta��mak istiyorsun : ");
			scanf("%d",&tasiCubuk );
			if(a[oynatCubuk-1].veri[a[oynatCubuk-1].tepe] == 0){			// �zetlersek : �stenen �ubukta tepe de�er 0 ise , yani hi� eleman yoksa i�lem yapma.
				printf("!!!!!! �ubukta eleman yok.L�tfen farkl� �ubuk se� !!!!!!\n");	// �rne�in 2. �ubuk i�in : a[1].veri[2] de diyebiliriz. (2 indisi tepedeki elemand�r.)
				continue;
			}
			else if(oynatCubuk == tasiCubuk){
				printf("!!!!! Diski ayn� �ubu�a ta��ma! L�tfen farkl� bir �ubuk se� !!!!!!\n");	// �zetlersek : Kullan�c� ayn� cubuklar� girdiyse i�lem yapmayacak.																
				continue;															// �rnegin : 1.cubuktaki diski tekrar 1.cubuga tas�maya cal�smak gereksiz olur.
			}
			else{
				oyna(&a[oynatCubuk - 1]  , &a[tasiCubuk-1] );
				bastir();	
			}
		}
		if(adim >=7   &&   !oyunbittimi()  ){
			printf("Maalesef 7 adimda bitiremedin , rezil  !");
			scanf("%d");
			break;
		}
		if( oyunbittimi() == 1  ){
			printf("\n Tebrikler oyunu bitirdin\n");
			scanf("%d");
			break;
		}
	}
}
