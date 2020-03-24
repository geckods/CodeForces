#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
    	freopen("input", "r", stdin);
    	freopen("output", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);

   	int n;
   	cin>>n;

   	int arr[10];

   	memset(arr,0,sizeof(arr));

   	string s;
   	cin>>s;

   	for(int i=0;i<n;i++){
   		if(s[i]=='L'){
   			int i=0;
   			while(arr[i])i++;
   			arr[i]=1;
   		}
   		else if (s[i]=='R'){
   			int i=9;
   			while(arr[i])i--;
   			arr[i]=1;
   		}
   		else{
   			arr[s[i]-'0']=0;
   		}
   	}

   	for(int i=0;i<10;i++){
   		cout<<arr[i];
   	}
   	cout<<endl;

}
