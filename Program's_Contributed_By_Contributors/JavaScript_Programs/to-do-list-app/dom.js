const INCOMPLETE_LIST = "incompleteList";
const COMPLETE_LIST = "completeList";

function addList() {
    const idList = +new Date();
    const inputListTitle = document.getElementById("inputListTitle").value;
    const inputListDescription = document.getElementById("inputListDescription").value;
    const inputListIsComplete = document.getElementById("inputListIsComplete").checked;

    const list = createList(idList, inputListTitle, inputListDescription, inputListIsComplete);
    const listObject = composeListObject(idList, inputListTitle, inputListDescription, inputListIsComplete);

    lists.push(listObject);

    if (inputListIsComplete) {
        document.getElementById(COMPLETE_LIST).append(list);
    } else {
        document.getElementById(INCOMPLETE_LIST).append(list);
    }

    updateJson();
}

function createList(idList, inputListTitle, inputListDescription, inputListIsComplete) {
    const list = document.createElement("article");
    list.setAttribute("id", idList)
    list.classList.add("card", "my-3");

    const listTitle = document.createElement("h5");
    listTitle.classList.add("text-truncate");
    listTitle.style.maxWidth = "200px";
    listTitle.innerText = inputListTitle;

    const listDescription = document.createElement("span");
    listDescription.classList.add("text-truncate", "d-inline-block");
    listDescription.style.maxWidth = "200px";
    listDescription.innerText = inputListDescription;

    const br = document.createElement("br");

    const cardContainer = document.createElement("div");
    cardContainer.classList.add("card-body", "border-start", "border-4", "border-info", "d-flex", "justify-content-between");

    const cardContent = document.createElement("div");
    cardContent.classList.add("card-content");

    const cardAction = addAction(inputListIsComplete, idList);

    cardContent.append(listTitle, listDescription, br);
    cardContainer.append(cardContent);
    cardContainer.append(cardAction);
    list.append(cardContainer);

    return list;
}

function addAction(inputListIsComplete, idList) {
    const cardActions = document.createElement("div");

    const actionDelete = createActionDelete(idList);
    const actionRead = createActionRead(idList);
    const actionUndo = createActionUndo(idList);

    cardActions.append(actionDelete);

    if (inputListIsComplete) {
        cardActions.append(actionUndo);
    } else {
        cardActions.append(actionRead);
    }

    return cardActions;
}

function createActionDelete(idList) {
    const actionDelete = document.createElement("button");
    actionDelete.classList.add("btn", "btn-sm", "btn-outline-danger", "mx-1");
    actionDelete.innerHTML = '<i class="bi bi-x"></i>';

    actionDelete.addEventListener("click", function () {
        let confirmation = confirm("apakah anda yakin ingin menghapus buku?");

        if (confirmation) {
            const cardParent = document.getElementById(idList);
            cardParent.addEventListener("eventDelete", function (event) {
                event.target.remove();
            });
            cardParent.dispatchEvent(new Event("eventDelete"));

            deleteListFromJson(idList);
            updateJson();
        }
    });

    return actionDelete;
}

function createActionRead(idList) {
    const action = document.createElement("button");
    action.classList.add("btn", "btn-sm", "btn-outline-success");
    action.innerHTML = '<i class="bi bi-check"></i>';

    action.addEventListener("click", function () {
        const cardParent = document.getElementById(idList);

        const listTitle = cardParent.querySelector(".card-content > h5").innerText;
        const listDescription = cardParent.querySelectorAll(".card-content > span")[0].innerText;

        cardParent.remove();

        const list = createList(idList, listTitle, listDescription, true);
        document.getElementById(COMPLETE_LIST).append(list);

        deleteListFromJson(idList);
        const listObject = composeListObject(idList, listTitle, listDescription, true);

        lists.push(listObject);
        updateJson();
    })

    return action;
}

function createActionUndo(idList) {
    const action = document.createElement("button");
    action.classList.add("btn", "btn-sm", "btn-outline-secondary");
    action.innerHTML = '<i class="bi bi-arrow-counterclockwise"></i>';

    action.addEventListener("click", function () {
        const cardParent = document.getElementById(idList);

        const listTitle = cardParent.querySelector(".card-content > h5").innerText;
        const listDescription = cardParent.querySelectorAll(".card-content > span")[0].innerText;

        cardParent.remove();

        const list = createList(idList, listTitle, listDescription,false);
        document.getElementById(INCOMPLETE_LIST).append(list);

        deleteListFromJson(idList);
        const listObject = composeListObject(idList, listTitle, listDescription, false);

        lists.push(listObject);
        updateJson();
    })

    return action;
}

function listSearch(keyword) {
    const filter = keyword.toUpperCase();
    const titles = document.getElementsByTagName("h5");

    for (let i = 0; i < titles.length; i++) {
        const titlesText = titles[i].textContent || titles[i].innerText;

        if (titlesText.toUpperCase().indexOf(filter) > -1) {
            titles[i].closest(".card").style.display = "";
        } else {
            titles[i].closest(".card").style.display = "none";
        }
    }
}