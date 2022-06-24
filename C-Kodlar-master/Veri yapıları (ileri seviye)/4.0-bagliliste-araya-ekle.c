#include<stdio.h>
#include<stdlib.h>
/*

* Ba�l� listelerde araya eleman ekleme 

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
void ekle(node* r , int x){			// Bildi�imiz sona eleman ekleme fonksiyonu
	while(r->next != NULL){
		r = r -> next;
	}
	r -> next = (node *)malloc(sizeof(node));
	r -> data = x;
	r -> next -> next = NULL;
}
void araya_ekle(node* r , int x){	// Belirli bir ko�ula g�re araya eleman ekleyecek fonksiyon
	while(r->next->data < x ){			// Kutudaki de�erler fonksiyona verilen say�dan k���k oldu�u s�rece sonraki kutuya gidecek.
		r = r ->next;					// Kutuda daha b�y�k say� bulduktan sonra d�ng�den ��kacak.
	}
	node * tutucu = (node *)malloc(sizeof(node));	// Yeni bir pointer olu�turacak(ram da farkl� bir yerde) ve pointer�n oldu�u yerde node tipinde bir kutu olu�turacak
	tutucu -> data = x ;							// Bu kutuya fonksiyona gelen say�y� ekleyecek. 
	tutucu -> next = r -> next ;					// Kutunun next'ini b�y�k say�l� olan kutuyu g�sterecek �ekilde ayarlad�k.
	r -> next = tutucu;								// �imdi durdu�umuz yerdeki kutuyu da bu tutucu kutusuna ba�lay�p zinciri olu�turmu� olacak.

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
