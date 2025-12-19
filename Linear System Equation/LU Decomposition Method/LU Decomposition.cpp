#include <bits/stdc++.h>
using namespace std;

int main()
{
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
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
    return 0;
}
