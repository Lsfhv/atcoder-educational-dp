#include <iostream>
#include <vector>
using namespace std;
int n,m;

vector<int> values;
vector<int> weights;

 long long int dp[100 + 1][100000 + 1];

long long int helper(int pointer, int weight) {
    
    if (pointer == n) return 0;
    
    if (dp[pointer][weight] != -1) return dp[pointer][weight];

     long long int q = 0;

    q = max(q, helper(pointer +1 ,weight));
    if (weight - weights[pointer] >=0) {
        q= max(q, values[pointer] + helper(pointer +1, weight - weights[pointer]));
    }
    dp[pointer][weight] = q;
    return q;
}

int main() {
    for (int i = 0; i <= 100;i++) {
        for (int j = 0; j <= 100000;j++) {
            dp[i][j] = -1;
        }
    }
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int left,right;
        cin>>left>>right;
        values.push_back(right);
        weights.push_back(left);
    }

    cout << helper(0, m) << endl;

    return 0;
}