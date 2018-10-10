let contributors = document.querySelectorAll('.card-text a')
contributors.forEach(con => {
    console.log(con.href)
    con.innerHTML += '<img style="width: 62px; margin-left: 12px" src="https://github.com/'+ con.href.split('https://github.com/')[1] + '.png?size=62">'
})