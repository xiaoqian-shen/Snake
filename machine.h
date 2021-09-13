#include "snake.h"
using namespace std;
struct info25
{
	int x;
	int y;
	int step;
};
struct food25
{
	int direct;
	int step;
	int x;
	int y;
};
struct queue25
{
	int first = 0;
	int rear = 0;
	int a[10000] = { 0 };
	void push(int x)
	{
		a[rear++] = x;
	}
	void pop()
	{
		first++;
	}
	int front()
	{
		return a[first];
	}
	int empty()
	{
		return first > rear ? 1 : 0;
	}
};

bool judge_block25(int p, int q, GamePanel gp, point snake[5][100], int len[5], int t)
{
	if (p <= 0 || p >= gp.n + 1 || q <= 0 || q >= gp.m + 2)  //判断墙
		return false;
	for (int i = 0; i < gp.wallnum; i++)  //判断障碍物
	{
		if (p == gp.wall[i].x && q == gp.wall[i].y)
			return false;
	}
	if (gp.stage == 1)
	{
		for (int i = 1; i <= len[t]-1; i++) //判断自己身体障碍 除掉尾巴
		{
			if (p == snake[t][i].x && q == snake[t][i].y)
				return false;
		}
	}
	else
	{
		for (int i = 1; i <= len[t]; i++) //判断自己身体障碍
		{
			if (p == snake[t][i].x && q == snake[t][i].y)
				return false;
		}
	}
	int a = 1 - t;
	for (int i = 1; i <= len[a]; i++)  //判断对方身体障碍 
	{
		if (p == snake[a][i].x && q == snake[a][i].y)
			return false;
	}
	return true;
}

bool check25(point snake[5][100], int len[5], int t, GamePanel gp, int direction)
{
	int x0 = 0, y0 = 0;
	x0 = snake[t][1].x;
	y0 = snake[t][1].y;
	switch (direction)
	{
	case 0:
	{
		return judge_block25(x0 + 1, y0, gp, snake, len, t);
	}
	case 1:
	{
		return judge_block25(x0, y0 + 2, gp, snake, len, t);
	}
	case 2:
	{
		return judge_block25(x0, y0 - 2, gp, snake, len, t);
	}
	case 3:
	{
		return judge_block25(x0 - 1, y0, gp, snake, len, t);
	}
	case 4:
	{
		int f = 2;
		if (judge_block25(x0, y0 + 2, gp, snake, len, t) == 0)
			f--;
		if (judge_block25(x0 + 1, y0, gp, snake, len, t) == 0)
			f--;
		int ff = 1;
		ff = judge_block25(x0 + 1, y0 + 2, gp, snake, len, t);
		if (ff == 0 || f == 0)
			return false;
		else
			return true;
	}
	case 5:
	{
		int f = 2;
		if (judge_block25(x0 - 1, y0, gp, snake, len, t) == 0)
			f--;
		if (judge_block25(x0, y0 + 2, gp, snake, len, t) == 0)
			f--;
		int ff = 1;
		ff = judge_block25(x0 - 1, y0 + 2, gp, snake, len, t);
		if (ff == 0 || f == 0)
			return false;
		else
			return true;
	}
	case 6:
	{
		int f = 2;
		if (judge_block25(x0 - 1, y0, gp, snake, len, t) == 0)
			f--;
		if (judge_block25(x0, y0 - 2, gp, snake, len, t) == 0)
			f--;
		int ff = 1;
		ff = judge_block25(x0 - 1, y0 - 2, gp, snake, len, t);
		if (ff == 0 || f == 0)
			return false;
		else
			return true;
	}
	case 7:
	{
		int f = 2;
		if (judge_block25(x0 + 1, y0, gp, snake, len, t) == 0)
			f--;
		if (judge_block25(x0, y0 - 2, gp, snake, len, t) == 0)
			f--;
		int ff = 1;
		ff = judge_block25(x0 + 1, y0 - 2, gp, snake, len, t);
		if (ff == 0 || f == 0)
			return false;
		else
			return true;
	}
	}
	return false;
}

bool ccheck25(point head, point snake[5][100], int len[5], int t, GamePanel gp, int direction)
{
	int x0 = 0, y0 = 0;
	x0 = head.x;
	y0 = head.y;
	switch (direction)
	{
	case 0:
	{
		return judge_block25(x0 + 1, y0, gp, snake, len, t);
	}
	case 1:
	{
		return judge_block25(x0, y0 + 2, gp, snake, len, t);
	}
	case 2:
	{
		return judge_block25(x0, y0 - 2, gp, snake, len, t);
	}
	case 3:
	{
		return judge_block25(x0 - 1, y0, gp, snake, len, t);
	}
	case 4:
	{
		int f = 2;
		if (judge_block25(x0, y0 + 2, gp, snake, len, t) == 0)
			f--;
		if (judge_block25(x0 + 1, y0, gp, snake, len, t) == 0)
			f--;
		int ff = 1;
		ff = judge_block25(x0 + 1, y0 + 2, gp, snake, len, t);
		if (ff == 0 || f == 0)
			return false;
		else
			return true;
	}
	case 5:
	{
		int f = 2;
		if (judge_block25(x0 - 1, y0, gp, snake, len, t) == 0)
			f--;
		if (judge_block25(x0, y0 + 2, gp, snake, len, t) == 0)
			f--;
		int ff = 1;
		ff = judge_block25(x0 - 1, y0 + 2, gp, snake, len, t);
		if (ff == 0 || f == 0)
			return false;
		else
			return true;
	}
	case 6:
	{
		int f = 2;
		if (judge_block25(x0 - 1, y0, gp, snake, len, t) == 0)
			f--;
		if (judge_block25(x0, y0 - 2, gp, snake, len, t) == 0)
			f--;
		int ff = 1;
		ff = judge_block25(x0 - 1, y0 - 2, gp, snake, len, t);
		if (ff == 0 || f == 0)
			return false;
		else
			return true;
	}
	case 7:
	{
		int f = 2;
		if (judge_block25(x0 + 1, y0, gp, snake, len, t) == 0)
			f--;
		if (judge_block25(x0, y0 - 2, gp, snake, len, t) == 0)
			f--;
		int ff = 1;
		ff = judge_block25(x0 + 1, y0 - 2, gp, snake, len, t);
		if (ff == 0 || f == 0)
			return false;
		else
			return true;
	}
	}
	return false;
}

bool next_next25(point snake[5][100], int len[5], int t, GamePanel gp, int direction)
{
	point head;
	head.x = snake[t][1].x;
	head.y = snake[t][1].y;
	int d = pow((snake[t][1].x - snake[1 - t][1].x), 2) + pow((snake[t][1].y - snake[1 - t][1].y), 2) / 4;
	int standard;
	if (d < 5)
		standard = 1;
	else
		standard = 0;
	switch (direction)
	{
		case 0:
		{
			int cc = 0;
			head.x = head.x + 1;
			for (int i = 0; i < 4; i++)
			{
				if (ccheck25(head, snake, len, t, gp, i) != 0)
					cc++;
			}
			if (cc > standard)
				return true;
			else
				return false;
		}
		case 1:
		{
			int cc = 0;
			head.y = head.y + 2;
			for (int i = 0; i < 4; i++)
			{
				if (ccheck25(head, snake, len, t, gp, i) != 0)
					cc++;
			}
			if (cc > standard)
				return true;
			else
				return false;
		}
		case 2:
		{
			int cc = 0;
			head.y = head.y - 2;
			for (int i = 0; i < 4; i++)
			{
				if (ccheck25(head, snake, len, t, gp, i) != 0)
					cc++;
			}
			if (cc > standard)
				return true;
			else
				return false;
		}
		case 3:
		{
			int cc = 0;
			head.x = head.x - 1;
			for (int i = 0; i < 4; i++)
			{
				if (ccheck25(head, snake, len, t, gp, i) != 0)
					cc++;
			}
			if (cc > standard)
				return true;
			else
				return false;
		}
	}
	return false;
}

