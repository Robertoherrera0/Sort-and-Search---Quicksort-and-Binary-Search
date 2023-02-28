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

void quick_sort(std::vector<int>& ar) {
  // TODO: implement!
}

int binary_search(std::vector<int>& ar, int val) {
  // TODO: implement!
  return -1;
}

int main() {
  // Read the inputs from the user.

  // Sort the vector.

  // Read a number from the user.

  // Find the number in the sorted vector.
}