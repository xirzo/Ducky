#include "render.h"

#include "raylib.h"

namespace fb {
    void draw_player(const game_state_t &state) {
        DrawRectangle(state.player.x, state.player.y, state.player.width, state.player.height, WHITE);
    }

    void draw_walls(const game_state_t &state) {
        for (const wall_t &wall: state.walls) {
            DrawSphere({wall.x, wall.y, 9}, 10, RED);
        }
    }
}
