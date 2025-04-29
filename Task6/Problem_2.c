#include <stdio.h>

struct Player {
    char *name;
    short age;
    short number;
    char *position;
    char *team;
    char *country;
};

void init_player(struct Player *player) {
    player->name = "Mohamed";
    player->age = 25;
    player->number = 12345;
    player->position = "Striker";
    player->team = "Manchester United";
    player->country = "England";
}

void print_player_info(struct Player player) {
    printf("Name: %s\n", player.name);
    printf("Age: %d\n", player.age);
    printf("Number: %d\n", player.number);
    printf("Position: %s\n", player.position);
    printf("Team: %s\n", player.team);
    printf("Country: %s\n", player.country);
}

int main() {
    struct Player player1;
    init_player(&player1);
    print_player_info(player1);
    return 0;
}