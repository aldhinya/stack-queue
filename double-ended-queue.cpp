#include <iostream>
#include <stdio.h>
#define MAX 3

using namespace std;

struct mahasiswa {
    int data[MAX];
    string nama[MAX];
    int front;
    int rear;
}mhs;

void inisialisasi () {
    mhs.front = -1;
    mhs.rear = MAX;
}

bool isEmpty () {
    return mhs.front == -1 && mhs.rear == MAX;
}

bool isFull () {
    return mhs.front == mhs.rear - 1;
}

void enqueueFront () {
    if(isFull()){
        printf("DATA PENUH");
    } else {
        mhs.front++;
        printf("DATA : "); cin >> mhs.data[mhs.front];
        printf("NAMA : "); cin >> mhs.nama[mhs.front];
    }
}

void enqueueRear () {
    if (isFull()) {
        printf("DATA PENUH");
    } else {
        mhs.rear--;
        printf("DATA : "); cin >> mhs.data[mhs.rear];
        printf("NAMA : "); cin >> mhs.nama[mhs.rear];
    }
}

void dequeueFront () {
    if(isEmpty()){
        printf("DATA KOSONG");
    } else {
        for (int i = 0; i < mhs.front; i++) {
            mhs.data[i] = mhs.data[i+1];
            mhs.nama[i] = mhs.nama[i+1];
        }
        mhs.front--;
    }
}

void dequeueRear () {
    if(isEmpty()){
        printf("DATA KOSONG");
    } else {
        for (int i = MAX - 1; i > mhs.rear; i--) {
            mhs.data[i] = mhs.data[i-1];
            mhs.nama[i] = mhs.nama[i-1];
        }
        mhs.rear++;
    }
}
void view () {
    if (isEmpty()){
        printf("DATA KOSONG GAN");
    } else {
        for (int i = 0; i <= mhs.front; i++){
            cout << " <- DATA : "<< mhs.data[i] << " NAMA : " << mhs.nama[i];
        }

        for (int i = mhs.rear; i < MAX; i++) {
            cout << " DATA : "<< mhs.data[i] << " NAMA : " << mhs.nama[i] << " -> ";
        }
    }
}

main () {
    bool exit = false;
    int chooseMenu;
    inisialisasi();
    do {
        printf("\n1. ENQUEUE FRONT\n2. ENQUEUE REAR\n3. DEQUEUE FRONT\n4. DEQUEUE REAR\n5. VIEW\nCHOOSE : "); cin >> chooseMenu;
        switch(chooseMenu){
            case 1:
                enqueueFront();
                break;
            case 2:
                enqueueRear();
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                view();
                break;
        }
    } while (exit == false);

}