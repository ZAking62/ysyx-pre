#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
	int i = 0,  count = 0;

	for(i = 0; argv[i] != NULL; i++){
		count++;
	}

	for(i = 0; i < count; i++){
		printf("%d , %s\n", i, argv[i]);
	}
	return 0;
}

