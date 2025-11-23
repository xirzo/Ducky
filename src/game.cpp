#include "game.h"

#include <raylib.h>
#include <chrono>

#include "render.h"

namespace fb {
    void add_wall(game_state_t &state) {
        float x = static_cast<float>(state.window_width) -
                  static_cast<float>(state.window_width) / 4;
        float y = state.random_range(state.random_generator);
        state.walls.emplace_back(x, y);
    }

    void init(game_state_t &state) {
        SetTraceLogLevel(LOG_ERROR);
        InitWindow(state.window_width, state.window_height, "Flappy Bird");
        SetTargetFPS(state.target_fps);

        state.player.x = state.player.initial_x;
        state.player.y = state.player.initial_y;

        long long seed = std::chrono::system_clock::now()
                .time_since_epoch()
                .count();

        state.random_generator = std::mt19937(seed);

        float top_random_y_position =
                state.world.wall_offset +
                state.world.wall_gap / 2.0f;

        float bottom_random_y_position =
                static_cast<float>(state.window_height) -
                state.world.wall_offset -
                state.world.wall_gap / 2.0f;

        state.random_range = std::uniform_real_distribution(top_random_y_position, bottom_random_y_position);

        add_wall(state);
    }

    void restart(game_state_t &state) {
        state.player.x = state.player.initial_x;
        state.player.y = state.player.initial_y;
        state.player.velocity_y = 0;
    }

    void player_jump(game_state_t &state) {
        state.player.velocity_y = -state.player.jump_force;
    }

    bool should_close() {
        return WindowShouldClose();
    }

    void process_input(game_state_t &state) {
        if (IsKeyPressed(KEY_SPACE)) {
            player_jump(state);
        }
    }

    void draw(const game_state_t &state) {
        BeginDrawing();
        ClearBackground(BLACK);
        draw_player(state);
        draw_walls(state);
        EndDrawing();
    }

    void move_player(game_state_t &state) {
        const float deltaTime = GetFrameTime();
        state.player.velocity_y += state.world.gravity_constant * deltaTime;

        if (state.player.velocity_y > state.player.max_fall_speed) {
            state.player.velocity_y = state.player.max_fall_speed;
        }
        if (state.player.velocity_y < state.player.max_rise_speed) {
            state.player.velocity_y = state.player.max_rise_speed;
        }

        state.player.y += state.player.velocity_y * deltaTime;
    }

    void clamp_player_position(game_state_t &state) {
        if (state.player.y >= static_cast<float>(state.window_height) - state.player.height ||
            state.player.y <= 0) {
            restart(state);
        }
    }

    void update(game_state_t &state) {
        move_player(state);
        clamp_player_position(state);
    }

    void deinit() {
        CloseWindow();
    }
}
