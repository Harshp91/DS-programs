#include<iostream>
using namespace std;

struct complex
{
	int real;
	int img;
};

struct building
{
	int foot;
	int inch;
};

int main(){

    float x,b1,b2,a1,a2;

    cout<<"enter the foot and inch value of 1st building"<<endl;
    cin>>a1>>b1;
    cout<<"enter the foot and inch value of 1st building"<<endl;
    cin>>a2>>b2;
	struct building f1={a1,b1};
	struct building f2={a2,b2};
	struct building h;


    h.inch=(f1.inch+f2.inch)%12;
	x=(f1.inch+f2.inch)/12;
	h.foot=(f1.foot+f2.foot+x);	
    cout<<"length in foot and inch is"<<endl;
	cout<<h.foot<<"foot"<<" "<<h.inch<<"inch"<<endl;

return 0;
}