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
        random_storage[nullptr] = nullptr;



        for(Node* cur = head; cur != nullptr; cur = cur->next)
            random_storage[cur] = new Node(cur->val);


        //handles the next and random
        for (Node* cur = head; cur != nullptr; cur = cur->next) {
            random_storage[cur]->next = random_storage[cur->next];
            random_storage[cur]->random = random_storage[cur->random];
        }
        
        return random_storage[head];
    }
};
