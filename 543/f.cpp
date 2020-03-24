#include <bits/stdc++.h>
using namespace std;
// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(char* pat, int M, int* lps) 
{ 
    // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
}

int KMPSearch(char* pat, char* txt) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
  
    // create lps[] that will hold the longest prefix suffix 
    // values for pattern 
    int lps[M]; 
  
    // Preprocess the pattern (calculate lps[] array) 
    computeLPSArray(pat, M, lps); 
  
    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) { 
            return i-j;
//            printf("Found pattern at index %d ", i - j); 
            j = lps[j - 1]; 
        } 
  
        // mismatch after j matches 
        else if (i < N && pat[j] != txt[i]) { 
            // Do not match lps[0..lps[j-1]] characters, 
            // they will match anyway 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
    return -1;
} 

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input", "r", stdin);
        freopen("output", "w", stdout);
    #endif


    int n,a,b;
    cin>>n>>a>>b;
    string mainstr;
    cin>>mainstr;

    int better = b/a;
//substrings must be of length greater than better to be bettter encoded

    char* before= (char*)malloc(sizeof(char)*(n+1));
    char* substr = (char*)malloc(sizeof(char)*(better+2));
    substr[better+1]='\0';

    int ans=0;
    int issub;

    int howlong;
    set<int> doneset;

    int i=0;
    //for(int i=0;i<n-(better+1);i++){
    while(i<n){
        howlong=0;
        before[i]='\0';

//        cout<<i<<endl;

        if(doneset.find(i)==doneset.end()){
//            cout<<i<<endl;
            for(int j=0;j<=better;j++){
                substr[j]=mainstr[i+j];
            }

            issub=KMPSearch(substr,before);
//            cout<<i<<" "<<issub<<" "<<before<<" "<<substr<<endl;
            if(issub==-1 || i==0){
                ans+=a;
            }
            else{
                while(before[issub+howlong]!='\0' && i+howlong<n && before[issub+howlong]==mainstr[i+howlong]) howlong++;
//                cout<<howlong<<endl;
                ans+=b;
                for(int j=i;j<i+howlong;j++){
                    doneset.insert(j);
                }
            }
        }

        before[i]=mainstr[i];
        i++;
    }

    cout<<ans<<endl;

/*
    char txt[] = "ABABDABACDABABCABAB"; 
    char pat[] = "ABABCABAB";

    cout<<KMPSearch(pat, txt)<<endl; 
*/
}