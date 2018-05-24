#include<iostream>
#define max 5
using namespace std;

struct datatoko
{
   char nama_barang[50];
   char harga[50];
};
struct node{
    int data;
    node *next;
    datatoko pembelian;
}*front=NULL,*rear=NULL,*n,*temp,*temp1;
int nomor=1;

void insertion()
{
    n=new node;

    cout << "\n"  ;
    cout << "-------------System inventory Toko------------ " << endl ;
    cout << "\n"  ;
    cout << "Masukkan Nama Barang                : " ;cin.sync();
    cin.getline(n->pembelian.nama_barang,50) ;
    cout << "Masukkan harga                      : "  ;
    cin.getline(n->pembelian.harga,50) ;
    cout << "\n"  ;

    if(front==NULL){
        front=n;
        rear=n;
        rear->next=front;
    }
    else if(nomor==max){
        cout<<"\nCircular Queue Is Full!!!\n";
    }
    else{
        rear->next=n;
        rear=n;
        rear->next=front;
        nomor++;
    }

}

void deletion()
{

  temp=front;
  if(front==NULL)
  {
      cout<<"\nCircular Queue Empty!!!";
  }
  else
  {
     if(front==rear)
     {
       delete(temp);
       front=NULL;
       rear=NULL;
     }
     else
     {
        front=front->next;
        rear->next=front;
        delete(temp);
        nomor--;
     }
     cout<<"\nDeleted";
  }

}

void display()
{
  temp=front;
  temp1=NULL;
  if(front==NULL)
  {
    cout<<"\n\nCircular Queue Empty!!!";
  }
  else
  {
    cout<<"\n\nCircular Queue Elements are:\n\n";
    while(temp!=temp1)
    {
  cout << "Nama               : " << temp->pembelian.nama_barang << endl ;
    cout << "harga              : " << temp->pembelian.harga << endl ;
       temp=temp->next;
       temp1=front;
    }
  }
}

int main()
{

  int pil;

  do
  {
     cout<<"\n1. Insert\n2. Delete\n3. Display\n4. Exit\n\nEnter Your Choice: ";
     cin>>pil;
     switch(pil)
     {
        case 1:
          insertion();
          display();
          break;
        case 2:
          deletion();
          display();
          break;
        case 3:
          display();
          break;
        case 4:
          break;
        default:
          cout<<"\n\nsalah";
     }
  }while(pil!=4);

  return 0;
}
