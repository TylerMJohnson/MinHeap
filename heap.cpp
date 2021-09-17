#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "heap.h"

using namespace std;

HEAP::HEAP() {
}

HEAP::HEAP(int cap, int s) {
	capacity = cap;
	size = s;
	element = new Element[cap];
}

HEAP Initialize(int cap) {
	HEAP return_heap(cap, 0);
	return return_heap;
}

void BuildHeap(HEAP &heap, Element a[], int size) {
	int initialSize = heap.getSize();
	for (int index = initialSize; index < size + initialSize && index < heap.getCapacity(); index++) {
		if (index > heap.getCapacity()) {
			cout << "ERROR";
		}
		InsertElement(heap, a[index - initialSize]);
	}
	for (int i = floor(heap.getSize() / 2); i >= 1; i--) {
		Heapify(heap, i);
	}
}

void InsertElement(HEAP &heap, Element element){
	heap.setSize(heap.getSize() + 1);
	heap.setElement(heap.getSize(), element);
}

void Insert(HEAP &heap, int flag, int key) {
	if (flag == 2) {
		printHeap(heap);
	}
	Element element;
	element.key = key;
	
	InsertElement(heap, element);
	
	//linear time?
	for (int i = floor(heap.getSize() / 2); i >= 1; i--) {
		Heapify(heap, i);
	}
	if (flag == 2) {
		printHeap(heap);
	}
}

int DeleteMin(HEAP &heap, int flag) {
	if (flag == 2) {
		printHeap(heap);
	}
	Element element = heap.getElement(1);
	heap.setElement(1, heap.getElement(heap.getSize()));
	heap.setSize(heap.getSize() - 1);
	Heapify(heap, 1);
	if (flag == 2) {
		printHeap(heap);
	}
	return element.key;
}


void DecreaseKey(HEAP &heap, int flag, int element, int key) {
	if (heap.getElement(element).key <= key) {
		return;
	}
	if (flag == 2) {
		printHeap(heap);
	}
	heap.setElementKey(element, key);
	while (element > 1 && heap.getParentElement(element).key > key) {
		heap.swapWithParent(element);
		element = heap.getParent(element);
	}
	if (flag == 2) {
		printHeap(heap);
	}
}

void printHeap(HEAP heap) {
	cout << heap.getSize() << "\n";
	for (int i = 1; i <= heap.getSize(); i++) {
		cout << heap.getElement(i).key << "\n";
	}
	//proceeded by capacity as instructed
	cout << heap.getCapacity() << "\n";
}

void Heapify(HEAP &heap, int element) {
	int currentKey = heap.getElement(element).key;
	int leftNode = heap.getLeftChild(element);
	int rightNode = heap.getRightChild(element);
	int smallest;
	//new method according to slides from lecture
	if(leftNode <= heap.getSize()){
		int leftkey = heap.getLeftChildElement(element).key;
		if(leftkey < currentKey){
			smallest = leftNode;
		}
	} else {
		smallest = element;
	}
	
	if(rightNode <= heap.getSize()){
		int rightKey = heap.getRightChildElement(element).key;
		if(rightKey < heap.getElement(smallest).key){
			smallest = rightNode;
		}
	}
	
	if(smallest != element){
		Element smaller = heap.getElement(smallest);
        heap.setElement(smallest, heap.getElement(element));
        heap.setElement(element, smaller);
        Heapify(heap, smallest);	
	}
	
	//if (!heap.isChild(element)) {
	//	int leftKey = heap.getLeftChildElement(element).key;
	//	int rightKey = heap.getRightChildElement(element).key;
	//	if ((currentKey > leftKey) || (currentKey > rightKey)){
	//		if (leftKey < rightKey) {
	//			SwapElement(heap, element, leftNode);
	//			Heapify(heap, leftNode);
	//		} else {
	//			SwapElement(heap, element, rightNode);
	//			Heapify(heap, rightNode);
	//		}
	//	}
	///}
}

void SwapElement(HEAP &heap, int first, int second) {
	Element first_element = heap.getElement(first);
	heap.setElement(first, heap.getElement(second));
	heap.setElement(second, first_element);
}