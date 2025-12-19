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
    cout<<"enter:";
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