#include <iostream>
#include <conio.h>
#include <windows.h>
#include <climits>
using namespace std;

#define MAX 100

int graph[MAX][MAX];
int vertexWeights[MAX];
int n;
char simpul1 = 'A';
char simpul2 = 'A';

void addEdge(int n) {
    int i, j, weight;
    cout << "Beri nilai weight untuk edge antara kedua simpul yang terhubung, dan 0 jika kedua simpul tidak terhubung" << endl << endl;
    for (i = 0; i < n; i++) {
        cout << "Simpul " << simpul1++ << " terhubung dengan: " << endl;
        for (j = 0; j < n; j++) {
            if (i != j) {
                cout << "simpul " << char('A' + j) << " (weight): ";
                cin >> weight;
                graph[i][j] = weight;
            } else {
                graph[i][j] = 0; // No self-loops
            }
        }
        cout << endl;
    }
    simpul1 = 'A';
}

void addVertexWeights(int n) {
    int weight;
    for (int i = 0; i < n; i++) {
        cout << "Masukkan weight untuk simpul " << char('A' + i) << ": ";
        cin >> weight;
        vertexWeights[i] = weight;
    }
}

void printGraph(int n) {
    cout << "Cetak Adjacency Matrix" << endl << endl;
    int i, j;
    cout << "  ";
    for (i = 0; i < n; i++) {
        cout << char('A' + i) << "  ";
    }
    cout << endl;
    for (i = 0; i < n; i++) {
        cout << char('A' + i) << "  ";
        for (j = 0; j < n; j++) {
            cout << graph[i][j] << "  ";
        }
        cout << endl;
    }
}

void searchPath(char x, char y) {
    int source = x - 'A';
    int destination = y - 'A';
    int dist[MAX];
    int parent[MAX];
    bool visited[MAX] = {false};

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int minDist = INT_MAX, u;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] <= minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    if (dist[destination] == INT_MAX) {
        cout << "Tidak ada jalur dari " << x << " ke " << y << endl;
    } else {
        cout << "Jarak terpendek dari " << x << " ke " << y << " adalah " << dist[destination] << endl;

        cout << "Jalur terpendek adalah: ";
        int path[MAX], count = 0;
        for (int v = destination; v != -1; v = parent[v]) {
            path[count++] = v;
        }
        for (int i = count - 1; i >= 0; i--) {
            cout << char(path[i] + 'A');
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    }
}

void deleteEdge(char x, char y) {
    int i = x - 'A';
    int j = y - 'A';
    graph[i][j] = 0;
    graph[j][i] = 0;
    cout << "Garis antara simpul " << x << " dan simpul " << y << " berhasil dihapus!" << endl;
}

void deleteVertex(char z) {
    int v = z - 'A';
    if (v >= n) {
        cout << "Simpul tidak ada" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = v; j < n - 1; j++) {
            graph[i][j] = graph[i][j + 1];
        }
    }

    for (int i = v; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = graph[i + 1][j];
        }
    }

    n--;
    cout << "Simpul " << z << " berhasil dihapus!" << endl;
}

int main() {
    cout << "============================================================" << endl;
    cout << "Program ini dibuat oleh : " << endl;
    cout << "Nama  : Indira Ayu Anggraeni" << endl;
    cout << "NPM   : 2310631170021" << endl;
    cout << "Kelas : 2C-Informatika" << endl;
    cout << "============================================================" << endl;

    cout << "Tekan apa saja untuk melanjutkan!" << endl;
    getch();

    first:
    system("cls");
    char name = 'A', x, y;
    int pil;

    cout << "========================================" << endl;
    cout << "             Adjacency Matrix           " << endl;
    cout << "========================================" << endl;
    cout << "1. Tambah simpul dan sisi " << endl;
    cout << "2. Print graph " << endl;
    cout << "3. Cari jalur " << endl;
    cout << "4. Hapus simpul " << endl;
    cout << "5. Hapus sisi " << endl;
    cout << "\nMasukkan pilihan : "; cin >> pil;

    if (pil == 1) {
        system("cls");
        cout << "Masukkan jumlah n : ";
        cin >> n;
        addEdge(n);
        addVertexWeights(n);

        cout << endl;
        cout << "Simpul berhasil dibuat." << endl;
        cout << "Tekan apa saja untuk melanjutkan!";
        getch();
        goto first;
    } else if (pil == 2) {
        system("cls");
        printGraph(n);
        cout << "\nTekan apa saja untuk melanjutkan!";
        getch();
        goto first;
    } else if (pil == 3) {
        system("cls");
        cout << "Mencari jalur terpendek " << endl;
        cout << "Masukkan node asal   : "; cin >> x;
        cout << "Masukkan node tujuan : "; cin >> y;
        searchPath(x, y);
        cout << endl;
        cout << "Tekan apa saja untuk melanjutkan!";
        getch();
        goto first;
    } else if (pil == 4) {
        system("cls");
        printGraph(n);
        cout << "\nMenghapus simpul = "; cin >> x;
        deleteVertex(x);
        cout << endl;
        cout << "Tekan apa saja untuk melanjutkan!";
        getch();
        goto first;
    } else if (pil == 5) {
        system("cls");
        printGraph(n);
        cout << "\nMenghapus garis antara simpul "; cin >> x;
        cout << " dengan simpul "; cin >> y;
        deleteEdge(x, y);
        cout << endl;
        cout << "Tekan apa saja untuk melanjutkan!";
        getch();
        goto first;
    } else {
        cout << "Input yang anda masukkan salah" << endl;
        char rep;
        cout << "Apakah anda ingin melanjutkan?"; cin >> rep;
        if (rep == 'y' || rep == 'Y') {
            cout << endl;
            cout << "Tekan apa saja untuk melanjutkan!";
            getch();
            goto first;
        } else {
            return 0;
        }
    }
}
