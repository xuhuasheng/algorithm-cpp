#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#define MAXN 1000015
#define m_p make_pair
#define inf 0x3f3f3f3f

using namespace std;

priority_queue<pair<int,int> >q;
int S,T,dis[MAXN],n;
vector<pair<int,int> >g[MAXN];
int b[15]={0,31,29,31,30,31,30,31,31,30,31,30,31};


void dijs(){
	
	int i,v,len,month,day;
	for(i=1;i<=n;i++)dis[i]=inf;
	dis[S]=0;
	q.push(m_p(0,S));
	while(!q.empty()){
		day=-q.top().first;
		month=q.top().second;
		q.pop();
		if(month==T)return;
		if(dis[month]!=day)continue;
		for(i=0;i<g[month].size();i++){
			v=g[month][i].first;
			len=g[month][i].second;
			if(dis[month]+len<dis[v]){
				dis[v]=dis[month]+len;
				q.push(m_p(-dis[v],v));
			}
		}
	}
}


int main(){
	
	
	int m,i,j,k,month,day,year;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&month,&day,&year);
		g[month].push_back(m_p(day,year));
		g[day].push_back(m_p(month,year));
	}
	scanf("%d%d",&S,&T);	
	dijs();
	scanf("%d.%d/%d",&month,&day,&year);
	day+=dis[T]/24;
	year+=dis[T]%24;
	if(year>=24){
		day++;
		year-=24;
	}
	while(day>b[month]){
		day-=b[month];
		month++;
	}	
		
	printf("%d.%d/%d",month,day,year);
	return 0;
}