#include <stdio.h>
#include <stdlib.h>

// qsort fonksiyonunun �a��raca�� kar��la�t�rma fonksiyonu
int cmpfunc(const void * a, const void * b) {
	
   return ( *(int*)a - *(int*)b );
}

// binary search i�lemini ger�ekle�tiren fonksiyon

int binarySearch(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)  							// aranan eleman ortadaki elemana e�itse ortanca indis d�nd�r�l�r
            return mid;
        if (arr[mid] > x)  								// aranan eleman ortadaki elemandan k���kse, sol taraf binary search ile aran�r
            return binarySearch(arr, low, mid - 1, x);
        return binarySearch(arr, mid + 1, high, x);  	// aranan eleman ortadaki elemandan b�y�kse, sa� taraf binary search ile aran�r
    }
    return -1;  										// eleman bulunamad�ysa -1 d�nd�r�l�r
}

int main() {
    int dizi[]={4,8,3,84,47,76,9,24,68};
    int n = sizeof(dizi) / sizeof(dizi[0]);  		// dizi boyutu hesaplan�r
    int x = 76;  									// aranacak eleman belirlenir
    qsort(dizi, n, sizeof(int), cmpfunc);   		// dizi s�ralan�r
    int sonuc = binarySearch(dizi, 0, n - 1, x);  	// s�ralanm�� diziye binary search uygulan�r
    if (sonuc == -1)  								// eleman bulunamad�ysa
        printf("Eleman bulunamadi.");
    else  											// eleman bulunduysa
        printf("Eleman %d indisinde bulundu.", sonuc);
    return 0;
}

