#include <stdio.h>


//��������
void Insert(int* a,int n)
{
	for (int i = 1; i < n; i++)//����Ӵ�����ڶ���Ԫ�ؿ�ʼ������룬Ĭ�������һ��Ԫ�ؾͲ����ȥ
	{
		//һ������
		int end=i-1;//��ʾ���һ��Ԫ�ص��±�----��һ��Ԫ��λ���±�Ϊ0
		int tmp=a[i];//��ʾҪ���������---�ӵڶ���Ԫ�ؿ�ʼ���룬�ڶ���Ԫ��λ����i
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				//�������a[end]��tmpҪС��,��end+1�ϲ��ǿ�λ
				break;
			}
		}
		//�ߵ����������ֿ��ܣ�һ����a[end]��tmpС��ѭ��ֹͣbreak�������ˣ���һ�־���ѭ��һֱ�ߣ�ֱ������
		//Ҳ����������ÿ��Ԫ�ض���Ҫ�����Ԫ��Ҫ����end���ܵ�-1ȥ��
		//���tmp�ܹ�Ҫȥend+1��λ����ȥ��
		a[end + 1] = tmp;//����һ��
	}
	
}
//ϣ������--Ԥ����--����
void Shellsort(int *a,int n)
{
	int gap = n;
	while (gap)
	{
		gap/=2;
		for (int j = 0; j < gap; j++)
		{
			//ϣ��������ص���Ƿֳ�gap���� ����gapΪ3�Ļ����ͷֳ�3����--�����ƺ�
			for (int i = j; i < n - gap; i += gap)
			{
				//��дһ��--Ҳ���Ǻ�ɫ
				int end = i;
				int tmp = a[i + gap];
				while (end >= 0)
				{
					if (a[end] > tmp)
					{
						//��ǰ�ƶ�gapλ�ã�endÿ���ƶ�gap
						a[end + gap] = a[end];
						end -= gap;
					}
					else
					{
						break;
					}
				}
				//tmp�ܹ�Ҫ���뵽a[end+gap]λ����ȥ��
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
//�����key�ұ����ߣ��ұ���key�������
//void Quick(int *a,int begin,int end)//����˼�����ѡȡһ����׼ֵkey����С��key��˦�����ȥ��������key��˦���ұ�ȥ��Ȼ���õݹ������˼���ٵݹ�key�����key���ұ�
//{
//	
//	int left = begin;
//	int right =end;
//	int key = a[begin];
//	while (left < right)
//	{
//		//�ұ���С
//		while (a[right] > key)
//			right--;
//		//����Ҵ�
//		while (a[left] < key)
//			left++;
//		//���ߵ������ʾ���ұ��Ҹ�һ����keyС�ģ�����ҵ�һ����key��ģ���������
//		Swap(&a[left], &a[right]);
//	}
//	//���ߵ������ʾleft��right����--������ͽ�keyֵ������ֵ����
//	Swap(&key, &a[left]);
//	int keyi = left;
//	//��������һ�����򣬽�key����ã�����������������ݹ�һ������Ϊ���������������������������key��������key��ߣ�������key�ұ�
//	//begin   key   end
//	Quicksort(a, begin, keyi - 1);//key�󲿷�
//	Quicksort(a, keyi + 1, end);//key�Ҳ���
//
//}

//���ŵ�ȱ�㣺�����������ʱ��Ч���ر�����������ջ�����
void Quicksort(int *a,int left,int right)//��Ҫ���䣬������Ҫ֪��left��right
{
	if (left >= right)//��Ϊÿ�ζ�����С��������һ�����в����ڵ������
		return;
	//��Ϊ�ݹ������仹��Ҫ�ָ����䷶Χ�����ﲻ���޸�left��right���������Ǳ������ǵ�ֵ
	int begin = left;
	int end = right;
	//����һ����׼ֵkey--���±궨�壬�����
	int keyi = left;
	while (left<right)
	{
		//�ұ���С
		while (left<right&&a[right] >= a[keyi])//���е��ұߵ�ֵ����keyʱ����ν����
			--right;//Ҫע��right�ķ�Χ�����ұߵ�ֵ����key��ʱ��right�ͳ�����Χ�ˣ���left�����ˣ����Ի���Ҫ�ж�һ��
            		
		//����Ҵ�
		while (left < right && a[left] <= a[keyi])
			++left;
		//�����ҵ��˽���
		Swap(&a[left], &a[right]);
	}
	//���left��right����  ��������key����
	Swap(&a[keyi], &a[left]);
	keyi = left;
	//�������ͱ��  begin   [keyi-1]  key [keyi+1]    end
	Quicksort(a, begin, keyi - 1);//������
	Quicksort(a, keyi + 1, end);//������
	//���ݹ鵽�����ڵ�����ʱ�����ݹ飬ʲô�������ֲ����ڵ����䣿
	//��ֻ����������ʱ����������󣬸õݹ�ͽ���
	// 0 -beagin  1 -keyi
	//û�������䣬����left����right��
}
//���ѡK  ����ȡ��--ȡ�����±�--�������мȲ��������ĸ�Ҳ������С���ĸ�
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