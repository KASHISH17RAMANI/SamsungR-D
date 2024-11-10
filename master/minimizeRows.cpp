void f(vector<int> &v)
{
    map<int, int> m;
    for (auto &c : v)
    {
        auto t = m.upper_bound(c);
        if (t != m.end())
            m.erase(t->first);
        m[c] = 1;
    }
    cout << m.size() << " ";
}