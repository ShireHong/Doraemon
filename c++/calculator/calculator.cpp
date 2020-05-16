#include<iostream>
#include<stack>
#include<string>
#include<cstring>

using namespace std;

class Calculator{
	stack<char>   ops;
	stack<double> num;
	char op;
	double res,in1,in2;
public:
	double calculate()
	{
		do{
			readdata();
			skipspace();
		}
		while(readop());
		calremain();
		return res;
	}
	void readdata()
	{
		while(!(cin>>res))
		{
			cin.clear();
			cin>>op;
			if(op!='(') throw string("无效符号");
			ops.push(op);
		}
		num.push(res);
	}
	void skipspace()
	{
		while(cin.peek()==' ')
		{
			cin.ignore();
		}
	}
	bool readop()
	{
		while((op=cin.get())==')')
		{
			while(ops.top()!='(')
			{
				in1=num.top();
				num.pop();
				in2=num.top();
				num.pop();
				num.push(calc(in1,ops.top(),in2));
				ops.pop();
			}
			ops.pop();
		}
		if(op=='\n') return false;
		if(strchr("+-*/",op)==NULL) throw string("无效输入")+op;
		while(!ops.empty()&&ops.top()!='('&&!prior(op,ops.top()))
		{
        	in1=num.top();
			num.pop();
            in2=num.top();
			num.pop();
            num.push(calc(in1,ops.top(),in2));
            ops.pop();
		}
		ops.push(op);
		return true;
	}
	double calc(double in1,char op,double in2)
	{
		return op=='+'?in1+in2:op=='-'?in2-in1:op=='*'?in1*in2:in2/in1;
	}
	void calremain()
	{
		while(!ops.empty())
		{
			in1=num.top();
			num.pop();
            in2=num.top();
			num.pop();
            num.push(calc(in1,ops.top(),in2));    
            ops.pop();
		}
		if(num.size()!=1) throw string("无效表达式");
		res=num.top();
		num.pop();
	}
	bool prior(char op1,char op2)
	{
		return op1!='+'&&op1!='-'&&op2!='*'&&op2!='/';
	}
	
};

int main()
{
	Calculator calc;
	cout<<"计算器"<<endl;
	try
	{
		cout<<calc.calculate()<<endl;
	}catch(const string &calc)
    {
		cout<<calc<<endl;
	}	
	return 0;
}







