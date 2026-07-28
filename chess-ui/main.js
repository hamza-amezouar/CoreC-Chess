/** @type {HTMLDivElement} */
const game = document.querySelector(".game");
const board = document.querySelector(".game .board");
const piecesLayer = document.querySelector(".game .piecesLayer");
const square_array = [];
let dragging = false;
let selectedImage = null;
let selectedPiece = null;
let originalSquare = null;
let img_top;
let img_left;
function draw_board()
{

    
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
                square.dataset.real_color = "#ebecd0";
            }
            else
            {
                square.style.backgroundColor = "#739552";
                square.dataset.real_color = "#739552";
            }
            
        }
    }
}

function defualt_square(){
    for (square of square_array){
        square.style.backgroundColor = square.dataset.real_color;
    }
}

function events(){

    game.addEventListener("contextmenu", function(event){

        event.preventDefault();


        const elements = document.elementsFromPoint(
            event.clientX,
            event.clientY
        );

        const square = elements.find(el => 
            el.classList.contains("square")
        );


        if (!square) return;



        if (square_array.includes(square)){

            square.style.backgroundColor = square.dataset.real_color;


            const index = square_array.indexOf(square);

            if (index > -1){
                square_array.splice(index, 1);
            }

        }
        else{

            const row = Number(square.dataset.row);
            const col = Number(square.dataset.col);


            if ((row + col) % 2 === 0){
                square.style.backgroundColor = "#eb7e6a";
            }
            else{
                square.style.backgroundColor = "#d36c51";
            }


            square_array.push(square);
        }

    });



    game.addEventListener("click", defualt_square);

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

function piece_move(){
    game.addEventListener('mousedown', function(event){
        
        console.log("mousedown")

        const elements = document.elementsFromPoint(
            event.clientX,
            event.clientY
        );

        const square = elements.find(el => 
            el.classList.contains("square")
        );

        if (!square) return;
        selectedImage = square.querySelector('img')
        if (!selectedImage) return;
        let img_width = selectedImage.width
        let img_height = selectedImage.height
        const img_meta_data = selectedImage.getBoundingClientRect();
        img_top = img_meta_data.top
        img_left = img_meta_data.left
        piecesLayer.appendChild(selectedImage)
        const rect = piecesLayer.getBoundingClientRect();
        selectedImage.style.width = `${img_width}px`
        selectedImage.style.height = `${img_height}px`
        selectedImage.style.top = `${event.clientY - rect.top - (img_height / 2)}px`
        selectedImage.style.left = `${event.clientX - rect.left - (img_width / 2)}px`
        originalSquare = square
        dragging = true

    });
    document.addEventListener("mousemove", function(event){
        console.log("mousemove");
        if (!dragging) return;
        const rect = piecesLayer.getBoundingClientRect();
        const rect_game = game.getBoundingClientRect();
        let img_width = selectedImage.width
        let img_height = selectedImage.height
        selectedImage.style.top = `${event.clientY - rect.top - (img_height / 2)}px`
        selectedImage.style.left = `${event.clientX - rect.left - (img_width / 2)}px`
    });
    document.addEventListener("mouseup", function(){
        console.log("mouseup")
        if(!dragging) return;
        dragging = false
        image = piecesLayer.querySelector("img")
        console.log(image.style.position)
        originalSquare.appendChild(image)
    });
    
}
draw_board();
insert_pieces();
events();
piece_move()