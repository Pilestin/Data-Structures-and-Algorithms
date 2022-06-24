#include<stdio.h>										
#include<stdlib.h>	
#include<locale.h>			
int adim = 0;							// Oynanan adým sayýsýný tutan deðiþken (Bizim durumumuz için 7 adým var.)
struct n{
	int veri[3];						// Diskleri tutacak deðiþken. DÝSKLER BU UYGULAMA ÝÇÝN 1 - 2 - 3 ALINMIÞTIR.
	int sayac , tepe , hangicubuk;		// sayac : disk sayýsýný tutar  ; tepe : çubuktaki en üst diski tutar.  ; hangicubuk : hangi cubuk olduðu bilgisini tutar. 
}a[3];typedef struct n yigin;

int top(yigin *kimin ){												// Fonksiyona verilen çubukta en üstteki veriyi döndürür.
	return kimin->veri[kimin->tepe];
}

int ekle(yigin *p , yigin *n){										// Disklerin taþýnabilme durumunu kontrol eden fonksiyon(kimi , nereye)
	if(n->sayac == 0 || top(p) < top(n)  ){	// ya içeride disk olmayacak ya da içerideki disk ekleyeceðimiz diskten daha büyük olacak.
		return 1;
	}
	else
		printf("\n!!!!! TAÞINAMAZ !!!!!\n\n");
		return 0;
}

int push(yigin *p , int sayi){										// Verilen çubuða , verilen sayýyý (diski) ekler.
	if(p->sayac == 0){
		p->veri[p->tepe] = sayi;
		p->sayac++ ;
		printf("\n%d diskini %d. çubuða  ekledim  \n", sayi ,p->hangicubuk );
	}
	else if(p->sayac < 3 && p->sayac > 0){		 
		p->veri[0] = p->veri[1];							//  Çubuktaki elemanlarý bir alt kýsma taþýr.[Dizide indislerini azaltýr.] Sayi deðiþkenini en üstte oluþan boþluða ekler.
		p->veri[1] = p->veri[2];
		p->veri[2] = sayi ; 
		p->sayac++;
		printf("\n%d diskini %d. çubuða  ekledim  \n", sayi ,p->hangicubuk );
	}
	else{
		printf("\n heeeeeeeeeeey icerisi zaten dolu\n");
		return 0;
	}	
}

int sil(yigin *p){													// Diski siler ve yerini günceller.
	int i , dizi [2];
	int silinen = p->veri[p->tepe];
	if ( p->sayac == 0 ){
		return 0;
	}
	
	dizi[0] = p->veri[1];
	dizi[1] = p->veri[0];	// dizi arrayi 2 elemanlý ve silinecek çubuktaki son iki diski tutmak için var.
	
	p->veri[0] = 0;			// çubuktaki en üst disk silindikten sonra diðer diskler yukarý çýkmalý. En altta kalan boþluk ise yine 0 olacak.				
	p->veri[1] = dizi[1];	// dizideki elemanlarý tekrar çubuða (üste çýkararak) ekliyoruz.
	p->veri[2] = dizi[0];				
	
	p->sayac--;				// Bir eleman silindiði için sayacýmýzý azaltýyoruz.
	return silinen;			// silinen deðeri döndürüyoruz çünkü daha sonra bu iþimize yarayacak.(Oyna ve push fonksiyonunda. Push'daki int sayi deðiþkeni , silinen deðiþkeni olacak )
}

int oyna(yigin *kimi , yigin *nereye){								// Çubuk ve diski kontrol eden ekle fonksiyonu ve push fonksiyonunu kullanan fonksiyon. Eðer disk taþýnabilir durumdaysa deðerleri push fonksiyonuna gönderir ve taþýma gerçekleþir. 
	
	int eklenirmi = ekle(kimi , nereye );	// fonksiyona gelen deðerlerin tutarlýmý olduðunu kontrol etmek için ekle fonksiyonuna gönderir.
	if(eklenirmi == 1){
		push( nereye , sil(kimi) );	// push(yigin * , int )  push fonksiyonundaki int , bizim taþýyacagýmýz cubuðun tepesindeki disk.
		return 1;
	}
	else if(kimi->tepe == 0){		// Disk içermeyen çubuklarý taþýmayý engellemek için.					
		printf("\nDiski buraya ekleyemezsin\n");
		return 0;
	}
}

