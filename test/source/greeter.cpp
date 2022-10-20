#include <doctest/doctest.h>
#include <devquery/devquery.h>
#include <devquery/version.h>

#include <string>

TEST_CASE("Devquery") {
  using namespace devquery;

  Devquery devquery("Tests");

  CHECK(devquery.greet(LanguageCode::EN) == "Hello, Tests!");
  CHECK(devquery.greet(LanguageCode::DE) == "Hallo Tests!");
  CHECK(devquery.greet(LanguageCode::ES) == "¡Hola Tests!");
  CHECK(devquery.greet(LanguageCode::FR) == "Bonjour Tests!");
}

TEST_CASE("Devquery version") {
  static_assert(std::string_view(DEVQUERY_VERSION) == std::string_view("1.0"));
  CHECK(std::string(DEVQUERY_VERSION) == std::string("1.0"));
}
