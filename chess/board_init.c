/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 15:29:47 by hamezoua          #+#    #+#             */
/*   Updated: 2026/07/13 21:09:23 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"
#include "board.h"

static void init_white(t_board *board)
{
    int     col;
    int     row;
    
    row = 6;
    col = 0;
    while(col < 8)
    {
        board->board[row][col].Type = Pawn;
        col++;
    }
    board->board[7][0].Type = Rook;
    board->board[7][1].Type = Knight;
    board->board[7][2].Type = Bishop;
    board->board[7][3].Type = Queen;
    board->board[7][4].Type = King;
    board->board[7][5].Type = Bishop;
    board->board[7][6].Type = Knight;
    board->board[7][7].Type = Rook;
    row = 7;
    while(row > 5)
    {
        col = 0;
        while(col < 8)
        {
            board->board[row][col].p_color = White;
            col++;
        }
        row--;
    }
}

static void init_black(t_board *board)
{
    int     col;
    int     row;
    
    row = 1;
    col = 0;
    while(col < 8)
    {
        board->board[row][col].Type = Pawn;
        col++;
    }
    board->board[0][0].Type = Rook;
    board->board[0][1].Type = Knight;
    board->board[0][2].Type = Bishop;
    board->board[0][3].Type = Queen;
    board->board[0][4].Type = King;
    board->board[0][5].Type = Bishop;
    board->board[0][6].Type = Knight;
    board->board[0][7].Type = Rook;
    row = 0;
    while(row < 2)
    {
        col = 0;
        while(col < 8)
        {
            board->board[row][col].p_color = Black;
            col++;
        }
        row++;
    }
}

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
    init_white(board);
    init_black(board);
}