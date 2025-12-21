# Project Introduction

This project implements **19 classical Numerical Methods in C++** with support for **multiple test cases**, **file-based input**, and **file/terminal output**.
All methods are **modular and well-categorized**, making the project suitable for academic learning and practical implementation.

## Classification of Implemented Numerical Methods

### 1. Solution of Non-Linear Equations (4 Methods)
- Bisection Method  
- False Position (Regula Falsi) Method  
- Newton–Raphson Method  
- Secant Method  

### 2. Solution of Linear Equations (4 Methods)
- Gauss Elimination Method  
- Gauss–Jordan Elimination Method  
- LU Decomposition (Doolittle’s Method)  
- Matrix Inversion Method  

### 3. Differential Equation Solving (1 Method)
- Runge–Kutta 4th Order Method  

### 4. Interpolation Methods (3 Methods)
- Newton Forward Interpolation  
- Newton Backward Interpolation  
- Newton Divided Difference Interpolation  

### 5. Curve Fitting and Regression (3 Methods)
- Linear Regression  
- Polynomial Regression  
- Transcendental Regression  

### 6. Numerical Integration (2 Methods)
- Simpson’s 1/3 Rule  
- Simpson’s 3/8 Rule
  
### 7. Numerical Differentiation (2 Methods)
- Differentiation by Forward Interpolation  
- Differentiation by Backward Interpolation  
  
### Table of Contents <a id="toc"></a>
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


