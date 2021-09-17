#include <cmath>
#include <climits>

using namespace std;

struct Element{
	int key;
};

class HEAP {
	public:
		HEAP();
		HEAP(int, int);

		int getSize() {
			return size;
		}

		void setSize(int n) { 
			size = n; 
		}

		int getCapacity() { 
			return capacity;
		}

		Element getElement(int index) {
			return element[(index - 1)];
		}

		void setElementKey(int node, int key) {
			this->element[(node - 1)].key = key;
		}

		void setElement(int node, Element i_element) {
			this->element[(node - 1)] = i_element;
		}

		int getParent(int node){
			return floor(node / 2);
		}

		Element getParentElement(int node){
			return (this->getElement(this->getParent(node)));
		}

		Element getRightChildElement(int node){
			return this->getElement((2 * node) + 1);
		}

		int getRightChild(int node){
			if (2 * node + 1 <= this->size) {
				return node * 2 + 1;
			} else {
				return INT_MAX;
			}
		}

		Element getLeftChildElement(int node){
			return this->getElement(2 * node);
		}

		int getLeftChild(int node){
			if (node * 2 <= this->getSize()) {
				return node * 2;
			} else {
				return INT_MAX;
			}
		}

		bool twoChildren(int node) {
			if (this->size >= this->getParent(node) * 2 + 1){
				return true;
			} else {
				return false;
			}
		}

		bool isElement(int node){
			if (node <= this->size) {
				return true;
			} else {
				return false;
			}
		}

		void swapWithParent(int node){
			Element parent = this->getParentElement(node);
			this->setElement(this->getParent(node), this->getElement(node));
			this->setElement(node, parent);
			return;
		}

		bool isChild(int pos) {
			if (pos >= (size / 2) && pos <= size) {
				return true;
			}
			return false;
		}

	private:
		int capacity;
		int size;
		Element *element;
};

HEAP Initialize(int);
void BuildHeap(HEAP&, Element[], int);
void InsertElement(HEAP&, Element);
void Insert(HEAP&, int, int);
int DeleteMin(HEAP&, int);
void DecreaseKey(HEAP&, int, int, int);
void printHeap(HEAP);
void Heapify(HEAP&, int);
void SwapElement(HEAP&, int, int);
