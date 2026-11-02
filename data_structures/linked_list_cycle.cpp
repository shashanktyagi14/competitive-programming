#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long value;
    Node *next = nullptr;
    explicit Node(long long v) : value(v) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<unique_ptr<Node>> nodes;
    nodes.reserve(n);
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        nodes.push_back(make_unique<Node>(x));
        if (i) nodes[i - 1]->next = nodes[i].get();
    }

    int pos;
    cin >> pos;
    if (n > 0 && pos >= 0 && pos < n) nodes.back()->next = nodes[pos].get();

    Node *slow = n ? nodes[0].get() : nullptr;
    Node *fast = slow;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    if (!fast || !fast->next) {
        cout << -1 << '\n';
        return 0;
    }

    slow = nodes[0].get();
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    int index = 0;
    Node *cur = nodes[0].get();
    while (cur != slow) {
        cur = cur->next;
        ++index;
    }
    cout << index << '\n';
    return 0;
}