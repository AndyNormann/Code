int height(node * root)
{
    if (root == NULL) {
        return -1;
    }

    int left = height(root->left);
    int right = height(root->right);

    if (left > right) {
        return left + 1;
    }else {
        return right + 1;
    }
}
  
