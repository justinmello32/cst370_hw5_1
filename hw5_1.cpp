#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printHeap(vector<int> v) {
    for (int i = 1; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

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
                        leftChild = rightChild;  // assignes right to left
                    }
                    if (heap[parent] >= heap[leftChild]) {
                        isHeap = true;
                    } else {
                        // if parent is not greater than the left child
                        swap(heap[parent], heap[leftChild]);
                    }
                }
            }
        }
    }
}

void insert(vector<int> &heap, int node_val) {
    heap.push_back(node_val);
    heapify(heap);
}

void deleteNode(vector<int> &heap, int node_val) {
    for (int i = 1; i < heap.size(); i++) {
        if (heap[i] == node_val) {
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


void displayMax(vector<int> heap) {
    cout << heap[1] << endl;
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

    int num_commands;
    cin >> num_commands;

    string command;
    int node_val;
    int update_val;

    for (int i = 0; i < num_commands; i++) {
        cin >> command;


        if (command == "insert") {
            cin >> node_val;
            insert(heap, node_val);
        } else if (command == "delete") {
            cin >> node_val;
            deleteNode(heap, node_val);
        } else if (command == "update") {
            cin >> node_val >> update_val;
            update(heap, node_val, update_val);
        } else if (command == "display") {
            for (int i = 1; i < heap.size(); i++) {
                cout << heap[i] << " ";
            }
            cout << endl;
        } else if (command == "displayMax") {
            displayMax(heap);
        } else if (command == "deleteMax") {
            deleteMax(heap);
        }
    }
    return 0;
}