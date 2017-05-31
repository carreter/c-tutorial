#include <stdio.h>

#define IN      1
#define OUT     0
#define MAXLEN  100

/* Count word length and print in histogram */

main()
{
    int c, i, l, x, lword, state;
    int nlength[MAXLEN];

    lword = l = 0;
    state = OUT;
    for (i = 0; i < MAXLEN; ++i)
        nlength[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                state = OUT;
                ++nlength[l];
                l = 0;
            }   
        } else {
            state = IN;
            ++l;
        }
    }

    for (i = MAXLEN; i > 0; --i) {
        if (nlength[i] > 0) {
            lword = i;
            break;
        }
    }

    printf("Inputs had words of length:\n");
    for (i = 1; i <= lword; ++i) {
        printf("%3d:", i);
        for (x = 0; x < nlength[i]; ++x) {
            printf("\u2588");
        }
        printf("\n");
    }
}
