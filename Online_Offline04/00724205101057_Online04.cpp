#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* link;
};

struct node* header1 = NULL;
struct node* header2 = NULL;
struct node* create_node(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL)exit(1);
    newNode->data = value;
    newNode->link = NULL;
};

void insertVal1(int value){
    struct node* newNode = create_node(value);
    if(header1 == NULL){
        header1 = newNode;
        return;
    }
    newNode->link = header1;
    header1 = newNode;
}
void insertVal2(int value){
    struct node* newNode = create_node(value);
    if(header2 == NULL){
        header2 = newNode;
        return;
    }
    newNode->link = header2;
    header2 = newNode;
}

void print1(){
    struct node* ptr1 = header1;
    for(int i = 1; ptr1 != NULL; ptr1 = ptr1->link){
        cout << ptr1->data << " ";
    }
}
void print2(){
    struct node* ptr2 = header2;
    for(int i = 1; ptr2 != NULL; ptr2 = ptr2->link){
        cout << ptr2->data << " ";
    }
}

void findVAL(struct node* ptr3 = header1){
    while(ptr3 != NULL){
        if(ptr3->data % 5 == 0 && ptr3->data > 20 ){
            cout << "Divisible by 5 and greater than 20 is " << ptr3->data << endl;
        }
    ptr3 = ptr3->link;
    }
}

int listSize(){
    int count = 0;
    struct node* pt = header2;
    while(pt != NULL){
        pt = pt->link;
        count++;
    }
    return count;
}
void findMID(struct node* ptr4 = header2){
    int c = listSize();
    int mid;
    if(c % 2 == 0){
        int mid = c / 2;
    }else{
        int mid = ((c-1)/2) + 1;
    }
    int pos = 1;
    while (ptr4->link != NULL && pos <= mid){
        ptr4 = ptr4->link;
    }
    cout << "mid value of list 2 " << ptr4->link->data << endl;
}

void del(int value){
    struct node* pt5 = header1;
    while(pt5->link != NULL && pt5->data != value){

    }
}
int main(){
    insertVal1(35);
    insertVal1(25);
    insertVal1(15);
    insertVal1(5);

    print1();
    cout << endl;
    insertVal2(30);
    insertVal2(20);
    insertVal2(10);
    print2();
    cout<< endl;
    findVAL();
    findMID();
    // remove 25 from list 1 and add it to list 2 instantly

    return 0;
}
