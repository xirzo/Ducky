#ifndef FLAPPYBIRD_RENDER_H
#define FLAPPYBIRD_RENDER_H

#include "global.h"

namespace fb {
    constexpr int PLAYER_SIDE_SIZE = 60;

    void draw_player(const game_state_t &state);
}

#endif //FLAPPYBIRD_RENDER_H
