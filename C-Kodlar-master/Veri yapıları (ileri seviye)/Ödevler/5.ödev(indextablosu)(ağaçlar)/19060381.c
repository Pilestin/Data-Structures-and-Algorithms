#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int index_puan[15][3] = { {0 , 18060311 , 40} , {1 , 20060045 , 50} , {2 , 19061091 , 75} , {3 , 20060134 , 90} , {4 , 20060678 , 40} , {5 , 18061086 , 75} , {6 , 20060032 , 50} , {7 , 20060067 , 60} , {8 , 19060456 , 60} , {9 , 18060245 , 75} , {10 , 20060110 , 40} , {11 , 20060234 , 90} , {12 , 20060141 , 60} , {13 , 20060011 , 50} , {14 , 20060012 , 60}  }; 			
int yazdir_dizisi[15][3]; 
int y=0; 																/*						   1						*/
struct D{																/*						 / 	\						*/	
	int index;															/*						/    \						*/
	int numara;															/*					   2      3						*/	
	int puan;															/*					  /	\	 / \					*/
};																		/*					 4	 5  6   7					*/	
struct m{									// Binary Tree için yapý	/*					/	/		 \					*/										
	int veri;															/*				   8   9		 10					*/		
	struct m *sol;																							
	struct m *sag;																								
};typedef struct m tree;																							
struct n{																																
	struct D data;
	struct n *sol;
	struct n *sag;
};typedef struct n node;

tree *soldanekle(tree *root , int x ){		// Aðaca soldan eleman ekleyen fonksiyon.

		if(root == NULL ){					// Aðaçta eleman yoksa yeni node oluþtur.
			root = (tree *)malloc(sizeof(tree));
			root->sol = NULL;
			root->sag = NULL;
			root->veri = x;
			return root;
		}
		if(root->sol == NULL){				// Agacýn solu boþsa yeni node olustur.
			root->sol = (tree *)malloc(sizeof(tree));
			root->sol->veri = x;
			root->sol->sol  = NULL;
			root->sol->sag  = NULL;
			return root;
		}
		if(root->sol != NULL){				// Agacý solu boþ deðilse yeni nodu araya ekle
			int aradeger = root->sol->veri;
			root->sol->veri = x;
			root->sol = soldanekle(root->sol , aradeger);
			return root;
		}
}

tree *sagdanekle(tree *root , int x){		// Aðaca saðdan eleman ekleyen fonksiyon

		if(root == NULL ){					// Aðaçta eleman yoksa yeni node oluþtur.
			root = (tree *)malloc(sizeof(tree));
			root->veri= x;
			root->sol = NULL;
			root->sag = NULL;
			
			return root;
		}
		if(root->sag == NULL){				// Agacýn saðý boþsa yeni node olustur.
			root->sag = (tree *)malloc(sizeof(tree));
			root->veri = x;
			root->sag->sag  = NULL;
			root->sag->sol  = NULL;
			return root;
		}
		if(root->sag != NULL){				// Agacý saðý boþ deðilse yeni nodu araya ekle
			int aradeger = root->sag->veri;
			root->sag->veri= x;
			root->sag = sagdanekle(root->sag , aradeger);
			return root;
		}
}

void preOrder(tree *root){						// Pre-order DFS kuralýnda node ekrana yazdýran fonksiyon
	if (root == NULL)
		return;
	printf("%d ",root->veri);
	preOrder(root->sol);
	preOrder(root->sag);
}
void inOrder(tree *root){						// Ýn-order DFS kuralýnda node ekrana yazdýran fonksiyon
	if (root == NULL)
		return;
	inOrder(root->sol);
	printf("%d ",root->veri);
	inOrder(root->sag);
	
}
void postOrder(tree *root){						// Post-order DFS kuralýnda node ekrana yazdýran fonksiyon
	if (root == NULL)
		return;
	postOrder(root->sol);
	postOrder(root->sag);
	printf("%d ",root->veri);
}

void bfsYazdir(tree *root , int yukseklik){			// BFS þeklinde yazdýran fonksiyon
	if (root == NULL)
		return;
	if (yukseklik == 1)
		printf("%d ", root->veri);
	else if (yukseklik > 1)
	{
		bfsYazdir(root->sol, yukseklik-1);
		bfsYazdir(root->sag, yukseklik-1);
	}
}
void BFS(tree *root){							// BFS kuralýnda ekrana node yazdýran fonksiyon
	int h = yukseklikBul(root);
	int i;
	for (i=1; i<=h; i++)
		bfsYazdir(root, i);
}

int yukseklikBul(tree *root){					// Aðaç yüksekliðini bulan fonksiyon

	if (root == NULL)
		return 0;
	else{
		int solyukseklik = yukseklikBul(root->sol);
		int sagyukseklik = yukseklikBul(root->sag);
		if (solyukseklik > sagyukseklik)
			return(solyukseklik+1);
		else 
			return(sagyukseklik+1);
	}
}

