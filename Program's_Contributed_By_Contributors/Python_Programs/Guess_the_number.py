import chisel3._
import chisel3.util._

class NumberGuessGame extends Module {
  val io = IO(new Bundle {
    val resetGame = Input(Bool())
    val guess = Input(UInt(8.W))
    val correct = Output(Bool())
    val gameOver = Output(Bool())
  })

  val secretNumber = RegInit(42.U(8.W)) // Initialize the secret number to 42
  val attemptsLeft = RegInit(3.U(4.W)) // Initialize attempts left to 3

  when(io.resetGame) {
    secretNumber := 42.U // Reset the secret number to 42
    attemptsLeft := 3.U // Reset attempts left to 3
  }

  val isCorrect = io.guess === secretNumber
  val isGameOver = attemptsLeft === 0.U || isCorrect

  when(!isGameOver) {
    when(io.guess > secretNumber) {
      attemptsLeft := attemptsLeft - 1.U
    }.elsewhen(io.guess < secretNumber) {
      attemptsLeft := attemptsLeft - 1.U
    }
  }

  io.correct := isCorrect
  io.gameOver := isGameOver
}

object NumberGuessGameMain extends App {
  chisel3.Driver.execute(args, () => new NumberGuessGame) { c =>
    val io = c.io
    var gameOver = false
    var attempts = 3

    while (!gameOver) {
      println(s"Attempts left: $attempts")
      print("Enter your guess: ")
      val guess = scala.io.StdIn.readInt()
      io.guess.poke(guess.U)
      c.clock.step()

      val isCorrect = io.correct.peek().litToBoolean
      gameOver = io.gameOver.peek().litToBoolean
      attempts -= 1

      if (isCorrect) {
        println("Congratulations! You guessed correctly!")
        gameOver = true
      } else if (gameOver) {
        println(s"Game over! The secret number was ${io.secretNumber.peek().litValue()}.")
      } else if (attempts == 0) {
        println("Out of attempts! Game over.")
        gameOver = true
      } else {
        println("Try again.")
      }
    }
  }
}
