//
//DFS尋找所有路徑 
//
void DFS(int nowPoint, int count)
{
	char direction;
	visited[nowPoint] = 1;
	path[count++] = nowPoint; //儲存正確路徑
	if (startPoint > endPoint) {
		direction = 'L'; //如果終點數字大於起點數字只能往左下走
	}else if (startPoint < endPoint) {
		direction = 'R'; //如果起點數字大於終點數字只能往右上走
	}
	if (nowPoint == endPoint && (count) >= 1)
	{
		int select = 0;

		if (direction == 'R') {
			for (i = 0; i < (count)-1; i++) {
				if (path[i] > path[i + 1])
					select = 1;		
			} //判斷往右上走的路徑是否正確
		}else if (direction == 'L') {
			for (i = 0; i < (count)-1; i++) {
				if (path[i] < path[i + 1])
					select = 1;		
			} //判斷往左下走的路徑是否正確
		} //正確select=0

		if (select == 0) {
			pathNumber++;
			printf("這兩個城市間第%d條簡單路徑為: ", pathNumber);

			for (i = 0; i < (count)-1; i++)
			{
				printf("%d-->", path[i] + 1);
			}
			printf("%d\n", path[(count)-1] + 1);
			select = 0;
		}
	}
	else
	{
		int k;
		for (k = first(nowPoint); k < row*column; k = next(nowPoint, k))
		{
			if (visited[k] == 0)
				DFS(k, count);
		}
	}
	visited[nowPoint] = 0;  //將走過的路徑設為0 
	(count)--;
	return;
}


int main()
{
	int count = 0, pathNumber = 0;
	printf("請輸入要生成圖的行和列：\n");
	scanf("%d%d", &row, &column);
	createGraphics();
	printf("請輸入要找到路徑的起點和終點:\n");
	scanf("%d%d", &startPoint, &endPoint);
	if (startPoint != endPoint) {
		startPoint--;
		endPoint--;
		DFS(startPoint, count);
	}else {
		printf("\n選擇錯誤\n\n");
	}
	system("pause");
	return 0;
}