#include <iostream>
#include <stdio.h>
#define MAX 3

using namespace std;

struct mahasiswa {
    int data[MAX];
    string nama[MAX];
    int front;
    mahasiswa *next;
}mhs;

mahasiswa *head = NULL, *tail = NULL, *baru, *help, *deleteNode;

void inisialisasi () {
    mhs.front = -1;
}

bool isEmpty () {
    return mhs.front == -1;
}

bool isFull () {
    return mhs.front == MAX - 1;
}

void push () {
    if(isFull()){
        printf("DATA PENUH");
    } else {
        baru = new mahasiswa;
        baru -> next = baru;
        mhs.front++;
        printf("DATA : "); cin >> baru -> data[mhs.front];
        printf("NAMA : "); cin >> baru -> nama[mhs.front];
        if(head == NULL) {
            head = baru;
            tail = baru;
        } else {
            tail -> next = baru;
            baru -> next = head;
            tail = baru;
        }
    }
}

void pop () {
    if(isEmpty()){
        printf("DATA KOSONG");
    } else {
        help = head;
        deleteNode = tail;
        while (help -> next != tail){
            help = help -> next;
        }
        tail = help;
        tail -> next = head;
        delete deleteNode;
        mhs.front--;
    }
}

void view () {
    if (isEmpty()){
        printf("DATA KOSONG GAN");
    } else {
        help = head;
        int i = 0;
        do {
            cout << " <- DATA : "<< help -> data[i] << " NAMA : " << help -> nama[i];
            i++;
            help = help -> next;
        }while (help != head);
    }
}

main () {
    bool exit = false;
    int chooseMenu;
    inisialisasi();
    do {
        printf("\n1. PUSH MEONG\n2. POP MIE\n3. VIEW\nCHOOSE : "); cin >> chooseMenu;
        switch(chooseMenu){
            case 1:
                push();
                break;
            case 2:
                pop ();
                break;
            case 3:
                view ();
                break;
        }
    } while (exit == false);

}