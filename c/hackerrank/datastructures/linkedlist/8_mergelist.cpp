#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node(int v)
    {
        data = v;
        next = NULL;
    }
};

Node* MergeLists(Node *headA, Node* headB);
Node *Add(Node *head, int value);
void PrintList(Node *head);

Node *Add(Node *head, int value)
{
    Node *ret_val = new Node(value);
    if (head == NULL) {
        return ret_val;
    }
    if (head->next == NULL) {
        head->next = ret_val;
        return head;
    }
    Node *current;
    for (current = head; current->next != NULL; current = current->next) {}
    current->next = ret_val;
    return head;
}

void PrintList(Node *head)
{
    for (Node *current = head; current != NULL; current = current->next) {
        printf("%d --> ", current->data);
    }
    printf("NULL\n");
}

Node* MergeLists(Node *headA, Node* headB)
{
    if (headA == NULL) {
        return headB;
    }
    if (headB == NULL) {
        return headA;
    }
    if (headA->data < headB->data) {
        headA->next = MergeLists(headA->next, headB);
        return headA;
    }else{
        headB->next = MergeLists(headB->next, headA);
        return headB;
    }
}

int main()
{
    Node *headA = NULL;
    headA = Add(headA, 1);
    headA = Add(headA, 3);
    headA = Add(headA, 5);
    headA = Add(headA, 7);
    headA = Add(headA, 9);

    PrintList(headA);

    printf("\n");

    Node *headB = NULL;
    headB = Add(headB, 2);
    headB = Add(headB, 4);
    headB = Add(headB, 6);
    headB = Add(headB, 8);
    headB = Add(headB, 10);

    PrintList(headB);

    printf("\nMerging lists\n\n");

    MergeLists(headA, headB);

    PrintList(headA);

    return 0;
}

