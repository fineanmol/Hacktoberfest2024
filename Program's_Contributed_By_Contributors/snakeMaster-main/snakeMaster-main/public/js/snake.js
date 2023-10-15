export default class snake {
  constructor(scene){
    this.scene = scene;
    this.lastMoveTime = 0;
    this.moveInterval = 500;
    this.tileSize = 16;
    //Snake🐍 start point
    this.direct = Phaser.Math.Vector2.RIGHT;

    this.body = [];
    this.body.push(this.scene.add.rectangle(32,32,this.tileSize,this.tileSize,0xff0000).setOrigin(0)); 
    //Apple 🍎 starts here
    this.apple = this.scene.add.rectangle(0,0,this.tileSize,this.tileSize,0x00ff00).setOrigin(0);
    //Ramdom Apple 🍎 generate here
    this.appleSpawn();
    scene.input.keyboard.on('keydown', e => {
      this.keydown(e);
    });
  }
  //Ramdom Apple 🍎 Function definitions 
  appleSpawn(){
    this.apple.x = Math.floor(Math.random() * this.scene.game.config.width / this.tileSize) * this.tileSize;
    this.apple.y = Math.floor(Math.random() * this.scene.game.config.width / this.tileSize) * this.tileSize;
  }
  keydown(event) {
    console.log(event);
    switch (event.keyCode){
      case 37: //To move left
        if (this.direct !== Phaser.Math.Vector2.RIGHT)
          this.direct = Phaser.Math.Vector2.LEFT;
        break;
      case 38: //To move up 
        if (this.direct !== Phaser.Math.Vector2.DOWN)
          this.direct = Phaser.Math.Vector2.UP;
        break;
      case 39: //To move right
        if (this.direct !== Phaser.Math.Vector2.LEFT)
          this.direct = Phaser.Math.Vector2.RIGHT;
        break;
      case 40: //To move down
        if (this.direct !== Phaser.Math.Vector2.UP)
          this.direct = Phaser.Math.Vector2.DOWN;
        break;
    }
  }
  update(time) {
    if(time >= this.lastMoveTime + this.moveInterval){
      this.lastMoveTime = time;
      this.move();
    }
  }
  move() {
    //Eating apple strategy
    let x = this.body[0].x + this.direct.x * this.tileSize;
    let y = this.body[0].y + this.direct.y * this.tileSize;

    if(this.apple.x === x && this.apple.y === y){
      //Apple eaten
      this.body.push(this.scene.add.rectangle(0,0,this.tileSize,this.tileSize, 0xffffff).setOrigin(0));
      this.appleSpawn();
    }

    for (let index = this.body.length - 1; index>0; index--) {
      this.body[index].x = this.body[index-1].x;
      this.body[index].y = this.body[index-1].y;
    }
    this.body[0].x = x;
    this.body[0].y = y;

    //Eternal snake🐍 must die if offscreen
    if (this.body[0].x < 0 || this.body[0].x >= this.scene.game.config.width || this.body[0].y < 0 || this.body[0].y >= this.scene.game.config.height) {
      this.scene.scene.restart();
    }
    //Eternal snake🐍 must die if eat own body.
    let tail = this.body.slice(1);
    if (tail.some(s => s.x === this.body[0].x && s.y === this.body[0].y)) {
      this.scene.scene.restart();
    }
  }
}