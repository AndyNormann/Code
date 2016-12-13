#include <stdio.h>

struct Node
{
    int data;
    Node *next;
};

Node *add_node(Node *head, int data);
void print_list(Node *head);
Node *Reverse(Node *head);

int main()
{
    Node *head = NULL;

    head = add_node(head, 1);
    head = add_node(head, 2);
    head = add_node(head, 3);
    head = add_node(head, 4);
    head = add_node(head, 5);
    head = add_node(head, 6);
    head = add_node(head, 7);

    print_list(head);

    Node *reversed_list = Reverse(head);

    print_list(reversed_list);

    return 0;
}

Node *Reverse(Node *head)
{
    Node *new_list = NULL;
    int length = 0;
    for(Node *current = head; current != NULL; current = current->next){
        length++;
    }

    for (int i = length-1; i >= 0; i--) {
        Node *current;
        int j;
        for(current = head, j = 0; j < i; current = current->next, j++){}

        new_list = add_node(new_list, current->data);
    }

    return new_list;
}

Node *add_node(Node *head, int data) 
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;

    if (!head) {
        return new_node;
    }

    Node *current;
    for(current = head; current->next != NULL; current = current->next){}
    current->next = new_node;

    return head;
}

void print_list(Node *head)
{
    for (Node *current = head; current != NULL; current = current->next) {
        printf("%d --> ", current->data);
    }
    printf("NULL\n");
}

