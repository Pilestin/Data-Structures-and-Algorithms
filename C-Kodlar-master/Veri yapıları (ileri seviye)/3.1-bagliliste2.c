#include<stdio.h>
#include<stdlib.h>
/*			Konular

* 3. uygulamanýn aynýsý
* Tek fark verileri kullanýcý girmekte
	
*/
struct n {
	int data;
	struct n * next;
};	
typedef struct n node;										// n struct'ýndan node isminde deðiþken tanýmladýk.

//-----Hücre ekleme foksiyonumuz-----//

void ekle(node *r , int x){									// Bir pointer bir de eklenecek sayýyý alýyor.
	while(r->next != NULL){									// Eklemek için son hücreye gitmeli ve orada kalmalýyýz. 
			r = r->next;									// O yüzden döngü sadece bizi son hücreye götürecek.
	}	
	r->next = (node * )malloc(sizeof(node));				// Son hücreden bir sonrasýnda yeni hücre oluþturduk.
	r->next->data = x;										// Oluþturduðumuz hücrenin datasýna , gelen x deðerini koyduk.
	r->next -> next = NULL;									// Hata oluþmamasý ve tekrar kullaným için sonraki(boþluk) deðere NULL deðeri atadýk.	

}
//-----Hücreleri okuma fonksiyonumuz-----//

void bastir(node *r){										// Sadece pointer alacak
	int i = 1;
	while(r != NULL){										// Pointer NULL deðilse döngü baþlayacak.
		printf("%d. eleman : %d\n", i , r->data);			// Gezerken hücrelerin deðerlerini basacak
		r  = r -> next;										// Ardýndan bir sonraki hücreye geçicek. Ve döngü tekrarlanacak.
		i ++;	
	}
}

int main(){
	int i = 1;
	int deger = 0;
	node * root;
	root = (node* )malloc(sizeof (node));
	root -> next = NULL;
	root -> data = 100;
	
	for(i = 1 ; i<=10;i++){
		printf("%d. elemani giriniz : ",i);
		scanf("%d",&deger);
		ekle( root , deger);
	}
	bastir(root);
	
	
}
