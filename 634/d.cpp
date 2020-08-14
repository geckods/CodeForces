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

    ll t;
    cin>>t;

    while(t--){
        int arr[9][9];
        string s;
        for(int i=0;i<9;i++){
            cin>>s;
            for(int j=0;j<9;j++){
                arr[i][j]=s[j]-'0';
            }
        }

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(i==0 && j==0 || i==1 && j==4 || i==2 && j==8 || i==3 && j==1 || i==4 && j==5 || i==5 && j==6 || i==6 && j==2 || i==7 && j==3 || i==8 && j==7){
                    arr[i][j]=(arr[i][j]+1);
                    if(arr[i][j]==10)arr[i][j]-=9;
                }
                cout<<arr[i][j];
            }
            cout<<endl;
        }
    }
}