#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {

    int vectorLength = 0;
    int numOfCommands = 0;
    int number;
    cin >> vectorLength;
    vector<int> numbers[vectorLength];

    for(int i = 0; i < vectorLength; i++) {
        cin >> number;
        numbers->push_back(number);
    }
    cin >> numOfCommands;

    //Make Heap
    make_heap(numbers->begin(), numbers->end());






    cout << "Max heap is " << numbers->front();



    return 0;
}
