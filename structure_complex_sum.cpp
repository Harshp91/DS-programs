#include<iostream>
using namespace std;

struct complex
{
	int real;
	int img;
};

int main(){
	int n;
	cout<<"enter the no of complex to add"<<endl;
	cin>>n;
	struct complex s[n];
	
	int i,x=0,y=0;
	for(i=0;i<n;i++){
		cin>>s[i].real>>s[i].img;
	}
	for(i=0;i<n;i++){
		x=x+s[i].real;
		y=y+s[i].img;
	}
    cout<<"complex number is"<<endl;
	cout<<x<<" "<<y<<"i"<<endl;

return 0;
}