
 #include <bits/stdc++.h>
 using namespace std;
 double tavg=0.0,wavg=0.0;
 const int tcnst=4;
  void input(int a[],int b[],int n)
 {
   cout << "Enter arrival time of process"  << endl;
   for(int i=0;i<n;i++)
   {
       cin >> a[i];
   }
   cout << "Enter burst time of process"  << endl;

   for(int i=0;i<n;i++)
   {
       cin >> b[i];
   }
 }
 void waitingTime(int a[],int b[],int c[],int w[],int n)
 {
     //computing completion time;
        int rt[n+1]={0};
        for(int i=0;i<n;i++)
        {
            rt[i]=b[i];
        }
        deque <int> d;
        int procnt=0;
          int time=0;
          int k=-1;
        bool vis[n]={false};
        while(procnt<n)
       {
             for(int i=0;i<n;i++)
              {
                 if(a[i]<=time&&rt[i]>0&&!vis[i])
                 {
                     vis[i]=true;
                     d.push_back(i);
                 }
              }
              if(k!=-1)
                d.push_back(k);
             if(d.size()>0)
             {
                 int j=d.front();
                 d.pop_front();
               if(rt[j]>tcnst)
                {
                 rt[j]-=tcnst;
                 time+=tcnst;
                  k=j;
                }
                else
                {
                  time+=rt[j];
                  c[j]=time;
                  w[j]=c[j]-a[j]-b[j];
                  wavg+=w[j];
                  rt[j]=0;
                  k=-1;
                  procnt++;
                }
             }
             else
             {
                time+=1;
             }
     }
 }
 void turnaroundTime(int b[],int w[],int t[],int n)
{
    for(int i=0;i<n;i++)
   {
     t[i]=w[i]+b[i];
     tavg+=t[i];
   }
}
void output(int c[],int w[],int t[],int n)
{
    cout << "Completion     Waiting time    " << "Turnaround Time" << endl ;
    for(int i=0;i<n;i++)
      {
          cout << c[i] << "                  "<< w[i] << "                   " << t[i] << endl;
       }

}
 int main()
 {
   cout << "Enter no of process" << endl;
   int n;
   cin >> n;
   int a[n],b[n],c[n],w[n],t[n];
   input(a,b,n);
   waitingTime(a,b,c,w,n);
   turnaroundTime(b,w,t,n);
   tavg=tavg/(double)n;
   wavg=wavg/(double)n;
   output(c,w,t,n);
   cout << "Average Waiting Time "  <<  wavg << endl;
   cout << "Average Turnaround Time "  <<  tavg << endl;


 }

