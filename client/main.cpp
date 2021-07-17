#include "Client.h"

#include <nlohmann/json.hpp>

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

using Json = nlohmann::json;
using namespace std::chrono_literals;

auto fetch_duration(Client& c) -> std::uint32_t
{
    using Clock = std::chrono::high_resolution_clock;

    const auto s = Clock::now();
    c.fetch();

    return ((Clock::now() - s) / 1us);
}

auto get_delay() -> std::chrono::milliseconds
{
    static std::random_device rd;
    static std::mt19937 gen{rd()};
    static std::uniform_int_distribution<> distrib{2, 100};

    return std::chrono::milliseconds{distrib(gen)};
}

template <typename T>
auto avg(const T& t) -> std::int32_t
{
    if (t.empty())
        return 0;

    return std::accumulate(t.begin(), t.end(), 0) / t.size();
}

auto main(int argc, char** argv) -> int
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <client id>" << std::endl;
        return -1;
    }

    std::ofstream file{"./data/avg_" + std::string{argv[1]} + ".txt"};
    if (!file.is_open())
    {
        std::cout << "couldn't open output file" << std::endl;
        return -1;
    }

    std::vector<std::uint32_t> durations;

    Client client{[&](auto&){
        for (auto i = 0; i < 1000; ++i)
        {
            std::this_thread::sleep_for(get_delay());
            durations.push_back(fetch_duration(client));
        }

        file << avg(durations) << std::endl;
    }};

    std::this_thread::sleep_for(10s);

    return 0;
}
