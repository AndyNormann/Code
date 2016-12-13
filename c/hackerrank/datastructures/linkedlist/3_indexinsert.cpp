#include <iostream>

struct Node
{
    int data;
    Node *next;
};

Node* InsertNth(Node *head, int data, int position);

int main()
{
    Node *head = NULL;
    head = InsertNth(head, 4, 0);
    head = InsertNth(head, 1, 1);
    head = InsertNth(head, 9, 2);
    head = InsertNth(head, 8, 3);
    head = InsertNth(head, 7, 4);
    head = InsertNth(head, 0, 5);
    head = InsertNth(head, 0, 2);

    for(Node *current = head; current != NULL; current = current->next){
	printf("%d --> ", current->data);
    }
    printf("NULL\n");

    for(Node *current = head; current != NULL; current = current->next){
	printf("%d --> ", current->data);
    }
    printf("NULL\n");

    return 0;
}


Node* InsertNth(Node *head, int data, int position)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;

    if (position == 0) {
	new_node->next = head;
	return new_node;
    }
    if (head == NULL) {
	return new_node;
    }

    Node *current = head;
    for (int i = 0; i < position-1; ++i) {
        current = current->next;
    }

    if (current->next == NULL) {
	current->next = new_node;
    } else {
	new_node->next = current->next;
	current->next = new_node;
    }
    return head;
}
