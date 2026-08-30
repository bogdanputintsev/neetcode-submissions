class Solution {
public:
    public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> sequenceLength;

        for (int num : nums) {
            sequenceLength[num] = 0;
        }

        int maxSequenceLength = 0;

        for (auto& [num, length] : sequenceLength) {
            if (length == 0) {
                length = findSequenceLength(num, sequenceLength);
            }

            maxSequenceLength = max(maxSequenceLength, length);
        }

        return maxSequenceLength;
    }

private:
    int findSequenceLength(int num, unordered_map<int, int>& sequenceLength) {
        auto it = sequenceLength.find(num);

        if (it == sequenceLength.end()) {
            return 0;
        }

        if (it->second != 0) {
            return it->second;
        }

        it->second = 1 + findSequenceLength(num - 1, sequenceLength);
        return it->second;
    }
};
