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
    ) {
        if (x_1_min <= x_2_max && x_1_max >= x_2_min && y_1_min <= y_2_max
            && y_1_max >= y_2_min) {
            return true;
        }
        return false;
    }

    bool are_player_wall_colliding(const player_t &player, const wall_t &wall, const game_state_t &state) {
        if (wall.is_hidden) {
            return false;
        }

        float player_x_min = player.x;
        float player_x_max = player.x + player.width;
        float player_y_min = player.y;
        float player_y_max = player.y + player.height;

        float top_x_min = wall.x;
        float top_x_max = wall.x + state.world.wall_width;
        float top_y_min = 0.0f;
        float top_y_max = wall.y - state.world.wall_gap / 2.0f;

        if (are_intersected(player_x_min, player_x_max, player_y_min, player_y_max,
                            top_x_min, top_x_max, top_y_min, top_y_max)) {
            return true;
        }

        float bottom_x_min = wall.x;
        float bottom_x_max = wall.x + state.world.wall_width;
        float bottom_y_min = wall.y + state.world.wall_gap / 2.0f;
        float bottom_y_max = static_cast<float>(state.window_height);

        if (are_intersected(player_x_min, player_x_max, player_y_min, player_y_max,
                            bottom_x_min, bottom_x_max, bottom_y_min, bottom_y_max)) {
            return true;
        }

        return false;
    }

    bool are_player_wall_gap_colliding(const player_t &player, const wall_t &wall, const game_state_t &state) {
    }
}
