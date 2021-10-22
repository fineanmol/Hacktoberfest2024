// Selectors

const todoInput = document.querySelector('.todo-input');
const todoButton= document.querySelector('.todo-button');
const todoList = document.querySelector('.todo-list');
const filterOption = document.querySelector('.filter-todo');


// Event Listeners
document.addEventListener('DOMContentLoaded',getTodos) // if page is refreshed then call getTodos() function
todoButton.addEventListener('click',addTodo)
todoList.addEventListener('click',deleteCheck)
filterOption.addEventListener('click',filtertodo)


// Functions

function addTodo(event){
    event.preventDefault(); //prevents form from submitting

    //  TODO div
    const todoDiv = document.createElement('div')
    todoDiv.classList.add("todo")

    // create Li
    const newTodo = document.createElement('li');
    newTodo.innerText = todoInput.value;// input from from 
    newTodo.classList.add("todo-item");
    todoDiv.appendChild(newTodo);
    // ADDING TODOS TO LOCAL STORAGE !!!!!!!!!!!!!!!!!!!
    saveLocalTodos(todoInput.value);

    // cHECK MARK/COMPLETE BUTTON
    const completedButton = document.createElement('button')
    completedButton.innerHTML = '<i class = "fas fa-check"></i>'
    completedButton.classList.add("complete-btn")
    todoDiv.appendChild(completedButton)

    // cHECK DELETE BUTTON
        const trashButton = document.createElement('button')
        trashButton.innerHTML = '<i class = "fas fa-trash"></i>'
        trashButton.classList.add("trash-btn")
        todoDiv.appendChild(trashButton)

        /// Append to list
        todoList.appendChild(todoDiv)

        //Clear todo input value
        todoInput.value = "";
}

function deleteCheck(e) {
// console.log(e.target)
   const item = e.target;
   
   //DELETE TODO
   if(item.classList[0] === 'trash-btn')
   {  
       const todo = item.parentElement;
       todo.classList.add('fall')
       removeLocalTodos(todo); // REMOVING Local todos from local storage !!!!---
       // here the function waits till the animation is not completed then function runs and remove the element
       todo.addEventListener('transitionend',function() {
        todo.remove();
       })
       
   }
   if(item.classList[0] === 'complete-btn')
   {  
       const todo = item.parentElement;
       todo.classList.toggle('completed')
    //    todo.remove();
   }

}


function filterTodo(e)
{   console.log('filertodo() function called')
    const todos = todoList.childNodes;
    console.log('type of todos',typeof(todos))

    for(let todo of todos)
    {   
        console.log(e.target.value,todo.style.display)
        if(e.target.value === "all")
        {
            todo.style.display = 'flex';   
        }
        if(e.target.value === "completed")
        {
            if(todo.classList.contains('completed')){
                todo.style.display = 'flex';
              }
              else{
                todo.style.display = 'none';
              }  
        }

        // switch(e.target.value){
        //     case "all" : 
        //       todo.style.display = 'flex';
        //       break ;
        //     case "completed" : 
        //       if(todo.classList.contains('completed')){
        //         todo.style.display = 'flex';
        //       }
        //       else{
        //         todo.style.display = none;
        //       }           
        // }
    }

}
function filtertodo(e) {
    const todos = todoList.childNodes;
    todos.forEach(function(todo) {
      switch (e.target.value) {
        case "all":
          todo.style.display = "flex";
          break;
        case "completed":
          if (todo.classList.contains("completed")) {
            todo.style.display = "flex";
          } else {
            todo.style.display = "none";
          }
          break;
        case "uncompleted":
          if (!todo.classList.contains("completed")) {
            todo.style.display = "flex";
          } else {
            todo.style.display = "none";
          }
          break;
      }
    });
  }

function saveLocalTodos(todo)
{  // first checking if we have something there already or not ?
  let todos;
  if(localStorage.getItem('todos') === null)
  {
    todos = [];
  }
  else
  {
    todos = JSON.parse(localStorage.getItem('todos'))
  }

  todos.push(todo);
  localStorage.setItem('todos',JSON.stringify(todos)) ;
}

// Below we will get list from local storge and add that to our list as we did up !
function getTodos(){
  // first checking if we have something there already or not ?
  let todos;
  if(localStorage.getItem('todos') === null)
  {
    todos = [];
  }
  else
  {
    todos = JSON.parse(localStorage.getItem('todos'))
  }
   todos.forEach(function(todo){
      //  TODO div
    const todoDiv = document.createElement('div')
    todoDiv.classList.add("todo")

    // create Li
    const newTodo = document.createElement('li');
    newTodo.innerText = todo                 // Cwe don't need user input instead we need our todo argument
    newTodo.classList.add("todo-item");
    todoDiv.appendChild(newTodo);

    // No need here to save local storage ----- !!!


    // cHECK MARK/COMPLETE BUTTON
    const completedButton = document.createElement('button')
    completedButton.innerHTML = '<i class = "fas fa-check"></i>'
    completedButton.classList.add("complete-btn")
    todoDiv.appendChild(completedButton)

    // cHECK DELETE BUTTON
        const trashButton = document.createElement('button')
        trashButton.innerHTML = '<i class = "fas fa-trash"></i>'
        trashButton.classList.add("trash-btn")
        todoDiv.appendChild(trashButton)

        /// Append to list
        todoList.appendChild(todoDiv)

   });

}

function removeLocalTodos(todo){
    // first checking if we have something there already or not ?
    let todos;
    if(localStorage.getItem('todos') === null)
    {
      todos = [];
    }
    else
    {
      todos = JSON.parse(localStorage.getItem('todos'))
    }

    // console.log(todo.children[0].innerText);
    const todoIndex = todo.children[0].innerText;
    // console.log(todos.indexOf(todoIndex))
    todos.splice(todos.indexOf(todoIndex),1) ;

    localStorage.setItem('todos',JSON.stringify(todos)) ;
}