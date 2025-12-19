#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin >> n;

    vector<double> x(n), f(n), cf(n);
    for(int i=0;i<n;i++) cin >> x[i];
    for(int i=0;i<n;i++) cin >> f[i];

    double ch;
    cin >> ch;

    double xx, yy;
    cin >> xx >> yy;

    cf[0]=f[0];
    for(int i=1;i<n;i++) cf[i]=cf[i-1]+f[i];

    vector<vector<double>> d(n, vector<double>(n));
    for(int i=0;i<n;i++) d[i][0]=cf[i];

    for(int j=1;j<n;j++)
        for(int i=n-1;i>=j;i--)
            d[i][j]=d[i][j-1]-d[i-1][j-1];

    cout<<"Backward Difference Table (upto 70-80)\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++)
            cout<<fixed<<setprecision(2)<<d[i][j]<<" ";
        cout<<"\n";
    }

    double h=x[1]-x[0];
    double u=(ch-x[n-1])/h;

    double cff=d[n-1][0], term=1;
    for(int i=1;i<n;i++){
        term*=(u+i-1)/i;
        cff+=term*d[n-1][i];
    }

    double cfff=cf[n-2];
    double ans1=cff-cfff;

    cout<<"\nStudents between 40 and 45 = "<<fixed<<setprecision(3)<<ans1<<"\n";

    x.push_back(xx);
    f.push_back(yy);
    cf.push_back(cf.back()+yy);
    n++;

    vector<vector<double>> d2(n, vector<double>(n));
    for(int i=0;i<n;i++) d2[i][0]=cf[i];

    for(int j=1;j<n;j++)
        for(int i=n-1;i>=j;i--)
            d2[i][j]=d2[i][j-1]-d2[i-1][j-1];

    cout<<"\nBackward Difference Table (with 80-90)\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++)
            cout<<fixed<<setprecision(2)<<d2[i][j]<<" ";
        cout<<"\n";
    }

    u=(ch-x[n-1])/h;
    double cffn=d2[n-1][0];
    term=1;

    for(int i=1;i<n;i++){
        term*=(u+i-1)/i;
        cffn+=term*d2[n-1][i];
    }

    double ans2=cffn-cfff;

    cout<<"\nNew Students between 40 and 45 = "<<fixed<<setprecision(3)<<ans2<<"\n";
    cout<<"\nNumerical Error = "<<fixed<<setprecision(3)<<fabs(ans2-ans1)<<"\n";

    return 0;
}
