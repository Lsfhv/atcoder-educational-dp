#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int k;
int dp[100000 + 1];
int helper(int i) {
    if (i == 0) {
        return 0;
    }   
    if (dp[i] != -1) return dp[i];
    int current = arr[i];
    int q = abs(current - arr[i - 1]) + helper(i - 1);

    for (int j = 2; j <= k; j++) {
        if (i - j < 0) {
            break;
        }
        q = min(q, abs(current - arr[i - j]) + helper(i - j));
    }

    dp[i] = q;
    return q;
}

int main() {
    for (int i = 0; i <= 100000 + 1; i++) {
        dp[i] = -1;
    }
    int n;
    cin >> n;
    cin >> k;
    for (int i = 0 ; i < n;i++) {
        int x;cin >> x;
        arr.push_back(x);
    }

    cout << helper(n - 1) << endl;

    return 0;
}