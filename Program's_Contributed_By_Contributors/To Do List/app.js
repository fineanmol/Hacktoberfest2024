const todoInput = document.querySelector('.todo-input');     
const todoButton = document.querySelector('.todo-button');     
const todoList = document.querySelector('.todo-list');
const filterOption = document.querySelector('.filter-todo');
const themeBtn = document.getElementById('theme')

todoButton.addEventListener('click', addTo);
todoList.addEventListener('click', deleteCheck);
filterOption.addEventListener('click', filterTodo);

themeBtn.addEventListener('click',()=>{
 
    if (document.documentElement.getAttribute("data-theme")!=="dark") {
      document.documentElement.setAttribute("data-theme", "dark");
    } else {
      document.documentElement.setAttribute("data-theme", "light");
    }
  })

    function addTo(event){

        
        event.preventDefault()                                                                                                          
        //to do div
        const todoDiv =  document.createElement('div');
        todoDiv.classList.add('todo');
        //create list
        const newTodo = document.createElement('li');
        
        newTodo.innerText = todoInput.value;
        newTodo.classList.add('todo-item');
        todoDiv.appendChild(newTodo);
        
        //Complete and delete buttons
        const completeButton = document.createElement('button');
        completeButton.innerHTML = '<i class="fas fa-check"></i>';
        completeButton.classList.add("complete-btn");
        todoDiv.appendChild(completeButton);

        const trashButton = document.createElement('button');
        trashButton.innerHTML = '<i class="fas fa-trash"></i>';
        trashButton.classList.add("trash-btn");
        todoDiv.appendChild(trashButton);

        //Append list
        if(!todoInput.value == ""){
            todoList.appendChild(todoDiv); 
        }
        
        todoInput.value = "";
    }



function deleteCheck(e){
  const item = e.target;

  if(item.classList[0] === 'trash-btn') {
      const todo = item.parentElement; 
      //animation
      todo.classList.add("fall");
      todo.addEventListener('transitionend', function(){
        todo.remove();
    
      });     
      
  }

   if(item.classList[0] === "complete-btn"){
       const todo = item.parentElement;
       todo.classList.toggle('completed');
   }
}

function filterTodo(event)
{
    const todos = todoList.childNodes;
    todos.forEach(function(todo){ 
        switch(event.target.value) {
            case "all":
                todo.style.display = "flex";   
                break;                
            case "completed":
                if(todo.classList.contains('completed')) {
                    todo.style.display = "flex";                    
                }
                else{
                    todo.style.display = "none";
                }
                break;
            case "uncompleted":
                if(!todo.classList.contains('completed')){
                    todo.style.display = "flex";
                }else{
                    todo.style.display = "none";
                }
                break;
        }
    });
}
