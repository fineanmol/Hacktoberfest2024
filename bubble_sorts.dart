main() {
  // bubble sorts
  var list = [5, 1, 4, 2, 8];
  print(list);
  for (var i = 0; i < list.length; i++) {
    for (var j = 0; j < list.length - 1; j++) {
      if (list[j] > list[j + 1]) {
        var temp = list[j];
        list[j] = list[j + 1];
        list[j + 1] = temp;
      }
    }
  }
  print(list);

  // bubble sort with while loop
  var list2 = [5, 1, 4, 2, 8];
  print(list2);
  var i = 0;
  while (i < list2.length) {
    var j = 0;
    while (j < list2.length - 1) {
      if (list2[j] > list2[j + 1]) {
        var temp = list2[j];
        list2[j] = list2[j + 1];
        list2[j + 1] = temp;
      }
      j++;
    }
    i++;
  }
  print(list2);
}
