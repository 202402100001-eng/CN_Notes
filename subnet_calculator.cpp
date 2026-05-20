#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(){
    string ip;
    int prefix;

    cout << "Enter IP address (e.g. 192.168.1.0): ";
    cin >> ip;
    cout << "Enter prefix length (e.g. 24): ";
    cin >> prefix;

    // Parse IP into 4 octets
    int oct[4];
    int i = 0, val = 0;
    for(char c : ip){
        if(c == '.'){
            oct[i++] = val;
            val = 0;
        } else {
            val = val * 10 + (c - '0');
        }
    }
    oct[i] = val;

    // Convert IP to 32-bit
    unsigned int ipNum    = (oct[0]<<24)|(oct[1]<<16)|(oct[2]<<8)|oct[3];
    unsigned int mask     = 0xFFFFFFFF << (32 - prefix);
    unsigned int network  = ipNum & mask;
    unsigned int broadcast= network | (~mask);
    unsigned int firstHost= network + 1;
    unsigned int lastHost = broadcast - 1;

    int hostBits   = 32 - prefix;
    long long hosts = pow(2, hostBits) - 2;

    int defaultPrefix;
    if(oct[0] < 128)      defaultPrefix = 8;
    else if(oct[0] < 192) defaultPrefix = 16;
    else                  defaultPrefix = 24;

    int borrowedBits   = prefix - defaultPrefix;
    long long numSubnets = (borrowedBits >= 0) ? (long long)pow(2, borrowedBits) : 1;

    auto printIP = [](unsigned int ip){
        cout << ((ip>>24)&0xFF) << "."
             << ((ip>>16)&0xFF) << "."
             << ((ip>>8) &0xFF) << "."
             << ( ip     &0xFF);
    };

    cout << "\n======= Subnet Calculator =======" << endl;
    cout << "IP Address       : " << ip << "/" << prefix << endl;
    cout << "Subnet Mask      : "; printIP(mask);      cout << endl;
    cout << "Network Address  : "; printIP(network);   cout << endl;
    cout << "Broadcast Addr   : "; printIP(broadcast); cout << endl;
    cout << "First Host       : "; printIP(firstHost); cout << endl;
    cout << "Last Host        : "; printIP(lastHost);  cout << endl;
    cout << "Total Hosts      : " << hosts << endl;
    cout << "Number of Subnets: " << numSubnets << endl;
    cout << "Host Bits        : " << hostBits << endl;
    cout << "=================================" << endl;

    return 0;
}
