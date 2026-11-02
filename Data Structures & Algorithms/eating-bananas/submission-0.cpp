class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for(int pile : piles){
            high = max(high,pile);
        }

        while (low < high) {
            int mid = low + (high - low) / 2;

            long long hours = 0;
            for (int p : piles) {
                hours += ceil(static_cast<double>(p)/mid);
            }

            if (hours <= h) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};