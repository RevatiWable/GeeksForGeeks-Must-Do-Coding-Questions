Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.
Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. Each test case consists of two lines.
First line of each test case contains an Integer N denoting size of array and the second line contains N space separated elements.
Output:
For each test case, print the count of all triplets, in new line. If no such triplets can form, print "-1".
Constraints:
1 <= T <= 100
3 <= N <= 105
1 <= A[i] <= 106
Example:
Input-
2
4
1 5 3 2
3
3 2 7
Output-
2
-1

Explanation:
Testcase 1: There are 2 triplets: 1 + 2 = 3 and 3 +2 = 5

//------------------------------TIME 0.05 sec-----------------------------------------------
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int countTrip(int a[],int N)
{
    int i,j,k,c=0;
    sort(a,a+N);// sort fuction used most commonly in Vector
    for(i=0;i<N;i++)
    {
        j=i+1;
        k=j+1;
        while(k<N)
        {
            if(a[i]+a[j]==a[k])
                {c++;j++;}
            else if(a[i]+a[j]<a[k])
                {j++;k--;}
            k++;
        }
    }
    if(c==0)    return -1;
    else    return c;
}
int main() {
	int i,j,T,N,count=0;
	cin>>T;
	while(T--)
	{
	    cin>>N;
	    int a[N];
	    for(i=0;i<N;i++)
	        cin>>a[i];
	    cout<<countTrip(a,N);
	    cout<<endl;
	}
	return 0;
}
