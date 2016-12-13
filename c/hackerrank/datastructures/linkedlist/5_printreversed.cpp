void ReversePrint(Node *head)
{
    if (head) {
	ReversePrint(head->next);
	printf("%d\n", head->data);
    }
}
