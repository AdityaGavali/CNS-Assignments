#include<bits/stdc++.h>
using namespace std;
//1
void ceasarcipher(string msg){
      transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
      string encrypt = "",decrypt = "";
   for(int i = 0;i<msg.size();i++){
    if(msg[i] != ' '){

        encrypt += ((msg[i]-'A') + 3)%26 + 'A';
       
   }
   }
   cout<<"Encrypted Message : "<<encrypt<<endl;
   for(int i = 0;i<encrypt.size();i++){
    if(encrypt[i] != ' '){
        decrypt += ((encrypt[i]-'A') - 3)%26 + 'A';
   }
   }
   cout<<"Decrypted Message : "<<decrypt<<endl;
    return;
}
   
 //2
 void monoalphabetic(string msg){
    unordered_map<char,char> m;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string sub = "mnbvcxzlkjhgfdsapoiuytrewq";
    string encrypt;
  for(int i=0; i<sub.size(); i++)
  {
    m.insert(make_pair(alphabet[i],sub[i]));
  } 
  for(int i=0; i<msg.size(); i++)
  {
    encrypt.push_back(m[msg[i]]);
  }
   cout<<"Encrypted Message : "<<encrypt<<endl;
      m.clear();
  for(int i=0; i<sub.size(); i++)
  {
    m.insert(make_pair(sub[i],alphabet[i]));
  }
   string decrypt;
  for(int i=0; i<msg.size(); i++)
  {
    decrypt.push_back(m[encrypt[i]]);
  }
  cout<<"Decrypted Messaeg : "<<decrypt<<endl;
  return;
 }  
//3
void vegnere(string msg){
  cout<<"Enter the Key"<<endl;
  string key;
  cin>>key;
   string encrypted_text = "";
    string extended_key = key;
    while (extended_key.length() < msg.length())
        extended_key += key;
    for (int i = 0; i < msg.length(); ++i) {
        char c = msg[i];
        if (isalpha(c)) {
            char ch='A';
            if(islower(c))
                ch='a';
            int shift = extended_key[i] - 'A';
            if(islower(extended_key[i]))
                shift = extended_key[i] - 'a';
            char encrypted_char = ch+((c-ch+shift)%26);
            encrypted_text += encrypted_char;
        } else {
            encrypted_text += c;
        }
    }
    cout<<"Encrypted Message : "<<encrypted_text<<endl;
    string cipher = encrypted_text;
     string decrypted_text = "";
    for (int i = 0; i < cipher.length(); ++i) {
        char c = cipher[i];
        if (isalpha(c)) {
            char ch='A';
            if(islower(c))
                ch='a';
            int shift = extended_key[i] - 'A';
            if(islower(extended_key[i]))
                shift = extended_key[i] - 'a';
            char encrypted_char = ch+((c-ch-shift+26)%26);
            decrypted_text += encrypted_char;
        } else {
            decrypted_text += c;
        }
    }
    cout<<"Decrypted Message : "<<decrypted_text<<endl;
    return;
}

 //4
 void vernam(string msg){
  int n = msg.length();
   string key;
  cout<<"Enter key : "<<endl;
  cin>>key;
string ciphertext;
for (int i = 0; i < n; ++i) {
char encryptedChar = msg[i] ^ key[i%key.size()];
ciphertext += encryptedChar;
}
 cout<<"Encrypted Message : "<<ciphertext<<endl;
 string decrypt;
for (int i = 0; i < n; ++i) {
char decryptedChar = ciphertext[i] ^ key[i%key.size()];
 decrypt += decryptedChar;
}
 cout<<"Decrypted Message : "<<decrypt<<endl;
 return;
 }

//5 

void Railfence(string msg){
  int railCount;
  cout<<"Enter number of rails : \n";
  cin>>railCount;
  vector<string> rails(railCount, "");
int currentRail = 0;
bool downDirection = true;
for (char c : msg) {
rails[currentRail] += c;
if (currentRail == 0)
downDirection = true;
else if (currentRail == railCount - 1)
downDirection = false;
if (downDirection)
currentRail++;
else
currentRail--;
}
string ciphertext;
for (const string& rail : rails) {
ciphertext += rail;
}
cout<<"Encrypted Text : "<<ciphertext<<endl;
 vector<string> rail(railCount, "");
    int direction = 1;
    int row = 0;
    for (char &c:ciphertext) {
        rail[row] += '$';
        if (row == 0) {
            direction = 1;
        } else if (row == railCount- 1) {
            direction = -1;
        }
        row += direction;
    }
    int ind=0;
    for(int i=0;i<railCount;i++){
        for(auto &ch:rail[i]){
            ch=ciphertext[ind++];
        }
    }
    row-=direction;
    string res;
    for(int i=0;i<ciphertext.size();i++){
        res+=rail[row].back();
        rail[row].pop_back();
        if (row == 0) {
            direction = 1;
        } else if (row == railCount - 1) {
            direction = -1;
        }
        row += direction;
    }
    reverse(res.begin(),res.end());
    cout<<"Decrypted Message : "<<res<<endl;
    return;
}

int main(){

    cout<<"Enter the message :\n";
    string msg;
    cin>>msg;
    cout << "Select a Cipher:" << endl;
        cout << "1. Caesar Cipher" << endl;
        cout << "2. Monoalphabetic Cipher" << endl;
        cout << "3. Polyalphabetic (Vigenere) Cipher" << endl;
        cout << "4. Vernam Cipher" << endl;
        cout << "5. Rail Fence Cipher" << endl;
        cout << "6. Exit" << endl;
    int choice;
    cout<<"Enter the choice of cipher : \n";
    cin>>choice;
    if(choice == 1){
        ceasarcipher(msg);
    }
    if(choice == 2){
        monoalphabetic(msg);
    }
    if(choice == 3){
      vegnere(msg);
          }
    if(choice == 4){
      vernam(msg);
    }
    if(choice == 5){
      Railfence(msg);
    }
return 0;
}
