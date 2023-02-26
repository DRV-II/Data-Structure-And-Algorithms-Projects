#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

/*
https://parzibyte.me/blog
*/
// 3319424004
// 3311382311
// 3221533062


/*template <class T> class Node {
    public:
        T mes; // The object information
        T dia;
        T hora;
        T ip;
        T razon;
        Node* next; // Pointer to the next node element
        Node* previous;

        void set_mes(T new_data){
            this->mes = new_data;
        }

        void set_dia(T new_data){
            this->dia = new_data;
        }

        void set_hora(T new_data){
            this->hora = new_data;
        }

        void set_ip(T new_data){
            this->ip = new_data;
        }

        void set_razon(T new_data){
            this->razon = new_data;
        }

        void set_next(Node *next_node){
            this->next = next_node;
        }

        void set_previous(Node *previous_node){
            this->previous = previous_node;
        }
};*/

/*template <class T> class CustomLinkedList{
    Node<T> *head;

    public:
        CustomLinkedList(){
            head = NULL;
        }

        ~CustomLinkedList(){

        }

        // Method adds info to the end of the list
        void add_end(T info){
            if(head == NULL){ //if our list is currently empty
                head = new Node<T>; //Create new node of type T
                head->set_data(info);
            }
            else{ //if not empty add to the end and move the tail
                Node<T>* temp = new Node<T>;
                temp->set_data(info);
                temp->set_next(NULL);

                Node<T>* current_node = this->head;
                while (current_node->next != NULL){
                    current_node = current_node->next;
                }
                temp->set_previous(current_node);
                current_node->next = temp;
            }
        }

        // Method adds info to the begining of the list
        void add_begin(T info){
            Node<T>* temp = new Node<T>;
            temp->set_data(info);
            temp->set_next(head);
            temp->set_previous(NULL);
            this->head = temp;
        }

        // Method adds info to the begining of the list
        void add_after_node(T value_insert, T value_after){
            Node<T>* temp = head;
            while (temp != NULL && temp->data != value_after){
                temp = temp->next;
            }
            if (!temp) {
                return;
            }
            Node <T>* nodito= new Node<T>;
            nodito -> set_data(value_insert);
            nodito -> set_previous(temp);

            if (temp->next != NULL) {
              nodito -> set_next(temp->next);
              nodito -> next -> set_previous(nodito);
            }
            else {
              nodito -> set_next(NULL);
            }
            temp -> set_next(nodito);
        }


        void delete_node(T value){
            if(!this->head){
                // Empty linked list, no values to delete
                return;
            }

            // Check if the node to delete is the head
            if(this->head->data == value){
                this->head = this->head->next;
                head->set_previous(NULL);
                return;
            }

            Node<T>* current_node = this->head;
            // Search for the node to delete
            while ( current_node && current_node->next->data != value){
                current_node = current_node->next;
            }

            // current node is empty the node wasn't found
            if(!current_node){
                return;
            }

            Node<T>* node_to_delete = current_node->next;

            current_node->next = node_to_delete->next;

            if (node_to_delete->next != NULL) {
              current_node->next->set_previous(current_node);
            }
            delete node_to_delete;
        }

        void print_list(){
            Node<T>* current_node = this->head;
            while (current_node != NULL){
                cout << current_node ->data << " -> ";

                current_node = current_node->next;
            }
            cout << endl;
        }


};*/

void leerArchivo(string nombreArchivo,vector<string> &bitacora){
  ifstream archivo(nombreArchivo.c_str());
  string linea;
  // Obtener línea de archivo, y almacenar contenido en "linea"
  while (getline(archivo, linea)) {
      // Lo vamos imprimiendo
      bitacora.push_back(linea);
    }
}

vector<vector<string>> separar(vector<string> &bitacora) {
  vector<vector<string>> bitacoraAcomodada;
  string spaceDelimiter = " ";
  size_t pos = 0;
  std::string token;
  for (int i=0; i < bitacora.size(); i++) {
    vector<string> vectorTemp{};
    string s = bitacora[i];
    while ((pos = s.find(spaceDelimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        vectorTemp.push_back(token);
        s.erase(0, pos + spaceDelimiter.length());
    }
    bitacoraAcomodada.push_back(vectorTemp);
  }
  cout<<bitacoraAcomodada[4][3]<<endl;
  return bitacoraAcomodada;
}

vector<vector<string>> convertirNumeros(vector<vector<string>> vector) {
  for (int i=0; i < vector.size(); i++) {
    if (vector[i][0]=="Jan") {
      vector[i][0] = "100";
    }
    else if (vector[i][0]=="Feb") {
      vector[i][0] = "200";
    }
    else if (vector[i][0]=="Mar") {
      vector[i][0] = "300";
    }
    else if (vector[i][0]=="Apr") {
      vector[i][0] = "400";
    }
    else if (vector[i][0]=="May") {
      vector[i][0] = "500";
    }
    else if (vector[i][0]=="Jun") {
      vector[i][0] = "600";
    }
    else if (vector[i][0]=="Jul") {
      vector[i][0] = "700";
    }
    else if (vector[i][0]=="Aug") {
      vector[i][0] = "800";
    }
    else if (vector[i][0]=="Sep") {
      vector[i][0] = "900";
    }
    else if (vector[i][0]=="Oct") {
      vector[i][0] = "1000";
    }
    else if (vector[i][0]=="Nov") {
      vector[i][0] = "1100";
    }
    else if (vector[i][0]=="Dec") {
      vector[i][0] = "1200";
    }
    else {
      cout<<"No amigo"<<endl;
    }
  }
  return vector;
}

vector<vector<string>> ordenBurbuja(vector<vector<string>> a) {
    int n=a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if((stoi(a[j][0])+stoi(a[j][1]))>(stoi(a[j+1][0])+stoi(a[j+1][1]))) {
                vector<string> tmp_value=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp_value;
            }
        }
    }
    return a;
}

void printVector(vector<vector<string>> a) {
  int n = a.size();
  for (int i = 0; i<n; i++) {
    cout<<a[i][0]<<", ";
  }
  cout<<endl;
}

/*vector<string> words{};
/*
size_t pos = 0;
for(int j = 0;j<bitacora.size();j++)
  for (int i = 0; i < 4;i++){
      pos = text.find(space_delimiter)
      words.push_back(text.substr(0, pos));
      text.erase(0, pos + space_delimiter.length());
  }
      words.push_back(text.substr(pos+1,size(bitacora(j))));

for (const auto &str : words) {
    cout << str << endl;
}*/


int main() {
  //CustomLinkedList<int> bitacoraAcomodada;
  vector<string> bitacora;
  vector<vector<string>> vectorConvertido;
  vector<vector<string>> vectorSeparado;
  vector<vector<string>> vectorOrdenado;
  leerArchivo("bitacora.txt", bitacora);
  cout<<bitacora[2]<<endl;
  vectorSeparado=separar(bitacora);
  vectorConvertido=convertirNumeros(vectorSeparado);
  cout<<vectorConvertido[0][0]<<endl;
  vectorOrdenado = ordenBurbuja(vectorConvertido);
  printVector(vectorOrdenado);
}
