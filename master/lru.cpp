/*
 An LRU Cache should support fast lookup. Apparently, in order to achieve fast lookup, we need to use Hashtable or HashMap.

Also, an LRU Cache requires that insert and delete operations should be in O(1) time. The obvious choice for this requirement is Linked List. Linked List support insert/delete operations in O(1) time if we have the reference of element.

While building an LRU cache requires that you think in terms of these two data structures. The reality is that these two data structures actually work coherently to achieve the design.

So, we are finalizing on these data structures: HashMap and Doubly Linked List
*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, list<int>::iterator> mp;
list<int> q;
int sz;
void insert(int x)
{

    // if not present
    if (mp.find(x) == mp.end())
    {
        if (q.size() == sz)
        {
            int last = q.back();
            q.pop_back();
            mp.erase(last);
        }
    }
    // if present
    else
        mp.erase(x);

    q.push_front(x);
    mp[x] = q.begin();
}

void display()
{

    for (auto it = q.begin(); it != q.end(); it++)
        cout << *it << " ";
}

int main()
{

    cin >> sz;
    insert(1);
    insert(2);
    insert(3);
    insert(1);
    insert(4);
    insert(5);
    display();
    return 0;
}