

import React, { useState } from "react";
import './App.css';

var arr = [];
for (let i = 0; i < 9; i++) {
  arr[i] = [];
  for (let j = 0; j < 9; j++) {
    arr[i][j] = 0; // Initialize empty cells as 0
  }
}

function App() {
  const [sudokuValues, setSudokuValues] = useState(arr);


  function solveSudoku(board, depth = 0) {
    if (depth > 100) {
      return null; // Return null to indicate an unsolvable puzzle
    }
  
    // Check if the puzzle is unsolvable.
    if (!isValidSudoku(board)) {
      return null;
    }
  
    const newBoard = board.map((row) => [...row]);
    const emptyCell = findEmptyCell(newBoard);
  
    if (!emptyCell) {
      return newBoard;
    }
  
    const [row, col] = emptyCell;
  
    for (let num = 1; num <= 9; num++) {
      if (newBoard[row][col] === 0 && isSafe(newBoard, row, col, num)) {
        newBoard[row][col] = num;
  
        const solution = solveSudoku(newBoard, depth + 1);
        if (solution) {
          return solution;
        }
  
        // Reset the cell to 0 or another marker (e.g., -1) to indicate it didn't lead to a solution.
        newBoard[row][col] = 0;
      }
    }
  
    return null;
  }

  
  function isValidSudoku(board) {
    for (let row = 0; row < 9; row++) {
      const rowSet = new Set();
      for (let col = 0; col < 9; col++) {
        if (board[row][col] !== 0 && rowSet.has(board[row][col])) {
          return false;
        }
  
        rowSet.add(board[row][col]);
      }
    }
  
    for (let col = 0; col < 9; col++) {
      const colSet = new Set();
      for (let row = 0; row < 9; row++) {
        if (board[row][col] !== 0 && colSet.has(board[row][col])) {
          return false;
        }
  
        colSet.add(board[row][col]);
      }
    }
  
    for (let row = 0; row < 9; row += 3) {
      for (let col = 0; col < 9; col += 3) {
        const boxSet = new Set();
        for (let i = row; i < row + 3; i++) {
          for (let j = col; j < col + 3; j++) {
            if (board[i][j] !== 0 && boxSet.has(board[i][j])) {
              return false;
            }
  
            boxSet.add(board[i][j]);
          }
        }
      }
    }
  
    return true;
  }
  

  function findEmptyCell(board) {
    for (let row = 0; row < 9; row++) {
      for (let col = 0; col < 9; col++) {
        if (board[row][col] === 0) {
          return [row, col];
        }
      }
    }
    return null;
  }

  function isSafe(board, row, col, num) {
    return (
      isSafeRow(board, row, num) &&
      isSafeCol(board, col, num) &&
      isSafeBox(board, row - (row % 3), col - (col % 3), num)
    );
  }

  function isSafeRow(board, row, num) {
    return !board[row].includes(num);
  }

  function isSafeCol(board, col, num) {
    for (let row = 0; row < 9; row++) {
      if (board[row][col] === num) {
        return false;
      }
    }
    return true;
  }

  function isSafeBox(board, boxStartRow, boxStartCol, num) {
    for (let row = 0; row < 3; row++) {
      for (let col = 0; col < 3; col++) {
        if (board[row + boxStartRow][col + boxStartCol] === num) {
          return false;
        }
      }
    }
    return true;
  }

  function handleUpDownLeftRight(e) {
    let id = e.target.id;
   
    let x = parseInt(id[0]);
    let y = parseInt(id[1]);
    let nowactiveinput=document.getElementById(id);

    if (e.code === "ArrowDown") {
      e.preventDefault();
   

      
    
      if(nowactiveinput.value)document.getElementById(`${parseInt(id.slice(0,1))}${parseInt(id.slice(1))}`).classList.add("highlighter");
        else {
          document.getElementById(`${parseInt(id.slice(0,1))}${parseInt(id.slice(1))}`).classList.remove("highlighter");
          
      
        }
      x++;
      if (x >= 9) x = 0;
    } else if (e.code === "ArrowUp") {
      e.preventDefault();
      x--;
      if(nowactiveinput.value)document.getElementById(`${parseInt(id.slice(0,1))}${parseInt(id.slice(1))}`).classList.add("highlighter");
        else {
          document.getElementById(`${parseInt(id.slice(0,1))}${parseInt(id.slice(1))}`).classList.remove("highlighter");
          
      
        }
      if (x < 0) x = 8;
    } else if (e.code === "ArrowLeft") {
      y--;
      if (y < 0) y = 8;
      if(nowactiveinput.value)document.getElementById(`${parseInt(id.slice(0,1))}${parseInt(id.slice(1))}`).classList.add("highlighter");
        else {
          document.getElementById(`${parseInt(id.slice(0,1))}${parseInt(id.slice(1))}`).classList.remove("highlighter");
          
      
        }
    } else if (e.code === "ArrowRight") {
      y++;
      if (y >= 9) y = 0;
      if(nowactiveinput.value)document.getElementById(`${parseInt(id.slice(0,1))}${parseInt(id.slice(1))}`).classList.add("highlighter");
        else {
          document.getElementById(`${parseInt(id.slice(0,1))}${parseInt(id.slice(1))}`).classList.remove("highlighter");
          
      
        }
    }

    document.getElementById(`${x}${y}`).focus();
  }

  function handlechange(value, id) {
    let updatedArray = [...sudokuValues];
    value = value.replace(/^0+/, '');
    value = parseInt(value) || 0;
    value=value%10;

    updatedArray[parseInt(id[0])][parseInt(id[1])] = value;
    if(value)document.getElementById(`${parseInt(id.slice(0,1))}${parseInt(id.slice(1))}`).classList.add("highlighter");
    else {
      document.getElementById(`${parseInt(id.slice(0,1))}${parseInt(id.slice(1))}`).classList.remove("highlighter");
      
  
    }
    setSudokuValues(updatedArray);
  }
  
  const handleanimatior=()=>{
    let suss3=document.querySelectorAll("button");
    let suss1=document.querySelectorAll("input");
    suss3.forEach((val)=>{val.style.disabled=true})


    suss1.forEach((val)=>{val.style.visibility="hidden"})
    let suss=document.querySelector(".userux");
    suss.style.display="block";
    let x=document.querySelector(".suduko");
    x.classList.add("animationrot");
    const solvedBoard = solveSudoku(sudokuValues);
      
    if(solvedBoard)
    
    setSudokuValues(solvedBoard);
  else
    alert("This Suduko is not valid please Enter valid values..")
  setTimeout(()=>{
    let suss1=document.querySelectorAll("input");
    let x=document.querySelector(".suduko");
    x.classList.remove("animationrot");

    suss1.forEach((val)=>{val.style.visibility="visible"})
    let suss=document.querySelector(".userux");
     suss.style.display="none";
   
    x.classList.add("animationrot");
  

  },300)
  x.classList.remove("animationrot");
   



    //  animation: rotateAnimation 1s linear forwards 2ms; 
  

  }






  return (
    <div className="App">

  
    <div className="puzzle">
      <h1>Sudoku Wizard</h1>
      <div className="userseensont">
    <h2>Ready for the Solution? Click "Solve" for Instant Gratification!</h2>

<h3>🌟 Your Sudoku puzzle journey is about to reach its destination. No more waiting, no more uncertainty. Click "Solve" now, and behold the complete solution in all its glory.</h3>

<h3>Click "Solve" to Reveal the Sudoku Masterpiece!</h3>

<h3>💡 Instantly unlock the puzzle's secrets with a single click. The numbers will align, and the solution will materialize before your eyes.</h3>

<h3>🧩 Enjoy the satisfaction of seeing the puzzle resolved effortlessly. Perfect for those who seek the answer without delay.</h3>
    </div>
      <div className="suduko"  >
      <div className="userux">
        <div className="uxcontent">
          <div className="waveloader">
          <div class="wave"></div>
  <div class="wave"></div>
  <div class="wave"></div>
  <div class="wave"></div>
  <div class="wave"></div>
  <div class="wave"></div>
  <div class="wave"></div>
  <div class="wave"></div>
  <div class="wave"></div>
  <div class="wave"></div>

        </div>
        <div className="detailsux">
          <span className="x1"> Loading...</span>
          <span className="x2">  Sudoku experts at work</span>
    

        </div>

          </div>
      




      </div>
     
         
        <table >
        
          {sudokuValues.map((array, i) => (
            <tr key={`row-${i}`}  >
              {i % 3 === 0 && <td className="horizontal"></td>}
              {array.map((val, j) => (
                (j + 1) % 3 ? (
                  <input
                
                    type="number"
                    id={`${i}${j}`}
                    value={val===0?"":val}
                    onChange={(e) => { handlechange(e.target.value, e.target.id) }}
                    onKeyDown={(e) => { handleUpDownLeftRight(e) }}
                  />
                ) : (
                  <input
                
                    type="number"
                    id={`${i}${j}`}
                    value={val===0?"":val}
                    onChange={(e) => { handlechange(e.target.value, e.target.id) }}
                    onKeyDown={(e) => { handleUpDownLeftRight(e) }}
                    style={{ marginRight: '1.2rem' }}
                  />
                ))
              )}
            </tr>
          ))}
        </table >
      </div>
      <div style={{display:"flex",flexDirection:"row"}}>
      <div className="eleven" >
        <buton type="submit" onClick={handleanimatior}>Go For Solution --></buton>

      </div>
      <div className="eleven">
        <buton type="submit" onClick={()=>{let arj=[];
          for(let i=0;i<9;i++){
         arj[i]=[];
          for(let j=0;j<9;j++){
            arj[i][j]=0;
            
          }


        }
        
     setSudokuValues(arj);   }
        }>Clear X</buton>

      </div>
      </div>
     
    

    

    </div>
    
  
    </div>
  );
}

export default App;
