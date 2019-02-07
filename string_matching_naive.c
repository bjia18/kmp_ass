#include "string_matching.h"

int string_matching_naive(char *text, int n, char* pattern, int m){
	int match=0;
	for (int j=0;j<n;j++){
		for (int i=0;i<m;i++){
			if (text[j+i]!=pattern[i])
				break;
			if (i==(m-1))
				match++;
		}
	}
	return match;
}
