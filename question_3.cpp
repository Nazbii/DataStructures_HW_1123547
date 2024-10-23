#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printFirstNegativeInteger(const vector<int>& arr, int k) {
    queue<int> negatives;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            negatives.push(i);
        }

        if (i >= k - 1) {
            if (!negatives.empty() && negatives.front() < i - k + 1) {
                negatives.pop();
            }

            if (!negatives.empty()) {
                cout << arr[negatives.front()] << " ";
            } else {
                cout << "0 ";
            }
        }
    }
}

int main() {
    vector<int> arr = {-8, 2, 3, -6, 10};
    int k = 2;
    printFirstNegativeInteger(arr, k);
    return 0;
}
