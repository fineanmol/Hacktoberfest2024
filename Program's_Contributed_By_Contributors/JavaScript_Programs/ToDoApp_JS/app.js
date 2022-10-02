function add() {
    var data = document.getElementById('text').value;

    if (data === "") {
        alert("Nothing To Add!", "", "warning");

    }
    else {

        var div = document.createElement("div")
        div.setAttribute('class', 'input-group p-3')

        var inp = document.createElement("input");
        inp.value = data
        inp.setAttribute('class', 'form-control bg-darl')
        inp.setAttribute('disabled', 'disabled')
        // inp.setAttribute('autofocus', 'autofocus')


        var editBtn = document.createElement('button')
        var edittext = document.createTextNode('Edit')
        editBtn.appendChild(edittext)
        editBtn.setAttribute('class', 'btn btn-success')
        editBtn.setAttribute('onclick', 'edit(this.previousSibling)')


        var delBtn = document.createElement('button')
        var deltext = document.createTextNode('Delete')
        delBtn.appendChild(deltext)
        delBtn.setAttribute('class', 'btn btn-outline-dark')
        delBtn.setAttribute('onclick', 'del(this)')


        div.appendChild(inp)
        div.appendChild(editBtn)
        div.appendChild(delBtn)
        main.appendChild(div)

        document.getElementById('text').value = "";
        alert("Successfully Added!", "", "success");

    }
}

function del(a) {

swal({
  title: "Are you sure?",
  text: "",
  icon: "warning",
  buttons: true,
  buttons: ["No", "Yes"],
  dangerMode: true,
})
.then((willDelete) => {
  if (willDelete) {
    a.parentNode.remove();
  } 
});

}


function edit(inputdata) {
    var check = inputdata.nextSibling.innerText
    if (check === "Edit") {
        console.log(inputdata)

        inputdata.disabled = false;
        inputdata.focus();

        inputdata.nextSibling.innerText = "Update"
        console.log(inputdata.nextSibling.innerText = "Update")
    }
    else if (check === "Update") {
        inputdata.disabled = true;
        inputdata.nextSibling.innerText = "Edit"
        swal("Successfully Updated!", "", "success");

    }
    else {
        alert("Some Error Occur")
    }

}

// alertify.confirm("This is a confirm dialog.",
//     function () {
//         alertify.success('Ok');
//     },
//     function () {
//         alertify.error('Cancel');
//     });

function enter(code) {
    if (code.keyCode === 13) {
        add()
    }
}
    
    
    
    
     
     
     
     
     
