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
