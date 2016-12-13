#include <stdio.h>


struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
    ~Node()
    {
        if (next) {
            delete next;
        }
        next = NULL;
        data = 0;
    }
};

struct LinkedList
{
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    ~LinkedList()
    {
        if (head) {
            delete head;
        }
        head = NULL;
        tail = NULL;
    }

    void print_list()
    {
        for (Node *current = head; current != NULL; current = current->next) {
            printf("%d --> ", current->data);
        }
        printf("NULL\n");
    }

    void add(int data)
    {
        Node *new_node = new Node(data);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else{
            new_node->next = head;
            head = new_node;
        }
    }
};

int GetNode(Node *head,int positionFromTail)
{
    int length = 0;
    for (Node *current = head; current != NULL; current = current->next) {
        length++;
    }
    length -= positionFromTail;
    for (Node *current = head; current != NULL; current = current->next) {
        length--;
        if (length == 0) {
            return current->data;
        }
    }
}
