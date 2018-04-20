#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
	
	int mx,my,nL,h,lx,ly,x,y;
	cin>>mx>>my;
	cin>>nL;
	vector<vector<int>> pd(nL);
	for(int i= 0;i<3;i++){
		pd[i].push_back(0);
	}
	for(int i = 0;i<nL;i++){
		cin>>lx>>ly>>h;
		int p = (my-ly)/(mx-lx);
		int d = sqrt(((mx-lx)*(mx-lx))+((my-ly)*(my-ly)));
		pd[i][0] = p;
		pd[i][1] = d;
		pd[i][2] = h;
	}
	sort(pd.begin(), pd.end( ), [ ]( const vector<int>& lhs, const vector<int>& rhs )
{	
	if(lhs[0]==rhs[0])return lhs[1]<rhs[1];
   return lhs[0] < rhs[0];
});;
	int hmax;
	hmax = pd[0][2];
	int p = pd[0][1];
	for(int i = 1;i<pd.size();i++){
		if(pd[i][0] == p){
			if(pd[i][2]<=hmax)
			nL--;
			else 
			hmax = pd[i][2];
		}
		else{
		p = pd[i][0];
		hmax = pd[0][2];
		}
	}
	cout<<nL;
}
