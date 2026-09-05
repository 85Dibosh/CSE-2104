#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* link;
};

struct node* header = NULL;

struct node* create(int val){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        cout << "Memory Allocation failed.";
        exit(1);
    }

    newNode->data = val;
    newNode->link = NULL;
    return newNode;
}

void insertF(int val){
    struct node* n = create(val);
    if(header == NULL){
        header = n;
    }else{
        n->link = header;
        header = n;
    }
}

void insertL(int val){
    struct node* n = create(val);
    if(header == NULL){
        header = n;
    }else{
        struct node* ptr = header;
        while(ptr->link != NULL)
        {
            ptr = ptr->link;
        };
        ptr->link = n;

    }
}

void insertA(int pos, int val, bool isPos){
    if(isPos == true){
        if(pos == 1){
            insertF(val);
        }else{
            struct node* n = create(val);
            struct node* ptr = header;

            for(int i = 1; i < pos - 1 && ptr->link != NULL; i++){
                ptr = ptr->link;
            }
            if(ptr == NULL){
                cout << "Invalid POS" << endl;
                free(n);
            }else{
                n->link = ptr->link;
                ptr->link = n;
            }

        }
    }else{
        struct node* n = create(val);
        if(header == NULL || n->data < header->data){
            n->link = header;
            header = n;
        }else{
            struct node* ptr = header;
            while(ptr->link != NULL && n->data > ptr->link->data){
                ptr = ptr->link;
            }
            n->link = ptr->link;
            ptr->link = n;
        }
    }
}

void deleteF(){
    if(header == NULL){
        cout << "List Empty." << endl;
    }else{
        struct node* ptr = header;
        header = header->link;
        free(ptr);
    }
}

void deleteL(){
    if(header == NULL){
        cout << "List Empty." << endl;
    }else if(header->link == NULL){
        deleteF();
    }else{
        struct node* ptr = header;
        struct node* ptr1 = NULL;
        while(ptr->link != NULL){
            ptr1 = ptr;
            ptr = ptr->link;
        }
        ptr1->link = NULL;
        free(ptr);
    }
}

void deleteA(int posVal, bool isPos){
    if(header == NULL){
        cout << "List Empty" << endl;
        return;
    }

    if( isPos == true){
        if(posVal == 1){
            deleteF();
        }else{
            struct node* ptr = header;
            for(int i = 1; i < posVal - 1 && ptr->link != NULL; i++){
                ptr = ptr->link;
            }
            if(ptr->link == NULL){
                cout << "Invalid Position" << endl;
            }else{
                struct node* ptr1 = ptr->link;
                ptr->link = ptr->link->link;
                free(ptr1);

            }
        }

    }else{
        if(header->data == posVal){
            struct node* ptr = header;
            header = header->link;
            free(ptr);
        }else{
            struct node* ptr = header;
            while(ptr->link != NULL && ptr->link->data != posVal){
                ptr = ptr->link;
            }
            if(ptr->link == NULL){
                cout << "Value not Found" << endl;
            }else{
                struct node* ptr1 = ptr->link;
                ptr->link = ptr->link->link;
                free(ptr1);
            }
        }
    }
}

void print(){
    for(struct node* ptr = header; ptr != NULL; ptr = ptr->link){
        cout << ptr->data << " ";
    }
    cout << endl;
}

void Search(int val){
    struct node* ptr = header;
    int pos = 1;
    while(ptr != NULL){
        if(ptr->data == val){
            cout << "Value " << val << "found at pos " << pos << endl;
            return;
        }
        ptr = ptr->link;
        pos++;
    }
    cout << "Value " << val << " not found" << endl;
}

void last_node(){
    if (header == NULL) {
        cout << "List is empty\n";
        return;
    }
    struct node* ptr = header;
    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    cout << "Last node value: " << ptr->data << endl;
}

void prevOf_last_node(){
    if (header == NULL) {
        cout << "List is empty\n";
        return;
    }
    if (header->link == NULL) {
        cout << "Only one node exists in list\n";
        return;
    }
    struct node* ptr = header;
    while(ptr->link->link != NULL){
        ptr = ptr->link;
    }
    cout << "Prev Last node value: " << ptr->data << endl;
}
int main(){

}
