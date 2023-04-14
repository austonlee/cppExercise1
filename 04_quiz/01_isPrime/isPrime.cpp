#include<iostream>
using namespace std;

void isPrime(int n)
{
    if(n==1)
    {
        cout<<"Yes"<<endl;
    }
    else{
        for (int i = 2; i < n; i++){
            if(n%i==0)
            {
                cout<<"No"<<endl;
                return;
            }
        }
        cout<<"Yes"<<endl;
    }
    return;
}

int main()
{
    int n;
    while( cin >> n )
    {
        isPrime(n);
    }

    return 0;
}