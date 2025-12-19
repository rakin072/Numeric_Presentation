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
  
---

### Solution of Linear Equations

### Gauss Elimination Method

#### Gauss Elimination Theory
[Add your theory content here]

#### Gauss Elimination Code
```python
# Add your code here
```

#### Gauss Elimination Input
```
[Add your input format here]
```

#### Gauss Elimination Output
```
[Add your output format here]
```

---

### Gauss Jordan Elimination Method

#### Gauss Jordan Theory
[Add your theory content here]

#### Gauss Jordan Code
```python
# Add your code here
```

#### Gauss Jordan Input
```
[Add your input format here]
```

#### Gauss Jordan Output
```
[Add your output format here]
```

---

### LU Decomposition Method

#### LU Decomposition Theory
[Add your theory content here]

#### LU Decomposition Code
```python
# Add your code here
```

#### LU Decomposition Input
```
[Add your input format here]
```

#### LU Decomposition Output
```
[Add your output format here]
```

---

### Matrix Inversion

#### Matrix Inversion Theory
[Add your theory content here]

#### Matrix Inversion Code
```python
# Add your code here
```

#### Matrix Inversion Input
```
[Add your input format here]
```

#### Matrix Inversion Output
```
[Add your output format here]
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
```1x^4-5x^2+4=0
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
