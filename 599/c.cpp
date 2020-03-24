#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> primeFactors(ll n)  
{  
    vector<ll> ans;
    if(n%2==0){
        ans.push_back(2);
    }
    while (n % 2 == 0)  
    {  
        n = n/2;  
    }  


    for (int i = 3; i <= sqrt(n); i = i + 2)  
    {  
        if(n%i==0){
            ans.push_back(i);
        }
        while (n % i == 0)  
        {  
            n = n/i;  
        }  
    }  
  
    if (n > 2)  
        ans.push_back(n);
    return ans;
}  

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;

    vector<ll> myVec=primeFactors(n);

    if(myVec.size()==1){
        cout<<myVec[0]<<endl;
    }
    else{
        cout<<1<<endl;
    }
}

