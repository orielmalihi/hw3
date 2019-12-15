/*
 * strings.h
 *
 *  Created on: 15 Dec 2019
 *      Author: oriel
 */

#ifndef STRINGS_H_
#define STRINGS_H_

int getLine(char s[]);
int getword(char w[]);
int startsWith(char* str1, char* str2);
int substring(char* str1, char* str2);
int similar(char* s, char* t, int n);
void print_lines(char* str);
void clearInputBuffer();


#endif /* STRINGS_H_ */
