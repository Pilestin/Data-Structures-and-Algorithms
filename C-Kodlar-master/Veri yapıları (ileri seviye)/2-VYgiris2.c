#include<stdio.h>
#include<stdlib.h>
/*			Konular

* Struck ile bellekte alan olu�turma
* Olu�an alanlardaki verileri d�ng� ile yazd�rma
	
*/
struct n{
	int data;
	
	struct n * next;
};

typedef struct n node;

int main(){
	
	node * root;									// BURAYA 				/-------------------K�saca---------------------------/
	root = malloc(sizeof(node));					// KADAR				+ root ve iter ad�na pointer lar�m�z var.
	root -> data = 10;								// B�R  				+ root bellekteki ilk kutumuzu tutuyor.
	root -> next = (node *)malloc(sizeof(node));	// �NCEK�				+ bu ilk kutunun i�inde 10 de�eri var(bkz. 16.sat�r)
	root -> next -> data = 20;						// PROGRAMIN			+ iter de �u anda ilk kutuyu tutuyor(bkz: 20.sat�r)												
	node * iter;									// AYNISI				+ bellekteki ikinci kutuda ise 20 de�eri var.(bkz. 18.sat�r)
	iter = root;									// ...					
	
	// Madem d�ng�ler diye bir�ey ��rendik o zaman de�erleri iter -> next yada root->next->next diye uzatarak yapmak sa�mal�k.
	// Bir d�ng� yazarak t�m h�crelerdeki de�erleri okuyabiliriz.
	// Fakat d�ng�y� nerede sonland�raca��z ya da ka� h�cre oldu�unu nas�l bilece�iz.
	
	// ��te burada devreye NULL ifadesi devreye giriyor.
	// Bellekteki olu�turulan h�creler de�i�ken ve pointer k�sm�ndan olu�uyor.(data - next ) Ayr�ca her h�credeki pointer bir sonraki h�creyi g�steriyor.
	// Fakat olu�turulan son h�credeki pointer bo�lu�u yani NULL de�erini g�steriyor.
	// ��te bu ifadeden yararlanarak d�ng� olu�turabilir.
					
	root->next->next = NULL;	// Son olu�turdu�umuz kutunun sonras�na NULL de�eri	atamal�y�z. Yoksa hata verir.
					
	int i = 1;
	while(iter != NULL){									// E�er d�ng�de iter dersek son kald���m�z kutu NULL olacakt�r.
		printf("%d. eleman : %d\n", i , iter->data);		// Fakat iter->next dersek son kald���m�z kutu NULL'dan �nceki kutu olacakt�r.
		iter = iter -> next;								// B�ylece son kutunun arkas�na kutu ekleebiliriz.
		i ++;	
	}
		 
	
	
}
