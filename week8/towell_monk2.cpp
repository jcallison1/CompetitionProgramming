#include <iostream>
using namespace std;

int cache[1000];

// slowest ending at N
int _slowest(int height[], int n)
{
    if (cache[n] != -1) return cache[n];
    
    if (n == 0)
        return 0;
 
    int max = 1;
    for (int i=0; i<n; i++)
        if (height[i] > height[n]) {
            int s = _slowest(height,i) + 1;
            if (s > max)
                max = s;
        }
    
    cache[n] = max;
    return max;
}

int slowest(int height[], int n)
{
    int max = 0;
    for (int i=0; i<n; i++) {
        int s = _slowest(height,i);
        if (s > max) 
            max = s;
    }
    return max;
}

int main()
{
    int h[1000];
    int n = 0;
    int x;
    
    for (int i = 0; i < 1000; i++) {
        cache[i] = -1;
    }
    
    while (cin >> x)
        h[n++] = x;
    cout << slowest(h, n) << endl;
}
