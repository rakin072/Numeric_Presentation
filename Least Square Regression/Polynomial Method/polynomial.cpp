#include<bits/stdc++.h>
using namespace std;

double pro(double x,double n)
{
    double temp=1;
    for(int i=0;i<n;i++)
    {
        temp*=x;
    }
    return temp;
}

vector<double> gauss(vector<vector<double>>& a,vector<double>& b)
{
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        double pivot=i;
        for(int j=i+1;j<n;j++)
        {
            if(fabs(a[j][i])>fabs(a[pivot][i]))
            {
                pivot=j;
            }
        }

        swap(a[i],a[pivot]);
        swap(b[i],b[pivot]);

        for(int j=i+1;j<n;j++)
        {
            double v=a[j][i]/a[i][i];
            for(int k=i;k<n;k++)
            {
                a[j][k]-=(v*a[i][k]);
            }
            b[j]-=(v*b[i]);
        }
    }

    vector<double>ans(n,0);

    for(int i=n-1;i>=0;i--)
    {
        double sum=b[i];
        for(int j=i+1;j<n;j++)
        {
            sum-=(ans[j]*a[i][j]);
        }
        sum=sum/a[i][i];
        ans[i]=sum;
    }
    return ans;
}

vector<double> poly(vector<double>& x,vector<double>& y,double d)
{
    vector<vector<double>>a(d+1,vector<double>(d+1,0));
    vector<double>b(d+1,0);
    int n=d+1;
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<n;col++)
        {
            for(int i=0;i<x.size();i++)
            {
                a[row][col]+=pro(x[i],row+col);
            }
        }

        for(int i=0;i<x.size();i++)
        {
            b[row]+=(pro(x[i],row)*y[i]);
        }
    }
    return gauss(a,b);
}

int main()
{    freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
    double n,d;
    cin>>d>>n;
    vector<double>x(n),y(n),ans;
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<n;i++) cin>>y[i];
    ans=poly(x,y,d);
    for(auto it:ans) cout<<it<<" ";
    cout<<endl;
    cout << "Resulting polynomial:"<<endl;
cout << "y = ";

for (int i = 0; i < ans.size(); i++)
{
    if (i > 0)
        cout << " + ";
   
    cout << ans[i];

    if (i == 1)
        cout << "*x";
    else if (i > 1)
        cout << "*x^" << i;
}

cout << endl;

}