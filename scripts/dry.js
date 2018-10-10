class Rain {
  constructor(ctx, {width, height}) {
    this.width = width
    this.height = height
    this.ctx = ctx
    this.size = Math.floor(Math.random() * 6) + 5
    this.x = Math.floor(Math.random() * this.width)
    this.y = -this.size
    this.vx = 0
    this.vy = 0
    this.gravity = 0.1
    this.maxSpeed = 4
    this.color = '#174fd5'
  }

  updateVelocity() {
    this.vy += this.gravity
  }
  updatePosition() {
    this.y += this.vy
  }

  update() {
    this.updateVelocity()
    this.updatePosition()
    this.ctx.fillStyle = this.color
    this.ctx.fillRect(this.x, this.y, this.size, this.size)
    cc.checkCollission({x: this.x, y: this.y, size: this.size})
  }
}

class Actor {
  constructor(ctx, {width, height}) {
    this.width = width
    this.height = height
    this.ctx = ctx
    this.size = 10
    this.x = this.width/2 - this.size / 2
    this.y = this.height/2 - this.size
    this.vx = 0
    this.vy = 0
    this.jumping = true
    this.gravity = 0.2
    this.friction = 0.8
    this.maxSpeed = 4
    this.color = '#ffffff'
    this.keys = []
    this.initializeControls()
  }

  initializeControls() {
    addEventListener('keydown', ({keyCode}) => {
      this.keys[keyCode] = true
    })
    addEventListener('keyup', ({keyCode}) => {
      this.keys[keyCode] = false
    })
  }

  move() {
    if (this.keys[38] && !this.jumping) {
      this.jumping = true
      this.vy = -this.maxSpeed * 2
    }

    if (this.keys[37] && this.vx < this.maxSpeed) {
      this.vx -= 0.9
    }

    if (this.keys[39] && this.vx > -this.maxSpeed) {
      this.vx += 0.9
    }
  }

  updateVelocity() {
    this.vx *= this.friction
    this.vy += this.gravity
  }

  updatePosition() {
    this.y += this.vy
    this.x += this.vx
  }

  checkBoundries() {
    if (this.x >= this.width - this.size) {
      this.x = this.width - this.size
    } else if (this.x < 0) {
      this.x = 0
    }

    if (this.y >= this.height - this.size) {
      this.jumping = false
      this.y = this.height - this.size
    }

    cc.updateActor({x: this.x, y: this.y, size: this.size})
  }

  update() {
    this.updateVelocity()
    this.move()
    this.updatePosition()
    this.checkBoundries()
    this.ctx.fillStyle = this.color
    this.ctx.fillRect(this.x, this.y, this.size, this.size)
  }
}

class Timer {
  constructor(ctx, {width, height}) {
    this.ctx = ctx
    this.width = width
    this.height = height
    this.time = 0
    this.startTimer()
  }

  startTimer() {
    setInterval(() => {
      this.time += 0.1
    }, 100)
  }

  update() {
    this.ctx.fillStyle = '#ffffff'
    this.ctx.font = '15px sans-serif'
    this.ctx.textAlign = 'center'
    this.ctx.fillText(this.time.toFixed(1), this.width - 25, 25)
    cc.setTime(this.time)
  }

  getTime() {
    return this.time
  }
}

class CollissionControl {
  constructor() {
    this.actor = {}
    this.hasCollided = false
    this.time = 0
  }

  updateActor({x, y, size}) {
    this.actor = {x, y, size}
  }

  checkCollission({x, y, size}) {
    if (
      this.actor.x < x + size &&
      this.actor.x + this.actor.size > x &&
      this.actor.y < y + size &&
      this.actor.size + this.actor.y > y
    ) {
      this.hasCollided = true
    }
  }

  isColliding() {
    return this.hasCollided
  }

  setTime(time) {
    this.time = time
  }

  getTime() {
    return this.time
  }
}

class Scene {
  constructor() {
    const canvas = document.querySelector('.dry-game')
    this.ctx = canvas.getContext('2d')
    const {width, height} = canvas
    this.width = width
    this.height = height
    this.objects = []
    this.showMenu = true
    this.game = true
    this.gameOver = false
    this.restart = false
    this.rainInterval = null
    this.initializeMenuControls()
  }

  initialize() {
    if (this.game) {
      this.addObject(
        new Actor(this.ctx, {height: this.height, width: this.width}),
      )
      this.addObject(
        new Timer(this.ctx, {height: this.height, width: this.width}),
      )
      this.rainInterval = setInterval(() => {
        this.addObject(
          new Rain(this.ctx, {height: this.height, width: this.width}),
        )
      }, 25)
      this.game = false
    }
  }

  background() {
    const gradient = this.ctx.createLinearGradient(0, 0, 170, 0)
    gradient.addColorStop(0, '#ff5974')
    gradient.addColorStop(1, '#ff0844')
    this.ctx.fillStyle = gradient
    this.ctx.fillRect(0, 0, this.height, this.width)
  }

  addObject(object) {
    this.objects.push(object)
  }

  beginGame() {
    this.objects.forEach(object => object.update())
  }

  initializeMenuControls() {
    document.querySelector('.dry-game').addEventListener('click', () => {
      this.showMenu = false
      if (this.gameOver) {
        this.restart = true
      }
    })
  }

  menu() {
    this.ctx.fillStyle = 'rgba(255, 255, 255, 0.8)'
    this.ctx.font = '32px sans-serif'
    this.ctx.textAlign = 'center'
    this.ctx.fillText('STAY DRY', this.width / 2, this.height / 2 - 10)

    this.ctx.fillStyle = '#ffffff'
    this.ctx.font = '50px sans-serif'
    this.ctx.textAlign = 'center'
    this.ctx.fillText('START', this.width / 2, this.height / 2 + 40)
  }

  update() {
    this.ctx.clearRect(0, 0, this.width, this.height)
    this.background()
    this.gameOver = cc.isColliding()
    if (this.gameOver) {
      clearInterval(this.rainInterval)
      this.objects = []
      this.ctx.font = '32px sans-serif'
      this.ctx.textAlign = 'center'
      this.ctx.fillStyle = '#ffffff'
      this.ctx.fillText(
        `${cc.getTime().toFixed(1)}s`,
        this.width / 2,
        this.height / 2 - 50,
      )
      this.ctx.font = '32px sans-serif'
      this.ctx.fillStyle = 'rgba(255, 255, 255, 0.8)'
      this.ctx.fillText('YOU ARE WET', this.width / 2, this.height / 2 - 10)
      this.ctx.fillStyle = '#ffffff'
      this.ctx.font = '50px sans-serif'
      this.ctx.fillText('RESTART?', this.width / 2, this.height / 2 + 40)
      if (this.restart) {
        this.game = true
        this.gameOver = false
        this.restart = false
        cc.hasCollided = false
      }
    }

    if (this.showMenu) {
      this.menu()
    } else {
      this.initialize()
      this.beginGame()
    }
  }
}

class Hopper {
  constructor() {
    this.scene = new Scene()
    this.render()
  }

  render() {
    requestAnimationFrame(this.render.bind(this))
    this.scene.update()
  }
}

// As dirty as a popsicle that has been in mud for 3 decades. Super dirty. Unsaveable. But it worksish.
const cc = new CollissionControl()
new Hopper()
