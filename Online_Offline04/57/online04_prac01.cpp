#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node *link;
};

struct node *header = NULL;

struct node *create_node(int value) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  if (new_node == NULL) {
    cout << "Memory allocation failed";
    exit(1);
  }
  new_node->data = value;
  new_node->link = NULL;
  return new_node;
};

void insert_first(int value) {
  struct node *newNode = create_node(value);
  if (header == NULL) {
    header = newNode;
    return;
  }
  newNode->link = header;
  header = newNode;
}

void insert_last(int value) {
  struct node *newNode = create_node(value);
  if (header == NULL) {
    header = newNode;
    return;
  }
  struct node *ptr = header;
  while (ptr->link != NULL) {
    ptr = ptr->link;
  }
  ptr->link = newNode;
}

void insert_anywhere(int pos, int value, bool isPos) {
  if (isPos == true) {
    if (pos == 1) {
      insert_first(value);
      return;
    }
    struct node *newNode = create_node(value);
    struct node *ptr = header;

    for (int i = 1; i < pos - 1 && ptr->link != NULL; i++) {
      ptr = ptr->link;
    }

    if (ptr == NULL) {
      cout << "Invalid Position." << endl;
    } else {
      newNode->link = ptr->link;
      ptr->link = newNode;
    }
  } else {
    struct node *newNode = create_node(value);
    if (header == NULL && newNode->data < header->data) {
      newNode->link = header;
      header = newNode;
    } else {
      struct node *ptr = header;
      while (ptr->link != NULL && newNode->data < ptr->link->data) {
        ptr = ptr->link;
      }

      newNode->link = ptr->link;
      ptr->link = newNode;
    }
  }
}

void delete_first() {
  if (header == NULL)
    cout << "List Empty " << endl;
  struct node *ptr = header;
  header = header->link;
  free(ptr);
}

void delete_last() {
  if (header == NULL)
    cout << "List Empty " << endl;
  if (header->link == NULL) {
    free(header);
    header = NULL;
    return;
  }
  struct node *ptr = header;
  struct node *ptr1 = NULL;
  while (ptr->link != NULL) {
    ptr1 = ptr;
    ptr = ptr->link;
  }
  ptr1->link = NULL;
  free(ptr);
}

void delete_anywhere(int posOrValue, bool isPos) {
  if (header == NULL)
    cout << "List Empty " << endl;
  if (isPos == true) {
    if (posOrValue == 1) {
      delete_first();
      return;
    }
    struct node *ptr = header;
    for (int i = 1; ptr->link != NULL && i < posOrValue - 1; i++) {
      ptr = ptr->link;
    }
    if (ptr->link == NULL) {
      cout << "Invalid Position " << endl;
    } else {
      struct node *ptr1 = ptr->link;
      ptr->link = ptr1->link;
      free(ptr1);
    }
  } else {
    if (header->data == posOrValue) {
      struct node *ptr = header;
      header = header->link;
      free(ptr);
    }
    struct node *ptr = header;
    while (ptr->link != NULL && ptr->link->data != posOrValue) {
      ptr = ptr->link;
    }

    if (ptr->link == NULL)
      cout << "Value not found. " << endl;
    else {
      struct node *ptr1 = ptr->link;
      ptr->link = ptr1->link;
      free(ptr1);
    }
  }
}

void print() {
  for (struct node *ptr = header; ptr->link != NULL; ptr = ptr->link) {
    cout << ptr->data << " ";
  }
}

void Search(int value) {
  int pos = 1;
  for (struct node *ptr = header; ptr != NULL; ptr = ptr->link) {
    if (ptr->data == value) {
      cout << value << " found at position " << pos << endl;
    }
    pos++;
  }
  cout << "Value Not Found. " << endl;
}

void last_node() {
  struct node *ptr = header;
  while (ptr->link != NULL) {
    ptr = ptr->link;
  }
  cout << "Last node value: " << ptr->data << endl;
}

void previous_of_last_node() {
  struct node *ptr = header;
  while (ptr->link->link != NULL) {
    ptr = ptr->link;
  }
  cout << "Previous node of Last node value: " << ptr->data << endl;
}

int list_size() {
  int count = 0;
  struct node *ptr = header;
  while (ptr != NULL) {
    ptr = ptr->link;
    count++;
  }
  return count;
}

void reversePrint(struct node *ptr = header) {
  if (ptr == NULL)
    return;
  reversePrint(ptr->link);
  cout << ptr->data << " ";
}

int main() {
  insert_first(10);
  insert_last(30);
  insert_last(40);
  insert_last(50);
  insert_last(60);
  insert_anywhere(2, 20, true);
  insert_anywhere(0, 25, false);
  cout << "Current List: ";
  print();
  Search(25);
  last_node();
  previous_of_last_node();
  cout << "Size of linked list: " << list_size() << endl;
  cout << "Printing in reverse : ";
  reversePrint();
  cout << endl;
  delete_first();
  cout << "After delete_first: ";
  print();
  delete_last();
  cout << "After delete_last: ";
  print();
  delete_anywhere(4, true);
  cout << "After delete_anywhere by position (pos 4): ";
  print();
  delete_anywhere(25, false);
  cout << "After delete_anywhere by value (val 25): ";
  print();

  return 0;
}
