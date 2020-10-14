#include <bits/stdc++.h>
using namespace std;

bool sortbysecdesc(const pair<string,long> &a, const pair<string,long> &b)
{
    return a.second>b.second;
}
int main()
{
    long n,m;
    cin>>n>>m;
    long i,j;
    string a,b;
    map<string,string> mp;
    map<string,long> m1;
    map<string,long> m2;
    map<string,string>::iterator itr;
    map<string,long>::iterator itr1,itr2;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        mp.insert(pair<string, string>(a,b));
    }
    for(i=0;i<m;i++)
    {
        cin>>a;
        if(m1.find(a)==m1.end())
        {
            m1.insert(pair<string, long>(a,1));
            //c++;
            itr=mp.find(a);
            b=itr->second;
            if(m2.find(b)==m2.end())
            {
                m2.insert(pair<string,long>(b,1));
              //  d++;
            }
            else
            {
                itr2=m2.find(b);
                itr2->second++;
            }
        }
        else
        {
            itr1=m1.find(a);
            itr1->second++;
            itr=mp.find(a);
            b=itr->second;
            itr2=m2.find(b);
            itr2->second++;
        }
    }
    vector<pair<string,long> > vp1,vp2;
    copy(m1.begin(),m1.end(),back_inserter(vp1));
    copy(m2.begin(),m2.end(),back_inserter(vp2));
    sort(vp1.begin(),vp1.end(),sortbysecdesc);
    sort(vp2.begin(),vp2.end(),sortbysecdesc);
    vector<pair<string,long> >:: iterator itr3;
    /*i=0;
    cout<<"vp1"<<endl;
    for(itr3=vp1.begin();itr3!=vp1.end();itr3++)
    {
        cout<<vp1[i].first<<" "<<vp1[i].second<<endl;
        i++;
    }
    cout<<"vp2"<<endl;
    i=0;
    for(itr3=vp2.begin();itr3!=vp2.end();itr3++)
    {
        cout<<vp2[i].first<<" "<<vp2[i].second<<endl;
        i++;
    }*/
    long min=vp2[0].second;
    set <string> s;
    i=0;
    for(itr3=vp2.begin();itr3!=vp2.end();itr3++)
    {
        if(min==vp2[i].second)
        {
            s.insert(vp2[i].first);
        }
        else
            break;
    }
    cout<<*(s.begin())<<endl;
    s.clear();
    i=0;
    min=vp1[0].second;
    for(itr3=vp1.begin();itr3!=vp1.end();itr3++)
    {
        if(min==vp1[i].second)
        {
            s.insert(vp1[i].first);
        }
        else
            break;
    }
    cout<<*(s.begin())<<endl;
    /*cout<<vp2[0].first<<" "<<vp2[0].second<<endl;
    cout<<vp1[0].first<<" "<<vp1[0].second<<endl;*/
	return 0;
}
