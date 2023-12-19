class Trie
{
public:
    static int CHAR_TO_INDEX(char c){
        return (int)c - (int)'a';
    }
    static const int ALPHABET_SIZE= 26;
    struct TrieNode{
        struct TrieNode* children[ALPHABET_SIZE];
        bool isLastWord;
    };

    struct TrieNode* getNode(){
        TrieNode* newNode = new TrieNode;
        newNode->isLastWord = false;

        for (int i=0; i<ALPHABET_SIZE; i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    TrieNode* root;

    Trie(){
        root = getNode();
    }

    
    void insert(string word) {
        struct TrieNode* TCrawl = root;
        for (int level=0; level < word.length() ; level++){
            int index = word[level] - 'a';
            if (!TCrawl->children[index]){
                TCrawl->children[index] = getNode();
            }
            TCrawl = TCrawl->children[index];
        }
        TCrawl->isLastWord = true;
    }



    vector<string> autoCompleteCuy(string prefix){
        struct TrieNode* PCrawl= root;
           vector<string> current;
        for (int i=0; i<prefix.size(); i++){
            int index = prefix[i] - 'a';
            if (!PCrawl->children[index]){
                return current;
            }
            PCrawl = PCrawl->children[index];
        }
     
        // if (PCrawl->isLastWord){
        //     current.push_back(prefix);
        // }

        dfs(PCrawl ,prefix, current);

        // current autocomplete dg prefix=prefix sudah keisi
        return current;

    }

    //  coba coba cari word dari children a-z kalo ada
    void dfs(TrieNode *curr, string & word, vector<string> & result) {
        if (result.size() == 3)
            return;
        if (curr->isLastWord)
            result.push_back(word);

        for (char c = 'a'; c <= 'z'; c++)
            // coba coba children a-z kalo ada
            if (curr->children[c - 'a']) {
                word += c;
                dfs(curr->children[c - 'a'], word, result);
                word.pop_back();
            }
    }
    
};

class Solution {
public:
    vector<vector<string>> res;
    

    
    

    

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie = Trie();
        for(string& p : products){
            trie.insert(p);
        }

        string prefix;
        for (int i=0; i<searchWord.length(); i++){
            prefix= prefix+ searchWord[i];
            res.push_back(trie.autoCompleteCuy(prefix));
        }
        return res;
    }
};

/*
time complexity: 
- searching prefix / fungsi autoCompleteCuy: O(n)
- insert : O(m)
m = total character dari setiap word di products. 
n = length dari prefix


*/