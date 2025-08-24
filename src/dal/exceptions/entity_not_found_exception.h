//
// Created by Dhanush Nadella on 8/24/25.
//

#ifndef ENTITY_NOT_FOUND_EXCEPTION_H
#define ENTITY_NOT_FOUND_EXCEPTION_H
#include <format>
#include <stdexcept>

namespace dal {

class EntityNotFoundException : public std::runtime_error {
public:
    explicit EntityNotFoundException(const std::string_view entity_type, const std::string& entity_identifier)
        : std::runtime_error(std::format("{} '{}' not found.", entity_type, entity_identifier)) {}
};

}
#endif //ENTITY_NOT_FOUND_EXCEPTION_H
