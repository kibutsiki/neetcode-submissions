class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pairs{};


        for(size_t i{} ; i < position.size(); i++){
            pairs.push_back(pair{position[i], speed[i]});
        }

        sort(pairs.rbegin(), pairs.rend());

        int fleet = 1;

        double max_time = static_cast<double>(target - pairs[0].first) / pairs[0].second;

        for(size_t i{} ; i < pairs.size(); i++){
            double curr_time = static_cast<double>(target - pairs[i].first) / pairs[i].second;
            std::cout << curr_time << " " << max_time << std::endl;
            if(curr_time > max_time){
                fleet++;
                max_time = curr_time;
            }
        }
        

        return fleet;
    }
};
