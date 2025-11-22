#ifndef FLAPPYBIRD_GLOBAL_H
#define FLAPPYBIRD_GLOBAL_H

namespace fb {
    struct player_t {
        int x;
        int y;
    };

    struct game_state_t {
        int window_width;
        int window_height;
        int target_fps;

        player_t player;
    };
}

#endif //FLAPPYBIRD_GLOBAL_H
