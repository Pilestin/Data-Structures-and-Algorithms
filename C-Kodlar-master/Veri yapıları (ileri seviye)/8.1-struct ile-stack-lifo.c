#include<stdio.h>
#include<stdlib.h>

// Stack (yýðýn) kodlamasý , struct ile yapýlýþý.
// LIFO :(last in first out) Son giren ilk çýkar.

struct n {
	int data;
	struct n * next;
};
typedef struct n node;

node* ekle(node *r , int sayi){				// Yeni gelen elemanlarý baþa gelecek þekilde ekleyen fonksiyon.
	if(r == NULL){		// Null ise direk kutu ekle
		r = (node *)malloc(sizeof(node));
		r->data = sayi;
		r ->next = NULL;
		return r;
	}
	else{			// Aksi halde yeni bir kutu oluþtur. Bu kutunun next'ini roota koy . Yani en baþa eleman ekledik.
		node * temp = (node *)malloc(sizeof(node));
		temp->data = sayi;
		temp->next = r ;
		r = temp;
		return r;
	}
	
}

node * sil(node *r){
	node *iter = r;
	if( r->next == NULL ){		// Eðer bir tane kutu varsa direk free diyerek sil.
		free(r);
		r = NULL;	
	}
	r = iter->next;				// Baþtaki elemaný tutan rootu bir saða kaydýr ve baþtaki o elemaný free diyerek sil.
	free(iter);					// Böylece baþtaki o eleman silinmiþ oldu. ( Baþtaki eleman aslýnda en son gelen kutuydu. LÝFO)
	return r ; 
}
void bastir(node *r){			// Normal bir þekilde kutularýn data'larný bastýran fonksiyon.
	node *iter = r;
	if(iter == NULL){
		printf(" eleman yok ki ");
	}
	while(iter != NULL){
		printf("%d ",iter->data);
		iter = iter->next;
	}

}
int main(){
	node *root = NULL;
	root = ekle(root , 5);		bastir(root);		printf("\n");
	root = ekle(root , 10);		bastir(root);		printf("\n");
	root = ekle(root , 15);		bastir(root);		printf("\n");
	root = ekle(root , 20);		bastir(root);		printf("\n");
	
	bastir(root);

	printf("\n");
	root = sil(root);
	bastir(root);
	
	printf("\n");
	root = sil(root);
	bastir(root);
	
	printf("\n");
	root = sil(root);
	bastir(root);
	
	printf("\n");
	root = sil(root);
	
	
	printf("\n Yeni root:");
	bastir(root);
	root = ekle(root , 25);root = ekle(root , 30);
	root = ekle(root , 35);root = ekle(root , 40);
	printf("\n Yeni root:");
	bastir(root);
	

	
}
