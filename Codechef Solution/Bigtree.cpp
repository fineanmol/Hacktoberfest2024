#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}
LL gcd(LL x,LL y){return !y?x:gcd(y,x%y);}

void exgcd(LL a,LL b,LL &x,LL &y){
	if (!b){x=1;y=0;return;}
	LL tx,ty;
	exgcd(b,a%b,tx,ty);
	x=ty,y=tx-a/b*ty;
}

LL a,b,n,m,v;
LL inv,tmp,g,cir;

LL getw0(LL a,LL b,LL m,LL v){
	//a+bx mod m<=v
	a=(a%m+m)%m,b=(b%m+m)%m;
	if (v<a%g)return -1;
	LL now=(a+b)%m;
	if (now>v){
		LL p=(m-b)%m,q=m;
		if (p<=now){
			if (now%p>v)now%=p;
			else{
				now=now%p+v/p*p;
				while(now>v)now-=p;
				while(now+p<=v)now+=p;
			}
		}
		for(;now>v;){
			LL q_=q%p;
			if (!q_)return -1;
			LL p_=p%q_;
			LL tot=p/q_;
			while(p_<=now&&now>v){
				if (p<=now){
					if (now%p>v)now%=p;
					else{
						now=now%p+v/p*p;
						while(now>v)now-=p;
						while(now+p<=v)now+=p;
					}
				}
				else{
					LL key=p-(p-now)/q_*q_;
					while(key>now)key-=q_;
					while(key+q_<=now)key+=q_;
					if (!key)key+=q_;
					if (now%key>v)now%=key;
					else{
						now=now%key+v/key*key;
						while(now>v)now-=key;
						while(now+key<=v)now+=key;
					}
				}
			}
			p=p_,q=q_;
		}
	}
	return now;
}

LL getw1(LL a,LL b,LL m,LL v){
	if (v==m-1)return -1;
	//a+bx mod m>v
	LL ret=getw0(-a-1,-b,m,m-v-2);
	if (ret==-1)return -1;
	ret=((m-ret-1)%m+m)%m;
	return ret;
}

LL gettim(LL v){
	LL ret=((v-a)/g*inv%cir+cir)%cir;
	if (ret==0)ret=cir;
	return ret;
}

void solve(){
	cin>>a>>b>>m>>n;
	a%=m,b%=m;
	if (b==0){
		cout<<n-1<<endl;
		return;
	}
	v=((n%m)*b+a)%m;
	g=gcd(m,b);
	cir=m/g;
	exgcd(b,m,inv,tmp);
	//down
	LL st=getw0(a,b,m,v);
	LL ans=1;
	for(;st<v;){
		LL u=getw0(0,b,m,v-st);
		if (u==-1)break;
		LL ad=(v-st)/u;
		st+=ad*u;
		ans+=ad;
	}
	LL delt=((v-a)/g*inv%cir+cir)%cir;
	if (delt==0)delt=cir;
	ans=ans+(n-delt)/cir-1;
	
	//up
	st=getw1(a,b,m,v);
	if (st!=-1&&gettim(st)<n){
		ans++;
		LL now=gettim(st);
		for(;st>v+1;){
			LL u=getw0(-1,m-b,m,st-v-2);
			if (u==-1)break;
			u++;
			LL t=gettim((m*2-u+a)%m);
			LL ad=(st-v-1)/u;
			if (now+t*ad>n){
				ad=(n-now)/t;
				ans+=ad;
				st-=u*ad;
				now+=t*ad;
				break;
			}
			else{
				ans+=ad;
				st-=u*ad;
				now+=t*ad;
			}
		}
	}
	cout<<ans<<endl;
}

int main(){
	for(int T=get();T;T--)solve();
	return 0;
}
