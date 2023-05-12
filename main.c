#include <stdio.h>
#include <stdlib.h>

// qsort fonksiyonunun çaðýracaðý karþýlaþtýrma fonksiyonu
int cmpfunc(const void * a, const void * b) {
	
   return ( *(int*)a - *(int*)b );
}

// binary search iþlemini gerçekleþtiren fonksiyon

int binarySearch(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)  							// aranan eleman ortadaki elemana eþitse ortanca indis döndürülür
            return mid;
        if (arr[mid] > x)  								// aranan eleman ortadaki elemandan küçükse, sol taraf binary search ile aranýr
            return binarySearch(arr, low, mid - 1, x);
        return binarySearch(arr, mid + 1, high, x);  	// aranan eleman ortadaki elemandan büyükse, sað taraf binary search ile aranýr
    }
    return -1;  										// eleman bulunamadýysa -1 döndürülür
}

int main() {
    int dizi[]={4,8,3,84,47,76,9,24,68};
    int n = sizeof(dizi) / sizeof(dizi[0]);  		// dizi boyutu hesaplanýr
    int x = 76;  									// aranacak eleman belirlenir
    qsort(dizi, n, sizeof(int), cmpfunc);   		// dizi sýralanýr
    int sonuc = binarySearch(dizi, 0, n - 1, x);  	// sýralanmýþ diziye binary search uygulanýr
    if (sonuc == -1)  								// eleman bulunamadýysa
        printf("Eleman bulunamadi.");
    else  											// eleman bulunduysa
        printf("Eleman %d indisinde bulundu.", sonuc);
    return 0;
}

