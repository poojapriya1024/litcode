/*
    problem title : sum of numbers with units digit k
    ex: sum = 58 and k = 9
    we have to find a solution set of size n such that each integer in this set has a unit digit = k and their total sum = sum
    then,
    (A1+A2+..+AN) = sum
    n * k + 10*(a1+a2+a3+..+an) = sum where ai = Ai / 10
    thus, our goal is to satisfy the above equation
    we can do that by checking if (sum % 10) == (n * k) % 10 => then 10*(a1+a2+a3+..+an) % 10 becomes 0 
*/ 

#include<bits/stdc++.h>
using namespace std;

int minimumNumbers(int sum, int k)
{

    //if the target sum is 0, then solution is an empty set.
    //total elements in an empty set = 0
    if(sum == 0)
        return 0;
    // if k = 0, then there is only one possible solution when sum is a multiple of 10
    //ex: sum = 40, then solution set = {40}
    if(k == 0)
        return (sum % 10 == 0) ? 1:-1;

    //if k is even and sum is odd, solution is not possible as we can never get an odd sum with even integers
    if(sum % 2 != 0 && k % 2 == 0)
        return -1;

    for(int n=1;n*k<=sum;n++)
    {
        if(sum % 10 == (n*k) % 10)
            return n; ///solution set of size = n
    }

    return -1;
}

int main()
{
    int sum, k;
    cin>>sum>>k;

    int solution = minimumNumbers(sum,k);
    cout<<solution<<endl;

    return 0;
}