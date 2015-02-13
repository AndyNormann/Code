#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct NoField {
    unsigned int value;
    unsigned int value2;
} nofield;

typedef struct Field{
    unsigned int value : 1;
    unsigned int value2 : 1;
    unsigned int value3 : 1;
    unsigned int value4: 9;
} field;

int main(int argc, const char *argv[])
{
    field* f = malloc(sizeof(field));
    f->value = 1;
    f->value2 = 0;
    f->value3 = 1;
    f->value4 = 256;

    printf("fields: %d %d %d %d\n", f->value, f->value2, f->value3, f->value4);

    printf("NoField: %ld\nField: %ld\n", sizeof(nofield), sizeof(field));
    free(f);
    return 0;
}

