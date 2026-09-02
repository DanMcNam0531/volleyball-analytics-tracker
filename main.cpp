#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

struct PlayerStats {
    std::string name;
    int serveAttempts{};
    int servesIn{};
    int aces{};
    int receiveAttempts{};
    int receivePoints{};
};

double percentage(int value, int attempts) {
    return attempts == 0 ? 0.0 : (100.0 * value) / attempts;
}

double receiveAverage(const PlayerStats& player) {
    return player.receiveAttempts == 0
        ? 0.0
        : static_cast<double>(player.receivePoints) / player.receiveAttempts;
}

void displayPlayer(const PlayerStats& player) {
    std::cout << std::left << std::setw(18) << player.name
              << std::right << std::setw(10) << std::fixed << std::setprecision(1)
              << percentage(player.servesIn, player.serveAttempts) << "%"
              << std::setw(8) << player.aces
              << std::setw(12) << std::setprecision(2) << receiveAverage(player)
              << '\n';
}

int main() {
    const std::vector<PlayerStats> players{
        {"Player One", 20, 18, 3, 15, 34},
        {"Player Two", 16, 15, 2, 18, 42},
        {"Player Three", 12, 10, 1, 10, 21},
    };

    std::cout << std::left << std::setw(18) << "Player"
              << std::right << std::setw(11) << "Serve %"
              << std::setw(8) << "Aces"
              << std::setw(12) << "Receive Avg" << '\n';

    for (const PlayerStats& player : players) {
        displayPlayer(player);
    }

    return 0;
}
