#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <string>
#include <map>
#include "doctest.h"
#include "table.hpp"

ctcpp::Table *table;

std::vector<std::string> output;
TEST_CASE("table test") {
    SUBCASE("preparation") {
        table = new ctcpp::Table();
    };
    SUBCASE("generation") {
        output = table->render(
          {
            {"testcolumA", "testcolumB", "testcolumC"},
            {"A0", "B0", "C0"},
            {"A1", "B1", "C1"},
            {"A2", "B2", "C2"}
          }
        );
    };
    SUBCASE("line 0") {
        CHECK(output[0] == "┌──────────┬──────────┬──────────┐");
    };
    SUBCASE("line 1") {
        CHECK(output[1] == "│testcolumA│testcolumB│testcolumC│");
    };
    SUBCASE("line 2") {
        CHECK(output[2] == "├──────────┼──────────┼──────────┤");
    };
    SUBCASE("line 3") {
        CHECK(output[3] == "│A0        │B0        │C0        │");
    };
    SUBCASE("line 4") {
        CHECK(output[4] == "├──────────┼──────────┼──────────┤");
    };
    SUBCASE("line 5") {
        CHECK(output[5] == "│A1        │B1        │C1        │");
    };
    SUBCASE("line 6") {
        CHECK(output[6] == "├──────────┼──────────┼──────────┤");
    };
    SUBCASE("line 7") {
        CHECK(output[7] == "│A2        │B2        │C2        │");
    };
    SUBCASE("line 8") {
        CHECK(output[8] == "└──────────┴──────────┴──────────┘");
    };
};
