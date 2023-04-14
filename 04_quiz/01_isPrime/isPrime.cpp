#include<iostream>
using namespace std;

void isPrime(int n)
{
    if(n==1){
        cout<<"not prime"<<endl;
    }
    else{
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                cout<<"not prime"<<endl;
                return;
            }
        }
        cout<<"prime"<<endl;        
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