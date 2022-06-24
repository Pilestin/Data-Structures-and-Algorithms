#include<stdio.h>
int tablo[15][3] ={	{0 , 18060311 , 40},		// Ekle fonksiyonu �al��t�rmadan sil ve yazd�r gibi fonksiyonlar� �al��t�rabilmek i�in �nceden tan�ml� dizimiz.
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
int yenitablo[15][3]; 		// Ekle fonksiyonuna gelen de�erler s�raland�ktan sonra olu�acak de�erleri tutan dizi.
	
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
			if (tablo[k][2] < tablo[k+1][2]){    // Ders notuna g�re s�ralama
            	// Not de�i�imi
            	aradeger = tablo[k+1][2] ;
            	tablo[k+1][2] = tablo[k][2] ;
            	tablo[k][2] = aradeger ;
            	// ��renci numaras� de�i�imi
           		aradeger = tablo[k+1][1];
            	tablo[k+1][1] = tablo[k][1];
            	tablo[k][1] = aradeger ;
            	// �ndex de�i�imi
            	aradeger = tablo[k+1][0];
            	tablo[k+1][0] = tablo[k][0];
            	tablo[k][0] = aradeger ;			
			}
        	else if ((tablo[k][2] == tablo[k+1][2]) & (tablo[k][1] > tablo[k+1][1]) ){    // Ders notlar� e�itse ��renci numaras�na g�re s�ralama
            		// ��renci numaras� de�i�imi
                	aradeger = tablo[k+1][1];
                	tablo[k+1][1] = tablo[k][1];
                	tablo[k][1] = aradeger;
                	// �ndex de�i�imi
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
		if( puan > yenitablo[i][2] ){					// E�er yeni eklenen puan tablodakinden(�u an 0) b�y�kse d�ng� ba�lar. 
			for( k = 14 ; k>i ; k-- ){					// En alttan ba�layarak her sat�r� bir a�a��ya kayd�r�r. Ta ki , yeni gelen puan de�erinin b�y�k oldu�u sat�r a�a�� inene kadar.
				yenitablo[k][0] = yenitablo[k-1][0];
				yenitablo[k][1] = yenitablo[k-1][1];
				yenitablo[k][2] = yenitablo[k-1][2];
			}
			yenitablo[i][0] = index;					// Sat�rlar a�a�� indi�inde olu�an bo� sat�ra  , fonksiyona gelen de�erler yerle�ir.
			yenitablo[i][1] = ogr_no;
			yenitablo[i][2] = puan ; 
			break;
		}
		else if( (puan == yenitablo[i][2]) & (ogr_no < yenitablo[i][1] )){	// �stteki algoritman�n ayn�s�n� yapar.
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
	for(i = 0 ; i<15 ; i++){										// Silinecek ��rencinin tabloda hangi index de oldu�unu bulmam�z i�in d�ng�.
		if(tablo[i][0] == index)
			k = i ;		
	}
	printf("\n-------Silinen ogrenci--------\n");
	printf("Indis\tNumarasi\tNotu\n  %d\t%d\t %d\n",tablo[k][0],tablo[k][1],tablo[k][2]);
	printf("------------------------------\n");
	for(i = k ; i<15 ; i++ ){										// Bulunan indexin alt�nda kalan sat�rlar bir �st k�sma ta��n�r.
		tablo[i][0] = tablo[i+1][0];
		tablo[i][1] = tablo[i+1][1];
		tablo[i][2] = tablo[i+1][2];
	}
	for(i = 0;i<15;i++){													// Tabloyu ekrana bast�r�r. 
		printf("%d\t%d\t%d\n",tablo[i][0] , tablo[i][1] , tablo[i][2]);
	}
}

void degistir(int puan,int index){ 
	int i = 0;
	for(i = 0 ; i < 15 ; i++){							// Tabloda t�m de�erleri tarar ve aranan indexdeki ��renci bulununca not b�l�m�n� g�nceller.
		if(tablo[i][0] == index )
			tablo[i][2] = puan;			
	}
	sirala(tablo);										// G�ncel de�eri sirala fonksiyonuna g�nderir ve ard�ndan tabloyu g�nceller.
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
				for(i = 0 ; i<15 ; i++){										// Orjinal tablodaki de�erleri ekle fonksiyonuna g�ndermek i�in d�ng�.
					ekle(tablo[i][1] , tablo[i][2] , tablo[i][0] );
				}
				for(i = 0 ; i<15 ; i++){										// Ekle fonksiyonunda olu�an yenitablo dizisini orjinal tablo dizisine atmak i�in d�ng�.
					tablo[i][0] = yenitablo[i][0];
					tablo[i][1] = yenitablo[i][1];
					tablo[i][2] = yenitablo[i][2];
				}
				for(i = 0;i<15;i++){											// Tabloyu ekrana bast�r�r.	
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
