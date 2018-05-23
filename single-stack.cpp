#include <iostream>
#include <windows.h>

using namespace std;

struct
{
    int input, s[100], top, batas;
}  tumpukan;

bool isFull ()
{
    return tumpukan.top==tumpukan.batas-1;
}

bool isEmpty ()
{
    return tumpukan.top==-1;
}

void push()
{
    if (isFull())
    {
        cout <<"Error: Data sudah penuh !"<<endl;
    }
    else
    {
        tumpukan.top++;
        cout <<">> Input Data = ";
        cin>>tumpukan.input;
        tumpukan.s[tumpukan.top] = tumpukan.input;
        cout <<"Data berhasil dimasukkan !" <<endl;
    }
}

void pop()
{
    int DATA;
    if (isEmpty())
    {
        cout <<"Data kosong !"<<endl;
    }
    else
    {
        cout << "Data " <<tumpukan.s[tumpukan.top]<< " berhasil dihapus !" <<endl;
        tumpukan.top--;
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
        cout <<">> Isi Data = " <<endl;
        for (int i=tumpukan.top; i>=0; i--)
        {
            cout << " [" <<tumpukan.s[i] << "]"<<endl; ;
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
        cout <<">> Data Paling Atas = [" << tumpukan.s[tumpukan.top] << "]" <<endl;
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
        tumpukan.top=-1;
        cout << "Semua Data berhasil dihapus." <<endl;
    }
}

int main()
{
    tumpukan.top = -1;
    int menu;

    cout << "Input Batas Data = ";
    cin >>tumpukan.batas;
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