- [Solution of Ordinary Differential Equations](#solution-of-ordinary-differential-equations)
  - [Runge Kutta Method](#runge-kutta-method)
    - [Theory](#runge-kutta-theory)
    - [Code](#runge-kutta-code)
    - [Input](#runge-kutta-input)
    - [Output](#runge-kutta-output)
      
- [Solution of Least Square Regression](#solution-of-least-square-regression)
    - [Linear Equation Method](#linear-equation-method)
      - [Theory](#linear-equation-theory)
      - [Code](#linear-equation-code)
      - [Input](#linear-equation-input)
      - [Output](#linear-equation-output)
    - [Transcendental Equation Method](#transcendental-equation-method)
      - [Theory](#transcendental-equation-theory)
      - [Code](#transcendental-equation-code)
      - [Input](#transcendental-equation-input)
      - [Output](#transcendental-equation-output)
    - [Polynomial Equation Method](#polynomial-equation-method)
      - [Theory](#polynomial-equation-theory)
      - [Code](#polynomial-equation-code)
      - [Input](#polynomial-equation-input)
      - [Output](#polynomial-equation-output)
      
 - [Solution of Interpolation Method](#solution-of-interpolation-method)
    - [Newton Forward Interpolation](#newton-forward-interpolation)
      - [Theory](#newton-forward-interpolation-theory)
      - [Code](#newton-forward-interpolation-code)
      - [Input](#newton-forward-interpolation-input)
      - [Output](#newton-forward-interpolation-output)
    - [Newton Backward Interpolation](#newton-backward-interpolation)
      - [Theory](#newton-backward-interpolation-theory)
      - [Code](#newton-backward-interpolation-code)
      - [Input](#newton-backward-interpolation-input)
      - [Output](#newton-backward-interpolation-output)
    - [Newton Divided Difference Interpolation](#newton-divided-difference-interpolation)
      - [Theory](#newton-divided-difference-theory)
      - [Code](#newton-divided-difference-code)
      - [Input](#newton-divided-difference-input)
      - [Output](#newton-divided-difference-output)
        
  - [Numerical Integration](#numerical-integration)
    - [Simpson’s 1/3 Rule](#simpsons-13-rule)
      - [Theory](#simpsons-13-theory)
      - [Code](#simpsons-13-code)
      - [Input](#simpsons-13-input)
      - [Output](#simpsons-13-output)
    - [Simpson’s 3/8 Rule](#simpsons-38-rule)
      - [Theory](#simpsons-38-theory)
      - [Code](#simpsons-38-code)
      - [Input](#simpsons-38-input)
      - [Output](#simpsons-38-output)
      - 
  - [Numerical Differentiation](#numerical-differentiation)
      - [Differentiation By Forward Interpolation](#differentiation-by-forward-interpolation)
          - [Theory](#differentiation-by-forward-interpolation-theory)
          - [Code](#differentiation-by-forward-interpolation-code)
          - [Input](#differentiation-by-forward-interpolation-input)
          - [Output](#differentiation-by-forward-interpolation-output)
      - [Differentiation By Backward Interpolation](#differentiation-by-backward-interpolation)
          - [Theory](#differentiation-by-backward-interpolation-theory)
          - [Code](#differentiation-by-backward-interpolation-code)
          - [Input](#differentiation-by-backward-interpolation-input)
          - [Output](#differentiation-by-backward-interpolation-output)     
---
### Solution of Non-Linear Equations

### Bisection Method
#### Bisection Theory
## Introduction
The Bisection Method is a numerical technique used to find a real root of a non-linear equation: f(x)=0.
It is one of the simplest and most reliable bracketing methods in numerical analysis.

---
##  Mathematical Foundation
The method is based on the *Intermediate Value Theorem*.
### Intermediate Value Theorem
If a function *f(x)* is:
- continuous on the interval [a, b]
- and f(a) · f(b) < 0
Then at least *one real root exists* in the open interval (a, b).
---
## Basic Idea
1. Select two initial guesses a and b
2. Ensure that: f(a) · f(b) < 0
3. Compute the midpoint: c = (a + b) / 2
4. Check the sign of f(c)
5. Replace either a or b such that the sign change is maintained
6. Repeat until the desired accuracy is achieved
---
##  Algorithm
1. Input the function f(x)
2. Input initial interval [a, b]
3. If f(a) · f(b) ≥ 0  
  → Method fails
4. Compute midpoint: c = (a + b) / 2
5. If f(c) = 0  
  → Root found
6. If f(a) · f(c) < 0  
  → Set b = c
7. Else  
  → Set a = c
8. Repeat steps 4–7 until stopping condition is satisfied
---
##  Stopping Criteria
The iteration stops when *any one* of the following conditions is met:
  - |f(c)| < ε  
  - |b − a| < ε  
  - Maximum number of iterations reached  
Where ε is the allowable error (tolerance).
---
# Convergence
  - Type: *Linear Convergence*
  - Rate: Slow but steady
  - Convergence is *guaranteed* if the initial condition is satisfied
---
##  Advantages
  -  Very simple to understand and implement
  -  Guaranteed convergence
  -  No derivative required
  -  Stable numerical behavior
---
## Disadvantages
  -  Slow convergence
  -  Requires an initial interval with sign change
  -  Not suitable for multiple roots in one interval
---

#### Bisection Code
```python
#include <bits/stdc++.h>
using namespace std;
#define ll double
ll a, b, c, d, e;
ll f(ll x)
{

  return a * x * x * x * x + b * x * x * x + c * x * x + d * x + e;
}

ll tmax()
{
  vector<ll> v;
  v.push_back(abs(b / a));
  v.push_back(abs(c / a));
  v.push_back(abs(d / a));
  v.push_back(abs(e / a));
  return 1 + *max_element(v.begin(), v.end());
}

void bisection(ll l, ll r)
{

  ll mid = (l + r) / 2;
  ll cnt = 1;
  while (fabs(mid - l) >= .0001)
  {
    cnt++;

    if (f(mid) * f(l) < 0)
      r = mid;
    else if (f(mid) * f(r) < 0)
      l = mid;
    else if (f(mid) == 0)
    {

      break;
    }
    mid = (l + r) / 2;
  }

  cout << "root:" << mid << endl;
  cout << "iteration:" << cnt << endl;

  return;
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ll T;
  cout << "Enter number of test cases: ";
  cout << endl;
  cin >> T;

  while (T--)
  {
    cout << "Enter coefficients a b c d e: " << endl;
    cin >> a >> b >> c >> d >> e;

    ll r = tmax();

    ll l = -r;

    cout << "Search interval:[" << l << " " << r << "]" << endl;
    while (l <= r)
    {
      ll d = l + 0.5;

      if (f(l) * f(d) < 0)
      {

        cout << "interval:[" << l << " " << d << "]" << endl;

        bisection(l, d);
      }
      l = d;
    }
  }
}

```

#### Bisection Input
```
1
1 -8 -7 58 40
```

#### Bisection Output
```
Enter number of test cases: 
Enter coefficients a b c d e: 
Search interval:[-59 59]
interval:[-2.5 -2]
root:-2.35675
iteration:13
interval:[-1 -0.5]
root:-0.680969
iteration:13
interval:[3 3.5]
root:3.16656
iteration:13
interval:[7.5 8]
root:7.87115
iteration:13

```
⬆ [Back to Table of Contents](#toc)

---

### False Position Method

#### False Position Theory
The **False Position Method**, also known as the **Regula Falsi Method**, is a numerical technique used to find a **real root** of a nonlinear equation of the form: f(x) = 0
This method is a **bracketing method** and combines the **reliability of the Bisection Method** with the **faster convergence of linear interpolation**.

---
## Initial Interval
Let the initial interval be: [a, b]
such that: f(a) · f(b) < 0
This condition ensures that at least one real root lies within the interval.

---
## Iterative Formula
The next approximation of the root is obtained using **linear interpolation**:
$$x_n = \frac{a \cdot f(b) - b \cdot f(a)}{f(b) - f(a)}$$
This point is the x-intercept of the straight line joining  
(a, f(a)) and (b, f(b)).

---
## Iteration Process
1. Compute the approximation `xₙ`
2. Evaluate `f(xₙ)`
3. Update the interval as follows:
   - If `f(a) · f(xₙ) < 0`, set `b = xₙ`
   - If `f(xₙ) · f(b) < 0`, set `a = xₙ`
4. Repeat until the stopping criteria are satisfied
---
## Stopping Criteria
The iteration stops when **any one** of the following conditions is met: |f(xₙ)| < ε
or |xₙ − xₙ₋₁| < ε
or when the maximum number of iterations is reached.
Here, ε denotes the allowable error (tolerance).
##  Algorithm Steps
1. Choose initial interval `[a, b]`
2. Check if `f(a) · f(b) < 0`
   - If not, the method fails
3. Compute: $$x_n = \frac{a \cdot f(b) - b \cdot f(a)}{f(b) - f(a)}$$
4. Evaluate `f(xₙ)`
5. Update the interval `[a, b]`
6. Check convergence criteria
7. Repeat steps 3–6 until convergence
---
##  Convergence Characteristics
- The False Position Method converges **faster than the Bisection Method**
- Convergence is generally **linear**
- Convergence is **guaranteed** if the initial interval satisfies the sign-change condition
However, convergence may become slow if one end of the interval remains fixed for many iterations.
---
## Advantages
-  Guaranteed convergence
-  Faster than Bisection Method
-  Simple and easy to implement
-  Does not require derivatives
---
## Disadvantages
  - Slower than Newton–Raphson Method
  - One endpoint may remain unchanged for many iterations
  - Linear convergence

---
#### False Position Code
```python
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
⬆ [Back to Table of Contents](#toc)

### Newton Raphson Method

#### Newton Raphson Theory
# Newton–Raphson Method (Numerical Analysis)

## Newton–Raphson Theory
The *Newton–Raphson Method* is a numerical technique used to determine the root of a *non-linear equation* of the form:

f(x) = 0

Unlike the *Secant* or *False Position* methods, the Newton–Raphson Method *requires the derivative* of the function to compute successive approximations.  
It uses a *single initial guess* that should be reasonably close to the actual root.

---

## Initial Guess
Let the initial guess be: x₀

---

##  Iterative Formula
The next approximation of the root is computed using the formula:
xₙ₊₁ = xₙ − f(xₙ) / f′(xₙ)
Here, xₙ₊₁ is obtained by finding the *x-intercept of the tangent line* to the curve  
y = f(x) at the point (xₙ, f(xₙ)).

---

##  Iteration Process
The process is repeated iteratively by updating the approximation: xₙ ← xₙ₊₁  until the difference between successive approximations becomes smaller than a prescribed tolerance: |xₙ₊₁ − xₙ| < ε or the absolute value of the function satisfies: |f(xₙ₊₁)| < ε
where ε is the allowable error.

---

##  Algorithm Steps
1. Start with an initial guess x₀
2. Compute f(xₙ) and f′(xₙ)
3. Calculate the next approximation: xₙ₊₁ = xₙ − f(xₙ) / f′(xₙ)
4. Check convergence criteria:
- If |xₙ₊₁ − xₙ| < ε *or*
- If |f(xₙ₊₁)| < ε
5. If satisfied, *stop*
6. Otherwise, set xₙ = xₙ₊₁ and repeat from step 2

---

## Convergence Characteristics
The Newton–Raphson Method typically converges *faster* than the Bisection or Secant methods, especially when the *initial guess is sufficiently close* to the root.

However, it may fail to converge if:
- The derivative becomes zero or very small
  f′(xₙ) ≈ 0
  - The initial guess is far from the actual root
- The function has multiple roots or local extrema near the initial guess

---

##  Advantages
-  Fast convergence  
-  Quadratic convergence rate under favorable conditions  
-  Requires fewer iterations compared to other methods  

---

##  Disadvantages
-  Requires computation of derivative f′(x)
-  Highly sensitive to initial guess
-  May diverge if f′(x) = 0 or very small
  ---
#### Newton Raphson Code
```python
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
```

#### Newton Raphson Input
```
1
5
1 -8 -7 58 40
```

#### Newton Raphson Output
```
Enter number of test cases:
Enter the degree of the equation:
Enter coeffients:
function:1x^5-8x^4-7x^3+58x^2+40x^1

derivative:5x^4-32x^3-21x^2+116x^1+40x^00

[-tmax,tmax]:[-8.83176,8.83176]
f1:-286.112 f2:5.39905
f(x): 5.39905
df(x):208.844
f(x): -0.189779
df(x):223.609
f(x): -0.000209056
df(x):223.116
search interval for root is :[ -2.98176 to -2.33176 ]
Root1 : -2.35676
Number of the iterations: 3

f1:17.9257 f2:-6.606
f(x): -6.606
df(x):-5.4582
f(x): 49.9505
df(x):-36.6554
f(x): -6.06135
df(x):12.6915
f(x): 13.3679
df(x):67.0322
f(x): 2.09041
df(x):45.61
f(x): 0.120231
df(x):40.347
f(x): 0.000514664
df(x):40.0015
f(x): 9.60112e-09
df(x):40
search interval for root is :[ -1.03176 to -0.381761 ]
Root2 : 8.35395e-20
Number of the iterations: 8

f1:-6.606 f2:14.7277
f(x): 14.7277
df(x):69.013
f(x): 2.36657
df(x):46.2925
f(x): 0.149312
df(x):40.4304
f(x): 0.000790328
df(x):40.0023
f(x): 2.26397e-08
df(x):40
search interval for root is :[ -0.381761 to 0.268239 ]
Root3 : 4.64504e-19
Number of the iterations: 5

f1:79.3904 f2:-132.861
f(x): -132.861
df(x):-439.308
f(x): -16.0026
df(x):-333.604
f(x): -0.398145
df(x):-317.02
f(x): -0.000271773
df(x):-316.588
search interval for root is :[ 2.86824 to 3.51824 ]
Root4 : 3.16658
Number of the iterations: 4

f1:-1130.87 f2:710.995
f(x): 710.995
df(x):3989.8
f(x): 61.8724
df(x):3307.29
f(x): 0.633179
df(x):3239.72
f(x): 6.85862e-05
df(x):3239.02
search interval for root is :[ 7.41824 to 8.06824 ]
Root5 : 7.87113
Number of the iterations: 4

```
⬆ [Back to Table of Contents](#toc)
### Secant Method

#### Secant Theory
#  Secant Method (Numerical Analysis)

##  Secant Method Theory
The *Secant Method* is an *open numerical method* used to find the root of a nonlinear equation: f(x) = 0
Unlike the *Newton–Raphson Method, the Secant Method **does not require the derivative* of the function.  
Instead, it uses *two initial approximations* to construct a secant line and iteratively find the root.

---
##  Initial Approximations
Let the two initial guesses be: x₀ and x₁
These should be *reasonably close* to the actual root to ensure convergence.

---
##  Iterative Formula
The next approximation of the root is computed using the *secant line formula*:
   $$x_{n+1} = x_n - f(x_n) \cdot \frac{x_n - x_{n-1}}{f(x_n) - f(x_{n-1})}$$
Here:
- xₙ₊₁ = next approximation
- xₙ, xₙ₋₁ = current and previous approximations
- f(xₙ), f(xₙ₋₁) = function values at these points

---
##  Iteration Process
1. Compute xₙ₊₁ using the formula above
2. Update:
    xₙ₋₁ ← xₙ
    xₙ ← xₙ₊₁
3. Repeat until stopping criteria are satisfied

---
##  Stopping Criteria
The iteration stops when *any one* of the following conditions is met: |xₙ₊₁ − xₙ| < ε or |f(xₙ₊₁)| < ε
or the maximum number of iterations is reached.  
Here, ε denotes the allowable error (tolerance).

---
##  Algorithm Steps
1. Choose initial guesses x₀ and x₁
2. Compute the next approximation: $$x_2 = x_1 - f(x_1) \cdot \frac{x_1 - x_0}{f(x_1) - f(x_0)}$$
3.Update previous values:
  x₀ ← x₁
  x₁ ← x₂
4. Check convergence:
  - If |xₙ₊₁ − xₙ| < ε *or*
  - If |f(xₙ₊₁)| < ε
5. If satisfied, *stop*
6. Otherwise, repeat steps 2–4
---
##  Convergence Characteristics
  - Convergence is generally *faster than Bisection*, but slower than Newton–Raphson
  - May fail if initial guesses are poorly chosen or function is not well-behaved

---
##  Advantages
-  Does not require derivative of f(x)
-  Faster than Bisection Method
-  Simple and easy to implement
---
##  Disadvantages
-  Requires two initial guesses
-  Convergence is not guaranteed
-  Slower than Newton–Raphson if derivative is available

---
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
⬆ [Back to Table of Contents](#toc)

---
### Solution of Linear Equations

### Gauss Elimination Method

#### Gauss Elimination Theory
# Gauss Elimination Method
## Introduction
The *Gauss Elimination Method* is a systematic procedure for solving a system of linear equations of the form: Ax = b
where:
- A is the coefficient matrix
- x is the column vector of unknowns
- b is the constant vector
It transforms the system into an *upper triangular form* and then solves it using *back-substitution*.

---
## Steps of Gauss Elimination Method
### Step 1: Forward Elimination
1. Transform the augmented matrix [A|b] into an *upper triangular matrix*.
2. For each pivot row:
   - Make the elements below the pivot zero using row operations: $$R_j \leftarrow R_j - \left( \frac{a_{jk}}{a_{kk}} \right) R_k$$
   - Where Rk is the pivot row and Rj is the row being eliminated.
---
### Step 2: Back Substitution
1. After obtaining the upper triangular matrix, solve for the unknowns starting from the last row.
2. Formula for back substitution:
    $$x_n = \frac{b_n}{a_{nn}}$$

$$x_i = \frac{1}{a_{ii}} \left( b_i - \sum_{j=i+1}^{n} a_{ij} x_j \right), \quad i = n-1, n-2, \dots, 1$$
where the sum is over j = i+1 to n.
---
## Algorithm Steps
1. Form the augmented matrix [A|b].
2. Apply forward elimination to convert [A|b] to upper triangular form.
3. Apply back substitution to find the solution vector x.
4. Check for singularity: If any pivot element a_kk = 0, the method fails.
---
## Conditions for Applicability
- The coefficient matrix A must be *non-singular* (determinant ≠ 0).
- Partial or complete pivoting may be required if pivot elements are zero or very small to avoid division errors.
---
## Advantages
- Simple and systematic procedure
- Can be applied to any system of linear equations
---
## Disadvantages
- Sensitive to round-off errors
- Pivoting is required to improve stability
---

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
⬆ [Back to Table of Contents](#toc)

---

### Gauss Jordan Elimination Method

#### Gauss Jordan Theory
# Gauss-Jordan Elimination Method
## Introduction
The *Gauss-Jordan Elimination Method* is an extension of the Gauss Elimination Method.  
It is used to solve a system of linear equations of the form: Ax = b
The method transforms the augmented matrix [A|b] into a *reduced row echelon form (RREF)*, making the solution directly readable without the need for back-substitution.

---
## Steps of Gauss-Jordan Elimination
### Step 1: Form the Augmented Matrix
Write the system of linear equations in the augmented matrix form [A|b].

---
### Step 2: Forward Elimination
1. Select a pivot element in the current row.
2. Make the pivot element 1 by dividing the entire row by the pivot value.
3. Make all elements *below the pivot zero* using row operations: $$R_j \leftarrow R_j - a_{jk} R_k$$
where Rk is the pivot row and Rj is the row being eliminated.
---
### Step 3: Backward Elimination
1. After forward elimination, make all elements *above the pivot zero*.
2. Apply row operations: $$R_i \leftarrow R_i - a_{ij} R_j$$
   where Rj is the pivot row and Ri is a row above it.
3. Repeat for all pivot positions until the matrix is in *reduced row echelon form*.
---
### Step 4: Read the Solution
Once the augmented matrix is in RREF, the solution vector x can be directly read from the last column:
$$x_i = b_i, \quad i = 1, 2, \dots, n$$

---

## Algorithm Steps
1. Form augmented matrix [A|b].
2. For each pivot row:
   - Make pivot element 1.
   - Make all other elements in the pivot column 0 using row operations.
3. Repeat until the entire matrix is in reduced row echelon form.
4. Read the solution directly from the augmented column.
5. Check for singularity or inconsistency:  
   - If a row becomes [0 0 ... 0 | c] with c ≠ 0, the system has no solution.  
   - If a row becomes [0 0 ... 0 | 0], the system has infinitely many solutions.
---
## Conditions for Applicability
- The coefficient matrix A must not be singular for a unique solution.
- Pivoting may be required if pivot elements are zero or very small to avoid division errors.
---
## Advantages
- Provides *direct solution* without back-substitution.
- Can determine if the system has no solution or infinitely many solutions.
- Systematic and easy to implement for small to medium-sized systems.
---
## Disadvantages
- Computationally intensive for very large systems.
- Sensitive to round-off errors.
- Requires careful pivot selection to maintain numerical stability.
---

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
⬆ [Back to Table of Contents](#toc)

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
⬆ [Back to Table of Contents](#toc)

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
⬆ [Back to Table of Contents](#toc)



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
⬆ [Back to Table of Contents](#toc)

### Solution of Least Square Regression

### Linear Equation Method

#### Linear Equation Theory
[Add your theory content here]

#### Linear Equation Code
```python
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

```

#### Linear Equation Input
```
5
1 2 3 4 5
2 4 5 4 5
6

```

#### Linear Equation Output
```
y=1.2+0.6x
For x=6, y=4.8
```
⬆ [Back to Table of Contents](#toc)

### Transcendental Equation Method

#### Transcendental Equation Theory
[Add your theory content here]

#### Transcendental Equation Code
```python
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

```

#### Transcendental Equation Input
```
5
1 2 3 4 5
50 80 96 120 45
6
```

#### Transcendental Equation Output
```
p = 76.5970
q = 0.7119
Equation: y = 76.5970 + (0.7119)*e^(z/4)
Estimated y at z: 79.7875

```
⬆ [Back to Table of Contents](#toc)

### Polynomial Equation Method

#### Polynomial Equation Theory
[Add your theory content here]

#### Polynomial Equation Code
```python
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
```

#### Polynomial Equation Input
```
2 5
1 2 3 4 5 
6 11 18 27 38
```

#### Polynomial Equation Output
```
3 2 1 
Resulting polynomial:
y = 3 + 2*x + 1*x^2
```
⬆ [Back to Table of Contents](#toc)

### Solution of Interpolation Method
### Newton Forward Interpolation

#### Newton Forward Interpolation Theory
[Add your theory content here]

#### Newton Forward Interpolation Code
```python
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
```

#### Newton Forward Interpolation Input
```
5
40 50 60 70 80
31 73 124 159 190
45
90 220

```

#### Newton Forward Interpolation Output
```
Forward Difference Table:
        31         42          9        -16          8
        73         51         -7          8
       124         35          1
       159         31
       190

Cumulative frequency at 45 = 52.0625
Students between 40 and 45 = 21.0625

After adding new data:
Forward Difference Table:
        31         42          9        -16          8         -3
        73         51         -7          8         -3
       124         35          1          5
       159         31          6
       190         30
       220

Cumulative frequency at 45 = 53.3125
Students between 40 and 45 = 22.3125
Error = 1.25
```
⬆ [Back to Table of Contents](#toc)

### Newton Backward Interpolation

#### Newton Backward Interpolation Theory
[Add your theory content here]

#### Newton Backward Interpolation Code
```python
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

    cout<<"\nStudents between 70 and 75 = "<<fixed<<setprecision(3)<<ans1<<"\n";

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

    cout<<"\nNew Students between 70 and 75 = "<<fixed<<setprecision(3)<<ans2<<"\n";
    cout<<"\nNumerical Error = "<<fixed<<setprecision(3)<<fabs(ans2-ans1)<<"\n";

    return 0;
}

```

#### Newton Backward Interpolation Input
```
5
40 50 60 70 80
31 42 51 35 31
75
90 25

```

#### Newton Backward Interpolation Output
```
Backward Difference Table (upto 70-80)
31.00 
73.00 42.00 
124.00 51.00 9.00 
159.00 35.00 -16.00 -25.00 
190.00 31.00 -4.00 12.00 37.00 

Students between 70 and 75 = 13.805

Backward Difference Table (with 80-90)
31.00 
73.00 42.00 
124.00 51.00 9.00 
159.00 35.00 -16.00 -25.00 
190.00 31.00 -4.00 12.00 37.00 
215.00 25.00 -6.00 -2.00 -14.00 -51.00 

New Students between 70 and 75 = 15.199

Numerical Error = 1.395

```
⬆ [Back to Table of Contents](#toc)

### Newton Divided Difference Interpolation
#### Newton Divided Difference Interpolation Theory
[Add your theory content here]

#### Newton Divided Difference Interpolation Code
```python
#include <bits/stdc++.h>
using namespace std;

#define ll double

ll dividedDifference(vector<ll> &x, vector<ll> &y, ll tar, ofstream &out)
{
    int n = x.size();
    vector<vector<ll>> table(n, vector<ll>(n));

    for (int i = 0; i < n; i++)
        table[i][0] = y[i];

    for (int j = 1; j < n; j++)
        for (int i = 0; i < n - j; i++)
            table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x[i + j] - x[i]);

    out << "Divided Difference Table:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
            out << setw(12) << table[i][j] << " ";
        out << "\n";
    }
    out << "\n";

    ll ans = table[0][0];
    ll term = 1;

    for (int i = 1; i < n; i++)
    {
        term *= (tar - x[i - 1]);
        ans += term * table[0][i];
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
    for (int i = 0; i < n; i++) in >> x[i];
    for (int i = 0; i < n; i++) in >> y[i];

    ll target;
    in >> target;

    ll ans1 = dividedDifference(x, y, target, out);
    ll students1 = ans1 - y[0];

    out << "Cumulative frequency at " << target << " = " << ans1 << "\n";
    out << "Students between " << x[0] << " and " << target << " = " << students1 << "\n\n";

    ll nx, ny;
    in >> nx >> ny;

    x.push_back(nx);
    y.push_back(ny);

    out << "After adding new data:\n";

    ll ans2 = dividedDifference(x, y, target, out);
    ll students2 = ans2 - y[0];

    out << "Cumulative frequency at " << target << " = " << ans2 << "\n";
    out << "Students between " << x[0] << " and " << target << " = " << students2 << "\n";
    out << "Error = " << abs(students2 - students1) << "\n";

    in.close();
    out.close();

    return 0;
}

```

#### Newton Divided Difference Interpolation Input
```
5
40 50 60 70 80
31 73 124 159 190
45
90 220

```

#### Newton Divided Difference Interpolation Output
```
Forward Difference Table:
        31         42          9        -25         37 
        73         51        -16         12 
       124         35         -4 
       159         31 
       190 

Cumulative frequency at 45 = 47.8672
Students between 40 and 45 = 16.8672

After adding new data:
Forward Difference Table:
        31         42          9        -25         37        -46 
        73         51        -16         12         -9 
       124         35         -4          3 
       159         31         -1 
       190         30 
       220 

Cumulative frequency at 45 = 46.6094
Students between 40 and 45 = 15.6094
Error = 1.25781
```
⬆ [Back to Table of Contents](#toc)

### Numerical Integration

### Simpson’s 1/3 Rule

#### Simpson’s 1/3 Theory
[Add your theory content here]

#### Simpson’s 1/3 Code
```python
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
        if(i%2==0) sum+=2*f(x);
        else sum+=4*f(x);
    }

    double result=(h/3)*sum;
    cout<<"The Result is "<<fixed<<setprecision(6)<<result;
    return 0;
}


```

#### Simpson’s 1/3 Input
```
0 1
6
```

#### Simpson’s 1/3 Output
```
The Result is 0.785398
```
⬆ [Back to Table of Contents](#toc)

### Simpson’s 3/8 Rule

#### Simpson’s 3/8 Theory
[Add your theory content here]

#### Simpson’s 3/8 Code
```python
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


```

#### Simpson’s 3/8 Input
```
0 1
6
```

#### Simpson’s 3/8 Output
```
The Result is 0.785398
```
⬆ [Back to Table of Contents](#toc)

### Numerical Differentiation

### Differentiation By Forward Interpolation 

#### Differentiation By Forward Interpolation Theory
[Add your theory content here]

#### Differentiation By Forward Interpolation Code
```python
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double

int fact(int n)
{
    if(n==1 or n==0) return 1;
    else return fact(n-1)*n;
}

db f(db x)
{
    return ((pow(cos(x),5))-6*(pow(sin(x),5)))+log(x)+2;
}

db f1(db x)
{
    return -5*sin(x)*pow(cos(x),4)  -30*pow(sin(x),4)*cos(x)+1/x;
}

db f2(db x)
{
     return 30 * pow(sin(x), 5)-120 * pow(sin(x), 3) * pow(cos(x), 2)
            +20 * pow(sin(x), 2) * pow(cos(x), 3)
           -5 * pow(cos(x), 5)
           -1.0 / pow(x, 2);
}

vector<vector<db>> difftable(vector<db>&y)
{
    int n=y.size();
    vector<vector<db>>dftbl(n,vector<db>(n,0));
    for(int i=0;i<n;i++)  dftbl[i][0]=y[i];
    for(int j=1;j<n;j++)
    {
        for(int i=0;i<n-j;i++)
        {
            dftbl[i][j]=dftbl[i+1][j-1]-dftbl[i][j-1];
        }
    }
    return dftbl;
}

void solve(int tc, ifstream &fin, ofstream &fout)
{
    int n;
    fin>>n;
    cout<<"Reading number of intervals n: "<<n<<endl;
    fout<<"Reading number of intervals n: "<<n<<endl;

    db a,b;
    fin>>a>>b;
    cout<<"Reading interval start (a): "<<a<<", end (b): "<<b<<endl;
    fout<<"Reading interval start (a): "<<a<<", end (b): "<<b<<endl;

    db X;
    fin>>X;
    cout<<"Reading interpolation point X: "<<X<<endl;
    fout<<"Reading interpolation point X: "<<X<<endl;

    db h=(b-a)/n;

    vector<db>x(n),y(n);
    for(int i=0;i<n;i++)
    {
        x[i]=a+ i*h;
        y[i]=f(x[i]);
    }

    db u=(X-x[0])/h;
    vector<vector<db>>diff=difftable(y);

    db y1 = (diff[0][1] + (2*u-1)*diff[0][2]/fact(2)+ (3*u*u-6*u+2)*diff[0][3]/fact(3))/h;
    db y2= ((diff[0][2])+(u-1)*diff[0][3])/(h*h);

    db y1_1=f1(X);
    db y2_1=f2(X);
    db error_y1 = abs((y1_1-y1)/y1)*100;
    db error_y2 = abs((y2_1-y2)/y2)*100;

    cout<<"\nTEST CASE #"<<tc<<"\n";
    cout<<"n: "<<n<<", a: "<<a<<", b: "<<b<<", X: "<<X<<"\n";
    cout<<"Difference table:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<setw(10)<<diff[i][j]<<" ";
        cout<<endl;
    }
    cout<<"y': "<<y1<<endl;
    cout<<"y'': "<<y2<<endl;
    cout<<"functional value"<<endl;
    cout<<"y': "<<y1_1<<endl;
    cout<<"y'': "<<y2_1<<endl;
    cout<<"First diff error: "<<error_y1<<"%"<<endl;
    cout<<"Second diff error: "<<error_y2<<"%"<<endl;

    fout<<"\nTEST CASE #"<<tc<<"\n";
    fout<<"n: "<<n<<", a: "<<a<<", b: "<<b<<", X: "<<X<<"\n";
    fout<<"Difference table:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            fout<<setw(10)<<diff[i][j]<<" ";
        fout<<endl;
    }
    fout<<"y': "<<y1<<endl;
    fout<<"y'': "<<y2<<endl;
    fout<<"functional value"<<endl;
    fout<<"y': "<<y1_1<<endl;
    fout<<"y'': "<<y2_1<<endl;
    fout<<"First diff error: "<<error_y1<<"%"<<endl;
    fout<<"Second diff error: "<<error_y2<<"%"<<endl;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input.txt");
    if(!fin)
    {
        cout<<"Error: input.txt not found\n";
        return 0;
    }

    ofstream fout("output.txt");

    int t;
    fin>>t;
    cout<<"Total Test Cases: "<<t<<"\n";
    fout<<"Total Test Cases: "<<t<<"\n";

    for(int tc=1;tc<=t;tc++)
    {
        solve(tc, fin, fout);
    }

    cout<<"\nAll test cases completed! Results saved to output.txt\n";
    fin.close();
    fout.close();
    return 0;
}
```

#### Differentiation By Forward Interpolation Input
```
4

10
1 2
1.2

10
2 5.5
2.2

10
1 3
1.5

10
2 4
2.3
10
0.5 2.5
1
```

#### Differentiation By Forward Interpolation Output
```
Total Test Cases: 4
Reading number of intervals n: 10
Reading interval start (a): 1, end (b): 2
Reading interpolation point X: 1.2

TEST CASE #1
n: 10, a: 1, b: 2, X: 1.2
Difference table:
 -0.485274  -0.773437 0.000624729  0.0838691 0.00039901 -0.0142342 0.00134595  0.0028391 -0.000833681 -0.000475536 
  -1.25871  -0.772812  0.0844938  0.0842681 -0.0138352 -0.0128883 0.00418505 0.00200542 -0.00130922          0 
  -2.03152  -0.688318   0.168762  0.0704329 -0.0267235 -0.00870321 0.00619047 0.000696203          0          0 
  -2.71984  -0.519556   0.239195  0.0437094 -0.0354267 -0.00251273 0.00688668          0          0          0 
   -3.2394  -0.280361   0.282904 0.00828277 -0.0379394 0.00437394          0          0          0          0 
  -3.51976  0.0025429   0.291187 -0.0296566 -0.0335655          0          0          0          0          0 
  -3.51722    0.29373    0.26153 -0.0632221          0          0          0          0          0          0 
  -3.22349    0.55526   0.198308          0          0          0          0          0          0          0 
  -2.66823   0.753569          0          0          0          0          0          0          0          0 
  -1.91466          0          0          0          0          0          0          0          0          0 
y': -7.44543
y'': 8.44938
functional value
y': -7.45044
y'': 8.44411
First diff error: 0.0672453%
Second diff error: 0.0624101%
Reading number of intervals n: 10
Reading interval start (a): 2, end (b): 5.5
Reading interpolation point X: 2.2

TEST CASE #2
n: 10, a: 2, b: 5.5, X: 2.2
Difference table:
  -1.04909    2.63834   -1.92386    1.04153    0.25842   -1.29568    2.69353   -5.62903    9.02142   -7.72401 
   1.58925   0.714485   -0.88233    1.29995   -1.03726    1.39785   -2.93551    3.39239    1.29741          0 
   2.30373  -0.167845   0.417617   0.262688   0.360589   -1.53766   0.456878     4.6898          0          0 
   2.13589   0.249772   0.680305   0.623277   -1.17707   -1.08078    5.14668          0          0          0 
   2.38566   0.930078    1.30358  -0.553793   -2.25785     4.0659          0          0          0          0 
   3.31574    2.23366   0.749789   -2.81165    1.80804          0          0          0          0          0 
    5.5494    2.98345   -2.06186    -1.0036          0          0          0          0          0          0 
   8.53285   0.921593   -3.06546          0          0          0          0          0          0          0 
   9.45444   -2.14387          0          0          0          0          0          0          0          0 
   7.31057          0          0          0          0          0          0          0          0          0 
y': 6.92282
y'': -19.3488
functional value
y': 7.5133
y'': -14.1185
First diff error: 8.52955%
Second diff error: 27.0313%
Reading number of intervals n: 10
Reading interval start (a): 1, end (b): 3
Reading interpolation point X: 1.5

TEST CASE #3
n: 10, a: 1, b: 3, X: 1.5
Difference table:
 -0.485274   -1.54625   0.338374   0.591681  -0.394929  -0.158493    0.37355  -0.155896  -0.169906   0.274794 
  -2.03152   -1.20787   0.930056   0.196753  -0.553421   0.215057   0.217653  -0.325802   0.104888          0 
   -3.2394  -0.277818    1.12681  -0.356668  -0.338364   0.432711  -0.108149  -0.220914          0          0 
  -3.51722    0.84899    0.77014  -0.695032  0.0943467   0.324562  -0.329063          0          0          0 
  -2.66823    1.61913  0.0751078  -0.600686   0.418909 -0.00450118          0          0          0          0 
  -1.04909    1.69424  -0.525578  -0.181777   0.414407          0          0          0          0          0 
  0.645143    1.16866  -0.707355    0.23263          0          0          0          0          0          0 
    1.8138   0.461305  -0.474725          0          0          0          0          0          0          0 
   2.27511   -0.01342          0          0          0          0          0          0          0          0 
   2.26169          0          0          0          0          0          0          0          0          0 
y': -1.51236
y'': 30.6474
functional value
y': -1.43439
y'': 28.5928
First diff error: 5.15545%
Second diff error: 6.70414%
Reading number of intervals n: 10
Reading interval start (a): 2, end (b): 4
Reading interpolation point X: 2.3

TEST CASE #4
n: 10, a: 2, b: 4, X: 2.3
Difference table:
  -1.04909    1.69424  -0.525578  -0.181777   0.414407  -0.273259 -0.0020276   0.222792  -0.237882  0.0369795 
  0.645143    1.16866  -0.707355    0.23263   0.141149  -0.275286   0.220764 -0.0150904  -0.200903          0 
    1.8138   0.461305  -0.474725   0.373779  -0.134137  -0.054522   0.205674  -0.215993          0          0 
   2.27511   -0.01342  -0.100946   0.239641  -0.188659   0.151152 -0.0103194          0          0          0 
   2.26169  -0.114366   0.138695   0.050982 -0.0375076   0.140832          0          0          0          0 
   2.14732  0.0243295   0.189678  0.0134745   0.103325          0          0          0          0          0 
   2.17165   0.214007   0.203152   0.116799          0          0          0          0          0          0 
   2.38566   0.417159   0.319951          0          0          0          0          0          0          0 
   2.80282    0.73711          0          0          0          0          0          0          0          0 
   3.53993          0          0          0          0          0          0          0          0          0 
y': 5.88117
y'': -15.4117
functional value
y': 5.8808
y'': -17.9941
First diff error: 0.006297%
Second diff error: 16.7567%
```
⬆ [Back to Table of Contents](#toc)

### Differentiation By Backward Interpolation 

#### Differentiation By Backward Interpolation Theory
[Add your theory content here]

#### Differentiation By Backward Interpolation Code
```python
#include<bits/stdc++.h>

using namespace std;
double polyValue(const vector<double>&coeff,double x)
{
    double val=0,p=1;
    for(double c:coeff)
    {
        val+=c*p;
        p*=x;
    }
    return val;
}

double trueDerivative(const vector<double>&coeff,double x)
{
    double val=0;
    for(int i=1; i<coeff.size(); i++)
    {
        val+=i*coeff[i]*pow(x,i-1);
    }
    return val;
}

vector<vector<double>>buildBackwardDiffTable(const vector<double>&y)
{
    int n=y.size();
    vector<vector<double>>diff(n,vector<double>(n,0));
    for(int i=0; i<n; i++)diff[i][0]=y[i];
    for(int j=1; j<n; j++)
    {
        for(int i=n-1; i>=j; i--)
        {
            diff[i][j]=diff[i][j-1]-diff[i-1][j-1];
        }
    }
    return diff;
}

double newtonBackwardDerivative5(const vector<vector<double>>&diff,double xn,double h,double xp,int n)
{
    double s=(xp-xn)/h;
    double der=0;
    if(n>=2) der+=diff[n-1][1];
    if(n>=3) der+=((2*s+1)/2.0)*diff[n-1][2];
    if(n>=4) der+=((3*s*s+6*s+2)/6.0)*diff[n-1][3];
    if(n>=5) der+=((4*s*s*s+18*s*s+22*s+6)/24.0)*diff[n-1][4];
    if(n>=6) der+=((5*s*s*s*s+40*s*s*s+105*s*s+100*s+24)/120.0)*diff[n-1][5];
    return der/h;
}

string polyString(const vector<double>&c)
{
    stringstream ss;
    bool first=true;
    for(int i=0; i<c.size(); i++)
    {
        double a=c[i];
        if(fabs(a)<1e-12) continue;
        if(!first) ss<<(a>=0?" + ":" - ");
        else if(a<0) ss<<"-";
        if(a<0) a=-a;
        ss<<fixed<<setprecision(4)<<a;
        if(i==1) ss<<"x";
        else if(i>1) ss<<"x^"<<i;
        first=false;
    }
    return ss.str();
}

int main()
{
    ifstream inputFile("Input.txt");
    ofstream outputFile("Output.txt");
    if(!inputFile.is_open())
    {
        cerr<<"Error opening Input.txt!"<<endl;
        return 1;
    }
    int testCases;
    inputFile>>testCases;
    for(int tc=1; tc<=testCases; tc++)
    {
        int deg;
        inputFile>>deg;
        vector<double>coeff(deg+1);
        for(int i=0; i<=deg; i++) inputFile>>coeff[i];
        int n;
        inputFile>>n;
        vector<double>x(n),y(n);
        for(int i=0; i<n; i++) inputFile>>x[i];
        for(int i=0; i<n; i++) y[i]=polyValue(coeff,x[i]);
        double xp;
        inputFile>>xp;
        double h=x[1]-x[0];
        auto diff=buildBackwardDiffTable(y);
        double approx=newtonBackwardDerivative5(diff,x[n-1],h,xp,n);
        double trueVal=trueDerivative(coeff,xp);
        double err=fabs((trueVal-approx)/trueVal)*100.0;
        string poly=polyString(coeff);
        cout<<"Test Case "<<tc<<"\n";
        outputFile<<"Test Case "<<tc<<"\n";
        cout<<"Polynomial: f(x) = "<<poly<<"\n";
        outputFile<<"Polynomial: f(x) = "<<poly<<"\n";
        cout<<"Number of points: "<<n<<"\n";
        outputFile<<"Number of points: "<<n<<"\n";
        cout<<"x-values: ";
        outputFile<<"x-values: ";
        for(int i=0; i<n; i++)
        {
            cout<<x[i]<<" ";
            outputFile<<x[i]<<" ";
        }
        cout<<"\n";
        outputFile<<"\n";
        cout<<"y-values: ";
        outputFile<<"y-values: ";
        for(int i=0; i<n; i++)
        {
            cout<<fixed<<setprecision(6)<<y[i]<<" ";
            outputFile<<fixed<<setprecision(6)<<y[i]<<" ";
        }
        cout<<"\n";
        outputFile<<"\n";
        cout<<fixed<<setprecision(6);
        outputFile<<fixed<<setprecision(6);
        cout<<"Step size (h): "<<h<<"\n";
        outputFile<<"Step size (h): "<<h<<"\n";
        cout<<"Differentiation point: "<<xp<<"\n";
        outputFile<<"Differentiation point: "<<xp<<"\n";
        cout<<"Backward Difference Table:\n";
        outputFile<<"Backward Difference Table:\n";
        for(int i=0; i<n; i++)
        {
            cout<<"Row "<<i<<":  ";
            outputFile<<"Row "<<i<<":  ";
            for(int j=0; j<=i && j<n; j++)
            {
                cout<<setw(10)<<diff[i][j]<<" ";
                outputFile<<setw(10)<<diff[i][j]<<" ";
            }
            cout<<"\n";
            outputFile<<"\n";
        }
        cout<<"Approximate derivative : "<<approx<<"\n";
        outputFile<<"Approximate derivative : "<<approx<<"\n";
        cout<<"True derivative: "<<trueVal<<"\n";
        outputFile<<"True derivative: "<<trueVal<<"\n";
        cout<<"Percentage error: "<<err<<" %\n\n";
        outputFile<<"Percentage error: "<<err<<" %\n\n";
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
```

#### Differentiation By Backward Interpolation Input
```
2

3
1 2 -1 0.5
6
0 1 2 3 4 5
4.5

2
0 0 1
7
0 0.5 1 1.5 2 2.5 3
2
```

#### Differentiation By Backward Interpolation Output
```
Test Case 1
Polynomial: f(x) = 1.0000 + 2.0000x - 1.0000x^2 + 0.5000x^3
Number of points: 6
x-values: 0 1 2 3 4 5 
y-values: 1.000000 2.500000 5.000000 11.500000 25.000000 48.500000 
Step size (h): 1.000000
Differentiation point: 4.500000
Backward Difference Table:
Row 0:    1.000000 
Row 1:    2.500000   1.500000 
Row 2:    5.000000   2.500000   1.000000 
Row 3:   11.500000   6.500000   4.000000   3.000000 
Row 4:   25.000000  13.500000   7.000000   3.000000   0.000000 
Row 5:   48.500000  23.500000  10.000000   3.000000   0.000000   0.000000 
Approximate derivative : 23.375000
True derivative: 23.375000
Percentage error: 0.000000 %

Test Case 2
Polynomial: f(x) = 1.0000x^2
Number of points: 7
x-values: 0.000000 0.500000 1.000000 1.500000 2.000000 2.500000 3.000000 
y-values: 0.000000 0.250000 1.000000 2.250000 4.000000 6.250000 9.000000 
Step size (h): 0.500000
Differentiation point: 2.000000
Backward Difference Table:
Row 0:    0.000000 
Row 1:    0.250000   0.250000 
Row 2:    1.000000   0.750000   0.500000 
Row 3:    2.250000   1.250000   0.500000   0.000000 
Row 4:    4.000000   1.750000   0.500000   0.000000   0.000000 
Row 5:    6.250000   2.250000   0.500000   0.000000   0.000000   0.000000 
Row 6:    9.000000   2.750000   0.500000   0.000000   0.000000   0.000000   0.000000 
Approximate derivative : 4.000000
True derivative: 4.000000
Percentage error: 0.000000 %

```
⬆ [Back to Table of Contents](#toc)
---

