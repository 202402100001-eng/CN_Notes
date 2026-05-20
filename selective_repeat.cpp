#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void selectiveRepeatARQ(int totalFrames, int windowSize) {
    vector <bool> ack(totalFrames, false);
    int base = 0;

    while (base < totalFrames)
    {
        int end = min(base + windowSize, totalFrames);

        for (int i = base; i < end - 1; i++)
        {
            if(ack[i]) continue;
            
            if(rand() % 4 == 0)
            {
                cout << "Receiver : Error at frame " << i << endl;
            }
            else 
            {
                cout << "Receiver : Frame recieved " << i << " ack sent!" << endl;
            }
        }

        bool ispending = false;
        for(int i = base; i < end - 1; i++)
        {
            if(!ack[i])
            {
                ispending = true;
                cout << "Sender : resending frame " << i << endl;
            }
        }

        while (ack[base] && base < totalFrames) base++;

        cout << (ispending ? "Sender waiting for ACK ..\n\n"
        : "Sender : sliding window....\n\n");
    }
    cout << "All frames recieved! " << endl;
}

int main() {
    srand(time(0));

    int n, w;
    cout << "Enter total number of frames: ";
    cin >> n;
    cout << "Enter window size: ";
    cin >> w;

    selectiveRepeatARQ(n, w);
}
