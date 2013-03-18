#ifndef PROFILEVIEW_H_INCLUDED
#define PROFILEVIEW_H_INCLUDED

#include "main.h"

class ProfileView
{
    public:
    ProfileView(String file);
    int init();
    String getName();
    String getAge();
    String getLastTest();
    String getSaveFileName();

    private:
    String nameOfFile;
    String data[4];
};

#endif // PROFILEVIEW_H_INCLUDED
