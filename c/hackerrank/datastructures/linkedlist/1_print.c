
void Print(Node *head)
{
    Node *temp;
    for(temp = head; temp != NULL; temp = temp->next){
        printf("%d\n", temp->data);
    }
}


