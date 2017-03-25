#include <iostream>
using namespace std;

int main()
{
				int t;
				string s;
				cin >> t;

				while(t--) {
								int idx[26][2];
								cin >> s;

								for(int i = 0; i < 26;i++) {
												idx[i][0] = idx[i][1] = -1;
								}

								for(int i = 0; i < s.length(); i++) {
												if(idx[s[i]-'a'][0] == -1) {
																idx[s[i]-'a'][0] = i;
												} else {
																idx[s[i]-'a'][1] = i;
												}
								}

								int maxdiff = -1;
								for(int i = 0; i < 26; i++) {
												if(idx[i][1] == -1) continue;
												int diff = (idx[i][1] - idx[i][0]) - 1; 
												if (diff > maxdiff) {
																maxdiff = diff;
												}
								}

								cout << maxdiff << endl;

				}

				return 0;
}

