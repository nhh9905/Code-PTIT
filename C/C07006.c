#include <stdio.h>
#include <math.h>
typedef struct
{
    double x, y;
} point;
int check(double a, double b, double c)
{
    if (a == 0 || b == 0 || c == 0)
        return 0;
    if (a + b <= c || a + c <= b || b + c <= a)
        return 0;
    return 1;
}
point p[3];
int main() 
{
    // freopen("a.inp", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        double ab, bc, ac;
        for (int i = 0; i < 3; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        ab = sqrt((p[1].x - p[0].x)*(p[1].x - p[0].x) + (p[1].y - p[0].y)*(p[1].y - p[0].y));
        bc = sqrt((p[2].x - p[1].x)*(p[2].x - p[1].x) + (p[2].y - p[1].y)*(p[2].y - p[1].y));
        ac = sqrt((p[2].x - p[0].x)*(p[2].x - p[0].x) + (p[2].y - p[0].y)*(p[2].y - p[0].y));
        if (!check(ab, bc, ac))
            printf("INVALID\n");
        else
        {
            double p = (ab + bc + ac)/2.0;
            double s = sqrt(p*(p - ac)*(p - ab)*(p - bc));
            printf("%.2lf\n", s);
        }
    }
}