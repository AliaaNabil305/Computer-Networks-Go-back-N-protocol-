#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
/*to simulate a Noisy cahnnel we used the rand function and an input from the user that 
would be the effiecency of the channel.
Then We asked The user for the number of frames to be sent and we have a default window 
size of 8.
then we indexed the start of the window with i and the frame to be sent with j and when ever
acknowldgment is recieved for frame j we advance the window(i) by 1.
if acknowledge isn't recieved we retransmit the entire frame. */
int main()
{
 srand (time(NULL)); 
 int number_of_frames,percentageEff,WINDOW_SIZE;
 cout<<"Enter The percentage efficiency:";
 cin>>percentageEff;
 cout<<"Enter the number of frames : ";
 cin>> number_of_frames;
 cout<<"Enter window size : "; 
 cin>> WINDOW_SIZE;

 int i=1;
 while(i<=number_of_frames)
 {
     int k=0;
     //sending the frames out on the channel from the start of the window. 
     for(int j=i;j<i+WINDOW_SIZE && j<=number_of_frames;j++)
     {
         cout<<"Sent Frame "<<j<<endl;
     }
     for(int j=i;j<i+WINDOW_SIZE && j<=number_of_frames;j++)
     {
         int randTemp = rand()%100; 
         if(randTemp >= (100 - percentageEff)) //emulating the noise on a channel
             {
                 cout<<"Acknowledgment for Frame "<<j<<endl;
                 k++;
             }
         else
             {   cout<<"Frame "<<j<<" Not Received"<<endl;
                 cout<<"Retransmitting Window"<<endl;
                 break;
             }
     }
     cout<<endl;
     i+=k; //sliding the window forward with the number of sent frames
 }
 return 0;
}