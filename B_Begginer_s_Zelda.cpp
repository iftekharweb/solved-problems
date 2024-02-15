#include <iostream>
#include <vector>
#include <unordered_map>

bool isSumPossible(const std::vector<int>& powersOf2, int w, int index,
                   int currentSum, std::unordered_map<std::string, bool>& memo) {
    // If the current sum is equal to w, return true
    if (currentSum == w) {
        return true;
    }

    // If we have reached the end of the array, return false
    if (index == powersOf2.size()) {
        return false;
    }

    // Create a unique key for the current state
    std::string key = std::to_string(index) + "_" + std::to_string(currentSum);

    // Check if the result for the current state is already memoized
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    // Include the current element and check if a sum is possible
    bool includeCurrent = isSumPossible(powersOf2, w, index + 1, currentSum + powersOf2[index], memo);

    // Exclude the current element and check if a sum is possible
    bool excludeCurrent = isSumPossible(powersOf2, w, index + 1, currentSum, memo);

    // Memoize the result for the current state
    memo[key] = includeCurrent || excludeCurrent;

    // Return true if either including or excluding the current element leads to a valid sum
    return memo[key];
}

int main() {
    // Example usage:
    std::vector<int> powersOf2 = {1, 2, 4, 8, 16};
    int w = 1387730;

    std::unordered_map<std::string, bool> memo;

    if (isSumPossible(powersOf2, w, 0, 0, memo)) {
        std::cout << "Yes, it is possible to generate the sum " << w << ".\n";
    } else {
        std::cout << "No, it is not possible to generate the sum " << w << ".\n";
    }

    return 0;
}
