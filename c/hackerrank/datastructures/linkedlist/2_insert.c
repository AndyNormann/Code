
struct Node *Insert(struct Node *head, int data)
{
    if (head == NULL) {
        head = calloc(1, sizeof(struct Node));
        head->data = data;
        return head;
    }

    struct Node *temp;
    for (temp = head; temp->next != NULL; temp = temp->next) {}

    temp->next = calloc(1, sizeof(struct Node));
    temp->next->data = data;
    return head;
}

