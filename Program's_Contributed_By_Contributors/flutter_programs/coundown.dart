//TODO: make new flutter project then copy-paste this code bellow to lib/main.dart

/*
import 'dart:async';
import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

//style color contents
class Constants {
  static const double kPadding = 10.0;

  static const Color purpleLight = Color(0xff1e224c);
  static const Color purpleDark = Color(0XFF0d193e);
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.blue,
        scaffoldBackgroundColor: Constants.purpleDark,
        canvasColor: Constants.purpleLight,
      ),
      home: const TimerPage(),
    );
  }
}

//timer state
class TimerPage extends StatefulWidget {
  const TimerPage({Key? key}) : super(key: key);

  @override
  State<TimerPage> createState() => _TimerPageState();
}

class _TimerPageState extends State<TimerPage> {
  static const maxSeconds = 5;
  int seconds = maxSeconds;
  Timer? timer;

  //Reset Function
  void resetTimer() => setState(
        () => seconds = maxSeconds,
      );

  //Start Function
  void startTimer({bool reset = true}) {
    if (reset) {
      resetTimer();
    }

    timer = Timer.periodic(const Duration(seconds: 1), (_) {
      if (seconds > 0) {
        setState(() => seconds--);
      }
    });
  }

  @override
  //Main Widget
  Widget build(BuildContext context) => Scaffold(
        body: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              buildTime(),
              const SizedBox(
                height: 40,
              ),
              buildButtons(),
            ],
          ),
        ),
      );

  //Button Widget
  Widget buildButtons() {
    final isRunning = timer == null ? false : timer!.isActive;
    final isCompleted = seconds == maxSeconds || seconds == 0;

    return isRunning || !isCompleted
        ? ButtonWidget(
            onClicked: () {
              if (isRunning) {
                null;
              } else {
                startTimer(reset: false);
              }
            },
            text: "Start",
            backgroundColor: const Color(0xff2b2b2b),
          )
        : ButtonWidget(
            onClicked: () {
              startTimer();
            },
            color: Colors.black,
            backgroundColor: Colors.white,
            text: "Start",
          );
  }

  //Content Widget
  Widget buildTime() {
    if (seconds == 0) {
      return const VictoryWidget();
    } else {
      return Text(
        '$seconds',
        style: const TextStyle(
          fontWeight: FontWeight.bold,
          color: Colors.white,
          fontSize: 80,
        ),
      );
    }
  }
}

//button widget
class ButtonWidget extends StatelessWidget {
  const ButtonWidget({
    Key? key,
    required this.onClicked,
    required this.text,
    this.backgroundColor = Colors.black,
    this.color = Colors.white,
  }) : super(key: key);

  final String text;
  final Color color;
  final Color backgroundColor;
  final VoidCallback onClicked;

  @override
  Widget build(BuildContext context) => ElevatedButton(
        style: ElevatedButton.styleFrom(
          primary: backgroundColor,
          padding: const EdgeInsets.symmetric(horizontal: 32, vertical: 16),
        ),
        onPressed: onClicked,
        child: Text(
          text,
          style: TextStyle(fontSize: 20, color: color),
        ),
      );
}

//content widget
class VictoryWidget extends StatelessWidget {
  const VictoryWidget({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Column(
      children: const [
        Text(
          " Happy Brithday",
          style: TextStyle(
            fontSize: 20,
            color: Colors.white,
          ),
          textAlign: TextAlign.center,
        ),
        SizedBox(
          height: 20,
        ),
        Text(
          "Dear Jhon Doe 🎉",
          style: TextStyle(
            fontSize: 50,
            color: Colors.white,
            fontWeight: FontWeight.bold,
          ),
          textAlign: TextAlign.center,
        ),
      ],
    );
  }
}

*/