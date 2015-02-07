#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

#define GREEN "\x1B[32m"
#define WHITE "\x1B[37m"
#define RESET "\x1B[0m"


void print_array(int* array, int size, int hl){
    system("clear");
    int i;
    for (i = 0; i < size; i++) {
        if(i == hl){
            printf(GREEN "%d " RESET, array[i]);
        }else
            printf(WHITE "%d " RESET, array[i]);
    }
    printf("\n");
}

void insert_sort(int* array, int size){
    int i, j, temp;
    for (i = 1; i < size; i++) {
        j = i;
        print_array(array, size, j);
        getchar();
        while(j > 0 && array[j-1] > array[j]){
            temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp;
            j--;
            print_array(array, size, j);
            getchar();
        }
    }
    print_array(array, size, size+1);
}

int* rand_array(int size){
    srand(time(NULL));
    int* array = malloc(sizeof(int)*size);
    int i;
    
    for (i = 0; i < size; i++) {
        array[i] = rand()%MAX;
    }

    return array;
}


int main(int argc, const char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <Arraysize>\n", argv[0]);
        return -1;
    }
    int size = atoi(argv[1]);
    int* array = rand_array(size);

    insert_sort(array, size);

    free(array);
    return 0;
}

