#include <iostream>

using namespace std;

int main()
{
    const double pi = acos(-1.0);
    double d, r,s,left,right,m,mid,th;
    int n;
    cin >> d >> r >> n;

    for (int i = 1; i < n; i++)
    {
        s = i * (pi * r * r + 2 * r * d) / n;
        left = 0;
        right = 2 * r + d;

        for (int j = 0; j < 64; j++)
        {
            m = (left + right) / 2;
            if (m < r)
            {
                th = 2 * acos((r - m) / r);
                mid = r * r / 2 * (th - sin(th));
            }
            else
            {
                if (m <= r + d)
                    mid = pi * r * r / 2 + (m - r) * 2 * r;
                else
                {
                    th = 2 * acos((r - (2 * r + d - m)) / r);
                    mid = (pi * r * r + 2 * r * d) - r*r/2 * (th - sin(th));
                }
            }

            if (mid > s)
                right = m;
            else
                left = m;
        }
        cout << (left + right) / 2 << endl;
    }
}