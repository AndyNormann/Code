Node* RemoveDuplicates(Node *head)
{
    if (!head) {
        return NULL;
    }
    if (!head->next) {
        return head;
    }
    
    
    if (head->data == head->next->data) {
        Node *temp = head->next;
        head->next = head->next->next;
        delete temp;
        RemoveDuplicates(head);
    }else{
        RemoveDuplicates(head->next);    
    }
    return head;
}

