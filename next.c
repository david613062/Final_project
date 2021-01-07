int next(int n, int now)
{
	for (i = now + 1; i < row*column; i++)
	{
		if (map[n][i] == 1)
			return i;
	}
	return 1000;  //當找不到節點n的下一個節點，返回1000
}