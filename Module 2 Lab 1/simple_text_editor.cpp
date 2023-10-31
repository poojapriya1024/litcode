#include<bits/stdc++.h>
using namespace std;

stack<char> org;
stack<char> cache;
string s = "";
//stores the length of the new word after each operation
vector<int> stringSize; 

void addWord(string word)
{
    for(auto &ch: word)
        org.push(ch);
}

void deleteChars(int num)
{
    //move num characters from org stack to cache
    int i = 1;
    while(i <= num)
    {
        cache.push(org.top());
        org.pop();
        i++;
    }
}

void printIndex(stack<char> temp, int index)
{
    int currSize = temp.size();
    int noOfCharsToBePopped = currSize - index;
    int i = 1;

    while(i <= noOfCharsToBePopped)
    {    
        temp.pop();
        i++;
    }
    
    cout<<temp.top()<<endl;
    return;
}

void printArray(vector<string> arr) 
{
    if(arr.empty())
    {
        cout<<"Empty Array"<<endl;
        return;
    }

    for(auto &el: arr)
        cout<<el<<endl;
    
}

void printStack(stack<char> stck)
{
    if(stck.empty())
    {
        cout<<"Empty Stack"<<endl;
        return;
    }

    while(!stck.empty())
    {
        cout<<stck.top()<<endl;
        stck.pop();
    }
}

int main() 
{
    int size;
    cout<<"Enter the size: ";
    cin>>size;
    cin.ignore();

    vector<string> operations(size);

    for(int i=0;i<size;i++)
        getline(cin, operations[i]);

    stringSize.push_back(s.size());
    //perform the operations

    for(int i=0;i<size;i++) 
    {   
        string temp = operations[i];
        //get the type of operation
        if(temp[0] == '1') 
        {
            //add characters to our current stack
            // temp.size() - 2 -> extract all characters except the first two characters
            string wordToBeAdded = temp.substr(2, temp.size() - 2); 
            addWord(wordToBeAdded);
            stringSize.push_back(org.size());
            continue;
        }

        if(temp[0] == '2') //delete a particular set of characters
        {
            int noOfCharsToBeDeleted = temp[2] - '0';
            deleteChars(noOfCharsToBeDeleted);
            stringSize.push_back(org.size());
            continue;
        }

        if(temp[0] == '3')
        {
            int index = temp[2] - '0';
            printIndex(org, index);
            continue;
        }

        if(temp[0] == '4') //undo operation
        {   
            //undo only if the prev operation was 1 or 2
            // if(operations[i-1][0] == '3' || operations[i-1][0] == '4')
            //     continue;
            
            int n = stringSize.size();

            if(n == 1)
                continue;
            
            int val = stringSize[n - 1] - stringSize[n - 2];
            if(val > 0) //addition has taken place => increase in size
            {
                //undo addition of val chars => delete val chars
                while(val > 0)
                {
                    org.pop();
                    val--;
                }
            }
            else if (val < 0) {
                //undo deletion of abs(val) chars => add abs(val) chars from cache to org
                val = abs(val);

                while(val > 0)
                {
                    org.push(cache.top());
                    cache.pop();
                    val--;
                }
            }
            
            //pop the last added element
            stringSize.pop_back();

        }


    }

    return 0;
}