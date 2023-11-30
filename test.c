#include <stdio.h>
#include <string.h>


void print2DArray(int arr[10][10], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a character is in the alphabet
int isInAlphabet(char c) {
    return (c == 'a' || c == 'b');
}

// Function to check if a string belongs to the alphabet star
int belongsToAlphabetStar(char* str) {
    int n = strlen(str);
    int dp[n][n];

    // Initialize the dp table
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill the dp table
    for(int len = 1; len <= n; len++) {
        for(int i = 0; i <= n - len; i++) {
            int j = i + len - 1;

            // Check if the substring str[i...j] belongs to the alphabet
            if(isInAlphabet(str[j])) {
                dp[i][j] = 1;
                print2DArray(dp, n,n);
                printf("\nsingle char\n");
            }

            // Check if the substring str[i...j] can be divided into two substrings that belong to the alphabet
            for(int k = i; k < j; k++) {
                if(dp[i][k] && dp[k + 1][j]) {
                    dp[i][j] = 1;
                    print2DArray(dp, n,n);
                    printf("\nsubstring\n");
                    break;
                }
            }
        }
    }

    // Return whether the whole string belongs to the alphabet star
    return dp[0][n - 1];
}

int main() {
    char str[] = "abcba";
    if(belongsToAlphabetStar(str)) {
        printf("The string belongs to the alphabet star.\n");
    } else {
        printf("The string does not belong to the alphabet star.\n");
    }
    return 0;
}
