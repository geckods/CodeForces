#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	string a,b;
   	cin>>a;
   	cin>>b;

   	int alen=a.length();
   	int blen=b.length();

   	int count[alen-blen+1];
   	memset(count,0,sizeof(count));

   	int onecount=0;
   	for(int i=a.length()-1;i>=alen-blen;i--){
   		if(a[i]=='1'){
   			onecount++;
   		}
   	}

   	count[alen-blen]=onecount;

   	for(int i=alen-blen-1;i>=0;i--){
   		if(a[i+blen]=='1')onecount--;
   		if(a[i]=='1')onecount++;
   		count[i]=onecount;
   	}

   	int bcount=0;
   	for(int i=0;i<blen;i++){
   		if(b[i]=='1')bcount++;
   	}

   	int ans=0;
   	for(int i=0;i<=alen-blen;i++){
   		if(bcount%2==count[i]%2){
   			ans++;
   		}
   	}

   	cout<<ans<<endl;
}