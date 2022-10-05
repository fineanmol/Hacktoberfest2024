import arcade
import pathlib

#* Constants and windows dimensions
SCREEN_WIDTH = 1000
SCREEN_HEIGHT = 650
SCREE_TITLE = "Test Game"

#* Map scaling constants
MAP_SCALING = 1.0

#* Player constants
GRAVITY = 1.0
PLAYER_START_X = 65
PLAYER_START_Y = 256

#* Assest path
ASSETS_PATH = pathlib.Path(__file__).resolve().parent.parent / "assets"

class Plataformer(arcade.Window):
    def __init__(self) -> None:
        super().__init__(SCREEN_HEIGHT, SCREEN_WIDTH, SCREE_TITLE)

        #Setup of different configs in the game
        self.coins = None
        self.background = None
        self.walls = None
        self.ladders = None
        self.goals = None
        self.enemies = None
        self.player = None

        #Physic engine
        self.physics_engine = None

        #Score
        self.score = 0

        #Level
        self.level = 1

        #Assets parts
        # Load up our sounds here

        self.coin_sound = arcade.load_sound(

            str(ASSETS_PATH / "sounds" / "coin.wav")

        )

        self.jump_sound = arcade.load_sound(

            str(ASSETS_PATH / "sounds" / "jump.wav")

        )

        self.victory_sound = arcade.load_sound(

            str(ASSETS_PATH / "sounds" / "victory.wav")

        )

    def setup(self) -> None:
        """Sets up the game for the current level"""
        
        # Get the current map based on the level
        map_name = f"platform_level_{self.level:02}.tmx"
        map_path = ASSETS_PATH / map_name

        # Names of the layers
        wall_layer = "ground"
        coin_layer = "coin"
        goal_layer = "goal"
        background_layer = "background"
        ladders_layer = "ladders"

        # Load the current game map
        game_map = arcade.tilemap.read_tmx(str(map_path))

        # Load the layers
        self.background = arcade.tilemap.process_layer(
            game_map, layer_name=background_layer, scaling=MAP_SCALING
        )
        self.goals = arcade.tilemap.process_layer(
            game_map, layer_name=goal_layer, scaling=MAP_SCALING
        )
        self.walls = arcade.tilemap.process_layer(
            game_map, layer_name=wall_layer, scaling=MAP_SCALING
        )
        self.ladders = arcade.tilemap.process_layer(
            game_map, layer_name=ladders_layer, scaling=MAP_SCALING
        )
        self.coins = arcade.tilemap.process_layer(
            game_map, layer_name=coin_layer, scaling=MAP_SCALING
        )

        # Set the background color
        background_color = arcade.color.FRESH_AIR
        if game_map.background_color:
            background_color = game_map.background_color
        arcade.set_background_color(background_color)

        # Create the player sprite if it's not already set up
        if not self.player:
            self.player = self.create_player_sprite()

        # Move the player sprite back to the beginning
        self.player.center_x = PLAYER_START_X
        self.player.center_y = PLAYER_START_Y
        self.player.change_x = 0
        self.player.change_y = 0

        # Load the physics engine for this map
        self.physics_engine = arcade.PhysicsEnginePlatformer(
            player_sprite=self.player,
            platforms=self.walls,
            gravity_constant=GRAVITY,
            ladders=self.ladders
        )

    def create_player_sprite(self) -> arcade.AnimatedWalkingSprite:
        """Creates the animated player sprite
        
            Returns:
                The properly set up player sprite
        """
        # Path to the player images
        texture_path = ASSETS_PATH / "images" / "player"

        # Set up the appropriate textures
        walking_paths = [
            texture_path / f"alienGreen_walk{x}.png" for x in (1,2)
        ] 
        climbing_paths = [
            texture_path / f"alienGreen_climb{x}.png" for x in (1,2)
        ]
        standing_path = texture_path / "alienGreen_stand.png"

        # Load them
        walking_right_textures = [
            arcade.load_texture(texture) for texture in walking_paths
        ]
        walking_left_textures = [
            arcade.load_texture(texture,mirrored=True)
            for texture in walking_paths
        ]

        walking_up_textures = [
            arcade.load_texture(texture) for texture in climbing_paths
        ]
        walking_down_textures = [
            arcade.load_texture(texture) for texture in climbing_paths
        ]

        standing_right_textures = [arcade.load_texture(standing_path)]
        standing_left_textures = [
            arcade.load_texture(standing_path, mirrored=True)
        ]

        # Create the sprite
        player = arcade.AnimatedWalkingSprite()

        # Add the proper textures
        player.stand_left_textures = standing_left_textures
        player.stand_right_textures = standing_right_textures
        player.walk_left_textures = walking_left_textures
        player.walk_right_textures = walking_right_textures
        player.walk_up_textures = walking_up_textures
        player.walk_down_textures = walking_down_textures

        # Set up player defaults
        player.center_x = PLAYER_START_X
        player.center_y = PLAYER_START_Y
        player.state = arcade.FACE_RIGHT

        # Set the initial texture
        player.texture = player.stand_right_textures[0]

        return player


    def on_key_press(self, key: int, modifiers: int):
        """Processes key presses
        
            Arguments:
                key {int} --> which key was pressed
                modifiers {int} --> which modifiers were down at the time
        """
        pass
    
    def on_key_release(self, key: int, modifiers: int):
        """Processes key releases

            Arguments:
                key {int} --> which key was released
                modifiers {int} --> which modifers were down at the time
        """
        pass

    def on_update(self, delta_time: float):
        """Updates the position of all game objects

            Arguments:
                delta_time {float} --> time since last call
        """
        pass

    def on_draw(self):
        """Draws the game"""
        pass

if __name__ == "__main__":
    window = Plataformer()
    window.setup()
    arcade.run()
    