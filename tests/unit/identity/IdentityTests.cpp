#include <stdexcept>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../include/doctest.hpp"
#include "shared/domain/Identity.hpp"
#include "modules/identity/Person.hpp"


TEST_CASE("Identity cannot be empty") {
    CHECK_THROWS_AS(Identity<PersonId>::of(""), std::invalid_argument);
}

TEST_CASE("Identity stores a non empty value") {
    auto id = Identity<PersonId>::of("abc123");
    CHECK(id.value() == "abc123");
}

TEST_CASE("PersonId identity equality works") {
    auto first = Identity<PersonId>::of("person-1");
    auto second = Identity<PersonId>::of("person-1");
    CHECK(first == second);
}
