class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (int i = 0; i < tasks.size(); i++) {
            freq[tasks[i] - 'A']++;
        }

        priority_queue<int> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                pq.push(freq[i]);
            }
        }

        queue<pair<int, int>> q;

        int time = 0;
        int freqVal;

        while (!pq.empty() || !q.empty()) {
            time++;
            if (!pq.empty()) {
                freqVal = pq.top() - 1;
                pq.pop();
                if (freqVal)
                    q.push({freqVal, time + n});
            } 

            if (!q.empty() && time == q.front().second) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
