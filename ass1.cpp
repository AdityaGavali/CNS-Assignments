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
return 0;
}
