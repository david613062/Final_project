int first(int n)
{
 for (i = 0; i < row*column; i++)
 {
  if (map[n][i] == 1)
   return i;
 }
 printf("起點為故障點，請輸入一個不為故障點的起點\n");
 return 0;
}


//
//返回第n個節點相鄰的點的個數
// 
int sumCount(int n)
{
 int count = 0;
 for (i = 0; i < row*column; i++)
 {
  if (map[n][i] == 1)
   count++;
 }
 return count;
}