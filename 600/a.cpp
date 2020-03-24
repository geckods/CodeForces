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

   	int t;
   	cin>>t;

   	for(int test=0;test<t;test++){
   		int stage=1;
   		int n;
   		cin>>n;

   		int a[n];
   		int b[n];

   		for(int i=0;i<n;i++){
   			cin>>a[i];
   		}

   		for(int i=0;i<n;i++){
   			cin>>b[i];
   		}

   		bool works=true;
   		int currk=0;
   		for(int i=0;i<n;i++){
   			if(a[i]>b[i]){
   				works=false;
   				break;
   			}
   			if(stage==1){
   				if(a[i]<b[i]){
   					stage=2;
   					currk=b[i]-a[i];
   				}
   			}
   			else if (stage==2){
   				if(a[i]<b[i]){
   					if(b[i]-a[i]!=currk){
   						works=false;
   						break;
   					}
   				}
   				else if (a[i]==b[i]){
   					stage=3;
   				}
   			}
   			else{
   				if(a[i]<b[i]){
   					works=false;
   					break;
   				}
   			}
   		}

   		if(works){
   			cout<<"YES"<<endl;
   		}
   		else{
   			cout<<"NO"<<endl;
   		}


   	}

}
