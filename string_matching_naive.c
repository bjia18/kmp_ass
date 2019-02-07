#include "string_matching.h"

int string_matching_naive(char *text, int n, char* pattern, int m){
	int match=0, count=0;
	for (int i=0;i<n;i++){
		if (text[i]==pattern[count])
			count++;
		else
			count=0;
		
		if (count==m){
			match++;
			count=0;
		}
	}
	return match;
}
