#pragma once

#include <string>
#include <string_view>
#include <optional>
#include <iostream>
#include <limits>

namespace Difficulty{
    enum Difficulty{
        easy,
        medium,
        hard,
    };
}

std::istream & operator>>(std::istream& in, Difficulty::Difficulty& difficulty);

std::ostream& operator<<(std::ostream& out, Difficulty::Difficulty difficulty);

std::string enum_to_string(Difficulty::Difficulty difficulty);

std::optional<Difficulty::Difficulty> string_to_enum(std::string_view difficulty);