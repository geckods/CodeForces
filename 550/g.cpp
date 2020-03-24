#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int GetCeilIndex(int arr[], vector<int> &T, int l, int r, 
                 int key) 
{ 
    while (r - l > 1) 
    { 
        int m = l + (r - l)/2; 
        if (arr[T[m]] >= key) 
            r = m; 
        else
            l = m; 
    } 
  
    return r; 
} 
  
vector<int> LongestIncreasingSubsequence(int arr[], int n) 
{ 
    // Add boundary case, when array n is zero 
    // Depend on smart pointers 
  
    vector<int> tailIndices(n, 0); // Initialized with 0  
    vector<int> prevIndices(n, -1); // initialized with -1 
  
    int len = 1; // it will always point to empty location 
    for (int i = 1; i < n; i++) 
    { 
        if (arr[i] < arr[tailIndices[0]]) 
        { 
            // new smallest value 
            tailIndices[0] = i; 
        } 
        else if (arr[i] > arr[tailIndices[len-1]]) 
        { 
            // arr[i] wants to extend largest subsequence 
            prevIndices[i] = tailIndices[len-1]; 
            tailIndices[len++] = i; 
        } 
        else
        { 
            // arr[i] wants to be a potential condidate of 
            // future subsequence 
            // It will replace ceil value in tailIndices 
            int pos = GetCeilIndex(arr, tailIndices, -1, 
                                   len-1, arr[i]); 
  
            prevIndices[i] = tailIndices[pos-1]; 
            tailIndices[pos] = i; 
        } 
    } 

    vector<int> solutionVec;  

    for (int i = tailIndices[len-1]; i >= 0; i = prevIndices[i]) 
        solutionVec.push_back(arr[i]);
  
    return solutionVec; 
}

int main(){
    
    // #ifndef ONLINE_JUDGE
    //     freopen("input", "r", stdin);
    //     freopen("output", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> LIS = LongestIncreasingSubsequence(arr,n);
    reverse(LIS.begin(),LIS.end());

    vector<int> originVec;
    vector<int> remainVec;
    for(int i=0;i<n;i++){
        originVec.push_back(arr[i]);
    }

    int i=0,j=0;

    while(i<originVec.size()){
        if(j<LIS.size() && originVec[i]==LIS[j]){
            i++;
            j++;
        }
        else{
            remainVec.push_back(originVec[i]);
            i++;
        }
    }


    if(remainVec.size()==0){
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++){
            cout<<0<<" ";
        }
        cout<<endl;
        return 0;
    }

    // for(int i=0;i<LIS.size();i++){
    //     cout<<LIS[i]<<" ";
    // }
    // cout<<endl;

    // for(int i=0;i<remainVec.size();i++){
    //     cout<<remainVec[i]<<" ";
    // }
    // cout<<endl;


    for(int i=0;i<remainVec.size()-1;i++){
//    cout<<"HI"<<i<<remainVec.size()<<endl;
//    fflush(stdout);

        if(remainVec[i]<=remainVec[i+1]){
            cout<<"NO"<<endl;
            return 0;
        }
    }


    cout<<"YES"<<endl;
    i=0,j=0;
    while(i<originVec.size()){
        if(j<LIS.size() && originVec[i]==LIS[j]){
            cout<<0<<" ";
            j++;
        }
        else{
            cout<<1<<" ";
        }
        i++;
    }
    cout<<endl;
}