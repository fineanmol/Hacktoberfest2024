
/*
* D K
*/

// Slider for Jetpack Compose(seekbar in java)
@Composable
fun sliderSample() {
    var sliderVal by remember {
        mutableStateOf(0f)
    }
    Column(
        modifier = Modifier.padding(horizontal = 15.dp)
    ) {
        Slider(value = sliderVal, onValueChange = {
            sliderVal = it
        },
            steps = 3,
            valueRange = 0f..50f,
            )
        Text(text = sliderVal.toString())
    }
}


// Range Slider like in pricing slide in flipkart for lower // price to higher price
@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun rangeSliderSample() {
    var rangeValue by remember{
        mutableStateOf(0f..100f)
    }
    var text by remember{
        mutableStateOf("")
    }
    Column {
        RangeSlider(value = rangeValue, onValueChange = {
            rangeValue = it
        },
            steps = 5,
            valueRange = 0f..100f,
            onValueChangeFinished = {
                text = "FINISHED"
            })
        Text(text = rangeValue.toString())
        Text(text = text)


    }
}


// Example of Snackbar with scaffold
@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun snackBarSample() {
    val snackBarHost = remember {
        SnackbarHostState()
    }
    var scope = rememberCoroutineScope()
    Scaffold(
        snackbarHost = {
            SnackbarHost(hostState = snackBarHost)
        },
        floatingActionButton = {
            ExtendedFloatingActionButton(
                text = { Text("Show snackbar") },
                icon = { Icon(Icons.Filled.Home, contentDescription = "") },
                onClick = {
                    scope.launch {
                        snackBarHost.showSnackbar("Snackbar")
                    }
                }
            )
        }
    ) {contentPadding ->
contentPadding
    }
}


// demonstrating flashlight effect using graphics
@Composable
fun drawWithContent() {
    var offset by remember {
        mutableStateOf(Offset(100f, 100f))
    }
    Column(
        modifier = Modifier
            .fillMaxSize()
            .pointerInput("dragging") {
                detectDragGestures { change, dragAmount ->
                    offset += dragAmount
                }
            }
            /* .onSizeChanged {
                offset = Offset(it.width / 2f, it.height / 2f)
            }*/
            .drawWithContent {
                drawContent()
                drawRect(
                    brush = Brush.radialGradient(
                        colors = listOf(Color.Transparent, Color.Black),
                        center = offset,
                        radius = 100.dp.toPx()
                    )
                )
            }
    ){
        Image(painter = painterResource(id = R.drawable.ic_launcher_background), contentDescription = null)
    }
}


// Demonstrated path graphics
@Composable
fun drawLineSample() {
    Spacer(modifier = Modifier.drawWithCache {
        val path = Path()
        path.moveTo(0f, 20f)
        path.lineTo(0f, 20f)
        path.lineTo(20f, 0f)
        path.lineTo(20f, 30f)
        path.close()
        this.onDrawBehind {
            drawPath(path, color = Color.Magenta, style = Fill)
        }
    })
}