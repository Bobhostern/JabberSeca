#include "ProfileView.h"
#include <fstream>

using namespace std;

ProfileView::ProfileView(String file)
{
    nameOfFile = file + ".rsbxl2";
}

int ProfileView::init()
{
    ifstream file;
    String t;
    file.open(nameOfFile.c_str(), ios::ate);
    if(file.is_open())
    {
        file.seekg(0, ios::beg);
        for(int i = 0; i < 4; i++)
        {
            getline(file, t);
            data[i] = t;
        }
        return 0;
    }
    else
    {
        cout << "Couldn't get file" << endl;
        return -1;
    }
}

String ProfileView::getName()
{
    return data[0];
}

String ProfileView::getAge()
{
    return data[1];
}

String ProfileView::getLastTest()
{
    return data[2];
}

String ProfileView::getSaveFileName()
{
    return data[3];
}
