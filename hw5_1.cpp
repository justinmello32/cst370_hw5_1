#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
int main() {

    int vectorLength = 0;
    int numOfCommands = 0;
    int number;
    string results;
    cin >> vectorLength;
    vector<int> numbers(vectorLength);
    string userInput;

    for(int i = 0; i < vectorLength; i++) {
        cin >> number;
        numbers[i] = number;
    }
    //Make Heap
    make_heap(numbers.begin(), numbers.end());

    //Run user commands
    cin >> numOfCommands;

    for(int i = 0; i < numOfCommands; i++) {
        cin >> userInput;

        if(userInput == "displayMax") {
            results += to_string(numbers.front());
            results += '\n';
        }

        else if(userInput == "display") {
            for(int j = 0; j < numbers.size(); j++) {
                results += to_string(numbers[j]);
                results += " ";
            }
            results += '\n';
        }
        else if(userInput == "deleteMax") {
            numbers.erase(numbers.begin());
            make_heap(numbers.begin(),numbers.end());
        }
        else if(userInput[0] == 'i') {
            string tempString;
            cin >> tempString;
            int tempNum = stoi(tempString);
            numbers.push_back(tempNum);
            make_heap(numbers.begin(),numbers.end());
        }
        else if(userInput[0] == 'd') {
            string tempString;
            cin >> tempString;
            int tempNum = stoi(tempString);

            for(int q = 0; q < numbers.size(); q++) {
                if(numbers[q] == tempNum)
                    numbers.erase(numbers.begin() + q);
            }
            make_heap(numbers.begin(),numbers.end());
        }
        else {
            string tempString;
            cin >> tempString;
            int tempNum = stoi(tempString);

            numbers.erase(numbers.begin() + tempNum);
            cin >> tempString;
            int tempNum2 = stoi(tempString);

            numbers.insert(numbers.begin() + tempNum, tempNum2);
            make_heap(numbers.begin(),numbers.end());
        }


    }

    //Display Results
    if(is_heap(numbers.begin(),numbers.end()))
        cout << "This is a heap." << endl;
    else
        cout << "This is NOT a heap." << endl;
    cout << results;




    return 0;
}
