#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include "heap.h"
#include "util.h"

int main(){
	HEAP heap;
	bool created = false;
	char c;
	int i, v, f;
	while (1) {
		c = nextCommand(i, v, f);
		switch (c) {
			case 's':
			case 'S': printf("COMMAND: %c.\n", c); 
				exit(0);
				break;

			case 'c':
			case 'C': printf("COMMAND: %c %d.\n", c, i);
				if (!created) {
					if (i > 0) {
						heap = Initialize(i);
						created = true;
						printf("Created heap. \n");
					}
				} else {
					printf("Heap already created \n");
				}
				break;

			case 'r':
			case 'R': printf("COMMAND: %c.\n", c);
				if (created) {
					readFileAndBuildHeap(heap);
				}
				break;
				
			case 'w':
			case 'W': printf("COMMAND: %c.\n", c);
				if (created) {
					printHeap(heap);
				} else {
					printf("Create or load a heap first! \n");	
				}
				break;

			case 'i':
			case 'I': printf("COMMAND: %c %d %d \n", c, f, i);
				if (created) {
					if (heap.getSize() < heap.getCapacity()) {
						Insert(heap, f, i);
					} else {
						printf("Not enough room! \n");	
					}
				} else {
					printf("Create or load a heap first! \n");	
				}
				break;

			case 'd':
			case 'D': printf("COMMAND: %c.\n", c);
				if (created) {
					if (heap.getSize() <= 0) {
						printf("Heap is already size 0 \n");
						break;
					} else {
						DeleteMin(heap, f);
					}
				} else {
					printf("Create or load a heap first! \n");	
				}
				break;

			case 'k':
			case 'K': printf("COMMAND: %c %d %d %d.\n", c, i, v, f); 
				if (created) {
					if (i > heap.getSize()) {
						printf("Element is not in the size of the heap. \n");
					}
					if (v > heap.getElement(i).key) {
						//DecreaseKey(HEAP &heap, int flag, int element, int key)
						DecreaseKey(heap, i, v, f);
					} else {
						printf("v =< key");
					}
				} else {
					printf("Create or load a heap first! \n");	
				}
				break;

			default:
				break;
		}
	}
    //std::cout << "Hello World!\n"; 
}