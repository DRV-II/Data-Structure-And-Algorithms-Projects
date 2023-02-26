// A C++ program to demonstrate common Binary Heap Operations
#include<iostream>
#include<climits>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);

// A class for Min Heap
class MinHeap
{
	int *harr; // pointer to array of elements in heap
	int capacity; // maximum possible size of min heap
	int heap_size; // Current number of elements in min heap
public:
	// Constructor
	MinHeap(int capacity);

	// to heapify a subtree with the root at given index
	void MinHeapify(int );

	int parent(int i)
	{
		return (i-1)/2;
	}

	// to get index of left child of node at index i
	int left(int i)
	{
		return (2*i + 1);
	}

	// to get index of right child of node at index i
	int right(int i)
	{
		 return (2*i + 2);
	}

	// to extract the root which is the minimum element
	int pop();

	//
	// int top();

	//
	bool empty();

	//
	int size();

	// Decreases key value of key at index i to new_val
	void decreaseKey(int i, int new_val);

	// Returns the minimum key (key at root) from min heap
	int top()
	{
		 return harr[0];
	}

	// Deletes a key stored at index i
	void deleteKey(int i);

	// Inserts a new key 'k'
	void push(int k);

};

// Constructor: Builds a heap from a given array a[] of given size
MinHeap::MinHeap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

// Inserts a new key 'k'
void MinHeap::push(int k)
{
	if (heap_size == capacity)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	// First insert the new key at the end
	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	// Fix the min heap property if it is violated
	while (i != 0 && harr[parent(i)] > harr[i])
	{
	swap(&harr[i], &harr[parent(i)]);
	i = parent(i);
	}
}

// Decreases value of key at index 'i' to new_val. It is assumed that
// new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i])
	{
	swap(&harr[i], &harr[parent(i)]);
	i = parent(i);
	}
}

// Method to remove minimum element (or root) from min heap
int MinHeap::pop()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	// Store the minimum value, and remove it from heap
	int root = harr[0];
	harr[0] = harr[heap_size-1];
	heap_size--;
	MinHeapify(0);

	return root;
}

/*
int MinHeap::top()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size >= 1)
	{
		return harr[0];
	}
}
*/

bool MinHeap::empty()
{
	if (heap_size <= 0)
  {
		return true;
	}

	else
	{
		return false;
	}
}

int MinHeap::size()
{
	return heap_size;
}

// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	pop();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
		MinHeapify(smallest);
	}
}

// A utility function to swap two elements
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void showpq(MinHeap gq)
{
	MinHeap g = gq;
	while (!g.empty()) {
		cout << '\t' << g.top();
		g.pop();
	}
	cout << '\n';
}

// Driver program to test above functions
int main()
{
	MinHeap h(11);
	h.push(3);
	h.push(2);
	//h.deleteKey(1);
	h.push(15);
	h.push(5);
	h.push(4);
	h.push(45);
	cout << h.pop() << " ";
	cout << h.top() << " ";
	// h.decreaseKey(2, 1);
	cout << h.top()<<endl;

	MinHeap uno(5);
  cout<<"\n------ Caso de prueba 1 -----"<<endl;
  // Agrega elementos al final de la cola de prioridad.
  uno.push(50);
  uno.push(80);
  uno.push(10);
  uno.push(5);
  uno.push(12);

  // Imprime la cola de prioridad.
  cout << "Priority queue: ";
	showpq(uno);
  cout << "\nSize of the queue: "<< uno.size(); // Devuelve el tamaño de la cola.
  cout << "\nTop element of the queue: " << uno.top(); // Devuelve el elemento superior de la cola.
  cout << "\nThe priority queue pq is : ";
  cout << uno.pop()<<endl;
  showpq(uno);
	return 0;
}
