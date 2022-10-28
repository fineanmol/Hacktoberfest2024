window.addEventListener('load', () => {
    const form = document.querySelector("#new-task-form");
    const input = document.querySelector("#new-task-input");
    const list_el = document.querySelector("#tasks");


    form.addEventListener('submit', (e) => {
        e.preventDefault();

        const task = input.value;

        if (task === "") {
            alert("Enter task");
            return;
        }

        let  task_el = document.createElement('div');
        task_el.classList.add('task');

        let  task_content_el = document.createElement('div');
        task_content_el.classList.add('content');

        task_el.appendChild(task_content_el);

        let task_input_el = document.createElement('input');
        task_input_el.classList.add('text');
        task_input_el.type = 'text';
        task_input_el.value = task;
        task_input_el.setAttribute('readonly','readonly');

        task_content_el.appendChild(task_input_el);

        let action_el = document.createElement('div');
        action_el.classList.add('actions');

        let task_edit_el = document.createElement('button');
        task_edit_el.classList.add('edit');
        task_edit_el.innerText = 'Edit';
        
        let task_delete_el = document.createElement('button');
        task_delete_el.classList.add('delete');
        task_delete_el.innerText = 'Delete';

        action_el.appendChild(task_edit_el);
        action_el.appendChild(task_delete_el);

        task_el.appendChild(action_el);

        list_el.appendChild(task_el);

        input.value = '';

        task_edit_el.addEventListener('click', () => {
            console.log(task_edit_el.innerText.toLowerCase());
            if (task_edit_el.innerText.toLowerCase() == "edit") {
                task_edit_el.innerText = "Save";
                task_input_el.removeAttribute("readonly");
                task_input_el.focus();
            } else {
                task_edit_el.innerText = "Edit";
                task_input_el.setAttribute("readonly","readonly");
            }
        });

        task_delete_el.addEventListener('click', () => {
            list_el.removeChild(task_el);
        })
    });
});
