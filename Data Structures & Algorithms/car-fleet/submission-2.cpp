class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> posSpe(n);

        for (int i = 0; i < n; i++) {
            posSpe[i] = {position[i], speed[i]};
        }

        sort(posSpe.begin(), posSpe.end());

        vector<double> reqDist(n);

        for (int i = 0; i < n; i++) {
            int dist = target - posSpe[i].first;
            int speed = posSpe[i].second;

            reqDist[i] = dist / (double)speed;

            // cout<<reqDist[i]<<" "<<endl;
        }

        stack<double> st;

        for (int i = n - 1; i >= 0; i--) {
            double dist = reqDist[i];

            if (!st.empty() && dist <= st.top()) {
                continue;
            } else {
                st.push(dist);
            }
        }

        return st.size();
    }
};
