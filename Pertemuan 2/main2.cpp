#include <iostream>

using namespace std;

//fungsi untuk merotasi matriks sebesar 90 derajat
void rotateMatrix(int matrix[3][3]) {
    int rotatedMatrix[3][3];

    for(int i = 0; i < 3; i++){ // loop pertama yang akan mengiterasi melalui baris matriks input.
        for(int j = 0; j < 3; j++){ // loop kedua yang akan mengiterasi melalui kolom matriks input.
            rotatedMatrix[j][2 - i] = matrix[i][j];
        }
    }

    //output matriks yang telah diputar
    cout << "Matriks setelah diputar:" << endl;
    for(int i = 0; i < 3; i++){ // loop pertama yang akan melalui baris matriks hasil rotasi.
        for(int j = 0; j < 3; j++){ // loop kedua yang akan mengiterasi melalui kolom matriks hasil rotasi.
            cout << rotatedMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[3][3];

    //input nilai matrix
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << "Masukan nilai dari matriks [" << i <<"][" << j << "] : ";
            cin >> matrix[i][j];
        cout << endl;
    }

    }

    //tampilkan matriks sebelum diputar
    cout << "Matriks sebelum diputar:" << endl;
    for(int i = 0; i < 3; i++){ // loop pertama yang digunakan untuk mengiterasi melalui setiap baris matriks.
        for(int j = 0; j < 3; j++){ // loop kedua yang digunakan untuk mengiterasi melalui setiap elemen dalam baris matriks.
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    //putar matriks 90 derajat sekali
    rotateMatrix(matrix);

    cout << "\nNama  : Indira Ayu Anggraeni" << endl;
    cout << "NPM   : 2310631170021" << endl;

   return 0;
}
