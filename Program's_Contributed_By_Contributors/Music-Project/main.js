class Myheader extends HTMLElement{
    connectedCallback() {
        this.innerHTML = `
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <style>
            body {
            font-family: "Lato", sans-serif;
            }

            .sidenav {
                height: 100%;
                width: 200px;
                position: fixed;
                z-index: 0;
                top: 0;
                left: 0;
                background-color: #111;
                overflow-x: hidden;
                padding-top: 20px;
            }

            .sidenav a {
                padding: 6px 6px 6px 32px;
                text-decoration: none;
                font-size: 18px;
                color: #818181;
                display: block;
            }

            .sidenav a:hover {
                color: #f1f1f1;
            }

            .main {
                margin-left: 200px; /* Same as the width of the sidenav */
            }

            @media screen and (max-height: 450px) {
                .sidenav {padding-top: 15px;}
                .sidenav a {font-size: 18px;}
            }
        </style>

        <div class="sidenav">
            <a href="./index.html">Home</a>
            <a href="./search.html">Search</a>
            <a href="#">About Us</a>
            <a href="#">My laylist</a>
        </div>
        `
    }
}

customElements.define('my-header', Myheader)