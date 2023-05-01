#include <stdio.h>
#include <string.h>

int main()
{
    char t[30];
    char p[30];
    int i, j;
    printf("Enter Text:- ");
    gets(t);
    printf("\nEnter Pattern:- ");
    gets(p);
    int m = strlen(p);
    int n = strlen(t);
    int max_shifts = n - m + 1;

    for (i = 0; i <= max_shifts; i++) {
        for (j = 0; j < m; j++) {
            if (t[i + j] != p[j])
                break;
        }
        if (j == m) {
            printf("Pattern found at index %d\n", i+1);
        }
    }
    printf("Maximum possible shifts: %d\n", max_shifts);
    return 0;
}
