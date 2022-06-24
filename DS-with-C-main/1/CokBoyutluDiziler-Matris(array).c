#include<stdio.h>
int tablo[15][3] ={	{0 , 18060311 , 40},		// Ekle fonksiyonu çalýþtýrmadan sil ve yazdýr gibi fonksiyonlarý çalýþtýrabilmek için önceden tanýmlý dizimiz.
					{1 , 20060045 , 50},
    				{2 , 19061091 , 75},
    				{3 , 20060134 , 90},
   					{4 , 20060678 , 40},
    				{5 , 18061086 , 75},
    				{6 , 20060032 , 50},
    				{7 , 20060067 , 60},
    				{8 , 19060456 , 60},
    				{9 , 18060245 , 75},
    				{10 , 20060110 , 40},
    				{11 , 20060234 , 90},
    				{12 , 20060141 , 60},
    				{13 , 20060011 , 50},
    				{14 , 20060012 , 60}
};
int yenitablo[15][3]; 		// Ekle fonksiyonuna gelen deðerler sýralandýktan sonra oluþacak deðerleri tutan dizi.
	
void ekrana_yazdir(){
	int i = 0;
	printf("\n--------Yeni tablo------------\n");
	printf("Indis:\tNumarasi:\tNotu:\n\n");
	for(i;i<15;i++){
		printf("%d\t%d\t%d\n",tablo[i][0] , tablo[i][1] , tablo[i][2]);
	}
	printf("______________________________\n");
}

int sirala(int tablo[15][3]){			
	int i = 0;
	int k = 0;
	int aradeger = 0;
	for(i ; i < 15 ; i++){			
		k = 0;
		for(k;k<14;k++){
			if (tablo[k][2] < tablo[k+1][2]){    // Ders notuna göre sýralama
            	// Not deðiþimi
            	aradeger = tablo[k+1][2] ;
            	tablo[k+1][2] = tablo[k][2] ;
            	tablo[k][2] = aradeger ;
            	// Öðrenci numarasý deðiþimi
           		aradeger = tablo[k+1][1];
            	tablo[k+1][1] = tablo[k][1];
            	tablo[k][1] = aradeger ;
            	// Ýndex deðiþimi
            	aradeger = tablo[k+1][0];
            	tablo[k+1][0] = tablo[k][0];
            	tablo[k][0] = aradeger ;			
			}
        	else if ((tablo[k][2] == tablo[k+1][2]) & (tablo[k][1] > tablo[k+1][1]) ){    // Ders notlarý eþitse öðrenci numarasýna göre sýralama
            		// Öðrenci numarasý deðiþimi
                	aradeger = tablo[k+1][1];
                	tablo[k+1][1] = tablo[k][1];
                	tablo[k][1] = aradeger;
                	// Ýndex deðiþimi
                	aradeger = tablo[k+1][0];
                	tablo[k+1][0] = tablo[k][0];
                	tablo[k][0] = aradeger;
				}
			}
		}	
}

int ekle(int ogr_no , int puan , int index){ 
	int i = 0 , k  ;
	for(i ; i<15 ; i++){
		if( puan > yenitablo[i][2] ){					// Eðer yeni eklenen puan tablodakinden(þu an 0) büyükse döngü baþlar. 
			for( k = 14 ; k>i ; k-- ){					// En alttan baþlayarak her satýrý bir aþaðýya kaydýrýr. Ta ki , yeni gelen puan deðerinin büyük olduðu satýr aþaðý inene kadar.
				yenitablo[k][0] = yenitablo[k-1][0];
				yenitablo[k][1] = yenitablo[k-1][1];
				yenitablo[k][2] = yenitablo[k-1][2];
			}
			yenitablo[i][0] = index;					// Satýrlar aþaðý indiðinde oluþan boþ satýra  , fonksiyona gelen deðerler yerleþir.
			yenitablo[i][1] = ogr_no;
			yenitablo[i][2] = puan ; 
			break;
		}
		else if( (puan == yenitablo[i][2]) & (ogr_no < yenitablo[i][1] )){	// Üstteki algoritmanýn aynýsýný yapar.
			for(k = 14; k>i ; k--){
				yenitablo[k][0] = yenitablo[k-1][0];
				yenitablo[k][1] = yenitablo[k-1][1];
				yenitablo[k][2] = yenitablo[k-1][2];
			}
			yenitablo[i][0] = index;
			yenitablo[i][1] = ogr_no;
			yenitablo[i][2] = puan ; 
			break;
		}
	}
}
	
