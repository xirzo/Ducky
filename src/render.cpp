#include "render.h"

#include "raylib.h"

namespace fb {
    void draw_player(const game_state_t &state) {
        DrawRectangle(state.player.x, state.player.y, PLAYER_SIDE_SIZE, PLAYER_SIDE_SIZE, WHITE);
    }
}
