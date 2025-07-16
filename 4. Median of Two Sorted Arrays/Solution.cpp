class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> out;
        for (int i : nums1) {
            out.push_back(i);
        }
        for (int i : nums2) {
            out.push_back(i);
        }
        sort(out.begin(), out.end());

        if (out.size() % 2 != 0) {
            return out[out.size() / 2];
        } else {
            double t = out.size() / 2;
            return (out[t - 1] + out[t]) / 2.0;
        }
    }
};