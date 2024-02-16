#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> minLeftIndex(n);
    vector<int> maxRightIndex(n);

    // the min left index
    minLeftIndex[0] = -1;
    for (int i = 1; i < n; i++) {
        int t = i - 1;
        while (t >= 0 && heights[t] >= heights[i])
            t = minLeftIndex[t];
        minLeftIndex[i] = t;
    }

    // the max right index
    maxRightIndex[0] = -1;
    for (int i = n - 2; i >= 0; i--) {
        int t = i - 1;
        while (t < n && heights[t] >= heights[i])
            t = maxRightIndex[t];
        maxRightIndex[i] = t;
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        int width = maxRightIndex[i] - minLeftIndex[i] - 1;
        int height = heights[i];
        result = max(result, width * height);
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    string input;
    getline(cin, input);

    stringstream ss(input);
    vector<int> heights;
    int height;

    while (ss >> height) {
        heights.push_back(height);
        if (ss.peek() == ',')
            ss.ignore();
    }

    cout << largestRectangleArea(heights) << endl;
}
