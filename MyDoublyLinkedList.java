/*
Description:
This program implements a Doubly Linked List (DLL) data structure in Java.
Each node of the list contains three parts:
1. Data (an integer)
2. Pointer to the previous node (prev)
3. Pointer to the next node (next)

The program demonstrates the following operations:
------------------------------------------------------
1. addAtHead(int item)     → Insert an element at the beginning of the list.
2. addAtTail(int item)     → Insert an element at the end of the list.
3. addByIndex(int item, int index, boolean dir)
                           → Insert an element before or after a given index.
                             (dir = true → after index, dir = false → before index)
4. deleteAtIndex(int index)→ Delete an element from a given position.
5. get(int index)          → Return the data of a node at a specific index.
6. displayForward()        → Display the list from head to tail.
7. displayBackward()       → Display the list from tail to head.
8. reverseList()           → Reverse the entire doubly linked list.
9. getSize()               → Return the number of elements in the list.

Objective:
To understand and implement insertion, deletion, traversal, and reversal operations
in a doubly linked list and verify the correctness of each operation
through function calls in the main method.
*/

class Node {
    int data;
    Node prev;
    Node next;

    Node(int data) {
        this.data = data;
        prev = null;
        next = null;
    }
}

class DoublyLinkedList {
    private Node head;
    private int size;

    DoublyLinkedList() {
        head = null;
        size = 0;
    }

    // Insert at the beginning
    void addAtHead(int item) {
        Node temp = new Node(item);
        if (head == null) {
            head = temp;
        } else {
            temp.next = head;
            head.prev = temp;
            head = temp;
        }
        size++;
    }

    // Insert at the end
    void addAtTail(int item) {
        if (head == null) {
            addAtHead(item);
            return;
        }
        Node ptr = head;
        while (ptr.next != null) {
            ptr = ptr.next;
        }
        Node temp = new Node(item);
        temp.prev = ptr;
        ptr.next = temp;
        size++;
    }

    // Delete a node by index
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            System.out.println("Index is out of bound of list.");
            return;
        }

        Node ptr = head;
        for (int i = 0; i < index; i++) {
            ptr = ptr.next;
        }

        // Case 1: delete head
        if (ptr == head) {
            head = head.next;
            if (head != null) head.prev = null;
            size--;
            return;
        }

        // Case 2: delete tail
        if (index == size - 1) {
            ptr.prev.next = null;
            size--;
            return;
        }

        // Case 3: delete middle node
        ptr.prev.next = ptr.next;
        ptr.next.prev = ptr.prev;
        ptr.prev = ptr.next = null;
        size--;
    }

    // Add a node before or after a given index
    void addByIndex(int item, int index, boolean dir) {
        if (index < 0 || index > size) {
            System.out.println("Index is out of bound of list.");
            return;
        }

        // dir = true → insert AFTER index
        // dir = false → insert BEFORE index
        if (dir) { // after
            if (index == size - 1) {
                addAtTail(item);
                return;
            }

            Node ptr = head;
            for (int i = 0; i < index; i++) ptr = ptr.next;

            Node temp = new Node(item);
            temp.prev = ptr;
            temp.next = ptr.next;
            if (ptr.next != null) ptr.next.prev = temp;
            ptr.next = temp;
            size++;
        } else { // before
            if (index == 0) {
                addAtHead(item);
                return;
            }

            Node ptr = head;
            for (int i = 0; i < index; i++) ptr = ptr.next;

            Node temp = new Node(item);
            temp.next = ptr;
            temp.prev = ptr.prev;
            ptr.prev.next = temp;
            ptr.prev = temp;
            size++;
        }
    }

    // Display list from head to tail
    void displayForward() {
        if (head == null) {
            System.out.println("List is empty..");
            return;
        }
        Node ptr = head;
        System.out.print("List-> ");
        while (ptr != null) {
            System.out.print(ptr.data + " -> ");
            ptr = ptr.next;
        }
        System.out.println("null");
    }

    // Display list from tail to head
    void displayBackward() {
        if (head == null) {
            System.out.println("List is empty..");
            return;
        }
        Node ptr = head;
        while (ptr.next != null) ptr = ptr.next;

        System.out.print("List-> ");
        while (ptr != null) {
            System.out.print(ptr.data + " -> ");
            ptr = ptr.prev;
        }
        System.out.println("null");
    }

    // Get value at a specific index
    int get(int index) {
        if (index < 0 || index >= size) {
            System.out.println("Index is out of bound of list.");
            return -1;
        }
        Node ptr = head;
        for (int i = 0; i < index; i++) ptr = ptr.next;
        return ptr.data;
    }

    // Return current list size
    int getSize() {
        return size;
    }

    // Reverse the entire list
    void reverseList() {
        Node ptr = head;
        Node temp = null;

        while (ptr != null) {
            // Swap prev and next
            temp = ptr.prev;
            ptr.prev = ptr.next;
            ptr.next = temp;
            ptr = ptr.prev; // move backward since links are swapped
        }

        // After reversal, temp will point to the old head’s previous node
        if (temp != null) {
            head = temp.prev;
        }
    }
}

public class MyDoublyLinkedList {
    public static void main(String[] args) {
        DoublyLinkedList dl = new DoublyLinkedList();

        System.out.println("=== Testing addAtHead ===");
        dl.addAtHead(30);
        dl.addAtHead(20);
        dl.addAtHead(10);
        dl.displayForward();
        dl.displayBackward();

        System.out.println("\n=== Testing addAtTail ===");
        dl.addAtTail(40);
        dl.addAtTail(50);
        dl.displayForward();
        dl.displayBackward();

        System.out.println("\n=== Testing addByIndex ===");
        dl.addByIndex(25, 1, true);  // after index 1 (after 20)
        dl.addByIndex(5, 0, false);  // before index 0 (before 10)
        dl.displayForward();

        System.out.println("\n=== Testing get() ===");
        for (int i = 0; i < dl.getSize(); i++) {
            System.out.println("Index " + i + ": " + dl.get(i));
        }

        System.out.println("\n=== Testing deleteAtIndex ===");
        dl.deleteAtIndex(0); // delete head (5)
        dl.deleteAtIndex(dl.getSize() - 1); // delete tail (50)
        dl.deleteAtIndex(2); // delete middle (25)
        dl.displayForward();

        System.out.println("\n=== Final Size of List: " + dl.getSize() + " ===");
        dl.displayBackward();

        System.out.println("\n=== Testing reverseList ===");
        dl.reverseList();
        dl.displayForward();
    }
}
