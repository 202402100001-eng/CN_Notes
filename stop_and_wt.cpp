#include <bits/stdc++.h>
using namespace std;


void stop_and_wait(int totalFrames)
{
    srand(time(0));
    int frame = 0;

    cout << "-- Stop and Wait simulation --" << endl;
    while(frame < totalFrames)
    {
        cout << "Sender : sending frame " << frame << endl;
        int ack = rand() % 2;
        if(ack)
        {
            cout << "Receiver : Frame " << frame << " recieved. Sending ACk\n";
            cout << "Sender : ACK recieved for Frame " << frame << "\n\n";
            frame++;
        }
        else
        {
            cout << "Receiver: Frame " << frame << " lost ACK not received\n";
            cout << "Sender : Timeout ! Resending Frame " << frame << "\n\n";
        }
    }
    cout << "All Frames Received Successfully ! " << endl;
}

int main()
{
    int n;
    cout << "Enter the number of frames : ";
    cin >> n;

    stop_and_wait(n);

    return 0;
}