/** @type {HTMLDivElement} */
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
