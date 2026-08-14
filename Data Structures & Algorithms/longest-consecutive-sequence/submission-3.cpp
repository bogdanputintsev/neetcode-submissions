class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;

        unordered_map<int, int> assignments;
        for (int num : nums) {
            assignments[num] = -1;
        }

        int numberOfGroups = 0;

        for (int num : nums) {
            if (assignments[num] != -1) {
                continue;
            }

            int newId = numberOfGroups;
            numberOfGroups++;
            
            int groupSize = 0;

            int currentNum = num;
            groupSize++;
            assignments[currentNum] = newId;

            currentNum = num - 1;
            while(assignments.contains(currentNum)) {
                groupSize++;
                assignments[currentNum] = newId;
                currentNum--;
            }

            currentNum = num + 1;
            while(assignments.contains(currentNum)) {
                groupSize++;
                assignments[currentNum] = newId;
                currentNum++;
            }

            result = max(result, groupSize);
        }

        return result;
    }
};
