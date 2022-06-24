#include<stdio.h>
#include<math.h>
double doubleArray[]= {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,11.1,22.2,33.3,44.4,55.5,66.6,77.7,88.8,99.9 };
double calcAverage() , calcMedian() , calcStdDeviation() , calcVariance();
double diziboyutu = 18 , medyan , standartsapma , varyans;
int i =0  ; 

	int main(){
		printf("Dizinin aritmatik ortalamasi = %f\n",calcAverage());
		printf("Dizinin medyani = %.2f\n",calcMedian());
		printf("Dizinin varyansi = %f\n",calcVariance());
		printf("Dizinin standart sapmasi = %f\n",calcStdDeviation());
	}
		double calcAverage(){
			int i = 0;
			double toplam = 0.0;
			double ortalama = 0.0; 
		
			while(i<18){
				toplam = toplam + doubleArray[i];
				i++;
			}
 			ortalama = toplam / diziboyutu;
 			return ortalama ;
 		}
		double calcVariance(){
			double deg1 = 0 ;	
			for(i=0;i<18;i++){
				deg1 = deg1 + (doubleArray[i] - calcAverage()) * (doubleArray[i] - calcAverage());			
			}
			varyans = deg1/17;
			return varyans ;	
		}		
		double calcStdDeviation(){
			varyans = calcVariance();
			standartsapma = sqrt(varyans);
			return standartsapma;
		
		}
		double calcMedian(){
			medyan = ( doubleArray[17/2]+doubleArray[(17/2)+1] )/2;
			return medyan ;
		}
