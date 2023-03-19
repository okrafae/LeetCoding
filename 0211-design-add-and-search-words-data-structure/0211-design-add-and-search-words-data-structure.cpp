class WordDictionary {
public:
            vector<string> v;
    WordDictionary() {
    }
    
    void addWord(string word) {
        v.push_back(word);
    }
    
    bool search(string word) {
        int n = v.size();
        int keySize = word.size();
        for( int i = 0; i < n; i++)
        {
            int len = v[i].size();
            if( len != keySize ) continue;
            int j = 0;
            for( j = 0; j < len; j++)
            {
                if( word[j] == '.' ) continue;
                if( word[j] != v[i][j]) break;
            }
            if( j == len ) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */