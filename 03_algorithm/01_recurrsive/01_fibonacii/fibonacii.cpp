#include<iostream>
using namespace std;

//int f(int n)
void f(int n)
{
    long long fib[75];

    fib[1] = 1;
    fib[2] = 1;

    for (int i = 3; i <= n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    for (int j = 1; j <= n; j++){
        cout << fib[j] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    while( cin >> n )
    {
        f(n);
    }

    return 0;
}