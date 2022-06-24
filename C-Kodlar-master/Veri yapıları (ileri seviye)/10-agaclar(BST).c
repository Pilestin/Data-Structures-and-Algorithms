#include <stdio.h>
#include <stdlib.h>
/*-----------------Binary Search Tree (BST)------------------

* Normal a�a�tan fark� her atan�n(parent) iki �ocu�u(child) vard�r.
* En �stteki node'a k�k(root) ad� verilir.
* Root'un solundaki node'un verisi roottan k���kt�r.
* Root'un sa��ndaki node'un verisi roottan b�y�kt�r.

		Dola�ma Algoritmalar�
* Prefix - Preorder : K�k ba�tad�r  ( NLR , NRL )

* �nfix  - �norder  : K�k ortadad�r ( RNL , LNR ) (k���kten b�y��e s�ralama - LNR ; b�y�kten k����e s�ralama - RNL )

* Postfix- Postorder: K�k sondad�r  ( LRN , RLN )

*/

struct n{
	int data ;
	struct n *sol;
	struct n *sag;
};
typedef struct n node;

node * ekle(node *agac , int x){
	if(agac == NULL){								// E�er a�ac bo�sa yeni eleman eklenir.
		node *root = (node *)malloc(sizeof(node));
		root->sol = NULL;
		root->sag = NULL;
		root->data = x;
		return root;
	}
	if(agac->data < x){								// E�er a�actaki eleman yeni gelen de�erden k���kse sa� tarafa ekleme yap�lacakt�r.(bkz. BST)
		agac->sag = ekle(agac->sag , x);			// Bunu yaparken rek�rsif �zellikten yaralan�lacak.
		return agac;
	}
	agac->sol = ekle(agac->sol , x)	;				// E�er a�a�taki eleman b�y�kse o zaman yeni gelen de�er a�ac�n soluna eklenecek.(bkz.BST)
	return agac;

}
void bastir(node *agac){		// Bast�rma fonksiyonumuz
	if(agac == NULL)			// E�er a�a� bo�sa bir�ey yapmaz(do�al olarak)
		return;
	bastir(agac->sol);			// Bo� de�ilse �nce solu , sonra node u , ard�ndan sa�� bast�rm���z
	printf("%d" , agac->data);	// Yani infix(LNR) kullanm���z.
	bastir(agac->sag);			// Rek�rsif
}

int bul(node *agac , int arananSayi){
	if(agac == NULL)			// E�er agacta node yoksa arad���m�z eleman yoktur.
		return -1;
	if(agac->data == arananSayi)	// E�er aga�ta arad���m�z eleman varsa 1 d�nd�r.
		return 1;
	if(bul(agac->sag , arananSayi ) == 1 || bul(agac->sol , arananSayi) == 1) // Rek�rsif �zellikten yararlanarak fonksiyonu tekrarlat�yor ve eleman� ar�yoruz.
		return 1;			// E�er eleman bulursak 1 d�nd�r�yoruz.
}

int max(node *agac){
	while(agac->sag != NULL){
		agac = agac->sag ; // En b�y�k eleman�m�z ekleme �eklimize g�re(BST) en sa� ve altta oldu�u i�in d�ng� ile oraya gidiyoruz.
	}
	return agac->data;
}

int main(){
	node *agac = NULL;
	
	agac = ekle(agac , 1);
	agac = ekle(agac , 2);
	agac = ekle(agac , 3);
	agac = ekle(agac , 4);
	agac = ekle(agac , 5);
	agac = ekle(agac , 6);

	bastir(agac);
	printf("\n%d arama sonucu %d \n" , 100 ,bul(agac,3) );
	printf("agactaki en buyuk eleman : %d",max(agac));
	
}








