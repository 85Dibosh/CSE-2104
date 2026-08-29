#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data; // Represents the weight of the package
    struct node* link;
};

struct node* header = NULL;

// --- EXISTING HELPER FUNCTIONS ---
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

void insert_First(int value) {
    struct node* new_node = create_node(value);
    if (header == NULL) {
        header = new_node;
    } else {
        new_node->link = header;
        header = new_node;
    }
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

void insert_Anywhere(int pos, int value, bool isPos) {
    if (isPos == true) {
        if (pos == 1) {
            insert_First(value);
            return;
        }
        struct node* new_node = create_node(value);
        struct node* ptr = header;

        for (int i = 1; i < pos - 1 && ptr->link != NULL; i++) {
            ptr = ptr->link;
        }

        if (ptr == NULL) {
            cout << "Invalid Position." << endl;
            free(new_node);
        } else {
            new_node->link = ptr->link;
            ptr->link = new_node;
        }
    } else {
        struct node* new_node = create_node(value);
        if (header == NULL || new_node->data < header->data) {
            new_node->link = header;
            header = new_node;
        } else {
            struct node* ptr = header;
            while (ptr->link != NULL && new_node->data > ptr->link->data) {
                ptr = ptr->link;
            }
            new_node->link = ptr->link;
            ptr->link = new_node;
        }
    }
}

int list_size() {
    int count = 0;
    struct node* ptr = header;
    while (ptr != NULL) {
        count++;
        ptr = ptr->link;
    }
    return count;
}

void print() {
    for (struct node* ptr = header; ptr != NULL; ptr = ptr->link) {
        cout << ptr->data << " ";
    }
    cout << endl;
}

void reversePrint(struct node* ptr = header) {
    if (ptr == NULL) return;
    reversePrint(ptr->link);
    cout << ptr->data << " ";
}


// --- NEW LOGIC (30% HARDER) ---

/*
 * TASK 1: Purge Lightweight Packages
 * Safely removes ALL nodes where data < threshold.
 * Difficulty: Must handle if the head itself needs deleting,
 * and must not lose the rest of the list when skipping multiple nodes.
 */
void purge_lightweight(int threshold) {
    // Edge Case 1: What if the head itself (or first several nodes) are below threshold?
    while (header != NULL && header->data < threshold) {
        struct node* temp = header;
        header = header->link;
        free(temp);
    }

    // If the whole list was deleted, stop here
    if (header == NULL) return;

    // Traverse the rest of the list
    struct node* ptr = header;
    while (ptr->link != NULL) {
        if (ptr->link->data < threshold) {
            // Node needs to be deleted
            struct node* temp = ptr->link;
            ptr->link = temp->link; // Reroute around the defective node
            free(temp);
            // Notice we DO NOT move `ptr` forward here!
            // The new `ptr->link` might ALSO be defective. We check it on the next loop.
        } else {
            // Safe to move forward
            ptr = ptr->link;
        }
    }
}

/*
 * TASK 2: Insert Separator
 * Uses list_size() to calculate the midpoint, then uses the existing
 * position-based insert_Anywhere() to drop the 0 in the middle.
 */
void insert_separator() {
    int size = list_size();
    if (size == 0) {
        insert_First(0);
        return;
    }
    // Calculate middle position (1-based index)
    int mid_pos = (size / 2) + 1;

    // Use the existing function! True indicates we are using position, not value.
    insert_Anywhere(mid_pos, 0, true);
}

// --- MAIN SIMULATION ---
int main() {
    cout << "--- The Smart Conveyor Belt Initialization ---" << endl;

    // 1. Initial Load
    insert_Last(15);
    insert_Last(8);
    insert_Last(42);
    insert_Last(5);
    insert_Last(19);
    insert_Last(3);
    insert_Last(50);

    // 2. VIP Package Sorted Insertion (Weight 25)
    // false means sorted insertion by value
    insert_Anywhere(0, 25, false);

    // 3. Print Initial State
    cout << "Loaded Belt (Before QC): ";
    print();

    // 4. Run Quality Control (Purge weights < 10)
    cout << "\n--- Running QC Scanner (Threshold: 10kg) ---" << endl;
    purge_lightweight(10);

    // 5. Print Post-Purge
    cout << "Approved Belt (After QC): ";
    print();

    // 6. Insert Checkpoint Separator (0)
    cout << "\n--- Adding Checkpoint Separator ---" << endl;
    insert_separator();

    // 7. Print Post-Separator
    cout << "Final Belt Configuration: ";
    print();

    // 8. Shipping Manifest
    cout << "\n--- Reverse Shipping Manifest ---" << endl;
    cout << "Manifest: ";
    reversePrint();
    cout << endl;

    return 0;
}
