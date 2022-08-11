#include <iostream>
#include <deque>
#include <algorithm>//sort
using namespace std;

struct Tree {
	int age;
	bool live;
};

bool sortTree(Tree &A, Tree &B) {
	return A.age < B.age;
}

int N, M, K;
int Map[11][11];//남은 양분 표시
int A[11][11];//인덱스 (1,1)~(N,N)
deque<Tree>tree[11][11];//각 칸 나무 나이들
const int dxy[][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };

//봄 양분 먹기
void Spring() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			//해당 칸 나무 개수
			int tree_cnt = tree[i][j].size();
			//나무 없으면
			if (tree_cnt == 0)
				continue;
			//순서대로 양분 먹기
			for (int t = 0; t < tree_cnt; t++) {
				int age = tree[i][j][t].age;
				//양분 먹을 수 있으면
				if (age <= Map[i][j]) {
					//양분 먹고 나이 + 1
					Map[i][j] -= age;
					tree[i][j][t].age++;
				}
				//양분 부족하면
				else {
					tree[i][j][t].live = false;
				}
			}
		}
	}
}

//여름 죽은 나무 양분으로
void Summer() {
	//각 칸에서 죽은 나무들 양분으로
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tree_cnt = tree[i][j].size();
			int dead = -1;
			int toFood = 0;
			for (int t = 0; t < tree_cnt; t++) {
				//죽은 나무 발견
				if (tree[i][j][t].live == false) {
					if (dead == -1)
						dead = t;
					toFood += tree[i][j][t].age / 2;
				}
			}
			if (dead >= 0) {
				tree[i][j].erase(tree[i][j].begin() + dead, tree[i][j].end());
				Map[i][j] += toFood;
			}
		}
	}
}

//가을 번식
void Autumn() {
	//각 칸에 나이 5배수인 나무 있으면 번식
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			//해당 칸 나무 개수
			int tree_cnt = tree[i][j].size();
			for (int t = 0; t < tree_cnt; t++) {
				int age = tree[i][j][t].age;
				//5배수면 번식
				if (age % 5 == 0) {
					for (int d = 0; d < 8; d++) {
						int nx = i + dxy[d][0];
						int ny = j + dxy[d][1];
						if (nx <= 0 || nx > N || ny <= 0 || ny > N)
							continue;
						//나이 1살 나무 제일 앞에 넣어주기
						tree[nx][ny].push_front({1,true});
					}
				}
			}
		}
	}
}

//양분 추가
void Winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Map[i][j] += A[i][j];
		}
	}
}

int countTree() {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cnt += tree[i][j].size();
		}
	}
	return cnt;
}

void solution() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			Map[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back({z,true});
	}
	//각 칸 나무 나이순으로 정렬
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sort(tree[i][j].begin(), tree[i][j].end(), sortTree);
		}
	}
	while (K--) {
		Spring();
		Summer();
		Autumn();
		Winter();
	}
	int res = countTree();
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solution();
	return 0;
}