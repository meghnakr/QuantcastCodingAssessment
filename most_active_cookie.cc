#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <map>
#include <iostream>

int main(int argc, char * argv[]) {
	if (argc != 4) {
		return -1;
	}
	char * filename = argv[1];
	FILE * fp = fopen(filename, "r");
	int maxLineLength = 0;
	int eachLineLength = 0;
	int numLines = 0;
	int flag = 0;
	while (1) {
		char c = getc(fp);
		if (c == '\n') {
			flag = 1;
			numLines++;
			if (eachLineLength > maxLineLength) {
				maxLineLength = eachLineLength;
			}
			eachLineLength = 0;
		}
		else if (c == EOF) {
			if (flag == 0) {
				numLines++;
				if (eachLineLength > maxLineLength) {
					maxLineLength = eachLineLength;
				}
			}
			break;
		}
		else {
			flag = 0;
			eachLineLength++;
		}
	}
	//char * line = (char *) malloc(maxLineLength);
	char * cookie = (char *) malloc(maxLineLength);
	char date[12];
	char ** cookieArray = (char **) malloc(numLines * sizeof(char *));
	//printf("Number of lines = %d\n", numLines);
	//cookies = (char **) malloc(sizeof(char *) * (numLines - 1));
	int arrayLen = 0;
	rewind(fp);
	std::map<std::string, int> cookie_count;
	int maxFreq = 0;
	for (int i = 0; i < numLines; i++) {
		//fscanf(fp, "%100[^,\n],%30[^,\n]\n", cookie, date);
		fscanf(fp, "%s\n", cookie);
		char * comma = strchr(cookie, ',');
		if (comma == NULL) {
			break;
		}
		strncpy(date, comma + 1, 10);
		date[10] = '\0';
		comma[0] = '\0';
		//printf("%s %s\n", cookie, date);
		//printf("%s %s\n", cookie, date);
		if (i == 0) {
			continue;
		}
		if (strncmp(date, argv[3], 10) == 0) {
			cookie_count[cookie] += 1;
			if (cookie_count[cookie] > maxFreq) {
				maxFreq = cookie_count[cookie];
			}
			if (cookie_count[cookie] == 1) {
				cookieArray[arrayLen] = (char *) malloc(strlen(cookie));
				strcpy(cookieArray[arrayLen], cookie);
				arrayLen++;
			}
		}
	}
	//printf("%d\n", arrayLen);
	for (int i = 0; i < arrayLen; i++) {
		int freq = cookie_count[cookieArray[i]];
		if (freq == maxFreq) {
			printf("%s\n", cookieArray[i]);
		}
		free(cookieArray[i]);
	}
	free(cookieArray);
	free(cookie);
	//free(line);
	return 0;
}
