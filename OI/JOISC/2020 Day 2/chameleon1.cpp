}

void Solve(int N) 
{
	for(int i = 1; i <= 2 * N; i++)
	{
		v.emplace_back(i);
		if(Query(v) != v.size())
		{
			v.pop_back();
			int ans = bs(v, i);
			cerr << i << " is same with " << ans << '\n';
			Answer(i, ans);
		}		
	}
}
