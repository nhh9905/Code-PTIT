#include <stdio.h>
#include <math.h>
int main()
{
    int a1,a2,b1,b2,c1,c2;
    int totalArea;
    int x;

    
        
        scanf("%d %d", &a1, &a2);
        
        
        scanf("%d %d", &b1, &b2);
        
       
        scanf("%d %d", &c1, &c2);
        
        totalArea = a1*a2 + b1*b2 +c1*c2;

    
    if (sqrt(totalArea) == round(sqrt(totalArea))) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

// 6 10 9
// 2 3
// 1 10
// 3 3