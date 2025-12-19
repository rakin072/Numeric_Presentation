#include <bits/stdc++.h>
using namespace std;

#define ll double

ll newtonforward(vector<ll> &x, vector<ll> &y, ll tar, ofstream &out)
{
    ll n = x.size() - 1;
    ll h = x[1] - x[0];
    ll u = (tar - x[0]) / h;

    vector<vector<ll>> table(n + 1, vector<ll>(n + 1));

    for (int i = 0; i <= n; i++)
        table[i][0] = y[i];

    for (int j = 1; j <= n; j++)
        for (int i = 0; i <= n - j; i++)
            table[i][j] = table[i + 1][j - 1] - table[i][j - 1];

    out << "Forward Difference Table:\n";
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
            out << setw(10) << table[i][j] << " ";
        out << "\n";
    }
    out << "\n";

    ll ans = table[0][0];
    ll u_term = 1, fact = 1;

    for (int i = 1; i <= n; i++)
    {
        u_term *= (u - (i - 1));
        fact *= i;
        ans += (u_term * table[0][i]) / fact;
    }

    return ans;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    vector<ll> x(n), y(n);

    for (int i = 0; i < n; i++)
        in >> x[i];

    for (int i = 0; i < n; i++)
        in >> y[i];

    ll target;
    in >> target;

    ll ans1 = newtonforward(x, y, target, out);
    ll students1 = ans1 - y[0];

    out << "Cumulative frequency at " << target << " = " << ans1 << "\n";
    out << "Students between " << x[0] << " and " << target << " = " << students1 << "\n\n";

    ll nx, ny;
    in >> nx >> ny;

    x.push_back(nx);
    y.push_back(ny);

    out << "After adding new data:\n";

    ll ans2 = newtonforward(x, y, target, out);
    ll students2 = ans2 - y[0];

    out << "Cumulative frequency at " << target << " = " << ans2 << "\n";
    out << "Students between " << x[0] << " and " << target << " = " << students2 << "\n";

    out << "Error = " << abs(students2 - students1) << "\n";

    in.close();
    out.close();

    return 0;
}

