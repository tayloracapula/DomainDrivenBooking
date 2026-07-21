#include "modules/staff/domain/StaffId.hpp"
#include "shared/domain/Identity.hpp"
#include <stdexcept>
#include "../../include/doctest.hpp"

TEST_CASE("Identity cannot be empty") {
    CHECK_THROWS_AS(Identity<StaffId>::of(""), std::invalid_argument);
}

TEST_CASE("Identity stores a non empty value") {
    auto id = Identity<StaffId>::of("abc123");
    CHECK(id.value() == "abc123");
}

TEST_CASE("Identity equality works") {
    auto first = Identity<StaffId>::of("person-1");
    auto second = Identity<StaffId>::of("person-1");
    CHECK(first == second);
}
