#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    struct node* link;
};

struct node* header = NULL;

// --- BASIC HELPERS ---
struct node* create_node(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }
    new_node->data = value;
    new_node->link = NULL;
    return new_node;
}

void insert_Last(int value) {
    struct node* new_node = create_node(value);
    if (header == NULL) {
        header = new_node;
        return;
    }
    struct node* ptr = header;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = new_node;
}

void print() {
    for (struct node* ptr = header; ptr != NULL; ptr = ptr->link) {
        cout << ptr->data << " -> ";
    }
    cout << "NULL" << endl;
}

// --- NEW LOGIC (60% HARDER) ---

/*
 * TASK 1: Remove Duplicates (Nested Pointer Traversal)
 * Uses 'curr' to lock onto a number, and 'runner' to hunt down and delete matches.
 */
void remove_duplicates() {
    struct node* curr = header;

    // Outer loop picks the target number
    while (curr != NULL && curr->link != NULL) {
        struct node* runner = curr;

        // Inner loop hunts for duplicates of curr->data
        while (runner->link != NULL) {
            if (runner->link->data == curr->data) {
                // Duplicate found! Unlink and free it.
                struct node* duplicate = runner->link;
                runner->link = duplicate->link; // Bridge over the duplicate
                free(duplicate);
                // CRITICAL: Notice we do NOT advance 'runner' here because
                // the new runner->link might ALSO be a duplicate!
            } else {
                // Only move runner forward if we didn't delete anything
                runner = runner->link;
            }
        }
        // Move to the next unique number to start checking again
        curr = curr->link;
    }
}

/*
 * TASK 2: In-Place Reversal
 * Physically flips the direction of every single pointer in the list.
 */
void reverse_sequence() {
    struct node* prev = NULL;
    struct node* current = header;
    struct node* next_node = NULL;

    while (current != NULL) {
        // 1. Save the next node so we don't lose the rest of the list
        next_node = current->link;

        // 2. REVERSE the arrow! Point it to the previous node
        current->link = prev;

        // 3. Shift 'prev' and 'current' one step forward for the next loop
        prev = current;
        current = next_node;
    }
    // 4. Update the global header to the new front (which is 'prev')
    header = prev;
}

// --- MAIN SIMULATION ---
int main() {
    cout << "--- The DNA Sequence Restorer ---" << endl;

    // 1. Load Corrupted DNA
    insert_Last(15);
    insert_Last(7);
    insert_Last(15);
    insert_Last(22);
    insert_Last(7);
    insert_Last(9);
    insert_Last(22);
    insert_Last(15);

    // 2. Print Initial State
    cout << "\nInitial Corrupted DNA: " << endl;
    print();

    // 3. Purify (Remove Duplicates)
    cout << "\n--- Running Purifier (Removing Duplicates) ---" << endl;
    remove_duplicates();

    // 4. Print Purified State
    cout << "Purified DNA: " << endl;
    print();

    // 5. Restore (In-Place Reversal)
    cout << "\n--- Running Restorer (Reversing Sequence) ---" << endl;
    reverse_sequence();

    // 6. Print Final Restored State
    cout << "Final Restored DNA: " << endl;
    print();

    return 0;
}
