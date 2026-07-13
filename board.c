/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 21:52:16 by hamezoua          #+#    #+#             */
/*   Updated: 2026/07/13 21:27:50 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "square.h"
#include "board.h"

void    print_board(t_board *board)
{
    int     row;
    int     col;
    while(1)
    {
        row = 0;
        while(row < 8)
        {
            col = 0;
            printf("______________________________________________________________________________________\n");
            while(col < 8)
            {
                if (board->board[row][col].Type == Pawn && board->board[row][col].p_color == Black)
                    printf("|  P-B  |  ");
                else if (board->board[row][col].Type == Pawn && board->board[row][col].p_color == White)
                    printf("|  P-W  |  ");
                else if (board->board[row][col].Type == Rook && board->board[row][col].p_color == White)
                    printf("|  R-W  |  ");
                else if (board->board[row][col].Type == Rook && board->board[row][col].p_color == Black)
                    printf("|  R-B  |  ");
                else if (board->board[row][col].Type == Knight && board->board[row][col].p_color == Black)
                    printf("|  KN-B |  ");
                else if (board->board[row][col].Type == Knight && board->board[row][col].p_color == White)
                    printf("|  KN-W |   ");
                else if (board->board[row][col].Type == Bishop && board->board[row][col].p_color == Black)
                    printf("|  B-B  |  ");
                else if (board->board[row][col].Type == Bishop && board->board[row][col].p_color == White)
                    printf("|  B-W |  ");
                else if (board->board[row][col].Type == King && board->board[row][col].p_color == Black)
                    printf("|  K-B  |  ");
                else if (board->board[row][col].Type == King && board->board[row][col].p_color == White)
                    printf("|  K-W |   ");
                else if (board->board[row][col].Type == Queen && board->board[row][col].p_color == Black)
                    printf("|  Q-B  |  ");
                else if (board->board[row][col].Type == Queen && board->board[row][col].p_color == White)
                    printf("|  Q-W |   ");
                else
                    printf("|  0-0 |   ");
                col++;
            }
            printf("\n____________________________________________________________________________________\n");
            row++;
        }
        break;
    }
}
SquareInfo **board_create(SquareInfo **board)
{
    int     i;
    
    i = 0;
    board = malloc(sizeof(SquareInfo *) * 8);
    if(!board)
        return NULL;
    while(i < 8)
    {
        board[i] = malloc(sizeof(SquareInfo) * 8);
        i++;
    }
    return board;
}

void free_board(t_board *board)
{
    int     i;

    i = 0;
    while(i < 8)
    {
        free(board->board[i]);
        i++;
    }
    free(board->board);
    free(board);
}

int     main(void)
{
    t_board *board;
    int     row;
    int     col;
    board = malloc(sizeof(t_board));
    board->board = board_create(board->board);
    init_board(board);
     print_board(board);
    free_board(board);
    
    
    return (0);
}