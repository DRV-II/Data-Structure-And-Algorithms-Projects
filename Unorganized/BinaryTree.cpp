#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

template <class T> class Node {
    private:
        T data; // The object information
        Node* left; // Pointer to the next node element
        Node* right;
    public:
        Node(){
            this->left = NULL;
			      this->right = NULL;
        }

        Node(T new_data, Node* left, Node* right){
            this->data = new_data;
            this->left = left;
			      this->right = right;
        }

        void set_right(Node* right){
            this->right = right;
        }

        void set_left(Node* left){
            this->left = left;
        }

        Node* get_left(){
          return this->left;
        }

        Node* get_right(){
          return this->right;
        }

        void set_data(T new_data){
          this->data = new_data;
        }

        T get_data(){
            return this->data;
        }
};

template <class T> class Tree{
  public:
    Node<T>* root;

    Tree(){
      root = NULL;
    }

    void add(T data, Node<T>* aux){
      if(this->root == NULL){
        Node<T>* temp = new Node<T>();
        temp->set_data(data);
        this->root = temp;
      } else {
        Node<T>* current = aux;
        if (data < current->get_data()) {
          Node<T>* temp = new Node<T>();
          temp->set_data(data);
          if (!current->get_left()) {
            current->set_left(temp);
          } else {
            current = current->get_left();
            add(data, current);
          }
        }else{
          Node<T>* temp = new Node<T>();
          temp->set_data(data);
          if (!current->get_right()) {
            current->set_right(temp);
          } else {
            current = current->get_right();
            add(data, current);
          }
        }
      }
    }

    void eliminar(Node<T>* current, T value){
      if (root->get_data() == value) {
        root->set_left(NULL);
        root->set_right(NULL);
        root = NULL;
      }
      if (current->get_left() == value) {
        current->set_left(NULL);
      }
      if (current->get_right() == value) {
        current->set_right(NULL);
      }

      if (current->get_left()) {
        navigate(current->get_left());
      }

      if (current->get_right()){
        navigate(current->get_right());
      }
    }

    void imprimir(Node<T>* current) {
      cout<<current->get_data()<<endl;

      if (current->get_left()) {
        imprimir(current->get_left());
      }

      if (current->get_right()){
        imprimir(current->get_right());
      }
    }
};

int main() {
  srand(time(NULL));
  Tree<int> tree;
  tree.add(10, tree.root);
  tree.add(4, tree.root);
  tree.add(5, tree.root);
  tree.add(7, tree.root);
  tree.add(90, tree.root);
  tree.add(115, tree.root);
  tree.add(23, tree.root);
  tree.imprimir(tree.root);
  return 0;
}
