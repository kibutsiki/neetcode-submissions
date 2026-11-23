class Solution {
public:
    int findDuplicate(const vector<int>& nums) {
    int slow = 0;
    int fast = 0;

    // Phase 1: Detect cycle
    do {
        slow = nums[slow];                 // move 1 step
        fast = nums[nums[fast]];           // move 2 steps
    } while (slow != fast);

    // Phase 2: Find cycle entry (duplicate number)
    slow = 0;
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow; // this is the duplicate number
}
};
