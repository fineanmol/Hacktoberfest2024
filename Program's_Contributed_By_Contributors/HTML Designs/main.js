<script src="./qrcode.js" defer></script>
        
        <script src="https://cdnjs.cloudflare.com/ajax/libs/qrious/4.0.2/qrious.min.js"></script>
		<script>
			/* JS comes here */
			var qr;
			(function() {
                    qr = new QRious({
                    element: document.getElementById('qr-code'),
                    size: 200,
                });
            })();
            
            function generateQRCode() {
                var qrtext = document.getElementById("qr-text").value;
                document.getElementById("qr-result").innerHTML = "QR code for " + qrtext +":";
                alert(qrtext);
                qr.set({
                    foreground: 'black',
                    size: 200,
                    value: qrtext
                });
            }
          qr.set({
    background: 'white',
    backgroundAlpha: 0.8,
    foreground: 'black',
    foregroundAlpha: 0.8,
    padding: 25,
    size: 300,

});
		</script>
      <script src="https://cdnjs.cloudflare.com/ajax/libs/qrious/4.0.2/qrious.min.js"></script>