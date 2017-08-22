#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll month,n,m,data,s,S,inventory,h_cost,ba_cost,z,k;
    cin>>inventory;
    cin>>s>>S;
    cin>>n;
    vector<ll>Di,Pi,Ai,event_time,event_size,oa_time,n_time,inventory_level,oi_time,s_event;
    for(ll i=0;i<n;i++)
    {
        cin>>data;
        Di.pb(data);
    }
    for(ll i=0;i<n;i++)
    {
        cin>>data;
        Pi.pb(data);
    }
    cin>>m;
    for(ll i=0;i<m;i++)
    {
        cin>>data;
        Ai.pb(data);
    }
    cin>>month;
    month*=30;
    cin>>h_cost>>ba_cost;
    cin>>z>>k;
    vector<string>event_type;
    //Initially
    ll i=1;
    ll index=0,month_count=0,oa=0,oa_index=0,os=0,ssss,eeee;
    if(inventory<s)
    {
        oi_time.pb(0);
        event_time.pb(0);
        event_type.pb("OI");
        if(inventory<0)
        {
            event_size.pb(S);
            ssss=S;
        }
        else
        {
            event_size.pb(S-inventory);
            ssss=S-inventory;
        }
        inventory_level.pb(inventory);
        if(oa_index<Ai.size())
        {
            oa=0+Ai[oa_index];
            os=ssss;
            oa_index++;
        }
    }
    else
    {
        n_time.pb(0);
        event_time.pb(0);
        event_type.pb("None");
        event_size.pb(0);
        inventory_level.pb(inventory);
    }
    while(true)
    {
        if(index>=n) break;
        if((event_time[i-1]+Di[index])>oa && oa!=0)
        {
            event_time.pb(event_time[i-1]);
            oa_time.pb(oa);
            event_type.pb("OA");
            event_size.pb(os);
            inventory_level.pb(inventory_level[i-1]+os);
            oa=0;
            os=0;
        }
        else if((event_time[i-1]+Di[index])==oa && oa!=0)
        {
            event_time.pb(event_time[i-1]+Di[index]);
            event_type.pb("D");
            event_size.pb(Pi[index]);
            inventory_level.pb(inventory_level[i-1]-Pi[index]);
            i++;

            event_time.pb(event_time[i-1]);
            oa_time.pb(oa);
            event_type.pb("OA");
            event_size.pb(os);
            inventory_level.pb(inventory_level[i-1]+os);
            index++;
            oa=0;
            os=0;
        }
        else if((event_time[i-1]+Di[index])%30==0)
        {
            month_count++;
            event_time.pb((event_time[i-1]+Di[index]));
            event_type.pb("D");
            event_size.pb(Pi[index]);
            inventory_level.pb(inventory_level[i-1]-Pi[index]);
            i++;
            if(inventory_level[i-1]<s)
            {
                oi_time.pb(event_time[i-1]);
                event_time.pb(event_time[i-1]);
                event_type.pb("OI");
                if(inventory_level[i-1]<0)
                {
                    event_size.pb(S);
                    ssss=S;
                }
                else
                {
                    event_size.pb(S-inventory_level[i-1]);
                    ssss=S-inventory_level[i-1];
                }
                inventory_level.pb(inventory_level[i-1]);
                if(oa_index<Ai.size())
                {
                    oa=event_time[i-1]+Ai[oa_index];
                    os=ssss;
                    oa_index++;
                }
            }
            else
            {
                n_time.pb(event_time[i-1]);
                event_time.pb(event_time[i-1]);
                event_type.pb("None");
                event_size.pb(0);
                inventory_level.pb(inventory_level[i-1]);
            }
            index++;
        }
        else if(((event_time[i-1]+Di[index])/30)>month_count)
        {
            month_count++;
            if(inventory_level[i-1]<s)
            {
                oi_time.pb(month_count*30);
                event_time.pb(event_time[i-1]);
                event_type.pb("OI");

                if(inventory_level[i-1]<0)
                {
                    event_size.pb(S);
                    ssss=S;
                }
                else
                {
                    event_size.pb(S-inventory_level[i-1]);
                    ssss=S-inventory_level[i-1];
                }

                inventory_level.pb(inventory_level[i-1]);
                if(oa_index<Ai.size())
                {
                    oa=(month_count*30)+Ai[oa_index];
                    os=ssss;
                    oa_index++;
                }
            }
            else
            {
                n_time.pb(month_count*30);
                event_time.pb(event_time[i-1]);
                event_type.pb("None");
                event_size.pb(0);
                inventory_level.pb(inventory_level[i-1]);
            }
        }
        else
        {
            event_time.pb((event_time[i-1]+Di[index]));
            event_type.pb("D");
            event_size.pb(Pi[index]);
            inventory_level.pb(inventory_level[i-1]-Pi[index]);
            index++;
        }
        i++;
    }
    cout<<"-------------------------------------------------------"<<endl;
    cout<<"|                   Inventory System                  |"<<endl;
    cout<<"-------------------------------------------------------"<<endl<<endl;

    cout<<"Event Time -----> ETi"<<endl;
    cout<<"Event Type -----> ETy"<<endl;
    cout<<"Event Size -----> ESi"<<endl;
    cout<<"Inventory Level -----> IL"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"|   ETi ------- ETy ------- ESi ------- IL   |"<<endl;
    cout<<"----------------------------------------------"<<endl;
    ll ind=0,ind2=0,ind3=0;
    vector<ll>store;
    for(ll i=0;i<event_time.size();i++)
    {
        if(event_type[i]=="OI")
        {
            cout<<"   "<<oi_time[ind2]<<" ----- ";
            s_event.pb(oi_time[ind2++]);
            store.pb(event_size[i]);
        }
        else if(event_type[i]=="OA")
        {
            cout<<"   "<<oa_time[ind]<<" ----- ";
            s_event.pb(oa_time[ind++]);
        }
        else if(event_type[i]=="None")
        {
            cout<<"   "<<n_time[ind3]<<" ----- ";
            s_event.pb(n_time[ind3++]);
        }
        else
        {
            cout<<"   "<<event_time[i]<<" ----- ";
            s_event.pb(event_time[i]);
        }
        cout<<event_type[i]<<" ----- ";
        cout<<event_size[i]<<" ----- ";
        cout<<inventory_level[i]<<endl;
    }
    cout<<"----------------------------------------------"<<endl<<endl<<endl<<endl<<endl<<endl;


    cout<<"------------------------------------------------------------"<<endl;
    cout<<"|                   Simulation Statistics                  |"<<endl;
    cout<<"------------------------------------------------------------"<<endl<<endl;

    cout<<"Event Duration (Day) -----> ED"<<endl;
    cout<<"Time total no. of Items in Positive Inventory -----> TPI"<<endl;
    cout<<"Time total no. of Items in Backlog -----> TIB"<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<"|        ED  -------  TPI  -------  TIB       |"<<endl;
    cout<<"-----------------------------------------------"<<endl;
    ll t1=0,t2=0,t3=0;
    for(ll i=1;i<s_event.size();i++)
    {
        cout<<"    "<<s_event[i]<<" - "<<s_event[i-1]<<" = "<<s_event[i]-s_event[i-1]<<" ----- ";
        t1+=s_event[i]-s_event[i-1];
        if(inventory_level[i-1]>=0)
        {
            cout<<inventory_level[i-1]<<" x "<<s_event[i]-s_event[i-1]<<" = "<<inventory_level[i-1]*(s_event[i]-s_event[i-1])<<" ----- ";
            cout<<"0 x "<<s_event[i]-s_event[i-1]<<" = 0 "<<endl;
            t2+=inventory_level[i-1]*(s_event[i]-s_event[i-1]);
        }
        else
        {
            cout<<"0 x "<<s_event[i]-s_event[i-1]<<" = 0 ----- ";
            cout<<inventory_level[i-1]*-1<<" x "<<s_event[i]-s_event[i-1]<<" = "<<inventory_level[i-1]*(s_event[i]-s_event[i-1])*(-1)<<endl;
            t3+=inventory_level[i-1]*(s_event[i]-s_event[i-1])*(-1);
        }
        if(s_event[i]==month)
            break;
    }
    cout<<"-----------------------------------------------"<<endl;
    cout<<"Total: "<<t1<<" ----- "<<t2<<" ----- "<<t3<<endl<<endl<<endl;
    double II=((t2*1.0)/((month*1.0)/30.0)),III=((t3*1.0)/((month*1.0)/30.0)),H=II*h_cost,Ba=III*ba_cost;
    cout<<"Time Average no of items in Positive Inventory, I+ = "<<fixed<<setprecision(3)<<II<<" Per Month"<<endl<<endl;
    cout<<"Time Average no of items in Negative Inventory, I- = "<<fixed<<setprecision(3)<<III<<" Per Month"<<endl<<endl<<endl<<endl;
    cout<<"Total Holding Cost, H = "<<H<<" Taka"<<endl<<endl;
    cout<<"Total Backlog Cost, B = "<<Ba<<" Taka"<<endl<<endl<<endl<<endl;
    ll total=0;
    for(i=0;i<store.size();i++)
    {
        cout<<"Cost for Order "<<i+1<<":  C"<<i+1<<" = "<<k<<" + ("<<store[i]<<" x "<<z<<")"<<endl;
        cout<<"                      = "<<k+(store[i]*z)<<endl<<endl;
        total+=(k+(store[i]*z));
    }
    cout<<"Total Ordering Cost = "<<total<<endl<<endl;

}
