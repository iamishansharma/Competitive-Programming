class MyHashSet 
{
    private:
            vector<bool> hashTable;
    public:
            /** Initialize your data structure here. */
            MyHashSet() 
            {
                hashTable.resize(1000001);
            }

            void add(int key) 
            {
                hashTable[key] = true;
            }

            void remove(int key) 
            {
                hashTable[key] = false;
            }

            /** Returns true if this set contains the specified element */
            bool contains(int key) 
            {
                return hashTable[key];
            }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */