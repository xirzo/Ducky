#include "game.h"

#include <raylib.h>

namespace fb {
    void init(const game_state_t &state) {
        SetTraceLogLevel(LOG_ERROR);
        InitWindow(state.window_width, state.window_height, "Flappy Bird");
        SetTargetFPS(state.target_fps);
    }

    bool should_close() {
        return WindowShouldClose();
    }

    void process_input() {
    }

    void draw() {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    void update() {

    }

    void deinit() {
        CloseWindow();
    }
}
