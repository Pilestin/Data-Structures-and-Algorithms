#include<stdio.h>
#include<stdlib.h>
/*

* Baðlý listelerde elemanlarý sýralý ekleme

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

void ekle(node* r , int x){	
	while(r->next != NULL){
		r = r -> next;
	}
	r -> next = (node *)malloc(sizeof(node));
	r -> data = x;
	r -> next -> next = NULL;						// Burasý çokomelli.
}
// Buraya kadar ayný.


node * siraliekle(node * r , int x){
	if (r == NULL){
		r = (node *)malloc(sizeof(node));
		r -> next = NULL;
		r -> data = x ;
	}
	else if(r-> next == NULL){
		if(r->data < x){
			node * temp = (node*)malloc(sizeof(node));
			temp -> data = x;
			temp -> next = r ;
			r = temp;
			return r ;
			
		}
	}
}
int main(){
	node * root ;
	root = (node *)malloc(sizeof(node));
	root = NULL;
	siraliekle( root , 10 );
	siraliekle( root , 20 );
	siraliekle( root , 30 );
	printf("%d",root-> data);
	bastir(root);
}


