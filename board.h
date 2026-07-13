/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamezoua <amouzwarh+1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 21:52:51 by hamezoua          #+#    #+#             */
/*   Updated: 2026/07/12 18:32:40 by hamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
#define BOARD_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "square.h"
typedef struct s_board
{
    SquareInfo **board;
}t_board;

void    init_board(t_board *board);
#endif