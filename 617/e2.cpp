#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> intpair;

int GetCeilIndex(vector<int> arr, vector<int>& T, int l, int r, 
                 int key) 
{ 
    while (r - l > 1) { 
        int m = l + (r - l) / 2; 
        if (arr[T[m]] <= key) 
            r = m; 
        else
            l = m; 
    } 
  
    return r; 
} 
  
vector<int> LongestIncreasingSubsequence(vector<int> arr) 
{ 
    // Add boundary case, when array n is zero 
    // Depend on smart pointers 
    int n=arr.size();
  
    vector<int> tailIndices(n, 0); // Initialized with 0 
    vector<int> prevIndices(n, -1); // initialized with -1 
  
    int len = 1; // it will always point to empty location 
    for (int i = 1; i < n; i++) { 
        if (arr[i] > arr[tailIndices[0]]) { 
            // new smallest value 
            tailIndices[0] = i; 
        } 
        else if (arr[i] < arr[tailIndices[len - 1]]) { 
            // arr[i] wants to extend largest subsequence 
            prevIndices[i] = tailIndices[len - 1]; 
            tailIndices[len++] = i; 
        } 
        else { 
            // arr[i] wants to be a potential condidate of 
            // future subsequence 
            // It will replace ceil value in tailIndices 
            int pos = GetCeilIndex(arr, tailIndices, -1, 
                                   len - 1, arr[i]); 
  
            prevIndices[i] = tailIndices[pos - 1]; 
            tailIndices[pos] = i; 
        } 
    } 
  
  	vector<int> ans;
    for (int i = tailIndices[len - 1]; i >= 0; i = prevIndices[i]) 
    	ans.push_back(i);
        // cout << arr[i] << " "; 
    // cout << endl; 
    reverse(ans.begin(),ans.end());
  
    return ans; 
}


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

    vector<int> arr(n);
    vector<int> ogarr(n);

    for(int i=0;i<n;i++){
    	ogarr[i]=arr[i]=s[i]-'a';
    }

    vector<int> newArr;
    int assign[n];
    memset(assign,0,sizeof(assign));

    int j=1;

    vector<int> temp=LongestIncreasingSubsequence(ogarr);
    for(int i=0;i<temp.size();i++){
    	cout<<temp[i]<<endl;
    }


}