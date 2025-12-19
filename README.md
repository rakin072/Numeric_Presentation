# Table of Contents

- [Solution of Linear Equations](#solution-of-linear-equations)
  - [Gauss Elimination Method](#gauss-elimination-method)
    - [Theory](#gauss-elimination-theory)
    - [Code](#gauss-elimination-code)
    - [Input](#gauss-elimination-input)
    - [Output](#gauss-elimination-output)
  - [Gauss Jordan Elimination Method](#gauss-jordan-elimination-method)
    - [Theory](#gauss-jordan-theory)
    - [Code](#gauss-jordan-code)
    - [Input](#gauss-jordan-input)
    - [Output](#gauss-jordan-output)
  - [LU Decomposition Method](#lu-decomposition-method)
    - [Theory](#lu-decomposition-theory)
    - [Code](#lu-decomposition-code)
    - [Input](#lu-decomposition-input)
    - [Output](#lu-decomposition-output)
  - [Matrix Inversion](#matrix-inversion)
    - [Theory](#matrix-inversion-theory)
    - [Code](#matrix-inversion-code)
    - [Input](#matrix-inversion-input)
    - [Output](#matrix-inversion-output)

- [Solution of Non-Linear Equations](#solution-of-non-linear-equations)
  - [Bisection Method](#bisection-method)
    - [Theory](#bisection-theory)
    - [Code](#bisection-code)
    - [Input](#bisection-input)
    - [Output](#bisection-output)
  - [False Position Method](#false-position-method)
    - [Theory](#false-position-theory)
    - [Code](#false-position-code)
    - [Input](#false-position-input)
    - [Output](#false-position-output)
  - [Newton Raphson Method](#newton-raphson-method)
    - [Theory](#newton-raphson-theory)
    - [Code](#newton-raphson-code)
    - [Input](#newton-raphson-input)
    - [Output](#newton-raphson-output)
  - [Secant Method](#Secant-method)
    - [Theory](#Secant-theory)
    - [Code](#Secant-code)
    - [Input](#Secant-input)
    - [Output](#Secant-output)
      
- [Solution of Ordinary Differential Equations](#solution-of-ordinary-differential-equations)
  - [Runge Kutta Method](#runge-kutta-method)
    - [Theory](#runge-kutta-theory)
    - [Code](#runge-kutta-code)
    - [Input](#runge-kutta-input)
    - [Output](#runge-kutta-output)
      
 - [Solution of Least Square Regression](#solution-of-least-square-regression)
    - [Linear Equation Method](#linear-equation)
      - [Theory](#linear-equation-theory)
      - [Code](#linear-equation-code)
      - [Input](#linear-equation-input)
      - [Output](#linear-equation-output)
    - [Transcendental Equation Method](#transcendental-equation)
      - [Theory](#transcendental-equation-theory)
      - [Code](#transcendental-equation-code)
      - [Input](#transcendental-equation-input)
      - [Output](#transcendental-equation-output)
    - [Polynomial Equation Method](#polunomial-equation)
      - [Theory](#polunomial-equation-theory)
      - [Code](#polunomial-equation-code)
      - [Input](#polunomial-equation-input)
      - [Output](#polunomial-equation-output)
---

### Solution of Linear Equations

### Gauss Elimination Method

#### Gauss Elimination Theory
[Add your theory content here]

#### Gauss Elimination Code
```python
#include <bits/stdc++.h>
using namespace std;
#define db double
int main()
{    freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
   // cout << "Number of test cases:" << endl;

    db t;
    cin >> t;
    while (t--)
    {

        int n;
      //  cout << "Enter number of equation : ";
        cin >> n;

        vector<vector<db>> v(n, vector<db>(n + 1));

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j <= n; j++)
            {
                cin >> v[i][j];
            }
        }

        bool jj = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (fabs(v[i][i]) < 1e-6)
            {
                for (int k = i + 1; k < n; k++)
                {

                    if (fabs(v[k][i]) > fabs(v[i][i]))
                    {

                        v[i][i] = v[k][i];
                        swap(v[i], v[k]);
                    }
                }
            }

            cout << "Pivot:" << v[i][i] << endl;
            for (int k = i + 1; k < n; k++)
            {
                db f = v[k][i] / v[i][i];
                for (int j = 0; j <= n; j++)
                {
                    v[k][j] -= v[i][j] * f;
                }
                for (int i = 0; i < n; i++)
                {

                    for (int j = 0; j <= n; j++)
                    {
                        cout << v[i][j] << " ";
                    }
                    cout << endl;
                }
            }
        }

        if (jj)
        {
            vector<db> ans(n);

            for (int i = n - 1; i >= 0; i--)
            {
                ans[i] = v[i][n];
                for (int j = i + 1; j < n; j++)
                {

                    ans[i] -= v[i][j] * ans[j];
                }

                ans[i] = ans[i] / v[i][i];
            }

            int kk = 1;
            for (int i = 0; i < n; i++)
            {
                int cnt = 0;
                for (int j = 0; j <= n; j++)
                {
                    if (v[i][j] == 0)
                    {

                        cnt++;
                    }
                }

                if (cnt == n + 1)
                {

                    cout << "infinte solution" << endl;
                    kk = 0;
                    break;
                }
                else if (cnt == n)
                {

                    cout << "No solution" << endl;
                    kk = 0;
                    break;
                }
            }
            if (kk)
            {
                cout << "Solution of the equation:";
                for (int i = 0; i < n; i++)
                {

                    cout << ans[i] << " ";
                }
                cout << endl;
            }
        }
    }
}


```

#### Gauss Elimination Input
```
3
3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3
2
1 1 2
2 2 4
2
1 1 2
2 2 5
```

#### Gauss Elimination Output
```
Pivot:2
2 1 -1 8 
0 0.5 0.5 1 
-2 1 2 -3 
2 1 -1 8 
0 0.5 0.5 1 
0 2 1 5 
Pivot:0.5
2 1 -1 8 
0 0.5 0.5 1 
0 0 -1 1 
Solution of the equation:2 3 -1 
Pivot:1
1 1 2 
0 0 0 
infinte solution
Pivot:1
1 1 2 
0 0 1 
No solution

```

---

### Gauss Jordan Elimination Method

#### Gauss Jordan Theory
[Add your theory content here]

#### Gauss Jordan Code
```python
#include<bits/stdc++.h>
using namespace std;
#define f float

void printm(ofstream &out, vector<vector<f>> p){
    int n = p.size(), m = p[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            out << fixed << setprecision(3) << p[i][j] << " ";
        }
        out << '\n';
    }
    out << '\n';
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    if(!in){
        out << "Error opening input file\n";
        return 0;
    }

    int n;
    in >> n;

    vector<vector<f>> a(n, vector<f>(n + 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n; j++){
            in >> a[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        if(!a[i][i]){
            for(int j = i + 1; j < n; j++){
                if(a[j][i]){
                    swap(a[i], a[j]);
                    break;
                }
            }
        }

        printm(out, a);

        for(int r = 0; r < n; r++){
            bool allZero = true;
            for(int c = 0; c <= n; c++){
                if(a[r][c] != 0){
                    allZero = false;
                    break;
                }
            }
            if(allZero){
                out << "The system has Inf. solution\n";
                return 0;
            }
        }

        for(int r = 0; r < n; r++){
            bool coeffZero = true;
            for(int c = 0; c < n; c++){
                if(a[r][c] != 0){
                    coeffZero = false;
                    break;
                }
            }
            if(coeffZero && a[r][n] != 0){
                out << "The system has No solution\n";
                return 0;
            }
        }

        f pivot = a[i][i];
        for(int j = 0; j <= n; j++){
            a[i][j] /= pivot;
        }

        printm(out, a);

        for(int j = i + 1; j < n; j++){
            f factor = a[j][i];
            for(int k = 0; k <= n; k++){
                a[j][k] -= factor * a[i][k];
            }
        }

        printm(out, a);

        for(int j = i - 1; j >= 0; j--){
            f factor = a[j][i];
            for(int k = 0; k <= n; k++){
                a[j][k] -= factor * a[i][k];
            }
        }
    }

    out << "Final Matrix:\n";
    printm(out, a);

    out << "Solution:\n";
    for(int i = 0; i < n; i++){
        out << fixed << setprecision(3) << a[i][n] << " ";
    }
    out << '\n';

    in.close();
    out.close();
    return 0;
}
```

#### Gauss Jordan Input
```
3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3

```

#### Gauss Jordan Output
```
1.000 0.500 -0.500 4.000
0.000 0.500 0.500 1.000
0.000 2.000 1.000 5.000

1.000 0.500 -0.500 4.000
0.000 1.000 1.000 2.000
0.000 0.000 -1.000 1.000

1.000 0.000 0.000 2.000
0.000 1.000 0.000 3.000
0.000 0.000 1.000 -1.000

Final Matrix:
1.000 0.000 0.000 2.000
0.000 1.000 0.000 3.000
0.000 0.000 1.000 -1.000

Solution:
2.000 3.000 -1.000

```

---

### LU Decomposition Method

#### LU Decomposition Theory
[Add your theory content here]

#### LU Decomposition Code
```python
#include <bits/stdc++.h>
using namespace std;

int main()
{
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        int t;
        cin>>t;
        while(t--)
        {
            int n;
            //cout << "Enter number of equations: ";
            cin >> n;
            vector<vector<double>> A(n, vector<double>(n));
            vector<double> b(n);
            //cout << "Enter the augmented matrix:" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cin >> A[i][j];
                }
                cin >> b[i];
            }
            vector<vector<double>> L(n, vector<double>(n, 0));
            vector<vector<double>> U(n, vector<double>(n, 0));
            bool decompositionFailed = false;
            for (int i = 0; i < n; i++)
            {
                for (int k = i; k < n; k++)
                {
                    double sum = 0;
                    for (int j = 0; j < i; j++)
                    {
                        sum += L[i][j] * U[j][k];
                    }
                    U[i][k] = A[i][k] - sum;
                }
                if (abs(U[i][i]) < 1e-10)
                {
                    decompositionFailed = true;
                    break;
                }
                for (int k = i; k < n; k++)
                {
                    if (i == k)
                    {
                        L[i][i] = 1;
                    }
                    else
                    {
                        double sum = 0;
                        for (int j = 0; j < i; j++)
                        {
                            sum += L[k][j] * U[j][i];
                        }
                        L[k][i] = (A[k][i] - sum) / U[i][i];
                    }
                }
            }
            cout << "\nLower triangular matrix L:" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << fixed << setprecision(3) << L[i][j] << " ";
                }
                cout << endl;
            }
            cout << "\nUpper triangular matrix U:" << endl;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << fixed << setprecision(3) << U[i][j] << " ";
                }
                cout << endl;
            }
            if (decompositionFailed)
            {
                vector<double> y(n);
                bool consistent = true;
                for (int i = 0; i < n; i++)
                {
                    double sum = 0;
                    for (int j = 0; j < i; j++)
                    {
                        sum += L[i][j] * y[j];
                    }
                    if (abs(L[i][i]) < 1e-10)
                    {
                        if (abs(b[i] - sum) > 1e-10)
                        {
                            consistent = false;
                            break;
                        }
                        y[i] = 0;
                    }
                    else
                    {
                        y[i] = (b[i] - sum) / L[i][i];
                    }
                }
                int rank = 0;
                for (int i = 0; i < n; i++)
                {
                    bool allZero = true;
                    for (int j = 0; j < n; j++)
                    {
                        if (abs(U[i][j]) > 1e-10)
                        {
                            allZero = false;
                            break;
                        }
                    }
                    if (!allZero)
                        rank++;
                }
                if (!consistent)
                {
                    cout << "\nThe system has no solution" << endl;
                }
                else if (rank < n)
                {
                    cout << "\nThe system has infinite solutions" << endl;
                }
                else
                {
                    cout << "\nThe system has no solution" << endl;
                }
            }
            else
            {
                vector<double> y(n);
                for (int i = 0; i < n; i++)
                {
                    double sum = 0;
                    for (int j = 0; j < i; j++)
                    {
                        sum += L[i][j] * y[j];
                    }
                    y[i] = (b[i] - sum) / L[i][i];
                }
                vector<double> x(n);
                for (int i = n - 1; i >= 0; i--)
                {
                    double sum = 0;
                    for (int j = i + 1; j < n; j++)
                    {
                        sum += U[i][j] * x[j];
                    }
                    x[i] = (y[i] - sum) / U[i][i];
                }
                cout << "\nSolution:" << endl;
                for (int i = 0; i < n; i++)
                {
                    cout << "x" << i + 1 << " = " << fixed << setprecision(3) << x[i] << endl;
                }

                cout << "\nThe system has unique solution" << endl;
            }
        }
    return 0;
}

```

#### LU Decomposition Input
```
3
3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3
3
1 1 1 6
2 2 2 12
3 3 3 18
3
1 1 1 6
1 1 1 7
2 2 2 12

```

#### LU Decomposition Output
```

Lower triangular matrix L:
1.000 0.000 0.000 
-1.500 1.000 0.000 
-1.000 4.000 1.000 

Upper triangular matrix U:
2.000 1.000 -1.000 
0.000 0.500 0.500 
0.000 0.000 -1.000 

Solution:
x1 = 2.000
x2 = 3.000
x3 = -1.000

The system has unique solution

Lower triangular matrix L:
1.000 0.000 0.000 
2.000 0.000 0.000 
3.000 0.000 0.000 

Upper triangular matrix U:
1.000 1.000 1.000 
0.000 0.000 0.000 
0.000 0.000 0.000 

The system has infinite solutions

Lower triangular matrix L:
1.000 0.000 0.000 
1.000 0.000 0.000 
2.000 0.000 0.000 

Upper triangular matrix U:
1.000 1.000 1.000 
0.000 0.000 0.000 
0.000 0.000 0.000 

The system has no solution

```

---

### Matrix Inversion

#### Matrix Inversion Theory
[Add your theory content here]

#### Matrix Inversion Code
```python
#include <bits/stdc++.h>
using namespace std;
#define ll double

void print(vector<vector<ll>> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << fixed << setprecision(3) << v[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void getcof(vector<vector<ll>> &mat, vector<vector<ll>> &cof, int p, int q, int n)
{
    int i = 0;
    for (int row = 0; row < n; row++)
    {
        if (row != p)
        {
            int j = 0;
            for (int col = 0; col < n; col++)
            {
                if (col != q)
                {
                    cof[i][j] = mat[row][col];
                    j++;
                }
            }
            i++;
        }
    }
}

ll det(vector<vector<ll>> &mat, int n)
{
    if (n == 1)
        return mat[0][0];

    ll dt = 0;
    vector<vector<ll>> cof(n, vector<ll>(n));
    int sign = 1;

    for (int i = 0; i < n; i++)
    {
        getcof(mat, cof, 0, i, n);
        dt += sign * mat[0][i] * det(cof, n - 1);
        sign = -sign;
    }
    return dt;
}

void getadj(vector<vector<ll>> &matrix, vector<vector<ll>> &adj, int n)
{
    if (n == 1)
    {
        adj[0][0] = 1;
        return;
    }

    vector<vector<ll>> cof(n, vector<ll>(n));
    int sign;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            getcof(matrix, cof, i, j, n);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = sign * det(cof, n - 1);
        }
    }
}

int rankMatrix(vector<vector<ll>> mat, int n, int m)
{
    int rank = 0;
    for (int col = 0, row = 0; col < m && row < n; col++)
    {
        int sel = row;
        for (int i = row; i < n; i++)
            if (fabs(mat[i][col]) > fabs(mat[sel][col]))
                sel = i;

        if (fabs(mat[sel][col]) < 1e-9)
            continue;

        swap(mat[sel], mat[row]);

        for (int i = 0; i < n; i++)
        {
            if (i != row)
            {
                double factor = mat[i][col] / mat[row][col];
                for (int j = col; j < m; j++)
                    mat[i][j] -= factor * mat[row][j];
            }
        }
        row++;
        rank++;
    }
    return rank;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<vector<ll>> A(n, vector<ll>(n));
        vector<ll> B(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> A[i][j];
            cin >> B[i];
        }

        cout << "Matrix A:\n";
        print(A, n);

        ll d = det(A, n);

        if (fabs(d) < 1e-9)
        {
            vector<vector<ll>> aug(n, vector<ll>(n + 1));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    aug[i][j] = A[i][j];
                aug[i][n] = B[i];
            }

            int rankA = rankMatrix(A, n, n);
            int rankAug = rankMatrix(aug, n, n + 1);

            if (rankA == rankAug)
                cout << "The system has infinite solutions\n";
            else
                cout << "The system has no solution\n";
            continue;
        }

        vector<vector<ll>> adj(n, vector<ll>(n));
        getadj(A, adj, n);

        cout << "Adjoint Matrix:\n";
        print(adj, n);

        vector<vector<ll>> inv(n, vector<ll>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                inv[i][j] = adj[i][j] / d;

        cout << "Inverse Matrix:\n";
        print(inv, n);

        vector<ll> X(n, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                X[i] += inv[i][j] * B[j];

        cout << "Unique solution:\n";
        for (int i = 0; i < n; i++)
            cout << "x" << i + 1 << " = " << fixed << setprecision(3) << X[i] << endl;
    }
    return 0;
}

```

#### Matrix Inversion Input
```
3
3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3
3
1 1 1 6
2 2 2 12
3 3 3 18
3
1 1 1 6
1 1 1 7
2 2 2 12

```

#### Matrix Inversion Output
```
Matrix A:
2.000 1.000 -1.000 
-3.000 -1.000 2.000 
-2.000 1.000 2.000 

Adjoint Matrix:
-4.000 -3.000 1.000 
2.000 2.000 -1.000 
-5.000 -4.000 1.000 

Inverse Matrix:
4.000 3.000 -1.000 
-2.000 -2.000 1.000 
5.000 4.000 -1.000 

Unique solution:
x1 = 2.000
x2 = 3.000
x3 = -1.000
Matrix A:
1.000 1.000 1.000 
2.000 2.000 2.000 
3.000 3.000 3.000 

The system has infinite solutions
Matrix A:
1.000 1.000 1.000 
1.000 1.000 1.000 
2.000 2.000 2.000 

The system has no solution

```

---

### Solution of Non-Linear Equations

### Bisection Method

#### Bisection Theory
[Add your theory content here]

#### Bisection Code
```python
# Add your code here
```

#### Bisection Input
```
[Add your input format here]
```

#### Bisection Output
```
[Add your output format here]
```

---

### False Position Method

#### False Position Theory
[Add your theory content here]

#### False Position Code
```
#include<bits/stdc++.h>
using namespace std;
#define f float

struct vaal{
    f root, start, end;
    int count;
};

f fun(vector<f> co, f x){
    f hld = 0.0;
    reverse(co.begin(), co.end());
    for(int i = co.size() - 1; i >= 0; i--){
        hld += pow(x, i) * co[i];
    }
    return hld;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    vector<f> cof(n + 1);
    for(auto &a : cof){
        in >> a;
    }

    f xmx = fabs(sqrt(pow((cof[1] / cof[0]), 2) - 2 * (cof[2] / cof[0])));

    vector<f> vv;
    for(f i = -xmx; i <= xmx; i += 0.5){
        f x1 = i, x2 = x1 + 0.5;
        f fx1 = fun(cof, x1), fx2 = fun(cof, x2);
        if(fx1 * fx2 < 0.0)
            vv.push_back(x1);
    }

    vector<vaal> res;

    for(int i = 0; i < vv.size(); i++){
        f x1 = vv[i], x2 = x1 + 0.5;
        f h1 = x1, h2 = x2;
        int cnt = 0;
        map<f, bool> mp;

        while(true){
            cnt++;
            f fx1 = fun(cof, x1), fx2 = fun(cof, x2);
            f x0 = x1 - fx1 * ((x2 - x1) / (fx2 - fx1));
            f fx0 = fun(cof, x0);

            if(abs(fx2 - fx1) < 0.0001 || mp[x0]){
                res.push_back({x0, h1, h2, cnt});
                break;
            }

            mp[x0] = true;

            if(fx1 * fx0 < 0.0)
                x2 = x0;
            else
                x1 = x0;
        }
    }

    for(int i = 0; i < res.size(); i++){
        out << "Root " << i + 1 << " : " << res[i].root << "\n";
        out << "Interval " << i + 1 << " : " 
            << res[i].start << " " << res[i].end << "\n";
        out << "Iteration " << i + 1 << " : " 
            << res[i].count << "\n\n";
    }

    in.close();
    out.close();
    return 0;
}

```

#### False Position Input
```
2
1 0 -4
```

#### False Position Output
```
Root 1 : -2
Interval 1 : -2.5 -2
Iteration 1 : 4

Root 2 : 2
Interval 2 : 1.5 2
Iteration 2 : 4

```

### Newton Raphson Method

#### Newton Raphson Theory
[Add your theory content here]

#### Newton Raphson Code
```python
# Add your code here
```

#### Newton Raphson Input
```
[Add your input format here]
```

#### Newton Raphson Output
```
[Add your output format here]
```

### Secant Method

#### Secant Theory
[Add your theory content here]

#### Secant Code
```python
    #include<bits/stdc++.h>
    using namespace std;
    const int maxi=1e5;
    double f(vector<double>&v,double x)
    {
        double res=0;
        int n=v.size();
        for(int i=0;i<v.size();i++){
            res+=v[i]*pow(x,n-1-i);
        }
        return res;
    }
    void secant(vector<double>&v,double a,double b,int r){
        double fa=f(v,a);
        double fb=f(v,b);
        double x=b-(((b-a)/(fb-fa))*fb);
        double p=a,q=b;
        int it=0;
        long long int cnt=0;
        bool found=true;
        while(fabs(x-b)>=0.001 && fabs(f(v,x))>=0.001){
            double fx=f(v,x);
            a=b,fa=fb;
            b=x,fb=fx;
            x=b-(((b-a)/(fb-fa))*fb);
            it++;
            cnt++;
            if((fabs(x-b)<=0.001 && fabs(f(v,x))<=0.001)||fabs(f(v,x)==0))
            {
                found=false;
                x=b-(((b-a)/(fb-fa))*fb);
                cout<<"Root "<<r<<": "<<x<<endl;
                cout<<"Search Interval : ["<<p<<", "<<q<<"]"<<endl;
                cout<<"No of iteration : "<<it<<endl;
                return;
            }
            if(cnt==maxi)break;
        }
        if(found)cout<<"No root found"<<endl;

    }
    int main()
    {
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        double deg;
        //cout<<"Enter the degree ";
        cin>>deg;
        //cout<<"Enter the Coefficient "<<endl;
        vector<double>v(deg+1);
        for(int i=0;i<deg+1;i++){
            cin>>v[i];
        }
        for(int i=0;i<deg+1;i++){
            if(v[i]!=0 && i<=deg){
                if(i==0)
                {
                    cout<<v[i]<<"x^"<<deg-i;
                }
                else if(i!=0)
                {
                    if(i==deg && v[i]>0)
                    {
                        cout<<"+"<<v[i];
                    }
                    else if(i==deg && v[i]<0)
                    {
                        cout<<"-"<<v[i];
                    }
                    else if(v[i]>0)
                    {
                        cout<<"+"<<v[i]<<"x^"<<deg-i;
                    }
                    else if(v[i]<0)
                    {
                        cout<<v[i]<<"x^"<<deg-i;
                    }
                    else{
                        continue;
                    }
                }

            }
        }
        cout<<"=0"<<endl;
        double xmax=0;
        for(int i=0;i<deg+1;i++){
            xmax=max(xmax,fabs(v[i]/v[0]));
        }
        xmax+=1;
        double xmin=-xmax;
        double a=xmin;
        double b;
        double s=0.45;
        int r=1;
        while(a<xmax){
            b=a+s;
            secant(v,a,b,r);
            r++;
            a=b;
        }
        return 0;
    }

```

#### Secant Input
```
4
1 0 -5 0 4
```

#### Secant Output
```
1x^4-5x^2+4=0
Root 1: -2
Search Interval : [-6, -5.55]
No of iteration : 10
Root 2: -2.00002
Search Interval : [-5.55, -5.1]
No of iteration : 9
Root 3: -2
Search Interval : [-5.1, -4.65]
No of iteration : 9
Root 4: -2.00001
Search Interval : [-4.65, -4.2]
No of iteration : 8
No root found
Root 6: -2
Search Interval : [-3.75, -3.3]
No of iteration : 7
Root 7: -2
Search Interval : [-3.3, -2.85]
No of iteration : 6
No root found
No root found
Root 10: -2
Search Interval : [-1.95, -1.5]
No of iteration : 5
Root 11: -1
Search Interval : [-1.5, -1.05]
No of iteration : 2
Root 12: -1.00003
Search Interval : [-1.05, -0.6]
No of iteration : 1
No root found
No root found
No root found
Root 16: 1
Search Interval : [0.75, 1.2]
No of iteration : 2
No root found
No root found
No root found
No root found
No root found
Root 22: 2.00002
Search Interval : [3.45, 3.9]
No of iteration : 7
Root 23: 2
Search Interval : [3.9, 4.35]
No of iteration : 8
No root found
Root 25: 2.00001
Search Interval : [4.8, 5.25]
No of iteration : 9
No root found
Root 27: 2
Search Interval : [5.7, 6.15]
No of iteration : 10

```
---
### Solution of Ordinary Differential Equations

### Runge Kutta Method

#### Runge Kutta Theory
[Add your theory content here]

#### Runge Kutta Code
```python
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

```

#### Runge Kutta Input
```
0
1
0.1 
0.3 
```

#### Runge Kutta Output
```
y(0.300000) = 1.488017
```
### Solution of Least Square Regression

### Linear Equation Method

#### Linear Equation Theory
[Add your theory content here]

#### Linear Equation Code
```python

```

#### Linear Equation Input
```
```

#### Linear Equation Output
```
```
### Transcendental Equation Method

#### Transcendental Equation Theory
[Add your theory content here]

#### Transcendental Equation Code
```python

```

#### Transcendental Equation Input
```
```

#### Transcendental Equation Output
```
```
### Polynomial Equation Method

#### Polynomial Equation Theory
[Add your theory content here]

#### Polynomial Equation Code
```python

```

#### Polynomial Equation Input
```
```

#### Polynomial Equation Output
```
```
---

