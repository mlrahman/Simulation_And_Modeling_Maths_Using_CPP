#include <bits/stdc++.h>
#define ll long
#define pb push_back
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<ll>inter_at,ser_dur,arr_t,dep_t,event_time,c_queue;
    vector<string>event_type,server_status;
    ll n,data;
    cin>>n;
    ll sum=0;

    for(ll i=0;i<n;i++)
    {
        cin>>data;
        sum+=data;
        arr_t.pb(sum);
        inter_at.pb(data);
    }
    for(ll i=0;i<n;i++)
    {
        cin>>data;
        ser_dur.pb(data);
    }


    for(ll i=0;i<n;i++)
    {
        if(i==0)
        {
            data=arr_t[i]+ser_dur[i];
            dep_t.pb(data);
        }
        else
        {
            if(dep_t[i-1]>arr_t[i])
            {
                data=arr_t[i]+ser_dur[i]+(dep_t[i-1]-arr_t[i]);
                dep_t.pb(data);
            }
            else
            {
                data=arr_t[i]+ser_dur[i];
                dep_t.pb(data);
            }
        }
    }
    ll index1=0,index2=0,i=0;
    if(arr_t[index1]==0)
    {
        event_time.pb(0);
        event_type.pb("Arrival");
        c_queue.pb(0);
        server_status.pb("Busy");
        index1++;
    }
    else
    {
        event_time.pb(0);
        event_type.pb("None");
        c_queue.pb(0);
        server_status.pb("Idle");
    }
    i++;
    while(true)
    {
        if(index1>=n && index2>=n) break;
        if(arr_t[index1]<dep_t[index2])
        {
            event_time.pb(arr_t[index1]);
            event_type.pb("Arrival");
            if(server_status[i-1]=="Busy")
            {
                c_queue.pb(c_queue[i-1]+1);
                server_status.pb("Busy");
            }
            else if(server_status[i-1]=="Idle" || server_status[i-1]=="None")
            {
                c_queue.pb(c_queue[i-1]);
                server_status.pb("Busy");
            }
            index1++;
        }
        else if(dep_t[index2]<=arr_t[index1])
        {
            event_time.pb(dep_t[index2]);
            event_type.pb("Departure");
            if(c_queue[i-1]>0)
            {
                c_queue.pb(c_queue[i-1]-1);
                server_status.pb("Busy");
            }
            else
            {
                c_queue.pb(c_queue[i-1]);
                server_status.pb("Idle");
            }
            index2++;
        }
        i++;
    }

    cout<<"----------------------------------------------------"<<endl;
    cout<<"|             Arrival Departure Routine            |"<<endl;
    cout<<"----------------------------------------------------"<<endl<<endl;

    cout<<"Customer No -----> CN"<<endl;
    cout<<"Inter Arrival Time -----> IAT"<<endl;
    cout<<"Arrival Time(Clock) -----> AT"<<endl;
    cout<<"Service Duration -----> SD"<<endl;
    cout<<"Departure Time(Clock) -----> DT"<<endl<<endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"| CN ----- IAT ----- AT ----- SD ----- DT |"<<endl;
    cout<<"-------------------------------------------"<<endl;
    for(ll i=0;i<n;i++)
    {
        cout<<"   "<<i+1<<" ----- ";
        cout<<inter_at[i]<<" ----- ";
        cout<<arr_t[i]<<" ----- ";
        cout<<ser_dur[i]<<" ----- ";
        cout<<dep_t[i]<<"\n";
    }
    cout<<"-------------------------------------------"<<endl<<endl<<endl<<endl<<endl<<endl<<endl;


    cout<<"----------------------------------------------------"<<endl;
    cout<<"|                Time History Graph                |"<<endl;
    cout<<"----------------------------------------------------"<<endl<<endl;

    cout<<"Event No -----> EN"<<endl;
    cout<<"Event Time(Clock) -----> ETi"<<endl;
    cout<<"Event Type -----> ETy"<<endl;
    cout<<"No of Customer in Queue -----> NCQ"<<endl;
    cout<<"Server's Status -----> SS"<<endl<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"| EN ------- ETi ------- ETy ------- NCQ ------- SS |"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    for(ll i=0;i<event_time.size();i++)
    {
        cout<<"   "<<i+1<<" ----- ";
        cout<<event_time[i]<<" ----- ";
        cout<<event_type[i]<<" ----- ";
        cout<<c_queue[i]<<" ----- ";
        cout<<server_status[i]<<"\n";
    }
    cout<<"------------------------------------------------------"<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

    cout<<"-------------------------------------------------------"<<endl;
    cout<<"|                Simulation Statistics                |"<<endl;
    cout<<"-------------------------------------------------------"<<endl<<endl;

    cout<<"Inter Event Time -----> IET"<<endl;
    cout<<"Customers in Queue -----> CIQ"<<endl;
    cout<<"Server's Utilization -----> SUt"<<endl<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout<<"|        IET ------- CIQ ------- SUt        |"<<endl;
    cout<<"---------------------------------------------"<<endl;
    ll t1=0,t2=0,t3=0;
    for(ll i=0;i<event_time.size()-1;i++)
    {
        cout<<"   "<<event_time[i+1]<<" - "<<event_time[i]<<" = "<<event_time[i+1]-event_time[i]<<" ----- ";
        t1+=event_time[i+1]-event_time[i];
        cout<<event_time[i+1]-event_time[i]<<" x "<<c_queue[i]<<" = "<<((event_time[i+1]-event_time[i])*c_queue[i])<<" ----- ";
        t2+=((event_time[i+1]-event_time[i])*c_queue[i]);
        if(server_status[i]=="Busy")
            data=1;
        else
            data=0;
        cout<<event_time[i+1]-event_time[i]<<" x "<<data<<" = "<<((event_time[i+1]-event_time[i])*data)<<endl;
        t3+=((event_time[i+1]-event_time[i])*data);
    }
    cout<<"----------------------------------------------"<<endl;
    cout<<"Total: "<<t1<<" ----- "<<t2<<" ----- "<<t3<<endl<<endl<<endl;

    float x=(t2*1.0/t1*1.0);
    cout<<"The Average no of customers in queue: "<<setprecision(4)<<x<<" Per Minute."<<endl<<endl;
    float y=((t3*1.0)/(t1*1.0))*100.0;
    cout<<"The Average no of customers in queue: "<<setprecision(4)<<y<<" %."<<endl<<endl;

}
