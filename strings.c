/*
 * strings.c
 *
 *  Created on: 15 Dec 2019
 *      Author: oriel
 */
#include "stdio.h"
#include "string.h"
#define LINE 256
#define WORD 30

void clearInputBuffer(){
	char c = getchar();
	while ( c != '\n'){
		c = getchar();
	}
}

int getLine(char s[]){
	char c = getchar();
	int i = 0;
	int numberOfLetters = 0;
	while(c=='\n'){
		c = getchar();
	}
	if(c==EOF)
		return 0;
	while(c != '\n' && numberOfLetters<LINE && c != EOF){
		s[i] = c;
		i++;
		numberOfLetters++;
		c = getchar();
	}
	if(numberOfLetters>0)
		s[i] = c;
//	printf("%d\n", numberOfLetters);
	printf("%s", s);
	return numberOfLetters;



	//	char c;
	//	scanf("%c", &c);
	//	int i = 0;
	//	int numberOfLetters = 0;
	//	while(c!='\n' && numberOfLetters<LINE){
	//		s[i] = c;
	//		i++;
	//		numberOfLetters++;
	//		c = getchar();
	//	}
	//	if(numberOfLetters>0)
	//		s[i] = c;
	//	return numberOfLetters;
}

int getword(char w[]){
	char c;
	c = getchar();
	int i = 0;
	int numberOfLetters = 0;
	while(c=='\n' || c=='\t' || c==' '){
			c = getchar();
		}
		if(c==EOF)
			return 0;
	while(c!='\n' && c!='\t' && c!=' ' && numberOfLetters<WORD && c != EOF){
		w[i] = c;
		i++;
		numberOfLetters++;
		c = getchar();
	}
	if(numberOfLetters>0)
		w[i] = '\n';
	return numberOfLetters;
}

int startsWith(char* str1, char* str2){
	int str1L = strlen(str1);
	int str2L = strlen(str2);
	if(str1L<str2L)
		return 0;
	for(int i =0; i<str2L; i++){
		if(str1[i]!=str2[i])
			return 0;
	}
	return 1;
}

int substring(char* str1, char* str2){
	int str1L = strlen(str1);
	int ans = 0;
	for(int i =0; i<str1L; i++){
		if(startsWith(str1+i, str2)){
			ans = 1;
			break;
		}
	}
	return ans;
}

int similar(char* s, char* t, int n){
	int sL = strlen(s);
	int tL = strlen(t);
	if(sL-tL>n || sL-tL<0)
		return 0;
	int notGoodLetters = 0;
	while(*t != '\n'){
		if(*s != *t){
			s++;
			notGoodLetters++;
			if(notGoodLetters > n)
				return 0;
		}
		else
		{
			s++;
			t++;
		}
	}
	return 1;
}

void print_lines(char* str){
	char line[LINE];
	int n = getLine(line);
	while(n > 0){
		if(substring(line, str)){
			printf("correct! this is the line:\n");
			printf("%s\n", line);
		}
		n = getLine(line);
	}
}


