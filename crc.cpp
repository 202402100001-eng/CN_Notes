#include<iostream>
#include<string>
using namespace std;

string xorOp(string a, string b){
    string res = "";
    for(int i = 1; i < b.length(); i++)
        res += (a[i] == b[i]) ? '0' : '1';
    return res;
}

string divide(string data, string div){
    int dlen = div.length();
    string temp = data.substr(0, dlen);
    for(int i = dlen; i <= data.length(); i++){
        if(temp[0] == '1')
            temp = xorOp(temp, div);
        else
            temp = xorOp(temp, string(dlen, '0'));
        if(i < data.length())
            temp += data[i];
    }
    return temp;
}

int main(){
    string data, gen;

    cout << "Enter binary data: ";
    cin >> data;
    cout << "Enter generator: ";
    cin >> gen;

    string appended  = data + string(gen.length()-1, '0');
    string remainder = divide(appended, gen);
    string transmitted = data + remainder;

    cout << "CRC remainder  : " << remainder << endl;
    cout << "Transmitted    : " << transmitted << endl;

    string received;
    cout << "Enter received data: ";
    cin >> received;

    string check = divide(received, gen);

    bool error = false;
    for(char c : check)
        if(c != '0'){ error = true; break; }

    if(error)
        cout << "Error detected! Remainder: " << check << endl;
    else
        cout << "No error detected." << endl;

    return 0;
}
