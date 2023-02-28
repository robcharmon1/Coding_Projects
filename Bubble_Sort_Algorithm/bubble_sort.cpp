#include <iostream>
#include <vector>
using namespace std;
// Program to output input integers from highest to lowest
// by: Robert Harmon

// function to sort input integers from high to low and output result
void SortVector(vector<int>& myVec) {

    int i;   // variable for number of bubble sorts
    int j;   // variable for number of swaps in each sort
    int tmp; // temp variable for exchanging values in loops
    int loops = myVec.size() - 1; // variable for number of iterations in bubble sort (don't need to sort with last index)
    // last item in vector is swapped with second to last index, it doesn't need it's own swap

    // bubble sort algorithm to sort vector argument from high to low
    // always runs the max number of iterations to move an item from one end of vector to other end

    for (i = 0; i < loops; ++i) { // if bubble sort happens vector size -1 times, largest value could move from far right to far left side

        for (j = 0; j < loops; ++j) { // sort each pair of items in vector, putting largest on left side

            if (myVec.at(j) < myVec.at(j + 1)) { // for each pair of adjacent items, swap if largest is not on left
                tmp = myVec.at(j); // temp value for storing a value to be swapped
                myVec.at(j) = myVec.at(j + 1);
                myVec.at(j + 1) = tmp;
            }
        }
    }

}

int main() {

    int vectorSize;    // declare variable for vector size

    cout << "Input number of items to be sorted: ";
    cin >> vectorSize; // get size of vector from user input

    vector<int> myVec(vectorSize); // declare vector to hold integer inputs from user

    // loop to get inputs from user to populate myVec vector
    for (int i = 0; i < vectorSize; ++i) {
        cout << "Input a whole number: ";
        cin >> myVec.at(i);
    }

    // call sorting function and pass vector as argrument
    SortVector(myVec);
    cout << "Sorted inputs from high to low: ";

    // output each vector item
    for (int i = 0; i < vectorSize; ++i) {
        cout << myVec.at(i) << ",";
    }
    cout << endl;

    return 0;
}
