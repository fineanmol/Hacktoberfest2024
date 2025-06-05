function generateQRCode() {
    var textInput = document.getElementById('text-input').value;
    var qrcodeContainer = document.getElementById('qrcode');

    // Clear previous QR code, if any
    qrcodeContainer.innerHTML = '';

    // Generate QR code
    var qrcode = new QRCode(qrcodeContainer, {
        text: textInput,
        width: 128,
        height: 128
    });
}
