#include<stdio.h>
#include<stdlib.h>

// Stack (y���n) kodlamas� , struct ile yap�l���.
// LIFO :(last in first out) Son giren ilk ��kar.

struct n {
	int data;
	struct n * next;
};
typedef struct n node;

node* ekle(node *r , int sayi){				// Yeni gelen elemanlar� ba�a gelecek �ekilde ekleyen fonksiyon.
	if(r == NULL){		// Null ise direk kutu ekle
		r = (node *)malloc(sizeof(node));
		r->data = sayi;
		r ->next = NULL;
		return r;
	}
	else{			// Aksi halde yeni bir kutu olu�tur. Bu kutunun next'ini roota koy . Yani en ba�a eleman ekledik.
		node * temp = (node *)malloc(sizeof(node));
		temp->data = sayi;
		temp->next = r ;
		r = temp;
		return r;
	}
	
}

node * sil(node *r){
	node *iter = r;
	if( r->next == NULL ){		// E�er bir tane kutu varsa direk free diyerek sil.
		free(r);
		r = NULL;	
	}
	r = iter->next;				// Ba�taki eleman� tutan rootu bir sa�a kayd�r ve ba�taki o eleman� free diyerek sil.
	free(iter);					// B�ylece ba�taki o eleman silinmi� oldu. ( Ba�taki eleman asl�nda en son gelen kutuydu. L�FO)
	return r ; 
}
void bastir(node *r){			// Normal bir �ekilde kutular�n data'larn� bast�ran fonksiyon.
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
