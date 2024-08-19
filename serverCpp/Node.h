// C++ program to insert a node in AVL tree 
using namespace std;

// An AVL tree node 
template <typename T>
struct Node {
    T val;
    Node<T>* left;
    Node<T>* right;
    int height;

    Node<T>(T v):val(v) {
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

// A utility function to 
// get the height of the tree 
template <typename T>
int height(Node<T>* N) {
    if (N == nullptr)
        return 0;
    return N->height;
}

// A utility function to right 
// rotate subtree rooted with y 
template <typename T>
Node<T>* rightRotate(Node<T>* y) {
    Node<T>* x = y->left;
    Node<T>* T2 = x->right;

    // Perform rotation 
    x->right = y;
    y->left = T2;

    // Update heights 
    y->height = 1 + max(height(y->left),
        height(y->right));
    x->height = 1 + max(height(x->left),
        height(x->right));

    // Return new root 
    return x;
}

// A utility function to left rotate 
// subtree rooted with x 
template <typename T>
Node<T>* leftRotate(Node<T>* x) {
    Node<T>* y = x->right;
    Node<T>* T2 = y->left;

    // Perform rotation 
    y->left = x;
    x->right = T2;

    // Update heights 
    x->height = 1 + max(height(x->left),
        height(x->right));
    y->height = 1 + max(height(y->left),
        height(y->right));

    // Return new root 
    return y;
}

// Get balance factor of node N 
template <typename T>
int getBalance(Node<T>* N) {
    if (N == nullptr)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a val in 
// the subtree rooted with node 
template <typename T>
Node<T>* insert(Node<T>* node, T val) {

    // Perform the normal BST insertion
    if (node == nullptr)
        return new Node<T>(val);

    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);
    else // Equal vals are not allowed in BST 
        return node;

    // Update height of this ancestor node 
    node->height = 1 + max(height(node->left),
        height(node->right));

    // Get the balance factor of this ancestor node 
    int balance = getBalance(node);

    // If this node becomes unbalanced, 
    // then there are 4 cases 

    // Left Left Case 
    if (balance > 1 && val < node->left->val)
        return rightRotate(node);

    // Right Right Case 
    if (balance < -1 && val > node->right->val)
        return leftRotate(node);

    // Left Right Case 
    if (balance > 1 && val > node->left->val) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case 
    if (balance < -1 && val < node->right->val) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer 
    return node;
}

// A utility function to print 
// preorder traversal of the tree 
template <typename T>
void preOrder(Node<T>* root) {
    //if (root != nullptr) {
    //    cout << root->val << " ";
    //    preOrder(root->left);
    //    preOrder(root->right);
    //}
}
