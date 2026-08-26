#include <vector>
#include <deque> // Required for std::deque
#include <algorithm> // Required for std::max (though not directly used in the deque logic)

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::deque<int> dq; // Stores indices of elements in decreasing order of their values

        // Iterate through the array with right pointer 'r'
        for (int r = 0; r < nums.size(); ++r) {
            // 1. Remove elements from the back of the deque that are smaller than or equal to nums[r]
            // This ensures dq stores indices of elements in strictly decreasing order of values.
            // If nums[dq.back()] <= nums[r], then nums[dq.back()] can never be the maximum
            // in any future window that also contains nums[r].
            while (!dq.empty() && nums[dq.back()] <= nums[r]) {
                dq.pop_back();
            }
            // Add current element's index to the back of the deque
            dq.push_back(r);

            // 2. Remove elements from the front of the deque if they are out of the current window
            // The left boundary of the current window is (r - k + 1)
            // If the index at the front of the deque is less than this left boundary, it's out of window.
            if (dq.front() < r - k + 1) {
                dq.pop_front();
            }

            // 3. Once the window has processed 'k' elements, the maximum is at the front of the deque
            // We start collecting results only when the window is fully formed.
            if (r >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};
