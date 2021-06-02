#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <map>
#include "bloom_filter.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    //string path1 = "test1.txt";
    string path1 = argv[1];
                            
    //string path2 = "answer1.txt";
    string path2 = argv[2];
                            
    // Задаю параметры.
    bloom_parameters parameters;
    parameters.false_positive_probability = 0.0001; // 1 in 10000
    parameters.random_seed = 0xA5A5A5A5;
    parameters.compute_optimal_parameters();

    // Использую регулярные выражения для распознования команды id видео и пользователя.
    smatch m;
    string input = "";
    
    int checker = 0;
    map<string, bloom_filter> mp;

    // Открываю поток на запись и чтение.
    ifstream in;
    ofstream out;
    in.open(path1);
    out.open(path2);
    if (in.is_open() && out.is_open())
    {
        // Первая строка с количеством видео.
        getline(in, input);
        out << "Ok" << endl;
        regex_search(input, m, regex("\\d+"));
        checker = stoi(m[0]);
        parameters.projected_element_count = checker;
        string command;
        while (!in.eof())
        {
            getline(in, command);

            regex_search(command, m, regex("\\d+"));
            string user = m[0];

            regex_search(command, m, regex("o\\d+"));
            string videos = m[0];
            videos = videos.erase(0, 1);
            string video = videos;

            if (command[0] == 'w')
            {
                const auto found = mp.find(user);
                if (found == mp.cend())
                {
                    bloom_filter filter(parameters);
                    mp[user] = filter;
                }
                out << "Ok" << endl;
                mp[user].insert(video);
            }
            if (command[0] == 'c')
            {
                const auto found = mp.find(user);
                if (found == mp.cend())
                {
                    out << "No" << endl;
                }
                else
                    if (mp[user].contains(video))
                    {
                        out << "Probably" << endl;
                    }
                    else
                    {
                        out << "No" << endl;
                    }
            }
        }
    }
    in.close();
    out.close();
    
    return 0;
}