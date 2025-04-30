#include<iostream>
using namespace std;
template<typename T>
class Calculation{
	private:
		T num1;
		T num2;
		public:
			Calculation(T x,T y)
			{
				num1=x;
				num2=y;
				
			}
			void add()
			{
				cout<<"Addition:"<<num1+num2;
			}
				void subtraction()
			{
				cout<<"\nsubtraction:"<<num1-num2;
			}
			
			
			 void multiplication()
			{
				cout<<"\nMultiplication:"<<num1*num2;
			}
			
			 void division()
			{
				cout<<"\ndivision:"<<num1/num2;
			}
			void maxnumber(){
				if(num1>num2)
				cout<<"\nThe max of 2 and 5 is:"<<num1;
				else{
							cout<<"\nThe max of 2 and 5 is:"<<num2;
				}
			}
			
			
};
int main(){
	Calculation <int>c1(2,5);
	c1.add();
	c1.subtraction();
	c1.multiplication();
	c1.division();
	c1.maxnumber();
	Calculation <float>c2(3.4,5.5);
	c2.multiplication();

	
}
