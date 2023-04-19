#include <iostream>
#include <ctime>
#include <fmt/format.h>
#include <fmt/compile.h>
#include <QString>

int main() {
    struct timespec before{}, after{};

    std::string a{
            R"(To use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers fromTo use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers fromTo use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers fromTo use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers fromTo use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers from)"};
    std::string b{
            R"(To use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers fromTo use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers fromTo use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers fromTo use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers fromTo use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers fromTo use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers fromTo use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers fromTo use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers fromTo use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers fromTo use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers fromTo use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers fromTo use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers fromTo use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers fromTo use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers from)"};
    std::string c{
            R"(To use the {fmt} library, add fmt/core.h, fmt/format.h, fmt/format-inl.h, src/format.cc and optionally other headers from)"};

    unsigned long a1 = 0, a2 = 0, a3 = 0, a4 = 0;
#define LOOP 6
    std::string r1{}, r2{}, r3{}, r4{};

    for (int i = 0; i < LOOP; ++i) {
        clock_gettime(CLOCK_MONOTONIC, &before);
        r1 = QString(R"(%1Long text Long text Long text Long text%2Long text Long text Long text Long text%3)").arg(
                a.c_str(), b.c_str(), c.c_str()).toStdString();
        clock_gettime(CLOCK_MONOTONIC, &after);
        a1 += after.tv_nsec - before.tv_nsec;

        clock_gettime(CLOCK_MONOTONIC, &before);
        r2 = fmt::format("{}Long text Long text Long text Long text{}Long text Long textLong text Long text{}", a, b,
                         c);
        clock_gettime(CLOCK_MONOTONIC, &after);
        a2 += after.tv_nsec - before.tv_nsec;

        clock_gettime(CLOCK_MONOTONIC, &before);
        r3 = fmt::format(
                FMT_COMPILE(R"({}Long text Long text Long text Long text{}Long text Long textLong text Long text{})"),
                a, b, c);
        clock_gettime(CLOCK_MONOTONIC, &after);
        a3 += after.tv_nsec - before.tv_nsec;

        clock_gettime(CLOCK_MONOTONIC, &before);
        r4 = a;
        r4.append("Long text Long text Long text Long text");
        r4.append(b);
        r4.append("Long text Long text Long text Long text");
        r4.append(c);
        clock_gettime(CLOCK_MONOTONIC, &after);
        a4 += after.tv_nsec - before.tv_nsec;


    }

    std::cout << a1 / LOOP << " ns" << std::endl;
    std::cout << a2 / LOOP << " ns" << std::endl;
    std::cout << a3 / LOOP << " ns" << std::endl;
    std::cout << a4 / LOOP << " ns" << std::endl;

    return 0;
}
