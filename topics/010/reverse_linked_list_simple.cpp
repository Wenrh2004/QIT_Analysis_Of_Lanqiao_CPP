//
// Created by 温若涵 on 2024/2/8.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x;
    vector<int> nodes;
    while (cin >> x && x != -1)
        nodes.push_back(x);

    for (int i = 0; i + 2 < nodes.size(); i += 3)
        swap(nodes[i], nodes[i + 2]);

    for (auto &i : nodes)
        cout << i << " ";

    cout << endl;
}