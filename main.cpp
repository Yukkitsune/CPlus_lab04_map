#include <iostream>
#include <string>
#include <vector>
#include <map>
struct Discipline {
    std::string namedis;
    int mark;
};
struct student {
    std::string fio;
    std::vector<Discipline>vecmark;
};

int main()
{
    std::vector<student>vecstud;
    std::map<std::string, int>ms;
    int n;
    std::cout << "Number of students: " << std::endl;
    std::cin >> n;
    vecstud.resize(n);
    for (size_t i = 0; i < n;++i) {
        std::cout << "Student " << i + 1<<":";
        std::cin.ignore();
        std::getline(std::cin,vecstud[i].fio);
        int dis;
        std::cout << "Number of disciplines^ " << std::endl;
        std::cin >> dis;
        vecstud[i].vecmark.resize(dis);
        for (size_t j = 0; j < dis;++j) {
            std::cout << "Discipline " << j + 1 << ":";
            std::cin.ignore();
            std::getline(std::cin, vecstud[i].vecmark[j].namedis);
            std::cout << "Mark: ";
            std::cin.ignore();
            std::getline(std::cin, vecstud[i].vecmark[j].mark);
            if (ms.find(vecstud[i].vecmark[j].namedis) == ms.end()) {
                ms[vecstud[i].vecmark[j].namedis] = vecstud[i].vecmark[j].mark;
            }
            else {
                ms[vecstud[i].vecmark[j].namedis] += vecstud[i].vecmark[j].mark;
            }

        }

    }
    int max = -1;
    std::string best_Dis;
    for (auto it = ms.begin();it != ms.end();++it) {
        if (it->second > max) {
            best_Dis = it->first;
        }
    }
    std::cout << best_Dis << std::endl;
    return 0;

}
