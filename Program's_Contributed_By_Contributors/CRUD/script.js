var selectedRow = null;

function showAlert(message, className){
    const div = document.creteElement("div");
    div.className = `alert alert-${className}`;

    div. appendChild(document.createTextNode(message));
    const container = document.querySelector(".container");
    const main = document.querySelector(".main");
    container.insertBefore(div, main);

    setTimeout(() => document.querySelector(".alert").remove(), 3000);

}

// clear cmd

function clearFields(){
    document.querySelector("#userName").value="";
    document.querySelector("#email").value="";
    document.querySelector("#rollno").value="";
}

//add data

document.querySelector("#student-form").addEventListener("submit", (e) =>{
    e.preventDefault();

    const userName = document.querySelector("#userName").value;
    const email = document.querySelector("#email").value;
    const rollno = document.querySelector("#rollno").value;

    if(userName == "" || email == "" || rollno == ""){
        alert("Please fill in all fields", "danger");
    }
    else{
        if(selectedRow == null){
        const list = document.querySelector("#student-list");
        const row = document.createElement("tr");

        row.innerHTML = `
        <td>${userName}</td>
        <td>${email}</td>
        <td>${rollno}</td>
        <td>
        <a href="#" class="btn btn-warning btn-sm edit" id="edit">Edit</a>
        <a href="#" class="btn btn-danger btn-sm delete" id="delete">Delete</a>
        </td>
        `;
        list.appendChild(row);
        selectedRow = null;
        alert("Student Added", "Success")         
    }
    else{
        selectedRow.children[0].textContent = userName;
        selectedRow.children[1].textContent = email;
        selectedRow.children[2].textContent = rollno;
        selectedRow = null;
        alert("Student Info Edited", "info");
    }
    clearFields();
}

});

//Edit cmd

document.querySelector("#student-list").addEventListener("click", (e) =>{
    target = e.target;
    if(target.classList.contains("edit")){
        selectedRow = target.parentElement.parentElement;
        document.querySelector("#userName").value = selectedRow.children[0].textContent;
        document.querySelector("#email").value = selectedRow.children[1].textContent;
        document.querySelector("#rollno").value = selectedRow.children[2].textContent;
    }
});

// Delete cmd

document.querySelector("#student-list").addEventListener("click", (e) =>{
    target = e.target;
    if(target.classList.contains("delete")){
        target.parentElement.parentElement.remove();
        alert("Student Data Deleted", "danger");
    }
});