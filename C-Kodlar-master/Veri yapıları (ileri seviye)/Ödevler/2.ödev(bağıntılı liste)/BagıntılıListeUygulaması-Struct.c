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


void yazdirAd(node2 *r ,char harf  ){	// Verilen harfle baþlayan isimleri index tablosundan bulur ve isim sýrasýna göre yazdýrýr.
	node2 * iter = r;
	while(iter != NULL){
		if (iter->isim[0] == harf){
			printf("%s\t%d\n",iter->isim , iter->faturaMiktari);
		
		}
		iter = iter->next;
	}	
	iter = r ;
	
}

void yazdirTutar(node3 *r , int sayi){	// Verilen sayýdan büyük ve eþit olan fatura miktarlarýný index tablosundan bulur ve sýraya göre yazdýrýr.
	node3 * iter = r;
	
	while(iter != NULL){
		if( iter->faturaMiktari > sayi){
			printf("%s\t%d\n",iter->isim , iter->faturaMiktari);
		}
		iter = iter->next;
	}
	iter = r ;
}

void ekle_1(node *r , char *isim , int f){	// Ekle 1 fonksiyonu deðerleri sýralamadan normal ekler.
	while (r -> next != NULL){							
		r = r->next;
	}
	r -> next 			= (node*)malloc(sizeof(node));
	r -> faturaMiktari 	= f;
	r -> isim 		  	= isim ;
	r -> next ->next	= NULL;
	
}

node2 * ekle_2(node2 * r , char * isim , int f ){			// Ekle 2 fonksiyonu isme göre sýralayarak yeni link list oluþturur.
	if ( r == NULL ){													// Eðer hiç node yoksa , elemanlarý direk ekle
		r = (node2 *)malloc(sizeof(node2));
		r->faturaMiktari = f ; 
		r->isim = isim ; 
		r->next = NULL;
	}
	node2 * iter ; 
	iter = r ;
	if( r->next == NULL && r->isim[0] > isim[0]) {						// eðer bir node varsa ve fonksiyona gelen ismin ilk harfi büyükse (ascii tablosuna göre) baþa ekle 
			node2 *temp = (node2 *)malloc(sizeof(node2));
			temp->faturaMiktari = f ;
			temp->isim 			= isim ; 
			temp->next 			= r ;
			r 					= temp;	
			r->next->next 		= NULL;		
	}
	iter = r ; 
	while(iter->next != NULL  &&  iter->next->isim[0] <= isim[0]  ){	// eðer node içinde fonksiyona gelen isimden küçük harf (ascii) varsa node un öncesine kadar git.
		iter = iter->next;
	}
	//burada iter in önüne kutu ekle
	node2 *temp = (node2 *)malloc(sizeof(node2));						// Sonraki node fonk. gelen isimden küçük old. için araya yeni node ekle
	temp->faturaMiktari	= f;											// Node içine fonksiyona gelen bilgileri koy
	temp->isim 			= isim;
	temp->next			= iter->next;
	iter->next			= temp ;
	return r ;
}

	
node3 * ekle_3(node3 *r , char *isim , int f ){				// Ekle 3 fonksiyonu fatura tutarýna göre sýraayarak yeni link list oluþturur. 
	if(r == NULL){														// Eðer hiç node yoksa , elemanlarý direk ekle
		r = (node3 *)malloc(sizeof(node3));
		r->faturaMiktari 	= f;
		r->isim			 	= isim; 
		r->next 			= NULL;
		
	}
	node3 * iter;
	iter = r;
 	if( r->next == NULL && r->faturaMiktari < f) {						// eðer bir node varsa ve gelen deðer büyükse baþa ekle .
			node3 *temp = (node3 *)malloc(sizeof(node3));
			temp->faturaMiktari = f ;
			temp->isim 			= isim ; 
			
			temp->next 			= r ;
			r = temp;	
			r->next->next =NULL;		
	}	
	
	iter = r ;
	while(iter->next != NULL  &&  iter->next->faturaMiktari >= f  ){	// Eðer node'larýn içindeki sayýlar fonksiyona gelen sayýdan büyükse nodelarda ilerle.
		iter = iter->next;
	}																	// Node'daki deðer küçükse araya eleman ekle						
	//burada iter in önüne kutu ekle
	node3 *temp = (node3 *)malloc(sizeof(node3));
	temp->faturaMiktari	= f;
	temp->isim 			= isim;
	temp->next			= iter->next;
	iter->next			= temp ;
	// !Hata : fonksiyona gönderilen ilk deðeri en baþta sabitliyor.
	return r ;
}

void bastir(node2 *r){				// Sýralanmýþ isim listesinin pointerýný alýr ve ekrana basar.
	node2 * iter = r ; 
	while(iter->next != NULL){
		printf("%s\t\t%d\n",iter->isim , iter->faturaMiktari);
		iter = iter->next;
	}
	
	 iter = r ;
}

int main(){
	node *root ;							// Ekle 1 fonksiyonunun pointerý
	root = (node *)malloc(sizeof(node));
	root->next = NULL;
	
	node * root2;							// Ekle 2 fonksiyonunun pointerý
	root2 = NULL; 
	
	node3 * root3;							// Ekle 3 fonksiyonunun pointerý
	root3 = NULL;
	
	//ekle 3 ve yazdirTutar fonksiyonlarý				// ekle 1 ve bastýr fonksiyonu
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
			
	printf("\tOrjinal link list.\n\n");         				bastir(root);	// Orjinal link listi bastýrýr.	 			
	printf("\n\tFaturalari siralanmis link list\n\n"); 			bastir(root3);	// Faturalarý sýralanmýþ link listi bastýrýr.
	int bulTutar = 600;
	printf("\n\t%d ve ustunde faturalar\n\n",bulTutar);				yazdirTutar(root3 , bulTutar);	// Ýstenen fatura deðerindeki faturalarý bastýrýr.
	
	// ekle 2 fonksiyonu ve yazdirAd fonksiyonlarý ; 
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
	
	printf("\n\tIsme gore siralanmis link list\n\n");								bastir(root2);	// fonksiyon isimleri sýralý bir þekilde bastýrýr.
	char bulHarf= 'A';
	printf("\n\tIsmi %c harfi ile baslayanlar\n\n",bulHarf);						yazdirAd(root2 , bulHarf );	// istenen harfte faturalarý bastýrýr.
	
	return 0;
}
