#include <SFML/Graphics.hpp>
#include "GameLoop.h"

int main()
{
    //SFML SCREEN COORDINATES////////////////////////\\
    // 0, 0                           screenwidth, 0 \\
    //                                               \\
    //                                               \\
    //                                               \\
    //                                               \\
    //                                               \\
    //                                               \\
    //                                               \\
    //                                               \\
    //                                               \\
    //                                               \\
    //                                               \\
    // 0, screenheight     screenwidth, screenheigth \\
    //\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

    GameLoop::Run();

    return 0;
}