#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

/** Our old friend die from ex17. */
void die(const char *message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// a typedef creates a fake type, in this
// case for a function pointer
typedef int (*compare_cb)(int a, int b);
typedef int (*newcompare_cb)(int a, int b);
/**
 * A classic bubble sort function that uses the
 * compare_cb to do the sorting.
 */
int *select_sort(int *numbers, int count, newcompare_cb ncmp){
	int *target = malloc(count * sizeof(int));
	if(!target) die("Memory error");
	memset(target, 0, count * sizeof(int));
	int *flags = malloc(count * sizeof(int));
	memset(flags, 0, count * sizeof(int));
	for(int i = 0; i < count; i++){
		int temp = 0;
		int flag = 0;
		for(int j = 0; j < count - 1; j++){
			if(ncmp(numbers[j] , numbers[j + 1]) > 0 && flags[j] == 0) {
				temp = numbers[j];
				flag = j;
			}
			else if(ncmp(numbers[j], numbers[j + 1]) < 0 &&  flags[j + 1] == 0){
				temp = numbers[j+1];
				flag = j + 1;
			}
		}
		target[i] = temp;
		flags[flag] = 1; 
	}
	return target;
		
}

int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    if(!target) die("Memory error.");

    memcpy(target, numbers, count * sizeof(int));

    for(i = 0; i < count; i++) {
        for(j = 0; j < count - 1; j++) {
            if(cmp(target[j], target[j+1]) > 0) {
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;
            }
        }
    } 

    return target;
}

int sorted_order(int a, int b)
{
    return a - b;
}

int reverse_order(int a, int b)
{
    return b - a;
}

int strange_order(int a, int b)
{
    if(a == 0 || b == 0) {
        return 0;
    } else {
        return a % b;
    }
}

/**
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */
void test_sorting(int *numbers, int count, compare_cb cmp)
{
    int i = 0;
	int start = clock();
    int *sorted = bubble_sort(numbers, count, cmp);
	int stop = clock();
    if(!sorted) die("Failed to sort as requested.");

    for(i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

	unsigned char *data = (unsigned char *)cmp;

	for(i = 0; i < 25; i++) {
		printf("%02x:", data[i]);
	}

	printf("\n");
	printf("%d\n", stop - start);
    free(sorted);
}

void newtest_sorting(int *numbers, int count, newcompare_cb ncmp)
{
    int i = 0;
	int start = clock();
    int *sorted = bubble_sort(numbers, count, ncmp);
	int stop = clock();
    if(!sorted) die("Failed to sort as requested.");

    for(i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

	unsigned char *data = (unsigned char *)ncmp;

	for(i = 0; i < 25; i++) {
		printf("%02x:", data[i]);
	}

	printf("\n");
	printf("%d\n", stop - start);
    free(sorted);
}


int main(int argc, char *argv[])
{
    if(argc < 2) die("USAGE: ex18 4 3 1 5 6");

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if(!numbers) die("Memory error.");

    for(i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
    }

    test_sorting(numbers, count, sorted_order);
    test_sorting(numbers, count, reverse_order);
    test_sorting(numbers, count, strange_order);
	newtest_sorting(numbers, count, sorted_order);
    newtest_sorting(numbers, count, reverse_order);
    newtest_sorting(numbers, count, strange_order);

    free(numbers);

    return 0;
}
