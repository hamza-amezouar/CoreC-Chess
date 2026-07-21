/** @type {HTMLDivElement} */
function draw_board()
{

    const board = document.querySelector(".board");
    
    let color = 0;
    let row_number = 8;
    let char = "a";
    for (let row = 0; row < 8;row++)
    {
        for (let col = 0;col < 8;col++)
        {
            const square = document.createElement("div");
            square.classList.add("square");
            square.dataset.row = row;
            square.dataset.col = col;
            if (col == 0)
            {
                const row_n = document.createElement("p");
                row_n.textContent = row_number;
                square.appendChild(row_n);
                row_number--;
                if ((row + col) % 2 == 0)
                {
                    const p = square.querySelector("p");
                    p.style.color = "#739552";
                }
                else
                {
                    const p = square.querySelector("p");
                    p.style.color = "#ebecd0";
                }
            }
            if (row == 7)
            {
                const col_char = document.createElement("h3");
                col_char.textContent = char;
                char = String.fromCharCode(char.charCodeAt(0) + 1);
                square.appendChild(col_char);
                if ((row + col) % 2 == 0)
                {
                    const h3 = square.querySelector("h3");
                    h3.style.color = "#739552";
                }
                else
                {
                    const h3 = square.querySelector("h3");
                    h3.style.color = "#ebecd0";
                }
            }
            board.appendChild(square);
            if ((row + col) % 2 == 0)
            {
                square.style.backgroundColor = "#ebecd0";
            }
            else
            {
                square.style.backgroundColor = "#739552";
            }
            
        }
    }
}

function addPiece(row, col, image) {
    const square = document.querySelector(
        `.square[data-row="${row}"][data-col="${col}"]`
    );

    const piece = document.createElement("img");
    piece.src = `images/pieces/${image}.svg`;

    square.appendChild(piece);
}

function insert_pieces()
{
    addPiece(7, 0, "rock");
    addPiece(7, 1, "knight");
    addPiece(7, 2, "beshop");
    addPiece(7, 3, "queen");
    addPiece(7, 4, "king");
    addPiece(7, 5, "beshop");
    addPiece(7, 6, "knight");
    addPiece(7, 7, "rock");

    for (let col = 0; col < 8;col++)
    {
        addPiece(6, col, "pawn");
    }
    addPiece(0, 0, "brock");
    addPiece(0, 1, "bknight");
    addPiece(0, 2, "bbshop");
    addPiece(0, 3, "bqueen");
    addPiece(0, 4, "bking");
    addPiece(0, 5, "bbshop");
    addPiece(0, 6, "bknight");
    addPiece(0, 7, "brock");
    for (let bcol = 0; bcol < 8;bcol++)
    {
        addPiece(1, bcol, "bpawn");
    }
}
draw_board();
insert_pieces()
