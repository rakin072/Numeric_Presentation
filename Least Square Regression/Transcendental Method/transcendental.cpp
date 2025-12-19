#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<double> z(n), y(n);

    for(int i = 0; i < n; i++) {
        cin >> z[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> y[i];
    }

    vector<double> x(n);

    for(int i = 0; i < n; i++) {
        x[i] = exp(z[i] / 4.0);
    }

    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0;

    for(int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
    }

    double q = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double p = (sum_y - q * sum_x) / n;

    double z6;
    cin >> z6;
    double x6 = exp(z6 / 4.0);
    double y6 = p + q * x6;

    cout << fixed << setprecision(4);
    cout << "p = " << p << endl;
    cout << "q = " << q << endl;
    cout << "Equation: y = " << p << " + (" << q << ")*e^(z/4)" << endl;
    cout << "Estimated y at z: " << y6 << endl;

    return 0;
}
