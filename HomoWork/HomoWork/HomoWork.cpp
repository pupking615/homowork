#include <iostream>
#include <string>

template <typename T>
class BinarySearch {
public:
    BinarySearch(const T* data, int size) : data_(data), size_(size) {}

    int find(const T& target) const {
        int left = 0;
        int right = size_ - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (data_[mid] == target) {
                return mid;
            }
            else if (data_[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }

private:
    const T* data_;
    int size_;
};

int main() {
    int test_cases = 2;
    while (test_cases--) {
        char type;
        int n, q;
        std::cin >> type >> n >> q;

        if (type == 'i') {
            int data[30];
            for (int i = 0; i < n; ++i) {
                std::cin >> data[i];
            }
            BinarySearch<int> binary_search(data, n);

            for (int i = 0; i < q; ++i) {
                int target;
                std::cin >> target;
                std::cout << binary_search.find(target) << std::endl;
            }
        }
        else if (type == 's') {
            std::string data[30];
            for (int i = 0; i < n; ++i) {
                std::cin >> data[i];
            }
            BinarySearch<std::string> binary_search(data, n);

            for (int i = 0; i < q; ++i) {
                std::string target;
                std::cin >> target;
                std::cout << binary_search.find(target) << std::endl;
            }
        }
    }
    return 0;
}