#include <bits/stdc++.h>
using namespace std;
int publicKey(int Xa, int alpha, int q)
{
  int Ya = 1;
  while(Xa > 0)
    {
      Ya *= alpha;
      Ya %= q;
      Xa--;
    }
  return Ya;
}
int sign1(int alpha, int K, int q)
{
  int s1 = 1;
  while(K > 0)
    {
      s1 *= alpha;
      s1 %= q;
      K--;
    }
  return s1;
}

int inverse(int K, int mod)
{
  int k1 = 1;
  while(K*k1 % mod != 1) {
    k1++;
  }
  return k1;
}

int sign2(int K1, int m, int Xa, int S1, int mod)
{
  int temp = m - Xa*S1;
  int s2 = ((K1) * abs(temp)) % mod;
  if(temp < 0) {
    return mod - s2;
  }
  return s2;
}
int verify1(int alpha, int m, int q)
{
  int v1 = 1;
  while(m > 0)
    {
      v1 *= alpha;
      v1 %= q;
      m--;
    }
  return v1;
}
int verify2(int Ya, int S1, int S2, int q)
{

  long long term1 = pow(Ya, S1);
  long long term2 = pow(S1, S2);
  return (term1 * term2) % q;
}
int main(){
  int q, alpha, Xa, Ya, m, K;
  cout << "\nEnter Public elements for Elgamal Algorithm (q, alpha) : ";
  cin >> q >> alpha;
  cout << "Enter Private Key for User : ";
  cin >> Xa;
  cout << "Enter Hash value of message ie. m : ";
  cin >> m;
  cout << "Enter a Random Character K : ";
  cin >> K;
  
  Ya = publicKey(Xa, alpha, q);
  cout << "\nPublic Key for User : Ya : " << Ya << endl;
  // Digital Signature generation
  int S1, S2;
  S1 = sign1(alpha, K, q);
  cout << "\nS1 = " << S1 << endl;
  int K1 = inverse(K, q-1);
  cout << "\nK inverse : K1 = " << K1 << endl;
  S2 = sign2(K1, m, Xa, S1, q-1);
  cout << "\nS2 = " << S2 << endl;
  // Digital Signature is (S1, S2)
  cout << "\nDigital Signature is : (S1, S2) => ( " << S1 << " , " << S2 << " ) \n"; 
  // Verification
  int v1, v2;
  v1 = verify1(alpha, m, q);
  v2 = verify2(Ya, S1, S2, q);
  cout << "\nV1 = " << v1 << endl;
  cout << "\nV2 = " << v2 << endl;
  if(v1 == v2) cout << "\nVerified\n";
  else cout << "\nNot Verified\n";
}