/**
 * @type {HTMLCanvasElement}
 */
const canvas = document.querySelector('.snek')
canvas.width = 400
canvas.height = 300
canvas.style.border = '2px solid #FF0844'
canvas.style.width = '800px'
canvas.style.height = '600px'
canvas.style.margin = '0 auto'

/**
 * @type {HTMLDivElement}
 */
const container = document.querySelector('.snek-container')
container.style.display = 'flex'
container.style.justifyContent = 'center'
container.style.textAlign = 'center'
container.style.flexDirection = 'column'

/**
 * @type {HTMLButtonElement}
 */
const button = document.querySelector('.snek-play')
button.style.width = '200px'
button.style.background = 'green'
button.style.alignSelf = 'center'
button.style.display = 'none'

/**
 * @type {HTMLDivElement}
 */
const points = document.querySelector('.snek-points')
points.style.fontSize = '50px'
points.style.color = '#FF0844'

points.innerHTML = 0

button.addEventListener('click', () => {
  state = getInitialState()
  button.style.display = 'none'
})

const ctx = canvas.getContext('2d')

const GRID_SIZE = 10

const Directions = {
  Left: 'LEFT',
  Up: 'UP',
  Right: 'RIGHT',
  Down: 'DOWN',
}

const Keys = {
  Left: 37,
  Up: 38,
  Right: 39,
  Down: 40,
}

const DirectionKeys = {
  [Keys.Left]: Directions.Left,
  [Keys.Up]: Directions.Up,
  [Keys.Right]: Directions.Right,
  [Keys.Down]: Directions.Down,
}

const initialBodyLength = 3

const getInitialState = () => {
  const initialState = {
    x: canvas.width / 2,
    y: canvas.height / 2,
    direction: Directions.Up,
    alive: true,
    body: [],
    bodyLength: 3,
    currentFoodPosition: getFoodPosition(),
  }

  return initialState
}

let state = getInitialState()

function getFoodPosition() {
  return {
    x: Math.floor(Math.random() * (canvas.width / GRID_SIZE)) * GRID_SIZE,
    y: Math.floor(Math.random() * (canvas.height / GRID_SIZE)) * GRID_SIZE,
  }
}

const Movements = {
  [Directions.Left]: () => {
    const nextPos = leftPosition()
    if (nextPos>= 0) {
      state.x = nextPos
    } else {
      state.alive = false
    }
  },
  [Directions.Up]: () => {
    const nextPos = upPosition()
    if (nextPos>= 0) {
      state.y = nextPos
    } else {
      state.alive = false
    }
  },
  [Directions.Right]: () => {
    const nextPos = rightPosition()
    if (nextPos < canvas.width) {
      state.x = nextPos
    } else {
      state.alive = false
    }
  },
  [Directions.Down]: () => {
    const nextPos = downPosition()
    if (nextPos < canvas.height) {
      state.y = nextPos
    } else {
      state.alive = false
    }
  },
}

function leftPosition() {
  return state.x - GRID_SIZE
}

function rightPosition() {
  return state.x + GRID_SIZE
}

function upPosition() {
  return state.y - GRID_SIZE
}

function downPosition() {
  return state.y + GRID_SIZE
}

function drawSnake() {
  const {x, y, direction, alive, body, currentFoodPosition, bodyLength} = state
  if (alive) {
    // Snek is hungry
    if (x === currentFoodPosition.x && y === currentFoodPosition.y) {
      state.bodyLength++
      state.currentFoodPosition = getFoodPosition()
      points.innerHTML = state.bodyLength - initialBodyLength
    }

    // To hungry, eat self
    if (body.some(b => b.x === x && b.y === y)) {
      // dead
      state.alive = false
    }
    const movement = Movements[direction]
    movement && movement()

    
    ctx.clearRect(0, 0, canvas.width, canvas.height)
  } else {
    ctx.font = '20px Georgia'
    ctx.textBaseline = 'middle'
    ctx.textAlign = 'center'
    ctx.fillText('Game over', canvas.width / 2, canvas.height / 2)
    button.style.display = 'block'
  }

  body.push({x, y})
  if (body.length> bodyLength) {
    var itemToRemove = body.shift()
    ctx.clearRect(itemToRemove.x, itemToRemove.x, GRID_SIZE, GRID_SIZE)
  }
  ctx.fillStyle = 'green'
  body.forEach(({x, y}) => ctx.fillRect(x, y, GRID_SIZE, GRID_SIZE))
  ctx.fillRect(x, y, GRID_SIZE, GRID_SIZE)

  ctx.fillStyle = 'red'
  ctx.fillRect(
    currentFoodPosition.x,
    currentFoodPosition.y,
    GRID_SIZE,
    GRID_SIZE,
  )
}

/**
 *
 * @param {KeyboardEvent} e
 */
function changeDirection(e) {
  if (DirectionKeys[e.keyCode]) {
    const currentDirection = state.direction
    const nextDirection = DirectionKeys[e.keyCode]

    if (canMove(currentDirection, nextDirection)) {
      state.direction = DirectionKeys[e.keyCode]
    }
  }
}

/**
 *
 * @param {String} currentDirection
 * @param {String} nextDirection
 */
function canMove(currentDirection, nextDirection) {
  if (currentDirection === Directions.Up) {
    return nextDirection !== Directions.Down
  }
  if (currentDirection === Directions.Left) {
    return nextDirection !== Directions.Right
  }
  if (currentDirection === Directions.Right) {
    return nextDirection !== Directions.Left
  }
  if (currentDirection === Directions.Down) {
    return nextDirection !== Directions.Up
  }
}

window.setInterval(drawSnake, 100)
window.addEventListener('keydown', changeDirection)
