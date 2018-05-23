#include <iostream>
#include <windows.h>

using namespace std;

struct
{
    char nama[100];
    int nilai;
}  tumpukan[100];

int top=-1, batas;

bool isFull ()
{
    return top==batas-1;
}

bool isEmpty ()
{
    return top==-1;
}

void push()
{
    if (isFull())
    {
        cout <<"Error: Data sudah penuh !"<<endl;
    }
    else
    {
        top++;
        cin.sync();
        cout <<"> Input Nama  = ";
        cin.getline(tumpukan[top].nama, 100);
        cout <<"> Input Nilai = ";
        cin >> tumpukan[top].nilai;
        cout <<"Data berhasil dimasukkan !" <<endl;
    }
}

void pop()
{
    string dataNama;
    int dataNilai;
    if (isEmpty())
    {
        cout <<"Data kosong !"<<endl;
    }
    else
    {
        dataNama = tumpukan[top].nama;
        dataNilai = tumpukan[top].nilai;
        top--;
        cout << "Data berikut berhasil dihapus :" <<endl<<endl;
        cout << "> Nama   = " << dataNama <<endl;
        cout << "> Nilai  = " << dataNilai <<endl;
    }
}

void view()
{
    if (isEmpty())
    {
        cout <<"Data kosong !"<<endl;
    }
    else
    {
        cout <<">> Isi Data : " <<endl<<endl;
        for (int i=top; i>=0; i--)
        {
            cout << "> Nama  = " <<tumpukan[i].nama <<endl;
            cout << "> Nilai = " <<tumpukan[i].nilai <<endl<<endl;
        }
    }
}

bool peek()
{
    if (isEmpty())
    {
        cout <<"Data kosong !"<<endl;
    }
    else
    {
        cout <<">> Data Paling Atas :"<<endl<<endl;
        cout << "> Nama  = " <<tumpukan[top].nama <<endl;
        cout << "> Nilai = " <<tumpukan[top].nilai<<endl;
    }
}

void clear()
{
    if (isEmpty())
    {
        cout <<"Data kosong !"<<endl;
    }
    else
    {
        top=-1;
        cout << "Semua Data berhasil dihapus." <<endl;
    }
}

int main()
{
    int menu;

    cout << "Input Batas Data = ";
    cin >>batas;
    do
    {

        cout << "==============" <<endl;
        cout << "Pilih Menu :" <<endl;
        cout << "==============" <<endl;
        cout << "1. Push" <<endl;
        cout << "2. Pop" <<endl;
        cout << "3. View" <<endl;
        cout << "4. Peek" <<endl;
        cout << "5. Clear" <<endl;
        cout << "6. Exit" <<endl;
        cout << "\n>> Input Menu = ";
        cin>>menu;
        system("cls");
        if (menu == 1)
        {
            push();
        }
        else if (menu == 2)
        {
            pop();
        }
        else if (menu == 3)
        {
            view();
        }
        else if (menu == 4)
        {
            peek();
        }
         else if (menu == 5)
        {
            clear();
        }
        else if (menu == 6)
        {
            exit(0);
        }
        else
        {
            cout <<"Input yang benar!"<<endl;
        }
        cout <<endl;
        system("pause");
        system("cls");
    }
    while(true);
}
