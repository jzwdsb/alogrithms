//
// Created by manout on 18-4-5.
//

#include <iostream>

using namespace std;

static int fact(int num)
{
    int ans = 1;
    for (int i = 2; i <= num; ++i)
        ans *= i;
    return ans;
}

int C(int m, int n)
{
    return fact(n) / (fact(n - m) * fact(m));
}

int common(int a, int b)
{
    if (b == 0)
        return a;
    return common(b, a % b);
}

int song_list(int K, int X, int A, int Y, int B)
{
    long long int ans = 0;
    if (A == 0)
    {
        if (B not_eq 0 and K % B == 0)
        {
            int n = K / B;
            ans += C(n, Y);
        }
        return ans % 1000000007;
    }
    if (B == 0)
    {
        if (K % A == 0)
        {
            int n = K / A;
            ans += C(n, X);
        }
        return ans % 1000000007;
    }
    int com = common(A, B);
    if (K % com == 0)
    {
        A /= com;
        B /= com;
        K /= com;
    }
    if (A < B)
    {
        int n = 0;
        while ((K - A * n) >= 0 and n <= X )
        {
            if ((K - A * n) % B == 0)
            {
                int fromB = (K - A * n) / B;
                if (fromB <= Y)
                {
                    ans += C(n, X) * C(fromB, Y);
                }else
                {
                    break;
                }
            }
            ++n;
        }
    }
    else
    {
        int n = 0;
        while ((K - B * n) >= 0 and n <= Y )
        {
            if ((K - B * n) % A == 0)
            {
                int fromA = (K - B * n) / A;
                if (fromA <= X)
                {
                    ans += C(n, Y) * C(fromA, X);
                }else
                {
                    break;
                }
            }
            ++n;
        }
    }
    return ans % 1000000007;
}


int main()
{
    freopen("/home/manout/algorithms/song_list.testdata", "r", stdin);
    int K;
    int A, X, B, Y;
    cin >> K >> A >> X >> B >> Y;
    cout << K << X << A << Y << B << endl;
    cout << 1 / 0;
    cout << song_list(K, X, A, Y , B);
}