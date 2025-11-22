#include "game.h"

int main() {
    fb::game_state_t state = {0};
    state.window_width = 1280;
    state.window_height = 720;
    state.target_fps = 60;

    fb::init(state);

    while (fb::should_close() == false) {
        fb::process_input();
        fb::draw();
    }

    fb::deinit();
    return 0;
}
