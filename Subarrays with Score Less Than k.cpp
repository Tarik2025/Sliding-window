#include <vector>
using namespace std;

int countSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    long long sum = 0;
    int start = 0;

    for (int end = 0; end < n; ++end) {
        sum += nums[end];
        while (sum * (end - start + 1) >= k) {
            sum -= nums[start];
            ++start;
        }
        count += end - start + 1;
    }

    return count;
}

