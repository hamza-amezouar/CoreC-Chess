/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 20:56:51 by hamezoua          #+#    #+#             */
/*   Updated: 2026/07/11 21:50:11 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_C
#define BOARD_C

// Type of pieces
typedef enum piece_type
{
    Pawn,
    Rook,
    Bishop,
    Knights,
    Queen,
    King,
    Empty
}Piecetype;

// Color of pieces
typedef enum piece_color
{
    White,
    Black,
    None
}Piece_color;


// struct of squere 
typedef struct square_info
{
    Piecetype Type;
    Piece_color p_color;
}SquareInfo;

#endif