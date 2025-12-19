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

