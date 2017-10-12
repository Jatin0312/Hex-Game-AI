
// A code for game of hex in c++
// There are two players one black and one white
// They had to reach the opposite ends
// Now +1 on board represent black and -1 represent white
#include <bits/stdc++.h>
using namespace std;
# define size 5
int hexboard[6][6];
int win_black_flag=0;
int win_white_flag=0;
int count1=0;
int count2=0;
int tempcount=0;

class move{
	public:
	int row,col;
	void setter(int r,int c)
	{
		row = r;
		col = c;
	}
};
// function naming
void dfs_result_connection(int );
void dfs_check_connection(int );
void dfs_result_connection_util(int ,int ,int ,bool[size+1][size+1]);
void dfs_check_connection_util(int ,int ,int ,bool[size+1][size+1]);
int dfs_distance(int );
int dfs_distance_util(int ,int ,int ,bool[size+1][size+1]);



 
int dfs_distance(int color)
{
	bool visited[size+1][size+1];
	memset(visited,false,sizeof(visited));
	int result = 1000;
	if(color==1)
	{
		for(int i=1;i<=size;i++)
		{
			memset(visited,false,sizeof(visited));
			result= min(result,dfs_distance_util(i,1,color,visited));
		}
	}
	else if(color==-1)
	{
		for(int i=1;i<=size;i++)
		{
			memset(visited,false,sizeof(visited));
			result= min(result,dfs_distance_util(1,i,color,visited));
		}
	}
	return result;
}
int dfs_distance_util(int i,int j,int color,bool visited[size+1][size+1])
{
	visited[i][j]=true;
	if(hexboard[i][j]==color)
	{
		int k1=1000;
		if(color==1)
		{
			if(j==size)
			{
				return 0;
			}
			if(i+1<=size && visited[i+1][j]==false)
			{
				k1 = dfs_distance_util(i+1,j,color,visited);
			}
			if(j+1<=size && visited[i][j+1]==false)
			{
				k1 = min(k1,dfs_distance_util(i,j+1,color,visited));
			}
			if(i-1>=1 && visited[i-1][j]==false)
			{
				k1 = min(k1,dfs_distance_util(i-1,j,color,visited));
			}
			if(j-1>=1 && visited[i][j-1]==false)
			{
				k1 = min(k1,dfs_distance_util(i,j-1,color,visited));
			}
			if(i+1<=size && j-1>=1 && visited[i+1][j-1]==false)
			{
				k1 = min(k1,dfs_distance_util(i+1,j-1,color,visited));
			}
			if(i-1>=1 && j+1<=size && visited[i-1][j+1]==false)
			{
				k1 = min(k1,dfs_distance_util(i-1,j+1,color,visited));
			}
				return k1;

		}
		else if(color==-1)
		{
			if(i==size)
			{
				return 0;
			}
			int k1 =1000;
			if(i+1<=size && visited[i+1][j]==false)
			{
				k1 = dfs_distance_util(i+1,j,color,visited);
			}
			if(j+1<=size && visited[i][j+1]==false)
			{
				k1 = min(k1,dfs_distance_util(i,j+1,color,visited));
			}
			if(i-1>=1 && visited[i-1][j]==false)
			{
				k1 = min(k1,dfs_distance_util(i-1,j,color,visited));
			}
			if(j-1>=1 && visited[i][j-1]==false)
			{
				k1 = min(k1,dfs_distance_util(i,j-1,color,visited));
			}
			if(i+1<=size && j-1>=1 && visited[i+1][j-1]==false)
			{
				k1 = min(k1,dfs_distance_util(i+1,j-1,color,visited));
			}
			if(i-1>=1 && j+1<=size && visited[i-1][j+1]==false)
			{
				k1 = min(k1,dfs_distance_util(i-1,j+1,color,visited));
			}
			return k1;
		}

	}
	if(hexboard[i][j]==0)
	{

		int k1=1000;
		if(color==1)
		{
			if(j==size)
			{
				return 1;
			}
			if(i+1<=size && visited[i+1][j]==false)
			{
				k1 = 1 + dfs_distance_util(i+1,j,color,visited);
			}
			if(j+1<=size && visited[i][j+1]==false)
			{
				k1 = min(k1,1 + dfs_distance_util(i,j+1,color,visited));
			}
			if(i-1>=1 && visited[i-1][j]==false)
			{
				k1 = min(k1,1 + dfs_distance_util(i-1,j,color,visited));
			}
			if(j-1>=1 && visited[i][j-1]==false)
			{
				k1 = min(k1,1 + dfs_distance_util(i,j-1,color,visited));
			}
			if(i+1<=size && j-1>=1 && visited[i+1][j-1]==false)
			{
				k1 = min(k1,1 + dfs_distance_util(i+1,j-1,color,visited));
			}
			if(i-1>=1 && j+1<=size && visited[i-1][j+1]==false)
			{
				k1 = min(k1,1 + dfs_distance_util(i-1,j+1,color,visited));
			}
			return k1;

		}
		else if(color==-1)
		{
			if(i==size)
			{
				return 1;
			}
			int k1 =1000;
			if(i+1<=size && visited[i+1][j]==false)
			{
				k1 = 1+ dfs_distance_util(i+1,j,color,visited);
			}
			if(j+1<=size && visited[i][j+1]==false)
			{
				k1 = min(k1,1 + dfs_distance_util(i,j+1,color,visited));
			}
			if(i-1>=1 && visited[i-1][j]==false)
			{
				k1 = min(k1,1 + dfs_distance_util(i-1,j,color,visited));
			}
			if(j-1>=1 && visited[i][j-1]==false)
			{
				k1 = min(k1,1 + dfs_distance_util(i,j-1,color,visited));
			}
			if(i+1<=size && j-1>=1 && visited[i+1][j-1]==false)
			{
				k1 = min(k1,1 + dfs_distance_util(i+1,j-1,color,visited));
			}
			if(i-1>=1 && j+1<=size && visited[i-1][j+1]==false)
			{
				k1 = min(k1,1 + dfs_distance_util(i-1,j+1,color,visited));
			}
			return k1;
		}
	}

}
void dfs_result_connection_util(int i,int j,int color,bool visited[size+1][size+1])
{
	if(win_black_flag+win_black_flag>=1)
		return;
	visited[i][j] =true;
	if(hexboard[i][j]==color)
	{
		if(color==1)
		{
			if(j==size)
			{

				win_black_flag=1;
				return;
			}
			/*if(j+1<=size && visited[i][j+1]==false)
			{
				dfs_result_connection_util(i,j+1,color,visited);
			}
			if(i-1>=1 && j+1<=size && visited[i-1][j+1]==false)
			{
				dfs_result_connection_util(i-1,j+1,color,visited);
			}*/

		}
		else
		{
			if(i==size)
			{
				
				win_white_flag=1;
				return;
			}
			/*if(i+1<=size && visited[i+1][j]==false)
			{
				dfs_result_connection_util(i+1,j,color,visited);
			}
			if(i+1<=size && j-1>=1 && visited[i+1][j-1]==false)
			{
				dfs_result_connection_util(i+1,j-1,color,visited);
			}*/
		}
		if(i+1<=size && visited[i+1][j]==false)
		{
			dfs_result_connection_util(i+1,j,color,visited);
		}
		if(j+1<=size && visited[i][j+1]==false)
		{
			dfs_result_connection_util(i,j+1,color,visited);
		}
		if(i-1>=1 && visited[i-1][j]==false)
		{
			dfs_result_connection_util(i-1,j,color,visited);
		}
		if(j-1>=1 && visited[i][j-1]==false)
		{
			dfs_result_connection_util(i,j-1,color,visited);
		}
		if(i+1<=size && j-1>=1 && visited[i+1][j-1]==false)
		{
			dfs_result_connection_util(i+1,j-1,color,visited);
		}
		if(i-1>=1 && j+1<=size && visited[i-1][j+1]==false)
		{
			dfs_result_connection_util(i-1,j+1,color,visited);
		}

	}

	//visited[i][j]=false;
}
void dfs_check_connection_util(int i,int j,int color,bool visited[size+1][size+1])
{
	visited[i][j]=true;
	//cout << i << " " << j << endl;
	if(hexboard[i][j]==color)
	{
		tempcount++;
		if(i+1<=size && visited[i+1][j]==false)
		{
			dfs_check_connection_util(i+1,j,color,visited);
		}
		if(j+1<=size && visited[i][j+1]==false)
		{
			dfs_check_connection_util(i,j+1,color,visited);
		}
		if(i-1>=1 && visited[i-1][j]==false)
		{
			dfs_check_connection_util(i-1,j,color,visited);
		}
		if(j-1>=1 && visited[i][j-1]==false)
		{
			dfs_check_connection_util(i,j-1,color,visited);
		}
		if(i+1<=size && j-1>=1 && visited[i+1][j-1]==false)
		{
			dfs_check_connection_util(i+1,j-1,color,visited);
		}
		if(i-1>=1 && j+1<=size && visited[i-1][j+1]==false)
		{
			dfs_check_connection_util(i-1,j+1,color,visited);
		}
	}
}


