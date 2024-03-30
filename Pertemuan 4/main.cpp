#include <iostream>
using namespace std;

// mendefinisikan sebuah struktur bernama 'Node' yang memiliki dua anggota, yaitu 'data' dan 'next'.
struct Node{
    int data; // mendeklarasikan variabel bernama 'data' yang bertipe data 'int' digunakan untuk menyimpan data.
    Node* next; // pointer yang menunjuk ke node selajutnya dalam linked list.

    // konstruktor untuk 'Node'
    Node(int val) : data(val), next(nullptr){} // menginisialisasi 'data' dengan nilai 'val' yang diberikan dan 'next' dengan 'nullptr'
};

//fungsi untuk membalikkan LinkedList
Node* reverseLinkedList(Node* head){
    Node *prev = nullptr, *current = head, *next = nullptr;
    while (current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

//fungsi untuk mencetak linked list
void displayLinkedList(Node* head){
    Node* temp = head;
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    int jml;
    cout << "\nMasukkan jumlah data : ";
    cin >> jml;
    Node* head = nullptr;
    Node* tail = nullptr;


    for (int i = 0; i < jml; i++){ // loop 'for' digunakan untuk mengulangi proses input nilai data sebanyak 'jml' kali.
        cout << "\nMasukkan nilai data ke-" << i+1 << " : ";
        int val;
        cin >> val;
        Node* newNode = new Node (val);

        if (head == nullptr){ // mengecek kondisi apakah linked list sudah memiliki elemen atau belum.
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // menampilkan LinkedList sebelum dibalik
    cout << "\n--------------------------------------------------------";
    cout << "\nLinkedList sebelum dibalik : ";
    displayLinkedList(head);
    head = reverseLinkedList(head);

    // menampilkan LinkedList setelah dibalik
    cout << "\nLinkedList setelah dibalik : ";
    displayLinkedList(head);
    cout << "--------------------------------------------------------" << endl;

    cout << "\nNama  : Indira Ayu Anggraeni" << endl;
    cout << "NPM   : 2310631170021" << endl;
    cout << "kelas : 2C-Informatika" << endl;
    cout << endl;

    return 0;
}
