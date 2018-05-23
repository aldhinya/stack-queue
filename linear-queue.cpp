#include <iostream>
#define MAX 20
using namespace std;

struct Queue
{
    int front, rear, data[MAX];
} Q;

bool isFull()
{
    return Q.rear == MAX;
}

bool isEmpty()
{
    return Q.rear == 0;
}

void printQueue()
{
    if (isEmpty())
    {
        cout << "Antrian kosong"<<endl;
    }
    else
    {
        cout << "QUEUE : ";
        for (int i = Q.front; i < Q.rear; i++)
            cout << "[" << Q.data[i] << "]";
        cout << endl;
    }
}

void enqueue()
{
    if (isFull())
    {
        cout << "Antrian penuh!"<<endl;
    }
    else
    {
        int data;
        cout << "Masukkan Data : ";
        cin >> data;
        Q.data[Q.rear] = data;
        Q.rear++;
        cout << "Data ditambahkan\n";
        printQueue();
    }
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Antrian masih kosong"<<endl;
    }
    else
    {
        cout << "Mengambil data [" << Q.data[Q.front] << "]" << endl;
        for (int i = Q.front; i < Q.rear; i++)
            Q.data[i] = Q.data[i + 1];
        Q.rear--;
        printQueue();
    }
}

int main()
{
    int choose;
    do
    {
        cout << "-------------------" <<endl;
        cout << " > Menu Pilihan"  <<endl;
        cout << "-------------------"  <<endl;
        cout << " [1] Enqueue"  <<endl;
        cout << " [2] Dequeue"  <<endl;
        cout << " [3] Keluar"  <<endl;
        cout << "-------------------"  <<endl;
        cout << "Pilih Menu : ";
        cin >> choose;
        if (choose==1)
        {
            enqueue();
        }
        else if (choose==2)
        {
            dequeue();
        }
        else if (choose==3)
        {
            return 0;
        }
        else
        {
            cout << "Input yang benar!" <<endl;
        }
    }
    while (true);
    return 0;
}
