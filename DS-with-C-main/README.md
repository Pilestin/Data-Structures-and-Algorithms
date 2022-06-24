# C - Data Structures

Created: March 14, 2022 1:51 PM

### Veri Yapıları dersinde yapılan ödevlerin bir kısmıdır.

| İsim | Klasör |
| --- | --- |
| İndex Tablosu | ![1](https://github.com/Pilestin/DS-with-C/tree/main/1) |
| Hanoi Oyunu | ![2](https://github.com/Pilestin/DS-with-C/tree/main/2) |
| Market Uygulaması | ![3](https://github.com/Pilestin/DS-with-C/tree/main/3) |

### İndex Tablosu

![Untitled](Untitled%20fcdf9/Untitled.png)

```c
#include<stdio.h>
int tablo[15][3] ={	{0 , 18060311 , 40},		// Ekle fonksiyonu çalıştırmadan sil ve yazdır gibi fonksiyonları çalıştırabilmek için önceden tanımlı dizimiz.
					{1 , 20060045 , 50},
    				{2 , 19061091 , 75},
    				{3 , 20060134 , 90},
   					{4 , 20060678 , 40},
    				{5 , 18061086 , 75},
    				{6 , 20060032 , 50},
    				{7 , 20060067 , 60},
    				{8 , 19060456 , 60},
    				{9 , 18060245 , 75},
    				{10 , 20060110 , 40},
    				{11 , 20060234 , 90},
    				{12 , 20060141 , 60},
    				{13 , 20060011 , 50},
    				{14 , 20060012 , 60}
};
int yenitablo[15][3]; 		// Ekle fonksiyonuna gelen değerler sıralandıktan sonra oluşacak değerleri tutan dizi.
	
void ekrana_yazdir(){
	int i = 0;
	printf("\n--------Yeni tablo------------\n");
	printf("Indis:\tNumarasi:\tNotu:\n\n");
	for(i;i<15;i++){
		printf("%d\t%d\t%d\n",tablo[i][0] , tablo[i][1] , tablo[i][2]);
	}
	printf("______________________________\n");
}

int sirala(int tablo[15][3]){			
	int i = 0;
	int k = 0;
	int aradeger = 0;
	for(i ; i < 15 ; i++){			
		k = 0;
		for(k;k<14;k++){
			if (tablo[k][2] < tablo[k+1][2]){    // Ders notuna göre sıralama
            	// Not değişimi
            	aradeger = tablo[k+1][2] ;
            	tablo[k+1][2] = tablo[k][2] ;
            	tablo[k][2] = aradeger ;
            	// Öğrenci numarası değişimi
           		aradeger = tablo[k+1][1];
            	tablo[k+1][1] = tablo[k][1];
            	tablo[k][1] = aradeger ;
            	// İndex değişimi
            	aradeger = tablo[k+1][0];
            	tablo[k+1][0] = tablo[k][0];
            	tablo[k][0] = aradeger ;			
			}
        	else if ((tablo[k][2] == tablo[k+1][2]) & (tablo[k][1] > tablo[k+1][1]) ){    // Ders notları eşitse öğrenci numarasına göre sıralama
            		// Öğrenci numarası değişimi
                	aradeger = tablo[k+1][1];
                	tablo[k+1][1] = tablo[k][1];
                	tablo[k][1] = aradeger;
                	// İndex değişimi
                	aradeger = tablo[k+1][0];
                	tablo[k+1][0] = tablo[k][0];
                	tablo[k][0] = aradeger;
				}
			}
		}	
}

int ekle(int ogr_no , int puan , int index){ 
	int i = 0 , k  ;
	for(i ; i<15 ; i++){
		if( puan > yenitablo[i][2] ){					// Eğer yeni eklenen puan tablodakinden(şu an 0) büyükse döngü başlar. 
			for( k = 14 ; k>i ; k-- ){					// En alttan başlayarak her satırı bir aşağıya kaydırır. Ta ki , yeni gelen puan değerinin büyük olduğu satır aşağı inene kadar.
				yenitablo[k][0] = yenitablo[k-1][0];
				yenitablo[k][1] = yenitablo[k-1][1];
				yenitablo[k][2] = yenitablo[k-1][2];
			}
			yenitablo[i][0] = index;					// Satırlar aşağı indiğinde oluşan boş satıra  , fonksiyona gelen değerler yerleşir.
			yenitablo[i][1] = ogr_no;
			yenitablo[i][2] = puan ; 
			break;
		}
		else if( (puan == yenitablo[i][2]) & (ogr_no < yenitablo[i][1] )){	// Üstteki algoritmanın aynısını yapar.
			for(k = 14; k>i ; k--){
				yenitablo[k][0] = yenitablo[k-1][0];
				yenitablo[k][1] = yenitablo[k-1][1];
				yenitablo[k][2] = yenitablo[k-1][2];
			}
			yenitablo[i][0] = index;
			yenitablo[i][1] = ogr_no;
			yenitablo[i][2] = puan ; 
			break;
		}
	}
}
	
int sil(int tablo[15][3], int index){
	int i = 0 , k;
	for(i = 0 ; i<15 ; i++){										// Silinecek öğrencinin tabloda hangi index de olduğunu bulmamız için döngü.
		if(tablo[i][0] == index)
			k = i ;		
	}
	printf("\n-------Silinen ogrenci--------\n");
	printf("Indis\tNumarasi\tNotu\n  %d\t%d\t %d\n",tablo[k][0],tablo[k][1],tablo[k][2]);
	printf("------------------------------\n");
	for(i = k ; i<15 ; i++ ){										// Bulunan indexin altında kalan satırlar bir üst kısma taşınır.
		tablo[i][0] = tablo[i+1][0];
		tablo[i][1] = tablo[i+1][1];
		tablo[i][2] = tablo[i+1][2];
	}
	for(i = 0;i<15;i++){													// Tabloyu ekrana bastırır. 
		printf("%d\t%d\t%d\n",tablo[i][0] , tablo[i][1] , tablo[i][2]);
	}
}

void degistir(int puan,int index){ 
	int i = 0;
	for(i = 0 ; i < 15 ; i++){							// Tabloda tüm değerleri tarar ve aranan indexdeki öğrenci bulununca not bölümünü günceller.
		if(tablo[i][0] == index )
			tablo[i][2] = puan;			
	}
	sirala(tablo);										// Güncel değeri sirala fonksiyonuna gönderir ve ardından tabloyu günceller.
}

void yazdir(int puan){									
	int i = 0  ;
	printf("\n----------------------------------\n%d notundan yuksek alan ogrenciler:\n----------------------------------\n",puan);
	for (i;i<15 ; i++){
		if(tablo[i][2] > puan){
			printf("%d\t%d\t%d\t\n",tablo[i][0],tablo[i][1],tablo[i][2]);		 
		}
	}
}

int main(){
	int islem  ;
	int i , no , puan ;
	while(1){
		printf("\n______________________________\n");
		printf("Tabloyu  yazdirmak  icin : 0\n");
		printf("Ekle     fonksiyonu icin : 1\n");
		printf("Sil  	 fonksiyonu icin : 2\n");
		printf("Degistir fonksiyonu icin : 3\n");
		printf("Yazdir   fonksiyonu icin : 4\n");
		printf("Programdan  cikmak  icin : 5\n");
		printf("______________________________");
		printf("\nLutfen islem seciniz : ");
		scanf("%d",&islem);
		
		switch (islem){
			
			case 0: // ekrana_yazdir()
				for(i=0;i<15;i++){
					printf("%d\t%d\t%d\n",tablo[i][0] , tablo[i][1] , tablo[i][2]);
				}
			
				break;
				
			case 1: // ekle()
			
				printf("\n---Tabloyu tek tek alip siralar---\n");
				for(i = 0 ; i<15 ; i++){										// Orjinal tablodaki değerleri ekle fonksiyonuna göndermek için döngü.
					ekle(tablo[i][1] , tablo[i][2] , tablo[i][0] );
				}
				for(i = 0 ; i<15 ; i++){										// Ekle fonksiyonunda oluşan yenitablo dizisini orjinal tablo dizisine atmak için döngü.
					tablo[i][0] = yenitablo[i][0];
					tablo[i][1] = yenitablo[i][1];
					tablo[i][2] = yenitablo[i][2];
				}
				for(i = 0;i<15;i++){											// Tabloyu ekrana bastırır.	
					printf("%d\t%d\t%d\n",tablo[i][0] , tablo[i][1] , tablo[i][2]);}
				break;
	
			case 2:	// Sil()
				
				printf("Silinecek indisi giriniz : ");scanf("%d",&i);
				sil(tablo , i);
				break;
				
			case 3: // degistir()
				
				printf("\nNotunu degistirmek istediginiz ogrencinin indisini giriniz    : ");scanf("%d",&i);
				printf("\nNotunu degistirmek istediginiz ogrencinin yeni notunu giriniz : ");scanf("%d",&puan);
				degistir(puan,i);
				break;
				
			case 4: // yazdir()
				
				printf("\nHangi sayidan yuksek olan notlari gormek istersiniz : ");scanf("%d",&puan);
				yazdir(puan);
				break;
		}
		if (islem == 5){
			break;
		}	
	}				
}

```

### Hanoi Oyunu

![Untitled](Untitled%20fcdf9/Untitled%201.png)

```c
#include<stdio.h>										
#include<stdlib.h>	
#include<locale.h>			
int adim = 0;							// Oynanan adım sayısını tutan değişken (Bizim durumumuz için 7 adım var.)
struct n{
	int veri[3];						// Diskleri tutacak değişken. DİSKLER BU UYGULAMA İÇİN 1 - 2 - 3 ALINMIŞTIR.
	int sayac , tepe , hangicubuk;		// sayac : disk sayısını tutar  ; tepe : çubuktaki en üst diski tutar.  ; hangicubuk : hangi cubuk olduğu bilgisini tutar. 
}a[3];typedef struct n yigin;

int top(yigin *kimin ){												// Fonksiyona verilen çubukta en üstteki veriyi döndürür.
	return kimin->veri[kimin->tepe];
}

int ekle(yigin *p , yigin *n){										// Disklerin taşınabilme durumunu kontrol eden fonksiyon(kimi , nereye)
	if(n->sayac == 0 || top(p) < top(n)  ){	// ya içeride disk olmayacak ya da içerideki disk ekleyeceğimiz diskten daha büyük olacak.
		return 1;
	}
	else
		printf("\n!!!!! TAŞINAMAZ !!!!!\n\n");
		return 0;
}

int push(yigin *p , int sayi){										// Verilen çubuğa , verilen sayıyı (diski) ekler.
	if(p->sayac == 0){
		p->veri[p->tepe] = sayi;
		p->sayac++ ;
		printf("\n%d diskini %d. çubuğa  ekledim  \n", sayi ,p->hangicubuk );
	}
	else if(p->sayac < 3 && p->sayac > 0){		 
		p->veri[0] = p->veri[1];							//  Çubuktaki elemanları bir alt kısma taşır.[Dizide indislerini azaltır.] Sayi değişkenini en üstte oluşan boşluğa ekler.
		p->veri[1] = p->veri[2];
		p->veri[2] = sayi ; 
		p->sayac++;
		printf("\n%d diskini %d. çubuğa  ekledim  \n", sayi ,p->hangicubuk );
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
	dizi[1] = p->veri[0];	// dizi arrayi 2 elemanlı ve silinecek çubuktaki son iki diski tutmak için var.
	
	p->veri[0] = 0;			// çubuktaki en üst disk silindikten sonra diğer diskler yukarı çıkmalı. En altta kalan boşluk ise yine 0 olacak.				
	p->veri[1] = dizi[1];	// dizideki elemanları tekrar çubuğa (üste çıkararak) ekliyoruz.
	p->veri[2] = dizi[0];				
	
	p->sayac--;				// Bir eleman silindiği için sayacımızı azaltıyoruz.
	return silinen;			// silinen değeri döndürüyoruz çünkü daha sonra bu işimize yarayacak.(Oyna ve push fonksiyonunda. Push'daki int sayi değişkeni , silinen değişkeni olacak )
}

int oyna(yigin *kimi , yigin *nereye){								// Çubuk ve diski kontrol eden ekle fonksiyonu ve push fonksiyonunu kullanan fonksiyon. Eğer disk taşınabilir durumdaysa değerleri push fonksiyonuna gönderir ve taşıma gerçekleşir. 
	
	int eklenirmi = ekle(kimi , nereye );	// fonksiyona gelen değerlerin tutarlımı olduğunu kontrol etmek için ekle fonksiyonuna gönderir.
	if(eklenirmi == 1){
		push( nereye , sil(kimi) );	// push(yigin * , int )  push fonksiyonundaki int , bizim taşıyacagımız cubuğun tepesindeki disk.
		return 1;
	}
	else if(kimi->tepe == 0){		// Disk içermeyen çubukları taşımayı engellemek için.					
		printf("\nDiski buraya ekleyemezsin\n");
		return 0;
	}
}

void bastir(){														// Ekrana cubukların durumunu basan fonksiyon
	int i , j;
	for(i=0 ; i<3 ; i++){
		printf("\n|--------%d.Çubuk--------|",i+1);
		for(j=2 ; j>=0 ; j-- ){
			printf("\n|\t    %d\t\t|",a[i].veri[j]);
		}
	}
	printf("\n|_______________________|\n\n");
}

int cubukdolumu(yigin *p ){											// Çubuk boş ise 0 döndüren fonksiyon.
	if(p->sayac == 0){
		printf("\n%d. çubuk dolu !!!\n",p->hangicubuk);
		return 0;
	}
	else{
		return 1;
	}
}

int oyunbittimi(){													// Oyunun bitme koşulu olan 2. ve 3. çubuğun dizili olma durumunu kontrol eder. 
	if(a[0].sayac == 0 && a[1].sayac == 3)
		return 1;
	if(a[0].sayac == 0 && a[2].sayac == 3)
		return 1;
	return 0;
}

int main(){
	setlocale(LC_ALL,"Turkish");
	a[0].veri[0]  	=  3		; 	a[0].veri[1] 	= 2 	; 	a[0].veri[2] 	= 1 	; 		// 1. Çubuk oluşturuldu. 
	a[0].tepe 	 	= 2 		; 	a[1].tepe 		= 2    	; 	a[2].tepe 		= 2 	;		// Çubuktaki tepeyi tutuyor.
	a[0].sayac    	= 3 		; 	a[1].sayac 		= 0    	; 	a[2].sayac 		= 0 	;		// Çubuktaki eleman sayılarını tutuyor.
	a[0].hangicubuk = 1 		;   a[1].hangicubuk = 2 	;   a[2].hangicubuk = 3		;		// Hangi çubuk olduğu bilgisini tutuyor.	
	// İlk çubuğun değerlerini(diskler) verdiğimiz için sayacı 3.												
	int i ; 
	printf("\n************************* HANOİ KULELERİ OYUNUNA HOŞ GELDİN *************************\n\n");
	printf(" Oyundaki amacımız diskleri (sayıları) , başlangıçtaki çubuk dışında başka bir çubuğa \n 7 adımda sıralı olarak dizmeye çalışmaktır.\n\n");
	printf("  KURALLAR:\n");
	printf("\n* Sadece en üstteki diski (sayıyı) hareket ettirebilirsin.(Örn: Başlangıç için 1 diski) \n");
	printf("\n* Taşımak istediğin diski daha küçük bir disk üstüne koyamazsın. \n");
	printf("\n* Boş çubuğa herhangi bir diski koyabilirsin. \n\n\n");
	while( !oyunbittimi() ){
		int oynatCubuk = 0 , tasiCubuk = 0;	
		bastir();
		for(adim = 0 ; adim < 7 ; adim++){
			printf("\n<<<<<<<  Adim : %d  >>>>>>>\n",adim+1);
			printf("\nOynatmak istedigin disk hangi 'ÇUBUKTA' : ");
			scanf("%d",&oynatCubuk);
			printf("\nDiski hangi çubuğaa taşımak istiyorsun : ");
			scanf("%d",&tasiCubuk );
			if(a[oynatCubuk-1].veri[a[oynatCubuk-1].tepe] == 0){			// Özetlersek : İstenen çubukta tepe değer 0 ise , yani hiç eleman yoksa işlem yapma.
				printf("!!!!!! Çubukta eleman yok.Lütfen farklı çubuk seç !!!!!!\n");	// Örneğin 2. çubuk için : a[1].veri[2] de diyebiliriz. (2 indisi tepedeki elemandır.)
				continue;
			}
			else if(oynatCubuk == tasiCubuk){
				printf("!!!!! Diski aynı çubuğa taşıma! Lütfen farklı bir çubuk seç !!!!!!\n");	// Özetlersek : Kullanıcı aynı cubukları girdiyse işlem yapmayacak.																
				continue;															// Örnegin : 1.cubuktaki diski tekrar 1.cubuga tasımaya calısmak gereksiz olur.
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
```

### Market Uygulaması

![Untitled](Untitled%20fcdf9/Untitled%202.png)

![Untitled](Untitled%20fcdf9/Untitled%203.png)

```c
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
struct E{				// Et türü
	char sktE[10];
	char etTuru[1];
	char paketTarihi[10];
};//typedef struct E Et;
struct T{				// Tarım türü
	char tarimTuru[1];
	char alimTarihi[10];
};//typedef struct T Tarim;
struct S{				// Süt 
	char sktS[10];
};//typedef struct S Sut;
struct K{				// Konserve
	char sktK[7];	//sadece ay ve yıl
	int reyonK;			
	char reyonTarafK[1];
};//typedef struct K Konserve;
struct G{				// Gıda dışı
	char gTuru[1];
	int reyonG;
	char reyonTarafG[1];
};//typedef struct G Gidadisi;

struct n{
	int maliyet ;
	char urunAdi[20];
	char kategori[1];
	struct E et;
	struct T tarim;
	struct S sut;
	struct K konserve;
	struct G gidadisi;
	struct n *next ;	
};typedef struct n node;

void urun_kaydet(node * iter ,char k){
	int tl ; char c1[10] ; char c2[10];  int i ;
	
	while(iter->next != NULL){
		iter = iter->next;
	}
	if(k == 'E'){
		
		
		iter->kategori[0] = 'E';
		printf("Ürün adını giriniz : ");									
		scanf("%s",iter->urunAdi);							
		printf("Ürün maliyetini TL cinsinden giriniz : ");									
		scanf("%d",&tl);												
		printf("Et türünü giriniz (R: Kırmızı et , B: Balık , P:Tavuk) : ");													
		scanf(" %c",&iter->et.etTuru[0]);			
		printf("Paketleme tarihini giriniz (#-#-#) : ");		
		scanf("%s",c1);	
		printf("\nSon kullanma tarihini giriniz (#-#-#) : ");		
		scanf("%s",c2);				
		iter->maliyet = tl;
	
		strcpy(iter->et.paketTarihi , c1 );
		strcpy(iter->et.sktE , c2);
		
		printf("%s" , iter->et.paketTarihi);
		
		iter->next = (node *)malloc(sizeof(node));
		iter = iter->next ;
		iter->next = NULL;
	}
	
	else if(k == 'T'){
		int tl ; char c1[10] ;
		
		iter->kategori[0] = 'T';
		printf("Ürün adını giriniz : ");									
		scanf("%s",iter->urunAdi);							
		printf("Ürün maliyetini TL cinsinden giriniz : ");									
		scanf("%d",&tl);												
		printf("Tarım türünü giriniz (M:Meyve , S:Sebze) : ");													
		scanf("%s",&iter->tarim.tarimTuru[0]);			
		printf("Alınma tarihini giriniz (#-#-#) : ");		
		scanf("%s",c1);		
					
		iter->maliyet = tl;
		strcpy(iter->tarim.alimTarihi , c1);
		
		iter->next = (node *)malloc(sizeof(node));
		iter = iter->next ;
		iter->next = NULL;			
		
	}
	
	else if(k == 'S'){
		int tl ; char c1[10] ;
		
		iter->kategori[0] = 'S';
		printf("Ürün adını giriniz : ");									
		scanf("%s",iter->urunAdi);							
		printf("Ürün maliyetini TL cinsinden giriniz : ");									
		scanf("%d",&tl);														
		printf("Son kullanma tarihini giriniz (#-#-#) : ");		
		scanf("%s",c1);		
					
		iter->maliyet = tl;
		strcpy(iter->sut.sktS , c1);
		
		iter->next = (node *)malloc(sizeof(node));
		iter = iter->next ;
		iter->next = NULL;
	}
	
	else if(k == 'K'){
		int tl ; char c1[10] ; 
		
		iter->kategori[0] = 'K';
		printf("Ürün adını giriniz : ");									
		scanf("%s",iter->urunAdi);							
		printf("Ürün maliyetini TL cinsinden giriniz : ");									
		scanf("%d",&tl);													
		printf("Son kullanma tarihini giriniz (ay-yıl) : ");		
		scanf("%s",c1);		
		printf("Reyon numarasını giriniz : ");													
		scanf("%d",&iter->konserve.reyonK);					
		printf("Reyon bölümünü giriniz (A ya da B) : ");		
		scanf("%s",iter->konserve.reyonTarafK);	
		
		iter->maliyet = tl;
		strcpy(iter->konserve.sktK , c1);
		
		iter->next = (node *)malloc(sizeof(node));
		iter = iter->next ;
		iter->next = NULL;
	}
	
	else if(k == 'G'){				
		int tl ;
		
		iter->kategori[0] = 'G';
		printf("Ürün adını giriniz : ");									
		scanf("%s",iter->urunAdi);							
		printf("Ürün maliyetini TL cinsinden giriniz : ");									
		scanf("%d",&tl);												
		printf("Ürün türünü giriniz (C:Temizlik Ürünleri , P: Eczane , D: Diğer Ürünler) : ");													
		scanf("%s",&iter->gidadisi.gTuru[0]);			
		printf("Reyon numarasını giriniz : ");													
		scanf("%d",&iter->gidadisi.reyonG);					
		printf("Reyon bölümünü giriniz (A ya da B) : ");		
		scanf("%s",iter->gidadisi.reyonTarafG);	
		
		iter->maliyet = tl;
		
		iter->next = (node *)malloc(sizeof(node));
		iter = iter->next ;
		iter->next = NULL;
	}
	
}

void urun_goster(node *iter){
	int i = 1;
	printf("-----------------KAYITLI ÜRÜNLER-----------------\n");
	while(iter->next!=NULL){
		printf("%d. ",i);
			 if(iter->kategori[0] == 'E') { printf("%s\t%dTL\t%c\t%s\t%s\n", iter->urunAdi , iter->maliyet , iter->et.etTuru[0] , iter->et.paketTarihi , iter->et.sktE);}	
				
		
		else if(iter->kategori[0] == 'T')	printf("%s\t%dTL\t%c\t%s\n"		, iter->urunAdi , iter->maliyet , iter->tarim.tarimTuru[0] , iter->tarim.alimTarihi );
			
		
		else if(iter->kategori[0] == 'S')	printf("%s\t\t%dTL\t%s\n"		, iter->urunAdi , iter->maliyet , iter->sut.sktS );
			
	
		else if(iter->kategori[0] == 'K')	printf("%s\t%dTL\t%s\t%d\t%c\n"	, iter->urunAdi , iter->maliyet , iter->konserve.sktK , iter->konserve.reyonK , iter->konserve.reyonTarafK[0] );
			

		else if(iter->kategori[0] == 'G')	printf("%s\t%dTL\t%c\t%d\t%c\n"	, iter->urunAdi , iter->maliyet , iter->gidadisi.gTuru[0] , iter->gidadisi.reyonG , iter->gidadisi.reyonTarafG[0] );
						
			iter = iter->next;
			i++;
	}
	printf("\n-------------------------------------------------\n");
}

int main(){
	setlocale(LC_ALL,"Turkish");
	int i = 0 ;
	char karakter;
	
	node * root = (node *)malloc(sizeof(node)) ;
	node * p = root ;
	root->next = NULL;
	
	printf("->Çıkmak için q tuşuna basınız.\n\n");

	while(karakter != 'q'){
		
		printf("\n------------------%d.ürün------------------\n",i+1);
		printf("E: et ürünleri \t       T: tarım ürünleri  S: süt ürünü\nK: konserve ürünleri   G: gıda dışı 	  q: çıkış\n\n");
		printf("Ürün Kategorisini Seçiniz : ");
		scanf(" %c",&karakter);
		if((karakter != 'E') && (karakter != 'T') && (karakter != 'S') && (karakter != 'K') && (karakter != 'G') && (karakter != 'q')){
			printf("HATALI TUŞLAMA YAPTINIZ . LÜTFEN TEKRAR GİRİNİZ.");
			continue;
		}
		urun_kaydet( p , karakter);
		i++;
	}
	urun_goster(root);

}
```
