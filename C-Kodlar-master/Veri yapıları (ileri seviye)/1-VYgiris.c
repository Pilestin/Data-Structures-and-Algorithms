#include<stdio.h>
#include<stdlib.h>
/*			Konular

* Struck ile yeni veri türü yaratıp ,  bellekte alan oluşturma
	
*/
struct n{
	int data ;
	struct n * next;
};


typedef struct n node; 	// n tipinden node isminde değişken oluşturdu.


int main(){
	
	node *root;	// Bizim için ilk verinin(bellekteki kutu da diyebiliriz.) yerini tutacak "node" tipinde bir pointer tanımladık. Fakat farklı kutular arasında gezinmek için başka bir göstericiye ihtiyacımız var.
	root = (node *)malloc(sizeof(node)); 	// Bize root'un gösterdiği yerde bir adet node tipinde yer ayırdı.
	root -> data = 10;						// Ayırdığı yere 10 değerini koydu.
	root -> next = (node *)malloc(sizeof(node)); 	// Root'un gösterdiği yerden bir sonraki kutuya node tipinde bir yer ayırdı.
	root -> next -> data = 20;						// Ayrıdığı yere 20 değerini koydu.
	node *iter;				    // En üstte söylediğimiz göstericiyi burada tanımladık. 
	iter = root;				// Gösterici ilk olarak root'un gösterdiği yer olan ilk kutuyu gösteriyor.
	printf("%d\n",iter->data);			// 10
	iter = iter -> next;			// Root'un gösterdiği kutudan bir sonraki kutuyu gösterir
	printf("%d\n",iter->data);			// 20
	iter = root ;					// Şimdi tekrar ilk kutuyu gösterir.
	
	// Özetlersek bellekte iki adet kutumuz , iki adet pointer'ımız ve kutularda 10 ve 20 değerleri var.
	// root pointer'ı ilk kutuyu gösterir. // iter pointer'ı ise herhangi bir kutuyu gösterebilir.(Şu anda ilk kutuyu gösteriyor.) 
}
