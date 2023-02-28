// Copyright, Roberto Herrera
#include <iostream>
#include <vector>

// Print the contents of the vector.
void print(std::vector<int>& ar) {
  for (int i = 0; i < ar.size(); i++) {
    std::cout << ar[i];
    if (i < ar.size() - 1) {
      std::cout << " ";
    } else {
      std::cout << std::endl;
    }
  }
}

// swap values
// O(1)
void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

// returns the index of the pivot, all elements to the left are smaller than the
// pivot, all elements to the right are bigger
int partition(std::vector<int>& ar, int start, int end) {
  int pivot = start;
  int pivot_index = start + 1;
  for (int i = pivot_index; i <= end; i++) {
    if (ar[i] < ar[pivot]) {
      swap(ar[pivot_index], ar[i]);
      pivot_index++;
    }
  }
  swap(ar[pivot], ar[pivot_index - 1]);
  return pivot_index - 1;
}

// partition the array and sorts both sides recursively
void quickSort(std::vector<int>& ar, int start, int end) {
  if (start <= end) {
    int pivot = partition(ar, start, end);
    quickSort(ar, start, pivot - 1);
    quickSort(ar, pivot + 1, end);
  }
}

// O(log n)
void quick_sort(std::vector<int>& ar) {
  int start = 0;
  int end = ar.size() - 1;
  quickSort(ar, start, end);
}

// O(log n)
int binarySearch(std::vector<int>& ar, int value, int start, int end) {
  int mid = start + (end - start) / 2;

  if (start <= end) {
    if (value == ar[mid]) {
      return mid;
    } else if (value < ar[mid]) {
      return binarySearch(ar, value, start, mid - 1);
    }

    return binarySearch(ar, value, mid + 1, end);
  } else {
    return -1;
  }
}

int binary_search(std::vector<int>& ar, int val) {
  int start = 0;
  int end = ar.size() - 1;

  return binarySearch(ar, val, start, end);
}

int main() {
  // Read the inputs from the user.
  std::vector<int> ar;
  int n;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    int input;
    std::cin >> input;
    ar.push_back(input);
  }
  // Sort the vector.
  quick_sort(ar);
  // Read a number from the user.
  int val;
  std::cin >> val;

  // print sorted vector
  print(ar);
  // Find the number in the sorted vector.
  std::cout << binary_search(ar, val) << std::endl;
}