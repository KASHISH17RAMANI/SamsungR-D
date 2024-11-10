.04 KB | None |

/*
          10
        /     \
      12       13
           /     \
         14       15
        /   \     /  \
       21   22   23   24
       /\   /\   /\   /\
      1 2  3 4  5 6  7  8
*/

#include <iostream>
    using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        data = data;
        left = right = NULL;
    }
};

void leaf(Node *x, int val, int *ans)
{

    if (x == NULL)
        return;

    if (!x->left && !x->right)
    {
        *ans = min(*ans, val);
        return;
    }

    leaf(x->left, val + 1, ans);
    leaf(x->right, val + 1, ans);
}

bool parent(Node *root, Node *x, int *ans)
{

    if (root == NULL)
        return false;
    if (root == x)
        return true;

    bool l = parent(root->left, x, ans);
    if (l)
    {
        leaf(root->right, 2, ans);
    }

    bool r = parent(root->right, x, ans);
    if (r)
    {
        leaf(root->left, 2, ans);
    }

    return false;
}

void solve(Node *root, Node *x)
{

    int ans = 100000;

    leaf(x, 0, &ans);
    parent(root, x, &ans);

    cout << ans << endl;
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(12);
    root->right = new Node(13);

    root->right->left = new Node(14);
    root->right->right = new Node(15);

    root->right->left->left = new Node(21);
    root->right->left->right = new Node(22);
    root->right->right->left = new Node(23);
    root->right->right->right = new Node(24);

    root->right->left->left->left = new Node(1);
    root->right->left->left->right = new Node(2);
    root->right->left->right->left = new Node(3);
    root->right->left->right->right = new Node(4);
    root->right->right->left->left = new Node(5);
    root->right->right->left->right = new Node(6);
    root->right->right->right->left = new Node(7);
    root->right->right->right->right = new Node(8);

    Node *x = root->right;

    solve(root, x);
    return 0;
}