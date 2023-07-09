#include <iostream>
using namespace std;

string s;
string t;

int sl;
int tl;

int dp[3000 + 1][3000 + 1];

int helper(int i, int j) {
    if (i == sl || j == tl) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int q =0 ;
    if (s[i] == t[j]) {
        q = 1 + helper(i + 1, j + 1);
    } else {
        q = max(helper(i + 1, j), helper(i, j + 1));
    }
    dp[i][j] = q;
    return q;
}

int main() {
    for (int i = 0; i <= 3000; i++) {
        for (int j= 0; j<=3000; j++) {
            dp[i][j] = -1;
        }
    }
    cin >> s >> t;
    sl = s.size();
    tl = t.size();

    auto x = helper(0, 0);
    if (x == 0)  {
        cout << "" << endl;
        return 0;
    }
    int left =0 ;
    int right =0 ;
    string result = "";

    while (left < sl || right < tl) {
        if (s[left] == t[right]) {
            result += s[left];
            left += 1;
            right += 1;
        } else {
            if (left + 1 < sl && right + 1 < tl) {
                if (dp[left+1][right] > dp[left][right + 1]) {
                    left += 1;
                } else {
                    right += 1;
                }
            } else if (left + 1 < sl) {
                left += 1;
            } else {
                right += 1;
            }
        }
    }
    // result += 
    cout << result << endl;

    return 0;
}