#include<stdio.h>
#include<stdlib.h>
struct n{
	int indis;
	int faturaMiktari;
	char *isim;
	struct n *next;
};
typedef struct n node ;
typedef struct n node2;
typedef struct n node3;


void yazdirAd(node2 *r ,char harf  ){	// Verilen harfle ba�layan isimleri index tablosundan bulur ve isim s�ras�na g�re yazd�r�r.
	node2 * iter = r;
	while(iter != NULL){
		if (iter->isim[0] == harf){
			printf("%s\t%d\n",iter->isim , iter->faturaMiktari);
		
		}
		iter = iter->next;
	}	
	iter = r ;
	
}

void yazdirTutar(node3 *r , int sayi){	// Verilen say�dan b�y�k ve e�it olan fatura miktarlar�n� index tablosundan bulur ve s�raya g�re yazd�r�r.
	node3 * iter = r;
	
	while(iter != NULL){
		if( iter->faturaMiktari > sayi){
			printf("%s\t%d\n",iter->isim , iter->faturaMiktari);
		}
		iter = iter->next;
	}
	iter = r ;
}

void ekle_1(node *r , char *isim , int f){	// Ekle 1 fonksiyonu de�erleri s�ralamadan normal ekler.
	while (r -> next != NULL){							
		r = r->next;
	}
	r -> next 			= (node*)malloc(sizeof(node));
	r -> faturaMiktari 	= f;
	r -> isim 		  	= isim ;
	r -> next ->next	= NULL;
	
}

node2 * ekle_2(node2 * r , char * isim , int f ){			// Ekle 2 fonksiyonu isme g�re s�ralayarak yeni link list olu�turur.
	if ( r == NULL ){													// E�er hi� node yoksa , elemanlar� direk ekle
		r = (node2 *)malloc(sizeof(node2));
		r->faturaMiktari = f ; 
		r->isim = isim ; 
		r->next = NULL;
	}
	node2 * iter ; 
	iter = r ;
	if( r->next == NULL && r->isim[0] > isim[0]) {						// e�er bir node varsa ve fonksiyona gelen ismin ilk harfi b�y�kse (ascii tablosuna g�re) ba�a ekle 
			node2 *temp = (node2 *)malloc(sizeof(node2));
			temp->faturaMiktari = f ;
			temp->isim 			= isim ; 
			temp->next 			= r ;
			r 					= temp;	
			r->next->next 		= NULL;		
	}
	iter = r ; 
	while(iter->next != NULL  &&  iter->next->isim[0] <= isim[0]  ){	// e�er node i�inde fonksiyona gelen isimden k���k harf (ascii) varsa node un �ncesine kadar git.
		iter = iter->next;
	}
	//burada iter in �n�ne kutu ekle
	node2 *temp = (node2 *)malloc(sizeof(node2));						// Sonraki node fonk. gelen isimden k���k old. i�in araya yeni node ekle
	temp->faturaMiktari	= f;											// Node i�ine fonksiyona gelen bilgileri koy
	temp->isim 			= isim;
	temp->next			= iter->next;
	iter->next			= temp ;
	return r ;
}

	
node3 * ekle_3(node3 *r , char *isim , int f ){				// Ekle 3 fonksiyonu fatura tutar�na g�re s�raayarak yeni link list olu�turur. 
	if(r == NULL){														// E�er hi� node yoksa , elemanlar� direk ekle
		r = (node3 *)malloc(sizeof(node3));
		r->faturaMiktari 	= f;
		r->isim			 	= isim; 
		r->next 			= NULL;
		
	}
	node3 * iter;
	iter = r;
 	if( r->next == NULL && r->faturaMiktari < f) {						// e�er bir node varsa ve gelen de�er b�y�kse ba�a ekle .
			node3 *temp = (node3 *)malloc(sizeof(node3));
			temp->faturaMiktari = f ;
			temp->isim 			= isim ; 
			
			temp->next 			= r ;
			r = temp;	
			r->next->next =NULL;		
	}	
	
	iter = r ;
	while(iter->next != NULL  &&  iter->next->faturaMiktari >= f  ){	// E�er node'lar�n i�indeki say�lar fonksiyona gelen say�dan b�y�kse nodelarda ilerle.
		iter = iter->next;
	}																	// Node'daki de�er k���kse araya eleman ekle						
	//burada iter in �n�ne kutu ekle
	node3 *temp = (node3 *)malloc(sizeof(node3));
	temp->faturaMiktari	= f;
	temp->isim 			= isim;
	temp->next			= iter->next;
	iter->next			= temp ;
	// !Hata : fonksiyona g�nderilen ilk de�eri en ba�ta sabitliyor.
	return r ;
}

