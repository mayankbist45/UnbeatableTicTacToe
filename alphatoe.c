#include "ttt.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv) {
    char human;

    init_boards();
    init_board(START_BOARD);
    join_graph(START_BOARD);
    compute_score();

    printf("X or O? ");
    fflush(stdin); // clear any extra characters in the input stream
    human = getc(stdin);

    print_node(htable[86]);

    int board = 0;

    while (isalpha(htable[board].turn))    // while no winner
    {
        printf("%d\n", board);
        if (human == htable[board].turn) {
            int next_board;
            do {
//                char movec;
                int movei;
                print_node(htable[board]);
                printf("Your move [0-8]: ");
                fflush(stdin); // clear any extra characters in the input stream
                scanf("%d", &movei);
                next_board = htable[board].move[movei];
                if (next_board == -1) {
                    printf("Illegal move, try again!\n");
                }
            } while (next_board == -1);
            board = next_board;
        } else // computer's turn
        {
            int val = best_move(board);
            board = htable[board].move[best_move(board)];
        } // computer's turn
        char ch = isalpha(htable[board].turn);
    } // while loop

    print_node(htable[board]);
    printf("Game over, Player 1!\n");

    if (htable[board].winner == human)
        printf("You won!\n");
    else if (htable[board].winner == '-')
        printf("The game was a tie!\n");
    else
        printf("You lost!\n");

}
