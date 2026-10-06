#include <iostream>
#include <string>

using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

// TODO : Menambahkan karakter ke stack
void push(char value)
{
    if (top == MAX - 1)
    {
        cout << "Stack penuh!" << endl;
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

// TODO : Mengambil karakter paling atas
char pop()
{
    if (top == -1)
    {
        return '\0';
    }
    else
    {
        char value = stack[top];
        top--;
        return value;
    }
}

int main()
{

    string kata;

    cout << "Masukkan sebuah kata: ";
    cin >> kata;

    // TODO : Memasukkan setiap karakter ke stack
    for (int i = 0; i < kata.length(); i++)
    {
        push(kata[i]);
    }

    // TODO Mengeluarkan karakter dari stack
    cout << "Kata setelah dibalik: ";

    while (top != -1)
    {
        cout << pop();
    }

    cout << endl;

    return 0;
}