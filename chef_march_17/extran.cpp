#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
				int t, n;
				long long int a[100000], res;
				cin >> t;
				while(t--) {
								cin >> n;

								for(int i = 0; i < n; i++) {
												cin >> a[i];
								}
								sort(a, a+n);
								res = 0;

								for(int i = 0; i < n-1; i++) {
												if(i == 0) {
														if(a[0] + 1 != a[1]) {
																res = a[0];
																break;
														}
												} else {
														if(a[i] + 1 != a[i + 1]) {
																		res = a[i+1];
																		break;
														}
												}
								}
								cout << res << endl;
				}
				return 0;
}
