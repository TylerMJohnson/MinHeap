#include "heap.h"
#include "util.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

string filename = "HEAPinput.txt";

void readFileAndBuildHeap(HEAP &heap) {
	string line;
	ifstream file(filename.c_str());
	Element *element;
	if (file.is_open()){
		int size = 0;
		int count = 0;
		int number;
		while (getline(file, line)){
			if ((count < 1)) {
				size = atoi(line.c_str());
				if (size != 0) {
					element = new Element[size];
				}
			} else {
				if (size != 0) {
					number = atoi(line.c_str());
					//for(int i = 0; i < size; i++){
						Element temp;
						temp.key = number;
						cout << number << '\n';
						element[count - 1] = temp;
					//}
					if (heap.getCapacity() < count + heap.getSize()) {
						printf("Heap is full \n");
					}
				}
			}
			count++;
			//cout << line << '\n';
		}
		BuildHeap(heap, element, size);
		file.close();
	}
}


int nextCommand(int& i, int& v, int& f) {
	char c;
	while (1) {
		scanf("%c", &c);
		if (c == 'S' || c == 's') {
			break;
		}
		if (c == ' ' || c == '\t' || c == '\n') {
			continue;
		}
		if (c == 'C' || c == 'c') {
			printf("Please enter capacity \n");
			scanf("%d", &i);
			break;
		}
		if (c == 'R' || c == 'r') {
			break;
		}
		if (c == 'W' || c == 'w') {
			break;
		}
		if (c == 'I' || c == 'i') {
			printf("Please enter in flag value \n");
			scanf("%d", &f);
			printf("Please enter in a key you would like to insert \n");
			scanf("%d", &i);
			break;
		}
		if (c == 'D' || c == 'd') {
			printf("Please enter in flag value \n");
			scanf("%d", &f);
			break;
		}
		if (c == 'K' || c == 'k') {
			//DecreaseKey(HEAP &heap, int flag, int element, int key)
			printf("Please enter in flag value \n");
			scanf("%d", &i);
			printf("Please enter which element \n");
			scanf("%d", &v);
			printf("Please enter the new value \n");
			scanf("%d", &f);
			break;
		}
		printf("Invalid Command\n");
	}
	return c;
}
