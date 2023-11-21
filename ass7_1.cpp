#include <bits/stdc++.h>
using namespace std;
int main()
{ // key generation
    int p;
    cout << "Enter prime number: ";
    cin >> p;

    int pT;
    cout << "Enter plain text: ";
    cin >> pT;
    int d;
    cout << "Enter private key: ";
    cin >> d;

    int e1;
    cout << "Enter public key: ";
    cin >> e1;

    int e2;
    e2 = (int)pow(e1, d) % p;

    // public key={e1,e2,p} private key={d}

    // encryption
    int r;
    cout << "Select random number r: ";
    cin >> r;

    int c1;
    c1 = (int)pow(e1, r) % p;

    long long c2;
    c2 = (pT * ((int)pow(e2, r))) % p;

    cout << "Encryption:c1 and c2 " << c1 << c2 << endl;

    // Decryption

    int decry;

    double temp;
    cout<<c1<<" "<<d;
    temp = pow(c1, d);
    int ans=temp;

    cout<<"Temp: "<<temp<<endl;

    int temp1;
    for (int i = 1; i < p - 1; i++)
    {
        if ((ans * i) % p == 1)
        {
            temp1 = i;
            break;
        }
    }
    cout<<"temp1: "<<temp1;
    decry = (c2 * temp1) % p;

    cout << "Decryption: " << decry;

    return 0;
}