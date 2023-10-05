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
