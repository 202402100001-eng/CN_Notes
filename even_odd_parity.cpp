#include <iostream>
using namespace std;

int main(){
    string data; 
    cout << "Enter binary data: ";
    cin >> data; 

    int cnt1 = 0;
    for (char c : data) if (c == '1') cnt1++;

    char parity;
    if(cnt1 % 2 == 0) parity = '0';
    else parity = '1';

    cout << "Even Parity Bit is: " << parity << endl;

    // Receiver side 
    string rec_data;
    cout << "Enter received data: ";
    cin >> rec_data;

    int cnt = 0; 
    for (char c : rec_data) if (c == '1') cnt++;

    if (cnt % 2 == 0)
        cout << "No error detected" << endl;
    else 
        cout << "Error Detected" << endl;

    return 0;

}