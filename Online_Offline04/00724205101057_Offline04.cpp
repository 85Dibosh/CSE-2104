#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* link;
};

struct node* header = NULL;

struct node* create_node(int value){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL){
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }
    new_node->data = value;
    new_node->link = NULL;
    return new_node;
};

void insert_First(int value){
    struct node* new_node = create_node(value);
    if(header == NULL){
        header = new_node;
    }else{
        new_node->link = header;
        header = new_node;
    }
}

void insert_Last(int value){
    struct node* new_node = create_node(value);
    if(header == NULL){
        header = new_node;
        return;
    }
    struct node* ptr = header;
    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = new_node;
}

void insert_Anywhere(int pos, int value, bool isPos){
    if(isPos == true){
        if(pos == 1){
            insert_First(value);
            return;
        }
        struct node* new_node = create_node(value);
        struct node* ptr = header;

        for(int i = 1; i < pos - 1 && ptr->link != NULL; i++){
            ptr = ptr->link;
        }

        if(ptr == NULL){
            cout << "Invalid Postion." << endl;
            free(new_node);
        }else{
                new_node->link = ptr->link;
                ptr->link = new_node;
        }
    }else{
        struct node* new_node = create_node(value);
        if(header == NULL && new_node->data < header->data){
            new_node->link = header;
            header = new_node;
        }else{
            struct node* ptr = header;
            while(ptr->link != NULL && new_node->data > ptr->link->data){
                ptr = ptr->link;
            }
            new_node->link = ptr->link;
            ptr->link = new_node;
        }
    }
}

void delete_First(){
    if(header == NULL){
        cout << "List is already empty. \n";
        return;
    }else{
        struct node* ptr = header;
        header = header->link;
        free(ptr);
    }
}

void delete_Last(){
    if(header == NULL){
        cout << "List is already empty. \n";
        return;
    }
    if(header->link == NULL){
        free(header);
        header = NULL;
        return;
    }
    struct node* ptr = header;
    struct node* ptr1 = NULL;
    while(ptr->link != NULL){
        ptr1 = ptr;
        ptr = ptr->link;
    }
    ptr1->link = NULL;
    free(ptr);
}

void delete_Anywhere(int pos_Value, bool isPos){
    if (header == NULL) {
        cout << "List is empty. \n";
        return;
    }

    if(isPos == true)
    {
        if(pos_Value == 1){
            struct node* ptr = header;
            header = header->link;
            free(ptr);
            return;
        }
        struct node* ptr = header;
        for(int i = 1; i < pos_Value - 1 && ptr->link != NULL;i++){
            ptr = ptr->link;
        }
        if(ptr->link == NULL){
            cout << "Invalid Position" << endl;
        }else{
            struct node* ptr1 = ptr->link ;
            ptr->link = ptr1->link;
            free(ptr1);
        }
    }
    else
    {
        if(header->data == pos_Value){
            struct node* ptr = header;
            header = header->link;
            free(ptr);
            return;
        }
        struct node* ptr = header;
        while(ptr->link != NULL && ptr->link->data != pos_Value){
            ptr = ptr->link;
        }
        if(ptr->link == NULL){
            cout << " Value not found" << endl;
        }else{
            struct node* ptr1 = ptr->link ;
            ptr->link = ptr1->link;
            free(ptr1);
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
            cout << "Value " << val << " found at position " << pos << endl;
            return;
        }
        ptr = ptr->link;
        pos++;
     }
}

void last_node(){
    if (header == NULL) {
        cout << "List is empty\n";
        return;
    }
    struct node* ptr = header;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    cout << "Last node value: " << ptr->data << endl;
}

void previous_of_last_node(){
    if (header == NULL) {
        cout << "List is empty\n";
        return;
    }
    struct node* ptr = header;
    while (ptr->link->link != NULL) {
        ptr = ptr->link;
    }
    cout << "Previous of last node value: " << ptr->data << endl;
}

int list_size(){
    int count = 0;
    struct node* ptr = header;
    while (ptr != NULL) {
        count++;
        ptr = ptr->link;
    }
    return count;
}

void reversePrint(struct node* ptr = header){
    if(ptr == NULL) return;
    reversePrint(ptr->link);
    cout << ptr->data << " ";
}

int main() {
    insert_First(10);
    insert_Last(30);
    insert_Last(40);
    insert_Last(50);
    insert_Last(60);
    insert_Anywhere(2, 20, true);
    insert_Anywhere(0, 25, false);
    cout << "Current List: ";
    print();
    Search(25);
    last_node();
    previous_of_last_node();
    cout << "Size of linked list: " << list_size() << endl;
    cout<< "Printing in reverse : ";
    reversePrint();
    cout << endl;
    delete_First();
    cout << "After delete_first: ";
    print();
    delete_Last();
    cout << "After delete_last: ";
    print();
    delete_Anywhere(4, true);
    cout << "After delete_anywhere by position (pos 4): ";
    print();
    delete_Anywhere(25, false);
    cout << "After delete_anywhere by value (val 25): ";
    print();

    return 0;
}


