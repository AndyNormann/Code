#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Dynamic {
    int *array = NULL;
    size_t count = 0;
    size_t size = 100;

    Dynamic()
    {
        array = new int[100];
    }

    ~Dynamic()
    {
        delete array;
    }

    void add(int i)
    {
        array[count++] = i;
        if(count == size){
            int *temp = new int[size*2];
            memcpy(temp, array, sizeof(int)*count);
            size = size*2;
            delete array;
            array = temp;
        }
    }

    inline int get(int index)
    {
        return array[index];
    }
};


int main()
{
    Dynamic *d = new Dynamic();

    for(int i = 300; i > 0; i--){
        d->add(i);
    }

    printf("%d\n", d->get(278));
    printf("%d\n", d->get(45));
    printf("%d\n", d->get(0));
    printf("%d\n", d->get(299));
    printf("%d\n", d->get(32));
    printf("%d\n", d->get(190));
    printf("%d\n", d->get(230));
    printf("%d\n", d->get(111));

    printf("array count: %zd\n", d->count);
    printf("array count: %zd\n", d->size);
    d->add(15);
    delete d;


    Dynamic arr;

    for (int i = 0; i < 300; i++) {
        arr.add(i);
    }

    printf("%d\n", arr.get(278));
    printf("%d\n", arr.get(45));
    printf("%d\n", arr.get(0));
    printf("%d\n", arr.get(299));
    printf("%d\n", arr.get(32));
    printf("%d\n", arr.get(190));
    printf("%d\n", arr.get(230));
    printf("%d\n", arr.get(111));

    printf("%zd\n", arr.count);
    printf("%zd\n", arr.size);

    return 0;
}
