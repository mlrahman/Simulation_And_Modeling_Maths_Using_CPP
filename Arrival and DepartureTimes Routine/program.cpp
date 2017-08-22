#include <bits/stdc++.h>
#define ll long
#define pb push_back
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<ll>inter_at,ser_dur,arr_t,dep_t;
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
    return 0;
}
