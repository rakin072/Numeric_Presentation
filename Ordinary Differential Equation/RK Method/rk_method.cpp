#include <bits/stdc++.h>
using namespace std;

double f(double x, double y) {
    return x + y*y;
}

int main() {
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
    double x0,y0;
    //cout<<"init x:";
    cin>>x0;
   // cout<<"init y:";
   cin>>y0;
   // cout<<"step size :";
    double h;
    cin>>h;    
    //cout<<"target value of x:" ;    
    double xn ; cin>>xn;        

    double x = x0, y = y0;

    while (x < xn) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h/2, y + k1/2);
        double k3 = h * f(x + h/2, y + k2/2);
        double k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        x += h;
    }

    cout << fixed << setprecision(6);
    cout << "y("<<xn<<") = " << y << endl;

    return 0;
}
