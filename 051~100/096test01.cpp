int numTrees(int n) {
    if(n==0) return 1;
    else if(n==1) return 1;
    else if(n==2) return 2;
    else if(n==3) return 5;
    int sol=0;
    for(int i=0;i<n;i++)
    {
        sol=sol+numTrees(i)*numTrees(n-1-i);
    }
    return sol;
}
