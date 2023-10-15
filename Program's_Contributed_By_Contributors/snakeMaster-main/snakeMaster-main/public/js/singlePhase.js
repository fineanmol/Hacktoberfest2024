import mainScene from './mainScene.js';

const config = {
  width: 528,
  height: 528,
  type: Phaser.AUTO,
  parent: 'phaserGame',
  scene: [mainScene]
};

new Phaser.Game(config);