bool next_next_ob25(point snake[5][100], int len[5], int t, GamePanel gp, int direction)
{
	point head;
	head.x = snake[t][1].x;
	head.y = snake[t][1].y;
	int d = pow((snake[t][1].x - snake[1 - t][1].x), 2) + pow((snake[t][1].y - snake[1 - t][1].y), 2) / 4;
	int standard;
	if (d < 10)
		standard = 1;
	else
		standard = 0;
	switch (direction)
	{
	case 0:
	{
		int cc = 0;
		head.x = head.x + 1;
		for (int i = 0; i < 4; i++)
		{
			if (ccheck25(head, snake, len, t, gp, i) != 0)
				cc++;
		}
			if (cc > standard)
				return true;
			else
				return false;
	}
	case 1:
	{
		int cc = 0;
		head.y = head.y + 2;
		for (int i = 0; i < 4; i++)
		{
			if (ccheck25(head, snake, len, t, gp, i) != 0)
				cc++;
		}
			if (cc > standard)
				return true;
			else
				return false;
	}
	case 2:
	{
		int cc = 0;
		head.y = head.y - 2;
		for (int i = 0; i < 4; i++)
		{
			if (ccheck25(head, snake, len, t, gp, i) != 0)
				cc++;
		}
			if (cc > standard)
				return true;
			else
				return false;
	}
	case 3:
	{
		int cc = 0;
		head.x = head.x - 1;
		for (int i = 0; i < 4; i++)
		{
			if (ccheck25(head, snake, len, t, gp, i) != 0)
				cc++;
		}
			if (cc > standard)
				return true;
			else
				return false;
	}
	case 4:
	{
		int cc = 0;
		head.x = head.x + 1;
		head.y = head.y + 2;
		for (int i = 0; i < 8; i++)
		{
			if (ccheck25(head, snake, len, t, gp, i) != 0)
				cc++;
		}
			if (cc > standard)
				return true;
			else
				return false;
	}
	case 5:
	{
		int cc = 0;
		head.x = head.x - 1;
		head.y = head.y + 2;
		for (int i = 0; i < 8; i++)
		{
			if (ccheck25(head, snake, len, t, gp, i) != 0)
				cc++;
		}
			if (cc > standard)
				return true;
			else
				return false;
	}
	case 6:
	{
		int cc = 0;
		head.x = head.x - 1;
		head.y = head.y - 2;
		for (int i = 0; i < 8; i++)
		{
			if (ccheck25(head, snake, len, t, gp, i) != 0)
				cc++;
		}
			if (cc > standard)
				return true;
			else
				return false;
	}
	case 7:
	{
		int cc = 0;
		head.x = head.x + 1;
		head.y = head.y - 2;
		for (int i = 0; i < 8; i++)
		{
			if (ccheck25(head, snake, len, t, gp, i) != 0)
				cc++;
		}
			if (cc > standard)
				return true;
			else
				return false;
	}
	}
	return false;
}

int find_path25(info25 start, info25 end, point snake[5][100], int len[5], int t, GamePanel gp)
{
	if (start.x == end.x && start.y == end.y)
		return 0;
	const int next[4][2] = { {1,0},{0,2},{0,-2}, {-1,0} };  //下0右1左2上3
	info25 inf;
	queue25 xx;
	queue25 yy;
	queue25 ss;
	inf.x = start.x;
	inf.y = start.y;
	inf.step = 0;
	xx.push(start.x);
	yy.push(start.y);
	ss.push(start.step);
	bool b[100][100];
	for (int i = 0; i < 50; i++)  //标志是否入队
		for (int j = 0; j < 100; j++)
			b[i][j] = true;
	b[start.x][start.y] = false;//头已入队
	while (!xx.empty())
	{
		info25 top;
		top.x = xx.front();
		top.y = yy.front();
		top.step = ss.front();
		xx.pop();
		yy.pop();
		ss.pop();
		for (int i = 0; i < 4; i++)
		{
			inf.x = top.x + next[i][0];
			inf.y = top.y + next[i][1];
			point now;
			now.x = top.x;
			now.y = top.y;
			if (inf.x <= 0 || inf.x >= gp.n + 1 || inf.y <= 0 || inf.y >= gp.m + 2) //出界
				continue;
			if (ccheck25(now, snake, len, t, gp, i) != 0 && b[inf.x][inf.y])
			{
				inf.step = top.step + 10;
				xx.push(inf.x);
				yy.push(inf.y);
				ss.push(inf.step);
				b[inf.x][inf.y] = false; //标记已入队
			}
			if (inf.x == end.x && inf.y == end.y)
				return inf.step;
		}
	}
	return -1;
}

int find_path_ob25(info25 start, info25 end, point snake[5][100], int len[5], int t, GamePanel gp)
{
	if (start.x == end.x && start.y == end.y)
		return 0;
	const int next[8][2] = { {1,0},{0,2},{0,-2}, {-1,0},{1,2},{-1,2},{-1,-2},{1,-2} };  //下0右1左2上3 右下4 右上5 左上6 左下7
	info25 inf;
	queue25 xx;
	queue25 yy;
	queue25 ss;
	inf.x = start.x;
	inf.y = start.y;
	inf.step = 0;
	xx.push(start.x);
	yy.push(start.y);
	ss.push(start.step);
	bool b[100][100];
	for (int i = 0; i < 50; i++)  //标志是否入队
		for (int j = 0; j < 100; j++)
			b[i][j] = true;
	b[start.x][start.y] = false;//头已入队
	while (!xx.empty())
	{
		info25 top;
		top.x = xx.front();
		top.y = yy.front();
		top.step = ss.front();
		xx.pop();
		yy.pop();
		ss.pop();
		for (int i = 7; i >= 0; i--)
		{
			inf.x = top.x + next[i][0];
			inf.y = top.y + next[i][1];
			point now;
			now.x = top.x;
			now.y = top.y;
			if (inf.x <= 0 || inf.x >= gp.n + 1 || inf.y <= 0 || inf.y >= gp.m + 2) //出界
				continue;
			if (ccheck25(now, snake, len, t, gp, i) != 0 && b[inf.x][inf.y])
			{
				if (i >= 0 && i <= 3)
					inf.step = top.step + 10;
				else
					inf.step = top.step + 9;
				xx.push(inf.x);
				yy.push(inf.y);
				ss.push(inf.step);
				b[inf.x][inf.y] = false; //标记已入队
			}
			if (inf.x == end.x && inf.y == end.y)
				return inf.step;
		}
	}
	return -1;
}

food25 find_food25(info25 start, point snake[5][100], int len[5], int t, GamePanel gp)
{
	food25 food_info;
	if (gp.panel[start.x][start.y] == 1)
	{
		food_info.step = 0;
		food_info.x = start.x;
		food_info.y = start.y;
		return food_info;
	}
	const int next[4][2] = { {1,0},{0,2},{0,-2}, {-1,0} };  //下0右1左2上3
	info25 inf;
	queue25 xx;
	queue25 yy;
	queue25 ss;
	inf.x = start.x;
	inf.y = start.y;
	inf.step = 0;
	xx.push(start.x);
	yy.push(start.y);
	ss.push(start.step);
	bool b[100][100];
	for (int i = 0; i < 50; i++)  //标志是否入队
		for (int j = 0; j < 100; j++)
			b[i][j] = true;
	b[start.x][start.y] = false;//头已入队
	while (!xx.empty())
	{
		info25 top;
		top.x = xx.front();
		top.y = yy.front();
		top.step = ss.front();
		xx.pop();
		yy.pop();
		ss.pop();
		for (int i = 0; i < 4; i++)
		{
			inf.x = top.x + next[i][0];
			inf.y = top.y + next[i][1];
			point now;
			now.x = top.x;
			now.y = top.y;
			if (inf.x <= 1 || inf.x >= gp.n || inf.y <= 2 || inf.y >= gp.m) //出界
				continue;
			if (ccheck25(now, snake, len, t, gp, i) != 0 && b[inf.x][inf.y])
			{
				inf.step = top.step + 10;
				xx.push(inf.x);
				yy.push(inf.y);
				ss.push(inf.step);
				b[inf.x][inf.y] = false; //标记已入队
			}
			if (gp.panel[inf.x][inf.y] == 1)
			{
				food_info.step = inf.step;
				food_info.x = inf.x;
				food_info.y = inf.y;
				return food_info;
			}
		}
	}
	food_info.step = -1;
	return food_info;
}

