#include <bits/stdc++.h>
#include <chrono>

using namespace std;

#define int long long

int binpow(int a,int b,int m){
    a%=m;
    int res=1;
    while(b){
        if(b&1)
            res=(res*a)%m;
        a=(a*a)%m;
        b/=2;
    }
    return res;
}

int encrypt(int m,int e,int n){
    return binpow(m,e,n);
}

int decrypt(int c,int d,int n){
    return binpow(c,d,n);
}

int32_t main() {
    auto key_gen_start=chrono::steady_clock::now();
    int p=3,q=7;
    int n=p*q;
    int phiN=(p-1)*(q-1);
    cout<<"n = "<<n<<'\n';
    cout<<"phiN = "<<phiN<<'\n';
    int e,d;
    for(e=2;e<phiN and __gcd(e,phiN)!=1;e++);
    cout<<"e = "<<e<<'\n';
    for(d=0;(d*e)%phiN != 1;d++);
    cout<<"d = "<<d<<'\n';
    auto key_gen_end=chrono::steady_clock::now();
    auto key_gen_diff=key_gen_end-key_gen_start;
    cout<<"Key generation time: "<<chrono::duration <double, milli> (key_gen_diff).count()<<" ms\n";
    int m;
    cout<<"Enter input length less than "<<n<<": \n";
    cin>>m;
    auto encryption_start=chrono::steady_clock::now();
    int c=encrypt(m,e,n);
    cout<<"Encrypted text: "<<c<<'\n';
    auto encryption_end=chrono::steady_clock::now();
    auto encryption_diff=encryption_end-encryption_start;
    cout<<"Encryption time: "<<chrono::duration <double, milli> (encryption_diff).count()<<" ms\n";
    auto decryption_start=chrono::steady_clock::now();
    cout<<"Decrypted text: "<<decrypt(c,d,n)<<'\n';
    auto decryption_end=chrono::steady_clock::now();
    auto decryption_diff=decryption_end-decryption_start;
    cout<<"Decryption time: "<<chrono::duration <double, milli> (decryption_diff).count()<<" ms\n";
}