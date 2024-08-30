#include <vector>
using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int n = arr.size();
    int sum = 0;
    int count = 0;
    int target = k * threshold;

    // Calculate the sum of the first k elements
    for (int i = 0; i < k; ++i) {
        sum += arr[i];
    }

    // Check if the first window meets the condition
    if (sum >= target) {
        ++count;
    }

    // Slide the window
    for (int i = k; i < n; ++i) {
        sum = sum - arr[i - k] + arr[i];
        if (sum >= target) {
            ++count;
        }
    }

    return count;
}

