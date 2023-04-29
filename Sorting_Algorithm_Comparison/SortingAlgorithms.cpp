// Program to Compare Different Sorting Algorithms
// By: Robert Harmon
// ===============================================================================================================

#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>
#include<list>
#include<iomanip>
using namespace std;

// ===============================================================================================================

// Insertion sort algorithm
void InsertionSort(vector<int>& numbers) {
	int i;
	int j;
	int temp;

	// loop for second number in list to last
	for (i = 1; i < numbers.size(); ++i) {
		j = i;
		// while index > 0 and number at index < number at index - 1, swap numbers
		// basically, for each item, keep swapping it with item to left until it is greater than item to left
		while ((j > 0) && (numbers.at(j) < numbers.at(j - 1))) {
			temp = numbers.at(j);
			numbers.at(j) = numbers.at(j - 1);
			numbers.at(j - 1) = temp;
			--j;
		}
	}
}

// Selection sort algorithm
void SelectionSort(vector<int>& numbers) {
	int i;
	int j;
	int indexSmallest;
	int temp;

	// loop through all items in list
	for (i = 0; i < numbers.size() - 1; ++i) {
		indexSmallest = i;

		// for item after i to end of list, if item j < item i, smallest item left is at j
		for (j = i + 1; j < numbers.size(); ++j) {
			if (numbers.at(j) < numbers.at(indexSmallest)) {
				indexSmallest = j;
			}
		}

		// swap items at i and index of smallest remaining
		temp = numbers.at(i);
		numbers.at(i) = numbers.at(indexSmallest);
		numbers.at(indexSmallest) = temp;
	}
}

void ShellSort(vector<int>& numbers, int n) {
	int gap, i, j;

	// for gap = half of list size, divided by 2 until 1
	for (gap = n / 2; gap > 0; gap /= 2) {
		
		// for i = gap to end of list
		// results in a gap number of sub lists analyzed
		for (i = gap; i < n; ++i) {

			int temp = numbers.at(i);

			// for j = i while j >= gap and item at j - gap > temp, reducing j by gap
			// basically swap j with j - gap if it's smaller
			for (j = i; j >= gap && numbers.at(j - gap) > temp; j -= gap) {
				numbers.at(j) = numbers.at(j - gap);
			}
			// this will either set item at j to item at j - gap if swap occurred or set item at j to itself otherwise
			numbers.at(j) = temp;
		}
	}
}

// function to partition vector for quick sort
int partition(vector<int>& numbers, int begin, int end) {
	int low = begin;
	int high = end;
	int temp;
	bool done = false;

	// find midpoint of vector to be used as pivot point
	int midpoint = begin + (end - begin) / 2;
	int pivot = numbers.at(midpoint);
	
	// while low index < high index
	while (!done) {

		// while item at low index < pivot, increment low
		while (numbers.at(low) < pivot) {
			low += 1;
		}

		// while item at high index > pivot, decrement high
		while (pivot < numbers.at(high)) {
			high -= 1;
		}


		// if low >= high, partitioning is complete
		if (low >= high) {
			done = true;
		}
		else {
			temp = numbers.at(low);
			numbers.at(low) = numbers.at(high);
			numbers.at(high) = temp;

			low++;
			high--;
		}
	}
	
	return high;
}

void QuickSort(vector<int>& numbers, int lowIndex, int highIndex) {

	// base case: if partition size is 1 or 0 elements, then partition is already sorted
	if (lowIndex >= highIndex) {
		return;
	}

	// Partition data in list
	int lowEndIndex = partition(numbers, lowIndex, highIndex);
	// Recursively call quick sort, first on left half of list (<= pivot), then on right half (>= pivot)
	QuickSort(numbers, lowIndex, lowEndIndex);
	QuickSort(numbers, lowEndIndex + 1, highIndex);
	
}

// Merge function to be used for MergeSort
// Puts the items from the two partitions into a temp vector in order, 
// then replaces original vector with temp vector for indices considered
void Merge(vector<int>& numbers, int begin, int mid, int end) {
	int mergeSize = end - begin + 1;
	int mergedVectorIndex = 0;
	int leftPartitionIndex = begin;
	int rightPartitionIndex = mid + 1;
	vector<int> mergedNumbers(mergeSize);

	while ((leftPartitionIndex <= mid) && (rightPartitionIndex <= end)) {
		if (numbers.at(leftPartitionIndex) <= (numbers.at(rightPartitionIndex))) {
			mergedNumbers.at(mergedVectorIndex) = numbers.at(leftPartitionIndex);
			leftPartitionIndex++;
		}
		else {
			mergedNumbers.at(mergedVectorIndex) = numbers.at(rightPartitionIndex);
			rightPartitionIndex++;
		}
		mergedVectorIndex++;
	}

	while (leftPartitionIndex <= mid) {
		mergedNumbers.at(mergedVectorIndex) = numbers.at(leftPartitionIndex);
		leftPartitionIndex++;
		mergedVectorIndex++;
	}

	while (rightPartitionIndex <= end) {
		mergedNumbers.at(mergedVectorIndex) = numbers.at(rightPartitionIndex);
		rightPartitionIndex++;
		mergedVectorIndex++;
	}

	for (int i = 0; i < mergeSize; ++i) {
		numbers.at(begin + i) = mergedNumbers.at(i);
	}

}

