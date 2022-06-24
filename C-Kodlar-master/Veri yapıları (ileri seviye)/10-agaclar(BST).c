#include <stdio.h>
#include <stdlib.h>
/*-----------------Binary Search Tree (BST)------------------

* Normal aðaçtan farký her atanýn(parent) iki çocuðu(child) vardýr.
* En üstteki node'a kök(root) adý verilir.
* Root'un solundaki node'un verisi roottan küçüktür.
* Root'un saðýndaki node'un verisi roottan büyüktür.

		Dolaþma Algoritmalarý
* Prefix - Preorder : Kök baþtadýr  ( NLR , NRL )

* Ýnfix  - Ýnorder  : Kök ortadadýr ( RNL , LNR ) (küçükten büyüðe sýralama - LNR ; büyükten küçüðe sýralama - RNL )

* Postfix- Postorder: Kök sondadýr  ( LRN , RLN )

*/

struct n{
	int data ;
	struct n *sol;
	struct n *sag;
};
typedef struct n node;

node * ekle(node *agac , int x){
	if(agac == NULL){								// Eðer aðac boþsa yeni eleman eklenir.
		node *root = (node *)malloc(sizeof(node));
		root->sol = NULL;
		root->sag = NULL;
		root->data = x;
		return root;
	}
	if(agac->data < x){								// Eðer aðactaki eleman yeni gelen deðerden küçükse sað tarafa ekleme yapýlacaktýr.(bkz. BST)
		agac->sag = ekle(agac->sag , x);			// Bunu yaparken rekürsif özellikten yaralanýlacak.
		return agac;
	}
	agac->sol = ekle(agac->sol , x)	;				// Eðer aðaçtaki eleman büyükse o zaman yeni gelen deðer aðacýn soluna eklenecek.(bkz.BST)
	return agac;

}
void bastir(node *agac){		// Bastýrma fonksiyonumuz
	if(agac == NULL)			// Eðer aðaç boþsa birþey yapmaz(doðal olarak)
		return;
	bastir(agac->sol);			// Boþ deðilse önce solu , sonra node u , ardýndan saðý bastýrmýþýz
	printf("%d" , agac->data);	// Yani infix(LNR) kullanmýþýz.
	bastir(agac->sag);			// Rekürsif
}

int bul(node *agac , int arananSayi){
	if(agac == NULL)			// Eðer agacta node yoksa aradýðýmýz eleman yoktur.
		return -1;
	if(agac->data == arananSayi)	// Eðer agaçta aradýðýmýz eleman varsa 1 döndür.
		return 1;
	if(bul(agac->sag , arananSayi ) == 1 || bul(agac->sol , arananSayi) == 1) // Rekürsif özellikten yararlanarak fonksiyonu tekrarlatýyor ve elemaný arýyoruz.
		return 1;			// Eðer eleman bulursak 1 döndürüyoruz.
}

int max(node *agac){
	while(agac->sag != NULL){
		agac = agac->sag ; // En büyük elemanýmýz ekleme þeklimize göre(BST) en sað ve altta olduðu için döngü ile oraya gidiyoruz.
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








