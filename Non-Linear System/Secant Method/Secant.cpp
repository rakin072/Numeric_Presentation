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
