#include <bits/stdc++.h>
using namespace std;

int main(){

	// #ifndef ONLINE_JUDGE
 //    	freopen("input", "r", stdin);
 //    	freopen("output", "w", stdout);
	// #endif
	// ios_base::sync_with_stdio(false);
 //   	cin.tie(NULL);

   	int arr[6]={4,8,15,16,23,42};

   	int ans1;
   	int ans2;
   	cout<<"? 1 2"<<endl;
   	fflush(stdout);
   	cin>>ans1;
   	cout<<"? 1 3"<<endl;
   	fflush(stdout);
   	cin>>ans2;

   	int myarr[6];

   	for(int i=0;i<6;i++){
   		bool thisis1=false;
   		bool seen1=false;
   		bool seen2=false;
   		for(int j=0;j<6;j++){
   			if(i==j)continue;
   			if(arr[i]*arr[j]==ans1){
   				seen1=true;
   			}
   			if(arr[i]*arr[j]==ans2){
   				seen2=true;
   			}

   			if(seen1&&seen2){
   				myarr[0]=arr[i];
   				myarr[1]=ans1/arr[i];
   				myarr[2]=ans2/arr[i];
   				thisis1=true;
   				break;
   			}
   		}
   		if(thisis1)break;
   	}

   	int ans3;
   	int ans4;
   	cout<<"? 4 5"<<endl;
   	fflush(stdout);
   	cin>>ans3;
   	cout<<"? 4 6"<<endl;
   	fflush(stdout);
   	cin>>ans4;


   	for(int i=0;i<6;i++){
   		bool thisis4=false;
   		bool seen3=false;
   		bool seen4=false;
   		for(int j=0;j<6;j++){
   			if(i==j)continue;
   			if(arr[i]*arr[j]==ans3){
   				seen3=true;
   			}
   			if(arr[i]*arr[j]==ans4){
   				seen4=true;
   			}

   			if(seen3&&seen4){
   				myarr[3]=arr[i];
   				myarr[4]=ans3/arr[i];
   				myarr[5]=ans4/arr[i];
   				thisis4=true;
   				break;
   			}
   		}
   		if(thisis4)break;
   	}

 	cout<<"! "<<endl;
   	for(int i=0;i<6;i++){
   		cout<<myarr[i]<<" ";
   	}
   	cout<<endl;
}

