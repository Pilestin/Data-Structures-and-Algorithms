#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
struct E{				// Et türü
	char sktE[10];
	char etTuru[1];
	char paketTarihi[10];
};//typedef struct E Et;
struct T{				// Tarým türü
	char tarimTuru[1];
	char alimTarihi[10];
};//typedef struct T Tarim;
struct S{				// Süt 
	char sktS[10];
};//typedef struct S Sut;
struct K{				// Konserve
	char sktK[7];	//sadece ay ve yýl
	int reyonK;			
	char reyonTarafK[1];
};//typedef struct K Konserve;
struct G{				// Gýda dýþý
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
		printf("Ürün adýný giriniz : ");									
		scanf("%s",iter->urunAdi);							
		printf("Ürün maliyetini TL cinsinden giriniz : ");									
		scanf("%d",&tl);												
		printf("Et türünü giriniz (R: Kýrmýzý et , B: Balýk , P:Tavuk) : ");													
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
		printf("Ürün adýný giriniz : ");									
		scanf("%s",iter->urunAdi);							
		printf("Ürün maliyetini TL cinsinden giriniz : ");									
		scanf("%d",&tl);												
		printf("Tarým türünü giriniz (M:Meyve , S:Sebze) : ");													
		scanf("%s",&iter->tarim.tarimTuru[0]);			
		printf("Alýnma tarihini giriniz (#-#-#) : ");		
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
		printf("Ürün adýný giriniz : ");									
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
		printf("Ürün adýný giriniz : ");									
		scanf("%s",iter->urunAdi);							
		printf("Ürün maliyetini TL cinsinden giriniz : ");									
		scanf("%d",&tl);													
		printf("Son kullanma tarihini giriniz (ay-yýl) : ");		
		scanf("%s",c1);		
		printf("Reyon numarasýný giriniz : ");													
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
		printf("Ürün adýný giriniz : ");									
		scanf("%s",iter->urunAdi);							
		printf("Ürün maliyetini TL cinsinden giriniz : ");									
		scanf("%d",&tl);												
		printf("Ürün türünü giriniz (C:Temizlik Ürünleri , P: Eczane , D: Diðer Ürünler) : ");													
		scanf("%s",&iter->gidadisi.gTuru[0]);			
		printf("Reyon numarasýný giriniz : ");													
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
	
	printf("->Çýkmak için q tuþuna basýnýz.\n\n");

	while(karakter != 'q'){
		
		printf("\n------------------%d.ürün------------------\n",i+1);
		printf("E: et ürünleri \t       T: tarým ürünleri  S: süt ürünü\nK: konserve ürünleri   G: gýda dýþý 	  q: çýkýþ\n\n");
		printf("Ürün Kategorisini Seçiniz : ");
		scanf(" %c",&karakter);
		if((karakter != 'E') && (karakter != 'T') && (karakter != 'S') && (karakter != 'K') && (karakter != 'G') && (karakter != 'q')){
			printf("HATALI TUÞLAMA YAPTINIZ . LÜTFEN TEKRAR GÝRÝNÝZ.");
			continue;
		}
		urun_kaydet( p , karakter);
		i++;
	}
	urun_goster(root);

}


