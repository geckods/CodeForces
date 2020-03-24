#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

   
vector<ll> lcs( vector<ll>X, vector<ll>Y, int m, int n ) 
{ 
   int L[m+1][n+1]; 
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (int i=0; i<=m; i++) 
   { 
     for (int j=0; j<=n; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
       else if (X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
  
   // Following code is used to print LCS 
   int index = L[m][n]; 
   // cout<<L[m][n]<<endl;
  
   // Create a character array to store the lcs string 
   ll lcs[index]; 
   // lcs[index] = '\0'; // Set the terminating character 
  
   // Start from the right-most-bottom-most corner and 
   // one by one store characters in lcs[] 
   int i = m, j = n; 
   while (i > 0 && j > 0) 
   { 
      // If current character in X[] and Y are same, then 
      // current character is part of LCS 
      if (X[i-1] == Y[j-1]) 
      { 
          lcs[index-1] = X[i-1]; // Put current character in result 
          // cout<<lcs[index-1]<<endl;
          i--; j--; index--;     // reduce values of i, j and index 
      } 
  
      // If not same, then find the larger of two and 
      // go in the direction of larger value 
      else if (L[i-1][j] > L[i][j-1]) 
         i--; 
      else
         j--; 
   } 
  
   // Print the lcs 
   // cout << "LCS of " << X << " and " << Y << " is " << lcs; 
  vector<ll> ans;
  for(int i=0;i<L[m][n];i++){
    // cout
    ans.push_back(lcs[i]);
  }
  return ans;
}    

int main(){

  #ifndef ONLINE_JUDGE
      freopen("input", "r", stdin);
      freopen("output", "w", stdout);
  #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;

  vector<ll> color;
  ll x;
  for(int i=0;i<n;i++){
    cin>>x;
    if(color.empty() || x!=color[color.size()-1]){
      color.push_back(x);
    }
  }

  n=color.size();

  vector<ll> reversecolor;
  for(int i=0;i<n;i++){
    reversecolor.push_back(color[n-1-i]);
  }

  vector<ll> thelcs = lcs(color,reversecolor,n,n);

  int z=thelcs.size();
  // int a=0;
  // int b=n-1;

  // for(int i=0;i<thelcs.size();i++){
  //   z=i;
  //   if(a>b+1) break;

  //   ll curr=thelcs[i];
  //   while(color[a]!=curr)a++;
  //   a++;
  //   while(color[b]!=curr)b--;
  //   b--;
  // }

  // cout<<z<<endl;

  // for(int i=0;i<z/2;i++){
  //   cout<<thelcs[i]<<" ";
  // }

  // int a=0;
  // int b=0;

  // while(b<=z/2){
  //   while(color[a]!=thelcs[b]){
  //     a++;
  //   }
  //   a++;
  //   b++;
  // }

  cout<<n-1-z/2<<endl;  



  // vector<ll> a;
  // a.push_back(1);  
  // a.push_back(2);
  // a.push_back(3);
  // a.push_back(4);
  // a.push_back(15);

  // vector<ll> b;
  // b.push_back(2);  
  // b.push_back(4);
  // b.push_back(1);
  // b.push_back(15);

  // vector<ll> asd = lcs(a,b,a.size(),b.size());
  // cout<<endl;
  // a.push_back(15);
}