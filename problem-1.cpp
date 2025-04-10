// https://leetcode.com/problems/edit-distance/
// Time Complexity: O(n*m)
// Space Complexity: O(m)


class Solution {
    public:
        int minDistance(string word1, string word2) {
            int n1 = word1.size();
            int n2 = word2.size();
            vector<int> dp(n2+1, 0);
            for(int i=0; i<=n2; i++){
                dp[i] = i;
            }
            for(int i=1; i<=n1; i++){
                int prev = dp[0];
                dp[0] = i;
                for(int j=1; j<=n2; j++){
                    int curr = dp[j];
                    if(word1[i-1] == word2[j-1]){
                        dp[j] = prev;
                    }
                    else{
                        dp[j] = 1 + min(dp[j-1],min(prev,dp[j]));
                    }
                    prev=curr;
                }
            }
            return dp[n2];
        }
    };