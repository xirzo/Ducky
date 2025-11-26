#ifndef FLAPPYBIRD_RENDER_H
#define FLAPPYBIRD_RENDER_H

#include <expected>

#include "global.h"

namespace fb {
    std::expected<void, std::string> init_renderer();

    void deinit_renderer();

    void draw_background(const game_state_t &state);

    void draw_player(const game_state_t &state);

    void draw_walls(const game_state_t &state);

    void draw_score(const game_state_t &state);
}

#endif //FLAPPYBIRD_RENDER_H