int notunuBul(int index){						// Verilen indexin puanýný çok boyutlu diziden bulan fonksiyon
	return index_puan[index][2];
}
int numarasiniBul(int index){					// Verilen indexin numarasýný çok boyutlu diziden bulan fonksiyon
	return index_puan[index][1];
}



node *maxBul (node *agac ){						// sil fonksiyonunda silinen node yerine BST'yi korumak için soldaki nodelardan(büyük olaný) birini koymamýz gerek.								
	while(agac->sag != NULL)					// Bu yüzden bu fonksiyonu kullanabiliriz.
		agac = agac->sag;
	return agac ;
}	
node *minBul (node *agac){						// sil fonksiyonunda silinen node yerine BST'yi korumak için sagdaki nodelardan(küçük olaný) birini koymamýz gerek.
	while(agac->sol != NULL)					// Bu yüzden bu fonksiyonu kullanabiliriz.
		agac = agac->sol;
	return agac;
}

node * ekle( node *agac , int index, int numara , int puan){		// Aðaca eleman ekleyen fonksiyon
	if(agac == NULL){							// Eðer aðac boþsa yeni eleman eklenir.
		agac 	   = (node *)malloc(sizeof(node));
		agac->sol  = NULL;	agac->sag    = NULL;	
		agac->data.puan = puan;	agac->data.numara = numara;	agac->data.index = index;
		return agac;
	}
	
	if(agac->data.puan < puan ){				// Eðer aðactaki eleman yeni gelen deðerden küçükse sað tarafa ekleme yapýlacaktýr.
		agac->sag = ekle(agac->sag , index , numara , puan );			
		return agac;
	}
	
	if(agac->data.puan == puan ){				// Eðer puanlar eþitse 
		if(agac->data.numara < numara){			// ve yeni oluþacak nodun numarasý büyükse mevcut node un soluna ekle
			agac->sol = ekle(agac->sol , index , numara , puan);
			return agac;
		}
		// aksi halde mevcut node ile yer deðiþtir ve yeni node un soluna ekle
		int notTutucu = agac->data.puan   ;   int indexTutucu = agac->data.index   ;   int numaraTutucu = agac->data.numara   ; 
		agac->data.puan = puan ; agac->data.index = index ; agac->data.numara = numara ;
		agac->sol = ekle(agac->sol , indexTutucu , numaraTutucu , notTutucu );
		return agac;
			
	}
	
	agac->sol = ekle(agac->sol , index , numara , puan)	;	// Eðer aðaçtaki eleman büyükse o zaman yeni gelen deðer aðacýn soluna eklenecek.
	return agac;	
}

node * sil (node *agac , int i){		
	
	int indeksinNotu = index_puan[i][2];
	
	if( i < 0 || i > 15 ){	
		printf("\n\nHatalý index girdiniz.\n"); 
		return  ;
	}

	if ( agac == NULL )							// agaçta eleman yoksa hiçbirþey yapma.
			return ;
	
	if ( agac->data.index == i){				// Aradýðýmýz deðeri aðaçta bulduysak;
		
			if (agac->sol == NULL && agac->sag == NULL) // ve altýnda node yoksa NULL döndür.
				return NULL;
			if (agac->sag != NULL){						// Eðer agacýn saðýnda node varsa saðdaki en küçük eleman silinen node yerine geçebilir.(BST gereði)
				agac->data.puan   = minBul(agac->sag)->data.puan ;
				agac->data.numara = minBul(agac->sag)->data.numara;
				agac->data.index  = minBul(agac->sag)->data.index;
				agac->sag    = sil(  agac->sag , minBul(agac->sag)->data.index  );
				return agac;
			}											// aksi halde soldaki en büyük eleman node yerine geçebilir.
			agac->data.puan   = maxBul(agac->sol)->data.puan;
			agac->data.numara = maxBul(agac->sol)->data.numara;
			agac->data.index  = maxBul(agac->sol)->data.index;
			agac->sol    = sil( agac->sol , maxBul(agac->sol)->data.index );
			return agac;
	}
	if ( agac->data.puan < indeksinNotu ){				// Eðer aðacýn puaný , yeni gelen puandan küçükse aramaya sað taraftan devam etmeliyiz. 
			agac->sag = sil(agac->sag , i );
			return agac;
	}
	agac->sol = sil(agac->sol , i );					// Eðer aðacýn puaný , yeni gelen puandan büyükse aramaya sol taraftan devam etmeliyiz.
	return agac;

}

node * degistir (node *agac , int index , int yeniNot){
	printf("%d.indisdeki ogrencinin  notu : %d\n", index_puan[index][0] , index_puan[index][2] );
	agac = sil (agac , index );										// Girilen indexi sil fonksiyonuna verip , o indisli node u siler.
	agac = ekle(agac , index , index_puan[index][1] , yeniNot );	// Girilen güncel not deðerini yeni bir node eklermiþ gibi, ekle fonksiyonuna göndererek, girer.
	index_puan[index][2] = yeniNot;
	printf("%d.indisdeki ogrencinin yeni notu : %d\n", index_puan[index][0] , index_puan[index][2] );
}

