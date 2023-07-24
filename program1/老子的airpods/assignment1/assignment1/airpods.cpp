#include<iostream>
#include<time.h>
#include<deque>
using namespace std;
// r1   r2   r3   r4	runway
// 1    2 5  3 6  4 7	landing
// 1    2    3    4		takeoff
deque<int> LandingQueue[8], TakeoffQueue[5];
int choose[5], landing_num, takeoff_num, landing_plane[5], takeoff_plane[5], emergency_land = 0, crashed_amount = 0,
landing_id = 1, takeoff_id = 0, oil[10000];
double fuel = 0, fuel_remain = 0, waitingtime = 0, totallanding = 0, totaltakeoff = 0;
int emer[5] = { 0 };
//landing_num:0~4;	takeoff_num:0~3(4);		line 226¡B227
int min(int w, int x, int y, int z) {
	int mini, tmp;
	mini = w;
	tmp = 1;
	if (mini > x) {
		mini = x;
		tmp = 2;
	}
	if (mini > y) {
		mini = y;
		tmp = 3;
	}
	if (mini > z) {
		mini = z;
		tmp = 4;
	}
	if (tmp == 1)	return 1;
	else if (tmp == 2)	return 2;
	else if (tmp == 3) return 3;
	else if (tmp == 4) return 4;
}

void printqueue() {
	for (int i = 1; i <= 4; i++) {			//runway1-4
		cout << "Runway" << i << "(" << choose[i] << ")\n";
		cout << "L1:";
		for (int j = 0; j < LandingQueue[i].size(); j++) {
			cout << "(" << LandingQueue[i][j] << ", " << oil[LandingQueue[i][j]] << "), ";
		}
		cout << endl;
		cout << "L2:";
		for (int j = 0; j < LandingQueue[i+3].size(); j++) {
			if (i == 1)	break;
			cout << "(" << LandingQueue[i+3][j] << ", " << oil[LandingQueue[i+3][j]] << "), ";
		}
		cout << endl;
		cout << "T:";
		for (int j = 0;  j < TakeoffQueue[i].size(); j++) {
			cout << "(" << TakeoffQueue[i][j] << "), ";
		}
		cout << endl;
	}
	cout << "\n\n";
}
void print() {
	cout << "Step1:\n";
	cout << "Landing plane: ";
	for (int i = 1; i <= landing_num; i++) {
		cout << "(" << landing_plane[i] << ", " << oil[landing_plane[i]] << "), ";
	}
	cout << endl;
	for (int i = 1; i <= 4; i++) choose[i] = -1;
	for (int i = 2; i <= 1 + landing_num; i++) {
		int la = min(1000, LandingQueue[2].size() + LandingQueue[5].size() + TakeoffQueue[2].size(), LandingQueue[3].size() + LandingQueue[6].size() + TakeoffQueue[3].size(), LandingQueue[4].size() + LandingQueue[7].size() + TakeoffQueue[4].size());
		if (LandingQueue[la].size() > LandingQueue[la + 3].size())	la += 3;
		LandingQueue[la].push_back(landing_plane[i - 1]);
	}

	printqueue();

	cout << "Step2:\n";
	cout << "Takeoff plane: ";
	for (int i = 1; i <= takeoff_num; i++) {
		cout << "(" << takeoff_plane[i] << "), ";
	}
	cout << endl;
	if (takeoff_num >= 1) {
		TakeoffQueue[1].push_back(takeoff_plane[takeoff_num]);
		takeoff_num--;
	}
	for (int i = 1; i <=takeoff_num; i++) {
		int ta = 5 - min(LandingQueue[4].size() + LandingQueue[7].size() + TakeoffQueue[4].size(), LandingQueue[3].size() + LandingQueue[6].size() + TakeoffQueue[3].size(), LandingQueue[2].size() + LandingQueue[5].size() + TakeoffQueue[2].size(), TakeoffQueue[1].size());
		TakeoffQueue[ta].push_back(takeoff_plane[i]);
	}
	printqueue();
	int emer_land[5] = { 0 };
	cout << "Step3:\n";
	cout << "Emergency plane: ";
	for (int i = 2; i <= 7; i++) {
		for (int j = 0; j < LandingQueue[i].size(); j++) {
			if (oil[LandingQueue[i][j]] <= 0) {
				if (emer_land[1]) {
					if (emer_land[2]) {
						if (emer_land[3]) {
							if (emer_land[4]) {
								crashed_amount++;
							}
							else {
								LandingQueue[4].push_front(LandingQueue[i][j]);
								emer_land[4] = 1;
								emer[4]++;
							}
						}
						else {
							LandingQueue[3].push_front(LandingQueue[i][j]);
							emer_land[3] = 1;
							emer[3]++;
						}
					}
					else {
						LandingQueue[2].push_front(LandingQueue[i][j]);
						emer_land[2] = 1;
						emer[2]++;
					}
				}
				else {
					LandingQueue[1].push_back(LandingQueue[i][j]);
					emer_land[1] = 1;
					emer[1]++;
				}
				deque<int> tm;
				for (int m = 0; m < LandingQueue[i].size(); m++) {
					if (m == j) continue;
					tm.push_back(LandingQueue[i][m]);
				}
				LandingQueue[i] = tm;
				emergency_land++;
			}
		}
	}
	cout << endl;
	printqueue();

	cout << "Step4:\n";
	//runway1:
	if (LandingQueue[1].size()) {
		choose[1] = LandingQueue[1].front();
		fuel_remain += oil[LandingQueue[1].front()];
		LandingQueue[1].pop_front();
		totallanding++;
	}
	else if (TakeoffQueue[1].size()) {
		choose[1] = TakeoffQueue[1].front();
		TakeoffQueue[1].pop_front();
		totaltakeoff++;
	}
	//runway234:
	for (int i = 2; i <= 4; i++) {
		/*
		if (LandingQueue[i].size() + LandingQueue[i + 3].size() < TakeoffQueue[i].size() && TakeoffQueue[i].size() > 0) {
			choose[i] = TakeoffQueue[i].front();
			TakeoffQueue[i].pop_front();
			totaltakeoff++;
		}
		else {
			if (LandingQueue[i].size() >= LandingQueue[i + 3].size() && LandingQueue[i].size() > 0) {
				choose[i] = LandingQueue[i].front();
				fuel_remain += oil[LandingQueue[i].front()];
				LandingQueue[i].pop_front();
				totallanding++;
			}
			else if (LandingQueue[i + 3].size() > LandingQueue[i].size() && LandingQueue[i + 3].size() > 0) {
				choose[i] = LandingQueue[i + 3].front();
				fuel_remain += oil[LandingQueue[i + 3].front()];
				LandingQueue[i + 3].pop_front();
				totallanding++;
			}
		}
		*/
		if (LandingQueue[i].size() >= LandingQueue[i + 3].size() && LandingQueue[i].size() > 0) {
			choose[i] = LandingQueue[i].front();
			fuel_remain += oil[LandingQueue[i].front()];
			LandingQueue[i].pop_front();
			totallanding++;
		}
		else if (LandingQueue[i+3].size() > LandingQueue[i].size() && LandingQueue[i+3].size() > 0) {
			choose[i] = LandingQueue[i+3].front();
			fuel_remain += oil[LandingQueue[i+3].front()];
			LandingQueue[i+3].pop_front();
			totallanding++;
		}
		else if (TakeoffQueue[i].size()) {
			choose[i] = TakeoffQueue[i].front();
			TakeoffQueue[i].pop_front();
			totaltakeoff++;
		}
	}
	printqueue();
	for (int i = 1; i <= 4; i++) {
		waitingtime += TakeoffQueue[i].size();
	}
}

