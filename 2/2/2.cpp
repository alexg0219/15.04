#include <iostream>
#include <queue>

using namespace std;

int main() 
{
    int n;
    cin >> n;

    priority_queue<pair<int, int>> q;
    
    for (int i = 0; i < n; i++) 
    {
        int k;
        cin >> k;
        q.emplace(k, i + 1);
    }

    vector<pair<int, int>> output;

    while (q.size() > 1) 
    {
        auto a1 = q.top();
        q.pop();
        auto a2 = q.top();
        q.pop();
        output.emplace_back(a1.second, a2.second);
        if (a1.first > 1) {
            q.emplace(a1.first - 1, a1.second);
        }
        if (a2.first > 1) {
            q.emplace(a2.first - 1, a2.second);
        }
    }

    std::cout << output.size() << endl;
}