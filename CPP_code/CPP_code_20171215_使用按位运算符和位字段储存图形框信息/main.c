#include "fun.h"

int main()
{
    union Views box={{true, YELLOW, true, GREEN, DASHED}};
    char bin_str[8*sizeof(unsigned int)+1];
    printf("Original box settings:\n");
    show_settings(&box.st_view);
    printf("\nBox settings using unsigned int view:\n");
    show_settings1(box.us_view);
    printf("bits are %s\n", itobs(box.us_view, bin_str));
    box.us_view &= ~FILL_MASK;
    box.us_view |= (FILL_BLUE|FILL_GREEN);
    box.us_view ^= OPAQUE;
    box.us_view |= BORDER_RED;
    box.us_view &= ~STYLE_MASK;
    box.us_view |= B_DOTTED;
    printf("\nModified box settings:\n");
    show_settings(&box.st_view);
    printf("\nBox settings using unsigned int view:\n");
    show_settings1(box.us_view);
    printf("bits are %s\n", itobs(box.us_view, bin_str));
    return 0;
}
