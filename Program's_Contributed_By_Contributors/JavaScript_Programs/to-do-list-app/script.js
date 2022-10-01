document.addEventListener("DOMContentLoaded", function () {

    const formInput = document.getElementById("inputList");
    const formSearch = document.getElementById("searchList");

    formInput.addEventListener("submit", function (event) {
        event.preventDefault();
        addList();

        document.getElementById("inputListTitle").value = "";
        document.getElementById("inputListDescription").value = "";
        document.getElementById("inputListIsComplete").checked = false;
    });

    formSearch.addEventListener("submit", function (event) {
        event.preventDefault();

        const inputSearch = document.getElementById("searchListTitle").value;
        listSearch(inputSearch);
    })

    if (isStorageSupported()) {
        fetchJson();
    }
});

document.addEventListener("onjsonfetched", function () {
    renderFromList();
});