void yazdir( node *agac , int puan ){
	
	if(agac == NULL){
		return;
	}
	if(agac != NULL  &&  agac->data.puan >= puan ){
		yazdir_dizisi[y][0] = agac->data.index;
		yazdir_dizisi[y][1] = agac->data.numara;
		yazdir_dizisi[y][2] = agac->data.puan;
		y++;
		yazdir(agac->sol , puan);
		yazdir(agac->sag , puan);
		return;
	}
	else{
		yazdir(agac->sag , puan);
		return;
	}
	
}

void sirala(){
	int i ,  k ,  aradeger   ;
	
	for(i = 0 ; i < 15 ; i++){
			for(k = 0 ; k < 14 ; k++){
				if (yazdir_dizisi[k][0] > yazdir_dizisi[k+1][0]){    
            		// Not deðiþimi
	            	aradeger = yazdir_dizisi[k+1][2] ;
    	        	yazdir_dizisi[k+1][2] = yazdir_dizisi[k][2] ;
        	    	yazdir_dizisi[k][2] = aradeger ;
            		// Öðrenci numarasý deðiþimi
           			aradeger = yazdir_dizisi[k+1][1];
	            	yazdir_dizisi[k+1][1] = yazdir_dizisi[k][1];
    	        	yazdir_dizisi[k][1] = aradeger ;
        	    	// Ýndex deðiþimi
            		aradeger = yazdir_dizisi[k+1][0];
            		yazdir_dizisi[k+1][0] = yazdir_dizisi[k][0];
	            	yazdir_dizisi[k][0] = aradeger ;			
				}
			}
	}
	for(i = 0 ; i<15 ; i++){
			if(yazdir_dizisi[i][1] == 0)	// Dizide elemanlarý bastýrmak için
				continue;
		
			printf("%d\t%d\t%d\n",yazdir_dizisi[i][0] , yazdir_dizisi[i][1] , yazdir_dizisi[i][2]);
	}		
}

void bastir(node *agac){		// Ýnorder dfs þeklinde bastýrýr.
	if(agac!= NULL){
		
		bastir(agac->sol);
		printf("\n%d\t%d\t%d",agac->data.index , agac->data.numara , agac->data.puan);
		bastir(agac->sag);
	}
}

int main (){
	node *indAgaci = NULL;																indAgaci = ekle(indAgaci , 0 , 18060311 , 40);
	tree *bintree = NULL;																indAgaci = ekle(indAgaci , 1 , 20060045 , 50);
																						indAgaci = ekle(indAgaci , 2 , 19061091 , 75);
																						indAgaci = ekle(indAgaci , 3 , 20060134 , 90);
																						indAgaci = ekle(indAgaci , 4 , 20060678 , 40);
	bintree = soldanekle(bintree , 1);													indAgaci = ekle(indAgaci , 5 , 18061086 , 75);
	bintree = soldanekle(bintree , 2);													indAgaci = ekle(indAgaci , 6 , 20060032 , 50);					
	bintree->sag = sagdanekle(bintree->sag , 3);										indAgaci = ekle(indAgaci , 7 , 20060067 , 60);				
	bintree->sol->sol = soldanekle(bintree->sol->sol , 4);								indAgaci = ekle(indAgaci , 8 , 19060456 , 60);
	bintree->sol->sag = sagdanekle(bintree->sol->sag , 5);								indAgaci = ekle(indAgaci , 9 , 18060245 , 75);									
	bintree->sag->sol = soldanekle(bintree->sag->sol , 6);								indAgaci = ekle(indAgaci , 10 , 20060110 , 40);									
	bintree->sag->sag = sagdanekle(bintree->sag->sag , 7);								indAgaci = ekle(indAgaci , 11 , 20060234 , 90);									
	bintree->sol->sol = soldanekle(bintree->sol->sol , 8);								indAgaci = ekle(indAgaci , 12 , 20060141 , 60);									
	bintree->sol->sag->sol = soldanekle(bintree->sol->sag->sol , 9);					indAgaci = ekle(indAgaci , 13 , 20060011 , 50);								
	bintree->sag->sag->sag = sagdanekle(bintree->sag->sag->sag ,10);					indAgaci = ekle(indAgaci , 14 , 20060012 , 60);											
																			
	printf("BFS: ");			BFS(bintree);			printf("\n");
	
	printf("preOrder: ");		preOrder(bintree);		printf("\n");
	
	printf("inOrder:");			inOrder(bintree);		printf("\n");
	
	printf("postOrder:");		postOrder(bintree);		printf("\n");
	
	
	sil(indAgaci , 5);
	degistir(indAgaci , 0 , 99);
	sil(indAgaci , 9);
	degistir(indAgaci , 10 , 100);
	degistir(indAgaci ,  2 ,   50);
	yazdir(indAgaci , 0);
	sirala();
	
}





















