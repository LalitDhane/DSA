#include<bits/stdc++.h>
using namespace std;

//Iterative 
int binary_search (vector<int>& v,int start,int end,int target) 
{
    //if target is not present return -1
    int ans = -1;  
            
    while(start <= end) 
    {
        int mid = (start+end) / 2;
        if(v[mid] == target) 
            return mid;
        else if(target < v[mid]) 
            end = mid - 1;
        else 
            start = mid + 1;
    }
    return ans;
}

int main()
{   
    vector<int> v {2,7,9,14,28,37,43,59,71};
    int target;
    cin>>target;
    cout<<binary_search(v,0,v.size()-1,target);
    return 0;
}