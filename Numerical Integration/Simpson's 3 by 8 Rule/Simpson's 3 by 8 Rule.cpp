#include <bits/stdc++.h>
using namespace std;

double f(double x){
    return 1.0/(1+x*x);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    double a,b;
    int n;
    cin>>a>>b>>n;

    double h=(b-a)/n;
    double sum=f(a)+f(b);

    for(int i=1;i<n;i++){
        double x=a+i*h;
        if(i%3==0) sum+=2*f(x);
        else sum+=3*f(x);
    }

    double result=(3*h/8)*sum;
    cout<<"The Result is "<<fixed<<setprecision(6)<<result;
    return 0;
}
