import 'dart:math' as Math;
import 'dart:math' show Random;
import 'package:test/test.dart';

main() {
  test("Sorting of empty list returns empty list", () {
    expect(radixSort([]), equals([]));
  });
  test("Sorting one element list return same list", () {
    expect(radixSort([1]), equals([1]));
  });
  test("Sorting two times doesnt change input", () {
    List<int> lst = [5, 7, 1, 10, 54, -1];
    expect(radixSort(lst), equals(radixSort(radixSort(lst))));
  });
  test("Sorting already sorted list returns same list", () {
    List<int> lst = [1, 2, 3, 4, 10];
    expect(radixSort(lst), equals(lst));
  });
  test("radix sort", () {
    expect(radixSort([34, -2, 122, 24435, 23, 434, 232, 1323]),
        equals([-2, 23, 34, 122, 232, 434, 1323, 24435]));
  });

  final seed = 10, rnd = Random(), length = 10;
  var list =
      List<int>.generate(length, (i) => rnd.nextInt(seed), growable: false);
  print('before sorting:');
  print(list);
  print('----------------------------------------------');
  print('After sorting:');
  print(radixSort(list));
}

getDigitNum(int n, int i) {
  var cal = (n.round().abs() / Math.pow(10, i)) % 10;

  return cal.round();
}

digitCount(int number) {
  if (number == 0) {
    return 1;
  }
  return (number.abs().toString().length);
}

mostDigits(List number) {
  var maxDigits = 0;
  for (var i = 0; i < number.length; i++) {
    maxDigits = Math.max(maxDigits, digitCount(number[i]));
  }
  return maxDigits;
}

radixSort(List nums) {
  var maxDightCount = mostDigits(nums);
  for (var k = 0; k < maxDightCount; k++) {
    var digitBuckets = List.generate(10, (_) => []);
    for (var i = 0; i < nums.length; i++) {
      var digit = getDigitNum(nums[i], k);
      digitBuckets[digit].add(nums[i]);
    }

    nums = digitBuckets.expand((lst) => lst).toList();
  }
  return nums;
}
