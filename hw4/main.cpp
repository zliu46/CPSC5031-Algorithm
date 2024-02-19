#include <iostream>
using namespace std;

int countInorderRec(struct Node*, int);
struct Node {
    int val;
    Node* left;
    Node* right;
    Node (int val) : val(val), left(nullptr), right(nullptr){}
};
int compute_levels(struct Node* root){
    if (root == nullptr) {
        return 0;
    }
    else if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    else {
        int left_level = compute_levels(root->left);
        int right_level = compute_levels(root->right);
        return max(left_level, right_level) + 1;
    }
}

int main() {
    Node tree (5);
    int level = compute_levels(&tree);
    cout << level;
    return 0;
}
int countInorder(struct Node* node) {
    return countInorderRec(node, 0);
}
int countInorderRec(struct Node* node, int count)
{
    if (node == NULL)
        return 0;

    /* first recur on left child */
    int a = countInorderRec(node->left, count) + 1;

    /* then print the data of node */
    count++;

    /* now recur on right child */
    int b = countInorderRec(node->right, count) + 1;

    count = count + a + b;
    return count;
}



