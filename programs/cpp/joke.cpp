#include "httplib.h"
#include "json.hpp"
#include <stdio.h>
#include <conio.h>
using json = nlohmann::json;
int main()
{
    httplib::Client cli("official-joke-api.appspot.com");

    if (auto res = cli.Get("/random_joke"); res && res->status == 200) {
        auto j = json::parse(res->body);
        printf("%s\n", j["setup"].get<std::string>().c_str());
        getch();
        printf("%s\n", j["punchline"].get<std::string>().c_str());
        getch();
    }
    else {
        printf("No jokes for today :'(");
    }
}
