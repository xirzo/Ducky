#ifndef FLAPPYBIRD_AABB_H
#define FLAPPYBIRD_AABB_H

#include "global.h"

namespace fb {
    bool are_intersected(
        float x_1_min,
        float x_1_max,
        float y_1_min,
        float y_1_max,
        float x_2_min,
        float x_2_max,
        float y_2_min,
        float y_2_max
    );

    bool are_player_wall_colliding(const player_t &player, const wall_t &wall, const game_state_t &state);
}

#endif //FLAPPYBIRD_AABB_H
