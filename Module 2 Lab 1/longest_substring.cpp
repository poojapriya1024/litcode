// programme to find the length of the longest substring with distinct characters
#include<bits/stdc++.h>
using namespace std;

int findLongestSubstring(string word)
{
    int len = word.size();
    if(len == 0 || len == 1)
        return 1;
    
    unordered_set<char> seen;
    int start = 0, end = 0, maxLength = 0;

    for(end = 0; end < len; end++)
    {
        char curr = word[end];
        //check if the current substring has duplicate characters
        //if yes, then find the string which doesn't have any duplicate characters by removing the characters at start
        while(seen.count(curr) > 0)
        {
            //remove the element from the start to find the substring with all distinct characters
            seen.erase(word[start]);
            //move the start pointer ahead
            start++;
        }

        seen.insert(curr);
        //get the length of the current substring and compare with the maxLength found
        maxLength = max(maxLength, end - start + 1);
    }
    
    return maxLength;

}
int main()
{
    string str = "abcabc";
    // cin>>str;
    int maxLength = findLongestSubstring(str);
    cout<<maxLength<<endl;
    return 0;
}