#include <stdio.h>

int main(int argc, char* argv[]){
	if(argc != 2){
		printf("ERROR: You need one argument.\n");
		return 0;
	}

	char* temp = argv[1];
	for(int i = 0; temp[i] != '\0'; i++){
		int t = temp[i] + 32;
		printf("%c\n", t);
	}

	return 0;

}
	
