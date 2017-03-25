#include <iostream>
using namespace std;

int main()
{
				int n,m,k;
				int r, c, s, num;
				cin >> n >> m >> k;
				int mat[1000][1000];

				for(int i = 0; i < n; i++) {
								for(int j = 0; j < m; j++) {
												cin >> mat[i][j];
								}
				}

				for(int i = 0; i < k; i++) {
								cin >> r >> c >> s >> num;

								for(int j = r-1; j < r+s-1; j++) {
												for(int l = c-1; l < c+s-1; l++ ) {
																mat[j][l] += num;
												}
								}
				}

				for(int i = 0; i < n; i++) {
								for(int j = 0; j < m; j++) {
												cout << mat[i][j] << " ";
								}
								cout << endl;
				}
				return 0;
}

