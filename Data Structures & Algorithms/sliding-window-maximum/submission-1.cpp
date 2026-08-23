class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;

        int left = 0;
        int right = k - 1;
        unordered_map<int, int> hashmap;
        priority_queue<int> q;

        for (int i = 0; i < k; i++) {
            hashmap[nums[i]]++;
            q.push(nums[i]);
        }

        while(right < nums.size()) {
            while(hashmap[q.top()] == 0) {
                q.pop();
            }

            result.push_back(q.top());
            hashmap[nums[left]]--;
            left++;
            right++;
            if (right < nums.size()) {
                hashmap[nums[right]]++;
                q.push(nums[right]);
            }
        }

        return result;
    }
};

// { 1:1, 3:1, -1:1, }
// { 3, 1, -1 }
// 1,3,-1,-3,5,3,6,7
// .    .