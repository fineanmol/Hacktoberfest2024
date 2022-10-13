package main

import (
	"image/png"
	"os"
	"image"
	"io/ioutil"
	"bytes"
	"fmt"

	// github. com liyue201 GOQR
	"github.com/liyue201/goqr"
	// barcode scale 
	"github.com/boombuler/barcode"
	// Build the QRcode for the text
	"github.com/boombuler/barcode/qr"
)


func qrCodeGen(t string, filename string) (error) {
	// Create the barcode
	qrCode, _ := qr.Encode(t, qr.M, qr.Auto)

	// Scale the barcode to 200x200 pixels
	qrCode, _ = barcode.Scale(qrCode, 2000, 2000)

	// create the output file
	file, err := os.Create(filename)
	defer file.Close()

	// encode the barcode as png
	png.Encode(file, qrCode)

	return err
}

func scanQRCode(path string) {
	
	// Reads imgdata from a file.
	imgdata, err := ioutil.ReadFile(path)
	if err != nil {
		fmt.Printf("%v\n", err)
		return
	}

	// Decodes an image.
	img, _, err := image.Decode(bytes.NewReader(imgdata))
	if err != nil {
		fmt.Printf("image.Decode error: %v\n", err)
		return
	}

	// Recognize QR Codes.
	qrCodes, err := goqr.Recognize(img)
	if err != nil {
		fmt.Printf("Recognize failed: %v\n", err)
		return
	}
	
	// Prints a list of QR Codes.
	for _, qrCode := range qrCodes {
		fmt.Printf("qrCode text: %s\n", qrCode.Payload)
	}
	return
}

func main() {
	
	// This is a text to encode
	t := "This is a text"
	// file to read from 
	filenameR := "qrcode.png"
	// qrCodeGen generates a QR Code
	qrCodeGen(t, filenameR)


	// file to write to
	filenameW := "qrcode.png"
	// scanQRCode scans a QR code image file.
	scanQRCode(filenameW)

}
