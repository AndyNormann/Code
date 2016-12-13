#include <stdio.h>
#include <stdlib.h>

typedef struct dynnamic_array 
{
    size_t count;
    size_t size;
    int *data;
} d_array;

void make_dynamic_array(d_array *array);
void array_append(d_array *array, int elem);
void print_dynamic_array(d_array *array);


void make_dynamic_array(d_array *array)
{
    array->count = 0;
    array->size = 10;
    array->data = calloc(array->size, sizeof(int));
}

void print_dynamic_array(d_array *array)
{
    size_t i;
    for (i = 0; i < array->count; ++i) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

void array_append(d_array *array, int elem)
{
    if (array->count > array->size) {
        array->data[array->count] = elem;
        array->count++;
        return;
    }

    array->data = reallocf(array->data, array->size*2);
    array->size *= 2;
    array->data[array->count] = elem;
    array->count++;
}

int main()
{
    int N, Q;
    int lastAns = 0;
    int i;

    scanf("%d %d", &N, &Q);

    d_array *seqList = calloc((size_t)N, sizeof(d_array));

    for (i = 0; i < N; ++i) {
        make_dynamic_array(&seqList[i]);
    }

    for (i = 0; i < Q; ++i) {
        int query, x, y;
        scanf("%d %d %d", &query, &x, &y);

        int seq = (x^lastAns) % N;

        if (query == 1) {
            array_append(&seqList[seq], y);
        }else{
            lastAns = seqList[seq].data[y % (int)seqList[seq].count];
            printf("%d\n", lastAns);
        }
    }

    for (i = 0; i < N; ++i) {
        free(seqList[i].data); 
    }
    free(seqList);

    return 0;
}

