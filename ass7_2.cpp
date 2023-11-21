#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long p, alpha;

    cout << "Enter prime number and primitive root: ";
    cin >> p >> alpha;

    long long xA;
    cout << "Enter private key: ";
    cin >> xA;

    double yA;
    yA = ((long long)pow(alpha, xA));

    long long temp_yA = yA;
    long long final_yA = temp_yA % p;
    cout << "yA: " << final_yA << endl;

    long long m;
    cout << "Enter plalong longext m=H(m): ";
    cin >> m;

    long long k;
    cout << "Enter random integer k which is less than p-1: ";
    cin >> k;

    // Calculating digital signature
    long long s1;
    s1 = ((long long)pow(alpha, k)) % p;
    cout << "Sigital signature s1: " << s1 << endl;

    long long k_inverse;
    for (long long i = 1; i < p - 1; i++)
    {
        if (((k * i) % (p - 1)) == 1)
        {
            k_inverse = i;
            break;
        }
    }
    cout << k_inverse;

    long long s2;
    s2 = (p - 1) - (abs(k_inverse * (m - (xA * s1))) % (p - 1));
    cout << "Sigital signature s2: " << s2 << endl;

    // calculating validation at receiver end

    double v1;
    v1 = pow(alpha, m);
    long long tem_v1 = v1;

    long long final_v1 = tem_v1 % p;

    cout << "V1: " << final_v1 << endl;

    long long v2;

    double temp_v2 = pow(final_yA, s1);
    long long ans1 = temp_v2;

    //cout << "ANS1" << ans1<<endl;

    double temp1_v2 = pow(s1, s2);
    long long ans2 = temp1_v2;

    //cout << "ANS2" << ans2<<endl;

    v2 = (ans1 * ans2) % p;
    cout << "V2: " << v2 << endl;

    if (final_v1 == v2)
    {
        cout << "Signature is valid" << endl;
    }

    return 0;
}