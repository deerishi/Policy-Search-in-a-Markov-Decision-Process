//In this code we try the thing that 

#include "bits/stdc++.h"
using namespace std;

double Q[4][4][4],V[4][4],R[4][4];
int Policy[4][4];

void initialize(double r)
{
    //This function initializes the Value Array V and the Reward Array R to the initial rewards of the system
    int i,j;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            V[i][j]=0.0;
            R[i][j]=-1.0;
        }
    }
    R[3][3]=10.0;
    R[3][1]=r;
    V[3][3]=10.0;
    
}

void printPolicy()
{
    //This fuinction prints the Policy with the arrows signifying the direction
    int i,j;
    for(i=3;i>=1;i--)
    {
        for(j=1;j<=3;j++)
        {
            if(i==3 and j==3)
            {
                cout<<" Goal ";
                continue;
            }
            switch(Policy[i][j])
            {
                case 0: cout<<" /\\";
                        break;
                case 1: cout<<"\\/";
                        break;
                case 2: cout<<" < ";
                        break;
                case 3: cout<<" > ";
                        break;
            }
            cout<<"  ";
         }
         cout<<"\n";
    }
}

void printV()
{
    int i,j;
    for(i=3;i>=1;i--)
    {
        for(j=1;j<=3;j++)
        {
            cout<<V[i][j]<<"  ";
        }
        cout<<"\n";
    }
}

void printQ(int i,int j)
{
    
    for(int a=0;a<4;a++)
    {
        cout<<Q[i][j][a]<<"  ";
        
    }
    cout<<"\n";
}

void valueIteration(double gamma)
{
    //This function computes the values for the Value Array  by doing Value Iteration
    int i,j,l,a,maxQindex;
    double maxQ;
    
    for(l=0;l<25;l++)
    {
        //Outer loop for the number of iterations
        for(i=3;i>=1;i--)
        {
            for(j=3;j>=1;j--)
            {
                if(i==3 and j==3)
                    continue;
                maxQ=-1000000.0;
                for(a=0;a<=3;a++)
                {
                    //We need to check if the current action is legal or not
                    switch(a)
                    {
                        case 0: 
                                //going up
                                Q[i][j][a]=R[i][j];
                                if(i+1<=3 and i+1>=1)
                                {
                                    Q[i][j][a]+=gamma*0.8*V[i+1][j];
                                }
                                else
                                {
                                    Q[i][j][a]+=gamma*0.8*V[i][j];
                                }
                                
                                //check for left and right conditions
                                if(j-1 >=1 and j-1<=3)
                                {
                                    Q[i][j][a]+=gamma*0.1*V[i][j-1];
                                }
                                else
                                {
                                    Q[i][j][a]+=gamma*0.1*V[i][j];
                                }
                                
                                if(j+1 <=3 and j+1>=1)
                                {
                                    Q[i][j][a]+=gamma*0.1*V[i][j+1];
                                }
                                else
                                {
                                    Q[i][j][a]+=gamma*0.1*V[i][j];
                                }
                                
                                if(Q[i][j][a]>maxQ)
                                {
                                    maxQ=Q[i][j][a];
                                    maxQindex=a;
                                }
                                break;
                       
                       case 1: 
                                //going doown
                                Q[i][j][a]=R[i][j];
                                if(i-1<=3 and i-1>=1)
                                {
                                    Q[i][j][a]+=gamma*0.8*V[i-1][j];
                                }
                                else
                                {
                                    Q[i][j][a]+=gamma*0.8*V[i][j];
                                }
                                
                                //check for left and right conditions
                                if(j-1 >=1 and j-1<=3)
                                {
                                    Q[i][j][a]+=gamma*0.1*V[i][j-1];
                                }
                                else
                                {
                                    Q[i][j][a]+=gamma*0.1*V[i][j];
                                }
                                
                                if(j+1 <=3 and j+1>=1)
                                {
                                    Q[i][j][a]+=gamma*0.1*V[i][j+1];
                                }
                                else
                                {
                                    Q[i][j][a]+=gamma*0.1*V[i][j];
                                }
                                
                                if(Q[i][j][a]>maxQ)
                                {
                                    maxQ=Q[i][j][a];
                                    maxQindex=a;
                                }
                                break;
                                
                      case 2: 
                                //going left
                                Q[i][j][a]=R[i][j];
                                if(j-1>=1 and j-1<=3)
                                {
                                    Q[i][j][a]+=gamma*0.8*V[i][j-1];
                                }
                                else
                                {
                                    Q[i][j][a]+=gamma*0.8*V[i][j];
                                }
                                
                                //check for up and down conditions
                                
                                if(i+1>=1 and i+1<=3)
                                {
                                    Q[i][j][a]+=gamma*0.1*V[i+1][j];
                                }
                                else
                                {
                                    Q[i][j][a]+=gamma*0.1*V[i][j];
                                }
                                
                                if(i-1>=1 and i-1<=3)
                                {
                                    Q[i][j][a]+=gamma*0.1*V[i-1][j];
                                }
                                else
                                {
                                    Q[i][j][a]+=gamma*0.1*V[i][j];
                                }
                                
                                if(Q[i][j][a]>maxQ)
                                {
                                    maxQ=Q[i][j][a];
                                    maxQindex=a;
                                }
                                break;
                                
                        case 3: 
                                //going right
                                Q[i][j][a]=R[i][j];
                                if(j+1>=1 and j+1<=3)
                                {
                                    Q[i][j][a]=Q[i][j][a]+gamma*0.8*V[i][j+1];
                                }
                                else
                                {
                                    Q[i][j][a]+=gamma*0.8*V[i][j];
                                }
                                
                                //check for up and down conditions
                                
                                if(i+1>=1 and i+1<=3)
                                {
                                    Q[i][j][a]+=gamma*0.1*V[i+1][j];
                                }
                                else
                                {
                                    Q[i][j][a]+=gamma*0.1*V[i][j];
                                }
                                
                                if(i-1>=1 and i-1<=3)
                                {
                                    Q[i][j][a]+=gamma*0.1*V[i-1][j];
                                }
                                else
                                {
                                    Q[i][j][a]+=gamma*0.1*V[i][j];
                                }
                                
                                if(Q[i][j][a]>maxQ)
                                {
                                    maxQ=Q[i][j][a];
                                    maxQindex=a;
                                }
                                break;
                                
                              
                    }
                }
                    //Now done with checking all the actions . Now time for updating the max Q to V and the Policy
                    V[i][j]=maxQ;
                    Policy[i][j]=maxQindex;
                    //cout<<"i="<<i<<" j= "<<j<<" and Q is \n";
                    //printQ(i,j);
                    //cout<<"\n";
            }
        }
        //cout<<"iteration "<<l<<" policy is \n";
        //printV();
        //cout<<"\n";
        //printPolicy();
        //cout<<"\n\n\n";
        
    }
}


int main()
{
    double r[4];
    int i,j;
    r[0]=100.0;
    r[1]=-3.0;
    r[2]=0;
    r[3]=3.0;
    double gamma=0.9;
    for(i=0;i<4;i++)
    {
        printf("Now doing Value Iteration with r=%lf\n",r[i]);
        initialize(r[i]);
        valueIteration(gamma);
        printf("The poilicy for r=%lf is \n",r[i]);
        printPolicy();
        
        //cout<<"the V is \n\n";
        //printV();
        cout<<"\n\n";
        
    }
    return 0;
}
