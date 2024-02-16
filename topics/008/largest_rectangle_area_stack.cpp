#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;

    for (int i = 0; i <= heights.size(); ++i) {
        while (!s.empty() && (i == heights.size() || heights[i] < heights[s.top()])) {
            int h = heights[s.top()];
            s.pop();
            int left = s.empty() ? -1 : s.top();
            maxArea = max(maxArea, h * (i - left - 1));
        }
        s.push(i);
    }

    return maxArea;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); // CLEAR THE NEWLINE CHARACTER LEFT IN THE INPUT BUFFER

    string input;
    getline(cin, input);

    stringstream ss(input);
    vector<int> heights;
    int height;

    while (ss >> height) {
        heights.push_back(height);
        if (ss.peek() == ',')
            ss.ignore(); // ignore the comma
    }

    cout << largestRectangleArea(heights) << endl;
}
