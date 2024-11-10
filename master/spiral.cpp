void printSpiral(Node *root)
{
    if (root == NULL)
        return;
    deque<Node *> q;
    q.push_front(root);
    int LtoR = 0;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            Node *temp;
            if (LtoR)
            {
                temp = q.front();
                cout << temp->data << " ";
                q.pop_front();
                if (temp->left)
                    q.push_back(temp->left);
                if (temp->right)
                    q.push_back(temp->right);
            }
            else
            {
                temp = q.back();
                cout << temp->data << " ";
                q.pop_back();

                if (temp->right)
                    q.push_front(temp->right);
                if (temp->left)
                    q.push_front(temp->left);
            }
        }
        LtoR = 1 - LtoR;
    }
}