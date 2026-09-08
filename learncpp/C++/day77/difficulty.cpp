#include "difficulty.h"

std::ostream& operator<<(std::ostream& out, Difficulty::Difficulty difficulty){
    out << enum_to_string(difficulty);

    return out;

}

std::istream& operator>>(std::istream& in, Difficulty::Difficulty& difficulty){

    
    std::string string_diff{};
    in >> string_diff;

    std::optional<Difficulty::Difficulty> diff_container{string_to_enum(string_diff)};

    
    if(diff_container)
        difficulty = {*diff_container};
    else
        in.setstate(std::ios_base::failbit);

    return in;
    
    
}

std::string enum_to_string(Difficulty::Difficulty difficulty){
    switch(difficulty){
        case Difficulty::easy: return "Easy";
        case Difficulty::medium: return "Medium";
        case Difficulty::hard: return "Hard";
        default: return "error";
    }
}

std::optional<Difficulty::Difficulty> string_to_enum(std::string_view difficulty){
    if (difficulty == "Easy")
        return Difficulty::easy;
    else if (difficulty=="Medium")
        return Difficulty::medium;
    else if (difficulty=="Hard")
        return Difficulty::hard;
    else
        return std::nullopt;
}