// Merge sort function that recursively divides the vector in 2 parts until each part has a single item,
// then calls merge function to combine parts in order
void MergeSort(vector<int> &numbers, int begin, int end) {
	// if vector size is 1
	if (begin >= end) {
		return;
	}
	int mid = (begin + end) / 2;
	// recursively divide left partition
	MergeSort(numbers, begin, mid);
	// recursively divide right partition
	MergeSort(numbers, mid + 1, end);
	// merge left and right partitions in order
	Merge(numbers, begin, mid, end);
}

// function to return highest number of digits of numbers in an array for radix sort
int GetMaxDigits(vector<int>& numbers) {
	int max = numbers.at(0);
	for (int i = 0; i < numbers.size(); ++i) {
		if (numbers.at(i) > max) {
			max = numbers.at(i);
		}
	}
	int maxDigits = 0;

	if (max == 0) {
		return 1;
	}

	while (max != 0) {
		maxDigits++;
		max = max / 10;
	}
	return maxDigits;
}

void RadixSort(vector<int> &numbers) {
	// get max number of digits of numbers in vector
	int maxDigits = GetMaxDigits(numbers);
	int numOfItems = numbers.size();
	int temp;
	int bucketIndex;
	
	// use a list to create buckets, where each bucket is a double linked list
	list<int> buckets[10];  

	// loop through each digits place in max digits (ones, tens, hundreds ...)
	for (int i = 0; i < maxDigits; ++i) {
		int moduloDivisor = pow(10, i + 1);
		int integerDivisor = pow(10, i);

		// loop through all items to be sorted
		for (int j = 0; j < numOfItems; ++j) {
			temp = numbers.at(j) % moduloDivisor; // get modulo considering current digit place
			bucketIndex = temp / integerDivisor; // integer division to get number at appropriate digit place
			buckets[bucketIndex].push_back(numbers.at(j)); // add item at j to buckets at appropriate index determined on previous line
		}

		// loop through all buckets, adding items to original vector and deleting items from list after adding
		int count = 0;
		for (int k = 0; k < 10; ++k) {
			while (!buckets[k].empty()) {
				numbers.at(count) = *(buckets[k].begin());
				buckets[k].erase(buckets[k].begin());
				count++;
			}
		}
	}
}

// Print out sorted list, will return all 0's unless a sorting algorithm is called first
void PrintSorted(vector<int> sortedNumbers) {
	for (int i = 0; i < sortedNumbers.size(); ++i) {
		cout << sortedNumbers.at(i) << " ";
	}
	cout << endl;
	cout << endl;
}

// ===============================================================================================================