void bastir(){														// Ekrana cubuklarýn durumunu basan fonksiyon
	int i , j;
	for(i=0 ; i<3 ; i++){
		printf("\n|--------%d.Çubuk--------|",i+1);
		for(j=2 ; j>=0 ; j-- ){
			printf("\n|\t    %d\t\t|",a[i].veri[j]);
		}
	}
	printf("\n|_______________________|\n\n");
}

int cubukdolumu(yigin *p ){											// Çubuk boþ ise 0 döndüren fonksiyon.
	if(p->sayac == 0){
		printf("\n%d. çubuk dolu !!!\n",p->hangicubuk);
		return 0;
	}
	else{
		return 1;
	}
}

int oyunbittimi(){													// Oyunun bitme koþulu olan 2. ve 3. çubuðun dizili olma durumunu kontrol eder. 
	if(a[0].sayac == 0 && a[1].sayac == 3)
		return 1;
	if(a[0].sayac == 0 && a[2].sayac == 3)
		return 1;
	return 0;
}

int main(){
	setlocale(LC_ALL,"Turkish");
	a[0].veri[0]  	=  3		; 	a[0].veri[1] 	= 2 	; 	a[0].veri[2] 	= 1 	; 		// 1. Çubuk oluþturuldu. 
	a[0].tepe 	 	= 2 		; 	a[1].tepe 		= 2    	; 	a[2].tepe 		= 2 	;		// Çubuktaki tepeyi tutuyor.
	a[0].sayac    	= 3 		; 	a[1].sayac 		= 0    	; 	a[2].sayac 		= 0 	;		// Çubuktaki eleman sayýlarýný tutuyor.
	a[0].hangicubuk = 1 		;   a[1].hangicubuk = 2 	;   a[2].hangicubuk = 3		;		// Hangi çubuk olduðu bilgisini tutuyor.	
	// Ýlk çubuðun deðerlerini(diskler) verdiðimiz için sayacý 3.												
	int i ; 
	printf("\n************************* HANOÝ KULELERÝ OYUNUNA HOÞ GELDÝN *************************\n\n");
	printf(" Oyundaki amacýmýz diskleri (sayýlarý) , baþlangýçtaki çubuk dýþýnda baþka bir çubuða \n 7 adýmda sýralý olarak dizmeye çalýþmaktýr.\n\n");
	printf("  KURALLAR:\n");
	printf("\n* Sadece en üstteki diski (sayýyý) hareket ettirebilirsin.(Örn: Baþlangýç için 1 diski) \n");
	printf("\n* Taþýmak istediðin diski daha küçük bir disk üstüne koyamazsýn. \n");
	printf("\n* Boþ çubuða herhangi bir diski koyabilirsin. \n\n\n");
	while( !oyunbittimi() ){
		int oynatCubuk = 0 , tasiCubuk = 0;	
		bastir();
		for(adim = 0 ; adim < 7 ; adim++){
			printf("\n<<<<<<<  Adim : %d  >>>>>>>\n",adim+1);
			printf("\nOynatmak istedigin disk hangi 'ÇUBUKTA' : ");
			scanf("%d",&oynatCubuk);
			printf("\nDiski hangi çubuðaa taþýmak istiyorsun : ");
			scanf("%d",&tasiCubuk );
			if(a[oynatCubuk-1].veri[a[oynatCubuk-1].tepe] == 0){			// Özetlersek : Ýstenen çubukta tepe deðer 0 ise , yani hiç eleman yoksa iþlem yapma.
				printf("!!!!!! Çubukta eleman yok.Lütfen farklý çubuk seç !!!!!!\n");	// Örneðin 2. çubuk için : a[1].veri[2] de diyebiliriz. (2 indisi tepedeki elemandýr.)
				continue;
			}
			else if(oynatCubuk == tasiCubuk){
				printf("!!!!! Diski ayný çubuða taþýma! Lütfen farklý bir çubuk seç !!!!!!\n");	// Özetlersek : Kullanýcý ayný cubuklarý girdiyse iþlem yapmayacak.																
				continue;															// Örnegin : 1.cubuktaki diski tekrar 1.cubuga tasýmaya calýsmak gereksiz olur.
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
