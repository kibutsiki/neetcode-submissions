/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> random_storage;
        Node* cur = head;

        while(cur){
            random_storage[cur] = new Node(cur->val);
            cur = cur->next;
        }


        //handles the next and random
        cur = head;
        while(cur){
            Node* copy = random_storage[cur];
            copy->next = random_storage[cur->next];
            copy->random = random_storage[cur->random];
            cur = cur->next;
        }
        
        return random_storage[head];
    }
};
