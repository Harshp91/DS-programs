#include<stdio.h>

struct height
{
    int foot;
    int inch;
};

int main()
{
    struct height h;
    int i,x;
    struct height h1={13,11};
    struct height h2={7,8};
    h.inch=(h1.inch+h2.inch)%12;
    x=(h1.inch+h2.inch)/12; 
    h.foot=(h1.foot+h2.foot+x);

    printf("%dfoot %dinch",h.foot,h.inch);

  return 0;
}