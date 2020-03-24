#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
    	freopen("error", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    string s;
    cin>>s;

    int lcount=0;
    int rcount=0;

    for(int i=0;i<n;i++){
    	if(s[i]=='L')lcount++;
    	else rcount++;
    }

    cout<<lcount+rcount+1<<endl;

}
