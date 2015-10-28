#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,res=0;
        cin>>n;
        while(n>0)
        {
            if(n==2)
            {
                res+=2;
                break;
            }
            if(n%2==0)
            {
                n/=2;
            }
            else
            {
                n=(n/2)+1;
            }
            res++;
        }
        cout<<res<<endl;

    }
    return 0;
}
