#include <iostream>

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
    ~Node(){
        delete(next);
    }
};

struct LinkedList
{
    Node *root;
    Node *end;
    Node *mid;

    LinkedList()
    {
        root = NULL;
        end = NULL;
        mid = NULL;
    }
    ~LinkedList(){
        delete(root);
    }

    void add(int to_add)
    {
        Node *new_node = new Node(to_add);
        if (root == NULL) {
            root = new_node;
            end = root;
        }else{
            end->next = new_node;
            end = end->next;
        }

    }

    void print()
    {
        for(Node *current = root; current != NULL; current = current->next){
            std::cout << current->data << std::endl;
        }
    }

    void remove_index(int index)
    {
        if (index == 0) {
            Node *temp = root;
            root = root->next;
            delete(temp);
            return;
        }
        Node *current = root;
        int i = 0;
        for (; current != NULL; current = current->next, i++) {
            if (i==index-1) {
                Node *temp = current->next;
                current->next = current->next->next;
                delete(temp);
            }
        }
    }

    void remove_elem(int elem)
    {
        if (root->data == elem) {
            Node *temp = root;
            root = root->next;
            delete(temp);
        }else{
            for (Node *current = root; current->next->data != elemt; current = current->next) {}
        }
    }
};

int main(int argc, const char *argv[])
{
    LinkedList l;
    
    l.add(5);
    l.add(0);
    l.add(9);
    l.add(7);
    l.add(2);
    l.add(1);
    l.print();

    return 0;
}
