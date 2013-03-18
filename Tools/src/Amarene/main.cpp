#include "main.h"
#include "ProfileView.h"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc >= 2)
    {
        String arg1 = String(argv[1]);
        ProfileView a(arg1);
        int y = a.init();
        if(y != -1)
        {
            std::cout << "Name: " + a.getName() << std::endl;
            std::cout << "Age: " + a.getAge() << std::endl;
            std::cout << "Test: " + a.getLastTest() << std::endl;
            std::cout << "Save File: " + a.getSaveFileName() + ".xrsbxl2x" << std::endl;
        }
    }
    else
    {
        std::cout << "Needs <infile>" << std::endl;
    }
}
