import snake from './snake.js'

export default class mainScene extends Phaser.Scene {
  constructor() {
    super('mainScene');
  }

  create() {
    this.snake = new snake(this);
  }

  update(time) {
    this.snake.update(time);
  }

}

