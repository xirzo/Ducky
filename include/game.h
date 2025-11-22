#ifndef FLAPPYBIRD_GAME_H
#define FLAPPYBIRD_GAME_H

namespace fb {
    struct game_state_t {
        int window_width;
        int window_height;
        int target_fps;
    };

    void init(const game_state_t &state);

    bool should_close();

    void process_input();

    void draw();

    void update();

    void deinit();
}

#endif //FLAPPYBIRD_GAME_H