#include <bits/stdc++.h>
using namespace std;

void goBackNARQ(int totalFrames,int windowSize){
    srand(time(0));
    int sent = 0;

    
    while(sent < totalFrames)
    {
        int windowend = min(sent + windowSize, totalFrames);
        cout << "Sender: sending Frame " << sent << " - " << windowend - 1 << endl;

        int errorframe = rand() % windowSize;
        bool error = rand() % 2;
        if(error && (errorframe + sent < totalFrames))
        {
            cout << "Receiver : Lost frame " << sent + errorframe << endl;
            cout << "sender : Timeout resending the frame " << sent + errorframe << endl;
            sent = sent + errorframe;
        }
        else
        {
            cout << "Received all window frames successfully" << endl;
            sent = windowend;
        }
    }

    cout << endl;
    cout << "All frames recieved! " << endl;
}

int main()
{
    int n,w;
    cout << "Enter total number of frames: ";
    cin >> n;

    cout << "Enter window size: ";
    cin >> w;

    goBackNARQ(n,w);
    return 0;
}