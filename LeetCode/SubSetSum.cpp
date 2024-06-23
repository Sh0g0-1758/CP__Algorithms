bool checksubset(int n,int k,vector<int>&a,int currsum,int currindex){
    if(currsum==k and currindex<=n){
        return true;
    }
    if(currsum>k or currindex==n){
        return false;
    }
    if(checksubset(n,k,a,currsum+a[currindex],currindex+1)){
        return true;
    }
    if(checksubset(n,k,a,currsum,currindex+1)){
        return true;
    }
    return false;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    return checksubset(n,k,a,0,0);
}