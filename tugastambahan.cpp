#include <iostream>
using namespace std;

int main() {
    int a[2][2], b[2][2], c[2][2], i, j, k;

    // Input matrix a
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            cout << "A [" << i << "," << j << "] = ";
            cin >> a[i][j];
        }
    }

    // Input matrix b
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            cout << "B [" << i << "," << j << "] = ";
            cin >> b[i][j];
        }
    }

     // Multiply matrix a and b
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            c[i][j] = 0;
            for (k=0;k<2;k++) {
                c[i][j] = c[i][j] + a[i][k]*b[k][j];
            }
        }
    }

    cout << "Hasil perkalian matriks A dan B\n";
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            cout << c[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
