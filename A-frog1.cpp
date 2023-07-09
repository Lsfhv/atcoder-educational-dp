#include <iostream>
#include <locale>
#include <vector>
using namespace std;

int n;
vector<int> arr;
int dp[100000 + 1];
int helper(int i) {
    if (i <= 0) {
        return 0;
    } 
    if (dp[i] != -1) return dp[i];
    int current = arr[i];

    int q = abs(current - arr[i - 1]) + helper(i - 1);
    if (i > 1) {
        q = min(q, abs(current - arr[i - 2]) + helper(i - 2));
    }
    dp[i] = q;
    return q;
}

int main() {
    cin >> n;
    for (int i = 0; i < 100000 + 1; i++) dp[i] = -1;
    for (int i =0 ; i < n;i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << helper(n - 1) << endl;

    return 0;
}