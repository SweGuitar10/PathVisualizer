#include <SFML/Graphics.hpp>
#include "testcode/bouncingRect.cpp"
// One liner to comile and exec cuz I'm lazy: mingw32-make.exe; ./main.exe

int main()
{  
    BouncingRect bouncer;
    bouncer.Run();
    return 0;
}