void dfs_check_connection(int color)
{
	bool  visited[size+1][size+1];
	memset(visited,false,sizeof(visited));
	for(int i=1;i<=size;i++)
	{
		for (int j = 1; j <= size; ++j)
		{
			if(visited[i][j]==false )
			{
				dfs_check_connection_util(i,j,color,visited);
			}
		}
	}

}
void dfs_result_connection(int color)
{
	bool  visited[size+1][size+1];
	memset(visited,false,sizeof(visited));
	if(color==1)
	{
		for(int i=1;i<=size;i++)
		{
			if(visited[i][1]==false)
				dfs_result_connection_util(i,1,color,visited);
		}
	}
	else if(color==-1)
	{
		for(int i=1;i<=size;i++)
		{
			if(visited[1][i]==false)
				dfs_result_connection_util(1,i,color,visited);
		}
	}

}
int minmax(int depth,bool ismax,int color)
{
	//cout << depth << endl;
	/*dfs_result_connection(color);
	if(win_black_flag==1)
	{
		return 1;
	}*/	
	/*if(color==-1)
		color = 1;
	else
		color = -1;
	dfs_result_connection(color);
	if(win_white_flag==1)
	{
		return -1;
	}
	if(color==-1)
		color = 1;
	else
		color = -1;
	*/
	dfs_result_connection(-1);
	if(win_white_flag==1)
	{
		win_white_flag=0;
		return -50;
	}
	dfs_result_connection(color);
	if(win_black_flag==1)
	{
		win_black_flag=0;
		return 50;
	}
	if(depth==0)
	{
		int result1 = dfs_distance(color);
		int result2 = dfs_distance(-1);
		return result2 - result1;
	}
	
	if(ismax)
	{
		int best=-100;
		for(int i=1;i<=size;i++)
		{
			for(int j=1;j<=size;j++)
			{
				if(hexboard[i][j]==0)
				{
					
					hexboard[i][j] = color;
					
					best = max(best,minmax(depth-1,!ismax,color));
					
					hexboard[i][j]=0;
				}
			}
		}
		return best;
	}
	
	if(!ismax)
	{
		int best = 100;
		for(int i=1;i<=size;i++)
		{
			for(int j=1;j<=size;j++)
			{
				if(hexboard[i][j]==0)
				{

				   	hexboard[i][j]=-1;
				    best = min(best,minmax(depth-1,!ismax,color));
					hexboard[i][j]=0;
				}
			}
		}
		return best;
	}

}
move findbestmove(int color)
{
	int bestval = -100;
	move mv;
	mv.row=0,mv.col=0;
	for(int i=1;i<=size;i++)
	{
		for(int j=1;j<=size;j++)
		{
			if(hexboard[i][j]==0)
			{
				hexboard[i][j] = color;
				//cout << i << " " << j << endl;
				
				int movval = minmax(3,false,color);
				
				hexboard[i][j]=0;
				if(movval>bestval)
				{
					mv.row = i;
					mv.col = j;
					bestval = movval;
				}
			}
		}
	}
	//cout << mv.row << " "  << mv.col << endl;
	return mv;
}
int main()
{
	memset(hexboard,0,sizeof(hexboard));
	move first;
	int color=1;
	while(win_black_flag+win_white_flag==0)
	{
		first = findbestmove(color);

		hexboard[first.row][first.col] = color;
		cout << first.row <<  " " << first.col << endl;
		for(int i=1;i<=size;i++)
		{
			for(int j=1;j<=size;j++)
			{
				cout << hexboard[i][j] << " ";
			}	
			cout << endl;
		}	
		cout << "Enter your move friend: ";
		int x,y;
		cin >> x >> y;
		hexboard[x][y]=-1;
		dfs_result_connection(1);
		dfs_result_connection(-1);

		

	}
	if(win_black_flag+win_white_flag!=0)
	{
		if(win_white_flag==1)
		{
			cout << "White won the game\n";
		}
		else
		{
			cout << "Black won the game\n";
		}
	}
	//cout << win_white_flag <<" " << win_black_flag << endl;	
	

	return 0;

}