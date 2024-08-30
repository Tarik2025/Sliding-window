#include <vector>
using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    int oddCount = 0;
    int left = 0;
    int result = 0;

    for (int right = 0; right < n; ++right) {
        if (nums[right] % 2 != 0) {
            ++oddCount;
            count = 0; // Reset count of valid subarrays ending at 'right'
        }

        while (oddCount == k) {
            if (nums[left] % 2 != 0) {
                --oddCount;
            }
            ++count; // Increment count of valid subarrays
            ++left;
        }

        result += count;
    }

    return result;
}

