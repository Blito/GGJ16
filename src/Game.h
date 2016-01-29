#ifndef GAME_H
#define GAME_H

#include "Client.h"

#include <chrono>

namespace BlitServer
{

class Game
{
public:
    Game();

    void init();

    void newInput(const Message & message);

    Message update(const std::chrono::milliseconds & ellapsed);
};

} // end BlitServer

#endif // GAME_H
