class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int idx1 = 0;
        int idx2 = 0;
        
        int steps = 0;
        const int commonSize = nums1.size() + nums2.size();
        const int maxSteps = commonSize / 2 + 1;

        double median1 = 0;
        double median2 = 0;

        while (steps < maxSteps) {
            
            median2 = median1;

            const bool idxOneIsValid = idx1 < nums1.size();
            const bool idxTwoIsValid = idx2 < nums2.size();

            if (idxOneIsValid && idxTwoIsValid) {

                if (nums1[idx1] < nums2[idx2]) {
                    median1 = nums1[idx1];
                    idx1++;
                } else {
                    median1 = nums2[idx2];
                    idx2++;
                }

            } else if (idxOneIsValid) {
                median1 = nums1[idx1];
                idx1++;
            } else if (idxTwoIsValid) {
                median1 = nums2[idx2];
                idx2++;
            }

            steps++;
        }

        if ((commonSize & 1) == 0) {
            return (median1 + median2) / 2.0;
        } else {
            return median1;
        }
    }
};

// (2, 2)
// 1,2
//     .
// 3,4
// .