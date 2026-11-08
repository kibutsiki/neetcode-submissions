
class TimeMap {
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = store.find(key);
        if (it == store.end()) return "";

        const auto& vals = it->second;
        int low = 0, high = static_cast<int>(vals.size()) - 1;
        string result = "";

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (vals[mid].first <= timestamp) {
                result = vals[mid].second;  // valid candidate, look for a later one
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
};
