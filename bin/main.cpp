#include "game.h"

int main() {
    fb::game_state_t state = {0};
    state.window_width = 720 / 2;
    state.window_height = 1280 / 2;
    state.target_fps = 60;

    state.player.x = state.window_width / 5;
    state.player.y = state.window_height / 2;

    fb::init(state);

    while (fb::should_close() == false) {
        fb::process_input();
        fb::draw(state);
        fb::update();
    }

    fb::deinit();
    return 0;
}
