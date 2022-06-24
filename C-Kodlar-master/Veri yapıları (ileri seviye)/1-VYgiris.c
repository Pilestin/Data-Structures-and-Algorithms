#include<stdio.h>
#include<stdlib.h>
/*			Konular

* Struck ile yeni veri t�r� yarat�p ,  bellekte alan olu�turma
	
*/
struct n{
	int data ;
	struct n * next;
};


typedef struct n node; 	// n tipinden node isminde de�i�ken olu�turdu.


int main(){
	
	node *root;	// Bizim i�in ilk verinin(bellekteki kutu da diyebiliriz.) yerini tutacak "node" tipinde bir pointer tan�mlad�k. Fakat farkl� kutular aras�nda gezinmek i�in ba�ka bir g�stericiye ihtiyac�m�z var.
	root = (node *)malloc(sizeof(node)); 	// Bize root'un g�sterdi�i yerde bir adet node tipinde yer ay�rd�.
	root -> data = 10;						// Ay�rd��� yere 10 de�erini koydu.
	root -> next = (node *)malloc(sizeof(node)); 	// Root'un g�sterdi�i yerden bir sonraki kutuya node tipinde bir yer ay�rd�.
	root -> next -> data = 20;						// Ayr�d��� yere 20 de�erini koydu.
	node *iter;				    // En �stte s�yledi�imiz g�stericiyi burada tan�mlad�k. 
	iter = root;				// G�sterici ilk olarak root'un g�sterdi�i yer olan ilk kutuyu g�steriyor.
	printf("%d\n",iter->data);			// 10
	iter = iter -> next;			// Root'un g�sterdi�i kutudan bir sonraki kutuyu g�sterir
	printf("%d\n",iter->data);			// 20
	iter = root ;					// �imdi tekrar ilk kutuyu g�sterir.
	
	// �zetlersek bellekte iki adet kutumuz , iki adet pointer'�m�z ve kutularda 10 ve 20 de�erleri var.
	// root pointer'� ilk kutuyu g�sterir. // iter pointer'� ise herhangi bir kutuyu g�sterebilir.(�u anda ilk kutuyu g�steriyor.) 
}
