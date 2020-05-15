/*Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.
Input:
The first line of input contains an integer T denoting the number of test cases.
Then T test cases follow. Each test case consists of two lines. 
The first line of each test case is N and S, where N is the size of array and S is the sum. 
The second line of each test case contains N space separated integers denoting the array elements.

Output:
For each testcase, in a new line, print the starting and
ending positions(1 indexing) of first such occuring subarray from the left if sum equals to subarray, else print -1.
Constraints: 1 <= T <= 100      1 <= N <= 107         1 <= Ai <= 1010
Example:
Input:
2
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10
Output:
2 4
1 5

Explanation :
Testcase1: sum of elements from 2nd position to 4th position is 12
Testcase2: sum of elements from 1st position to 5th position is 15
*/
// -------------------------------TIME TAKEN 0.56 sec --------------------------------------
#include <iostream>
using namespace std;
int subarr(int N,int S,int a[])
{
    int i,j,count=1,sum=0;
    for(i=1;i<=N;i++)
	       {   
	           if(a[i]+sum<=S)
	                sum+=a[i];
	           else
	               { 
	                   sum+=a[i];
	                   while(sum>S)
	                       { sum-=a[count];
	                        count++;}    
	               }
	           if(sum==S)
	            {
	                cout<<count<<" "<<i<<endl;
	                return 0;
	            }
	       } 
	       cout<<"-1"<<endl;
	       return 0;
}
int main() 
{
    int T,N,S;
	cin>>T;
	while(T--)
	{
	    cin>>N>>S;
	    int a[N];
	    for(int i=1;i<=N;i++)
	        cin>>a[i];
	    subarr(N,S,a);
	}
	return 0;
}

// -------------------------------TIME TAKEN > 1.76 sec --------------------------------------

#include <iostream>
using namespace std;
int subarr(int N,int S,int a[])
{
    int i,j,count=0;
    for(i=1;i<=N;i++)
	       {   
	           int sum=0;
	           for(j=i;j<=N;j++)
	            {
	                sum=sum+a[j];
	                if(S==sum)
	                    {
	                        count++;
	                        if(count==1)    
	                            cout<<i<<" "<<j<<" \n";
	                    }
	               if(count==1) exit;
	             }
	           if(count==1) exit;  
	        }
	        if(count==0)
	            cout<<"-1\n";
}
int main() 
{
    int T,N,S;
	cin>>T;
	while(T--)
	{
	    cin>>N>>S;
	    int a[N];
	    for(int i=1;i<=N;i++)
	        cin>>a[i];
	    subarr(N,S,a);    
	}
	return 0;
}
