#include <iostream>
using namespace std;

// Deklarasi Struktur Node
struct Node
{
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

// Fungsi Cetak List
void printList()
{
    Node *temp = head;

    cout << "Isi Linked List: ";

    if (head == NULL)
    {
        cout << "Kosong";
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
    }

    cout << "NULL\n";
}

// Tambah node di awal
void insertFirst(int n)
{
    Node *newNode = new Node{n, NULL};

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

// Tambah node di akhir
void insertLast(int n)
{
    Node *newNode = new Node{n, NULL};

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// Tambah node setelah nilai tertentu
void insertAfter(int n, int check)
{
    if (head == NULL)
    {
        cout << "List kosong!\n";
        return;
    }

    Node *p = head;

    while (p != NULL && p->value != check)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "Node dengan nilai " << check
             << " tidak ditemukan!\n";
        return;
    }

    Node *newNode = new Node{n, NULL};

    newNode->next = p->next;
    p->next = newNode;

    if (p == tail)
    {
        tail = newNode;
    }
}

// Hapus node berdasarkan nilai
void deleteByValue(int value)
{
    if (head == NULL)
    {
        cout << "List kosong!\n";
        return;
    }

    // Jika yang dihapus adalah node pertama
    if (head->value == value)
    {
        Node *temp = head;
        head = head->next;

        if (head == NULL)
        {
            tail = NULL;
        }

        delete temp;
        return;
    }

    // Mencari node sebelum node yang akan dihapus
    Node *p = head;

    while (p->next != NULL && p->next->value != value)
    {
        p = p->next;
    }

    // Jika tidak ditemukan
    if (p->next == NULL)
    {
        cout << "Node dengan nilai " << value
             << " tidak ditemukan!\n";
        return;
    }

    Node *temp = p->next;

    p->next = temp->next;

    if (temp == tail)
    {
        tail = p;
    }

    delete temp;
}

int main()
{
    int pilihan;
    int nilai;
    int setelah;

    do
    {
        cout << "\n===== MENU SINGLE LINKED LIST =====\n";
        cout << "1. Tambah di awal\n";
        cout << "2. Tambah di akhir\n";
        cout << "3. Tambah setelah nilai tertentu\n";
        cout << "4. Hapus berdasarkan nilai\n";
        cout << "5. Tampilkan Linked List\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {

        case 1:
            cout << "Masukkan nilai: ";
            cin >> nilai;

            insertFirst(nilai);

            printList();
            break;

        case 2:
            cout << "Masukkan nilai: ";
            cin >> nilai;

            insertLast(nilai);

            printList();
            break;

        case 3:
            cout << "Masukkan nilai baru: ";
            cin >> nilai;

            cout << "Masukkan nilai yang ingin dicari: ";
            cin >> setelah;

            insertAfter(nilai, setelah);

            printList();
            break;

        case 4:
            cout << "Masukkan nilai yang ingin dihapus: ";
            cin >> nilai;

            deleteByValue(nilai);

            printList();
            break;

        case 5:
            printList();
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}