food25 find_food_ob25(info25 start, point snake[5][100], int len[5], int t, GamePanel gp)
{
	food25 food_info;
	if (gp.panel[start.x][start.y] == 1)
	{
		food_info.step = 0;
		food_info.x = start.x;
		food_info.y = start.y;
		return food_info;
	}
	const int next[8][2] = { {1,0},{0,2},{0,-2}, {-1,0},{1,2},{-1,2},{-1,-2},{1,-2} };  //下0右1左2上3 右下4 右上5 左上6 左下7
	info25 inf;
	queue25 xx;
	queue25 yy;
	queue25 ss;
	inf.x = start.x;
	inf.y = start.y;
	inf.step = 0;
	xx.push(start.x);
	yy.push(start.y);
	ss.push(start.step);
	bool b[50][100];
	for (int i = 0; i < 50; i++)  //标志是否入队
		for (int j = 0; j < 100; j++)
			b[i][j] = true;
	b[start.x][start.y] = false;//头已入队
	while (!xx.empty())
	{
		info25 top;
		top.x = xx.front();
		top.y = yy.front();
		top.step = ss.front();
		xx.pop();
		yy.pop();
		ss.pop();
		for (int i = 7; i >= 0; i--)
		{
			inf.x = top.x + next[i][0];
			inf.y = top.y + next[i][1];
			point now;
			now.x = top.x;
			now.y = top.y;
			if (inf.x <= 1 || inf.x >= gp.n || inf.y <= 2 || inf.y >= gp.m) //出界
				continue;
			if (ccheck25(now, snake, len, t, gp, i) != 0 && b[inf.x][inf.y])
			{
				if (i >= 0 && i <= 3)
					inf.step = top.step + 10;
				else
					inf.step = top.step + 9;
				xx.push(inf.x);
				yy.push(inf.y);
				ss.push(inf.step);
				b[inf.x][inf.y] = false; //标记已入队
			}
			if (gp.panel[inf.x][inf.y] == 1)
			{
				food_info.step = inf.step;
				food_info.x = inf.x;
				food_info.y = inf.y;
				return food_info;
			}
		}
	}
	food_info.step = -1;
	return food_info;
}

int find_tail25(info25 start, point snake[5][100], int len[5], int t, GamePanel gp)
{
	if (start.x == snake[t][len[t]].x && start.y == snake[t][len[t]].y)
		return 0;
	const int next[4][2] = { {1,0},{0,2},{0,-2}, {-1,0} };  //下0右1左2上3
	info25 inf;
	queue25 xx;
	queue25 yy;
	queue25 ss;
	inf.x = start.x;
	inf.y = start.y;
	inf.step = 0;
	xx.push(start.x);
	yy.push(start.y);
	ss.push(start.step);
	bool b[100][100];
	for (int i = 0; i < 50; i++)  //标志是否入队
		for (int j = 0; j < 100; j++)
			b[i][j] = true;
	b[start.x][start.y] = false;//头已入队
	while (!xx.empty())
	{
		info25 top;
		top.x = xx.front();
		top.y = yy.front();
		top.step = ss.front();
		xx.pop();
		yy.pop();
		ss.pop();
		for (int i = 0; i < 4; i++)
		{
			inf.x = top.x + next[i][0];
			inf.y = top.y + next[i][1];
			point now;
			now.x = top.x;
			now.y = top.y;
			if (inf.x <= 0 || inf.x >= gp.n + 1 || inf.y <= 0 || inf.y >= gp.m + 2) //出界
				continue;
			if (ccheck25(now, snake, len, t, gp, i) != 0 && b[inf.x][inf.y])
			{
				inf.step = top.step + 10;
				xx.push(inf.x);
				yy.push(inf.y);
				ss.push(inf.step);
				b[inf.x][inf.y] = false; //标记已入队
			}
			if (inf.x == snake[t][len[t]].x && inf.y == snake[t][len[t]].y)
				return inf.step;
		}
	}
	return -1;
}

int find_tail_ob25(info25 start, point snake[5][100], int len[5], int t, GamePanel gp)
{
	if (start.x == snake[t][len[t]].x && start.y == snake[t][len[t]].y)
		return 0;
	const int next[8][2] = { {1,0},{0,2},{0,-2}, {-1,0},{1,2},{-1,2},{-1,-2},{1,-2} };  //下0右1左2上3 右下4 右上5 左上6 左下7
	info25 inf;
	queue25 xx;
	queue25 yy;
	queue25 ss;
	inf.x = start.x;
	inf.y = start.y;
	inf.step = 0;
	xx.push(start.x);
	yy.push(start.y);
	ss.push(start.step);
	bool b[50][100];
	for (int i = 0; i < 50; i++)  //标志是否入队
		for (int j = 0; j < 100; j++)
			b[i][j] = true;
	b[start.x][start.y] = false;//头已入队
	while (!xx.empty())
	{
		info25 top;
		top.x = xx.front();
		top.y = yy.front();
		top.step = ss.front();
		xx.pop();
		yy.pop();
		ss.pop();
		for (int i = 7; i >= 0; i--)
		{
			inf.x = top.x + next[i][0];
			inf.y = top.y + next[i][1];
			point now;
			now.x = top.x;
			now.y = top.y;
			if (inf.x <= 0 || inf.x >= gp.n + 1 || inf.y <= 0 || inf.y >= gp.m + 2) //出界
				continue;
			if (ccheck25(now, snake, len, t, gp, i) != 0 && b[inf.x][inf.y])
			{
				if (i >= 0 && i <= 3)
					inf.step = top.step + 10;
				else
					inf.step = top.step + 9;
				xx.push(inf.x);
				yy.push(inf.y);
				ss.push(inf.step);
				b[inf.x][inf.y] = false; //标记已入队
			}
			if (inf.x == snake[t][len[t]].x && inf.y == snake[t][len[t]].y)
			{
				return inf.step;
			}
		}
	}
	return -1;
}

int next_direction_close25(int direct, point head, point food, point snake[5][100], int len[5], int t, GamePanel gp)
{
	const int next[4][2] = { {1,0},{0,2},{0,-2}, {-1,0} };  //下0右1左2上3
	info25 around[4];
	for (int i = 0; i < 4; i++)
		around[i].step = -1;
	info25 start, end, tail;
	start.x = head.x;
	start.y = head.y;
	start.step = 0;
	end.x = food.x;
	end.y = food.y;
	end.step = 0;
	tail.x = snake[t][len[t]].x;
	tail.y = snake[t][len[t]].y;
	tail.step = 0;
	for (int i = 0; i < 4; i++)
	{
		if (i != 3 - direct)   //去掉蛇头方向
		{
			around[i].x = start.x + next[i][0];
			around[i].y = start.y + next[i][1];
			if (check25(snake, len, t, gp, i) == 0 || next_next25(snake, len, t, gp, i) == 0)
				around[i].step = -1;
			else
			{
				around[i].step = find_path25(around[i], end, snake, len, t, gp);
			}
		}
		else
			around[i].step = -1;
	}
	int min_step = 10000;
	int d = -1;
	for (int i = 0; i < 4; i++)
	{
		if (around[i].step != -1 && around[i].step < min_step)
		{
			min_step = around[i].step;
			d = i;
		}
	}
	return d;
}

