Node* Delete(Node *head, int position)
{
    Node *temp;

    if (head == NULL) {
	return NULL;
    }

    if (position == 0) {
	temp = head;
	head = head->next;
	delete temp;
	return head;
    }
    
    Node *current = head;
    for (int i = 0; i < position-1; i++) {
	current = current->next;
    }

    if (current->next->next == NULL) {
	delete current->next;
	current->next = NULL;
	return head;
    }

    temp = current->next;
    current->next = current->next->next;
    delete temp;
    return head;
}
