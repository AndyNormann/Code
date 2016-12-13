#include <stdio.h>

struct Node
{
    int data;
    Node *next;
};


bool has_cycle(Node* head);

bool has_cycle(Node* head)
{
    if (head == NULL) {
        return false;
    }

    Node *current = head;
    Node *next = head->next;

    while (true) {
        if (!next || !next->next || !next->next->next) {
            return false;
        }
        if (current == next) {
            break;
        }
        
        current = current->next;
        next = next->next->next;
    }
    return true;
}


int main()
{
    Node *head = new Node();
    head->next = new Node();
    head->next->next = new Node();
    head->next->next->next = new Node();
    head->next->next->next->next = new Node();

    int count = 0;
    for (Node *current = head; current != NULL; current = current->next) {
        current->data = count++;
        printf("%d\n", current->data);
    }

    //head->next->next->next->next = head;

    if (has_cycle(head)) {
        printf("It has a cycle\n");
    }else{
        printf("It doesen't have a cycle\n");
    }
    
    return 0;
}
