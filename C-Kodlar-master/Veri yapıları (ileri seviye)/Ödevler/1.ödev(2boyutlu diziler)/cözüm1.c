#include <stdio.h>

#define N 15

int OgrListe[N][2] = {{18060311,40},{20060045,50},{19061091,75},{20060134,90},{20060678,40},{18061086,75},{20060032,50},{20060067,60},{19060456,60},{18060245,75},{20060110,40},{20060234,90},{20060141,60},{20060011,50},{20060012,60}};
int indListe[N]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int ekle (int ind){
  int i,j;
  
  // indise ait not ve no de�erleri de�i�kene atan�r
  int no = OgrListe[ind][0];
  int not = OgrListe[ind][1];

  for(i=0;i<N;i++){
    if ((indListe[i]==-1) || (not > OgrListe[indListe[i]][1]) || (not == OgrListe[indListe[i]][1] && no < OgrListe[indListe[i]][0])) // indeks listesinde verilen indisin eklenece�i yer bulunur
      break;
  }
  for(j=N-1;j>i;j--){
    if(indListe[j-1]==-1){ // indeks listesindeki dolu de�erlerin yeri bulunur
      continue;
    }
    indListe[j]=indListe[j-1]; // indeks listesindeki indisler, yukar�ya ekleme i�in birer sona kayd�r�l�r
  }
  indListe[i]=ind; // indis de�eri indeks listesindeki yerine yaz�l�r

  return 0;
}

int sil (int ind){
  int i,j;

  for(i=0;i<N;i++){
    if (indListe[i]==ind) // verilen indisin indeks listesindeki yeri(indisi) bulunur
      break;
  }
  for(j=i;j<N-1;j++){
    if(indListe[j+1]==-1){ // liste sonuna gelindi�inde d�ng� k�r�l�r (liste sonunda -1 de�erleri varsa)
      indListe[j]=indListe[j+1];
      break;
    }
    indListe[j]=indListe[j+1]; // verilen indisten sonra gelen indisler, indeks listesinde birer yukar� kayd�r�l�r
  }
  indListe[j]=-1; // listenin en son bo�alan indisi -1'e �ekilir

  return 0;
}
int degistir(int ind){
  sil(ind);
  ekle(ind);

  return 0;
}

int yazdir(int not){
  int i;
  printf("OgrenciNo\tNot\n");
  for(i=0;i<N;i++){
    if(not>OgrListe[indListe[i]][1])  // verilen nottan daha k���k de�erlere gelindi�inde yazd�rma/d�ng� sonlan�r
      break;
    printf("%9d\t%3d\n",OgrListe[indListe[i]][0],OgrListe[indListe[i]][1]);
  }
  return 0;
}

int main (void) {

  int i;
  for (i=0;i<N;i++)
    ekle(i);
  sil(11);
  yazdir(60);
  ekle(11);
  yazdir(60);
  
  return 0;
}


