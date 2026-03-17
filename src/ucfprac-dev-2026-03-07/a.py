
def solve():
    input_data = input()

    player_a, player_b = "A", "B"
    players = {player_a : 0, player_b: 0}
    
    #A1B2A3
    for i in range(len(input_data)):
        if i % 2 == 0:
            player = input_data[i].upper()
            next_num = input_data[i+1]
            players[player] = players.get(player, 0) + int(next_num)

            diff = abs(players[player_a] - players[player_b])
            if players[player] >= 11 and diff >= 2:
                print(player)
                return player

if __name__ == "__main__":
    solve()