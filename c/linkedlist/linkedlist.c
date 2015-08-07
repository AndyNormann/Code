#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *make_node(int data){
    Node *ret_val = malloc(sizeof(Node));
    ret_val->data = data;
    ret_val->next = NULL;
    return ret_val;
}

Node *root;
Node *end;
Node *mid;
int count;

void set_mid(){
    Node *current = root;
    int i;
    for (i = 0; i < count/2; i++) {
        current = current->next;
    }
    mid = current;
}

void add(int to_add){
    if(root == NULL){
        root = make_node(to_add);
        end = root;
    }else{
        end->next = make_node(to_add);
        end = end->next;
    }
    count++;
    set_mid();
}

void print_list(){
    Node *current;
    for (current = root; current != NULL; current = current->next) {
        printf("%d\n", current->data);
    }
}

void read_file(const char* filename){
    FILE *file = fopen(filename, "r");

    int ret = 1;
    int buf = 0;

    while((ret = fscanf(file, "%d", &buf)) != EOF){
        add(buf);
    }
    fclose(file);
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return -1;
    }
    count = 0;

    read_file(argv[1]);

    print_list();

    printf("Middle element: %d\n", mid->data);
    return 0;
}
