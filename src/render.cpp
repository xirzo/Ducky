#include "render.h"

#include "raylib.h"

namespace fb {
    void draw_player(const game_state_t &state) {
        DrawRectangle(state.player.x, state.player.y, state.player.width, state.player.height, WHITE);
#ifdef DEBUG_MODE
        DrawSphere({state.player.x, state.player.y, 8}, 10, GREEN);
#endif
    }

    void draw_walls(const game_state_t &state) {
        for (const wall_t &wall: state.walls_pool) {
#ifdef DEBUG_MODE
            DrawSphere({wall.x, wall.y, 8}, 10, GREEN);
#endif

            if (wall.is_hidden) {
                continue;
            }

            Vector2 top_part_position = {
                wall.x, 0,
            };
            Vector2 top_part_size = {
                state.world.wall_width, wall.y - state.world.wall_gap / 2
            };

            Vector2 bottom_part_position = {
                wall.x, wall.y + state.world.wall_gap / 2
            };
            Vector2 bottom_part_size = {
                state.world.wall_width, static_cast<float>(state.window_height),
            };

            DrawRectangleV(top_part_position, top_part_size, RED);
            DrawRectangleV(bottom_part_position, bottom_part_size, BLUE);
        }
    }
}
