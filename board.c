/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 21:52:16 by hamezoua          #+#    #+#             */
/*   Updated: 2026/07/13 11:50:57 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "square.h"
#include "board.h"

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
    while(1)
    {
        row = 0;
        while(row < 8)
        {
            col = 0;
            printf("______________________________________________________________________\n");
            while(col < 8)
            {
                printf("|  %d  |  ", board->board[row][col].p_color);
                col++;
            }
            printf("\n______________________________________________________________________\n");
            row++;
        }
        break;
    }
    free_board(board);
    
    
    return (0);
}