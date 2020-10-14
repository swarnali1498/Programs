#include<bits/stdc++.h>
using namespace std;
void maxLengthSubArray(int arr[], int n, int S)
{
    map<int, int> map;
    map[0] = -1;
    int sum = 0;
    int len = 0;
    int ending_index = -1;
    for (int i = 0; i < n; i++)
	{
		sum += arr[i];
        if (map.find(sum) == map.end())
        {
			map[sum] = i;
		}
		//cout<<map.size()<<endl;
        if (map.find(sum - S) != map.end() && len < i - map[sum - S])
		{
			len = i - map[sum - S];
			ending_index = i;
		}
		cout<<ending_index<<endl;
	}
	cout << "[" << (ending_index - len + 1) << "," << ending_index << "]";
}
int main()
{
	int arr[] = {1,1,2,1,1,2};
	int sum = 8;
	int n = sizeof(arr) / sizeof(arr[0]);
	maxLengthSubArray(arr, n, sum);
	return 0;
}