int next_direction_close_ob25(int direct, point head, point food, point snake[5][100], int len[5], int t, GamePanel gp)
{
	const int next[8][2] = { {1,0},{0,2},{0,-2}, {-1,0},{1,2},{-1,2},{-1,-2},{1,-2} };  //下0右1左2上3 右下4 右上5 左上6 左下7
	info25 around[8];
	for (int i = 0; i < 8; i++)
		around[i].step = -1;
	info25 start, end, tail;
	start.x = head.x;
	start.y = head.y;
	start.step = 0;
	end.x = food.x;
	end.y = food.y;
	end.step = 0;
	tail.x = snake[t][len[t]].x;
	tail.y = snake[t][len[t]].y;
	tail.step = 0;
	for (int i = 0; i < 8; i++)
	{
		around[i].x = start.x + next[i][0];
		around[i].y = start.y + next[i][1];
		if (check25(snake, len, t, gp, i) == 0 || next_next_ob25(snake, len, t, gp, i) == 0)
			around[i].step = -1;
		else
		{
			around[i].step = find_path_ob25(around[i], end, snake, len, t, gp);
		}
	}
	int min_step = 10000;
	int d = -1;
	for (int i = 0; i < 8; i++)
	{
		if (around[i].step != -1 && around[i].step < min_step)
		{
			min_step = around[i].step;
			d = i;
		}
	}
	return d;
}

food25 next_direction_food25(int direct, point head, point snake[5][100], int len[5], int t, GamePanel gp)
{
	const int next[4][2] = { {1,0},{0,2},{0,-2}, {-1,0} };  //下0右1左2上3
	info25 around[4];
	food25 next_food[4];
	for (int i = 0; i < 4; i++)
		around[i].step = -1;
	info25 start, tail;
	start.x = head.x;
	start.y = head.y;
	start.step = 0;
	tail.x = snake[t][len[t]].x;
	tail.y = snake[t][len[t]].y;
	tail.step = 0;
	for (int i = 0; i < 4; i++)
	{
		if (i != 3 - direct)   //去掉蛇头方向
		{
			around[i].x = start.x + next[i][0];
			around[i].y = start.y + next[i][1];
			if (check25(snake, len, t, gp, i) == 0 || next_next25(snake, len, t, gp, i) == 0)
				around[i].step = -1;
			else
			{
				next_food[i] = find_food25(around[i], snake, len, t, gp);
				if (next_food[i].step != -1)
				{
					around[i].step = next_food[i].step;
				}
				else
					around[i].step = -1;
			}
		}
		else
			around[i].step = -1;
	}
	int min_step = 10000;
	food25 food_info;
	int d = -1;
	for (int i = 0; i < 4; i++)
	{
		if (around[i].step != -1 && around[i].step < min_step)
		{
			min_step = around[i].step;
			d = i;
		}
	}
	food_info.direct = d;
	if (d != -1)
	{
		food_info.x = next_food[d].x;
		food_info.y = next_food[d].y;
		food_info.step = next_food[d].step;
	}
	return food_info;
}

food25 next_direction_food_ob25(int direct, point head, point snake[5][100], int len[5], int t, GamePanel gp)
{
	const int next[8][2] = { {1,0},{0,2},{0,-2}, {-1,0},{1,2},{-1,2},{-1,-2},{1,-2} };  //下0右1左2上3 右下4 右上5 左上6 左下7
	info25 around[8];
	food25 next_food[8];
	for (int i = 0; i < 8; i++)
		around[i].step = -1;
	info25 start, tail;
	start.x = head.x;
	start.y = head.y;
	start.step = 0;
	tail.x = snake[t][len[t]].x;
	tail.y = snake[t][len[t]].y;
	tail.step = 0;
	for (int i = 0; i < 8; i++)
	{
		around[i].x = start.x + next[i][0];
		around[i].y = start.y + next[i][1];
		if (check25(snake, len, t, gp, i) == 0 || next_next_ob25(snake, len, t, gp, i) == 0)
			around[i].step = -1;
		else
		{
			next_food[i] = find_food25(around[i], snake, len, t, gp);
			if (next_food[i].step != -1)
			{
				around[i].step = next_food[i].step;
			}
			else
				around[i].step = -1;
		}
	}
	int min_step = 10000;
	food25 food_info;
	int d = -1;
	for (int i = 0; i < 8; i++)
	{
		if (around[i].step != -1 && around[i].step < min_step)
		{
			min_step = around[i].step;
			d = i;
		}
	}
	food_info.direct = d;
	if (d != -1)
	{
		food_info.x = next_food[d].x;
		food_info.y = next_food[d].y;
		food_info.step = next_food[d].step;
	}
	return food_info;
}
//判断对手下一步是否只有一步可走
point enemy_next25(point snake[5][100], int t, GamePanel gp, int len[5])
{
	int d = 0;
	int cc = 0;
	if (gp.obliqueowner[1 - t] != 1)
	{
		for (int i = 0; i < 4; i++)
		{
			if (ccheck25(snake[1 - t][1], snake, len, t, gp, i) != 0)
			{
				cc++;
				d = i;
			}
		}
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			if (ccheck25(snake[1 - t][1], snake, len, t, gp, i) != 0)
			{
				cc++;
				d = i;
			}
		}
	}
	if (cc == 1)
	{
		point next;
		switch (d)
		{
		case 0:
		{
			next.x = snake[1 - t][1].x + 1;
			next.y = snake[1 - t][1].y;
		}
		case 1:
		{
			next.x = snake[1 - t][1].x;
			next.y = snake[1 - t][1].y + 2;
		}
		case 2:
		{
			next.x = snake[1 - t][1].x;
			next.y = snake[1 - t][1].y - 2;
		}
		case 3:
		{
			next.x = snake[1 - t][1].x - 1;
			next.y = snake[1 - t][1].y;
		}
		case 4:
		{
			next.x = snake[1 - t][1].x + 1;
			next.y = snake[1 - t][1].y + 2;
		}
		case 5:
		{
			next.x = snake[1 - t][1].x - 1;
			next.y = snake[1 - t][1].y + 2;
		}
		case 6:
		{
			next.x = snake[1 - t][1].x - 1;
			next.y = snake[1 - t][1].y - 2;
		}
		case 7:
		{
			next.x = snake[1 - t][1].x + 1;
			next.y = snake[1 - t][1].y - 2;
		}
		}
		return next;
	}
	else
	{
		point next;
		next.x = -1;
		next.y = -1;
		return next;
	}
}

