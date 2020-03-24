/*
Vasya has a sequence 𝑎 consisting of 𝑛 integers 𝑎1,𝑎2,…,𝑎𝑛. Vasya may pefrom the following operation: choose some number from the sequence and swap any pair of bits in its binary representation. For example, Vasya can transform number 6 (…000000001102) into 3 (…000000000112), 12 (…0000000011002), 1026 (…100000000102) and many others. Vasya can use this operation any (possibly zero) number of times on any number from the sequence.

Vasya names a sequence as good one, if, using operation mentioned above, he can obtain the sequence with bitwise exclusive or of all elements equal to 0.

For the given sequence 𝑎1,𝑎2,…,𝑎𝑛 Vasya'd like to calculate number of integer pairs (𝑙,𝑟) such that 1≤𝑙≤𝑟≤𝑛 and sequence 𝑎𝑙,𝑎𝑙+1,…,𝑎𝑟 is good.
*/
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

    int n;
    cin>>n;

    // if(n==1){
    // 	cout<<0<<endl;
    // 	return 0;
    // }

    ll arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
    }

    int onecount[n];
    memset(onecount,0,sizeof(int)*n);

    for(int i=0;i<n;i++){
    	while(arr[i]>0){
    		onecount[i]+=(arr[i]%2);
    		arr[i]/=2;
    	}
    }

    int oddcount=0;
    int evencount=0;
    ll ans=0;

    // for(int i=0;i<n;i++){
    // 	cout<<onecount[i]<<endl;
    // }

    int cumonecount[n+1];
    cumonecount[n]=0;
    int cum=0;
    for(int i=n-1;i>=0;i--){
    	cum+=onecount[i];
    	cumonecount[i]=cum;
    }

    for(int i=n-2;i>=0;i--){
    	if(cumonecount[i+2]%2==0){
    		evencount++;
    	}
    	else{
    		oddcount++;
    	}

    	if(cumonecount[i]%2==0){
    		ans+=evencount;
    	}
    	else{
    		ans+=oddcount;
    	}
    }

    for(int i=n-1;i>=0;i--){
    	int sum=0;
    	int max=0;
    	for(int j=i;j<min(n,i+62);j++){
    		sum+=onecount[j];
    		if(onecount[j]>max)max=onecount[j];
    		if(j>i && max>(sum-max)){
    			if((cumonecount[i]-cumonecount[j+1])%2 == 0){
//    				cout<<i<<" "<<j<<endl;
	    			ans--;
	    		}
    		}
    	}
    }

    cout<<ans<<endl;
}


/*
//This solution underestimates the answer


    int howmanybits[n][60];
    for(int i=0;i<n;i++){
    	for(int j=0;j<60;j++){
    		howmanybits[i][j]=0;
    	}
    }

    for(int i=0;i<n;i++){
    	howmanybits[i][onecount[i]]=1;
    }

    int cumulatebitcount[n][60];
    for(int i=0;i<n;i++){
    	for(int j=0;j<60;j++){
    		cumulatebitcount[i][j]=0;
    	}
    }

    for(int j=0;j<60;j++){
    	int cumulate=0;
    	for(int i=0;i<n;i++){
    		cumulate+=howmanybits[i][j];
    		cumulatebitcount[i][j]=cumulate%2;
    	}
    }

    ll dp[n];
    memset(dp,0,sizeof(ll)*n);

    for(int i=0;i<n;i++){
    	for(int j=0;j<60;j++){
    		dp[i]+=cumulatebitcount[i][j]*pow(2,j);
    	}
    }

    unordered_map<ll,int> myMap;

    ll ans=0;
    for(int i=0;i<n;i++){
    	ans+=myMap[dp[i]];
    	myMap[dp[i]]++;
    }

    cout<<ans<<endl;
*/

//revelation after looking at the editorial:
//    a given subsequence works if the total number of ones is even, and the largest number of ones <= sum of all others
//    condition 1 because there will be an unpaired 1 otherwise
//    condition 2 is necessary because if it is not met, then the biggest list of ones will never get covered.
//    and if it is met, then after the biggest number of ones is covered, there will be an even number of leftover ones which can cancel each other out
