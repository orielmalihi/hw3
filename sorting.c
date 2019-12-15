/*
 * sorting.c
 *
 *  Created on: 14 Dec 2019
 *      Author: oriel
 */


void shift_element(int* arr, int i){
	for(int j=i; j>0; j--){
		*(arr+j) = *(arr+j-1);
	}
}

void insertion_sort(int* arr, int len){
	for(int i=0; i<len; i++){
		int numOfShift =0;
		for(int j=i-1; j>=0; j--){
			if(*(arr+i)<*(arr+j))
				numOfShift++;
		}
		int temp = *(arr+i);
		shift_element(arr+i-numOfShift, numOfShift);
		*(arr+i-numOfShift) = temp;
	}
}



