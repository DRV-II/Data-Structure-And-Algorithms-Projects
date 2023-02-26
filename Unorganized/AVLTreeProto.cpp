#include<iostream>
using namespace std;

/*
template <class T> class Node{
  public:
    T data;
    //int key;
    //int height;
    Node* left;
    Node* right;

    Node(T new_data, int key){
      this->data = new_data;
      this->key = key;
      this->height = 0;
      this->left = NULL;
      this->right = NULL;
    }

};
*/

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}*r;

class AVL
{
  public:
    /*
    avl_tree() {
        r = NULL;
    }

    AVL(Node* root){
      this->root = root;
    } */

    AVL(){
      r = NULL;
    }

    int height(Node* node) {
      int h = 0;
      if (node != NULL) {
          int l_height = height(node->left);
          int r_height = height(node->right);
          int max_height = max(l_height, r_height);
          h = max_height + 1;
      }
      return h;
    }

    int difference(Node* node) {
      int l_height = height(node->left);
      int r_height = height(node->right);
      int b_factor = l_height - r_height;
      return b_factor;
    }

    Node* rr_rotat(Node* parent) {
      Node* node;
      node = parent->right;
      parent->right = node->left;
      node->left = parent;
      cout << "Right Rotation" << endl;
      return node;
    }

    Node* ll_rotat(Node* parent) {
      Node* node;
      node = parent->left;
      parent->left = node->right;
      node->right = parent;
      cout << "Left Rotation" << endl;
      return node;
    }
    Node* lr_rotat(Node* parent) {
        Node* node;
        node = parent->left;
        parent->left = rr_rotat(node);
        cout << "Left-Right Rotation" << endl;
        return ll_rotat(parent);
    }
    Node* rl_rotat(Node* parent) {
        Node* node;
        node = parent->right;
        parent->right = ll_rotat(node);
        cout << "Right-Left Rotation" <<endl;
        return rr_rotat(parent);
    }
    /*
    int find_max(int a, int b){
      if(a>b){
        return a;
      }else{
        return b;
      }
    }
    */
    /*
    int find_height(Node* current){
      if(!current){
        return -1;
      }
      int height = find_max(find_height(current->left), find_height(current->right)) + 1;
      current->height = height;
      return height;
    }
    */
    /*
    int getBalance(Node* current){
      if (current == NULL){
        return 0;
      }
      else{
        return height(current->left) - height(current->right);
      }
    }
    */

    Node* balance(Node* node) {
    int bal_factor = difference(node);
    if (bal_factor > 1) {
        if (difference(node->left) > 0)
            node = ll_rotat(node);
        else
            node = lr_rotat(node);
    }
    else if (bal_factor < -1) {
        if (difference(node->right) > 0)
            node = rl_rotat(node);
        else
            node = rr_rotat(node);
    }
    return node;
    }

    Node* insert(Node* r, int k) {
    if (r == NULL) {
        r = new Node;
        r->data = k;
        r->left = NULL;
        r->right = NULL;
        return r;
    }
    else if (k < r->data) {
        r->left = insert(r->left, k);
        r = balance(r);
    }
    else if (k >= r->data) {
        r->right = insert(r->right, k);
        r = balance(r);
    } return r;
    }


/*
    void insert(T valor)
    {
      root = insert(root, valor);
    }

    int size(Node* node)
    {
        if (node == NULL)
            return 0;
        else
            return(size(node->left) + 1 + size(node->right));
    }
*/

   Node* deleteNode(Node* root, int key)
   {
    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller
    // than the root's key, then it lies
    // in left subtree
    if ( key < root->key )
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater
    // than the root's key, then it lies
    // in right subtree
    else if( key > root->key )
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then
    // This is the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) ||
            (root->right == NULL) )
        {
            Node*temp = root->left ?
                         root->left :
                         root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
            *root = *temp; // Copy the contents of
                           // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's
            // data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right,
                                     temp->key);
        }
    }

    // If the tree had only one node
    // then return
    if (root == NULL)
    return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF
    // THIS NODE (to check whether this
    // node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced,
    // then there are 4 cases

    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
    }

   /*void insert(Node * current_node, Node *node_insert){
      // Go to the next node according to the rules;
      Node * next_node = current_node->left;
      bool is_left = true;
      if(node_insert->key > current_node->key){
        next_node = current_node->right;
        is_left = false;
      }else if(node_insert->key < current_node->key){

      }
      /*if(next_node){
        // If exist the next node then, we go for the next
        this->insert(next_node, node_insert);
      }
      else if(is_left){
        // If the node doesn't exist and the node is in the left then we insert in the left side
        current_node->left = node_insert;
      }
      else{
        // If the node doesn't exist and the node is in the left then we insert in the left side
        current_node->right = node_insert;
      }

      int balance = getBalance(this -> current_node);

    }
}*/

};
 /*

 int size(Node* node)
 {
     if (node == NULL)
         return 0;
     else
         return(size(node->left) + 1 + size(node->right));
 }
    void preOrder(Node*root)
    {
        if(root != NULL)
        {
            cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    /*void inorder(Node* current_node){
      if(current_node) {
          inorder(current_node->left);
          cout << current_node->key << " ";
          inorder(current_node->right);
      }

      if(this->root == current_node){
          cout << endl;
      }
    }*/


//Sobrecarga para cuando está vacío
    /*
    void insert(T data, int key){
      Node *node_insert = new Node(data, key);
      if (this->root){
        this->insert(this->root, node_insert);
      }
      else{
        // Insert the first node, if root is NULL.
        this->root = node_insert;
      }

      //Terminó la inserción. Proceder a balancear
      find_height(this->root);

    }*/

int main()
{    //int c, i;
    int i;
    AVL avl;
    r = avl.insert(r, 3);
    r = avl.insert(r, 6);
    //r = avl.insert(r, 7);
    r = avl.insert(r, 5);
    //r = avl.insert(r, 9);
    cin >> i;

    return 0;
}

    /*Node *root = NULL;

    Constructing tree given in
    the above figure
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);*/

    /* The constructed AVL Tree would be
                30
            / \
            20 40
            / \ \
        10 25 50

    cout << "\nPreorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);

    root = insert(root, 8);
    cout<<"\nPreorder traversal of the modified Splay tree is \n";
    preOrder(root);

    root = deleteNode(root, 10);
    cout << "\nPreorder traversal after"
         << " deletion of 10 \n";
    preOrder(root);

    cout << "\nSize of the tree is " << size(root);*/
