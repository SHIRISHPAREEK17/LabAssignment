/* In LRU page replacement using a doubly linked list, when the cache is full and a repeated page is accessed, the node corresponding to that page is removed from its current position and moved to the front.
This process involves 6 pointer changes — 2 during deletion and 4 during insertion. */

import java.util.HashMap;
class LRUCache {

    private class Node {
        int val;
        Node prev, next;
        Node(int val){ 
            this.val = val; 
        }
    }

    private Node head = new Node(-1);
    private Node tail = new Node(-1);
    private int cap;
    int pageFaults = 0;
    private HashMap<Integer, Node> m = new HashMap<>();

    public LRUCache(int capacity) {
        this.cap = capacity;
        head.next = tail;
        tail.prev = head;
    }

    private void addNode(Node node) {
        node.next = head.next;
        node.prev = head;
        head.next.prev = node;
        head.next = node;
    }

    private void deleteNode(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    public void accessPage(int key) {
        // Page already present move it to front
        if (m.containsKey(key)) {
            Node node = m.get(key);
            deleteNode(node);
            addNode(node);
            return;
        }

        // Page not present page fault
        pageFaults++;

        if (m.size() == cap) {
            // Remove least recently used page (before tail)
            Node lru = tail.prev;
            deleteNode(lru);
            m.remove(lru.val);
        }

        Node newNode = new Node(key);
        addNode(newNode);
        m.put(key, newNode);
    }
}
