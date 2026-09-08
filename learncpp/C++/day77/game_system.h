#pragma once

namespace Gamestate{
    enum Gamestate{
        fail=0,
        one,
        two,
        three,
    };
}

Gamestate::Gamestate convert_choice(int choice);

void game();