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

   	string s;
   	cin>>s;
   	int n = s.length();
   	string p;

   	for(int i=0;i<n;i++){
   		p+='0';
   	}

   	for(int i=0;i<n-1;i++){
   		if(s[i]=='1' && s[i+1]=='0'){
   			p[i]='1';
   		}
   	}

   	int last=n;
   	// for(int last=n;last>0;last--){
   		//consider the subsequences ending at last (exclusive)
   		int sones=0;
   		int szeroes=0;
   		int sbestz=0;
   		int sbesto=0;

   		int pones=0;
   		int pzeroes=0;
   		int pbestz=0;
   		int pbesto=0;

   		for(int i=last-1;i>=0;i--){
   			int scurr=0;
   			int pcurr=0;

   			// if(i<last-1){
   			// 	if(s[i+1]=='1')sones++;
   			// 	else szeroes++;

   			// 	if(p[i+1]=='1')pones++;
   			// 	else pzeroes++;
   			// }

   			if(s[i]=='1'){
   				scurr=1+sbesto;
   			}
   			else{
   				scurr=1+max(sbestz,sbesto);   				
   			}

   			if(p[i]=='1'){
   				pcurr=1+pbesto;
   			}
   			else{
   				pcurr=1+max(pbestz,pbesto);	
   			}

   			if(pcurr>scurr){
   				p[i]='1';
   				pcurr=1+pbesto;
   			}

   			if(s[i]=='1'){
   				sbesto=max(sbesto,scurr);
   			}
   			else{
   				sbestz=max(sbestz,scurr);
   			}

   			if(p[i]=='1'){
   				pbesto=max(pbesto,pcurr);
   			}
   			else{
   				pbestz=max(pbestz,pcurr);
   			}
   		}
   	// }

   	cout<<p<<endl;
}