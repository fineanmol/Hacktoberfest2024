const relevantKeys = {
    37: 'left',
    38: 'up',
    39: 'right',
    40: 'down',
    65: 'a',
    66: 'b',
}

const keySequence = ['up', 'up', 'down', 'down', 'left', 'right', 'left', 'right', 'b', 'a'];
let positionInSequence = 0;

document.addEventListener('keydown', function(e) {
    let keyPressed = relevantKeys[e.keyCode];

    if (keyPressed === keySequence[positionInSequence]) {
        positionInSequence++;
        if (positionInSequence === keySequence.length) {
            activateResult();
            positionInSequence = 0;
        }
    } else {
        positionInSequence = 0;
    }
})

function activateResult() {
    let canvas = document.createElement('canvas');

    canvas.setAttribute('width', '400');
    canvas.setAttribute('height', '400');
    canvas.setAttribute('class', 'center');
    canvas.setAttribute('style', 'position: fixed; left: 30%; top: 20%;')

    ctx = canvas.getContext("2d");

    let w = 200, h = 200;

    ctx.strokeStyle = "#000000";
    ctx.strokeWeight = 3;
    ctx.shadowOffsetX = 4.0;
    ctx.shadowOffsetY = 4.0;
    ctx.lineWidth = 10.0;
    ctx.fillStyle = "#FF0000";

    const d = Math.min(w, h);
    const k = 120;

    ctx.moveTo(k, k + d / 4);
    ctx.quadraticCurveTo(k, k, k + d / 4, k);
    ctx.quadraticCurveTo(k + d / 2, k, k + d / 2, k + d / 4);
    ctx.quadraticCurveTo(k + d / 2, k, k + d * 3/4, k);
    ctx.quadraticCurveTo(k + d, k, k + d, k + d / 4);
    ctx.quadraticCurveTo(k + d, k + d / 2, k + d * 3/4, k + d * 3/4);
    ctx.lineTo(k + d / 2, k + d);
    ctx.lineTo(k + d / 4, k + d * 3/4);
    ctx.quadraticCurveTo(k, k + d / 2, k, k + d / 4);
    ctx.stroke();
    ctx.fill();

    let target = document.querySelector("#header")

    target.appendChild(canvas)
}