int main() {

	int numToBeSorted;
	unsigned int i;
	int choice = 0;
	clock_t ticks;

	// prompt for number of numbers
	cout << "Enter how many numbers will be used to be sorted: " << endl;
	cin >> numToBeSorted;

	vector<int> unsortedNumbers(numToBeSorted);
	cout << "Unsorted numbers:" << endl;

	// add numbers to vector of unsorted items
	for (i = 0; i < numToBeSorted; ++i) {
		unsortedNumbers.at(i) = rand() % 100 + 1;
		cout << unsortedNumbers.at(i) << " ";
	}
	cout << endl;
	cout << endl;

	while (choice != 8) {
		// menu
		cout << "Enter a choice for sorting data:" << endl;
		cout << "1. Insertion Sort" << endl;
		cout << "2. Selection Sort" << endl;
		cout << "3. Shell Sort" << endl;
		cout << "4. Quick Sort" << endl;
		cout << "5. Merge Sort" << endl;
		cout << "6. Radix Sort" << endl;
		cout << "7. Compare All Sorting Algorithms" << endl;
		cout << "8. Exit Program" << endl;

		cout << endl << "Choice:";
		cin >> choice;

		if (choice == 1) {
			// insertion sort
			vector<int> sortedNumbers(numToBeSorted);
			sortedNumbers = unsortedNumbers;

			// keep track of algorithm run time
			ticks = clock();

			InsertionSort(sortedNumbers);

			ticks = clock() - ticks;
			cout << "Clock ticks: " << ticks << endl;
			cout << "Run time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
			cout << endl;

			cout << "Sorted numbers:" << endl;
			PrintSorted(sortedNumbers);
		}

		else if (choice == 2) {
			// selection sort
			vector<int> sortedNumbers(numToBeSorted);
			sortedNumbers = unsortedNumbers;

			// keep track of algorithm run time
			ticks = clock();

			SelectionSort(sortedNumbers);

			ticks = clock() - ticks;
			cout << "Clock ticks: " << ticks << endl;
			cout << "Run time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
			cout << endl;

			cout << "Sorted numbers:" << endl;
			PrintSorted(sortedNumbers);
		}

		else if (choice == 3) {
			// shell sort
			vector<int> sortedNumbers(numToBeSorted);
			sortedNumbers = unsortedNumbers;

			// keep track of algorithm run time
			ticks = clock();

			ShellSort(sortedNumbers, sortedNumbers.size());

			ticks = clock() - ticks;
			cout << "Clock ticks: " << ticks << endl;
			cout << "Run time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
			cout << endl;

			cout << "Sorted numbers:" << endl;
			PrintSorted(sortedNumbers);

		}

		else if (choice == 4) {
			// quick sort
			vector<int> sortedNumbers(numToBeSorted);
			sortedNumbers = unsortedNumbers;

			// keep track of algorithm run time
			ticks = clock();

			QuickSort(sortedNumbers, 0, (sortedNumbers.size() - 1));

			ticks = clock() - ticks;
			cout << "Clock ticks: " << ticks << endl;
			cout << "Run time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
			cout << endl;

			cout << "Sorted numbers:" << endl;
			PrintSorted(sortedNumbers);
		}

		else if (choice == 5) {
			// merge sort
			vector<int> sortedNumbers(numToBeSorted);
			sortedNumbers = unsortedNumbers;

			// keep track of algorithm run time
			ticks = clock();

			MergeSort(sortedNumbers, 0, sortedNumbers.size() - 1);

			ticks = clock() - ticks;
			cout << "Clock ticks: " << ticks << endl;
			cout << "Run time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
			cout << endl;

			cout << "Sorted numbers:" << endl;
			PrintSorted(sortedNumbers);
		}

		else if (choice == 6) {
			// radix sort
			vector<int> sortedNumbers(numToBeSorted);
			sortedNumbers = unsortedNumbers;

			// keep track of algorithm run time
			ticks = clock();

			RadixSort(sortedNumbers);

			ticks = clock() - ticks;
			cout << "Clock ticks: " << ticks << endl;
			cout << "Run time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
			cout << endl;

			cout << "Sorted numbers:" << endl;
			PrintSorted(sortedNumbers);
		}

		else if (choice == 7) {
			// compare all sorting algorithms
			vector<int> sortedNumbers(numToBeSorted);
			vector<clock_t> runTimes;
			clock_t ticks;

			// insertion sort =========================================================================================
			sortedNumbers = unsortedNumbers;

			// keep track of algorithm run time
			ticks = clock();

			InsertionSort(sortedNumbers);

			ticks = clock() - ticks;
			runTimes.push_back(ticks);

			// selection sort =========================================================================================
			sortedNumbers = unsortedNumbers;

			// keep track of algorithm run time
			ticks = clock();

			SelectionSort(sortedNumbers);

			ticks = clock() - ticks;
			runTimes.push_back(ticks);

			// shell sort =========================================================================================
			sortedNumbers = unsortedNumbers;

			// keep track of algorithm run time
			ticks = clock();

			ShellSort(sortedNumbers, sortedNumbers.size());

			ticks = clock() - ticks;
			runTimes.push_back(ticks);

			// quick sort =========================================================================================
			sortedNumbers = unsortedNumbers;

			// keep track of algorithm run time
			ticks = clock();

			QuickSort(sortedNumbers, 0, (sortedNumbers.size() - 1));

			ticks = clock() - ticks;
			runTimes.push_back(ticks);

			// merge sort =========================================================================================
			sortedNumbers = unsortedNumbers;

			// keep track of algorithm run time
			ticks = clock();

			MergeSort(sortedNumbers, 0, sortedNumbers.size() - 1);

			ticks = clock() - ticks;
			runTimes.push_back(ticks);

			// radix sort =========================================================================================
			sortedNumbers = unsortedNumbers;

			// keep track of algorithm run time
			ticks = clock();

			RadixSort(sortedNumbers);

			ticks = clock() - ticks;
			runTimes.push_back(ticks);

			// print results ======================================================================================
			int numOfAlgorithms = runTimes.size();

			cout << endl;
			cout << string(115, '-') << endl;
			cout << string(26, ' ') << "Comparison of Sorting Algorithm Run Times" << endl;
			cout << string(115, '-') << endl;
			
			cout << left << setw(18) << "Insertion Sort" << "| " << setw(18) << "Selection Sort" << "| " << setw(18) 
				<< "Shell Sort" << "| " << setw(18) << "Quick Sort" << "| " << setw(18) << "Merge Sort" << "| " 
				<< setw(18) << "Radix Sort" << endl;

			for (int i = 0; i < numOfAlgorithms; ++i) {
				cout << left << "Run times: " << setw(5) << runTimes.at(i) * 1.0 / CLOCKS_PER_SEC << "s" << " | ";
			}
			cout << endl;
			cout << string(115, '-') << endl;
			cout << endl;
		}

		// else, input was not a choice from the menu
		else {
			if (choice != 8) {
				cout << "Please select a valid number choice from the menu." << endl;
			}
		}
	}

	cout << "Exiting program" << endl;
	return 0;
}
