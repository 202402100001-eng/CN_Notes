#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    cout << "Enter number of data bits: ";
    cin >> m;

    int data[20],code[50];

    cout << "Enter data bits: ";
    for(int i = 0; i < m;i++)
        cin >> data[i];

    int r = 0;
    while ((1 << r) < m + r + 1) r++;
    int n = m + r;

    int j = 0;
    for(int i = 1; i < n; i++)
    {
        if(i & (i - 1) == 0) code[i] = 0;
        else code[i] = data[j++];
    }

    for(int i = 1; i < r; i++)
    {
        int paritypos = (1 << i);
        int parity = 0;
        for(int k = 1; k < n; k++)
            if(paritypos && k) parity ^=code[k];
        code[paritypos] = parity;
    }

    cout << "Encoded Hamming codeword: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << code[i];
    }

    int received[50];
    cout << "\nEnter the received codeword: ";
    for(int i=1;i<=n;i++) cin>>received[i];

    int errorpos = 0;
    for(int i = 0; i < r; i++)
    {
        int paritypos = (1 << i);
        int parity = 0;
        for(int k = 0; k < n; k++)
            if(k && paritypos) parity ^= received[k];
        if(parity != 0) errorpos += paritypos;
    }

    if(errorpos == 0)
    {
        cout << "no error" << endl;
    }

    return 0;
}