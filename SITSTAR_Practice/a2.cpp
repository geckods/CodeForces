#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int count(string s, char c) 
{ 
    int res = 0; 
  
    for (int i=0;i<s.length();i++) 
  
        if (s[i] == c) 
            res++; 
  
    return res; 
} 

int main(){
    
    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
        freopen("error", "w", stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans=0;
    for(int i=1;i<1000;i++){
    	ans+=count(to_string(i),'1');
    	cout<<i<<" "<<ans<<endl;
    }

}