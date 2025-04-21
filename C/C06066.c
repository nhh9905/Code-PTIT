#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* add(const char* a, const char* b)
{
    int l = strlen(a), r = strlen(b), carry = 0;
    int max_len = l > r ? l : r;
    char* tong = (char*)malloc((max_len + 2) * sizeof(char));
    memset(tong, '0', max_len + 1);
    tong[max_len + 1] = '\0';
    char* num1 = (char*)malloc((max_len + 1) * sizeof(char));
    char* num2 = (char*)malloc((max_len + 1) * sizeof(char));
    memset(num1, '0', max_len);
    memset(num2, '0', max_len);
    num1[max_len] = '\0';
    num2[max_len] = '\0';
    strncpy(num1 + max_len - l, a, l);
    strncpy(num2 + max_len - r, b, r);
    for (int i = max_len - 1; i >= 0; i--)
    {
        int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
        tong[i + 1] = (sum % 10) + '0';
        carry = sum / 10;
    }
    if (carry)
        tong[0] = carry + '0';
    else
        memmove(tong, tong + 1, max_len + 1);
    free(num1);
    free(num2);  
    return tong;
}
void tach(char s[])
{
    int k = strlen(s) / 2;
    char a[205] = {0}, b[205] = {0};
    strncpy(a, s, k);
    strncpy(b, s + k, strlen(s) - k);
    char* result = add(a, b);
    strcpy(s, result);
    printf("%s\n", s);
    free(result);
    if (strlen(s) != 1)
        tach(s);
}
int main()
{
    char s[205];
    scanf("%s", s);
    tach(s);
    return 0;
}