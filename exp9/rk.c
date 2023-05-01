#include <stdio.h>
#include <string.h>
#define d 256

void RK(char p[], char t[], int q)
{
    int T = strlen(t);
    int P = strlen(p); //holds the length of the pattern and string
    int hp = 0;
    int ht = 0; //hash values for pattern and string
    int i, j;
    int h = 1;

    // calculate h = d^(P-1) % q
    for (i = 0; i < P - 1; i++)
        h = (h * d) % q;

    // calculate the initial hash values for pattern and string
    for (i = 0; i < P; i++) {
        hp = (d * hp + p[i]) % q;
        ht = (d * ht + t[i]) % q;
    }

    printf("Hash value of pattern: %d\n", hp); // print hash value of pattern

    int count = 0; // number of spurious hits
    for (i = 0; i <= T - P; i++) {
        if (hp == ht) {
            for (j = 0; j < P; j++) {
                if (t[i + j] != p[j])
                    break;
            }
            if (j == P) {
                printf("Pattern found at index %d\n", i+1);
            } else {
                count++;
            }
        }
        if (i < T - P) {
            // calculate the hash value for the next window in the text
            ht = (d * (ht - t[i] * h) + t[i + P]) % q;
            if (ht < 0)
                ht += q;
        }
    }
    printf("Number of spurious hits: %d\n", count);
}

int main()
{
    char t[30];
    char p[30];
    int q;
    printf("Enter Text: ");
    gets(t);
    printf("Enter Pattern: ");
    gets(p);
    printf("Enter q: ");
    scanf("%d",&q);
    RK(p, t, q);
    return 0;
}
