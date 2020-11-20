//Banker's Algorithm

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of process\n";
    cin>>n;
    int r;
    cout<<"Enter no of resoures\n";
    cin>>r;
    int resources[r];
    int available[r];
    for(int i =0;i<r;i++)
    {
        cout<<"Enter number of resources of type "<<(char)(65+i)<<"\n";
        cin>>resources[i];
        available[i]=resources[i];
    }
    int allocated[n][r];
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<r;j++){
        cout<<"Enter number of resources of type "<<(char)(65+j)<<" allocated for process P"<<i<<"\n";
        cin>>allocated[i][j];
        available[j]= available[j]-allocated[i][j];
        }
    }
    int max[n][r];
     for(int i =0;i<n;i++)
    {
        for(int j =0;j<r;j++){
        cout<<"Enter total number of resources of type "<<(char)(65+j)<<" required for process P"<<i<<"\n";
        cin>>max[i][j];
        }
    }
    int need[n][r];
     for(int i =0;i<n;i++)
    {
        for(int j =0;j<r;j++){
        need[i][j]=max[i][j]-allocated[i][j];
        }
    }
    int order[n];
    bool finish[n]={false};
    int x=0;
    for(int p =0;p<n;p++)
    {
        for(int i =0;i<n;i++)
        {
            if(finish[i]==true)
            {
                continue;
            }
            else{
                bool ready = true;
                for(int j =0;j<r;j++)
                {
                    if(need[i][j]>available[j])
                    {
                        ready=false;
                        break;
                    }
                }
                if(ready)
                {
                    finish[i]=true;
                    for(int j =0;j<r;j++)
                     {
                        available[j]+=allocated[i][j];
                     }
                     order[x++]=i;
                }
            }
        }
    }
    int i =0;
    for(i=0;i<n;i++)
    {
        if(finish[i]==false)
          break;
    }
    if(i==n)
    {
        cout<<"System is in safe state\n";
        cout<<"Safe Sequence: ";
        for(int j =0;j<n-1;j++)
        {
            cout<<"P"<<order[j]<<"->";
        }
        cout<<"P"<<order[n-1];
    }
    else{
        cout<<"System is not in safe state, Deadlock will occur\n";
    }
    return 0;
}
