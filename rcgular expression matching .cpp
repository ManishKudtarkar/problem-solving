class Solution {
public:

    bool recursion(string& s, string& p,int i,int j){
        if (i >= s.length() && j >= p.length()) return true;
        if (j >= p.length()) return false;

        bool match = (i < s.length()) && (s[i] == p[j] || p[j] == '.');

        if (j+1<p.length() && p[j+1] == '*'){
            return recursion ( s,p,i,j+2) || (match && recursion (s,p,i+1,j));
        } else if (match) {
            return recursion (s,p,i+1,j+1);
        } else {
            return false;
        }
    }

    bool memo(string& s , string& p, int i,int j,vector<vector<int>>& dp){

        if (i >= s.length() && j >= p.length()) return true;
        if (j>= p.length()) return false;

        if (dp[i][j] != -1) return dp [i][j];

        bool match = ( i<s.length()) && (s[i] == p[j] || p[j] == '.');

        bool ans;

        if (j + 1 <p.length() && p[j+1] == '*') {
            ans = memo(s,p,i,j+2,dp) || (match && memo (s,p,i+1,j,dp));
        } else if (match) {
            ans = memo ( s,p,i+1,j+1,dp);
        } else {
            ans = false;
        }
        dp[i][j] = ans;
        return dp [i][j];
    }

    bool tab (string& s,string& p){
        int n= s.length ();
        int m = p.length();

        vector<vector<int>> dp (n+1, vector < int> (m+1 , 0));
        dp[n][m] = 1;
         
        for (int a = n; a>=0;a--) {
            for (int b=m-1;b >= 0; b--){
                bool match= (a <s.length()) && (s[a] == p[b] || p[b] == '.');

                 bool ans;
                if (b + 1 < p.length() && p[b + 1] == '*') {
                    ans = dp[a][b + 2] || (match && dp[a + 1][b]);
                } else if (match) {
                    ans = dp[a + 1][b + 1];
                } else {
                    ans = false;
                }
                dp[a][b] = ans;
            }
        }
        return dp[0][0];
    }
     bool solve_using_so(string& s, string& p) {
        int n = s.length();
        int m = p.length();
        vector<int> x(m + 1, 0), y(m + 1, 0);
        y[m] = 1;

        for (int a = n; a >= 0; a--) {
            x[m] = (a == n);
            for (int b = m - 1; b >= 0; b--) {
                bool match = (a < s.length()) && (s[a] == p[b] || p[b] == '.');

                bool ans;
                if (b + 1 < p.length() && p[b + 1] == '*') {
                    ans = x[b + 2] || (match && y[b]);
                } else if (match) {
                    ans = y[b + 1];
                } else {
                    ans = false;
                }
                x[b] = ans;
            }
            y = x;
        }
        return x[0];
     }


    bool isMatch(string s, string p) {

        return solve_using_so(s, p);
        
    }
};
