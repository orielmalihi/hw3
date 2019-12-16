/*
 * main2.c
 *
 *  Created on: 15 Dec 2019
 *      Author: oriel
 */
#include "stdio.h"
#include "strings.h"
#define WORD 30
#define LINE 256

int main(){
	char w[WORD];
	char action;
	getword(w);
	scanf(" %c", &action);
	if(action == 'a')
		print_lines(w);
	else if(action == 'b')
		print_similar_words(w);

	return 0;
}


