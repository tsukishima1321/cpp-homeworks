#include <iostream>
#include <math.h>
#define PI 3.14159

using namespace std;

/*int main(){
	double x,y;
	cout<<"请输入坐标："<<endl; 
	cin>>x>>y;
	double distance=sqrt(x*x+y*y);
	if(distance>=2&&distance<=4){
		cout<<PI*4*4-PI*2*2<<endl;
	}else{
		cout<<0<<endl;
	}
	return 0;
} */

#include <iostream>
void encode(char* source,int length){
    for(int i=0;i<length;i++){
        char &t=source[i];
        if(t>='x'&&t<='z'){
            t-=23;
        }else{
            t+=3;
        }
    }
}

int main(){
    char s[4]="fly";
    encode(s,3);
    cout<<s;
    return 0;
}

/*int main(){
	double x,y,z;
	cout<<"请输入三个数："<<endl; 
	cin>>x>>y>>z;
	if(x<y){
		if(x<z){
			cout<<x;
		}else{
			cout<<z;
		}
	}else{
		if(y<z){
			cout<<y;
		}else{
			cout<<z;
		}
	}
	return 0;
}*/


/*int main(){
	double x,y;
	cout<<"请输入坐标："<<endl; 
	cin>>x>>y;
	double distance=sqrt(x*x+y*y);
	if(distance>=2&&distance<=4){
		cout<<PI*4*4-PI*2*2<<endl;
	}else{
		cout<<0<<endl;
	}
	return 0;
} */

