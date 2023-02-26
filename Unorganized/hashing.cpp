// CPP program to implement hashing with chaining
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int n)
  {
    // Iterating and printing the array
    for (int i = 0; i < n; i++)
    {
      cout << arr[i] << " ";
    }
  }

void printArray(vector<int> arr, int n)
  {
    // Iterating and printing the array
    for (int i = 0; i < n; i++)
    {
      cout << arr[i] << " ";
    }
  }

class Hash
{
	int BUCKET; // No. of buckets

	// Pointer to an array containing buckets
	list<int> *table;
public:
	Hash(int V); // Constructor

	// inserts a key into hash table
	void insertItem(int x);

	// deletes a key from hash table
	void deleteItem(int key);

	// hash function to map values to key
	int hashFunction(int x) {
		return (x % BUCKET);
	}

	void displayHash();
};

Hash::Hash(int b)
{
	this->BUCKET = b;
	table = new list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
	int index = hashFunction(key);
	table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
// get the hash index of key
int index = hashFunction(key);

// find the key in (index)th list
list <int> :: iterator i;
for (i = table[index].begin();
		i != table[index].end(); i++) {
	if (*i == key)
	break;
}

// if key is found in hash table, remove it
if (i != table[index].end())
	table[index].erase(i);
}

// function to display hash table
void Hash::displayHash() {
for (int i = 0; i < BUCKET; i++) {
	cout << i;
	for (auto x : table[i])
	cout << " --> " << x;
	cout << endl;
}
}

// C++ implementation of
// the Quadratic Probing
// Function to print an array
class HashCuadratic
{

private:
  int tamano; // No. of buckets
  int table[];
	//vector<int> table;

public:

  HashCuadratic(int tam) {
    // Size of the hash table
    this->tamano = tam;
	  //int hash_table[tamano];
    // Initializing the hash table
    for (int i = 0; i < tamano; i++)
    {
      //this->table[i].push_back(-1);
      this->table[i] = -1;
    }
    /*
    printArray(this->table, this->tamano); // Comprobamos que crea el arreglo
    cout<<endl;
    */
  }

  // Function to implement the
  // quadratic probing
  void hashing(int arr[], int N)
  {
    // Iterating through the array
    for (int i = 0; i < N; i++)
    {
      // Computing the hash value
      //cout<< arr[i] << " " << this->tamano;
      int hv = arr[i] % this->tamano;
      //cout<< " " << hv << endl;
      // Insert in the table if there
      // is no collision
      if (this->table[hv] == -1)
        this->table[hv] = arr[i];
      else
      {
        // If there is a collision
        // iterating through all
        // possible quadratic values
        for (int j = 0; j < this->tamano; j++)
        {
          // Computing the new hash value
          int t = (hv + j * j) % this->tamano;
          if (this->table[t] == -1)
          {
            // Break the loop after
            // inserting the value
            // in the table
            this->table[t] = arr[i];
            break;
          }
        }
      }
    }
    printArray(this->table, N);
    cout<<endl;
  }
};

// Driver program
int main()
{

  // array that contains keys to be mapped
  int a[] = {15, 11, 27, 8, 12};
  int n = sizeof(a)/sizeof(a[0]);

  // insert the keys into the hash table
  Hash h(7); // 7 is count of buckets in
        // hash table
  for (int i = 0; i < n; i++)
    h.insertItem(a[i]);

  // delete 12 from hash table
  h.deleteItem(12);

  // display the Hash table
  h.displayHash();

  //
  // Cuadratico:
  int arreglo[] = {50, 700, 76, 85, 92, 73, 101};
  int N = 7; // Numero de datos en arreglo

  int *arr = new int[N];
  /*
   for (int i = 0; i < n; ++i) {
       arr[i] = i+10;
   }
  */

  arr[0] = 50;
  arr[1] = 700;
  arr[2] = 76;
  arr[3] = 85;
  arr[4] = 92;
  arr[5] = 73;
  arr[6] = 101;

  // Size of the hash table and Initializing the hash table
  int l = 7; // Tamaño de la tabla de hash
  HashCuadratic hash1(l);
  //cout<<arr[1]<<endl;
  //cout<<arreglo[1]<<endl;
  // Quadratic probing
  //hash1.hashing(arreglo, n);

  hash1.hashing(arr, N);

  /*
  int hash_table[7];

  //
  for (int i = 0; i < L; i++)
  {
    hash_table[i] = -1;
  }
  */

  return 0;
}
