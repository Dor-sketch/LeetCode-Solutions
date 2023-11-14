class LRUCache {

public:
    LRUCache(int capacity) : capacity_(capacity), MRU_(nullptr), LRU_(nullptr) {
    }

    int get(int key) {
        auto it = hashTable_.find(key);
        if (it == hashTable_.end()) {
            return -1; // Key not found
        }
        // Move the node to MRU position
        moveToMRU(it->second.get());
        return it->second->value;
    }

    void put(int key, int value) {
        if (hashTable_.find(key) != hashTable_.end()) {
            // Update existing node and move to MRU position
            hashTable_[key]->value = value;
            moveToMRU(hashTable_[key].get());
            return;
        }

        if (hashTable_.size() >= capacity_) {
            removeLRU();
        }

        // Insert new node at MRU position
        auto node_ptr = std::make_unique<DoubleLinkedListNode>();
        node_ptr->key = key;
        node_ptr->value = value;
        insertAtMRU(std::move(node_ptr));
    }


private:
    struct DoubleLinkedListNode {
        int key = 0;
        int value = 0;
        DoubleLinkedListNode* next = nullptr;
        DoubleLinkedListNode* back = nullptr; // raw pointer to avoid ownership cycle
    };

    int capacity_;
    std::unordered_map<int, std::unique_ptr<DoubleLinkedListNode>> hashTable_;
    DoubleLinkedListNode* LRU_;
    DoubleLinkedListNode* MRU_;

    void moveToMRU(DoubleLinkedListNode* node) {
        if (MRU_ == node) return; // Node is already MRU

        // If node is LRU and there is more than one node in the cache
        if (node == LRU_ && node->next) {
            LRU_ = node->next;
            LRU_->back = nullptr;
        }

        // Unlink the node from its current position
        if (node->back) node->back->next = node->next;
        if (node->next) node->next->back = node->back;

        // Place the node at the MRU position
        node->next = nullptr;
        node->back = MRU_;
        if (MRU_) MRU_->next = node;
        MRU_ = node;

        // If the cache was empty, update LRU_
        if (!LRU_) LRU_ = node;
    }

    void removeLRU() {
        if (!LRU_) return; // No LRU to remove

        auto lru_key = LRU_->key;
        DoubleLinkedListNode* nextNode = LRU_->next;

        // Update LRU_
        if (nextNode) {
            nextNode->back = nullptr;
            LRU_ = nextNode;
        } else {
            // If the LRU is the only node in the cache
            LRU_ = nullptr;
            MRU_ = nullptr;
        }

        hashTable_.erase(lru_key); // Remove the node from the hash table
    }

    void insertAtMRU(std::unique_ptr<DoubleLinkedListNode> new_node) {
        new_node->back = MRU_;
        if (MRU_) {
            MRU_->next = new_node.get();
        }

        // If the cache was empty, update LRU_
        if (!LRU_) {
            LRU_ = new_node.get();
        }

        MRU_ = new_node.get();
        hashTable_[new_node->key] = std::move(new_node); // Add the new node to the hash table
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */