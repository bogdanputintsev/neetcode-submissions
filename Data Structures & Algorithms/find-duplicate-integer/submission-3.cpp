class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        // Phase 1: find meeting point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: find cycle entrance
        int finder = 0;
        while(slow != finder) {
            slow = nums[slow];
            finder = nums[finder];
        }

        return slow;
 
    }
};
