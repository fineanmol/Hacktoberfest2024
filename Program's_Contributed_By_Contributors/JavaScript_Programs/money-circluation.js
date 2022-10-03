function getData() {
  var elemen = document.getElementById("metode-solusi");
  var lembarUang = [1000, 2000, 5000, 10000, 20000, 50000, 100000];
  var banyakUang = lembarUang.length;

  console.log(banyakUang);

  var alphabhet = Math.pow(26, 3);
  console.log(alphabhet);

  var digitAngka = Math.pow(10, 6);
  console.log(digitAngka);

  var totalPermutasi = alphabhet * digitAngka;
  console.log(totalPermutasi);

  if (lembarUang.length > 0) {
    const arr = [];
    for (var i = 0; i < lembarUang.length; i++) {
      var kemunkinan = lembarUang[i] * totalPermutasi;
      console.log(kemunkinan);
      arr.push(kemunkinan);
    }
    console.log(arr);

    var uangBeredar = arr.reduce(function (result, item) {
      return result + item;
    }, 0);
    console.log(uangBeredar);

    var totalUangBeredar = uangBeredar * 3;
    console.log(totalUangBeredar);
  }

  console.log(
    "Jumlah pecahan yang tersedia di Indonesia " +
      banyakUang +
      " pecahan" +
      " <br> " +
      " Hasil permutasi berdasarkan alphabhet sebanyak " +
      alphabhet +
      " kemunkinan" +
      " <br> " +
      " Hasil permutasi berdasarkan nomor seri sebanyak  " +
      digitAngka +
      " kemunkinan" +
      " <br> " +
      " Total permutasi berdasarkan nomor seri dan alphabhet  " +
      totalPermutasi +
      " kemunkinan" +
      " <br> " +
      "Sehingga jumlah uang yang beredar " +
      uangBeredar +
      " triliun uang yang beredar" +
      " <br> " +
      "Jumlah uang beredar berdasarkan kode BI " +
      totalUangBeredar +
      " triliun uang yang beredar"
  );
}
