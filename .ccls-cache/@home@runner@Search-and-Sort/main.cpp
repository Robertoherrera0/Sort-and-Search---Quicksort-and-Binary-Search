#include <iostream>
#include <vector>

void print(std::vector<int>& ar) {
  for (auto& i : ar) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

void swap(int& left, int& right) {
  int tmp = left;
  left = right;
  right = tmp;
}

int partition(std::vector<int>& ar, int lo, int hi) {
  print(ar);
  std::cout << "partition"
            << ", lo=" << lo
            << ", hi=" << hi << std::endl;
  
  int pivot = ar[hi];

    // First element greater than the pivot.
  int pivot_index = lo;

  // Move all smaller elements left of the pivot_index.
  for (int i = lo; i < hi; i++) {
    if (ar[i] < pivot) {
      swap(ar[pivot_index], ar[i]);
      pivot_index++;
    }
  }

  // Move the pivot into the pivot_index.
  swap(ar[pivot_index], ar[hi]);
  return pivot_index;
}

void quick_sort(std::vector<int>& ar, int lo, int hi) {
  // Base.
  if (lo >= hi || lo < 0) return;

  // Recurse.
  int pivot = partition(ar, lo, hi);
  quick_sort(ar, lo, pivot - 1);
  quick_sort(ar, pivot + 1, hi);
}

void quick_sort(std::vector<int>& ar) {
  quick_sort(ar, 0, ar.size() - 1);
}

void merge(std::vector<int>& ar, int lo, int mid, int hi) {
  print(ar);
  std::cout << "merge"
            << ", lo=" << lo
            << ", mid=" << mid
            << ", hi=" << hi << std::endl;
  std::vector<int> left, right;
  for (int i = lo; i <= hi; i++) {
    if (i <= mid) {
      left.push_back(ar[i]);
    } else {
      right.push_back(ar[i]);
    }
  }

  int i = lo;
  int lefti = 0;
  int righti = 0;
  while (righti < right.size() &&
         lefti < left.size()) {
    if (left[lefti] < right[righti]) {
      ar[i++] = left[lefti++];
    } else {
      ar[i++] = right[righti++];
    }
  }

  while (lefti < left.size()) {
    ar[i++] = left[lefti++];
  }
  while (righti < right.size()) {
    ar[i++] = right[righti++];
  }
}

void merge_sort(std::vector<int>& ar, int lo, int hi) {
  // Base case.
  if (lo == hi) return;

  // Recurse.
  int mid = (lo + hi) / 2;
  merge_sort(ar, lo, mid);
  merge_sort(ar, mid + 1, hi);
  merge(ar, lo, mid, hi);
}

void merge_sort(std::vector<int>& ar) {
  merge_sort(ar, 0, ar.size() - 1);
}

void selection_sort(std::vector<int>& ar) {
  int first = 0;
  while (first != ar.size()) {
    // Find the index of the smallest.
    int smallest = first;
    for (int i = first; i < ar.size(); i++) {
      if (ar[i] < ar[smallest]) {
        smallest = i;
      }
    }
    // Swap
    if (first < smallest) {
      swap(ar[first], ar[smallest]);
    }
    first++;
  }
}

void bubble_sort(std::vector<int>& ar) {
  int last = ar.size();
  while (last != 0) {
    for (int i = 0; i < last-1; i++) {
      int j = i + 1;
      if (ar[i] > ar[j]) {
        swap(ar[i], ar[j]);
      }
    }
    last--;
  }
}

int binary_search(std::vector<int>& ar, int val) {
  int lo = 0;
  int hi = ar.size() - 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (val == ar[mid]) {
      return mid;
    } else if (val < ar[mid]) {
      hi = mid - 1;
    } else {
      lo = mid;
    }
  }
}

int main() {
  // Sorting
  std::vector<int> ar = {4, 3, 7, 8, 1, 5, 9, 2, 0, 6};
  //bubble_sort(ar);
  selection_sort(ar);
  //merge_sort(ar);
  //quick_sort(ar);
  print(ar);

  // Searching
  //std::vector<int> ar2 = {0, 0, 1, 1, 1, 2, 4, 6, 9};
  //std::cout << "found=" << binary_search(ar2, 4) << std::endl;
}