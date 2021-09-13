/*
Sample Input
1
7 10 4
abbbaaaaaa
abbbaaaaaa
abbbaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaccaaaaaa
aaccaaaaaa
1 2
2 4
4 6
5 2
Sample Output
7 10 4
3
1
5
1
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char map[100][100]; //global함수로 지정; 
int height,width;

int isSquare(int x,int y,int radius) //판단하는 함수; 
{
	int top,left,bottom,right;
	top=x-radius; // 그림 그려보면 알수있음; 
	bottom=x+radius;
	left=y-radius;
	right=y+radius;
	if(top<0||bottom>=height||left<0||right>=width) //끝을 도달했음; 
	{
		return 0; //끝을 넘어가면 0 반납; 
	}
	for(int i=top;i<=bottom;i++)
	{
		for(int j=left;j<=right;j++)
		{
			if(map[i][j]!=map[x][y]) //중간꺼랑 같은 문자면은 1 아니면 0; 
			{
				return 0;
			}
		}
	}
	return 1;
}


int main()
{
	int n,x,y,time,radius;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>height>>width>>time; //넓이랑 중간 지점 곗수 입력; 
		for(int i=0;i<height;i++)
		{
			for(int j=0;j<width;j++)
			{
				cin>>map[i][j]; //지도 그리기; 
			}
		}
		cout<<height<<" "<<width<<" "<<time<<endl;
		int x,y;
		for(int k=0;k<time;k++)
		{
			x=0,y=0,radius=0;
			cin>>x>>y;
			while(isSquare(x,y,radius)) //만약에 1이면 주변에 그림이 중간지점이랑 같으면 길이 1 더하기; 
			{
				radius++;	
			}
			if(isSquare(x,y,radius)==0) //다 구했으면 길이 구하기 , 위에서 구한건 반지름 , 우리가 구할껀 지름; 
			{
				cout<<2*radius-1<<endl;	
			}
		}
	}
return 0;
}