int enemy_wall25(point snake[5][100], int t, int len[5], GamePanel gp, int direct[5])
{
	if (((direct[1 - t] == 5 || direct[1 - t] == 1 || direct[1 - t] == 4) && (direct[t] != 6 && direct[t] != 2 && direct[t] != 7)) || ((direct[1 - t] == 6 || direct[1 - t] == 2 || direct[1 - t] == 7) && (direct[t] != 5 && direct[t] != 1 && direct[t] != 4)))
	{
		if (snake[1 - t][1].x <= 3 && snake[1 - t][2].x <= 3 && snake[1 - t][3].x <= 3)
		{
			if (direct[t] == 1 || direct[t] == 5 || direct[t] == 4)
			{
				if (snake[t][1].x <= 4 && snake[t][1].y > snake[1 - t][1].y&& snake[t][1].y <gp.m-2)
				{
					if (check25(snake, len, t, gp, 3) != 0)
						return 3;
				}
			}
			else if (direct[t] == 2 || direct[t] == 6 || direct[t] == 7)
			{
				if (snake[t][1].x <= 4 && snake[t][1].y < snake[1 - t][1].y && snake[t][1].y>4)
				{
					if (check25(snake, len, t, gp, 3) != 0)
						return 3;
				}
			}
		}
		if (snake[1 - t][1].x >= gp.n - 2 && snake[1 - t][2].x >= gp.n - 2 && snake[1 - t][3].x >= gp.n - 2)
		{
			if (direct[t] == 1 || direct[t] == 5 || direct[t] == 4)
			{
				if (snake[t][1].x >= gp.n - 4 && snake[t][1].y > snake[1 - t][1].y&& snake[t][1].y<gp.m-2)
				{
					if (check25(snake, len, t, gp, 4) != 0)
						return 4;
					if (check25(snake, len, t, gp, 0) != 0)
						return 0;
				}
			}
			else if (direct[t] == 2 || direct[t] == 6 || direct[t] == 7)
			{
				if (snake[t][1].x >= gp.n - 4 && snake[t][1].y < snake[1 - t][1].y && snake[t][1].y>4)
				{
					if (check25(snake, len, t, gp, 7) != 0)
						return 7;
					if (check25(snake, len, t, gp, 0) != 0)
						return 0;
				}
			}
		}
	}
	if (((direct[1 - t] == 6 || direct[1 - t] == 3 || direct[1 - t] == 5) && (direct[t] != 7 && direct[t] != 0 && direct[t] != 4)) || ((direct[1 - t] == 7 || direct[1 - t] == 0 || direct[1 - t] == 4) && (direct[t] != 6 && direct[t] != 3 && direct[t] != 5)))
	{
		if (snake[1 - t][1].y <= 6 && snake[1 - t][2].y <= 6 && snake[1 - t][3].y <= 6)
		{
			if (direct[t] == 3 || direct[t] == 6 || direct[t] == 5)
			{
				if (snake[t][1].y <= 8 && snake[t][1].x < snake[1 - t][1].x && snake[t][1].x>2)
				{
					if (check25(snake, len, t, gp, 6) != 0)
						return 6;
					if (check25(snake, len, t, gp, 2) != 0)
						return 2;
				}
			}
			else if (direct[t] == 0 || direct[t] == 7 || direct[t] == 4)
			{
				if (snake[t][1].y <= 8 && snake[t][1].x > snake[1 - t][1].x&& snake[t][1].x <gp.n-2)
				{
					if (check25(snake, len, t, gp, 7) != 0)
						return 7;
					if (check25(snake, len, t, gp, 2) != 0)
						return 2;
				}
			}
		}
		if (snake[1 - t][1].y >= gp.m - 4 && snake[1 - t][2].y >= gp.m - 4 && snake[1 - t][3].y >= gp.m - 4)
		{
			if (direct[t] == 3 || direct[t] == 6 || direct[t] == 5)
			{
				if (snake[t][1].y >= gp.m - 6 && snake[t][1].x < snake[1 - t][1].x && snake[t][1].x>2)
				{
					if (check25(snake, len, t, gp, 5) != 0)
						return 5;
					if (check25(snake, len, t, gp, 1) != 0)
						return 1;
				}
			}
			else if (direct[t] == 0 || direct[t] == 7 || direct[t] == 4)
			{
				if (snake[t][1].y >= gp.m - 6 && snake[t][1].x > snake[1 - t][1].x&& snake[t][1].x < gp.n - 2)
				{
					if (check25(snake, len, t, gp, 4) != 0)
						return 4;
					if (check25(snake, len, t, gp, 0) != 0)
						return 0;
				}
			}
		}
	}
	return -1;
}

int enemy_wall_ob25(point snake[5][100], int t, int len[5], GamePanel gp, int direct[5])
{
	if (((direct[1 - t] == 5 || direct[1 - t] == 1 || direct[1 - t] == 4) && (direct[t] != 6 && direct[t] != 2 && direct[t] != 7)) || ((direct[1 - t] == 6 || direct[1 - t] == 2 || direct[1 - t] == 7) && (direct[t] != 5 && direct[t] != 1 && direct[t] != 4)))
	{
		if (snake[1 - t][1].x <= 3 && snake[1 - t][2].x <= 3 && snake[1 - t][3].x <= 3)
		{
			if (direct[t] == 1 || direct[t] == 5 || direct[t] == 4)
			{
				if (snake[t][1].x <= 4 && snake[t][1].y > snake[1 - t][1].y&& snake[t][1].y<gp.m-2)
				{
					if (check25(snake, len, t, gp, 5) != 0)
						return 5;
				}
			}
			else if (direct[t] == 2 || direct[t] == 6 || direct[t] == 7)
			{
				if (snake[t][1].x <= 4 && snake[t][1].y < snake[1 - t][1].y && snake[t][1].y >4)
				{
					if (check25(snake, len, t, gp, 6) != 0)
						return 6;
				}
			}
		}
		if (snake[1 - t][1].x >= gp.n - 2 && snake[1 - t][2].x >= gp.n - 2 && snake[1 - t][3].x >= gp.n - 2)
		{
			if (direct[t] == 1 || direct[t] == 5 || direct[t] == 4)
			{
				if (snake[t][1].x >= gp.n - 4 && snake[t][1].y > snake[1 - t][1].y&& snake[t][1].y < gp.m - 2)
				{
					if (check25(snake, len, t, gp, 4) != 0)
						return 4;
				}
			}
			else if (direct[t] == 2 || direct[t] == 6 || direct[t] == 7)
			{
				if (snake[t][1].x >= gp.n - 4 && snake[t][1].y < snake[1 - t][1].y && snake[t][1].y > 4)
				{
					if (check25(snake, len, t, gp, 7) != 0)
						return 7;
				}
			}
		}
	}
	if (((direct[1 - t] == 6 || direct[1 - t] == 3 || direct[1 - t] == 5) && (direct[t] != 7 && direct[t] != 0 && direct[t] != 4)) || ((direct[1 - t] == 7 || direct[1 - t] == 0 || direct[1 - t] == 4) && (direct[t] != 6 && direct[t] != 3 && direct[t] != 5)))
	{
		if (snake[1 - t][1].y <= 6 && snake[1 - t][2].y <= 6 && snake[1 - t][3].y <= 6)
		{
			if (direct[t] == 3 || direct[t] == 6 || direct[t] == 5)
			{
				if (snake[t][1].y <= 8 && snake[t][1].x < snake[1 - t][1].x&& snake[t][1].x>2)
				{
					if (check25(snake, len, t, gp, 6) != 0)
						return 6;
				}
			}
			else if (direct[t] == 0 || direct[t] == 7 || direct[t] == 4)
			{
				if (snake[t][1].y <= 8 && snake[t][1].x > snake[1 - t][1].x&& snake[t][1].x <gp.n-2)
				{
					if (check25(snake, len, t, gp, 7) != 0)
						return 7;
				}
			}
		}
		if (snake[1 - t][1].y >= gp.m - 4 && snake[1 - t][2].y >= gp.m - 4 && snake[1 - t][3].y >= gp.m - 4)
		{
			if (direct[t] == 3 || direct[t] == 6 || direct[t] == 5)
			{
				if (snake[t][1].y >= gp.m - 6 && snake[t][1].x < snake[1 - t][1].x && snake[t][1].x>2)
				{
					if (check25(snake, len, t, gp, 5) != 0)
						return 5;
				}
			}
			else if (direct[t] == 0 || direct[t] == 7 || direct[t] == 4)
			{
				if (snake[t][1].y >= gp.m - 6 && snake[t][1].x > snake[1 - t][1].x&& snake[t][1].x <gp.n-2)
				{
					if (check25(snake, len, t, gp, 4) != 0)
						return 4;
				}
			}
		}
	}
	return -1;
}

int stage_last25(point food,point snake[5][100], int t, int len[5], GamePanel gp, int direct[5],int a)
{
		switch (a)
		{
		case 0:
		{
			if (check25(snake, len, t, gp, 1) != 0)
				return 1;
			else if (check25(snake, len, t, gp, 2) != 0)
				return 2;
			else
				return -1;
		}
		case 1:
		{
			if (check25(snake, len, t, gp, 3) != 0)
				return 3;
			else if (check25(snake, len, t, gp, 0) != 0)
				return 0;
			else
				return -1;
		}
		case 2:
		{
			if (check25(snake, len, t, gp, 0) != 0)
				return 0;
			else if (check25(snake, len, t, gp, 3) != 0)
				return 3;
			else
				return -1;
		}
		case 3:
		{
			if (check25(snake, len, t, gp, 1) != 0)
				return 1;
			else if (check25(snake, len, t, gp, 2) != 0)
				return 2;
			else
				return -1;
		}
		case 4:
		{
			if (check25(snake, len, t, gp, 2) != 0)
				return 2;
			else if (check25(snake, len, t, gp, 3) != 0)
				return 3;
			else
				return -1;
		}
		case 5:
		{
			if (check25(snake, len, t, gp, 0) != 0)
				return 0;
			else if (check25(snake, len, t, gp, 2) != 0)
				return 2;
			else
				return -1;
		}
		case 6:
		{
			if (check25(snake, len, t, gp, 0) != 0)
				return 0;
			else if (check25(snake, len, t, gp, 1) != 0)
				return 1;
			else
				return -1;
		}
		case 7:
		{
			if (check25(snake, len, t, gp, 1) != 0)
				return 1;
			else if (check25(snake, len, t, gp, 3) != 3)
				return 3;
			else
				return -1;
		}
		}
	return -1;
}

