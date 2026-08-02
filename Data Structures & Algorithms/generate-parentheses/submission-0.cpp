class Solution {
public:
    stack<string> st;
    vector<string> ans;
    
    vector<string> generateParenthesis(int n) {
        // Only add a ')' iff openN > closeN. 
        // Stop if openN == closeN == n.
        // Only add a '(' iff openN <= n.

        vector<string> ans;
        solve("", ans, n);
        return ans;
    }

    void solve(string s, vector<string>& ans, int n) {
        if(s.length() == n * 2) {
            if(valid(s)) ans.push_back(s);
            return;
        }

        solve(s + '(', ans, n);
        solve(s + ')', ans, n);
    }

    bool valid(const string& s) {
        int open = 0;
        for(char c : s) {
            open += (c == '(') ? 1 : -1;
            if(open < 0) return false;
        }

        return open == 0;
    }
};
