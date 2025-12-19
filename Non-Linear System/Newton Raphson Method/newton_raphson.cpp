#include <bits/stdc++.h>

using namespace std;

double E = .000001;
double f(vector<double> &co, double n, double val)
{
    double res = 0;

    for (int i = n; i >= 0; i--)
        res += co[i] * pow(val, i);

    return res;
}
double df(vector<double> &co, double n, double val)
{
    double res = 0;

    for (int i = n; i >= 1; i--)
        res += i * co[i] * pow(val, i - 1);

    return res;
}

void pdf(vector<double> &co, double n)
{
    for (int i = n; i >= 0; i--)

    {
        if (i != 0 and co[i] != 0)

            cout << i * co[i] << "x^" << i - 1;

        if (i != 0 and co[i - 1] > 0)
            cout << "+";

        if (i == 0)
            cout << i * co[i];
    }
    cout << endl;
}

double cnt = 1;
double raph(vector<double> &co, double n, double x)
{
    double xr = x;

    while (1)
    {
        double f1 = f(co, n, xr);

        double df1 = df(co, n, xr);

        cout << "f(x): " << f1 << endl;

        cout << "df(x):" << df1 << endl;

        double x_new = xr - (f1 / df1 * (1.00));

        if (fabs(x_new - xr) < E or fabs(f(co, n, x_new) - f1) < E)
            return x_new;
        xr = x_new;

        cnt++;
    }

    return xr;
}
int main()
{    freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
    double t;
    cout << "Enter number of test cases:" << endl;
    cin >> t;
    while (t--)
    {
        cout << "Enter the degree of the equation:" << endl;
        double deg;
        cin >> deg;
        double n = deg;

        vector<double> co(n + 1);
        cout << "Enter coeffients:" << endl;
        for (int i = deg; i >= 0; i--)
            cin >> co[i];

        cout << "function:";

        for (int i = deg; i >= 0; i--)
        {

            if (co[i] != 0)
            {

                cout << co[i];

                if (i > 0)

                    cout << "x^" << i;
            }
            if (i - 1 >= 0 and co[i - 1] > 0)
                cout << "+";
        }
        cout << endl
             << endl;

        cout << "derivative:";

        pdf(co, n);
        cout << endl;

        double xmax = sqrt((co[n - 1] / co[n]) * (co[n - 1] / co[n]) - 2 * (co[n - 2] / co[n]));

        double s = -xmax;
        cout << "[-tmax,tmax]:[" << s << "," << xmax << "]" << endl;
        double count = 0;

        for (double i = s; i <= xmax; i += 0.65)
        {
            double f1 = f(co, n, i);

            double f2 = f(co, n, i + 0.65);
            if (f1 == 0)
                cout << "Root found directly at x = " << i << endl;
            else if (f1 * f2 < 0)

            {

                cout << "f1:" << f1 << " " << "f2:" << f2 << endl;

                cnt = 1;

                double root = raph(co, n, i + 0.65);

                count++;
                cout << "search interval for root is :[ " << i << " to " << i + 0.65 << " ]" << endl;

                cout << "Root" << count << " : " << root << endl;

                cout << "Number of the iterations: " << cnt << endl;

                cout << endl;
            }
        }
    }
}