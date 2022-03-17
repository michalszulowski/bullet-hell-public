#include "sptr.h"
#include "Game.h"

int main(int argc, char **argv) {
    sptr<Game> game = new Game();
    game->start();
    return 0;
};
