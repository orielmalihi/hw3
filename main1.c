/*
 * main1.c
 *
 *  Created on: 14 Dec 2019
 *      Author: oriel
 */
#include "stdio.h"
#include "sorting.h"
#define maxLen 50

int main(){
	printf("Please enter 50 numbers to sort\n");
	int arr[50];
	for(int i =0; i<maxLen; i++){
		scanf(" %d", arr+i);
	}
	insertion_sort(arr, maxLen);
	for(int i =0; i<maxLen; i++)
		printf("%d ", *(arr+i));
	printf("\n");

	return 0;
}



