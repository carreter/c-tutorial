#include <stdio.h>

/* counts blanks, tabs, and newlines */

main()
{
    int c, nl, tab, blank;

    nl = 0;
    tab = 0;
    blank = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++nl;
        else if (c == ' ')
            ++blank;
        else if (c =='\t')
            ++tab;
    }
    printf("Newlines: %d, Blanks: %d, Tabs: %d\n", nl, blank, tab);
}
