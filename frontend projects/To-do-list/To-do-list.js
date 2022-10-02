const newBox=document.querySelector('.task-list');
const btn=document.querySelector('.to-add-button');
const task=document.querySelector('.typed-list');
const allTask=document.querySelector('.tasks');
const allTaskList = document.querySelector('.all-task')
const completed_task = document.querySelector('.completed-task');
const completed_task_heading = document.querySelector('.completed-task-heading')

btn.onclick= function() {
    const typedValue =task.value;
    if(typedValue!==''){

        const newtaskbox=document.createElement('div');
        newtaskbox.classList.add('task-list');

        const newtask=document.createElement('div');
        newtask.classList.add('tasks');

        const newtask_input = document.createElement('input');
        newtask_input.classList.add('typed-text');
        newtask_input.type='text';
        newtask_input.value=typedValue;
        newtask_input.setAttribute('readonly','readonly');
        
        // const Buttons=document.createElement('div');
        // Buttons.classList.add('.list-2');

        const done_btn=document.createElement('button');
        done_btn.classList.add('done');
        done_btn.innerText='Done';

        const del_btn=document.createElement('button');
        del_btn.classList.add('del');
        del_btn.innerText='Delete';

        newtask.appendChild(newtask_input);
        newtask.appendChild(done_btn);
        newtask.appendChild(del_btn);

        newtaskbox.appendChild(newtask);

        allTaskList.appendChild(newtaskbox);

    
        task.value='';
         
        del_btn.onclick = () => {
            allTaskList.removeChild(newtaskbox);
     }
   
        done_btn.onclick = () => {
            allTaskList.removeChild(newtaskbox);
            completed_task_heading.classList.remove('visibility');

            const new_completed_task_box = document.createElement('div');
            new_completed_task_box.classList.add('task-lists');

            const new_completed_task_item = document.createElement('div');
            new_completed_task_item.classList.add('items');

           


            const new_completed_task = document.createElement('input');
            new_completed_task.classList.add('typed-task-after');
            new_completed_task.type = 'text';
            new_completed_task.value = newtask_input.value;
            new_completed_task.setAttribute('readonly','readonly');

             const del_after=document.createElement('button');
            del_after.classList.add('del-after');
            del_after.innerText='Delete';
            

           
          


            new_completed_task_item.appendChild(new_completed_task);
            new_completed_task_item.appendChild(del_after);

            new_completed_task_box.appendChild(new_completed_task_item);
            completed_task.appendChild(new_completed_task_box);

            del_after.onclick = () => {
            completed_task.removeChild(new_completed_task_box);

            
        } 
    }

}

};

