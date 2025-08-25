//
// Created by Dhanush Nadella on 8/24/25.
//

#ifndef ENTITY_NOT_FOUND_EXCEPTION_H
#define ENTITY_NOT_FOUND_EXCEPTION_H

#include <stdexcept>
#include <string>

namespace dal::exception {

class EntityNotFoundException : public std::runtime_error {
public:
    EntityNotFoundException(std::string_view entity_type, const std::string& entity_identifier);
};

}

#endif //ENTITY_NOT_FOUND_EXCEPTION_H