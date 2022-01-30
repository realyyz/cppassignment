#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
const int number_of_csv_properties = 8;
class person
{
private:
    string properties[number_of_csv_properties];

public:
    input(string property = "", int order_property = 0);
    int survived();
    int pclass();
    int sex();
    int age();
    double faire();
};
person::input(string property, int order_property)
{
    properties[order_property] = property;
}
int person::survived()
{
    return stoi(properties[0]);
}
int person::pclass()
{
    return stoi(properties[1]);
}
int person::sex()
{
    if (properties[3] == "male")
        return 1;
    else
        return 0;
}
int person::age()
{
    return stoi(properties[4]);
}
double person::faire()
{
    return stod(properties[7]);
}
person string_process(string s) // convert a string into a person class.
{
    string delimiter = ",";
    int begin_of_substr = 0, end_of_substr, i = 0;
    person person111;
    for (i = 0; i < number_of_csv_properties - 1; i++)
    {
        end_of_substr = s.find(delimiter, begin_of_substr);
        person111.input(s.substr(begin_of_substr, end_of_substr - begin_of_substr), i);
        begin_of_substr = s.find(delimiter, begin_of_substr) + 1;
    }
    person111.input(s.substr(begin_of_substr, s.length()), i);
    return person111;
}
double survived_by_gender_class(vector<person> persons, int gender, int pclass)
{
    double survived = 0, dead = 0;
    for (long long unsigned int i = 0; i < persons.size(); i++)
    {
        if (persons[i].sex() == gender && persons[i].pclass() == pclass)
        {
            if (persons[i].survived() == 1)
            {
                survived = survived + 1;
            }
            else
                dead = dead + 1;
        }
    }

    return survived / (survived + dead);
}
double survived_child(vector<person> persons, int age, int pclass)
{
    double survived = 0, dead = 0;
    for (long long unsigned int i = 0; i < persons.size(); i++)
    {
        if (persons[i].age() <= age && persons[i].pclass() == pclass)
        {
            if (persons[i].survived() == 1)
            {
                survived = survived + 1;
            }
            else
                dead = dead + 1;
        }
    }

    return survived / (survived + dead);
}
double survived_faire(vector<person> persons, int pclass)
{
    double faire = 0, total_number = 0;
    for (long long unsigned int i = 0; i < persons.size(); i++)
    {
        if (persons[i].pclass() == pclass)
        {
            if (persons[i].survived() == 1)
            {
                faire = persons[i].faire() + faire;
            }
            total_number = total_number + 1;
        }
    }

    return faire / total_number;
}
int main()
{
    vector<person> persons;
    string line;
    ifstream myfile("titanic.csv"); // skip the first line of the csv files since it is the head of the csv files
    if (myfile.is_open())
    {
        getline(myfile, line);
        while (getline(myfile, line))
        {
            persons.push_back(string_process(line));
        }
        myfile.close();
    }
    cout << "P(S= true | G=female,C=1) \t"
         << "=\t" << survived_by_gender_class(persons, 0, 1) << endl;
    cout << "P(S= true | G=female,C=2) \t"
         << "=\t" << survived_by_gender_class(persons, 0, 2) << endl;
    cout << "P(S= true | G=female,C=3) \t"
         << "=\t" << survived_by_gender_class(persons, 0, 3) << endl;
    cout << "P(S= true | G=male,C=1) \t"
         << "=\t" << survived_by_gender_class(persons, 1, 1) << endl;
    cout << "P(S= true | G=male,C=2) \t"
         << "=\t" << survived_by_gender_class(persons, 1, 2) << endl;
    cout << "P(S= true | G=male,C=3) \t"
         << "=\t" << survived_by_gender_class(persons, 1, 3) << endl;
    cout << endl;
    cout << endl;
    cout << "P(S= true | A<=10,C=3) \t\t"
         << "=\t" << survived_child(persons, 10, 3) << endl;
    cout << endl;
    cout << endl;
    cout << "E[X | C=1] \t\t\t"
         << "=\t" << survived_faire(persons, 1) << endl;
    cout << "E[X | C=2] \t\t\t"
         << "=\t" << survived_faire(persons, 2) << endl;
    cout << "E[X | C=3] \t\t\t"
         << "=\t" << survived_faire(persons, 3) << endl;
}