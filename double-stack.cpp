#include <iostream>
#include <stdio.h>

using namespace std;

const int MAX = 5;
int top = -1;
int bottom = MAX;

struct mahasiswa {
    int data[MAX];
}mhs;

bool isEmpty(){
    return top == -1 && bottom == MAX;
}

bool isFull () {
    return (bottom - 1) == top;
}

void push1 (int dataBaru) {
    if(isFull()){
        printf("PENUH");
    }else {
        top++;
        mhs.data[top] = dataBaru;
    }
}

void push2 (int dataBaru) {
    if(isFull()){
        printf("PENUH");
    }else {
        bottom--;
        mhs.data[bottom] = dataBaru;
    }
}

void pop1 () {
    top--;
}

void pop2 () {
    bottom++;
}

void view () {
    for (int i = 0; i <= top; i++){
        printf(" <- [DATA] : %d ",mhs.data[i]);
    }
    for (int i = bottom; i < MAX; i++){
        printf("[DATA] : %d -> ",mhs.data[i]);
    }
}

int main()
{
    bool exit = false;
    int chooseMenu, dataB;
    do {
        printf("\n\n1. Change MAX\n2. PUSH TOP\n3. PUSH BOTTOM\n4. POP TOP\n5. POP BOTTOM\n6. VIEW\nPILIH : ");
        cin >> chooseMenu;
       switch (chooseMenu){
        case 2:
            printf("DATA : "); cin >> dataB;
            push1(dataB);
            break;
        case 3:
            printf("DATA : "); cin >> dataB;
            push2(dataB);
            break;
        case 6:
            view();
            break;
        }
    } while (exit == false);
}
