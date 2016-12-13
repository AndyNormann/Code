int CompareLists(Node *headA, Node* headB)
{
    Node *currentA, currentB;

    for (currentA = headA, currentB = headB; currentA && currentB && currentA->data == currentB->data; currentA = currentA->next, currentB = currentB->next){}

    if (!currentA && !currentB) {
        return 1;
    }
    return 0;
}
