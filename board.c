/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 21:52:16 by hamezoua          #+#    #+#             */
/*   Updated: 2026/07/11 23:15:10 by hamezoua         ###   ########.fr       */
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

int     main(void)
{
    t_board *board;
    board = malloc(sizeof(t_board));
    board->board = board_create(board->board);
    board->board[0][0].p_color = White;
    board->board[0][0].Type = King;
    printf("%d", board->board[0][0].p_color);
    return (0);
}