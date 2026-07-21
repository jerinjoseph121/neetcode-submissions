class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int maxHeight = 0;

        for (int i = 0; i < n; i++) {
            maxHeight = max(maxHeight, height[i]);
        }

        vector<int> maxHeightIdx;

        for (int i = 0; i < n; i++) {
            if (height[i] == maxHeight)
                maxHeightIdx.push_back(i);
        }

        int res = 0;

        int ptr = 0;

        int m = maxHeightIdx.size();

        int threshold;

        for (int i = 0; i < m; i++) {
            int high = maxHeightIdx[i];

            threshold = height[ptr];

            while (ptr < high) {
                if (height[ptr] <= threshold) {
                    res += threshold - height[ptr];
                } else {
                    threshold = height[ptr];
                }
                ptr++;
            }
        }

        int lastMaxHeightIdx = maxHeightIdx[m - 1];

        ptr = n - 1;

        threshold = height[ptr];

        while (ptr > lastMaxHeightIdx) {
            if (height[ptr] <= threshold) {
                res += threshold - height[ptr];
            } else {
                threshold = height[ptr];
            }
            ptr--;
        }

        return res;
    }
};
