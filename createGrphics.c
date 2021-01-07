void createGraphics()
{
	int tmp[4][2] = { {0,1},{1,0},{-1,0},{0,-1} }; //上 右 左 下
	memset(map, 0, sizeof(map));//把圖初始化為0
	for (i = 0; i < row*column; i++)
	{
		//找到該點上下左右4個點初始map 
		int r = i / column;//X軸座標
		int c = i % column;//Y軸座標
		for (j = 0; j < 4; j++)//每個點最多有4個路徑
		{
			//（r,c)相鄰的點為（r1,c1) 
			int r1 = r + tmp[j][0];
			int c1 = c + tmp[j][1];	//偵測路徑
			if (r1 >= 0 && r1 < row&&c1 >= 0 && c1 < column)//限制圖的大小
			{
				map[i][r1*column + c1] = 1;//把會用到的路徑設為1
			}
		}
	}
}