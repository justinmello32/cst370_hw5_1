/*
 * Title: hw5_1.cpp
 * Abstract: Program to conduct heap operations.
 * Author: Justin Mello
 * ID: 2002
 * Date: 04/13/2021
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isMaxHeap(vector<int> heap) {
    int parent;
    int leftChild;
    int rightChild;
    for (int i = heap.size() / 2; i > 0; i--) {
        parent = i;
        leftChild = i * 2;
        rightChild = i * 2 + 1;
        if (leftChild < heap.size()) {

            //Check left
            if (heap[leftChild] > heap[parent]) {
                return false;
            }
        }
        if (rightChild < heap.size()) {
            //Check right
            if (heap[rightChild] > heap[parent]) {
                return false;
            }
        }
    }
    return true;
}


void heapify(vector<int> &heap) {
    int parent;
    bool isHeap;
    int leftChild;
    int rightChild;

    while (!isMaxHeap(heap)) {
        for (parent = heap.size() / 2; parent > 0; parent--) {
            isHeap = false;
            leftChild = 2 * parent;
            rightChild = 2 * parent + 1;

            while (!isHeap && leftChild < heap.size()) {
                if (leftChild < heap.size()) {
                    if (heap[leftChild] < heap[rightChild]) {
                        leftChild = rightChild;
                    }
                    if (heap[parent] >= heap[leftChild]) {
                        isHeap = true;
                    } else {
                        swap(heap[parent], heap[leftChild]);
                    }
                }
            }
        }
    }
}

void insert(vector<int> &heap, int nodeValue) {
    heap.push_back(nodeValue);
    heapify(heap);
}

void deleteN(vector<int> &heap, int nodeValue) {
    for (int i = 1; i < heap.size(); i++) {
        if (heap[i] == nodeValue) {
            heap[i] = heap.back();
            heap.pop_back();
            heapify(heap);
            break;
        }
    }
}

void update(vector<int> &heap, int node_index, int new_val) {
    heap[node_index] = new_val;
    heapify(heap);
}

void deleteMax(vector<int> &heap) {
    heap[1] = heap.back();
    heap.pop_back();
    heapify(heap);
}

int main() {

    vector<int> heap;
    int rounds;
    cin >> rounds;
    heap.resize(rounds + 1);
    int input;
    for (int i = 1; i < rounds + 1; i++) {
        cin >> input;
        heap[i] = input;
    }

    if (isMaxHeap(heap)) {
        cout << "This is a heap." << endl;
    } else {
        cout << "This is NOT a heap." << endl;
        //call heapify
        heapify(heap);
    }

    int numCommands;
    cin >> numCommands;

    string command;
    int nodeValue;
    int updateValue;

    for (int i = 0; i < numCommands; i++) {
        cin >> command;


        if (command == "insert") {
            cin >> nodeValue;
            insert(heap, nodeValue);
        } else if (command == "delete") {
            cin >> nodeValue;
            deleteN(heap, nodeValue);
        } else if (command == "update") {
            cin >> nodeValue >> updateValue;
            update(heap, nodeValue, updateValue);
        } else if (command == "display") {
            for (int i = 1; i < heap.size(); i++) {
                cout << heap[i] << " ";
            }
            cout << endl;
        } else if (command == "displayMax") {
            cout << heap[1] << endl;
        } else if (command == "deleteMax") {
            deleteMax(heap);
        }
    }
    return 0;
}