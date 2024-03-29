
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int mc(int **dp, int *nums, int lo, int hi)
{
    if (lo > hi)
        return 0;

    if (dp[lo][hi] != -1)
        return dp[lo][hi];
    
    int j;
    
    dp[lo][hi] = 0;
    for (j = lo; j <= hi; j++) {
        int left = mc(dp, nums, lo, j - 1);
        int right = mc(dp, nums, j + 1, hi);
        int curr = nums[lo - 1] * nums[j] * nums[hi + 1] + left + right;
        dp[lo][hi] = MAX(dp[lo][hi], curr);
    }
    
    return dp[lo][hi];
}

int maxCoins(int* nums, int N)
{
    int *nums2 = malloc(sizeof(int) * (N + 2));
    int **dp = malloc(sizeof(int *) * (N + 2));
    int i, j;
    
    // add 1 before and after nums
    nums2[0] = 1;
    for (i = 0; i < N; i++) {
        nums2[i + 1] = nums[i];
    }
    nums2[N + 1] = 1;
    
    for (i = 0; i < (N + 2); i++) {
        dp[i] = malloc((N + 2) * sizeof(int));
        for (j = 0; j < (N + 2); j++) {
            dp[i][j] = -1;
        }
    }
    
    return mc(dp, nums2, 1, N);
}