#include<stdio.h>
#include<stdlib.h>
/*			Konular

* 3. uygulaman�n ayn�s�
* Tek fark verileri kullan�c� girmekte
	
*/
struct n {
	int data;
	struct n * next;
};	
typedef struct n node;										// n struct'�ndan node isminde de�i�ken tan�mlad�k.

//-----H�cre ekleme foksiyonumuz-----//

void ekle(node *r , int x){									// Bir pointer bir de eklenecek say�y� al�yor.
	while(r->next != NULL){									// Eklemek i�in son h�creye gitmeli ve orada kalmal�y�z. 
			r = r->next;									// O y�zden d�ng� sadece bizi son h�creye g�t�recek.
	}	
	r->next = (node * )malloc(sizeof(node));				// Son h�creden bir sonras�nda yeni h�cre olu�turduk.
	r->next->data = x;										// Olu�turdu�umuz h�crenin datas�na , gelen x de�erini koyduk.
	r->next -> next = NULL;									// Hata olu�mamas� ve tekrar kullan�m i�in sonraki(bo�luk) de�ere NULL de�eri atad�k.	

}
//-----H�creleri okuma fonksiyonumuz-----//

void bastir(node *r){										// Sadece pointer alacak
	int i = 1;
	while(r != NULL){										// Pointer NULL de�ilse d�ng� ba�layacak.
		printf("%d. eleman : %d\n", i , r->data);			// Gezerken h�crelerin de�erlerini basacak
		r  = r -> next;										// Ard�ndan bir sonraki h�creye ge�icek. Ve d�ng� tekrarlanacak.
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
