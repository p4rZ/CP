#include <bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26;

struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];
	bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;
	pNode->isEndOfWord = false;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

void insert(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}
	pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;
		pCrawl = pCrawl->children[index];
	}

	return (pCrawl->isEndOfWord);
}

bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

TrieNode* remove(TrieNode* root, string key, int depth = 0)
{
    if (!root)
        return NULL;
    if (depth == key.size()) 
    {
        if (root->isEndOfWord)
            root->isEndOfWord = false;
        if (isEmpty(root)) 
        {
            delete (root);
            root = NULL;
        }
 
        return root;
    }

    int index = key[depth] - 'a';
    root->children[index] =
          remove(root->children[index], key, depth + 1);
 
    if (isEmpty(root) && root->isEndOfWord == false) 
    {
        delete (root);
        root = NULL;
    }
 
    return root;
}

bool isLeafNode(struct TrieNode* root)
{
    return root->isEndOfWord != false;
}

void display(struct TrieNode* root, char str[], int level)
{
    if (isLeafNode(root)) 
    {
        str[level] = '\0';
        cout << str << endl;
    }
  
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++) 
    {
        if (root->children[i]) 
        {
            str[level] = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
}

int main()
{

	string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their", "hero", "heroplane" };
	int n = sizeof(keys)/sizeof(keys[0]);
	struct TrieNode *root = getNode();

	for (int i = 0; i < n; i++)
		insert(root, keys[i]);

	search(root, "the")? cout << "Yes\n" : cout << "No\n";
	search(root, "these")? cout << "Yes\n" : cout << "No\n";

    remove(root, "heroplane");
    search(root, "hero") ? cout << "Yes\n" : cout << "No\n";

    int level = 0;
    char str[20];
    cout << "Content of Trie: " << endl;
    display(root, str, level);

	return 0;
}
