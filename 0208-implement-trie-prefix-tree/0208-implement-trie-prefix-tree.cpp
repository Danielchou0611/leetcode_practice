#include <string>
#include <iostream>
#include <vector>
using namespace std;
class TrieNode
{
public:
    vector<TrieNode *> child;                      // 假設處理26個英文字母(小寫):child[0]對應'a', child[1]對應'b', 依此類推
    bool end;                                      // end為1的時候代表走到單字結尾了
    TrieNode() : child(26, nullptr), end(false) {} // 用來初始化成員變數的建構子,建立一個長度為26的vector並將每個位置初始為空指標,end是將此節點設為非結尾
    // child(26, nullptr)是c++初始化成員的語法,也可寫成TrieNode(){child = vector<TrieNode*>(26, nullptr)}
};
class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode(); // 建構子初始化
    }

    void insert(string word)
    {
        TrieNode *tmp = root;
        for (char c : word)
        {
            int index = c - 'a';              // only lowercase
            if (tmp->child[index] == nullptr) // 字母還沒被收錄進來
                tmp->child[index] = new TrieNode;
            tmp = tmp->child[index];
        }
        tmp->end = true;
    }

    bool search(string word)
    {
        TrieNode *tmp = root;
        for (char c : word)
        {
            int index = c - 'a';
            if (tmp->child[index] == nullptr)
                return false;
            tmp = tmp->child[index];
        }
        return tmp->end; // 要字母都符合且剛好停在最後一個字母,否則就只是前綴
    }

    bool startsWith(string prefix) // 如果插入的單字具有prefix(前綴)回傳true, 反之false (這個主要是查詢是否有前綴,ex:字典裡有apple,檢查app是前綴,apz不是)
    {
        TrieNode *tmp = root;
        for (char c : prefix)
        {
            int index = c - 'a';
            if (tmp->child[index] == nullptr)
                return false;
            tmp = tmp->child[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */