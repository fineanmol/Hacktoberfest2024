#include <iostream>
#include <vector>

void findIntersection(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    int i = 0;
    int j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] == arr2[j]) {
            std::cout << arr1[i] << " ";
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
}

int main() {
    std::vector<int> arr1 = {1, 3, 4, 5, 7};
    std::vector<int> arr2 = {3, 5, 6};
    
    std::cout << "Intersection of the two arrays: ";
    findIntersection(arr1, arr2);
    std::cout << std::endl;

    return 0;
}
