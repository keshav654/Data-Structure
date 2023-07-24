#include <iostream>
#include <climits>

class Solution {
public:
    int minDifference(int arr[], int N) {
        int i, j, sum= 0;
        for (i = 0; i < N; i++)
            sum += arr[i];

        bool dp[N + 1][sum + 1];

        for (j = 0; j <= sum; j++)
            dp[0][j] = false;

        for (i = 0; i <= N; i++)
            dp[i][0] = true;

        for (i = 1; i <= N; i++) {
            for (j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        int minimum = INT_MAX;
        for (j = 0; j <= sum; j++) {
            if (dp[N][j] == true)
                minimum = std::min(minimum, abs(j - (sum - j)));
        }

        return minimum;
    }
};

int main() {
    int arr[] = {1, 6, 11, 5};
    int N = sizeof(arr) / sizeof(arr[0]);

    Solution obj;
    int minDiff = obj.minDifference(arr, N);

    std::cout << "Minimum difference: " << minDiff << std::endl;

    return 0;
}