int sil(int tablo[15][3], int index){
	int i = 0 , k;
	for(i = 0 ; i<15 ; i++){										// Silinecek öðrencinin tabloda hangi index de olduðunu bulmamýz için döngü.
		if(tablo[i][0] == index)
			k = i ;		
	}
	printf("\n-------Silinen ogrenci--------\n");
	printf("Indis\tNumarasi\tNotu\n  %d\t%d\t %d\n",tablo[k][0],tablo[k][1],tablo[k][2]);
	printf("------------------------------\n");
	for(i = k ; i<15 ; i++ ){										// Bulunan indexin altýnda kalan satýrlar bir üst kýsma taþýnýr.
		tablo[i][0] = tablo[i+1][0];
		tablo[i][1] = tablo[i+1][1];
		tablo[i][2] = tablo[i+1][2];
	}
	for(i = 0;i<15;i++){													// Tabloyu ekrana bastýrýr. 
		printf("%d\t%d\t%d\n",tablo[i][0] , tablo[i][1] , tablo[i][2]);
	}
}

void degistir(int puan,int index){ 
	int i = 0;
	for(i = 0 ; i < 15 ; i++){							// Tabloda tüm deðerleri tarar ve aranan indexdeki öðrenci bulununca not bölümünü günceller.
		if(tablo[i][0] == index )
			tablo[i][2] = puan;			
	}
	sirala(tablo);										// Güncel deðeri sirala fonksiyonuna gönderir ve ardýndan tabloyu günceller.
}

void yazdir(int puan){									
	int i = 0  ;
	printf("\n----------------------------------\n%d notundan yuksek alan ogrenciler:\n----------------------------------\n",puan);
	for (i;i<15 ; i++){
		if(tablo[i][2] > puan){
			printf("%d\t%d\t%d\t\n",tablo[i][0],tablo[i][1],tablo[i][2]);		 
		}
	}
}


int main(){
	int islem  ;
	int i , no , puan ;
	while(1){
		printf("\n______________________________\n");
		printf("Tabloyu  yazdirmak  icin : 0\n");
		printf("Ekle     fonksiyonu icin : 1\n");
		printf("Sil  	 fonksiyonu icin : 2\n");
		printf("Degistir fonksiyonu icin : 3\n");
		printf("Yazdir   fonksiyonu icin : 4\n");
		printf("Programdan  cikmak  icin : 5\n");
		printf("______________________________");
		printf("\nLutfen islem seciniz : ");
		scanf("%d",&islem);
		
		switch (islem){
			
			case 0: // ekrana_yazdir()
				for(i=0;i<15;i++){
					printf("%d\t%d\t%d\n",tablo[i][0] , tablo[i][1] , tablo[i][2]);
				}
			
				break;
				
			case 1: // ekle()
			
				printf("\n---Tabloyu tek tek alip siralar---\n");
				for(i = 0 ; i<15 ; i++){										// Orjinal tablodaki deðerleri ekle fonksiyonuna göndermek için döngü.
					ekle(tablo[i][1] , tablo[i][2] , tablo[i][0] );
				}
				for(i = 0 ; i<15 ; i++){										// Ekle fonksiyonunda oluþan yenitablo dizisini orjinal tablo dizisine atmak için döngü.
					tablo[i][0] = yenitablo[i][0];
					tablo[i][1] = yenitablo[i][1];
					tablo[i][2] = yenitablo[i][2];
				}
				for(i = 0;i<15;i++){											// Tabloyu ekrana bastýrýr.	
					printf("%d\t%d\t%d\n",tablo[i][0] , tablo[i][1] , tablo[i][2]);}
				break;
	
			case 2:	// Sil()
				
				printf("Silinecek indisi giriniz : ");scanf("%d",&i);
				sil(tablo , i);
				break;
				
			case 3: // degistir()
				
				printf("\nNotunu degistirmek istediginiz ogrencinin indisini giriniz    : ");scanf("%d",&i);
				printf("\nNotunu degistirmek istediginiz ogrencinin yeni notunu giriniz : ");scanf("%d",&puan);
				degistir(puan,i);
				break;
				
			case 4: // yazdir()
				
				printf("\nHangi sayidan yuksek olan notlari gormek istersiniz : ");scanf("%d",&puan);
				yazdir(puan);
				break;
		}
		if (islem == 5){
			break;
		}	
	}				
}
