#include <iostream>
#include <vector>


using namespace std;

bool isPresent = false;

void binary_search_recursive(vector<int>& v,int start,int end,int target) {
    if(start > end) return;
    int mid = (start+end)/2;
    if(v[mid] == target) {
        cout<<target<<" is present at index "<<mid<<endl;
        isPresent = true;
        return;
    }
    if(target < v[mid]) binary_search_recursive(v,start,mid-1,target);
    if(target > v[mid]) binary_search_recursive(v,mid+1,end,target);
}

int main() {
    vector<int>v {-1,0,2,5,9,11,23};
    int target = 99;
    binary_search_recursive(v,0,v.size()-1,target);
    if(!isPresent) cout<<target<<" is not present"<<endl;
    return 0;
}
