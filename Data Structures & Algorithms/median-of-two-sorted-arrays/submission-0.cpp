class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n = nums1.size();
        int m = nums2.size();

        int low = 0;
        int high = n;

        int totalReq = (n + m) / 2;

        bool isEven = (n + m) % 2 ? false : true;

        double res;

        while (low <= high) {
            int leftReq = (high - low) / 2 + low;

            if (leftReq > totalReq) {
                high = leftReq - 1;
                continue;
            }

            int l1 = (leftReq == 0) ? INT_MIN : nums1[leftReq - 1];
            int r1 = (leftReq == n) ? INT_MAX : nums1[leftReq];

            int rightReq = totalReq - leftReq;

            int l2 = (rightReq == 0) ? INT_MIN : nums2[rightReq - 1];
            int r2 = (rightReq == m) ? INT_MAX : nums2[rightReq];

            if (l1 <= r2 && l2 <= r1) {
                int leftSideVal = max(l1, l2);
                int rightSideVal = min(r1, r2);

                if (isEven) {
                    res = (leftSideVal + rightSideVal) / (double)2;
                } else {
                    res = rightSideVal;
                }

                break;
            } else if (l1 > r2) {
                high = leftReq - 1;
            } else {
                low = leftReq + 1;
            }
        }

        return res;
    }
};
