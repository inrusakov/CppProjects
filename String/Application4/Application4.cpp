#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Wagner_Fischer(string& str1, string& str2, int errors)
{
    int len1 = str1.length() + 1;
    int len2 = str2.length() + 1;

    int* last = new int[len2];
    int* current = new int[len2];
    bool checker;
    int result = 0;

    for (int i = 0; i < len2; i++)
    {
        last[i] = i;
        current[i] = len2 - 1;
    }

    for (int i = 1; i < len1; i++) {
        checker = true;
        current[0] = i;

        for (int j = max(1, i - errors); j < min(len2, i + errors + 1); j++)
        {
            if (str1[i - 1] == str2[j - 1])
                current[j] = min(min((last[j] + 1), (current[j - 1] + 1)), (last[j - 1]));
            else
                current[j] = min(min((last[j] + 1), (current[j - 1] + 1)), (last[j - 1] + 1));
            
            if (current[j] <= errors)
                checker = false;
        }

        if (checker)
        {
            result = len1 - 1;
            break;
        }

        for (int j = 0; j < len2; j++)
        {
            swap(current[j], last[j]);
            current[j] = len2 - 1;
        }
    }

    if (result != len1 - 1)
    {
        result = last[len2 - 1];
    }

    delete[] last;
    delete[] current;

    return result;
}

int check(vector<string> commands, int errors, string current, int cmdNum)
{
    int result = 0;
    for (int i = 0; i < cmdNum; i++)
    {
        if (Wagner_Fischer(current, commands[i], errors) <= errors)
            result++;
    }
    return result;
}

int main()
{
    int N, D, K; 
    cin >> N;
    vector <string> commands;
    string temp;

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        commands.push_back(temp);
    }

    cin >> D;
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        cin >> temp;
        cout << check(commands, D, temp, N) << "\n";
    }

    return 0;
}