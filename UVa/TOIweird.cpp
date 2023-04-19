#include <bits/stdc++.h>
using namespace std;


signed main()
{
	int N;
	bool space = 0;
	while(cin >> N)
	{
		bool found = 0;
		if(!N)
			break;
		if(space)
			cout << '\n';
		space = 1;
		for(int a = 01234; a < 100000 / N; a++)
		{
			int b = a * N;
			set<int> st;
			for(int i = 0; i <= 9; i++)
				st.insert(i);
			for(int i = 1; i <= 10000; i *= 10)
			{
				auto iter = st.find(a / i % 10);
				if(iter == st.end())
					break;
				st.erase(iter);
			}
			for(int i = 1; i <= 10000; i *= 10)
			{
				auto iter = st.find(b / i % 10);
				if(iter == st.end())
					break;
				st.erase(iter);
			}
			
			if(st.empty())
			{
				found = 1;
					if(b <= 9999)
						cout << 0;
					cout << b;
				cout << " / ";
					if(a <= 9999)
						cout << 0;
					cout << a;
				

				cout << " = " << N << '\n';
			}
		}
		if(!found)
			cout << "There are no solutions for " << N << ".\n";
	}
}
