class Solution {
public:
    int maxScore(vector<int>& nums) {
        int m = nums.size(), n = nums.size() / 2;
        vector<int> dp(1 << m, -1);
        vector<vector<int>> gcd(m, vector<int>(m, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                gcd[i][j] = __gcd(nums[i], nums[j]);
            }
        }
        
        return calculateMaxScore(nums, 1, 0, dp, gcd);
    }
    
private:
    int calculateMaxScore(vector<int>& nums, int op, int mask, vector<int>& dp, vector<vector<int>>& gcd) {
        int m = nums.size(), n = nums.size() / 2;
        if (op > n) return 0;
        if (dp[mask] != -1) return dp[mask];

        for (int i = 0; i < m; i++) {
            if ((mask & (1 << i))) continue;
            for (int j = i + 1; j < m; j++) {
                if ((mask & (1 << j))) continue;
                
                int newMask = (1 << i) | (1 << j) | mask;
                int score = op * gcd[i][j] + calculateMaxScore(nums, op + 1, newMask, dp, gcd);
                dp[mask] = max(dp[mask], score);
            }
        }
        
        return dp[mask];
    }
};
