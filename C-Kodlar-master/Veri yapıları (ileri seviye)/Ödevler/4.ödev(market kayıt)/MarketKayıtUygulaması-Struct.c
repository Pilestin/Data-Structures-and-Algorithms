#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
struct E{				// Et t�r�
	char sktE[10];
	char etTuru[1];
	char paketTarihi[10];
};//typedef struct E Et;
struct T{				// Tar�m t�r�
	char tarimTuru[1];
	char alimTarihi[10];
};//typedef struct T Tarim;
struct S{				// S�t 
	char sktS[10];
};//typedef struct S Sut;
struct K{				// Konserve
	char sktK[7];	//sadece ay ve y�l
	int reyonK;			
	char reyonTarafK[1];
};//typedef struct K Konserve;
struct G{				// G�da d���
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
		printf("�r�n ad�n� giriniz : ");									
		scanf("%s",iter->urunAdi);							
		printf("�r�n maliyetini TL cinsinden giriniz : ");									
		scanf("%d",&tl);												
		printf("Et t�r�n� giriniz (R: K�rm�z� et , B: Bal�k , P:Tavuk) : ");													
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
		printf("�r�n ad�n� giriniz : ");									
		scanf("%s",iter->urunAdi);							
		printf("�r�n maliyetini TL cinsinden giriniz : ");									
		scanf("%d",&tl);												
		printf("Tar�m t�r�n� giriniz (M:Meyve , S:Sebze) : ");													
		scanf("%s",&iter->tarim.tarimTuru[0]);			
		printf("Al�nma tarihini giriniz (#-#-#) : ");		
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
		printf("�r�n ad�n� giriniz : ");									
		scanf("%s",iter->urunAdi);							
		printf("�r�n maliyetini TL cinsinden giriniz : ");									
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
		printf("�r�n ad�n� giriniz : ");									
		scanf("%s",iter->urunAdi);							
		printf("�r�n maliyetini TL cinsinden giriniz : ");									
		scanf("%d",&tl);													
		printf("Son kullanma tarihini giriniz (ay-y�l) : ");		
		scanf("%s",c1);		
		printf("Reyon numaras�n� giriniz : ");													
		scanf("%d",&iter->konserve.reyonK);					
		printf("Reyon b�l�m�n� giriniz (A ya da B) : ");		
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
		printf("�r�n ad�n� giriniz : ");									
		scanf("%s",iter->urunAdi);							
		printf("�r�n maliyetini TL cinsinden giriniz : ");									
		scanf("%d",&tl);												
		printf("�r�n t�r�n� giriniz (C:Temizlik �r�nleri , P: Eczane , D: Di�er �r�nler) : ");													
		scanf("%s",&iter->gidadisi.gTuru[0]);			
		printf("Reyon numaras�n� giriniz : ");													
		scanf("%d",&iter->gidadisi.reyonG);					
		printf("Reyon b�l�m�n� giriniz (A ya da B) : ");		
		scanf("%s",iter->gidadisi.reyonTarafG);	
		
		iter->maliyet = tl;
		
		iter->next = (node *)malloc(sizeof(node));
		iter = iter->next ;
		iter->next = NULL;
	}
	
}

void urun_goster(node *iter){
	int i = 1;
	printf("-----------------KAYITLI �R�NLER-----------------\n");
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
	
	printf("->��kmak i�in q tu�una bas�n�z.\n\n");

	while(karakter != 'q'){
		
		printf("\n------------------%d.�r�n------------------\n",i+1);
		printf("E: et �r�nleri \t       T: tar�m �r�nleri  S: s�t �r�n�\nK: konserve �r�nleri   G: g�da d��� 	  q: ��k��\n\n");
		printf("�r�n Kategorisini Se�iniz : ");
		scanf(" %c",&karakter);
		if((karakter != 'E') && (karakter != 'T') && (karakter != 'S') && (karakter != 'K') && (karakter != 'G') && (karakter != 'q')){
			printf("HATALI TU�LAMA YAPTINIZ . L�TFEN TEKRAR G�R�N�Z.");
			continue;
		}
		urun_kaydet( p , karakter);
		i++;
	}
	urun_goster(root);

}


