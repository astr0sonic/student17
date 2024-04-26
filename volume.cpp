#include "volume.h"

int getMaxVolume(int a, int b, int c, int n, int* arr)
{
    int mx = 0;
    int st = 0;
    for (int i = 0; i + a < n; i++)
        if (min({ arr[i], arr[i+a] }) > mx && min({ arr[i], arr[i+a] }) <= c)
        {
            mx = min({ arr[i], arr[i+a] });
            st = i;
        }
    int i = st; int j = min(st + a, n - 1);
    while (i != j)
    {
        int mn = min(arr[i], arr[j]);
        if (mx < (j - i) * mn && mn <= c)
            mx = (j - i) * mn;
        if (arr[i] <= arr[j])
            i++;
        else
            j--;
    }
    return b * mx;
}