void run() {
	for (int i = 2; i <= 7; i++) {
		for (int j = 0; j < LandingQueue[i].size(); j++) {
			oil[LandingQueue[i][j]]--;
		}
	}
	//totallanding += landing_num;
	//totaltakeoff += takeoff_num;
	for (int i = 1; i <= landing_num; i++) {
		landing_plane[i] = landing_id;
		oil[landing_id] = rand() % 10 + 1;
		fuel += oil[landing_id];
		landing_id += 2;
	}
	for (int i = 1; i <= takeoff_num; i++) {
		takeoff_plane[i] = takeoff_id;
		takeoff_id += 2;
	}
	print();
}

int main() {
	srand(time(NULL));
	int time_unit;
	cout << "How many time unit you want to simulate: ";
	cin >> time_unit;
	cout << "Simulation Time: " << time_unit << "\n\n";
	for (int i = 1; i <= time_unit; i++) {
		cout << "Time = " << i << ":\n";
		landing_num = rand() % 5;
		takeoff_num = rand() % 5;
		//cout << landing_num << "\t" << takeoff_num << "\n";
		run();
	}
	//cout << fuel << " " << fuel_remain << endl;
	//cout << totallanding << " " << totaltakeoff<< endl;
	cout << "average landing waiting time: " << (fuel - fuel_remain) / totallanding << "(s)" << endl;
	cout << "average takeoff waiting time: " << waitingtime / totaltakeoff << "(s)" << endl;
	cout << "average fuel saved: " << fuel_remain / totallanding << endl;
	cout << "emergency landing: " << emergency_land << endl;
	cout << "crashed amount: " << crashed_amount << endl;
	/*for (int i = 1; i <= 4; i++) {
		cout << emer[i] << " ";
	}*/
}