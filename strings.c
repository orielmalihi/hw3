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



int getLine(char s[]){
	char c = getchar();
	int letterIndex = 0;
	while(c=='\n'){
		c = getchar();
	}
	if(c==EOF)
		return 0;
	while(c != '\n' && letterIndex<LINE && c != EOF){
		s[letterIndex] = c;
		letterIndex++;
		c = getchar();
	}
	s[letterIndex] = 0;
	return letterIndex;
}



int getword(char w[]){
	char c;
	c = getchar();
	int letterIndex = 0;
	while(c=='\n' || c=='\t' || c==' '){
		c = getchar();
	}
	if(c==EOF)
		return 0;
	while(c!='\n' && c!='\t' && c!=' ' && letterIndex<WORD && c != EOF){
		w[letterIndex] = c;
		letterIndex++;
		c = getchar();
	}
	w[letterIndex] = 0;
	return letterIndex;
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
	for(int i =0; i<str1L; i++){
		if(startsWith(str1+i, str2)){
			return 1;
		}
	}
	return 0;
}

int similar(char* s, char* t, int n){
	int sL = strlen(s);
	int tL = strlen(t);
	if(sL-tL>n || sL-tL<0){
		return 0;
	}
	int notGoodLetters = 0;
	while(*t != 0){
		if(*s != *t){
			s++;
			notGoodLetters++;
			if(notGoodLetters > n){
				return 0;
			}
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
			printf("%s\n", line);
		}
		n = getLine(line);
	}
}

void print_similar_words(char* str){
	char word[WORD];
	int n = getword(word);
	while(n > 0){
		if(similar(word, str, 1)){
			printf("%s\n", word);
		}
		n = getword(word);
	}
}


