#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void printNGE(const vector<int>& arr) {
    stack<int> s;
    int n = arr.size();
    vector<int> nge(n, -1);

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        if (!s.empty()) {
            nge[i] = s.top();
        }
        s.push(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " --> " << nge[i] << endl;
    }
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    printNGE(arr);
    return 0;
}
