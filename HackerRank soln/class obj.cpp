#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 
class Box{
	public:
		int l,b,h;
		Box()
		{
			l=0;
			b=0;
			h=0;
		}
		Box(int length,int breadth,int height)
		{
			l=length;
			b=breadth;
			h=height;
		}
		
		Box(Box &B) 
		{
			l=B.l;
			b=B.b;
			h=B.h;
		}
		
		int getLength()// Return box's length
		{
			return l;
		}
		int getBreadth () // Return box's breadth
		{
			return b;
		}
		int getHeight ()  //Return box's height
		{
			return h;
		}
		long long CalculateVolume() // Return the volume of the box
		{
			return (long long)l*(long long)b*(long long)h;
		}
		
		//Overload operator < as specified
		bool operator<(Box& B) // b is temp object
		{
			if(l<B.l)
				return true;
			else if(b<B.b && l==B.l)
				return true;
			else if(h<B.h && b==B.b && l==B.l)
				return true;
			else
				return false;			
		}
		
		//Overload operator << as specified
		friend ostream& operator << (ostream &out, Box &B)
		{
			out<<""<<B.l<<" "<<B.b<<" "<<B.h;
			return out;
		}
		
};


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
