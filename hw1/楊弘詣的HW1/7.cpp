#include<iostream>
#include<stack>
using namespace std;
int main(){
	int n;
	cin>>n;
	char a[n][10];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		stack<char> before;
		for(int k=0;k<10;k++){
			if(a[i][k]=='\0'){
				break;
			}else if(!isalpha(a[i][k])){
				if(k!=0&&isalpha(a[i][k-1])){
					before.push(a[i][k]);
				}else if(k==0){
					before.push(a[i][k]);
				}else{
					before.push('(');
					before.push(a[i][k]);
				}
			}else{
				if(!isalpha(a[i][k-1])){
					cout<<a[i][k];
				}else{
					cout<<a[i][k];
					while(!before.empty()&&before.top()!='('){
						cout<<before.top();
						before.pop();
					}
					if(!before.empty()){
						before.pop();
					}
				}
			}			
		}
		cout<<endl;
	}
}
