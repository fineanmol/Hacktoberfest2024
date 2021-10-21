// adding querry link to delete button
function addinglink(idsArr) {
  console.log("addinglink", addinglink);
  if (idsArr.length == 0) {
    window.alert("Please select atleast one task to delete");
  } else {
    window.alert("Please click ok to delete");
  }

  let count = 0;
  link = "/delete-task/?";
  for (let id of idsArr) {
    console.log(id);
    link += "id" + count + "=";
    link += id;
    if (count < idsArr.length - 1) {
      link += "&";
    }
    count++;
  }
  console.log("s:", link);
  document.querySelector(".del>a").setAttribute("href", link);
}

// adding event listner on delete button and storing all the id's of marked checkbox
function getdel() {
  let idsArr = new Array();
  for (let checkbox of document.querySelectorAll('input[type="checkbox"]')) {
    if (checkbox.checked) {
      idsArr.push(checkbox.getAttribute("id"));
    }
  }
  addinglink(idsArr);
}
