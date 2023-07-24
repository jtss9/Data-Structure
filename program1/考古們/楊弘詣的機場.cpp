#include<iostream>
#include<vector> 
#include<cstdlib>
#include<ctime>
using namespace std;
typedef struct airport airport;
struct airport {
	vector< vector<int> > landing;//vector中的單位為vector l
	vector< vector<int> > landing_force;
	vector< vector<int> > takeoff;
};
int min(int w,int x,int y,int z){
	int mini;
	mini=w;
	if(mini>x){
		mini=x;
	}
	if(mini>y){
		mini=y;
	}
	if(mini>z){
		mini=z;
	}
	return mini;
}
int main(){
	int time_total;
	cout<<"How many time unit you want to simulate: ";
	cin>>time_total;
	airport runway_1;
	airport runway_2;
	airport runway_3;
	airport runway_4;
	vector<int> row;
	runway_1.landing_force.assign(2,row);//vector中加入兩個vector形成類似2*n的陣列 
	runway_1.takeoff.assign(2,row);
	runway_2.landing.assign(2,row);
	runway_2.landing_force.assign(2,row);
	runway_2.takeoff.assign(2,row);
	runway_3.landing.assign(2,row);
	runway_3.landing_force.assign(2,row);
	runway_3.takeoff.assign(2,row);
	runway_4.landing.assign(2,row);
	runway_4.landing_force.assign(2,row);
	runway_4.takeoff.assign(2,row);
	srand( time(NULL) );//以現在時間做亂數種子
	int landing_ID=1;
	int takeoff_ID=0;
	int crash_amount=0;
	int landing_before_total=0;
	int landing_after_total=0;
	int takeoff_before_total=0;
	int takeoff_after_total=0;
	int landingforce_amount=0;
	double plane_landing_amount=0;
	double plane_takeoff_amount=0;
	int time_unit=1;
	for(;time_unit<=time_total;time_unit++){ 
		int landing_amount=rand()%(5);
		int takeoff_amount=rand()%(4);
		plane_landing_amount=plane_landing_amount+landing_amount;
		plane_takeoff_amount=plane_takeoff_amount+takeoff_amount;
		
		for(int c=0;c<runway_2.landing[1].size();c++){
			runway_2.landing[1][c]--;
		}
		for(int c=0;c<runway_3.landing[1].size();c++){
			runway_3.landing[1][c]--;
		}
		for(int c=0;c<runway_4.landing[1].size();c++){
			runway_4.landing[1][c]--;
		}
		for(int d=1;d<=landing_amount;d++){
			int fuel_level=rand()%(10)+1;
			landing_before_total=landing_before_total+fuel_level;
			if(time_unit%2==1&&d==1){
				runway_2.landing[0].push_back(landing_ID);
				runway_2.landing[1].push_back(fuel_level);
				landing_ID+=2;
				cout<<"T = "<<time_unit<<",  (run2)landing_ID = "<<runway_2.landing[0].back()<<",  fuel level = "<<runway_2.landing[1].back()<<endl;
			}else if(time_unit%2==1&&d==2){
				runway_3.landing[0].push_back(landing_ID);
				runway_3.landing[1].push_back(fuel_level);
				landing_ID+=2;
				cout<<"T = "<<time_unit<<",  (run3)landing_ID = "<<runway_3.landing[0].back()<<",  fuel level = "<<runway_3.landing[1].back()<<endl;
			}else if(time_unit%2==1&&d==3){
				runway_4.landing[0].push_back(landing_ID);
				runway_4.landing[1].push_back(fuel_level);
				landing_ID+=2;
				cout<<"T = "<<time_unit<<",  (run4)landing_ID = "<<runway_4.landing[0].back()<<",  fuel level = "<<runway_4.landing[1].back()<<endl;
			}else if(time_unit%2==0&&d==1){
				runway_4.landing[0].push_back(landing_ID);
				runway_4.landing[1].push_back(fuel_level);
				landing_ID+=2;
				cout<<"T = "<<time_unit<<",  (run4)landing_ID = "<<runway_4.landing[0].back()<<",  fuel level = "<<runway_4.landing[1].back()<<endl;
			}else if(time_unit%2==0&&d==2){
				runway_3.landing[0].push_back(landing_ID);
				runway_3.landing[1].push_back(fuel_level);
				landing_ID+=2;
				cout<<"T = "<<time_unit<<",  (run3)landing_ID = "<<runway_3.landing[0].back()<<",  fuel level = "<<runway_3.landing[1].back()<<endl;
			}else if(time_unit%2==0&&d==3){
				runway_2.landing[0].push_back(landing_ID);
				runway_2.landing[1].push_back(fuel_level);
				landing_ID+=2;
				cout<<"T = "<<time_unit<<",  (run2)landing_ID = "<<runway_2.landing[0].back()<<",  fuel level = "<<runway_2.landing[1].back()<<endl;
			}
		}
		
		for(int d=1;d<=takeoff_amount;d++){
			takeoff_before_total=takeoff_before_total+time_unit;
			int m=min(runway_1.takeoff[0].size(),runway_2.landing[0].size()+runway_2.takeoff[0].size(),runway_3.landing[0].size()+runway_3.takeoff[0].size(),runway_4.landing[0].size()+runway_4.takeoff[0].size());
			if(m==runway_1.takeoff[0].size()){
				runway_1.takeoff[0].push_back(takeoff_ID);
				takeoff_ID+=2;
				cout<<"T = "<<time_unit<<",  (run1)takeoff_ID = "<<runway_1.takeoff[0].back()<<endl;
			}else if(m==runway_2.landing[0].size()+runway_2.takeoff[0].size()){
				runway_2.takeoff[0].push_back(takeoff_ID);
				takeoff_ID+=2;
				cout<<"T = "<<time_unit<<",  (run2)takeoff_ID = "<<runway_2.takeoff[0].back()<<endl;
			}else if(m==runway_3.landing[0].size()+runway_3.takeoff[0].size()){
				runway_3.takeoff[0].push_back(takeoff_ID);
				takeoff_ID+=2;
				cout<<"T = "<<time_unit<<",  (run3)takeoff_ID = "<<runway_3.takeoff[0].back()<<endl;
			}else if(m==runway_4.landing[0].size()+runway_4.takeoff[0].size()){
				runway_4.takeoff[0].push_back(takeoff_ID);
				takeoff_ID+=2;
				cout<<"T = "<<time_unit<<",  (run4)takeoff_ID = "<<runway_4.takeoff[0].back()<<endl;
			}
		}
		
		for(int c=0;c<runway_2.landing[0].size();c++){
			if(runway_2.landing[1][c]==0&&runway_1.landing_force[0].size()==0){//[][1]為油 [][0]為ID 
				runway_1.landing_force[0].push_back(runway_2.landing[0][c]);//從後面加入值
				runway_1.landing_force[1].push_back(runway_2.landing[1][c]);
				cout<<"T = "<<time_unit<<",  landing_force_ID = "<<runway_2.landing[0][c]<<" runway_1 "<<endl;
				runway_2.landing[0].erase(runway_2.landing[0].begin()+c,runway_2.landing[0].begin()+c+1);//erase(範圍)
				runway_2.landing[1].erase(runway_2.landing[1].begin()+c,runway_2.landing[1].begin()+c+1);
			}else if(runway_2.landing[1][c]==0&&runway_2.landing_force[0].size()==0){
				runway_2.landing_force[0].push_back(runway_2.landing[0][c]);
				runway_2.landing_force[1].push_back(runway_2.landing[1][c]);
				cout<<"T = "<<time_unit<<",  landing_force_ID = "<<runway_2.landing[0][c]<<" runway_2 "<<endl;
				runway_2.landing[0].erase(runway_2.landing[0].begin()+c,runway_2.landing[0].begin()+c+1);
				runway_2.landing[1].erase(runway_2.landing[1].begin()+c,runway_2.landing[1].begin()+c+1);
			}else if(runway_2.landing[1][c]==0&&runway_3.landing_force[0].size()==0){
				runway_3.landing_force[0].push_back(runway_2.landing[0][c]);
				runway_3.landing_force[1].push_back(runway_2.landing[1][c]);
				cout<<"T = "<<time_unit<<",  landing_force_ID = "<<runway_2.landing[0][c]<<" runway_3 "<<endl;
				runway_2.landing[0].erase(runway_2.landing[0].begin()+c,runway_2.landing[0].begin()+c+1);
				runway_2.landing[1].erase(runway_2.landing[1].begin()+c,runway_2.landing[1].begin()+c+1);
			}else if(runway_2.landing[1][c]==0&&runway_4.landing_force[0].size()==0){
				runway_4.landing_force[0].push_back(runway_2.landing[0][c]);
				runway_4.landing_force[1].push_back(runway_2.landing[1][c]);
				cout<<"T = "<<time_unit<<",  landing_force_ID = "<<runway_2.landing[0][c]<<" runway_4 "<<endl;
				runway_2.landing[0].erase(runway_2.landing[0].begin()+c,runway_2.landing[0].begin()+c+1);
				runway_2.landing[1].erase(runway_2.landing[1].begin()+c,runway_2.landing[1].begin()+c+1);
			}else if(runway_2.landing[1][c]==0){
				crash_amount++;
			}
		}
		for(int c=0;c<runway_3.landing[0].size();c++){
			if(runway_3.landing[1][c]==0&&runway_1.landing_force[0].size()==0){ 
				runway_1.landing_force[0].push_back(runway_3.landing[0][c]);
				runway_1.landing_force[1].push_back(runway_3.landing[1][c]);
				cout<<"T = "<<time_unit<<",  landing_force_ID = "<<runway_3.landing[0][c]<<" runway_1 "<<endl;
				runway_3.landing[0].erase(runway_3.landing[0].begin()+c,runway_3.landing[0].begin()+c+1);
				runway_3.landing[1].erase(runway_3.landing[1].begin()+c,runway_3.landing[1].begin()+c+1);
			}else if(runway_3.landing[1][c]==0&&runway_2.landing_force[0].size()==0){
				runway_2.landing_force[0].push_back(runway_3.landing[0][c]);
				runway_2.landing_force[1].push_back(runway_3.landing[1][c]);
				cout<<"T = "<<time_unit<<",  landing_force_ID = "<<runway_3.landing[0][c]<<" runway_2 "<<endl;
				runway_3.landing[0].erase(runway_3.landing[0].begin()+c,runway_3.landing[0].begin()+c+1);
				runway_3.landing[1].erase(runway_3.landing[1].begin()+c,runway_3.landing[1].begin()+c+1);
			}else if(runway_3.landing[1][c]==0&&runway_3.landing_force[0].size()==0){
				runway_3.landing_force[0].push_back(runway_3.landing[0][c]);
				runway_3.landing_force[1].push_back(runway_3.landing[1][c]);
				cout<<"T = "<<time_unit<<",  landing_force_ID = "<<runway_3.landing[0][c]<<" runway_3 "<<endl;
				runway_3.landing[0].erase(runway_3.landing[0].begin()+c,runway_3.landing[0].begin()+c+1);
				runway_3.landing[1].erase(runway_3.landing[1].begin()+c,runway_3.landing[1].begin()+c+1);
			}else if(runway_3.landing[1][c]==0&&runway_4.landing_force[0].size()==0){
				runway_4.landing_force[0].push_back(runway_3.landing[0][c]);
				runway_4.landing_force[1].push_back(runway_3.landing[1][c]);
				cout<<"T = "<<time_unit<<",  landing_force_ID = "<<runway_3.landing[0][c]<<" runway_4 "<<endl;
				runway_3.landing[0].erase(runway_3.landing[0].begin()+c,runway_3.landing[0].begin()+c+1);
				runway_3.landing[1].erase(runway_3.landing[1].begin()+c,runway_3.landing[1].begin()+c+1);
			}
			else if(runway_3.landing[1][c]==0){
				crash_amount++;
			}
		}
		for(int c=0;c<runway_4.landing[0].size();c++){
			if(runway_4.landing[1][c]==0&&runway_1.landing_force[0].size()==0){
				runway_1.landing_force[0].push_back(runway_4.landing[0][c]);
				runway_1.landing_force[1].push_back(runway_4.landing[1][c]);
				cout<<"T = "<<time_unit<<",  landing_force_ID = "<<runway_4.landing[0][c]<<" runway_1 "<<endl;
				runway_4.landing[0].erase(runway_4.landing[0].begin()+c,runway_3.landing[0].begin()+c+1);
				runway_4.landing[1].erase(runway_4.landing[1].begin()+c,runway_3.landing[1].begin()+c+1);
			}else if(runway_4.landing[1][c]==0&&runway_2.landing_force[0].size()==0){
				runway_2.landing_force[0].push_back(runway_4.landing[0][c]);
				runway_2.landing_force[1].push_back(runway_4.landing[1][c]);
				cout<<"T = "<<time_unit<<",  landing_force_ID = "<<runway_4.landing[0][c]<<" runway_2 "<<endl;
				runway_4.landing[0].erase(runway_4.landing[0].begin()+c,runway_3.landing[0].begin()+c+1);
				runway_4.landing[1].erase(runway_4.landing[1].begin()+c,runway_3.landing[1].begin()+c+1);
			}else if(runway_4.landing[1][c]==0&&runway_3.landing_force[0].size()==0){
				runway_3.landing_force[0].push_back(runway_4.landing[0][c]);
				runway_3.landing_force[1].push_back(runway_4.landing[1][c]);
				cout<<"T = "<<time_unit<<",  landing_force_ID = "<<runway_4.landing[0][c]<<" runway_3 "<<endl;
				runway_4.landing[0].erase(runway_4.landing[0].begin()+c,runway_3.landing[0].begin()+c+1);
				runway_4.landing[1].erase(runway_4.landing[1].begin()+c,runway_3.landing[1].begin()+c+1);
			}else if(runway_4.landing[1][c]==0&&runway_4.landing_force[0].size()==0){
				runway_4.landing_force[0].push_back(runway_4.landing[0][c]);
				runway_4.landing_force[1].push_back(runway_4.landing[1][c]);
				cout<<"T = "<<time_unit<<",  landing_force_ID = "<<runway_4.landing[0][c]<<" runway_4 "<<endl;
				runway_4.landing[0].erase(runway_4.landing[0].begin()+c,runway_3.landing[0].begin()+c+1);
				runway_4.landing[1].erase(runway_4.landing[1].begin()+c,runway_3.landing[1].begin()+c+1);
			}
			else if(runway_4.landing[1][c]==0){
				crash_amount++;
			}
		}
		if(runway_1.landing_force[0].size()==0){
			if(runway_1.takeoff[0].size()!=0){
				takeoff_after_total=takeoff_after_total+time_unit;
				cout<<"T = "<<time_unit<<",  (run1)takeoffing_ID = "<<runway_1.takeoff[0].front()<<endl;
				runway_1.takeoff[0].erase(runway_1.takeoff[0].begin(),runway_1.takeoff[0].begin()+1);//average takeoff time
			} 
		}else{
			runway_1.landing_force[0].erase(runway_1.landing_force[0].begin(),runway_1.landing_force[0].begin()+1);
			runway_1.landing_force[1].erase(runway_1.landing_force[1].begin(),runway_1.landing_force[1].begin()+1);
		}
		if(runway_2.landing_force[0].size()==0){
			if(runway_2.landing[0].size()==0){
				if(runway_2.takeoff[0].size()!=0){
					takeoff_after_total=takeoff_after_total+time_unit;
					cout<<"T = "<<time_unit<<",  (run2)takeoffing_ID = "<<runway_2.takeoff[0].front()<<endl;
					runway_2.takeoff[0].erase(runway_2.takeoff[0].begin(),runway_2.takeoff[0].begin()+1);//average takeoff time
				}
			}else{
				landing_after_total=landing_after_total+runway_2.landing[1].front();
				runway_2.landing[0].erase(runway_2.landing[0].begin(),runway_2.landing[0].begin()+1);
				runway_2.landing[1].erase(runway_2.landing[1].begin(),runway_2.landing[1].begin()+1);
			}
		}else{
			runway_2.landing_force[0].erase(runway_2.landing_force[0].begin(),runway_2.landing_force[0].begin()+1);
			runway_2.landing_force[1].erase(runway_2.landing_force[1].begin(),runway_2.landing_force[1].begin()+1);
		}
		if(runway_3.landing_force[0].size()==0){
			if(runway_3.landing[0].size()==0){
				if(runway_3.takeoff[0].size()!=0){
					takeoff_after_total=takeoff_after_total+time_unit;
					cout<<"T = "<<time_unit<<",  (run3)takeoffing_ID = "<<runway_3.takeoff[0].front()<<endl;
					runway_3.takeoff[0].erase(runway_3.takeoff[0].begin(),runway_3.takeoff[0].begin()+1);//average takeoff time
				}
			}else{
				landing_after_total=landing_after_total+runway_3.landing[1].front();
				runway_3.landing[0].erase(runway_3.landing[0].begin(),runway_3.landing[0].begin()+1);
				runway_3.landing[1].erase(runway_3.landing[1].begin(),runway_3.landing[1].begin()+1);
			}
		}else{
			runway_3.landing_force[0].erase(runway_3.landing_force[0].begin(),runway_3.landing_force[0].begin()+1);
			runway_3.landing_force[1].erase(runway_3.landing_force[1].begin(),runway_3.landing_force[1].begin()+1);
		}
		if(runway_4.landing_force[0].size()==0){
			if(runway_4.landing[0].size()==0){
				if(runway_4.takeoff[0].size()!=0){
					takeoff_after_total=takeoff_after_total+time_unit;
					cout<<"T = "<<time_unit<<",  (run4)takeoffing_ID = "<<runway_4.takeoff[0].front()<<endl;
					runway_4.takeoff[0].erase(runway_4.takeoff[0].begin(),runway_4.takeoff[0].begin()+1);//average takeoff time
				}
			}else{
				landing_after_total=landing_after_total+runway_4.landing[1].front();
				runway_4.landing[0].erase(runway_4.landing[0].begin(),runway_4.landing[0].begin()+1);
				runway_4.landing[1].erase(runway_4.landing[1].begin(),runway_4.landing[1].begin()+1);
			}
		}else{
			runway_4.landing_force[0].erase(runway_4.landing_force[0].begin(),runway_4.landing_force[0].begin()+1);
			runway_4.landing_force[1].erase(runway_4.landing_force[1].begin(),runway_4.landing_force[1].begin()+1);
		}
	}
	int remain_takeoff=runway_1.takeoff.size()+runway_2.takeoff.size()+runway_3.takeoff.size()+runway_4.takeoff.size();
	cout<<"average landing waiting time: "<<(landing_before_total-landing_after_total)/plane_landing_amount<<"(s)"<<endl;//use fuel level
	cout<<"average takeoff waiting time: "<<(takeoff_after_total-takeoff_before_total+remain_takeoff*time_total)/plane_takeoff_amount<<"(s)"<<endl;//use time unit
	cout<<"average fuel saved: "<<(landing_after_total)/plane_landing_amount<<endl;
	cout<<"total plane in emergency: "<<landingforce_amount<<endl;
	cout<<"total plane crashed: "<<crash_amount;
	return 0;
} 

