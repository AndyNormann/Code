#include <iostream>

typedef struct Bt_Node{
    int val;
    struct Bt_Node *left;
    struct Bt_Node *right;
    public:
    Bt_Node(int value){
        val = value;
        left = NULL;
        right = NULL;
    }
} bt_node;

typedef struct Bt_Root{
    int amount;
    bt_node *root;

    public:
    Bt_Root(int rootVal){ 
        amount = 0;
        root = new bt_node(rootVal);
    }
    void add(int value){
        bt_node *insNode = new bt_node(value);
        amount += addNode(insNode, root);
    }
    void printTree(){
        std::cout << amount << " nodes in the tree" << std::endl;
        printNode(root);
    }
    private:
    int addNode(bt_node *newNode, bt_node *curRoot){ 
        if(curRoot->val == newNode->val){
            std::cout << newNode->val << " already in tree" << std::endl;
            return 0;
        }
        else if(curRoot->val < newNode->val){
            if(curRoot->left == NULL){
                curRoot->left = newNode;
            }else{
                addNode(newNode, curRoot->left);
                return 1;
            }
        }else{
            if(curRoot->right == NULL){
                curRoot->right = newNode;
            }else{
                addNode(newNode, curRoot->right);
                return 1;
            }
        }
        return 0;
    }
    void printNode(bt_node *curNode){
        if(curNode->left != NULL){
            printNode(curNode->left);
        }
        std::cout << curNode->val << std::endl;
        if(curNode->right != NULL){
            printNode(curNode->right);
        }
    }
} bt_root;
