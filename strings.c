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
	//	printf("strlen: %ld\n", strlen(s));
	//	printf("letter index: %d\n", letterIndex);
	//	printf("%s\n", s);
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
//	printf("the word: %s\n", w);
//	printf("strlen: %ld\n", strlen(w));
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
	//	printf("str1l: %d, str1 = %s\n", str1L, str1);
	//	printf("str2l: %d, str2 = %s\n", str2L, str2);
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
//		printf("fi--> sl: %d, src: %s\n", sL, s);
//		printf("fi--> tl: %d, tar: %s\n", tL, t);
		return 0;
	}
	int notGoodLetters = 0;
	while(*t != 0){
		if(*s != *t){
			s++;
			notGoodLetters++;
			if(notGoodLetters > n){
	//			printf("while--> sl: %d, src: %s, notgoodleters: %d\n", sL, s, notGoodLetters);
	//			printf("while--> tl: %d, tar: %s\n", tL, t);
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
	//	printf("pase 1\n");
	while(n > 0){
		//		printf("pase 2\n");
		if(similar(word, str, 1)){
//			printf("correct! this is the word:\n");
			printf("%s\n", word);
		}
		n = getword(word);
	}
}


