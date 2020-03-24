#include <bits/stdc++.h>
using namespace std;

int c2(int x){
	return(x*(x-1))/2;
}


int main(){
	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    string s;
    int arr[26];

    for(int i=0;i<26;i++){
    	arr[i]=0;
    }

    for(int i=0;i<n;i++){
    	cin>>s;
    	arr[s[0]-'a']++;
    }

    int ans=0;
    for(int i=0;i<26;i++){
    	int asd,abc;
    	asd=arr[i]/2;
    	abc=arr[i]-asd;

    	ans+=c2(asd)+c2(abc);
    }

    cout<<ans<<endl;

}
