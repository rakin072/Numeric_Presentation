#include <bits/stdc++.h>
using namespace std;
#define ll double

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    ll n;
    fin >> n;

    vector<ll> x(n);
    vector<ll> y(n);
    for (int i = 0; i < n; i++)
        fin >> x[i];
    for (int i = 0; i < n; i++)
        fin >> y[i];

    ll sx = 0;
    ll sy = 0;
    ll sx2 = 0;
    ll sxy = 0;
    for (int i = 0; i < n; i++)
    {
        sx += x[i];
        sy += y[i];
        sx2 += x[i] * x[i];
        sxy += x[i] * y[i];
    }

    ll yb = sy / n;
    ll xb = sx / n;
    ll b = ((n * sxy) - (sx * sy)) / (n * sx2 - sx * sx);
    ll a = (sy / n) - b * (sx / n);

    fout << "y=" << a << "+" << b << "x\n";

    ll x_val;
    fin >> x_val;

    ll y_val = a + b * x_val;
    fout << "For x=" << x_val << ", y=" << y_val << "\n";

    fin.close();
    fout.close();
    return 0;
}
