// l.c 39
// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates 
// where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique 
// if the frequency of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]


//time complexity 
// O(n(T/m))
//space complexity O(T/m)
// Why T/m?
// In the worst case, recursion can go as deep as T/m.
// Example: if the smallest candidate is 2 and target = 10, the maximum depth is 10/2 = 5 (because the combination [2,2,2,2,2] uses up the target with depth 5).
// If the smallest candidate were 1, then depth could go all the way to T/1 = T.
// So T/m is the maximum recursion depth.

void combinationSum_helper(vector<int>& candidates, int target,
                               vector<vector<int>>& ans, vector<int>& temp,
                               int index) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (target < 0)
            return;
        for (int i = index; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            combinationSum_helper(candidates, target - candidates[i], ans, temp, i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combinationSum_helper(candidates, target, ans, temp, 0);
        return ans;
    }