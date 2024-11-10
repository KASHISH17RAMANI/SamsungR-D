#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int data)
    {
        data = data;
        left = right = NULL;
    }
};

node *insert(int data, node *root)
{
    if (root == NULL)
    {
        node *temp = new node(data);
        return temp;
    }
    if (data > root->data)
        root->right = insert(data, root->right);
    else if (data < root->data)
        root->left = insert(data, root->left);

    return root;
}

int search(int data, int level, node *head)
{

    if (head->data == data)
        return level;

    if (data > head->data)
        return search(data, level + 1, head->right);
    else
        return search(data, level + 1, head->left);
}

vector<int> solve(vector<int> v, int n)
{

    node *head = NULL;

    for (int i = 0; i < n; i++)
        head = insert(v[i], head);

    cout << head->data;

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        ans.push_back(search(v[i], 1, head));
    }

    return ans;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i_A = 0; i_A < N; i_A++)
    {
        cin >> A[i_A];
    }

    vector<int> out_;
    out_ = solve(A, N);
    cout << out_[0];
    for (int i_out_ = 1; i_out_ < N; i_out_++)
    {
        cout << " " << out_[i_out_];
    }
}