 #include <stdio.h>

#define MAX_WEIGHT 100
#define MAX_ITEMS 100

int max(int a, int b) {
    return (a > b)? a : b;
}

int knapsack(int weights[], int values[], int n, int W) {
    int dp[W + 1][n + 1];

    // Initialize the dp table
    for (int i = 0; i <= W; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill the dp table
    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= n; j++) {
            if (weights[j - 1] <= i) {
                dp[i][j] = max(values[j - 1] + dp[i - weights[j - 1]][j - 1], dp[i][j - 1]);
            } else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    return dp[W][n];
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    if (n > MAX_ITEMS || W > MAX_WEIGHT) {
        printf("Error: n or W is too large.\n");
        return 1;
    }

    int weights[n], values[n];
    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }

    int max_value = knapsack(weights, values, n, W);
    printf("Maximum value that can be put in the knapsack: %d\n", max_value);

    return 0;
}