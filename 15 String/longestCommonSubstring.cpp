class Solution{
	public:
int solveByTab(string s1,string s2, int n, int m){
        
        vector<int> curr(m + 1), next(m + 1);
        
        int maxi = 0;
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(s1[i] == s2[j]){
                    curr[j] = 1 + next[j + 1];
                }
                else{
                    curr[j] = 0;
                }
                maxi = max(maxi, curr[j]);
            }
            next = curr;
        }
        
        return maxi;
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m){
        return solveByTab(S1, S2, n, m);
    }
}
