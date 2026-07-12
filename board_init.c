/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 15:29:47 by hamezoua          #+#    #+#             */
/*   Updated: 2026/07/12 15:54:14 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"
#include "board.h"

// static int init_white(t_board *board)
// {
    
// }

void    init_board(t_board *board)
{
    int     row;
    int     col;
    
    row = 0;
    while(row < 8)
    {
        col = 0;
        while(col < 8)
        {
            board->board[row][col].p_color = None;
            board->board[row][col].Type = Empty;
            col++;
        }
        row++;
    }
}