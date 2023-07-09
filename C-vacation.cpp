#include <iostream>
using namespace std;
int vacation[100000 + 1][3 ];
int dp[100000 +1 ][3];
int helper(int day, int i) {
    if (day == 0) return 0;
    if (dp[day][i] != -1) return dp[day][i];
    int current = vacation[day][i];
    int q = 0;
    if (i == 0) {
        q = helper(day - 1, 1);
        q = max(q, helper(day - 1, 2));
    } else if (i == 1) {
        q = helper(day - 1, 0);
        q = max(q, helper(day -1 ,2));
    } else if (i == 2) {
        q = helper(day - 1, 0);
        q = max(q, helper(day -1 ,1));
    }
    dp[day][i] = q + current;
    return q + current;
}

int main() {
    for (int i =0 ; i <= 100000 + 1; i++) {
        for (int j = 0 ; j < 3; j++) {
            dp[i][j] = -1;
        }
    }
    int n;
    cin >> n;
    for (int i =1; i <=n ;i++ ){
        cin >> vacation[i][0];
        cin >> vacation[i][1];
        cin >> vacation[i][2];
    }

    cout << max(helper(n,0), max(helper(n,1), helper(n,2))) << endl;

    return 0;
}