int machine_move25(point snake[5][100], int len[5], int direct[5], int t, GamePanel gp)
{
	//输了强制返回
	int noway = 0;
	if (gp.obliqueowner[t] != 1)
	{
		for (int i = 0; i < 4; i++)
			if (check25(snake, len, t, gp, i) != 0)
			{
				noway = 1;
				break;
			}
	}
	else
	{
		for (int i = 0; i < 8; i++)
			if (check25(snake, len, t, gp, i) != 0)
			{
				noway = 1;
				break;
			}
	}
	if (noway == 1)
	{
		int copy_panel[50][100] = { 0 };
		for (int i = 0; i < len[t]; i++)
		{
			copy_panel[snake[t][i].x][snake[t][i].y] = 5;
		}
		//围食物
		if (gp.stage == 1 && len[t] == 8)
		{
			point food;
			for (int i = 0; i < gp.totalfoodnum; i++)
			{
				if (gp.panel[gp.food[i].x][gp.food[i].y] == 1)
				{
					food.x = gp.food[i].x;
					food.y = gp.food[i].y;
					point around[8];
					int a = -1;
					int body = 0;
					const int next[8][2] = { {1,0},{0,2},{0,-2}, {-1,0},{1,2},{-1,2},{-1,-2},{1,-2} };
					for (int i = 0; i < 8; i++)
					{
						around[i].x = food.x + next[i][0];
						around[i].y = food.y + next[i][1];
						if (snake[t][1].x == around[i].x && snake[t][1].y == around[i].y)
						{
							a = i;
						}
						if (copy_panel[around[i].x][around[i].y] == 5)
							body++;
					}
					if (a != -1)
					{
						int d1 = pow((snake[t][1].x - food.x), 2) + pow((snake[t][1].y - food.y), 2) / 4;
						int d2 = pow((snake[1 - t][1].x - food.x), 2) + pow((snake[1 - t][1].y - food.y), 2) / 4;
						int d = stage_last25(food, snake, t, len, gp, direct, a);
						if (d1 + 10 < d2)
						{
							if (d != -1)
								return d;
						}
						if (body >= 7)
						{
							if (d != -1)
								return d;
						}
					}
				}
			}
		}
		//堵对手
		if (gp.obliqueowner[t] != 1)
		{
			if (pow(snake[t][1].x - snake[1 - t][1].x, 2) + pow(snake[t][1].y - snake[1 - t][1].y, 2) / 4 < 30)
			{
				if (enemy_wall25(snake, t, len, gp, direct) != -1 && enemy_wall25(snake, t, len, gp, direct) <= 3)
					return enemy_wall25(snake, t, len, gp, direct);
				point enemyNext;
				enemyNext = enemy_next25(snake, t, gp, len);
				if (enemyNext.x != -1 && enemyNext.y != -1)
				{
					point selfNext[4];
					const int next[8][2] = { {1,0},{0,2},{0,-2}, {-1,0},{1,2},{-1,2},{-1,-2},{1,-2} };    //下0右1左2上3 右下4 右上5 左上6 左下7
					for (int i = 0; i < 4; i++)
					{
						selfNext[i].x = snake[t][1].x + next[i][0];
						selfNext[i].y = snake[t][1].y + next[i][1];
						if (selfNext[i].x == enemyNext.x && selfNext[i].y == enemyNext.y && check25(snake, len, t, gp, i) != 0)
							return i;
					}
				}
			}
		}
		else
		{
			if (pow(snake[t][1].x - snake[1 - t][1].x, 2) + pow(snake[t][1].y - snake[1 - t][1].y, 2) / 4 < 20)
			{
				if (enemy_wall_ob25(snake, t, len, gp, direct) != -1)
					return enemy_wall_ob25(snake, t, len, gp, direct);
				point enemyNext;
				enemyNext = enemy_next25(snake, t, gp, len);
				if (enemyNext.x != -1 && enemyNext.y != -1)
				{
					point selfNext[8];
					const int next[8][2] = { {1,0},{0,2},{0,-2}, {-1,0},{1,2},{-1,2},{-1,-2},{1,-2} };    //下0右1左2上3 右下4 右上5 左上6 左下7
					for (int i = 0; i < 8; i++)
					{
						selfNext[i].x = snake[t][1].x + next[i][0];
						selfNext[i].y = snake[t][1].y + next[i][1];
						if (selfNext[i].x == enemyNext.x && selfNext[i].y == enemyNext.y && check25(snake, len, t, gp, i) != 0)
							return i;
					}

				}
			}
		}
		//己方最近食物
		int min;
		food25 next_food;
		if (gp.obliqueowner[t] != 1)
			next_food = next_direction_food25(direct[t], snake[t][1], snake, len, t, gp);
		else
			next_food = next_direction_food_ob25(direct[t], snake[t][1], snake, len, t, gp);
		//找尾巴
		if (next_food.direct != -1)
		{
			info25 find_tail;
			find_tail.x = next_food.x;
			find_tail.y = next_food.y;
			find_tail.step = 0;
			if (gp.obliqueowner[t] != 1)
			{
				if (find_tail25(find_tail, snake, len, t, gp) == -1)  //吃完找不到尾巴
					next_food.direct = -1;
			}
			else
			{
				if (find_tail_ob25(find_tail, snake, len, t, gp) == -1)  //吃完找不到尾巴
					next_food.direct = -1;
			}
		}

		min = pow((next_food.x - snake[t][1].x), 2) + pow((next_food.y - snake[t][1].y), 2) / 4;
		//敌方最近食物
		food25 othernext_food;
		if (gp.obliqueowner[t] != 1)
			othernext_food = next_direction_food25(direct[t], snake[t][1], snake, len, t, gp);
		else
			othernext_food = next_direction_food_ob25(direct[t], snake[t][1], snake, len, t, gp);
		//吃倍速
		int aa = 0, bb = 0;
		aa = pow((snake[t][1].x - gp.speedprops.x), 2) + pow((snake[t][1].y - gp.speedprops.y), 2) / 4;
		bb = pow((snake[1 - t][1].x - gp.speedprops.x), 2) + pow((snake[1 - t][1].y - gp.speedprops.y), 2) / 4;
		if (gp.speednum == 1 && (gp.obliquenum == 0 && gp.obliqueowner[t] == 1 || aa < 10))
		{
			if (aa < bb && aa < min + 10)
			{
				int dd = -1;
				info25 speed;
				speed.x = gp.speedprops.x;
				speed.y = gp.speedprops.y;
				speed.step = 0;
				if (gp.obliqueowner[t] != 1)
				{
					dd = next_direction_close25(direct[t], snake[t][1], gp.speedprops, snake, len, t, gp);
					if (find_tail25(speed, snake, len, t, gp) == -1)  //吃完找不到尾巴
						dd = -1;
				}
				else
				{
					dd = next_direction_close_ob25(direct[t], snake[t][1], gp.speedprops, snake, len, t, gp);
					if (find_tail_ob25(speed, snake, len, t, gp) == -1)  //吃完找不到尾巴
						dd = -1;
				}
				if (dd != -1)
					return dd;
				else
				{
					dd = next_food.direct;
					if (dd != -1)
						return dd;
					else
					{
						if (gp.obliqueowner[t] != 1)
							for (int i = 0; i < 4; i++)
							{
								if (check25(snake, len, t, gp, i) != 0)
									return i;
							}
						else
							for (int i = 0; i < 8; i++)
							{
								if (check25(snake, len, t, gp, i) != 0)
									return i;
							}
					}
				}
			}
			//a>b
			else
			{
				int dd = next_food.direct;
				if (dd != -1)
					return dd;
				else
				{
					int d = 0;
					int f = 1;
					while (f)
					{
						d = rand() % 4;
						if (check25(snake, len, t, gp, d) != 0)
							f = 0;
					}
					return d;
				}
			}
		}
		else
		{
			//吃斜走
			if (gp.obliquenum > 0)
			{
				if (gp.obliquenum == 2)
				{
					//计算斜走距离
					int min_ob;
					int min_num;
					int d1, d2, d3, d4;
					d1 = pow((gp.obliqueprops[0].x - snake[t][1].x), 2) + pow((gp.obliqueprops[0].y - snake[t][1].y), 2) / 4;
					d2 = pow((gp.obliqueprops[1].x - snake[t][1].x), 2) + pow((gp.obliqueprops[1].y - snake[t][1].y), 2) / 4;
					d3 = pow((gp.obliqueprops[0].x - snake[1 - t][1].x), 2) + pow((gp.obliqueprops[0].y - snake[1 - t][1].y), 2) / 4;
					d4 = pow((gp.obliqueprops[1].x - snake[1 - t][1].x), 2) + pow((gp.obliqueprops[1].y - snake[1 - t][1].y), 2) / 4;
					if (d3 < d1 && d4>d2)
					{
						min_ob = d2;
						min_num = 1;
					}
					else if (d3 > d1&& d4 < d2)
					{
						min_ob = d1;
						min_num = 0;
					}
					else if (d1 < d3 && d2 < d4)
					{
						if (d1 < d2)
						{
							min_ob = d1;
							min_num = 0;
						}
						else
						{
							min_ob = d2;
							min_num = 1;
						}
					}
					else
					{
						if (d3 < d4)
						{
							min_ob = d2;
							min_num = 1;
						}
						else
						{
							min_ob = d1;
							min_num = 0;
						}
					}
					int dd = -1;
					info25 obli;
					obli.x = gp.obliqueprops[min_num].x;
					obli.y = gp.obliqueprops[min_num].y;
					obli.step = 0;
					if (min_ob < min + 1000)
					{
						if (gp.obliqueowner[t] != 1)
						{
							dd = next_direction_close25(direct[t], snake[t][1], gp.obliqueprops[min_num], snake, len, t, gp);
							if (find_tail25(obli, snake, len, t, gp) == -1)
								dd = -1;
						}
						else
						{
							dd = next_direction_close_ob25(direct[t], snake[t][1], gp.obliqueprops[min_num], snake, len, t, gp);
							if (find_tail_ob25(obli, snake, len, t, gp) == -1)
								dd = -1;
						}
					}
					else
					{
						dd = next_food.direct;
					}
					if (dd != -1)
						return dd;
					else
					{
						if (gp.obliqueowner[t] != 1)
							for (int i = 0; i < 4; i++)
							{
								if (check25(snake, len, t, gp, i) != 0)
									return i;
							}
						else
							for (int i = 0; i < 8; i++)
							{
								if (check25(snake, len, t, gp, i) != 0)
									return i;
							}
					}
				}
				//一个斜走道具
				else
				{
					int min_ob;
					int min_num;
					if (gp.panel[gp.obliqueprops[0].x][gp.obliqueprops[0].y] == 4)
					{
						min_ob = pow((gp.obliqueprops[0].x - snake[t][1].x), 2) + pow((gp.obliqueprops[0].y - snake[t][1].y), 2) / 4;
						min_num = 0;
					}
					else
					{
						min_ob = pow((gp.obliqueprops[1].x - snake[t][1].x), 2) + pow((gp.obliqueprops[1].y - snake[t][1].y), 2) / 4;
						min_num = 1;
					}
					info25 obli;
					obli.x = gp.obliqueprops[min_num].x;
					obli.y = gp.obliqueprops[min_num].y;
					obli.step = 0;
					int d1 = pow((gp.obliqueprops[min_num].x - snake[t][1].x), 2) + pow((gp.obliqueprops[min_num].y - snake[t][1].y), 2) / 4;
					int d2 = pow((gp.obliqueprops[min_num].x - snake[1 - t][1].x), 2) + pow((gp.obliqueprops[min_num].y - snake[1 - t][1].y), 2) / 4;
					int dd = -1;
					if (gp.obliqueowner[t] == 1 || d1 < d2)
					{
						if (gp.obliqueowner[t] != 1)
						{
							dd = next_direction_close25(direct[t], snake[t][1], gp.obliqueprops[min_num], snake, len, t, gp);
							if (find_tail25(obli, snake, len, t, gp) == -1)
								dd = -1;
						}
						else
						{
							dd = next_direction_close_ob25(direct[t], snake[t][1], gp.obliqueprops[min_num], snake, len, t, gp);
							if (find_tail_ob25(obli, snake, len, t, gp) == -1)
								dd = -1;
						}
					}
					else
					{
						dd = next_food.direct;
					}
					if (dd != -1)
						return dd;
				}
			}
			//界面已无斜走可吃 吃食物
			else
			{
				int dd = next_food.direct;
				int ff = 0;
				if (next_food.direct != -1 && othernext_food.direct != -1 && next_food.step > othernext_food.step&& next_food.x == othernext_food.x && next_food.y == othernext_food.y)
				{
					ff = 1;
				}
				if (gp.currentfoodnum == 1)
				{
					if (dd != -1)
						return dd;
					else
					{
						int ff = 0;
						for (int i = next_food.x - 2; i <= next_food.x + 2; i++)
							for (int j = next_food.y - 4; j <= next_food.y + 4; j++)
							{
								if (i >= 1 && i <= gp.n && j >= 2 && j <= gp.m)
								{
									if (copy_panel[i][j] == 5)
									{
										ff++;
									}
								}
							}
						if (ff < 4)
						{
							if (gp.obliqueowner[t] == 1)
							{
								if (next_food.direct != -1)
									return next_food.direct;
							}
							/*
							else
							{
								const int next[4][2] = { {1,0},{0,2},{0,-2}, {-1,0} };  //下0右1左2上3
								info25 around[4];
								for (int i = 0; i < 4; i++)
									around[i].step = -1;
								info25 start, end, tail;
								start.x = snake[t][1].x;
								start.y = snake[t][1].y;
								start.step = 0;
								end.x = next_food.x;
								end.y = next_food.y;
								end.step = 0;
								tail.x = snake[t][len[t]].x;
								tail.y = snake[t][len[t]].y;
								tail.step = 0;
								for (int i = 0; i < 4; i++)
								{
									around[i].x = start.x + next[i][0];
									around[i].y = start.y + next[i][1];
									if (check25(snake, len, t, gp, i) == 0)
										around[i].step = -1;
									else
									{
										around[i].step = find_path_ob25(around[i], end, snake, len, t, gp);
									}
								}
								int min_step = 10000;
								int d = -1;
								for (int i = 0; i < 4; i++)
								{
									if (around[i].step != -1 && around[i].step < min_step)
									{
										min_step = around[i].step;
										d = i;
									}
								}
								if (d != -1)
									return d;
							}
							*/
						}
					}
				}
				else
				{
					if (dd != -1 && ff == 0)
						return dd;
					//找次近食物
					else
					{
						int d = 0;
						int min = 100000;
						int food_num = -1;
						for (int i = 0; i < gp.totalfoodnum; i++)
						{
							if (gp.panel[gp.food[i].x][gp.food[i].y] == 1)
							{
								int f = 0;
								d = pow((gp.food[i].x - snake[t][1].x), 2) + pow((gp.food[i].y - snake[t][1].y), 2) / 4;   //蛇头与食物距离
								if (gp.food[i].x == next_food.x && gp.food[i].y == next_food.y)
									f = 1;
								if (d < min && f == 0)
								{
									min = d;
									food_num = i;
								}
							}
						}
						info25 food;
						food.x = gp.food[food_num].x;
						food.y = gp.food[food_num].y;
						int dddd = -1;
						if (gp.obliqueowner[t] != 1)
						{
							dddd = next_direction_close25(direct[t], snake[t][1], gp.food[food_num], snake, len, t, gp);
							if (find_tail25(food, snake, len, t, gp) == -1)
								dddd = -1;
						}
						else
						{
							dddd = next_direction_close_ob25(direct[t], snake[t][1], gp.food[food_num], snake, len, t, gp);
							if (find_tail_ob25(food, snake, len, t, gp) == -1)
								dddd = -1;
						}
						if (dddd != -1)
							return dddd;
						else
						{
							if (ff == 0)
							{
								int ff = 0;
								for (int i = next_food.x - 2; i <= next_food.x + 2; i++)
									for (int j = next_food.y - 4; j <= next_food.y + 4; j++)
									{
										if (i >= 1 && i <= gp.n && j >= 2 && j <= gp.m)
										{
											if (copy_panel[i][j] == 5)
											{
												ff++;
											}
										}
									}
								if (ff < 4)
								{
									if (gp.obliqueowner[t] == 1)
									{
										const int next[8][2] = { {1,0},{0,2},{0,-2}, {-1,0},{1,2},{-1,2},{-1,-2},{1,-2} };  //下0右1左2上3 右下4 右上5 左上6 左下7
										info25 around[8];
										for (int i = 0; i < 8; i++)
											around[i].step = -1;
										info25 start, end, tail;
										start.x = snake[t][1].x;
										start.y = snake[t][1].y;
										start.step = 0;
										end.x = next_food.x;
										end.y = next_food.y;
										end.step = 0;
										tail.x = snake[t][len[t]].x;
										tail.y = snake[t][len[t]].y;
										tail.step = 0;
										for (int i = 0; i < 8; i++)
										{
											around[i].x = start.x + next[i][0];
											around[i].y = start.y + next[i][1];
											if (check25(snake, len, t, gp, i) == 0)
												around[i].step = -1;
											else
											{
												around[i].step = find_path_ob25(around[i], end, snake, len, t, gp);
											}
										}
										int min_step = 10000;
										int d = -1;
										for (int i = 0; i < 8; i++)
										{
											if (around[i].step != -1 && around[i].step < min_step)
											{
												min_step = around[i].step;
												d = i;
											}
										}
										if (d != -1)
											return d;
									}
									else
									{
										const int next[4][2] = { {1,0},{0,2},{0,-2}, {-1,0} };  //下0右1左2上3
										info25 around[4];
										for (int i = 0; i < 4; i++)
											around[i].step = -1;
										info25 start, end, tail;
										start.x = snake[t][1].x;
										start.y = snake[t][1].y;
										start.step = 0;
										end.x = next_food.x;
										end.y = next_food.y;
										end.step = 0;
										tail.x = snake[t][len[t]].x;
										tail.y = snake[t][len[t]].y;
										tail.step = 0;
										for (int i = 0; i < 4; i++)
										{
											around[i].x = start.x + next[i][0];
											around[i].y = start.y + next[i][1];
											if (check25(snake, len, t, gp, i) == 0)
												around[i].step = -1;
											else
											{
												around[i].step = find_path_ob25(around[i], end, snake, len, t, gp);
											}
										}
										int min_step = 10000;
										int d = -1;
										for (int i = 0; i < 4; i++)
										{
											if (around[i].step != -1 && around[i].step < min_step)
											{
												min_step = around[i].step;
												d = i;
											}
										}
										if (d != -1)
											return d;
									}
								}
							}
							else
							{
								if (food_num != -1)
								{
									int ff = 0;
									for (int i = gp.food[food_num].x - 2; i <= gp.food[food_num].x + 2; i++)
										for (int j = gp.food[food_num].y - 4; j <= gp.food[food_num].y + 4; j++)
										{
											if (i >= 1 && i <= gp.n && j >= 2 && j <= gp.m)
											{
												if (copy_panel[i][j] == 5)
												{
													ff++;
												}
											}
										}
									if (ff < 4)
									{
										if (gp.obliqueowner[t] == 1)
										{
											const int next[8][2] = { {1,0},{0,2},{0,-2}, {-1,0},{1,2},{-1,2},{-1,-2},{1,-2} };  //下0右1左2上3 右下4 右上5 左上6 左下7
											info25 around[8];
											for (int i = 0; i < 8; i++)
												around[i].step = -1;
											info25 start, end, tail;
											start.x = snake[t][1].x;
											start.y = snake[t][1].y;
											start.step = 0;
											end.x = next_food.x;
											end.y = next_food.y;
											end.step = 0;
											tail.x = snake[t][len[t]].x;
											tail.y = snake[t][len[t]].y;
											tail.step = 0;
											for (int i = 0; i < 8; i++)
											{
												around[i].x = start.x + next[i][0];
												around[i].y = start.y + next[i][1];
												if (check25(snake, len, t, gp, i) == 0)
													around[i].step = -1;
												else
												{
													around[i].step = find_path_ob25(around[i], end, snake, len, t, gp);
												}
											}
											int min_step = 10000;
											int d = -1;
											for (int i = 0; i < 8; i++)
											{
												if (around[i].step != -1 && around[i].step < min_step)
												{
													min_step = around[i].step;
													d = i;
												}
											}
											if (d != -1)
												return d;
										}
										/*
										else
										{
											const int next[4][2] = { {1,0},{0,2},{0,-2}, {-1,0} };  //下0右1左2上3
											info25 around[4];
											for (int i = 0; i < 4; i++)
												around[i].step = -1;
											info25 start, end, tail;
											start.x = snake[t][1].x;
											start.y = snake[t][1].y;
											start.step = 0;
											end.x = next_food.x;
											end.y = next_food.y;
											end.step = 0;
											tail.x = snake[t][len[t]].x;
											tail.y = snake[t][len[t]].y;
											tail.step = 0;
											for (int i = 0; i < 4; i++)
											{
												around[i].x = start.x + next[i][0];
												around[i].y = start.y + next[i][1];
												if (check25(snake, len, t, gp, i) == 0)
													around[i].step = -1;
												else
												{
													around[i].step = find_path_ob25(around[i], end, snake, len, t, gp);
												}
											}
											int min_step = 10000;
											int d = -1;
											for (int i = 0; i < 4; i++)
											{
												if (around[i].step != -1 && around[i].step < min_step)
												{
													min_step = around[i].step;
													d = i;
												}
											}
											if (d != -1)
												return d;
										}
										*/
									}
								}
							}
						}
					}
				}
			}
		}

		const int next[4][2] = { {1,0},{0,2},{0,-2}, {-1,0} };  //下0右1左2上3
		info25 around[4];
		for (int i = 0; i < 4; i++)
			around[i].step = -1;
		info25 start, end;
		start.x = snake[t][1].x;
		start.y = snake[t][1].y;
		start.step = 0;
		int ddd = -1;
		int max_step = 0;
		for (int i = 0; i < 4; i++)
		{
			around[i].x = start.x + next[i][0];
			around[i].y = start.y + next[i][1];
			if (check25(snake, len, t, gp, i) == 0)
				around[i].step = -1;
			else
			{
				for (int p = start.x - 3; p <= start.x + 3; p++)
					for (int q = start.y - 6; q <= start.y + 6; q += 2)
					{
						if (p >= 1 && p <= gp.n && q >= 2 && q <= gp.m)
						{
							end.x = p;
							end.y = q;
							end.step = 0;
							int s = find_path25(around[i], end, snake, len, t, gp);
							if (max_step < s)
							{
								max_step = s;
								ddd = i;
							}
						}
					}
			}
		}
		if (ddd != -1)
			return ddd;
		else
		{
			for (int i = 0; i < 8; i++)
			{
				if (check25(snake, len, t, gp, i) != 0)
					return i;
			}
		}
	}
	else
	{
		return 0;
	}
	return 0;
}


