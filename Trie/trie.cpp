#include <iostream>

struct TrieNode
{
    bool isWordEnd;
    struct TrieNode *childern[26];
};

struct TrieNode *getNode()
{
    struct TrieNode *temp = new TrieNode;
    temp->isWordEnd = false;
    for (int i = 0; i < 26; i++)
    {
        temp->childern[i] = NULL;
    }

    return temp;
}

void insert(struct TrieNode *root, std::string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (pCrawl->childern[index] == NULL)
        {
            pCrawl->childern[index] = getNode();
        }
        pCrawl = pCrawl->childern[index];
    }
    pCrawl->isWordEnd = true;
}

bool search(struct TrieNode *root, std::string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (pCrawl->childern[index] == NULL)
        {
            return false;
        }
        pCrawl = pCrawl->childern[index];
    }
    return true;
}

int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    std::string keys[] = {"the", "a", "there",
                          "answer", "any", "by",
                          "bye", "their"};
    int n = sizeof(keys) / sizeof(keys[0]);

    struct TrieNode *root = getNode();

    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    // Search for different keys
    search(root, "the") ? std::cout << "Yes\n" : std::cout << "No\n";
    search(root, "these") ? std::cout << "Yes\n" : std::cout << "No\n";
    return 0;
}