function formValidation() {
    var uname = document.registration.username;
    var uadd = document.registration.address;
    var ucountry = document.registration.country;
    var uzip = document.registration.zip;
    var uemail = document.registration.email;
    var usex = document.registration.sex;
    var uabout = document.registration.desc;
    var ulang = document.registration.language;
    var uyear = document.registration.year;
    var udegree = document.registration.degree;
    var uinsti = document.registration.insti;
    var ures = document.registration.result;
    var upname = document.registration.pname;
    var upabout = document.registration.pabout;
    var upos = document.registration.position;
    var udur = document.registration.duration;
    var ucomp = document.registration.company;

    if (allLetter(uname)) {
        if (alphanumeric(uadd)) {
            if (countryselect(ucountry)) {
                if (allnumeric(uzip)) {
                    if (ValidateEmail(uemail, mail)) {
                        if (validsex(usex)) {
                            if (allnumeric(uyear)) {
                                checkAbout(uabout),
                                    lang(ulang),
                                    education(uyear, udegree, uinsti, ures),
                                    address(uadd, ucountry, uzip),
                                    project(upname, upabout),
                                    experience(ucomp, udur, upos);
                                    alert('Form Successfully Submitted');
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

function experience(ucomp, udur, upos) {

    if (ucomp.value == "" || udur.value == "" || upos.value == "") {
        document.getElementById("expinfo").remove()
    }
    else {
        document.getElementsByClassName("position")[0].innerHTML = upos.value
        document.getElementsByClassName("company")[0].innerHTML = ucomp.value
        document.getElementsByClassName("duration")[0].innerHTML = udur.value
    }
}

function education(uyear, udegree, uinsti, ures) {

    document.getElementsByClassName("yr")[0].innerHTML = uyear.value
    document.getElementsByClassName("deg")[0].innerHTML = udegree.value
    document.getElementsByClassName("insti")[0].innerHTML = uinsti.value
    document.getElementsByClassName("res")[0].innerHTML = ures.value

}

function project(upname, upabout) {
    if (upname.value !== "" || upabout.value !== "") {
        document.getElementsByClassName("pname")[0].innerHTML = upname.value
        document.getElementsByClassName("pabout")[0].innerHTML = upabout.value
    }
    else {
        document.getElementById("pinfo").remove()
    }
}

function checkAbout(uabout) {
    if (uabout.value.trim() !== "")
        document.getElementById("about").innerHTML = uabout.value.trim()
    else
        document.getElementById("about").parentElement.remove()
}

function address(uadd, ucountry, uzip) {
    var address = ""
    if (uadd.value.trim() !== "")
        address += uadd.value.trim() + "<br>"
    address += ucountry.value + "<br>"
    if (uzip.value)
        address += uzip.value
    document.getElementById("address").innerHTML = address
}

function lang(ulang) {
    var lang = ""

    for (var i of ulang) {
        if (i.checked)
            lang += i.value + "<br>"
    }
    document.getElementById("lang").innerHTML = lang
}

function allLetter(uname) {
    var letters = /^[A-Za-z ]+$/;   //Regex
    if (uname.value.trim().match(letters)) {
        document.getElementById("name").innerHTML = uname.value.toUpperCase()
        return true;
    }
    else {
        alert('Username must have alphabet characters only');
        uname.focus();
        return false;
    }
}

function alphanumeric(uadd) {
    var letters = /^[0-9a-zA-Z/ ]+$/;
    if (uadd.value.trim().match(letters) || uadd.value.trim() === "") {
        return true;
    }
    else {
        alert('User address must have alphanumeric characters only');
        uadd.focus();
        return false;
    }
}

function countryselect(ucountry) {
    if (ucountry.value == "Default") {
        alert('Select your country from the list');
        ucountry.focus();
        return false;
    }
    else {
        return true;
    }
}

function allnumeric(uzip) {
    var numbers = /^[0-9]+$/;
    if (uzip.value.trim().match(numbers) || uzip.value.trim() === "") {
        return true;
    }
    else {
        alert('ZIP code must have numeric characters only');
        uzip.focus();
        return false;
    }
}

function ValidateEmail(uemail) {
    var mailformat = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
    if (uemail.value.match(mailformat)) {
        document.getElementById("mail").href = "mailto:" + uemail.value
        document.getElementById("mail").innerHTML = uemail.value
        return true;
    }
    else {
        alert("You have entered an invalid email address!");
        uemail.focus();
        return false;
    }
}

function validsex(usex) {
    if (usex[0].checked || usex[1].checked) {
        console.log("assets/" + (usex[0].checked ? "male.png" : "female.png"))
        document.getElementsByTagName("img")[0].src = "./assets/" + (usex[0].checked ? "male.png" : "female.png")
        console.log(document.getElementsByTagName("img")[0].src)
        document.getElementsByTagName("h4")[0].innerHTML = usex[0].checked ? "MALE" : "FEMALE"
        return true;
    }
    else {
        alert('Select Male/Female');
        usex[0].focus();
        return false;
    }
}
document.getElementById("blue").addEventListener("click", blue)
function blue() {
    document.getElementById("theme").setAttribute("href", "./themes/blue.css")
}

document.getElementById("default").addEventListener("click", lavender)
function lavender() {
    document.getElementById("theme").setAttribute("href", "./themes/resume.css")
}

document.getElementById("grey").addEventListener("click",grey )
function grey() {
    document.getElementById("theme").setAttribute("href", "./themes/grey.css")
}
