#include<bits/stdc++.h>
using namespace std;

/*
    Incorrect Solution

*/


void printVect(vector<pair<int,int>>);
int solve(vector<pair<int,int>>,int,int,int);

int main(){

    int tc;cin>>tc;

    for(int te=0;te<tc;te++){
        int n,x,y,p,q,a,b,r,s,h1,m1,h2,m2,hours,minutes;
        cin>>n;
        char ch;
        vector<pair<int,int>> friends;

        cin>>x>>ch>>y;  //  in-time
        cin>>p>>ch>>q;  //  wake up time
        cin>>a>>ch>>b;  //  store_opening time
        cin>>r;         // travel time
        cin>>s;         // shopping time

        int turnAroundTime = 2*r + s;   // in minutes

        int intime = x*100+y;
        int wakeup = p*100+q;
        int store_opening = a*100+b;

        hours = r/60;
        minutes = r%60;

        int temp_minutes = b;
        int temp_hours = a;



        int leave_minutes = 0;
        int leave_hours= 0;
        int leaving_time =  0;

        int return_time = 0;


        if(wakeup == store_opening){

                leave_minutes = y;
                leave_hours = x;
                leaving_time =  leave_hours*100 + leave_minutes;




        }else if(wakeup < store_opening ){

            int time_to_reach = hours*100 + minutes;

            if((wakeup+time_to_reach) <= store_opening){

                    temp_minutes = b;
                    temp_hours = a;

                    if(temp_minutes<minutes){
                        temp_minutes+=60;
                        temp_hours--;
                    }

                    leave_minutes = temp_minutes-minutes;
                    leave_hours= temp_hours-hours;
                    leaving_time =  leave_hours*100 + leave_minutes;

            }

        }else{  // wakeup > store_opening

            leave_minutes = q;
            leave_hours= p;
            leaving_time =  leave_hours*100 + leave_minutes;

        }


        int shopping_time = r+s+r;
        hours = shopping_time/60;
        minutes = shopping_time%60;

        int ret_minutes = minutes + leave_minutes;
        int ret_hours = leave_hours+hours;

        if(ret_minutes >= 60){
            ret_minutes -= 60;
            ret_hours++;
        }

        return_time = ret_hours*100+ret_minutes;



        //cout<<"Return Time " <<return_time<<endl;




        for(int i=0;i<n;i++){
            cin>>h1>>ch>>m1;
            cin>>h2>>ch>>m2;

            int use_st = h1*100+m1;
            int use_end = h2*100+m2;

            friends.push_back(make_pair(use_st,use_end));
        }

       // printVect(friends);
        int ans = solve(friends,return_time,intime,turnAroundTime);
        cout<<"Case "<<(te+1)<<": "<<ans<<endl;
    }
}

int solve(vector<pair<int,int>> vect,int return_time,int intime,int turnAroundTime){

    int len = vect.size();
    int ans = -1;

    for(int i=0;i<len;i++){
        int use_st = vect[i].first;
        if(return_time < use_st){
            ans = i+1;
            break;
        }
    }



    if(ans==-1){

         for(int i=0;i<len;i++){

            int use_end = vect[i].second;

            int temp_hours = use_end/100;
            int temp_minutes = use_end%100;

            int hours = turnAroundTime/60;
            int minutes = turnAroundTime%60;

            int finish_hours = hours + temp_hours;
            int finish_minutes = temp_minutes+minutes;

            if(finish_minutes >= 60){
                finish_minutes -= 60;
                finish_hours++;
            }

            int finish_time = finish_hours*100+finish_minutes;

            if(finish_time <= intime){
                ans = i+1;
                break;
            }

        }

    }


    return ans;

}

void printVect(vector<pair<int,int>> vect){

    int len = vect.size();

    for(int i=0;i<len;i++){
        cout<<vect[i].first<<" "<<vect[i].second<<endl;
    }

}
