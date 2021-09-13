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

char map[100][100]; //global�Լ��� ����; 
int height,width;

int isSquare(int x,int y,int radius) //�Ǵ��ϴ� �Լ�; 
{
	int top,left,bottom,right;
	top=x-radius; // �׸� �׷����� �˼�����; 
	bottom=x+radius;
	left=y-radius;
	right=y+radius;
	if(top<0||bottom>=height||left<0||right>=width) //���� ��������; 
	{
		return 0; //���� �Ѿ�� 0 �ݳ�; 
	}
	for(int i=top;i<=bottom;i++)
	{
		for(int j=left;j<=right;j++)
		{
			if(map[i][j]!=map[x][y]) //�߰����� ���� ���ڸ��� 1 �ƴϸ� 0; 
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
		cin>>height>>width>>time; //���̶� �߰� ���� ��� �Է�; 
		for(int i=0;i<height;i++)
		{
			for(int j=0;j<width;j++)
			{
				cin>>map[i][j]; //���� �׸���; 
			}
		}
		cout<<height<<" "<<width<<" "<<time<<endl;
		int x,y;
		for(int k=0;k<time;k++)
		{
			x=0,y=0,radius=0;
			cin>>x>>y;
			while(isSquare(x,y,radius)) //���࿡ 1�̸� �ֺ��� �׸��� �߰������̶� ������ ���� 1 ���ϱ�; 
			{
				radius++;	
			}
			if(isSquare(x,y,radius)==0) //�� �������� ���� ���ϱ� , ������ ���Ѱ� ������ , �츮�� ���Ҳ� ����; 
			{
				cout<<2*radius-1<<endl;	
			}
		}
	}
return 0;
}