void bastir(node2 *r){				// S�ralanm�� isim listesinin pointer�n� al�r ve ekrana basar.
	node2 * iter = r ; 
	while(iter->next != NULL){
		printf("%s\t\t%d\n",iter->isim , iter->faturaMiktari);
		iter = iter->next;
	}
	
	 iter = r ;
}

int main(){
	node *root ;							// Ekle 1 fonksiyonunun pointer�
	root = (node *)malloc(sizeof(node));
	root->next = NULL;
	
	node * root2;							// Ekle 2 fonksiyonunun pointer�
	root2 = NULL; 
	
	node3 * root3;							// Ekle 3 fonksiyonunun pointer�
	root3 = NULL;
	
	//ekle 3 ve yazdirTutar fonksiyonlar�				// ekle 1 ve bast�r fonksiyonu
	root3 = ekle_3(root3,"Ahmet",100); 					ekle_1(root,"Ahmet",100); 
	root3 = ekle_3(root3,"Bilal",1000);					ekle_1(root,"Bilal",1000);
	root3 = ekle_3(root3,"Cemal",600);					ekle_1(root,"Cemal",600);
	root3 = ekle_3(root3,"Adem" ,650);					ekle_1(root,"Adem" ,650);
	root3 = ekle_3(root3,"Yasin",350);					ekle_1(root,"Yasin",350);
	root3 = ekle_3(root3,"Esin" ,270);					ekle_1(root,"Esin" ,270);
	root3 = ekle_3(root3,"Emel" ,410);					ekle_1(root,"Emel" ,410);
	root3 = ekle_3(root3,"Mustafa",750);				ekle_1(root,"Mustafa",750);
	root3 = ekle_3(root3,"Ayten",600);					ekle_1(root,"Ayten",600);
	root3 = ekle_3(root3,"Ceylan",1000);				ekle_1(root,"Ceylan",1000);
	root3 = ekle_3(root3,"Nesrin",900);					ekle_1(root,"Nesrin",900);	
	root3 = ekle_3(root3,"Bekir",850);					ekle_1(root,"Bekir",850);
	root3 = ekle_3(root3,"Emin" ,790);					ekle_1(root,"Emin" ,790);
	root3 = ekle_3(root3,"Hakan",610);					ekle_1(root,"Hakan",610);
	root3 = ekle_3(root3,"Hatice",550);					ekle_1(root,"Hatice",550);						
			
	printf("\tOrjinal link list.\n\n");         				bastir(root);	// Orjinal link listi bast�r�r.	 			
	printf("\n\tFaturalari siralanmis link list\n\n"); 			bastir(root3);	// Faturalar� s�ralanm�� link listi bast�r�r.
	int bulTutar = 600;
	printf("\n\t%d ve ustunde faturalar\n\n",bulTutar);				yazdirTutar(root3 , bulTutar);	// �stenen fatura de�erindeki faturalar� bast�r�r.
	
	// ekle 2 fonksiyonu ve yazdirAd fonksiyonlar� ; 
	root2 = ekle_2(root2,"Ahmet",100); 
	ekle_2(root2,"Bilal",1000);
	ekle_2(root2,"Cemal",600);	
	ekle_2(root2,"Adem" ,650);	
	ekle_2(root2,"Yasin",350);	
	ekle_2(root2,"Esin" ,270);
	ekle_2(root2,"Emel" ,410);	
	ekle_2(root2,"Mustafa",750);
	ekle_2(root2,"Ayten",600);
	ekle_2(root2,"Ceylan",1000);
	ekle_2(root2,"Nesrin",900);
	ekle_2(root2,"Bekir",850);
	ekle_2(root2,"Emin" ,790);
	ekle_2(root2,"Hakan",610);
	ekle_2(root2,"Hatice",550);
	
	printf("\n\tIsme gore siralanmis link list\n\n");								bastir(root2);	// fonksiyon isimleri s�ral� bir �ekilde bast�r�r.
	char bulHarf= 'A';
	printf("\n\tIsmi %c harfi ile baslayanlar\n\n",bulHarf);						yazdirAd(root2 , bulHarf );	// istenen harfte faturalar� bast�r�r.
	
	return 0;
}
