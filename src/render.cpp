#include "render.h"

#include "raylib.h"

namespace fb {
    static Texture2D player_texture;

    constexpr char PLAYER_IMAGE_PATH[] = "assets/duck.png";

    std::expected<void, std::string> init_renderer() {
        if (FileExists(PLAYER_IMAGE_PATH) == false) {
            return std::unexpected("Player image is not found");
        }

        Image player_image = LoadImage(PLAYER_IMAGE_PATH);
        player_texture = LoadTextureFromImage(player_image);
        UnloadImage(player_image);
        SetTextureFilter(player_texture, TEXTURE_FILTER_POINT);
        return {};
    }

    void deinit_renderer() {
        UnloadTexture(player_texture);
    }

    void draw_player(const game_state_t &state) {
        float scale_x = state.player.width / static_cast<float>(player_texture.width);
        float scale_y = state.player.height / static_cast<float>(player_texture.height);
        float scale = (scale_x < scale_y) ? scale_x : scale_y;

        DrawTextureEx(player_texture, {state.player.x, state.player.y}, 0.0f, scale, WHITE);
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
