/*

Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();

*/

class RandomizedSet 
{  
    private:
            unordered_map<int, int> hash;
            vector<int> nums;
    
    public:
            /** Initialize your data structure here. */
            RandomizedSet() 
            {
                srand(time(nullptr));
                hash.clear();
                nums.clear();
            }

            /** Inserts a value to the set. Returns true if the set did not
             *  already contain the specified element.
             */
            bool insert(int val) 
            {
                if(hash.count(val)) 
                    return false;
                
                hash[val] = nums.size();
                nums.push_back(val);
                return true;
            }

            /** Removes a value from the set. Returns true if the set contained
             *  the specified element.
             */
            bool remove(int val) 
            {
                if(!hash.count(val)) 
                    return false;
                
                int idx = hash[val];
                int last = nums.back();
                // move the last element to the position of the removed element
                // we only need to do so if the element to be removed is not the last element.
                if(last != val)
                {
                    nums[idx] = last;
                    hash[last] = idx;
                }
                
                hash.erase(val);
                nums.pop_back();
                return true;
            }

            /** Get a random element from the set. */
            int getRandom() 
            {
                int k = rand() % nums.size();
                return nums[k];
            }
};