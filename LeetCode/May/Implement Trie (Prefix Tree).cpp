/*Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.*/
class Trie 
{
    struct TrieNode
    {
        char ch; // not needed but okay
        int count;  // prefix count being used by other strings
        int endhere; // How many words end on this node
        TrieNode *child[26]; // 26 child for a to z
    };
    
    TrieNode *root;
    
    TrieNode *newNode(int index)
    {
        TrieNode *newnode = new TrieNode;
        newnode->ch = 'a' + index;
        newnode->count = newnode->endhere = 0;
        
        for(int i=0;i<26;++i)
            newnode->child[i] = NULL;
        
        return newnode;
    }
    
    public:
            /** Initialize your data structure here. */
            Trie() 
            {            
                ios_base::sync_with_stdio(false);
                cin.tie(NULL);
                root = newNode('/' - 'a');
            }

            /** Inserts a word into the trie. */
            void insert(string word) 
            {
                TrieNode *curr = root;
                int letter = 0;
                
                for(int i=0; i<word.size(); i++)
                {
                    letter = word[i] - 'a';
                    
                    if(curr->child[letter] == NULL)
                        curr->child[letter] = newNode(letter);
                    
                    curr->child[letter]->count++;
                    curr = curr->child[letter];
                }
                curr->endhere++;
            }

            /** Returns if the word is in the trie. */
            bool search(string word) 
            {
                TrieNode *curr = root;
                int letter = 0;
                
                for(int i=0; i < word.size(); i++)
                {
                    letter = word[i] - 'a';
                    
                    if(curr->child[letter] == NULL)
                        return false;
                    curr = curr->child[letter];
                }
                
               return (curr->endhere > 0);
            }

            /** Returns if there is any word in the trie that starts with the given prefix. */
            bool startsWith(string prefix) 
            {    
                TrieNode *curr = root;
                int letter = 0;
                for(int i = 0; i < prefix.size(); i++)
                {
                    letter = prefix[i] - 'a';
                    
                    if(curr->child[letter] == NULL)
                        return false;
                    
                    curr = curr->child[letter];
                }
                return (curr->count > 0);
            }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */