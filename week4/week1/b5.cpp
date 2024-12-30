#include <stdio.h>

int check(int n, int k, int arr[]) {
    int sum = 0;
    int count = 0;

    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    if (sum % 2 == 0) {
        count++;
    }

    for (int i = 1; i <= n - k; i++) {
        sum = sum - arr[i - 1] + arr[i + k - 1];

        if (sum % 2 == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = check(n, k, arr);
    printf("%d\n", result);

    return 0;
}

