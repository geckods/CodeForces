ll getSumUtil(ll *st, ll ss, ll se, ll qs, ll qe, ll si)  
{  
    // If segment of this node is a part of given range, then return  
    // the sum of the segment  
    if (qs <= ss && qe >= se)  
        return st[si];  
  
    // If segment of this node is outside the given range  
    if (se < qs || ss > qe)  
        return 0;  
  
    // If a part of this segment overlaps with the given range  
    ll mid = getMid(ss, se);  
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +  
        getSumUtil(st, mid+1, se, qs, qe, 2*si+2);  
}  
  
/* A recursive function to update the nodes which have the given  
index in their range. The following are parameters  
    st, si, ss and se are same as getSumUtil()  
    i --> index of the element to be updated. This index is  
            in the input array.  
diff --> Value to be added to all nodes which have i in range */
void updateValueUtilSUM(ll *st, ll ss, ll se, ll i, ll diff, ll si)  
{  
    // Base Case: If the input index lies outside the range of  
    // this segment  
    if (i < ss || i > se)  
        return;  
  
    // If the input index is in range of this node, then update  
    // the value of the node and its children  
    st[si] = st[si] + diff;  
    if (se != ss)  
    {  
        ll mid = getMid(ss, se);  
        updateValueUtilSUM(st, ss, mid, i, diff, 2*si + 1);  
        updateValueUtilSUM(st, mid+1, se, i, diff, 2*si + 2);  
    }  
}  
  
// The function to update a value in input array and segment tree.  
// It uses updateValueUtil() to update the value in segment tree  
void updateValueSUM(ll arr[], ll *st, ll n, ll i, ll new_val)  
{  
    // Check for erroneous input index  
    if (i < 0 || i > n-1)  
    {  
        cout<<"Invalid Input";  
        return;  
    }  
  
    // Get the difference between new value and old value  
    ll diff = new_val - arr[i];  
  
    // Update the value in array  
    arr[i] = new_val;  
  
    // Update the values of nodes in segment tree  
    updateValueUtilSUM(st, 0, n-1, i, diff, 0);  
}  
  
// Return sum of elements in range from index qs (quey start)  
// to qe (query end). It mainly uses getSumUtil()  
ll getSum(ll *st, ll n, ll qs, ll qe)  
{  
    // Check for erroneous input values  
    if (qs < 0 || qe > n-1 || qs > qe)  
    {  
        cout<<"Invalid Input";  
        return -1;  
    }  
  
    return getSumUtil(st, 0, n-1, qs, qe, 0);  
}  
  
// A recursive function that constructs Segment Tree for array[ss..se].  
// si is index of current node in segment tree st  
ll constructSTUtilSUM(ll arr[], ll ss, ll se, ll *st, ll si)  
{  
    // If there is one element in array, store it in current node of  
    // segment tree and return  
    if (ss == se)  
    {  
        st[si] = arr[ss];  
        return arr[ss];  
    }  
  
    // If there are more than one elements, then recur for left and  
    // right subtrees and store the sum of values in this node  
    ll mid = getMid(ss, se);  
    st[si] = constructSTUtilSUM(arr, ss, mid, st, si*2+1) +  
            constructSTUtilSUM(arr, mid+1, se, st, si*2+2);  
    return st[si];  
}  
  
/* Function to construct segment tree from given array. This function  
allocates memory for segment tree and calls constructSTUtil() to  
fill the allocated memory */
ll *constructSTSUM(ll arr[], ll n)  
{  
    // Allocate memory for the segment tree  
  
    //Height of segment tree  
    ll x = (ll)(ceil(log2(n)));  
  
    //Maximum size of segment tree  
    ll max_size = 2*(ll)pow(2, x) - 1;  
  
    // Allocate memory  
    ll *st = new ll[max_size];  
  
    // Fill the allocated memory st  
    constructSTUtilSUM(arr, 0, n-1, st, 0);  
  
    // Return the constructed segment tree  
    return st;  
}