#include <iostream>
#include <stack>
using namespace std;

void insertBottom(stack<int>& s, int x) {
    if (s.size() == 0) {
        s.push(x);
    } else {
int n = s.top();
s.pop();
        insertBottom(s, x);

        s.push(n);
    }
}

void reverse(stack<int>& s) {
    if (!s.empty()) {
        int temp = s.top();
        s.pop();
        reverse(s);

        insertBottom(s, temp);
    }
}

void printStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }
    int temp = s.top();
    s.pop();

    printStack(s);

    cout << temp << " ";
    s.push(temp);
}

int main() {
    stack<int> current;

    current.push(1);
    current.push(2);
    current.push(3);
    current.push(4);
    current.push(5);

    cout << "Original stack: ";
    printStack(current);
    cout << endl;

    reverse(current);

    cout << "Reversed stack: ";
    printStack(current);

    return 0;
}