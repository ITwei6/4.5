#include <stdio.h>


//插入排序
void Insert(int* a,int n)
{
	for (int i = 1; i < n; i++)//这里从从数组第二个元素开始往后插入，默认数组第一个元素就插入进去
	{
		//一趟排序
		int end=i-1;//表示最后一个元素的下标----第一个元素位置下标为0
		int tmp=a[i];//表示要插入的数据---从第二个元素开始插入，第二个元素位置是i
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				//这里表明a[end]比tmp要小了,但end+1上才是空位
				break;
			}
		}
		//走到这里有两种可能，一种是a[end]比tmp小，循环停止break跳出来了，另一种就是循环一直走，直到结束
		//也就是数组里每个元素都比要插入的元素要大那end就跑到-1去了
		//最后tmp总归要去end+1的位置上去的
		a[end + 1] = tmp;//这是一趟
	}
	
}
//希尔排序--预排序--排序
void Shellsort(int *a,int n)
{
	int gap = n;
	while (gap)
	{
		gap/=2;
		for (int j = 0; j < gap; j++)
		{
			//希尔排序的特点就是分成gap区间 假设gap为3的话，就分成3部分--假设红黄黑
			for (int i = j; i < n - gap; i += gap)
			{
				//先写一趟--也就是红色
				int end = i;
				int tmp = a[i + gap];
				while (end >= 0)
				{
					if (a[end] > tmp)
					{
						//往前移动gap位置，end每次移动gap
						a[end + gap] = a[end];
						end -= gap;
					}
					else
					{
						break;
					}
				}
				//tmp总归要插入到a[end+gap]位置上去的
				a[end + gap] = tmp;
			}
		}
	}

}
//void TestOP()
//{
//	
//	int* a2 = (int*)malloc(sizeof(int) * N);
//	int* a3 = (int*)malloc(sizeof(int) * N);
//	int* a4 = (int*)malloc(sizeof(int) * N);
//	int* a5 = (int*)malloc(sizeof(int) * N);
//	int* a6 = (int*)malloc(sizeof(int) * N);
//	
//		a2[i] = a1[i];
//		a3[i] = a1[i];
//		a4[i] = a1[i];
//		a5[i] = a1[i];
//		a6[i] = a1[i];
//	}
//}
#include <stdlib.h>
#include <time.h>
void InsertTest()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
	}
	int begin1 = clock();
	Insert(a1, N);
	int end1 = clock();
	printf("InsertSort:%d\n", end1 - begin1);
	free(a1);
}
void ShellTest()
{
	srand(time(0));
	const int N = 100000;
	int* a2 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a2[i] = rand();
	}
	int begin1 = clock();
	Shellsort(a2, N);
	int end1 = clock();
	printf("Shellsort:%d\n", end1 - begin1);
	free(a2);
}
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//左边做key右边先走，右边做key左边先走
//void Quick(int *a,int begin,int end)//快排思想就是选取一个基准值key，将小于key的甩到左边去，将大于key的甩到右边去。然后用递归二叉树思想再递归key的左边key的右边
//{
//	
//	int left = begin;
//	int right =end;
//	int key = a[begin];
//	while (left < right)
//	{
//		//右边找小
//		while (a[right] > key)
//			right--;
//		//左边找大
//		while (a[left] < key)
//			left++;
//		//当走到这里表示，右边找个一个比key小的，左边找到一个比key大的，两个交换
//		Swap(&a[left], &a[right]);
//	}
//	//当走到这里表示left和right相遇--相遇后就将key值与相遇值交换
//	Swap(&key, &a[left]);
//	int keyi = left;
//	//以上算是一趟排序，将key排序好，接下来就像二叉树递归一样，分为左子树右子树的这里是先排序好key，再排序key左边，再排序key右边
//	//begin   key   end
//	Quicksort(a, begin, keyi - 1);//key左部分
//	Quicksort(a, keyi + 1, end);//key右部分
//
//}

//快排的缺点：当有序和逆序时，效率特别慢，甚至会栈溢出。
void Quicksort(int *a,int left,int right)//需要区间，所以需要知道left和right
{
	if (left >= right)//因为每次都在缩小区间所以一定会有不存在的区间的
		return;
	//因为递归子区间还需要分割区间范围，这里不好修改left和right，所以我们保存它们的值
	int begin = left;
	int end = right;
	//定义一个基准值key--用下标定义，最左边
	int keyi = left;
	while (left<right)
	{
		//右边找小
		while (left<right&&a[right] >= a[keyi])//还有当右边的值等于key时无所谓左右
			--right;//要注意right的范围，当右边的值都比key大时，right就超出范围了，比left还大了，所以还需要判断一下
            		
		//左边找大
		while (left < right && a[left] <= a[keyi])
			++left;
		//两边找到了交换
		Swap(&a[left], &a[right]);
	}
	//最后left和right相遇  相遇点与key交换
	Swap(&a[keyi], &a[left]);
	keyi = left;
	//最后区间就变成  begin   [keyi-1]  key [keyi+1]    end
	Quicksort(a, begin, keyi - 1);//左区间
	Quicksort(a, keyi + 1, end);//右区间
	//当递归到不存在的区间时结束递归，什么情况会出现不存在的区间？
	//当只有两个区间时，并且有序后，该递归就结束
	// 0 -beagin  1 -keyi
	//没有左区间，并且left大于right了
}
//随机选K  三数取中--取的是下标--三个数中既不是最大的哪个也不是最小的哪个
void QuickTest()
{
	srand(time(0));
	const int N = 100000;
	int* a2 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a2[i] = rand();
	}
	int begin1 = clock();
	Quicksort(a2, 0, N - 1);
	int end1 = clock();
	printf("Quicksort:%d\n", end1 - begin1);
	free(a2);
}
int main()
{
	/*QuickTest();*/
	/*int a[] = { 9,8,7,6,5,4,3,2,1,0 };
	Quicksort(a,0,9);*/
	InsertTest();
	ShellTest();
	
	//Insert(a, 10);
	///*Shellsort(a,10);*/
	/*for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}*/
	return 0;
}