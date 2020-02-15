int mySqrt(int x) {
    int a=0;int b=pow(2,16);
    long long c;
    while(true)
    {
        c=(a+b)/2;
        if(c*c>x){b=c;}
        else if((c+1)*(c+1)<=x){a=c;}
        else{return c;}
    }
}
