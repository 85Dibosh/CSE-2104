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
    if (new_node == NULL) exit(1);
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
    while (ptr->link != NULL) ptr = ptr->link;
    ptr->link = new_node;
}

void print() {
    for (struct node* ptr = header; ptr != NULL; ptr = ptr->link) {
        cout << ptr->data << " -> ";
    }
    cout << "NULL" << endl;
}


// ==========================================
// --- NEW LOGIC (90% HARDER) ---
// ==========================================

/*
 * TASK 1: Delete K-th from End (Single Pass)
 * Creates a "gap" of K nodes between a fast and slow pointer.
 * When 'fast' hits the end, 'slow' is exactly at the target.
 */
void intercept_threat(int k) {
    if (header == NULL) return;

    struct node* fast = header;
    struct node* slow = header;

    // 1. Move the fast pointer 'k' steps ahead
    for (int i = 0; i < k; i++) {
        if (fast == NULL) {
            cout << "Error: List is shorter than " << k << endl;
            return;
        }
        fast = fast->link;
    }

    // 2. Edge Case: If fast hit NULL exactly after k steps,
    // it means the k-th node from the end is the very first node (header)
    if (fast == NULL) {
        struct node* temp = header;
        header = header->link;
        free(temp);
        return;
    }

    // 3. Move both at the same speed.
    // We check fast->link != NULL so 'slow' stops RIGHT BEFORE the target
    while (fast->link != NULL) {
        fast = fast->link;
        slow = slow->link;
    }

    // 4. Slow is now sitting right before the node we want to delete. Reroute and free.
    struct node* target = slow->link;
    slow->link = target->link;
    free(target);
}

/*
 * TASK 2: Pairwise Link Swap
 * Physically rewires connections: A->B->C->D becomes B->A->D->C
 */
void encrypt_route() {
    // A temporary "dummy" node makes handling the new header much easier
    struct node* dummy = create_node(0);
    dummy->link = header;

    struct node* prev = dummy;
    struct node* curr = header;

    // We need at least two nodes left to swap them
    while (curr != NULL && curr->link != NULL) {
        struct node* next_node = curr->link;      // Node to swap with
        struct node* next_next = next_node->link; // Save the rest of the list

        // --- THE SWAP (Rewiring the arrows) ---
        prev->link = next_node;     // Arrow 1: Point previous to the 2nd node
        next_node->link = curr;     // Arrow 2: Point 2nd node back to 1st node
        curr->link = next_next;     // Arrow 3: Point 1st node forward to the rest of the list

        // --- ADVANCE ---
        prev = curr;                // Move prev to the end of the swapped pair
        curr = next_next;           // Move curr to the start of the next pair
    }

    // Update the global header to point past our dummy node, then delete dummy
    header = dummy->link;
    free(dummy);
}

/*
 * TASK 3: Floyd's Cycle Detection (Tortoise and Hare)
 * One pointer moves 1 step, the other moves 2 steps.
 * If there is an infinite loop, the fast one will eventually "lap" the slow one.
 */
bool detect_routing_loop() {
    struct node* slow = header;
    struct node* fast = header;

    while (fast != NULL && fast->link != NULL) {
        slow = slow->link;             // Tortoise moves 1 step
        fast = fast->link->link;       // Hare moves 2 steps

        if (slow == fast) {
            return true; // They collided! An infinite loop exists.
        }
    }
    return false; // Fast reached NULL safely. No loops.
}


// --- MAIN SIMULATION ---
int main() {
    cout << "--- The Compromised Server Network ---" << endl;

    insert_Last(10);
    insert_Last(20);
    insert_Last(30);
    insert_Last(40);
    insert_Last(50);
    insert_Last(60);

    cout << "\n1. Initial Network Route:" << endl;
    print();

    cout << "\n2. Encrypting Route (Pairwise Swap)..." << endl;
    encrypt_route();
    print(); // Should be: 20 -> 10 -> 40 -> 30 -> 60 -> 50

    cout << "\n3. Intercepting Payload (Deleting 2nd node from end)..." << endl;
    // We want to delete '60' without measuring the list size.
    intercept_threat(2);
    print(); // Should be: 20 -> 10 -> 40 -> 30 -> 50

    cout << "\n4. Running Route Diagnostics..." << endl;
    if (detect_routing_loop()) cout << "[ALERT] Routing Loop Detected!" << endl;
    else cout << "[SAFE] Route is clear of loops." << endl;

    // --- ARTIFICIALLY CREATE A MALICIOUS LOOP FOR TESTING ---
    cout << "\n[!] Hacker initiates a routing loop..." << endl;
    struct node* tail = header;
    while(tail->link != NULL) tail = tail->link;
    // Connect the tail back to the header!
    tail->link = header;

    cout << "5. Running Route Diagnostics Again..." << endl;
    if (detect_routing_loop()) cout << "[ALERT] Infinite Routing Loop Detected!" << endl;
    else cout << "[SAFE] Route is clear of loops." << endl;
    // NOTE: If we ran print() now, the terminal would freeze in an infinite loop!

    return 0;
}
