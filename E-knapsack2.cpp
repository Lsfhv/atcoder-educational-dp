#include <iostream>
#include <vector>
using namespace std;

vector<int> values;
vector<int> weights;

long long int inf = 1e9 + 10;

int n, weight;

long long int dp[100 + 1][1000 + 1];

int main() {
    cin >> n >> weight;
    for (int i = 0 ; i < n; i++) {
        int left,right;
        cin >>left>>right;
        weights.push_back(left);
        values.push_back(right);
    }

    for (int i = 0; i <= 100 ;i++) {
        for (int j = 0; j <= 1000 ; j++) {
            dp[i][j] = inf;
        }
    }

    for (int i = 0; i <= 100; i++) {
        dp[i][0] = 0;
    }

    values[0];
    

    for (int i = 1 ;i < n; i++) {
        int currentv = values[i ];
        int currentw = weights[i];
        for (int j = currentv; j <=1000; j++) {
            if (currentw + dp[i-1][j - currentw] <= weight) {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-currentv] + currentw);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return 0;
}