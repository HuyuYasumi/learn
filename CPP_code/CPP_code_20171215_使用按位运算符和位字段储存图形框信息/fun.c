#include "fun.h"

void show_settings(const struct box_props * pb)
{
    printf("Box is %s.\n", pb->opaque == true ? "opaque":"transparent");
    printf("The fill color is %s.\n", colors[pb->fill_color]);
    printf("Border %s.\n", pb->show_border == true ? "shown":"not shown");
    printf("The border color is %s.\n", colors[pb->border_color]);
    printf("The border style is");
    switch(pb->border_style) {
        case SOLID:printf("solid.\n");break;
        case DOTTEN:printf("dotted.\n");break;
        case DASHED:printf("dashed.\n");break;
        default:printf("unknown type.\n");
    }
}
void show_settings1(unsigned short us)
{
    printf("box is %s.\n", (us&OPAQUE) == OPAQUE ? "opaque":"transparent");
    printf("The fill color is %s.\n", colors[(us>>1)&07]);
    printf("Border %s.\n", (us&BORDER) == BORDER ? "shown":"not shown");
    printf("The border style is ");
    switch(us&STYLE_MASK) {
        case B_SOLID:printf("solid.\n");break;
        case B_DOTTED:printf("dotted.\n");break;
        case B_DASHED:printf("dashed.\n");break;
        default:printf("unknown type.\n");
    }
    printf("The border color is %s.\n", colors[(us>>9)&07]);
}
char * itobs(int n, char * ps)
{
    int i;
    const static int size=CHAR_BIT*sizeof(int);
    for(i=size-1; i >= 0; i--, n>>=1) ps[i]=(01&n)+'0';
    ps[size]='\0';
    return ps;
}
