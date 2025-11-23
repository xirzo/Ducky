#include "render.h"

#include "raylib.h"

namespace fb {
    void draw_player(const game_state_t &state) {
        DrawRectangle(state.player.x, state.player.y, state.player.width, state.player.height, WHITE);
    }

    void draw_walls(const game_state_t &state) {
        for (const wall_t &wall: state.walls) {
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
