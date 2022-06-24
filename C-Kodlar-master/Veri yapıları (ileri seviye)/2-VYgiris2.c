#include<stdio.h>
#include<stdlib.h>
/*			Konular

* Struck ile bellekte alan oluþturma
* Oluþan alanlardaki verileri döngü ile yazdýrma
	
*/
struct n{
	int data;
	
	struct n * next;
};

typedef struct n node;

int main(){
	
	node * root;									// BURAYA 				/-------------------Kýsaca---------------------------/
	root = malloc(sizeof(node));					// KADAR				+ root ve iter adýna pointer larýmýz var.
	root -> data = 10;								// BÝR  				+ root bellekteki ilk kutumuzu tutuyor.
	root -> next = (node *)malloc(sizeof(node));	// ÖNCEKÝ				+ bu ilk kutunun içinde 10 deðeri var(bkz. 16.satýr)
	root -> next -> data = 20;						// PROGRAMIN			+ iter de þu anda ilk kutuyu tutuyor(bkz: 20.satýr)												
	node * iter;									// AYNISI				+ bellekteki ikinci kutuda ise 20 deðeri var.(bkz. 18.satýr)
	iter = root;									// ...					
	
	// Madem döngüler diye birþey öðrendik o zaman deðerleri iter -> next yada root->next->next diye uzatarak yapmak saçmalýk.
	// Bir döngü yazarak tüm hücrelerdeki deðerleri okuyabiliriz.
	// Fakat döngüyü nerede sonlandýracaðýz ya da kaç hücre olduðunu nasýl bileceðiz.
	
	// Ýþte burada devreye NULL ifadesi devreye giriyor.
	// Bellekteki oluþturulan hücreler deðiþken ve pointer kýsmýndan oluþuyor.(data - next ) Ayrýca her hücredeki pointer bir sonraki hücreyi gösteriyor.
	// Fakat oluþturulan son hücredeki pointer boþluðu yani NULL deðerini gösteriyor.
	// Ýþte bu ifadeden yararlanarak döngü oluþturabilir.
					
	root->next->next = NULL;	// Son oluþturduðumuz kutunun sonrasýna NULL deðeri	atamalýyýz. Yoksa hata verir.
					
	int i = 1;
	while(iter != NULL){									// Eðer döngüde iter dersek son kaldýðýmýz kutu NULL olacaktýr.
		printf("%d. eleman : %d\n", i , iter->data);		// Fakat iter->next dersek son kaldýðýmýz kutu NULL'dan önceki kutu olacaktýr.
		iter = iter -> next;								// Böylece son kutunun arkasýna kutu ekleebiliriz.
		i ++;	
	}
		 
	
	
}
