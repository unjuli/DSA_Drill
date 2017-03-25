#include <iostream>
using namespace std;

int main()
{
				int t, n, x;
				long int sum1e, sum1o, sum2e, sum2o;
				cin >> t;
				while(t--) {
								cin >> n;
								sum1e = sum1o = sum2e = sum2o = 0;
								for(int i = 0; i < n; i ++) {
												cin >> x;
												if(i%2==0) {
																sum1e += x;
												} else {
																sum1o += x;
												}
								}
								for(int i = 0; i < n; i ++) {
												cin >> x;
												if(i%2==0) {
																sum2e += x;
												} else {
																sum2o += x;
												}
								}

								if (sum1e + sum2o < sum1o + sum2e) {
									cout << sum1e+sum2o << endl;
								} else {
									cout << sum1o+sum2e << endl;
								}
				}

				return 0;
}
