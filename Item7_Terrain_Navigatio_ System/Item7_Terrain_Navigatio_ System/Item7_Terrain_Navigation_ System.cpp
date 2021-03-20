#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <Windows.h>

using namespace std;

#define N 64

bool isPeak(const double grid[N][N], int r, int c);
bool isValley(const double grid[N][N], int r, int c);
void extremes(const double grid[N][N], int row, int column);

int main(void) {
	int nrows, ncols;
	double map[N][N];
	string filename;
	ifstream file;

	cout << "请输出文件名:  ";
	cin >> filename;

	file.open(filename.c_str());
	if(file.fail()) {
		cout << "文件名输入错误.\n";
		system("pause");
		exit(1);
	}

	file >> nrows >> ncols;

	if((nrows >N) || (ncols >N)) {
		cout << "文件格子太大.\n";
		system("pause");
		exit(1);
	}

	//从数据文件读数据到数组
	for(int i=0; i<nrows; i++) {
		for(int j=0; j<ncols; j++) {
			file >> map[i][j];
		}
	}
	
	int count= 0;  //int total_peaks = 0;
	//判断并打印峰值位置
	for(int i=1; i<nrows-1; i++) {
		for(int j=1; j<ncols-1; j++) {
			if(isPeak(map, i, j)) {
				count++;
				cout << "峰点出现在:  " << i+1  << "行  " << j+1  << "  列." << endl;
			}
		}
	}
	cout << "一共有" << count << "个峰点.\n" << endl;

	int count1 = 0;
	for(int i=1; i<=nrows-1; i++) {
		for(int j=1; j<=ncols-1; j++) {
			if(isValley(map, i, j)) {
				count1++;
				cout << "峰谷出现在:  " << i+1 << "行  " << j+1 << "  列." << endl;
			}
		}
	}
	cout << "一共有" << count1 << "个谷点.\n" << endl;

	//打印海拔的最大值和最小值,以及他们所在的位置
	extremes(map, nrows, ncols);

	system("pause");
	file.close();
	return 0;
}

bool isPeak(const double grid[N][N], int r, int c) {
	assert(0<r && r<N-1);
	assert(0<c && c<N-1);`

	if((grid[r][c]>grid[r-1][c-1]) &&  //当前元素的上一行
		(grid[r][c]>grid[r-1][c]) &&		//当前元素的上一行
		(grid[r][c]>grid[r-1][c+1]) &&//当前元素的上一行 
		(grid[r][c]>grid[r][c-1]) &&		//当前元素的所在行
		(grid[r][c]>grid[r][c+1]) &&	//当前元素的所在行
		(grid[r][c]>grid[r+1][c-1]) &&//当前元素的下一行
		(grid[r][c]>grid[r+1][c]) &&	//当前元素的下一行
		(grid[r][c]>grid[r+1][c+1])) {	//当前元素的下一行
			return true;
	} else {
		return false;
	}
}

bool isValley(const double grid[N][N], int r, int c) {
	assert(0<r && r<N-1);
	assert(0<c && c<N-1);

	if((grid[r][c]<grid[r-1][c]) &&
		(grid[r][c]<grid[r+1][c]) &&
		(grid[r][c]<grid[r][c-1]) &&
		(grid[r][c]<grid[r][c+1])) {
			return true;
	} else {
		return false;
	}
}

void extremes(const double grid[N][N], int row, int column) {
	assert(0<=row && row<N);
	assert(0<=column && column<N);

	int pos[2][2]={0};  //pos[0][0] pos[0][1] 保存最高点的坐标  pso[1][0] pos[1][1] 保存最低点的坐标

	double max = grid[0][0];
	double min = grid[0][0];
	for(int i=0; i<row; i++) {
		for(int j=0; j<column; j++) {
			if(max<grid[i][j]) {
				max = grid[i][j];
				pos[0][0] = i;
				pos[0][1] = j;
			}

			if(min>grid[i][j]) {
				min = grid[i][j];
				pos[1][0] = i;
				pos[1][1] = j;
			}
		}
	}
	printf("海拔的最大值及位置是:  %lf, %d行, %d列.\n", max, pos[0][0] + 1, pos[0][1] + 1);

	printf("海拔的最小值及位置是:  %lf, %d行, %d列.\n", min, pos[1][0] + 1, pos[1][1] + 1);
}