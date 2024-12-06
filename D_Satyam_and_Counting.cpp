#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int maxBeautifulSegments(const vector<int>& arr) {
    unordered_map<int, int> prefixSumMap;
    prefixSumMap[0] = -1;
    int currentSum = 0, lastEnd = -1, beautifulCount = 0;

    for (int i = 0; i < arr.size(); ++i) {
        currentSum += arr[i];
        if (prefixSumMap.count(currentSum) && prefixSumMap[currentSum] >= lastEnd) {
            beautifulCount++;
            lastEnd = i;
        }
        prefixSumMap[currentSum] = i;
    }

    return beautifulCount;
}

int main() {
    vector<int> arr = {1, -1, 2, 0, 0, 0};
    cout << maxBeautifulSegments(arr) << endl;
    return 0;
}
