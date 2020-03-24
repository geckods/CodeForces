#include <bits/stdc++.h>
using namespace std;

int findmax(int arr[],int a, int b){

	//it is inclusive

	b++;

//    vector<int> v(arr+a,arr+b);

//    sort(v.begin(),v.end());

    int n=b-a;
    int max=0;
    int ans;
    for(int i=0;i<n;i++){
//        vector<int>::iterator upper = upper_bound(v.begin(),v.end(),v[i]+5);
        int* upper = upper_bound(arr+a,arr+b,arr[a+i]+5);
        ans=(upper-(arr+a));
        if(ans-i>max) max=ans-i;
    }
	return max;
}

/*
if k->1, find maximum
else
	form 

in o(n**2 logn) time,find the best single team size for each subarray
*/

//first, suppose exactl

int max(int a,int b){
	if(a>b){
		return a;
	}
	else return b;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif

    int n,k;
    cin>>n>>k;
    int arr[n];


	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
    sort(arr,arr+n);

	int spanarr[n][n];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			spanarr[i][j]=findmax(arr,i,j);
		}
	}

//	for(int i=0;i<n;i++){
//		for(int j=i;j<n;j++){
//			cout<<i<<" "<<j<<" "<<spanarr[i][j]<<endl;
//		}
//	}

	int dparr[k][n];

	for(int i=0;i<n;i++){
		dparr[0][i]=spanarr[i][n-1];
	}

	for(int i=1;i<min(k,n);i++){
		for(int j=0;j<n;j++){
			int mymax=0;
			int ans;
			for(int z=j;z<n-1;z++){
				ans=spanarr[j][z]+dparr[i-1][z+1];
				if (ans>mymax) mymax=ans;
			}
			dparr[i][j]=max(mymax,dparr[i-1][j]);
		}
	}
/*
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			cout<<i<<" "<<j<<" "<<dparr[i][j]<<endl;
		}
	}
*/

	cout<<dparr[min(k,n)-1][0]<<endl;
}