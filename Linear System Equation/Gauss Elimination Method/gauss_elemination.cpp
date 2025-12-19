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

