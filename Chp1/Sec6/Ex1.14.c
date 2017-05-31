#include <stdio.h>

main()
{
    int c, x, i, ntab, nnl, nblank, nother;
    int nletter[26], ndigit[10];

    for (i = 0; i < 26; ++i)
        nletter[i] = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;
    ntab = nnl = nblank = nother = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c >= 'a' && c <= 'z')
            ++nletter[c - 'a'];
        else if (c >= 'A' && c <= 'Z')
            ++nletter[c - 'A'];
        else if (c == ' ')
            ++nblank;
        else if (c == '\n')
            ++nnl;
        else if (c == '\t')
            ++ntab;
        else
            ++nother;
    }

    printf("Occurences of each character in input: \n");
    for (i = 0; i < 26; ++i) {
        printf("%8c:", 'a' + i);
        for (x = 0; x < nletter[i]; ++x)
            printf("\u2588");
        printf("\n");
    }

    for (i = 0; i < 10; ++i) {
        printf("%8d:", i);
        for (x = 0; x < ndigit[i]; ++x)
            printf("\u2588");
        printf("\n");
    }

    printf("%8s:", "Tabs");
    for (i = 0; i < ntab; ++i)
        printf("\u2588");
    printf("\n");

    printf("%8s:", "Newlines");
    for (i = 0; i < nnl; ++i)
        printf("\u2588");
    printf("\n");

    printf("%8s:", "Blanks");
    for (i = 0; i < nblank; ++i)
        printf("\u2588");
    printf("\n");

    printf("%8s:", "Other");
    for (i = 0; i < nother; ++i)
        printf("\u2588");
    printf("\n");

}
