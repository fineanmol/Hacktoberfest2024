class CurrencyTools {
  static String nominalTerbilang(dynamic nominal) {
    final terbilangSatuan = [
      '', 'Satu', 'Dua', 'Tiga', 'Empat', 'Lima', 'Enam', 'Tujuh', 'Delapan', 'Sembilan', 'Sepuluh', 'Sebelas'
    ];

    if (nominal < 12) {
      return terbilangSatuan[nominal];
    } else if (nominal < 20) {
      return '${terbilangSatuan[nominal % 10]} Belas';
    } else if (nominal < 100) {
      return '${terbilangSatuan[nominal ~/ 10]} Puluh ${terbilangSatuan[nominal % 10]}';
    } else if (nominal < 200) {
      return 'Seratus ${nominalTerbilang(nominal % 100)}';
    } else if (nominal < 1000) {
      return '${terbilangSatuan[nominal ~/ 100]} Ratus ${nominalTerbilang(nominal % 100)}';
    } else if (nominal < 2000) {
      return 'Seribu ${nominalTerbilang(nominal % 1000)}';
    } else if (nominal < 1000000) {
      return '${nominalTerbilang(nominal ~/ 1000)} Ribu ${nominalTerbilang(nominal % 1000)}';
    } else if (nominal < 1000000000) {
      return '${nominalTerbilang(nominal ~/ 1000000)} Juta ${nominalTerbilang(nominal % 1000000)}';
    } else if (nominal < 1000000000000) {
      return '${nominalTerbilang(nominal ~/ 1000000000)} Milyar ${nominalTerbilang(nominal % 1000000000)}';
    } else {
      return 'Nominal terlalu besar';
    }
  }