#include<stdio.h>
#include<stdlib.h>
/*

* Baðlý listelerde araya eleman ekleme 

*/
struct n{
	int data ;
	struct n *next ;
};
typedef struct n node;

void bastir(node *r ){
	int i = 0;
	while( r->next != NULL){
		printf("%d.\t%d\n",i+1, r->data);
		r = r -> next;
		i++;
	}
}
void ekle(node* r , int x){			// Bildiðimiz sona eleman ekleme fonksiyonu
	while(r->next != NULL){
		r = r -> next;
	}
	r -> next = (node *)malloc(sizeof(node));
	r -> data = x;
	r -> next -> next = NULL;
}
void araya_ekle(node* r , int x){	// Belirli bir koþula göre araya eleman ekleyecek fonksiyon
	while(r->next->data < x ){			// Kutudaki deðerler fonksiyona verilen sayýdan küçük olduðu sürece sonraki kutuya gidecek.
		r = r ->next;					// Kutuda daha büyük sayý bulduktan sonra döngüden çýkacak.
	}
	node * tutucu = (node *)malloc(sizeof(node));	// Yeni bir pointer oluþturacak(ram da farklý bir yerde) ve pointerýn olduðu yerde node tipinde bir kutu oluþturacak
	tutucu -> data = x ;							// Bu kutuya fonksiyona gelen sayýyý ekleyecek. 
	tutucu -> next = r -> next ;					// Kutunun next'ini büyük sayýlý olan kutuyu gösterecek þekilde ayarladýk.
	r -> next = tutucu;								// Þimdi durduðumuz yerdeki kutuyu da bu tutucu kutusuna baðlayýp zinciri oluþturmuþ olacak.

}
int main(){
	node *root;
	root = (node*)malloc(sizeof(node));
	root -> next = NULL;
	ekle(root , 10);
	ekle(root , 20);
	ekle(root , 30);
	araya_ekle(root , 25);
	bastir(root);
}
