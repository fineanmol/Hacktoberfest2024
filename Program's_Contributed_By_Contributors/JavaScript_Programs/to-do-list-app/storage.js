const LIST_KEY = "LIST_APP";

let lists = [];

function isStorageSupported() {
    if (typeof Storage === "undefined") {
        alert("Your browser doesn't support Web Storage !");
        return false;
    } else {
        return true;
    }
}

function updateJson() {
    if (isStorageSupported()) {
        localStorage.setItem(LIST_KEY, JSON.stringify(lists));
    }
}

function fetchJson() {
    let data = JSON.parse(localStorage.getItem(LIST_KEY));

    if (data !== null) {
        lists = data;
    }

    document.dispatchEvent(new Event("onjsonfetched"));
}

function composeListObject(id, title, description, isComplete) {
    return {
        id, title, description, isComplete
    };
}

function renderFromList() {
    for (list of lists) {
        const newList = createList(lists.id, lists.title, lists.description, lists.isComplete);

        if (list.isComplete) {
            document.getElementById(COMPLETE_LIST).append(newList);
        } else {
            document.getElementById(INCOMPLETE_LIST).append(newList);
        }
    }
}

function deleteListFromJson(idList) {
    for (let arrayPosition = 0; arrayPosition < lists.length; arrayPosition++) {
        if (lists[arrayPosition].id == idList) {
            lists.splice(arrayPosition, 1);
            break;
        }
    }
}