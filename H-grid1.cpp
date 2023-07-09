#include <iostream>
#include <vector>
using namespace std;

int h, w;
vector<string> grid;

int dp[1000+1][1000+1];
int mod = 1e9 +7;
int helper(int i, int j) {
    if (i == h -1 && j == w - 1) {
        return 1;
    }

    if (dp[i][j] != -1) return dp[i][j];

    int q = 0;
    if (i + 1 < h && grid[i + 1][j] != '#') {
        q += helper(i + 1, j);
        while (q >= mod) q-= mod;
    }
    if (j + 1 < w && grid[i][j + 1] != '#' ) {
        q += helper(i, j + 1);
        while(q>=mod) q-=mod;
    }
    
    dp[i][j] = q;
    return q;
} 

int main() {
    for (int i = 0; i<=1000; i++) {
        for (int j = 0; j <=1000;j++) {
            dp[i][j] = -1;
        }
    }
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        string s;
        cin>>s;
        grid.push_back(s);
    }

    cout << helper(0,0) << endl;;

    return 0;
}

// At each index, count how many ways we can do down and right
// bottom corner [h][w] = 1