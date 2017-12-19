#include "test1a.h"

void show_font(const struct font * pf)
{
    ONEL;
    printf("   %.3d", pf->id);
    printf(" %.4d", pf->size);
    switch(pf->al) {
        case LEFT:
            printf("   left   "); break;
        case CENTER:
            printf("  center  "); break;
        case RIGHT:
            printf("   right  "); break;
    }
    printf(" %s", pf->bold ? "on ":"off");
    printf(" %s", pf->it ? "on ":"off");
    printf(" %s", pf->un ? "on ":"off");
    putchar('\n');
}
