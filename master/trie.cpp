#include <bits/stdc++.h>
using namespace std;

#define hashmap unordered_map<char, node *>

class node
{
public:
    char data;
    hashmap h;
    bool isTerminal;
    node(char c)
    {
        data = c;
        isTerminal = false;
    }
};

class trie
{
    node *root;

public:
    trie()
    {
        root = new node('\0');
    }
    void addWord(char *word)
    {
        node *temp = root;
        for (int i = 0; word[i] != '\0'; i++)
        {
            char ch = word[i];
            if (temp->h.count(ch) == 0)
            {
                node *child = new node(ch);
                temp->h[ch] = child;
                temp = child;
            }
            else
                temp = temp->h[ch];
        }
        temp->isTerminal = true;
    }
    bool search(char *word)
    {
        node *temp = root;
        for (int i = 0; word[i] != '\0'; i++)
        {
            char ch = word[i];
            if (temp->h.count(ch) == 0)
                return false;
            else
                temp = temp->h[ch];
        }
        return temp->isTerminal;
    }
};

int main()
{

    char word[10][100] = {"ankit", "mittal"};
    trie t;
    t.addWord(word[0]);
    t.addWord(word[1]);
    cout << t.search(word[0]);
}