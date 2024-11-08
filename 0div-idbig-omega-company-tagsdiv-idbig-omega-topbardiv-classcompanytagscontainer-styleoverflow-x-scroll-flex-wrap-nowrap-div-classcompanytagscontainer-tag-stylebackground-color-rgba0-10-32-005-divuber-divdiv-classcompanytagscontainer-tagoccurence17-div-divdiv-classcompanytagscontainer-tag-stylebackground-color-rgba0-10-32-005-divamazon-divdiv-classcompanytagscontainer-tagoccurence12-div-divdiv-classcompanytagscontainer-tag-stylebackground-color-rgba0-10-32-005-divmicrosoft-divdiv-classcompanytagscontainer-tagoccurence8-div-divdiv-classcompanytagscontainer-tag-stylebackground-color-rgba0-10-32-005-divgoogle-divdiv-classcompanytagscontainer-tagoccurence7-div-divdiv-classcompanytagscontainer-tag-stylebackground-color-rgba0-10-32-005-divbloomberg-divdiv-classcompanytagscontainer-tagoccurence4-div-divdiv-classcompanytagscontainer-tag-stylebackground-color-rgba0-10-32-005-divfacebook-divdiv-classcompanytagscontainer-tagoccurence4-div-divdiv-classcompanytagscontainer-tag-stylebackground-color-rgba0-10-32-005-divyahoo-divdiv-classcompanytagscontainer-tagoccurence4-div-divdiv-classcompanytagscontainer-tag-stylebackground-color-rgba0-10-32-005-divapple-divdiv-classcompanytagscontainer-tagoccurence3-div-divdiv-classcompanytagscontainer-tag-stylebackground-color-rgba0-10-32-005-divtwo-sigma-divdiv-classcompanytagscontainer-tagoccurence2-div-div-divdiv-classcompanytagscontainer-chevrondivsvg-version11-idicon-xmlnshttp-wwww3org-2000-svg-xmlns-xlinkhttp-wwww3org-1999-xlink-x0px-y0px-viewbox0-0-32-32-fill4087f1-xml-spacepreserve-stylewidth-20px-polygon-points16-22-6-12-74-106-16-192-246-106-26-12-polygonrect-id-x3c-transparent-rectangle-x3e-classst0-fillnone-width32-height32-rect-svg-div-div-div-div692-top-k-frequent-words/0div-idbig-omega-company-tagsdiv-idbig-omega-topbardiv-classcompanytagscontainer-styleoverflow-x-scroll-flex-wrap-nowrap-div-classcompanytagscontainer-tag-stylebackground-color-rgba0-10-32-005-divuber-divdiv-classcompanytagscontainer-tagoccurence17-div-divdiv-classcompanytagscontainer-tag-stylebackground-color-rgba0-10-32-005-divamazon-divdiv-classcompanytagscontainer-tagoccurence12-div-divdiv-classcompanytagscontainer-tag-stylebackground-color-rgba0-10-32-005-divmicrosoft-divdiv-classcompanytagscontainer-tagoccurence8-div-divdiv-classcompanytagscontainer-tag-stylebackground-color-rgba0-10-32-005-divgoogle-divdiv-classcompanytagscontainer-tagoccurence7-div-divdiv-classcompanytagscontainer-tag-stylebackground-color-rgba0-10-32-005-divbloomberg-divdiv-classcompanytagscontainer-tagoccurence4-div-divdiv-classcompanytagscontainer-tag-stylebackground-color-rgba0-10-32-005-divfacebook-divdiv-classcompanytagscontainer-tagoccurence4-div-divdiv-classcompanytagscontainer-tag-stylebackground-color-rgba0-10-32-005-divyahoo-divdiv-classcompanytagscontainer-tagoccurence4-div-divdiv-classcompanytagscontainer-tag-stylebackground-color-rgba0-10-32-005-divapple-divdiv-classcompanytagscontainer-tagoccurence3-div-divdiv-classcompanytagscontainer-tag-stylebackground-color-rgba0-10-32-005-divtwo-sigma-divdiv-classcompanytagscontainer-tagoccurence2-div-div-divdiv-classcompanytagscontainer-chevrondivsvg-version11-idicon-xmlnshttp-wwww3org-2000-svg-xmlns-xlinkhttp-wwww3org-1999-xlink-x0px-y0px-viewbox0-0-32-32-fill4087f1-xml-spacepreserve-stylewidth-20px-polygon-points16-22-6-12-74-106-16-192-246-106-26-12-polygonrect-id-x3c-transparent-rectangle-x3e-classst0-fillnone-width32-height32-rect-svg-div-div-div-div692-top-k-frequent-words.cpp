class Solution {
public:
    //  // Step 2: Define a min-heap priority queue with custom comparator
    // auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) {
    //     // If frequencies are equal, compare lexicographically
    //     if (a.first == b.first)
    //         return a.second < b.second;
    //     // Otherwise, sort by frequency (higher frequency first)
    //     return a.first > b.first;
    // };
    struct Compare {
    bool operator() (pair<int, string> a, pair<int, string> b) {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(int i=0; i<words.size(); i++)
            m[words[i]]++;
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> q;
        for(auto p : m)
            q.push({p.second, p.first});
        
        vector<string> ans;
        while(k--) {
            ans.push_back(q.top().second);
            q.pop();
        }
        
        return ans;
    }
};