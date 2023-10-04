#include<iostream>
#include<string>
#include<cmath>
#include<sstream>
using namespace std;
int bintodec(string c);
string bintohex(string c);
string bintooct(string c);
string hextobin(char c);
string octtobin(char c);
string dectobin(int c);
string dectohex(int c);
string dectooct(int c);
string hextooct(string c);
string octtohex(string c);

int bintodec(string c)
{
	int x = 0;
	for(int i=0; i<c.length(); i++)
	{
		if(c[i] == '1')
		{
			x += pow(2, c.length()-i-1);
		}
	}
	return x;
}
string bintohex(string q)
{
	string d, g, h = "";
	int c, e, f = 0;
	stringstream ss;
	e = q.length();
	if(q.length() <= 4)
	{
		c = bintodec(q);
		if(c>=0 && c<=9)
		{
			ss<<c;
			ss>>d;
		}
		else if(c == 10)
		{
			d = "A";
		}
		else if(c == 11)
		{
			d = "B";
		}
		else if(c == 12)
		{
			d = "C";
		}
		else if(c == 13)
		{
			d = "D";
		}
		else if(c == 14)
		{
			d = "E";
		}
		else if(c == 15)
		{
			d = "F";
		}
		return d;
	}
	else if(q.length() > 4)
	{
		while(e != 0)
		{
			for(int j=0; j<4; j++)
			{
				d += q[e-1];
				e--;
			}
			for(int k=0; k<d.length(); k++)
			{
				if(d[k] == '1')
				{
					f += pow(2, k);
				}
			}
			if(f>=0 && f<=9)
			{
				ss<<f;
				ss>>h;
				ss.clear();
				g += h;
			}
			else if(f == 10)
			{
				g += "A";
			}
			else if(f == 11)
			{
				g += "B";
			}
			else if(f == 12)
			{
				g += "C";
			}
			else if(f == 13)
			{
				g += "D";
			}
			else if(f == 14)
			{
				g += "E";
			}
			else if(f == 15)
			{
				g += "F";
			}
			f = 0;
			d = "";
		}
		return g;
	}
}
string bintooct(string q)
{
	string d, g, h = "";
	int c, e, f = 0;
	stringstream ss;
	e = q.length();
	if(q.length() <= 3)
	{
		c = bintodec(q);
		ss<<c;
		ss>>d;
		return d;
	}
	else if(q.length() > 3)
	{
		while(e != 0)
		{
			for(int j=0; j<3; j++)
			{
				d += q[e-1];
				e--;
			}
			for(int k=0; k<d.length(); k++)
			{
				if(d[k] == '1')
				{
					f += pow(2, k);
				}
			}
			ss<<f;
			ss>>h;
			ss.clear();
			g += h;
			f = 0;
			d = "";
		}
		return g;
	}
}
string hextobin(char q)
{
	string c = "";
	if(q == '0')
	{
		c = "0000";
	}
	else if(q == '1')
	{
		c = "0001";
	}
	else if(q == '2')
	{
		c = "0010";
	}
	else if(q == '3')
	{
		c = "0011";
	}
	else if(q == '4')
	{
		c = "0100";
	}
	else if(q == '5')
	{
		c = "0101";
	}
	else if(q == '6')
	{
		c = "0110";
	}
	else if(q == '7')
	{
		c = "0111";
	}
	else if(q == '8')
	{
		c = "1000";
	}
	else if(q == '9')
	{
		c = "1001";
	}
	else if(q == 'A')
	{
		c = "1010";
	}
	else if(q == 'B')
	{
		c = "1011";
	}
	else if(q == 'C')
	{
		c = "1100";
	}
	else if(q == 'D')
	{
		c = "1101";
	}
	else if(q == 'E')
	{
		c = "1110";
	}
	else if(q == 'F')
	{
		c = "1111";
	}
	return c;
}
string octtobin(char q)
{
	string c = "";
		if(q == '0')
		{
			c = "000";
		}
		else if(q == '1')
		{
			c = "001";
		}
		else if(q == '2')
		{
			c = "010";
		}
		else if(q == '3')
		{
			c = "011";
		}
		else if(q == '4')
		{
			c = "100";
		}
		else if(q == '5')
		{
			c = "101";
		}
		else if(q == '6')
		{
			c = "110";
		}
		else if(q == '7')
		{
			c = "111";
		}
	return c;
}
string dectobin(int r)
{
	string b = "";
	while(r > 0)
	{
		if(r%2 == 0)
		{
			b += "0";
		}
		else if(r%2 == 1)
		{
			b += "1";
		}
		r = r/2;
	}
	b = string(b.rbegin(), b.rend());
	return b;
}
string dectohex(int r)
{
	string b = dectobin(r);
	if(b.length()%4 == 1)
	{
		b.insert(0, "000");
	}
	else if(b.length()%4 == 2)
	{
		b.insert(0, "00");
	}
	else if(b.length()%4 == 3)
	{
		b.insert(0, "0");
	}
	string c = bintohex(b);
	c = string(c.rbegin(), c.rend());
	return c;
}
string dectooct(int r)
{
	string b = dectobin(r);
	if(b.length()%3 == 1)
	{
		b.insert(0, "00");
	}
	else if(b.length()%3 == 2)
	{
		b.insert(0, "0");
	}
	string c = bintooct(b);
	c = string(c.rbegin(), c.rend());
	return c;
}
string hextooct(string q)
{
	string b = "";
	cout<< q<< endl;
	for(int i = 0; i<q.length(); i++)
	{
		b.append(hextobin(q[i]));
	}
	if(b.length()%3 == 1)
	{
		b.insert(0, "00");
	}
	else if(b.length()%3 == 2)
	{
		b.insert(0, "0");
	}
	b = bintooct(b);
	b = string(b.rbegin(), b.rend());
	return b;
}
string octtohex(string q)
{
	string b = "";
	for(int i = 0; i<q.length(); i++)
	{
		b.append(octtobin(q[i]));
	}
	if(b.length()%4 == 1)
	{
		b.insert(0, "000");
	}
	else if(b.length()%4 == 2)
	{
		b.insert(0, "00");
	}
	else if(b.length()%4 == 3)
	{
		b.insert(0, "0");
	}
	b = bintohex(b);
	b = string(b.rbegin(), b.rend());
	return b;
}
int main()
{
	system("COLOR 1E");
	string a = "", w = "";
	int b = 0, ch = 0, x = 0;
	while(ch != 13)
	{
		cout<<"\n1. Bin to Dec\n2. Bin to Hex\n3. Bin to Oct\n4. Hex to Bin\n5. Oct to Bin\n6. Hex to Dec\n7. Oct to Dec\n8. Dec to Bin\n9. Dec to Hex\n10. Dec to Oct \n11. Hex to Oct\n12. Oct to Hex\n13. Exit\nEnter Choice: ";
		cin>> ch;
		if(ch > 13 || ch < 1 || ch != (int) ch)
		{
			cout<< "Wrong Input!\n";
			cin.clear();
			break;
		}
		if(ch == 1)
		{
			cout<< "Enter Binary Number: ";
			cin>> a;
			b = bintodec(a);
			cout<< "In Decimal = "<< b<< endl;
			b = 0;
		}
		else if(ch == 2)
		{
			cout<< "Enter Binary Number: ";
			cin>> a;
			if(a.length()%4 == 1)
			{
				a.insert(0, "000");
			}
			else if(a.length()%4 == 2)
			{
				a.insert(0, "00");
			}
			else if(a.length()%4 == 3)
			{
				a.insert(0, "0");
			}
			w = bintohex(a);
			cout<< "In Hexadecimal = ";
			for(int l=w.length()-1; l>=0; l--)
			{
				cout<< w[l];
			}
			cout<< endl;
			w = "";
			a = "";
		}
		else if(ch == 3)
		{
			cout<< "Enter Binary Number: ";
			cin>> a;
			if(a.length()%3 == 1)
			{
				a.insert(0, "00");
			}
			else if(a.length()%3 == 2)
			{
				a.insert(0, "0");
			}
			w = bintooct(a);
			cout<< "In Octal = ";
			for(int l=w.length()-1; l>=0; l--)
			{
				cout<< w[l];
			}
			cout<< endl;
			w = "";
			a = "";
		}
		else if(ch == 4)
		{
			cout<< "Enter Hexadecimal Number: ";
			cin>> a;
			cout<< "In Binary = ";
			for(int i = 0; i<a.length(); i++)
			{
				w.append(hextobin(a[i]));
			}
			cout<< w<< endl;
			w = "";
			a = "";
		}
		else if(ch == 5)
		{
			cout<< "Enter Octal Number: ";
			cin>> a;
			cout<< "In Binary = ";
			for (int i=0; i<a.length(); i++)
			{
				w.append(octtobin(a[i]));
			}
			cout<< w<< endl;
			w = "";
			a = "";
		}
		else if(ch == 6)
		{
			cout<< "Enter Hexadecimal Number: ";
			cin>> a;
			for (int i=0; i<a.length(); i++)
			{
				w.append(hextobin(a[i]));
			}
			x = bintodec(w);
			cout<< "In Decimal = "<< x<< endl;
			a = "";
			w = "";
			x = 0;
		}
		else if(ch == 7)
		{
			cout<< "Enter Octal Number: ";
			cin>> a;
			for (int i=0; i<a.length(); i++)
			{
				w.append(octtobin(a[i]));
			}
			x = bintodec(w);
			cout<< "In Decimal = "<< x<< endl;
			a = "";
			w = "";
			x = 0;
		}
		else if(ch == 8)
		{
			cout<< "Enter Decimal Number: ";
			cin>> x;
			w = dectobin(x);
			cout<< "In Binary = "<< w<< endl;
			w = "";
			x = 0;
		}
		else if(ch == 9)
		{
			cout<< "Enter Decimal Number: ";
			cin>> x;
			w = dectohex(x);
			cout<< "In Hexadecimal = "<< w<< endl;
			w = "";
			x = 0;
		}
		else if(ch == 10)
		{
			cout<< "Enter Decimal Number: ";
			cin>> x;
			w = dectooct(x);
			cout<< "In Octal = "<< w<< endl;
			w = "";
			x = 0;
		}
		else if(ch == 11)
		{
			cout<< "Enter Hexadecimal Number: ";
			cin>> a;
			w = hextooct(a);
			cout<< "In Octal: "<< w<< endl;
			w = "";
			a = "";
		}
		else if(ch == 12)
		{
			cout<< "Enter Octal Number: ";
			cin>> a;
			w = octtohex(a);
			cout<< "In Hexadecimal: "<< w<< endl;
			w = "";
			a = "";
		}
		else if(ch == 13)
		{
			break;
		}
	}
	if(ch == 13)
	{
		cout<< "Exiting..\n";
	}
	system("pause");
	return 0;
}
