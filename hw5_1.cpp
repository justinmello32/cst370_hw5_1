#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//prototypes
void inputHeap(vector<int> &heap);
void print(vector<int> v);
bool isMaxHeap(vector<int> heap);
void heapify(vector<int> &heap);
void inputCommands(vector<int> &heap);
void insert(vector<int> &heap, int node_val);
void deleteNode(vector<int> &heap, int node_val);
void update(vector<int> &heap, int node_index, int new_val);
void displayMax(vector<int> heap);
void deleteMax(vector<int> &heap);

int main() {
    vector<int> heap;
    inputHeap(heap);
    if (isMaxHeap(heap)) {
        cout << "This is a heap." << endl;
    } else {
        cout << "This is NOT a heap." << endl;
        //call heapify
        heapify(heap);
    }
    //print(heap);
    // call input commands
    inputCommands(heap);
    return 0;
}

void inputHeap(vector<int> &heap) {
    int cycles;
    cin >> cycles;
    heap.resize(cycles + 1);
    int input;
    for (int x = 1; x < cycles + 1; x++) {
        cin >> input;
        heap[x] = input;
    }
}


void print(vector<int> v) {
    for (int x = 1; x < v.size(); x++) {
        cout << v[x] << " ";
    }
    cout << endl;
}

bool isMaxHeap(vector<int> heap) {
    int parent;
    int l_child;
    int r_child;
    for (int x = heap.size() / 2; x > 0; x--) {
        parent = x;
        l_child = x * 2;      // left child
        r_child = x * 2 + 1;  // right child
        if (l_child < heap.size()) {
            //check left child
            if (heap[l_child] > heap[parent]) {
                return false;
            }
        }
        if (r_child < heap.size()) {
            // check right child
            if (heap[r_child] > heap[parent]) {
                return false;
            }
        }
    }
    return true;
}


void heapify(vector<int> &heap) {
    int parent;
    int currVal;
    bool is_heap;
    int l_child;
    int r_child;

    while (!isMaxHeap(heap)) {
        for (parent = heap.size() / 2; parent > 0; parent--) {
            is_heap = false;
            l_child = 2 * parent;
            r_child = 2 * parent + 1;

            while (!is_heap && l_child < heap.size()) {
                if (l_child < heap.size()) {
                    if (heap[l_child] < heap[r_child]) {
                        l_child = r_child;  // assignes right to left
                    }
                    if (heap[parent] >= heap[l_child]) {
                        is_heap = true;
                    } else {
                        // if parent is not greater than the left child
                        swap(heap[parent], heap[l_child]);
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
    for (int x = 1; x < heap.size(); x++) {
        if (heap[x] == node_val) {
            heap[x] = heap.back();
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


void inputCommands(vector<int> &heap) {
    int num_commands;
    cin >> num_commands;

    string command;
    int node_val;
    int update_val;

    for (int x = 0; x < num_commands; x++) {
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
            print(heap);
        } else if (command == "displayMax") {
            displayMax(heap);
        } else if (command == "deleteMax") {
            deleteMax(heap);
        }
    }
}