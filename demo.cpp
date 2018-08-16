#include <ev++.h>
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;

static void timeout_cb(struct ev_loop*, ev_timer *w, int revents) {
    json j;
    j["name"] = "Kitty";
    j["age"] = 2;
    std::cout << j.dump() << '\n';
}

int main() {
    auto loop = ev_default_loop();

    ev_timer t{};
    ev_timer_init(&t, timeout_cb, 1, 0);
    ev_timer_start(loop, &t);

    ev_run(loop);
}
