class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        priority_queue<pair<int, int>> pq;

        vector<int> res;

        int l = 0, r = 0;

        for (r; r < k; r++) {
            pq.push({nums[r], r});
        }

        res.push_back(pq.top().first);

        while (r < n) {
            l++;
            pq.push({nums[r], r});

            while (pq.top().second < l) {
                pq.pop();
            }

            res.push_back(pq.top().first);
            r++;
        }

        return res;
    }
};
